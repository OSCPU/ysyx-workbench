module PC (
    input clk,
    input rst,
    output reg [31:0] pc
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            pc <= 32'h80000000;  // 初始PC值为0x80000000
        else
            pc <= pc + 4;  // 每次递增4（每条指令长度）
    end
endmodule

