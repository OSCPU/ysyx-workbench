module IFU (
    input clk,
    input rst,
    input [31:0] inst_in,   // 上一级传入的PC
    output reg [31:0] instruction_out, // 输出指令
    output reg ebreak
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            instruction_out <= 32'b0;
        end else begin
            instruction_out <= inst_in;  // 直接传递来自 top 的指令
            // 假设mem是已经初始化的内存系统，通过地址获取指令
             if (inst_in == 32'h00100073) begin
                ebreak = 1; // ebreak 指令，设置 ebreak 信号
            end else begin
                ebreak = 0;
        	end
    	end
    end
endmodule

