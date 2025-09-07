module ysyx_25030077_top(
  input         clk,
  input         reset,
  output        ALU_carry,
  output        ALU_overflow,
  output [31:0] PC_count_o
);
wire [31:0] io_Pc_count;
wire [31:0] Pc_next;
ysyx_25030077_PC i0 (clk, reset,Pc_next ,io_Pc_count);
assign PC_count_o = io_Pc_count;
wire [31:0] instruction_out;
ysyx_25030077_IFU i1 (io_Pc_count, instruction_out);
wire [2:0] imm_type;
wire [4:0] rs1; 
wire [4:0] rs2;
wire [2:0] data_control;
wire [3:0] pc_next_type;
wire is_break_out;
wire [31:0] rs1_out0;
wire [31:0] rs2_out0;
wire [31:0] imm0;
wire [3 :0] ALU_ctrl0;
wire [4 :0] rd0;

ysyx_25030077_IDU i2 (instruction_out, imm_type, rs1, rs2, rd0, data_control, ALU_ctrl0, pc_next_type, is_break_out);
ysyx_25030077_Imm i3 (instruction_out, imm_type, imm0);
wire [31:0] ALU_result;
wire [31:0] mem_data;


ysyx_25030077_reg i4 (clk, reset, rd0, ALU_result, rs1, rs1_out0, rs2, rs2_out0);
wire [31:0] ALU_data_1;
wire [31:0] ALU_data_2;
wire is_unknown_instruction;
ysyx_25030077_DATA_CONTROL i5 (rs1_out0, rs2_out0, imm0, mem_data, io_Pc_count, data_control, ALU_data_1, ALU_data_2);
ysyx_25030077_ALU i6 (ALU_data_1, ALU_data_2, ALU_ctrl0, ALU_result, ALU_carry, ALU_overflow);
ysyx_25030077_PC_next i7(rs1_out0, rs2_out0, instruction_out, pc_next_type, io_Pc_count, Pc_next, is_unknown_instruction);
ysyx_25030077_MEM_read i9 (instruction_out, rs1_out0, rs2_out0, imm0, mem_data);
// always @(*) begin
//   $display("%d + %d = %d\n", rs1_out, imm, ALU_result);
//   $display("instroduction is :%h\n", instruction_out);
// end
endmodule


