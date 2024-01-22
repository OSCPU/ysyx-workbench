module ysyx_23060111_IDU(
  input [31:0] snpc,
  input [31:0] inst,
  output [31:0] dnpc,
  output [31:20] imm,
  output [14:12] funct3,
  output [19:15] rs1,
  output [11:7] rd,
  output [6:0] opcode
);
  assign dnpc=32'h80000004;
  assign imm=inst[31:20];
  assign rs1=inst[19:15];
  assign funct3=inst[14:12];
  assign rd=inst[11:7];
  assign opcode=inst[6:0];
endmodule
