module EXU (
  input [31:0] rs1_data,
  input [11:0] imm,
  input [2:0] alu_op,
 
  output reg [31:0] alu_result
);
  always @(*) begin
    case (alu_op)
      3'b000: alu_result = rs1_data + {{20{imm[11]}}, imm};  // ADDI 操作，符号扩展
      default: alu_result = 0;
    endcase
  end
endmodule

