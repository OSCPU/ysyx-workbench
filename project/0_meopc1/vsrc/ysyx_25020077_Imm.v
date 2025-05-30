module ysyx_25020077_Imm(
  input  [31:0] io_instruction,
  input  [2:0]  io_imm_type,
  output [31:0] io_imm
);
  wire [19:0] _Imm_1_T_2 = io_instruction[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] Imm_1 = {_Imm_1_T_2,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire  isType1 = io_imm_type == 3'h1; // @[module.scala 17:29]
  assign io_imm = isType1 ? Imm_1 : 32'h0; // @[Mux.scala 27:73]
endmodule