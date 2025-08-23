module ysyx_25030077_top(
  input         clock,
  input         reset,
  output [31:0] imm,
  output [4:0]  rd,
  output [3:0]  ALU_ctrl,
  output [31:0] rs1_out,
  output [31:0] rs2_out,
  output        ALU_carry,
  output        ALU_overflow
);
wire [31:0] io_Pc_count;
wire [31:0] Pc_next;
ysyx_25030077_PC i0 (clock, reset,Pc_next ,io_Pc_count);
wire [31:0] instruction_out;
ysyx_25030077_IFU i1 (io_Pc_count, instruction_out);
wire [2:0] imm_type;
wire [4:0] rs1; 
wire [4:0] rs2;
wire [2:0] data_control;
wire [3:0] pc_next_type;
wire is_break_out;
ysyx_25030077_IDU i2 (instruction_out, imm_type, rs1, rs2, rd, data_control, ALU_ctrl, pc_next_type, is_break_out);
ysyx_25030077_Imm i3 (instruction_out, imm_type, imm);

wire [31:0] ALU_result;
wire [31:0] mem_data;
ysyx_25030077_reg i4 (clock, reset, rd, ALU_result, rs1, rs1_out, rs2, rs2_out);
wire [31:0] ALU_data_1;
wire [31:0] ALU_data_2;
wire is_unknown_instruction;
ysyx_25030077_DATA_CONTROL i5 (rs1_out, rs2_out, imm, mem_data, io_Pc_count, data_control, ALU_data_1, ALU_data_2);
ysyx_25030077_ALU i6 (ALU_data_1, ALU_data_2, ALU_ctrl, ALU_result, ALU_carry, ALU_overflow);
ysyx_25030077_PC_next i7(rs1_out, rs2_out, instruction_out, pc_next_type, io_Pc_count, Pc_next, is_unknown_instruction);
ysyx_25030077_EXIT i8 (clock, reset, io_Pc_count, is_break_out, is_unknown_instruction);
ysyx_25030077_MEM_read i9 (instruction_out, rs1_out, rs2_out, imm, mem_data);
// always @(*) begin
//   $display("%d + %d = %d\n", rs1_out, imm, ALU_result);
//   $display("instroduction is :%h\n", instruction_out);
// end
endmodule


