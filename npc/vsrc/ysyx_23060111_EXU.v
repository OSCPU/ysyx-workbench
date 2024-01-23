module ysyx_23060111_EXU(
  output[31:0] dnpc,
  input [31:0] snpc,
  input[31:20] imm,
  input[19:15] rs1,
  input[14:12] funct3,
  input[11:7] rd,
  input[6:0] opcode,
  input[31:0] rout,
  output[31:0] wdata,
  output[4:0] waddr,
  output[4:0] raddr,
  output[9:0] rbb,
  output wen
);
  wire [31:0] imm_32;
  assign rbb={funct3,opcode};

  //addi
  assign imm_32={20'h00000,imm};
  assign raddr=rs1[19:15];
  assign wdata=rout+imm_32;
  assign waddr=rd[11:7];
  assign wen=1'b1;
  assign dnpc=snpc;

endmodule
  
