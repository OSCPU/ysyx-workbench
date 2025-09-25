module ysyx_25030077_ALU(
  input  [31:0] io_in_a,
  input  [31:0] io_in_b,
  input  [3:0]  io_sw,
  output [31:0] io_out,
  output        io_carry,
  output        io_overflow
);
  import "DPI-C" function bit[31:0] csr_read(input bit[31:0] rs1, input bit[31:0] imm, input bit[3:0] sw);
  wire [31:0] csr_data = csr_read(io_in_a, io_in_b, io_sw);
  
  wire [15:0] oneHot = 16'h1 << io_sw; // @[OneHot.scala 64:12]
  wire [32:0] add33 = io_in_a + io_in_b; // @[alu.scala 18:25]
  wire [32:0] sub33 = io_in_a - io_in_b; // @[alu.scala 19:25]
  wire [31:0] and32 = io_in_a & io_in_b; // @[alu.scala 20:25]
  wire [31:0] or32 = io_in_a | io_in_b; // @[alu.scala 21:25]
  wire [31:0] xor32 = io_in_a ^ io_in_b; // @[alu.scala 22:25]
  wire [31:0] srai32 = $signed(io_in_a) >>> io_in_b[4:0]; // @[alu.scala 23:49]
  wire [31:0] srli32 = io_in_a >> io_in_b[4:0]; // @[alu.scala 24:25]
  wire [62:0] _GEN_3 = {{31'd0}, io_in_a}; // @[alu.scala 25:25]
  wire [62:0] sll32 = _GEN_3 << io_in_b[4:0]; // @[alu.scala 25:25]
  wire  sltiu_b = io_in_a < io_in_b; // @[alu.scala 26:26]
  wire  slt_b = $signed(io_in_a) < $signed(io_in_b); // @[alu.scala 27:33]
  wire [32:0] _out33_T_3 = {32'h0,sltiu_b}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_5 = {1'h0,or32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_7 = {1'h0,xor32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_9 = {1'h0,srai32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_11 = {1'h0,and32}; // @[Cat.scala 31:58]
  wire [63:0] _out33_T_14 = {1'h0,sll32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_16 = {1'h0,srli32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_18 = {32'h0,slt_b}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_24 = oneHot[0] ? add33 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_25 = oneHot[1] ? sub33 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_26 = oneHot[2] ? _out33_T_3 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_27 = oneHot[3] ? _out33_T_5 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_28 = oneHot[4] ? _out33_T_7 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_29 = oneHot[5] ? _out33_T_9 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_30 = oneHot[6] ? _out33_T_11 : 33'h0; // @[Mux.scala 27:73]
  wire [63:0] _out33_T_32 = oneHot[8] ? _out33_T_14 : 64'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_33 = oneHot[9] ? _out33_T_16 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_34 = oneHot[10] ? _out33_T_18 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_40 = _out33_T_24 | _out33_T_25; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_41 = _out33_T_40 | _out33_T_26; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_42 = _out33_T_41 | _out33_T_27; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_43 = _out33_T_42 | _out33_T_28; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_44 = _out33_T_43 | _out33_T_29; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_45 = _out33_T_44 | _out33_T_30; // @[Mux.scala 27:73]
  wire [63:0] _GEN_0 = {{31'd0}, _out33_T_45}; // @[Mux.scala 27:73]
  wire [63:0] _out33_T_47 = _GEN_0 | _out33_T_32; // @[Mux.scala 27:73]
  wire [63:0] _GEN_1 = {{31'd0}, _out33_T_33}; // @[Mux.scala 27:73]
  wire [63:0] _out33_T_48 = _out33_T_47 | _GEN_1; // @[Mux.scala 27:73]
  wire [63:0] _GEN_2 = {{31'd0}, _out33_T_34}; // @[Mux.scala 27:73]
  wire [63:0] out33 = _out33_T_48 | _GEN_2; // @[Mux.scala 27:73]
  wire  a31 = io_in_a[31]; // @[alu.scala 58:20]
  wire  b31 = io_in_b[31]; // @[alu.scala 59:20]
  wire  s31 = out33[31]; // @[alu.scala 60:18]
  wire  _overflowAddBool_T = a31 ^ s31; // @[alu.scala 63:30]
  wire  _overflowAddBool_T_1 = a31 ^ b31; // @[alu.scala 63:45]
  wire  overflowAddBool = (a31 ^ s31) & ~(a31 ^ b31); // @[alu.scala 63:37]
  wire  overflowSubBool = _overflowAddBool_T & _overflowAddBool_T_1; // @[alu.scala 64:37]
  assign io_out = (oneHot[11] || oneHot[12]) ? csr_data :out33[31:0]; // @[module.scala 30:10]
  assign io_carry = out33[32]; // @[alu.scala 55:20]
  assign io_overflow = oneHot[0] & overflowAddBool | oneHot[1] & overflowSubBool; // @[Mux.scala 27:73]
endmodule
