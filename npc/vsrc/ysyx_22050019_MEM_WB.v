module ysyx_22050019_MEM_WB (
    input        clk                 ,
    input        rst_n               ,
    input [63:0] pc_i                ,
    input        reg_we_exu_lsu_i    ,
    input        reg_we_lsu_i        ,
    input [4:0]  reg_waddr_exu_i     ,
    input [4:0]  reg_waddr_lsu_i     ,
    input [63:0] reg_wdata_lsu_i     ,
    input [63:0] reg_wdata_csr_i     ,
    input [63:0] reg_wdata_exu_i     ,
    input  [63:0]csr_regs_diff_i[3:0],

    output [63:0]pc_o                ,
    output       reg_we_wbu_o        ,
    output [4:0] reg_waddr_wbu_o     ,
    output [63:0]reg_wdata_wbu_o     ,
    output [63:0]csr_regs_diff_o[3:0]
);
assign reg_we_wbu_o     = reg_we_exu_lsu_i|reg_we_lsu_i  ;
assign reg_waddr_wbu_o  = reg_waddr_exu_i|reg_waddr_lsu_i;
assign reg_wdata_wbu_o  = reg_we_exu_lsu_i ? reg_wdata_exu_i|reg_wdata_csr_i
                                            : reg_we_lsu_i ? reg_wdata_lsu_i : 64'b0;
assign csr_regs_diff_o[3:0]= csr_regs_diff_i;
assign pc_o             = pc_i           ;
endmodule