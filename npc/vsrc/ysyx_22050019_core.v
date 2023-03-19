module ysyx_22050019_core(
  input       clk,
  input       rst_n,
  
  //output [31:0]inst_i,         //1_inst
  //output[63:0]inst_addr,
  
  output[63:0]inst_addr_if_id, //2_inst(目前查看执行状态的指令)
  output[31:0]inst_if_id      
);

//取出指令的逻辑分离出来
wire [31:0]        inst_i ;
/*
fetch fetch_data(
    .clk (clk),
    .rst (rst_n),
    .addr(inst_addr),
    .data(inst_i)
);
*/

// 虚拟sram_axi握手模拟
wire axi_if_sram_rready;
wire axi_if_sram_rvalid;

wire axi_if_sram_arready;
wire axi_if_sram_arvalid;

axi_lite_sram sram(
   .clk               (clk),
   .rst_n             (rst_n),
   
   .s_axi_arvalid     (axi_if_sram_arvalid),
   .s_axi_araddr      (inst_addr_if_id),
   .s_axi_arready     (axi_if_sram_arready),
   
   .s_axi_rready      (axi_if_sram_rready),
   .s_axi_rvalid      (axi_if_sram_rvalid),
   .s_axi_rdata       (inst_i)
);

//fetch模块端口
ysyx_22050019_IFU IFU
(
    .clk               (clk            ),
    .rst_n             (rst_n          ),
    // pc
    .inst_j            (inst_j),
    .snpc              (snpc|snpc_csr_id),

    .inst_i            (inst_i         ),
    .m_axi_rready      (axi_if_sram_rready),
    .m_axi_rvalid      (axi_if_sram_rvalid),

    //.inst_addr         (inst_addr),       // 取出的指令地址
    .m_axi_arready     (axi_if_sram_arready),
    .m_axi_arvalid     (axi_if_sram_arvalid),

    .inst_addr_o       (inst_addr_if_id), // 传入下级模块的地址
    .inst_o            (inst_if_id     )
);



//decode模块端口
//wire [63:0] inst_addr_id_ex;//decode流水
wire [4:0]  raddr1_id_regs ;//读寄存器1索引
wire [4:0]  raddr2_id_regs ;//读寄存器2索引
wire [63:0] rdata1_id_regs ;//读寄存器1数据
wire [63:0] rdata2_id_regs ;//读寄存器2数据
wire [63:0] op1_id_ex      ;//操作数1
wire [63:0] op2_id_ex      ;//操作数2
wire        reg_we_id_ex   ;//reg写使能
wire [4:0]  reg_waddr_id_ex;//写寄存器的索引
wire [`LEN:0]alu_sel       ;//alu控制信号
wire [63:0] snpc           ;
wire        inst_j         ;

wire        ram_we_id_lsu   ;//存储器写使能
wire [63:0] ram_wdata_id_lsu;//mem写索引
wire        ram_re_id_lsu   ;
wire [5:0]  mem_r_wdth     ;
wire [3:0]  mem_w_wdth     ;

ysyx_22050019_IDU IDU(
 .inst_addr_pc  (inst_addr_if_id),
 .inst_i     (inst_if_id),
 
 .snpc       (snpc),
 .inst_j     (inst_j),
 .ram_we     (ram_we_id_lsu),
 .ram_wdata  (ram_wdata_id_lsu),
 .ram_re     (ram_re_id_lsu),

 .raddr1     (raddr1_id_regs),
 .rdata1     (rdata1_id_regs),
 .raddr2     (raddr2_id_regs),
 .rdata2     (rdata2_id_regs),
 .op1        (op1_id_ex),
 .op2        (op2_id_ex),
 .reg_we_o   (reg_we_id_ex),
 .reg_waddr_o(reg_waddr_id_ex),

 .csr_inst_type(csr_inst_type_id_ex),
 .csr_wen      (csr_wen_id_ex),
 .csr_addr     (csr_addr_id_ex),

 .mem_r_wdth (mem_r_wdth),
 .mem_w_wdth (mem_w_wdth),
 .alu_sel    (alu_sel)        
);

/*csr模块的寄存器模块单独列出
目前实现指令
csrw 读csr，将x[rs1]的值写入csr，原来的csr值写回x[rd]
ecall snpc->mtvec,把当前pc保存给mepc，把异常号0xb给mcause
目前实现寄存器
mtvec   存储异常地址入口寄存器，由csrw存入，ecall跳转
mepc    存入发生异常时pc
mcause  根据异常原因存入相应异常情况
mstatus 机械模式寄存器，只实现m模式
小尝试，考虑小范围的使用always在某些地方比写mux能方便些,always（*）在综合时reg信号也视作一根线
*/
wire [7:0] csr_inst_type_id_ex;
wire [11:0]csr_addr_id_ex;
wire       csr_wen_id_ex;
//wire [63:0]rdata1_reg_csr;/* verilator lint_off UNUSED */

wire [63:0]wdate_csr_reg;
/* verilator lint_off UNUSED */wire [63:0]csr_regs_diff[3:0];

wire [63:0]snpc_csr_id;
ysyx_22050019_CSR CSR(
    .clk            (clk),
    .rst_n          (rst_n),
    .pc             (inst_addr_if_id),
  
    .csr_inst_type  (csr_inst_type_id_ex),
    .csr_addr       (csr_addr_id_ex),
    .csr_wen        (csr_wen_id_ex),
    .rdata1_reg_csr (rdata1_id_regs),//从reg读到的数据

    .snpc           (snpc_csr_id),

    .csr_regs_diff  (csr_regs_diff),//csr to reg for diff
    .wdate_csr_reg  (wdate_csr_reg)//向reg写的数据
    

);

//EXecut模块端口
wire [63:0]  wdata_ex_reg  ;
wire         reg_we_ex_reg ;
wire [4:0]   waddr_ex_reg  ;

ysyx_22050019_EXU EXU(
 .alu_sel(alu_sel),

 .op1         (op1_id_ex),
 .op2         (op2_id_ex),
 .reg_we_i    (reg_we_id_ex),
 .reg_waddr_i (reg_waddr_id_ex),

 .result      (result_exu_lsu),
 .wdata       (wdata_ex_reg),
 .reg_we      (reg_we_ex_reg),
 .waddr       (waddr_ex_reg)
);

// lsu模块端口
wire [63:0] wdata_lsu_wb;
wire        ram_we_lsu_mem   ;//存储器写使能
wire [63:0] ram_waddr_lsu_mem ;//mem索引
wire [63:0] ram_wdata_lsu_mem ;
wire        ram_re_lsu_mem   ;//存储器读使能
wire [63:0] ram_rdata_mem_lsu ;
wire [63:0] ram_raddr_lsu_mem ;//mem读索引
wire [7:0]  wmask           ;
wire [63:0] result_exu_lsu;

ysyx_22050019_LSU LSU(
 .result      (result_exu_lsu),
 .ram_we_i    (ram_we_id_lsu),
 .ram_wdata_i (ram_wdata_id_lsu),
 .ram_re_i    (ram_re_id_lsu),
 .ram_rdata_i (ram_rdata_mem_lsu),

 .mem_r_wdth  (mem_r_wdth),
 .mem_w_wdth  (mem_w_wdth),

 .ram_we      (ram_we_lsu_mem),
 .ram_waddr   (ram_waddr_lsu_mem),
 .ram_wdata   (ram_wdata_lsu_mem),
 .ram_re      (ram_re_lsu_mem),
 .ram_raddr   (ram_raddr_lsu_mem),
 .wmask       (wmask),

 .wdata       (wdata_lsu_wb)
);

//MEM读取端口
ysyx_22050019_mem MEM (
  .ren(ram_re_lsu_mem),
  .wen(ram_we_lsu_mem),

  .raddr(ram_raddr_lsu_mem),
  .rdata(ram_rdata_mem_lsu),

  .waddr(ram_waddr_lsu_mem),
  .wdata(ram_wdata_lsu_mem),
  .mask(wmask)
);

//wb回写模块端口
wire [63:0] wdata_wb_reg ;
ysyx_22050019_WBU WBU(
 // 写入寄存器控制信号
 .reg_wen      (reg_we_ex_reg),
 .reg_lsu_wen  (ram_re_id_lsu),

 .wdata_exu_wbu(wdata_ex_reg),
 .wdata_lsu_wbu(wdata_lsu_wb),
 .wdata_csr_wbu(wdate_csr_reg),

 .wdata_o      (wdata_wb_reg)
);

//寄存器组端口
ysyx_22050019_regs REGS(
 .clk        (clk),
 .now_pc     (inst_addr_if_id),         
 .wdata      (wdata_wb_reg),
 .waddr      (waddr_ex_reg),
 .wen        (reg_we_ex_reg),

 .csr_regs_diff(csr_regs_diff),
 
 .raddr1     (raddr1_id_regs),
 .raddr2     (raddr2_id_regs),
 .rdata1     (rdata1_id_regs),
 .rdata2     (rdata2_id_regs)
);

endmodule
