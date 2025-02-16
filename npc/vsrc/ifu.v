module IFU (
    input clk,
    input rst,
    input [31:0] pc,
    output [31:0] instruction
);
    wire [31:0] inst_mem [0:1023];  // 假设有 1024 个 32 位的指令

    assign instruction = inst_mem[pc[9:0]];  // 根据 PC 取指令
endmodule

