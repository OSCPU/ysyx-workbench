module ysyx_25030077_DATA_CONTROL(
  // input         clock,
  // input         reset,
  input  [3:0]  io_sw,
  input  [4:0]  io_rd_addr,
  input  [31:0] io_rs1_data,
  input  [31:0] io_rs2_data,
  input  [31:0] io_instruction,
  input  [3:0]  io_pc_next_type,
  input  [31:0] io_imm,
  input  [31:0] io_mem_data,
  input  [31:0] io_pc_count,
  input  [2:0]  io_data_control,
  input         io_alu_Req_ready,
  output        io_alu_Req_valid,
  output [31:0] io_alu_Req_bits_data1,
  output [31:0] io_alu_Req_bits_data2,
  output [3:0]  io_alu_Req_bits_sw,
  output [4:0]  io_alu_Req_bits_addr,
  output [31:0] io_alu_Req_bits_rs1_data,
  output [31:0] io_alu_Req_bits_rs2_data,
  output [31:0] io_alu_Req_bits_instruction,
  output [3:0]  io_alu_Req_bits_pc_next_type,
  output [31:0] io_alu_Req_bits_pc_count,
  output        io_ready,
  input         io_valid
);

  export "DPI-C" function reg_read_rs1;
  function int reg_read_rs1();
    return {io_rs1_data};
  endfunction

  export "DPI-C" function reg_read_rs2;
  function int reg_read_rs2();
    return {io_rs2_data};
  endfunction

  wire  control1 = io_data_control == 3'h1; // @[data_control.scala 23:34]
  wire  control2 = io_data_control == 3'h2; // @[data_control.scala 24:34]
  wire  control3 = io_data_control == 3'h3; // @[data_control.scala 25:34]
  wire [31:0] _io_alu_Req_bits_data1_T = control2 ? io_mem_data : io_rs1_data; // @[Mux.scala 101:16]
  wire [31:0] _io_alu_Req_bits_data2_T = control3 ? io_rs2_data : io_imm; // @[Mux.scala 101:16]
  assign io_alu_Req_valid = io_valid; // @[data_control.scala 48:20]
  assign io_alu_Req_bits_data1 = control1 ? io_pc_count : _io_alu_Req_bits_data1_T; // @[Mux.scala 101:16]
  assign io_alu_Req_bits_data2 = control2 ? 32'h0 : _io_alu_Req_bits_data2_T; // @[Mux.scala 101:16]
  assign io_alu_Req_bits_sw = io_sw; // @[data_control.scala 39:22]
  assign io_alu_Req_bits_addr = io_rd_addr; // @[data_control.scala 40:24]
  assign io_alu_Req_bits_rs1_data = io_rs1_data; // @[data_control.scala 41:28]
  assign io_alu_Req_bits_rs2_data = io_rs2_data; // @[data_control.scala 42:28]
  assign io_alu_Req_bits_instruction = io_instruction; // @[data_control.scala 43:31]
  assign io_alu_Req_bits_pc_next_type = io_pc_next_type; // @[data_control.scala 44:32]
  assign io_alu_Req_bits_pc_count = io_pc_count; // @[data_control.scala 45:28]
  assign io_ready = io_alu_Req_ready; // @[data_control.scala 46:12]
endmodule