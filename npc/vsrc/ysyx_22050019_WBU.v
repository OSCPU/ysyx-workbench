// 控制写回reg的数据,这里放到lsu后面主要是考虑给处理冒险单元那方便判断遗漏的没有写的数据
// 这样可以全覆盖五级流水两周期读一条指令时出现的exu需要前递的数据，可以在lsu阶段补上。
module ysyx_22050019_WBU(
    input            reg_we_exu_lsu_i    ,
    input            reg_we_lsu_i        ,
    input     [4:0]  reg_waddr_exu_i     ,
    input     [4:0]  reg_waddr_lsu_i     ,
    input     [63:0] reg_wdata_lsu_i     ,
    input     [63:0] reg_wdata_csr_i     ,
    input     [63:0] reg_wdata_exu_i     ,

    output reg       reg_we_wbu_o        ,
    output reg[4:0]  reg_waddr_wbu_o     ,
    output reg[63:0] reg_wdata_wbu_o     
);
assign reg_we_wbu_o         = reg_we_exu_lsu_i|reg_we_lsu_i  ;
assign reg_waddr_wbu_o      = reg_waddr_exu_i|reg_waddr_lsu_i;
assign reg_wdata_wbu_o      = reg_we_lsu_i ? (reg_we_lsu_i ? reg_wdata_lsu_i : 64'b00) : (reg_wdata_exu_i|reg_wdata_csr_i);
endmodule