module ysyx_22050019_EX_MEM (
    input           clk                 ,
    input           rst_n               ,
    input  [63:0]   pc_i                ,
    input  [63:0]   result_i            ,
    input  [63:0]   wdata_exu_reg_i     ,
    input           ram_we_i            ,
    input  [63:0]   ram_wdata_i         ,
    input  [3:0]    mem_w_wdth_i        ,
    input           ram_re_i            ,
    input  [5:0]    mem_r_wdth_i        ,
    input           reg_we_i            ,
    input  [4:0]    reg_waddr_i         ,
    input  [63:0]   wdate_csr_reg_i     ,
    input  [63:0]   csr_regs_diff_i[3:0],

    output [63:0]   pc_o                ,
    output [63:0]   result_o            ,
    output [63:0]   wdata_exu_reg_o     ,
    output          ram_we_o            ,
    output [63:0]   ram_wdata_o         ,
    output [3:0]    mem_w_wdth_o        ,
    output          ram_re_o            ,
    output [5:0]    mem_r_wdth_o        ,
    output          reg_we_o            ,
    output [4:0]    reg_waddr_o         ,
    output [63:0]   wdate_csr_reg_o     ,
    output [63:0]   csr_regs_diff_o[3:0]
);
assign result_o            = result_i       ;
assign wdata_exu_reg_o     = wdata_exu_reg_i;
assign ram_we_o            = ram_we_i       ;
assign ram_wdata_o         = ram_wdata_i    ;
assign mem_w_wdth_o        = mem_w_wdth_i   ;
assign ram_re_o            = ram_re_i       ;
assign mem_r_wdth_o        = mem_r_wdth_i   ;
assign reg_we_o            = reg_we_i       ;
assign reg_waddr_o         = reg_waddr_i    ;
assign wdate_csr_reg_o     = wdate_csr_reg_i;
assign csr_regs_diff_o     = csr_regs_diff_i;
assign pc_o                = pc_i           ;
endmodule

