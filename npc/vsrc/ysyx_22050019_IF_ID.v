module ysyx_22050019_IF_ID (
    input clk,
    input rst_n,
    input [63:0] pc_i  ,
    input [31:0] inst_i,

    output[63:0] pc_o  ,
    output[31:0] inst_o 
);
assign pc_o   = pc_i  ;
assign inst_o = inst_i;
endmodule