// 控制写回reg的数据
module ysyx_22050019_WBU(
 // 写入寄存器控制信号
 input   reg_wen,
 input   reg_lsu_wen,

 input   [63:0] wdata_exu_wbu,
 input   [63:0] wdata_lsu_wbu,
 input   [63:0] wdata_csr_wbu,

 output  [63:0] wdata_o
);
 // 通过使能信号判断是谁传出来写的
 assign wdata_o = reg_wen ? wdata_exu_wbu | wdata_csr_wbu : 
                            reg_lsu_wen ? wdata_lsu_wbu : 64'b0 ;
endmodule

