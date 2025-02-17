module IFU (
    input clk,
    input rst,
    input [31:0] inst_in,   // 上一级传入的PC
    output reg [31:0] instruction_out // 输出指令
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            instruction_out <= 32'b0;
        end else begin
            instruction_out <= inst_in;  // 直接传递来自 top 的指令
            // 假设mem是已经初始化的内存系统，通过地址获取指令
            
        end
    end
endmodule

