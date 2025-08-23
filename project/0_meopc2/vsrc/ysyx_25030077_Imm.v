module ysyx_25030077_Imm(
  input  [31:0] io_instruction,
  input  [2:0]  io_imm_type,
  output [31:0] io_imm
);
  wire [19:0] _Imm_type1_T_2 = io_instruction[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] Imm_type1 = {_Imm_type1_T_2,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type2 = {io_instruction[31:12],12'h0}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type4 = {_Imm_type1_T_2,io_instruction[31:25],io_instruction[11:7]}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type5 = {27'h0,io_instruction[24:20]}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type6 = {20'h0,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire  is_type1 = io_imm_type == 3'h1; // @[module.scala 21:31]
  wire  is_type2 = io_imm_type == 3'h2; // @[module.scala 22:31]
  wire  is_type3 = io_imm_type == 3'h3; // @[module.scala 23:31]
  wire  is_type4 = io_imm_type == 3'h4; // @[module.scala 24:31]
  wire  is_type5 = io_imm_type == 3'h5; // @[module.scala 25:31]
  wire  is_type6 = io_imm_type == 3'h6; // @[module.scala 26:31]
  wire [31:0] _io_imm_T = is_type6 ? Imm_type6 : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_1 = is_type5 ? Imm_type5 : _io_imm_T; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_2 = is_type4 ? Imm_type4 : _io_imm_T_1; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_3 = is_type3 ? 32'h4 : _io_imm_T_2; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_4 = is_type2 ? Imm_type2 : _io_imm_T_3; // @[Mux.scala 101:16]
  assign io_imm = is_type1 ? Imm_type1 : _io_imm_T_4; // @[Mux.scala 101:16]
endmodule