module EXU (
    input [31:0] rs1_data,
    input [31:0] imm,
    input [6:0] opcode,
    output reg [31:0] result
);
    always @(*) begin
        case (opcode)
            7'b0010011: result = rs1_data + imm;  // ADDI 指令
            // 这里可以添加其他指令的支持
            default: result = 32'b0;
        endcase
    end
endmodule

