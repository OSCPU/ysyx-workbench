module IDU (
    input [31:0] instruction,
    output [4:0] rs1,
    output [4:0] rs2,
    output [4:0] rd,
    output [31:0] imm,
    output [6:0] opcode
);
    assign opcode = instruction[6:0];
    assign rs1 = instruction[19:15];
    assign rs2 = instruction[24:20];
    assign rd = instruction[11:7];
    assign imm = {{20{instruction[31]}}, instruction[31:20]};  // 立即数扩展
endmodule

