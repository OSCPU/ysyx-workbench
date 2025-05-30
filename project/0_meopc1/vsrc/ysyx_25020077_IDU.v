module ysyx_25020077_IDU(
  input  [31:0] io_instruction,
  output [2:0]  io_imm_type,
  output [4:0]  io_rs1,
  output [4:0]  io_rd,
  output [2:0]  io_ALU_ctrl,
  output        is_break_out
);
  import "DPI-C" function bit is_break(input bit[31:0] instruction_in);
  assign is_break_out = is_break(io_instruction);
  wire [9:0] instruction_type = {io_instruction[14:12],io_instruction[6:0]}; // @[Cat.scala 31:58]
  wire [4:0] addi_Rs1 = io_instruction[19:15]; // @[module.scala 23:32]
  wire [4:0] addi_Rd = io_instruction[11:7]; // @[module.scala 24:32]
  wire  isSpecialType = instruction_type == 10'h13; // @[module.scala 28:40]
  wire  _io_imm_type_T = ~isSpecialType; // @[module.scala 33:5]
  assign io_imm_type = isSpecialType ? 3'h1 : 3'h0; // @[Mux.scala 27:73]
  assign io_rs1 = isSpecialType ? addi_Rs1 : 5'h0; // @[Mux.scala 27:73]
  assign io_rd = isSpecialType ? addi_Rd : 5'h0; // @[Mux.scala 27:73]
  assign io_ALU_ctrl = _io_imm_type_T ? 3'h7 : 3'h0; // @[Mux.scala 27:73]
endmodule