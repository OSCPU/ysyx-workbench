module ysyx_25030077_MEM_read(
  // input         clock,
  // input         reset,
  input  [31:0] io_inst,
  input  [31:0] io_rs1,
  input  [31:0] io_rs2,
  input  [31:0] io_imm,
  output [31:0] io_mem_data
);

  import "DPI-C" function bit[31:0] mem_data_read(input bit[31:0] instruction_in, input bit[31:0] rs1_data_in, input bit[31:0] rs2_data_in, input bit[31:0] imm_data_in);
  assign io_mem_data = mem_data_read(io_inst, io_rs1, io_rs2, io_imm);

  // wire [31:0] _io_mem_data_T = io_inst & io_rs1; // @[mem.scala 13:27]
  // wire [31:0] _io_mem_data_T_1 = io_rs2 | io_imm; // @[mem.scala 13:47]
  // assign io_mem_data = _io_mem_data_T ^ _io_mem_data_T_1; // @[mem.scala 13:37]
endmodule
