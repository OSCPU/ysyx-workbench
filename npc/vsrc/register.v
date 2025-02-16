module RegisterFile (
    input clk,
    input rst,
    input [4:0] raddr1,  // 读取寄存器地址1
    input [4:0] raddr2,  // 读取寄存器地址2
    input [4:0] waddr,   // 写入寄存器地址
    input [31:0] wdata,  // 写入数据
    input wen,            // 写使能
    output reg [31:0] rdata1,  // 读取数据1
    output reg [31:0] rdata2   // 读取数据2
);
    reg [31:0] rf [31:0];  // 32个32位寄存器

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            rf[0] <= 32'b0;  // x0寄存器始终为0
            // 其他寄存器可以初始化为0，或者需要的值
        end else if (wen && waddr != 5'b00000) begin
            rf[waddr] <= wdata;  // 写入数据到指定寄存器
        end
    end

    // 读取寄存器值
    always @(*) begin
        rdata1 = (raddr1 == 5'b00000) ? 32'b0 : rf[raddr1];
        rdata2 = (raddr2 == 5'b00000) ? 32'b0 : rf[raddr2];
    end
endmodule

