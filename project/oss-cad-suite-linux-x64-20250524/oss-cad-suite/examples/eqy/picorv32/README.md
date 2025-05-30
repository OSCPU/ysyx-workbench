# Using EQY to get a formally verified synthesis result from Xilinx Vivado

This directory contains an example project that demonstrates a methodology for
creating formally verified netlist using EQY and Xilinx Vivado. The example
design we are using is PicoRV32 in its default configuration, and the
architecture we are targetting is Kintex-7.

The file [picorv32.v](picorv32.v) contains the unmodified original PicoRV32
Verilog HDL code. From this we first created a functionally equivalent
[picorv32_modified.v](picorv32_modified.v) that eliminates some of the
X-propagation from the design. The EQY project [picorv32_modified.eqy](picorv32_modified.eqy)
proves equivalence for the two versions of the design:

```
$ eqy -j6 picorv32_modified.eqy
...
EQY 17:43:02 [picorv32_modified] Successfully proved designs equivalent
EQY 17:43:02 [picorv32_modified] summary: Elapsed clock time [H:MM:SS (secs)]: 0:00:16 (16)
EQY 17:43:02 [picorv32_modified] summary: Elapsed process time [H:MM:SS (secs)]: 0:00:49 (49)
EQY 17:43:02 [picorv32_modified] DONE (PASS, rc=0)
```

Next we synthesized that modified design with Xilinx Vivado with [picorv32_vivado.tcl](picorv32_vivado.tcl)
into the Verilog netlist [picorv32_vivado.v](picorv32_vivado.v). Equivalence of the synthesis output
with the modified design is proven via the EQY project [picorv32_vivado.eqy](picorv32_vivado.eqy):

```
$ eqy -j6 picorv32_vivado.eqy
...
EQY 17:50:43 [picorv32_vivado] Successfully proved designs equivalent
EQY 17:50:43 [picorv32_vivado] summary: Elapsed clock time [H:MM:SS (secs)]: 0:04:16 (256)
EQY 17:50:43 [picorv32_vivado] summary: Elapsed process time [H:MM:SS (secs)]: 0:21:52 (1312)
EQY 17:50:43 [picorv32_vivado] DONE (PASS, rc=0)
```

The following sections describe the techniques we employed to create the [picorv32_vivado.eqy](picorv32_vivado.eqy) file.

## Initializing the design

After reading the gold and gate HDL files, the testbench in [init.v](init.v) is run on both
designs, initializing the registers in both designs to the same state, thus eliminating some
x-bits present in the un-initialzed versions of both design.

This is achieved by the `sim` commands in the `[gold]` and `[gate]` sections at the top
of the EQY configuration file.

## Eliminating false matched points

By default, EQY assumes that nets in the gold and gate designs with the same
name are meant to be equivalent, and the proof will fail if that is an
incorrect assumption.

The EQY output directory contains a per-module SBY file to run a bounded model
check for the assumed-equivalent nets:

```
$ eqy -fm picorv32_vivado.eqy
$ cd picorv32_vivado/modules/
$ sby picorv32.sby
```

The nets found not to be equivalent by this check have then been excluded from
matching each other using `gate-nomatch` statements in the EQY configuration file.

## Finding additional matching points

Additional equivalent points in the design are identified by comparing simulation
traces from running the same testbench on both designs.

First, the gold and gate netlists are extracted from the EQY output directory:

```
$ yosys -qo test_gold_uut.v picorv32_vivado/gold.il
$ yosys -qo test_gate_uut.v picorv32_vivado/gate.il
```

Next we compile and run the testbench on both designs:

```
$ iverilog -o test_gold -D GOLD testbench.v test_gold_uut.v
$ iverilog -o test_gate testbench.v test_gate_uut.v
$ vvp -N test_gold
$ vvp -N test_gate
```

Then we run [vcdmatch.py](vcdmatch.py) to extract candidates for equivalent
nets:

```
python3 vcdmatch.py | tee vcdmatch.out
```

After that we added additional rules to the EQY configuration file for the
candidates identified by `vcdmatch.py`.

Finally we re-generated the EQY output directory and re-ran the module-level
bounded model check from the previous section above, to verify we have not
accidentally added false equivalent points.

## Generating partitions and amend-rules

Next we added rules to group the *fragments* EQY extraced from gold and gate
designs into *partitions*, using `group` and `merge` rules in the EQY configuration
file. For this we select the fragments that we want to merge into the same partition
based on shared logic and signals, and related logic function.

Finally we needed to figure out which fragments of the gold design we need
to add to which EQY partition as additional constraints. The easiest way
of doing that is by first amending and excessive amount of fragments, and
then narrowing down that list.

The partitions with more fragments amended than needed are usually too complex
to PASS a complete proof. But EQY generates a per-partition bounded model check
for each partition, that can be used to test a configuration. For example:

```
$ eqy -fm picorv32_vivado.eqy
$ cd picorv32_vivado/partitions/
$ sby picorv32.3_cpu_state.sby
```

The script [tryamend.sh](tryamend.sh) can be useful for the task of stripping
down amend rules. First, we prefix the individual rules we want to test with
tags in the form `{name}`, for example:

```
{a} amend mem_do_prefetch  cpu_state[]
{b} amend mem_do_rdata     cpu_state[]
{c} amend mem_do_wdata     cpu_state[]
{d} amend decoded_imm_j[]  cpu_state[]
{e} amend is_rdcycle_*     cpu_state[]
{f} amend instr_trap       cpu_state[]
```

Running `bash tryamend.sh 3_cpu_state 12` will create copies of the config
file, each with one of the above lines omitted, and then run the per-partition
bounded model check for the `3_cpu_state` partition.

A failing test for a line indicates that the fragment was required for the
partition to pass verification. A passing test for a line indicates that
the line can be removed from the configuration file, as the fragment it
amends to the partition generating the `cpu_state` bits seems not needed
to verify the given partition.
