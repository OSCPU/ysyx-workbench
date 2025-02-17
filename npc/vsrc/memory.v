module Memory (
    input clk,
    input rst,
    input [31:0] addr,    // 内存地址
    input [31:0] write_data,  // 写数据
    input mem_read,          // 读使能
    input mem_write,         // 写使能
    output reg [31:0] read_data  // 读数据
);
    // 声明一个Memory类实例，C++部分将会实例化和访问
    reg [31:0] memory [0:1023]; // 1KB 存储器

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            read_data <= 32'b0;  // 初始化
        end else if (mem_read) begin
            read_data <= memory[addr];  // 读取内存
        end else if (mem_write) begin
             memory[addr] <= write_data;
        end
    end
endmodule

