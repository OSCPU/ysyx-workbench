module ysyx_23060111_EXU(
  input       clk,
  input       rst,
  input[31:0] dnpc,
  input[31:20] imm,
  input[19:15] rs1,
  input[11:7] rd,
  output[31:0] pc,
  output[31:0] reg_out,
  output[31:0] reg_out1,
  output[19:15] out
);
  reg [31:0] imm_32;
  assign imm_32={20'h00000,imm};
  assign out =rd+rs1;
 ysyx_23060111_trigger #(32,32'h80000000) renew_pc(clk,rst,dnpc,pc,1'b1);
 ysyx_23060111_reg #(1,32) reg_src1(clk,0,rs1[15:15],1'b0,reg_out);
 ysyx_23060111_reg #(1,32) reg_rd(clk,reg_out+imm_32,rd[7:7],1'b1,reg_out1);



endmodule
  
