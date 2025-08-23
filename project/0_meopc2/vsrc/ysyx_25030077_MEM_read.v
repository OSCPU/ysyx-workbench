module ysyx_25030077_MEM_read(
  input  [31:0] io_instruction,
  input  [31:0] rs1_data,
  input  [31:0] rs2_data,
  input  [31:0] imm_data,
  output [31:0] mem_data
);

  import "DPI-C" function bit[31:0] mem_data_read(input bit[31:0] instruction_in, input bit[31:0] rs1_data_in, input bit[31:0] rs2_data_in, input bit[31:0] imm_data_in);
  assign mem_data = mem_data_read(io_instruction, rs1_data, rs2_data, imm_data);
  
endmodule