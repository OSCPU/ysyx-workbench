module ysyx_25020077_top(
  input         clock,
  input         reset,
  output [31:0] imm,
  output [4:0]  rd,
  output [2:0]  ALU_ctrl,
  output [31:0] rs1_out,
  output [31:0] rs2_out,
  output        ALU_carry,
  output        ALU_overflow,
  output        is_break_out
);
wire [31:0] io_Pc_count;
ysyx_25020077_PC i0 (clock, reset, io_Pc_count);
wire [31:0] instruction_out;
ysyx_25020077_IFU i1 (io_Pc_count, instruction_out);
wire [2:0] imm_type;
wire [4:0] rs1; 
ysyx_25020077_IDU i2 (instruction_out, imm_type, rs1, rd, ALU_ctrl, is_break_out);
ysyx_25020077_Imm i3 (instruction_out, imm_type, imm);
wire [4:0]  rs2;
assign rs2 = 5'd0;
wire [31:0] ALU_result;
ysyx_25020077_reg i4 (clock, reset, rd, ALU_result, rs1, rs1_out, rs2, rs2_out);
ysyx_25020077_ALU i5 (rs1_out, imm, ALU_ctrl, ALU_result, ALU_carry, ALU_overflow);
// always @(*) begin
//   $display("%d + %d = %d\n", rs1_out, imm, ALU_result);
//   $display("instroduction is :%h\n", instruction_out);
// end
endmodule


