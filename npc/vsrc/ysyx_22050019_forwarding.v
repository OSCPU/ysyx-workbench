module ysyx_22050019_forwarding (
  input  wire  [4:0] reg_raddr_1_id,
  input  wire  [4:0] reg_raddr_2_id,
  input  wire  [4:0] reg_waddr_exu,
  input  wire  [4:0] reg_waddr_lsu,
  input  wire        reg_wen_exu,
  input  wire        reg_wen_lsu,
  input  wire  [4:0] reg_raddr_2_mem,
  input  wire        ram_store_en_mem,
  input  wire        ram_load_en_wb,

  output wire  [1:0] ForwardA,
  output wire  [1:0] ForwardB,
  output wire        ForwardC
);

  /* 对于将lsu写wb的写寄存器通路与来自exu写的进行了合并，这样如果exu拉下的数据的前递，在lsu阶段有机会补上 */

  /* rs1 MEM前推 */
  assign ForwardA[1] = reg_wen_mem && (reg_waddr_mem != 0) && (reg_waddr_mem == reg_raddr_1_ex);
  /* rs1 WB前推 */
  assign ForwardA[0] = reg_wen_wb && (reg_waddr_wb != 0) && (!(reg_wen_mem && (reg_waddr_mem != 0) && (reg_waddr_mem == reg_raddr_1_ex))) && (reg_waddr_wb == reg_raddr_1_ex);

  /* rs2 MEM前推 */
  assign ForwardB[1] = reg_wen_mem && (reg_waddr_mem != 0) && (reg_waddr_mem == reg_raddr_2_ex);
  /* rs2 WB前推 */
  assign ForwardB[0] = reg_wen_wb && (reg_waddr_wb != 0) && (!(reg_wen_mem && (reg_waddr_mem != 0) && (reg_waddr_mem == reg_raddr_2_ex))) && (reg_waddr_wb == reg_raddr_2_ex);

  /* 专门解决load-store数据冒险
   * load取出要存入寄存器的值，而store的rs2也需要那个值，则传递
   * mem执行store && wb执行load && 写入存储器的不为0寄存器 && load到寄存器地址 == mem需要的rs2
   */
  assign ForwardC = ram_store_en_mem && ram_load_en_wb && (reg_raddr_2_mem != 0) && (reg_waddr_wb == reg_raddr_2_mem);
  
endmodule
