# Checking Refactor Correctness With EQY

EQY - EQuivalence checking with Yosys - is a tool designed to perform formal
verification that two designs are equivalent, such as ensuring that a synthesis
tool has not introduced functional changes into a design, or ensuring that a
design refactor preserves correctness in all conditions.

In this example, a very simple CPU called NERV is used to demonstrate checking
that a refactor does not introduce bugs.

In the `nerv.sv` starter code, each RISC-V shift opcode (SLL, SRL, SRA, SLLI,
SRLI, SRAI) has its own shifter, and while the synthesis tool may be able to
combine some of these shifters together, it would be more efficient to have a
single shifter unit that all of these instructions use together.

`nerv_change.sv` contains a refactored version, where the shifts have been
extracted to a separate shifter unit, which can perform logical and arithmetic
right shifts, and by bit-reversing the input and output perform left shifts as
well.

```systemverilog
        // new shifter code
        function [31:0] bitreverse(input [31:0] arg);
                for (integer i = 0; i < 32; i++) bitreverse[i] = arg[31-i];
        endfunction
        wire [32:0] shift_t1 = {insn_funct7[5] && rs1_value[31], insn_funct3 == 3'b001 ? bitreverse(rs1_value) : rs1_value};
`ifdef SHIFTER_BUG
        wire [31:0] shift_t2 = $signed(shift_t1) >>> (insn_opcode == OPCODE_OP_IMM ? insn[24:20] : rs2_value[5:0]);
`else
        wire [31:0] shift_t2 = $signed(shift_t1) >>> (insn_opcode == OPCODE_OP_IMM ? insn[24:20] : rs2_value[4:0]);
`endif
        wire [31:0] shift_out = insn_funct3 == 3'b001 ? bitreverse(shift_t2) : shift_t2;
```

Imagine that we accidentally write an error in the code by using
`rs2_value[5:0]` instead of `rs2_value[4:0]`. This can be tested using the
`SHIFTER_BUG` ifdef in NERV.

To test if this design is equivalent to the original, we need to write a `.eqy`
file to tell EQY how to process the two designs.

First, we'll give the Yosys commands to process the known-good ("gold") design:

```
[gold]
read_verilog -sv nerv.sv
prep -top nerv
memory_map
```

We use `read_verilog -sv` to load the file, `prep -top nerv` to synthesise the 
design with `nerv` as top module, and then we use `memory_map` to turn the
register file into DFFs.

The design to be checked for equivalence (the "gate" design) has a similar
script.

```
[gate]
read_verilog -sv -DSHIFTER_BUG nerv_change.sv
prep -top nerv
memory_map
```

Then we need to tell EQY to collect sections that should be proven together,
like the register file and some logic known to be identical.

```
[collect *]
group regfile*
join imm_*
join insn*
```

Finally, we need to tell EQY how to prove these designs equivalent.

```
[strategy sby]
use sby
depth 2
engine smtbmc bitwuzla
```

These are included in `nerv_change_fail.eqy` for convenience. Now we can check
equivalence through `eqy nerv_change_fail.eqy`.

EQY will give output that ends like this:

```
EQY 16:33:44 [nerv_change_fail] Warning: Failed to prove equivalence for 1/44 partitions:
EQY 16:33:44 [nerv_change_fail] Failed to prove equivalence of partition nerv.next_rd
EQY 16:33:44 [nerv_change_fail] summary: Elapsed clock time [H:MM:SS (secs)]: 0:00:18 (18)
EQY 16:33:44 [nerv_change_fail] summary: Elapsed process time [H:MM:SS (secs)]: 0:00:22 (22)
EQY 16:33:44 [nerv_change_fail] DONE (FAIL, rc=2)
```

And we can see that these designs are not equivalent. EQY will create a trace
of the failing case in `nerv_change_fail/strategies/nerv.next_rd/sby/nerv.next_rd/engine_0/trace.vcd`.

Examining the trace, we can see that the failing instruction is an `SLL`
with `rs1_value` equal to `0xE0000000`, and an `rs2_value` equal to
`0x1FFFFFE2`. Since RISC-V mandates that `SLL` only looks at the lower 5 bits
of `rs2_value`, this is a left-shift of `0xE0000000` by 2, which should equal
`0x80000000`. However, due to the shifter bug, the shifter looks at the lower 6
bits of `rs2_value`, and performs a left-shift of `0xE0000000` by 34, resulting
in zero.

Since the bug has been found and fixed, we can run another equivalence check to
ensure that the new design is now equivalent. For NERV, this consists of just
removing the `SHIFTER_BUG` ifdef, which can be found in `nerv_change_pass.eqy`.
Running `eqy nerv_change_pass.eqy`, the output ends in

```
EQY 18:40:56 [nerv_change_pass] Successfully proved designs equivalent
EQY 18:40:56 [nerv_change_pass] summary: Elapsed clock time [H:MM:SS (secs)]: 0:00:21 (21)
EQY 18:40:56 [nerv_change_pass] summary: Elapsed process time [H:MM:SS (secs)]: 0:00:28 (28)
EQY 18:40:56 [nerv_change_pass] DONE (PASS, rc=0)
```

and EQY has proven the designs equivalent.
