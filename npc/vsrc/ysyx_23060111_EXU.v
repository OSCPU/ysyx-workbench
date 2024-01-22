module ysyx_23060111_EXU(
  input       clk,
  input       rst,
  output[31:0] dnpc,
  input[31:20] imm,
  input[19:15] rs1,
  input[14:12] funct3,
  input[11:7] rd,
  input[6:0] opcode,
  output[31:0] pc,
  output[20:1] rbb,
  input[31:0] rout,
  output[31:0] wdata,
  output[4:0] waddr,
  output[4:0] raddr,
  output wen
);
  reg [31:0] imm_32;
  assign rbb ={rd,rs1,funct3,opcode};
  ysyx_23060111_trigger #(32,32'h80000000) renew_pc(clk,rst,dnpc,pc,1'b1);

  //addi
  assign imm_32={20'h00000,imm};
  assign dnpc=32'h80000004;
  assign raddr=rs1[19:15];
  assign wdata=rout+imm_32;
  assign waddr=rd[11:7];
  assign wen=1'b1;


endmodule
  
