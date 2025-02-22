module IDU (
  input [31:0] instr,
  output [4:0] rs1,
input clk,
  output [4:0] rd,
  output [11:0] imm,
  output [6:0] opcode,
  output [2:0] func3

);
  assign rs1 = instr[19:15];

  assign rd = instr[11:7];
  assign imm =  instr[31:20];  // 立即数扩展
  assign opcode = instr[6:0];
  assign func3 =  instr[14:12];  // 扩展为 4 位
/*always @(posedge clk) begin
    $display("RS1: %b, RD: %b,fun:%b Imm: %b, Opcode: %b", rs1, rd,func3 ,imm, opcode);
end*/
//	assign func7 = instr[31:25];
endmodule

