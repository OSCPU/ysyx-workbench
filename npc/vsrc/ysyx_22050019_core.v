module ysyx_22050019_core(
  input       clk,
  input       rst_n,
  
  //output [31:0]inst_i,         //1_inst
  //output[63:0]inst_addr,
  
  output[63:0]pc, //2_inst(目前查看执行状态的指令)
  output[31:0]inst      
);

//取出指令的逻辑分离出来
wire [63:0]        inst_i ;

// 虚拟sram_axi握手模拟
wire axi_if_sram_rready;
wire axi_if_sram_rvalid;
wire [1:0] axi_if_sram_resp  ;
wire axi_if_sram_arready;
wire axi_if_sram_arvalid;
wire ifu_commite;
wire [63:0]pc_ifu;
wire [31:0]inst_ifu;
//fetch模块端口
ysyx_22050019_IFU IFU
(
    .clk               (clk                ),
    .rst_n             (rst_n              ),
    // pc
    .inst_j            (inst_j             ),
    .snpc              (snpc|snpc_csr_id   ),

    .inst_i            (inst_i             ),
    .m_axi_rready      (axi_if_sram_rready ),
    .m_axi_rvalid      (axi_if_sram_rvalid ),
    .m_axi_r_resp_i    (axi_if_sram_resp   ),

    //.inst_addr         (inst_addr),       // 取出的指令地址
    .m_axi_arready     (stll_ar_ready      ),
    .m_axi_arvalid     (axi_if_sram_arvalid),
    .inst_commite      (ifu_commite        ),

    .inst_addr_o       (pc_ifu             ), // 传入下级模块的地址
    .inst_o            (inst_ifu           )
);

//拉出来一个控制器来解决读hit与读总线的冲突,这是一个临时的方案

reg stll_ar_ready ;
reg stll_ar_rvalid;
always@(*) begin
  if(rst_n) begin
  stll_ar_ready = 0;
  stll_ar_rvalid= 0;
  end
  else if(axi_dcache_arbiter_ar_ready|axi_dcache_arbiter_r_ready|axi_dcache_aw_valid&axi_dcache_aw_ready|axi_dcache_w_ready|axi_dcache_b_ready&axi_dcache_b_ready) begin
    stll_ar_rvalid = 0 ;
    stll_ar_ready  = 0 ;
  end
  else begin
    stll_ar_rvalid = axi_if_sram_arvalid;
    stll_ar_ready  = axi_if_sram_arready;
  end 
end
//==================IF/ID=======================
wire [63:0] pc_ifu_id  ;
wire [31:0] inst_ifu_id;
wire commite_if_id;
ysyx_22050019_IF_ID IF_ID(
    .clk      ( clk          ),
    .rst_n    ( rst_n        ),
    .commite_i( ifu_commite  ),
    .pc_i     ( pc_ifu       ),
    .inst_i   ( inst_ifu     ),
    .commite_o( commite_if_id),
    .pc_o     ( pc_ifu_id    ),
    .inst_o   ( inst_ifu_id  )
);


//decode模块端口
//wire [63:0] inst_addr_id_ex;//decode流水
wire [4:0]  raddr1_id_regs ;//读寄存器1索引
wire [4:0]  raddr2_id_regs ;//读寄存器2索引
wire [63:0] rdata1_id_regs ;//读寄存器1数据
wire [63:0] rdata2_id_regs ;//读寄存器2数据
wire [63:0] op1_id      ;//操作数1
wire [63:0] op2_id      ;//操作数2
wire        reg_we_id   ;//reg写使能
wire [4:0]  reg_waddr_id;//写寄存器的索引
wire [`LEN:0]alu_sel       ;//alu控制信号
wire [63:0] snpc           ;
wire        inst_j         ;

wire        ram_we_id   ;//存储器写使能
wire [63:0] ram_wdata_id;//mem写数据
wire        ram_re_id   ;
wire [5:0]  mem_r_wdth     ;
wire [3:0]  mem_w_wdth     ;

ysyx_22050019_IDU IDU(
 .inst_addr_pc (pc_ifu_id            ),
 .inst_i       (inst_ifu_id          ),
 
 .snpc         (snpc                 ),
 .inst_j       (inst_j               ),
 .ram_we       (ram_we_id            ),
 .ram_wdata    (ram_wdata_id         ),
 .ram_re       (ram_re_id            ),

 .raddr1       (raddr1_id_regs       ),
 .rdata1       (rdata1_id_regs       ),
 .raddr2       (raddr2_id_regs       ),
 .rdata2       (rdata2_id_regs       ),
 .op1          (op1_id               ),
 .op2          (op2_id               ),
 .reg_we_o     (reg_we_id            ),
 .reg_waddr_o  (reg_waddr_id         ),

 .csr_inst_type(csr_inst_type_id_csr ),
 .csr_wen      (csr_wen_id_csr       ),
 .csr_addr     (csr_addr_id_csr      ),

 .mem_r_wdth   (mem_r_wdth           ),
 .mem_w_wdth   (mem_w_wdth           ),
 .alu_sel      (alu_sel              )        
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
wire [7:0] csr_inst_type_id_csr;
wire [11:0]csr_addr_id_csr;
wire       csr_wen_id_csr;
//wire [63:0]rdata1_reg_csr;/* verilator lint_off UNUSED */

wire [63:0]wdate_csr;
/* verilator lint_off UNUSED */wire [63:0]csr_regs_diff[3:0];

wire [63:0]snpc_csr_id;
ysyx_22050019_CSR CSR(
    .clk            (clk                 ),
    .rst_n          (rst_n               ),
    .pc             (pc_ifu_id           ),
  
    .csr_inst_type  (csr_inst_type_id_csr),
    .csr_addr       (csr_addr_id_csr     ),
    .csr_wen        (csr_wen_id_csr      ),
    .rdata1_reg_csr (rdata1_id_regs      ),//从reg读到的数据

    .snpc           (snpc_csr_id         ),

    .csr_regs_diff  (csr_regs_diff       ),//csr to reg for diff
    .wdate_csr_reg  (wdate_csr           )//向reg写的数据
    

);

//==================ID/EX=======================
wire         ram_we_id_exu   ;
wire [63:0]  ram_wdata_id_exu;
wire [3:0]   mem_w_wdth_exu  ;
wire         ram_re_id_exu   ;
wire [5:0]   mem_r_wdth_exu  ;
wire [63:0]  op1_id_exu      ;
wire [63:0]  op2_id_exu      ;
wire         reg_we_id_exu   ;
wire [4:0]   reg_waddr_id_exu;
wire [`LEN:0]alu_sel_exu     ;
wire [63:0]  wdate_csr_exu   ;
wire [63:0]  pc_id_exu       ;
wire [31:0]  inst_id_ex      ;
/* verilator lint_off UNUSED */wire [63:0]csr_regs_diff_exu[3:0];//验证用
wire commite_id_ex;
ysyx_22050019_ID_EX ID_EX(
    .clk              ( clk              ),
    .rst_n            ( rst_n            ),
    .pc_i             ( pc_ifu_id        ),
    .inst_i           ( inst_ifu_id      ),
    .commite_i        ( commite_if_id    ),
    .ram_we_i         ( ram_we_id        ),
    .ram_wdata_i      ( ram_wdata_id     ),
    .mem_w_wdth_i     ( mem_w_wdth       ),
    .ram_re_i         ( ram_re_id        ),
    .mem_r_wdth_i     ( mem_r_wdth       ),
    .op1_i            ( op1_id           ),
    .op2_i            ( op2_id           ),
    .reg_we_i         ( reg_we_id        ),
    .reg_waddr_i      ( reg_waddr_id     ),
    .alu_sel_i        ( alu_sel          ),
    .wdate_csr_reg_i  ( wdate_csr        ),
    .csr_regs_diff_i  ( csr_regs_diff    ),

    .pc_o             ( pc_id_exu        ),
    .inst_o           ( inst_id_ex       ),
    .commite_o        ( commite_id_ex    ),
    .ram_we_o         ( ram_we_id_exu    ),
    .ram_wdata_o      ( ram_wdata_id_exu ),
    .mem_w_wdth_o     ( mem_w_wdth_exu   ),
    .ram_re_o         ( ram_re_id_exu    ),
    .mem_r_wdth_o     ( mem_r_wdth_exu   ),
    .op1_o            ( op1_id_exu       ),
    .op2_o            ( op2_id_exu       ),
    .reg_we_o         ( reg_we_id_exu    ),
    .reg_waddr_o      ( reg_waddr_id_exu ),
    .alu_sel_o        ( alu_sel_exu      ),
    .wdate_csr_reg_o  ( wdate_csr_exu    ),
    .csr_regs_diff_o  ( csr_regs_diff_exu)
);

//EXecut模块端口
wire [63:0]  wdata_ex_reg  ;
//wire         reg_we_id_exu ;
//wire [4:0]   reg_waddr_id_exu  ;
wire [63:0] result_exu;
ysyx_22050019_EXU EXU(
 .alu_sel     (alu_sel_exu ),

 .op1         (op1_id_exu  ),
 .op2         (op2_id_exu  ),

 .result      (result_exu  ),
 .wdata       (wdata_ex_reg)
);

//==================EX/MEM======================
wire [63:0]  result_exu_lsu   ;
wire         ram_we_exu_lsu   ;
wire [63:0]  ram_wdata_exu_lsu;
wire [3:0]   mem_w_wdth_lsu   ;
wire         ram_re_exu_lsu   ;
wire [5:0]   mem_r_wdth_lsu   ;
wire         reg_we_exu_lsu   ;
wire [4:0]   reg_waddr_exu_lsu;
wire [63:0]  wdate_csr_lsu    ;
wire [63:0]  wdata_reg_exu_lsu;
/* verilator lint_off UNUSED */wire [63:0]csr_regs_diff_lsu[3:0];//验证用
wire [63:0]  pc_exu_mem       ;
wire [31:0]  inst_exu_mem     ;
wire commite_ex_mem;
ysyx_22050019_EX_MEM EX_MEM(
    .clk              ( clk              ),
    .rst_n            ( rst_n            ),
    .pc_i             ( pc_id_exu        ),
    .inst_i           ( inst_id_ex       ),
    .commite_i        ( commite_id_ex    ),
    .result_i         ( result_exu       ),
    .wdata_exu_reg_i  ( wdata_ex_reg     ),
    .ram_we_i         ( ram_we_id_exu    ),
    .ram_wdata_i      ( ram_wdata_id_exu ),
    .mem_w_wdth_i     ( mem_w_wdth_exu   ),
    .ram_re_i         ( ram_re_id_exu    ),
    .mem_r_wdth_i     ( mem_r_wdth_exu   ),
    .reg_we_i         ( reg_we_id_exu    ),
    .reg_waddr_i      ( reg_waddr_id_exu ),
    .wdate_csr_reg_i  ( wdate_csr_exu    ),
    .csr_regs_diff_i  ( csr_regs_diff_exu),

    .pc_o             ( pc_exu_mem       ),
    .inst_o           ( inst_exu_mem     ), 
    .commite_o        ( commite_ex_mem   ),
    .result_o         ( result_exu_lsu   ),
    .wdata_exu_reg_o  ( wdata_reg_exu_lsu),
    .ram_we_o         ( ram_we_exu_lsu   ),
    .ram_wdata_o      ( ram_wdata_exu_lsu),
    .mem_w_wdth_o     ( mem_w_wdth_lsu   ),
    .ram_re_o         ( ram_re_exu_lsu   ),
    .mem_r_wdth_o     ( mem_r_wdth_lsu   ),
    .reg_we_o         ( reg_we_exu_lsu   ),
    .reg_waddr_o      ( reg_waddr_exu_lsu),
    .wdate_csr_reg_o  ( wdate_csr_lsu    ),
    .csr_regs_diff_o  ( csr_regs_diff_lsu)
);

// lsu模块端口
wire [63:0] wdata_lsu_wb;
//wire        ram_we_lsu_mem   ;//存储器写使能
wire [31:0] ram_waddr_lsu_mem ;//mem索引
wire        axi_lsu_sram_aw_ready = uncache ? axi_dcache_arbiter_aw_ready  : axi_lsu_dcache_aw_ready;
wire        axi_lsu_sram_aw_valid;
wire [63:0] ram_wdata_lsu_mem    ;
wire [7:0]  wmask             ;
wire        axi_lsu_sram_w_ready  = uncache ? axi_dcache_arbiter_w_ready   : axi_lsu_dcache_w_ready ;
wire        axi_lsu_sram_w_valid;
wire [1:0]  axi_lsu_sram_b_wresp  = uncache ? axi_dcache_arbiter_b_resp    : axi_lsu_dcache_b_resp  ;
wire        axi_lsu_sram_b_ready;
wire        axi_lsu_sram_b_valid  = uncache ? axi_dcache_arbiter_b_valid   : axi_lsu_dcache_b_valid ;
//wire        ram_re_lsu_mem   ;//存储器读使能
wire [63:0] ram_rdata_mem_lsu     = uncache ? axi_dcache_arbiter_r_data    : axi_lsu_dcache_r_data;
wire [31:0] ram_raddr_lsu_mem ;//mem读索引
wire        axi_lsu_sram_ar_ready = uncache ? axi_dcache_arbiter_ar_ready  : axi_lsu_dcache_ar_ready;
wire        axi_lsu_sram_ar_valid;
wire [1:0]  axi_lsu_sram_r_resp ;
wire        axi_lsu_sram_r_ready;
wire        axi_lsu_sram_r_valid  = uncache ? axi_dcache_arbiter_r_valid : axi_lsu_dcache_r_valid;


wire        wen_lsu_reg;
wire [4:0]  waddr_lsu_reg;
ysyx_22050019_LSU LSU(
 .clk            (clk                  ),
 .rst            (rst_n                ),
 .result         (result_exu_lsu       ),
 .ram_we_i       (ram_we_exu_lsu       ),
 .ram_wdata_i    (ram_wdata_exu_lsu    ),
 .ram_re_i       (ram_re_exu_lsu       ),
 
 .mem_r_wdth     (mem_r_wdth_lsu       ),
 .mem_w_wdth     (mem_w_wdth_lsu       ),
   
 //.ram_we       (ram_we_lsu_mem),
 .ram_waddr      (ram_waddr_lsu_mem    ),
 .m_axi_aw_ready (axi_lsu_sram_aw_ready),
 .m_axi_aw_valid (axi_lsu_sram_aw_valid),
 .ram_wdata      (ram_wdata_lsu_mem    ),
 .wmask          (wmask                ),
 .m_axi_w_ready  (axi_lsu_sram_w_ready ),
 .m_axi_w_valid  (axi_lsu_sram_w_valid ),
 .ram_wresp_i    (axi_lsu_sram_b_wresp ),
 .m_axi_b_ready  (axi_lsu_sram_b_ready ),
 .m_axi_b_valid  (axi_lsu_sram_b_valid ),
 //.ram_re         (ram_re_lsu_mem),
 .ram_raddr      (ram_raddr_lsu_mem    ),
 .m_axi_ar_ready (axi_lsu_sram_ar_ready),
 .m_axi_ar_valid (axi_lsu_sram_ar_valid),
 .ram_rdata_i    (ram_rdata_mem_lsu    ),
 .m_axi_r_resp   (axi_lsu_sram_r_resp  ),
 .m_axi_r_ready  (axi_lsu_sram_r_ready ),
 .m_axi_r_valid  (axi_lsu_sram_r_valid ),


 .waddr_reg_i    (reg_waddr_id_exu     ),
 .wen_reg_o      (wen_lsu_reg          ),
 .waddr_reg_o    (waddr_lsu_reg        ),
 .wdata_reg_o    (wdata_lsu_wb         )
);

//icache的缓存区设置
wire        axi_icache_sram_ar_valid ;
wire        axi_icache_sram_ar_ready ;
wire [31:0] axi_icache_sram_ar_addr  ;
wire        axi_icache_sram_r_ready  ;
wire        axi_icache_sram_r_valid  ;
wire [1:0]  axi_icache_sram_r_resp   ;
wire [63:0] axi_icache_sram_r_data   ;
ysyx_22050019_icache I_CACHE(
    .clk               ( clk                      ),
    .rst               ( rst_n                    ),

    .ar_valid_i        ( stll_ar_rvalid           ),
    .ar_ready_o        ( axi_if_sram_arready      ),
    .ar_addr_i         ( pc_ifu                   ),
    .r_data_valid_o    ( axi_if_sram_rvalid       ),
    .r_data_ready_i    ( axi_if_sram_rready       ),
    .r_resp_i          ( axi_if_sram_resp         ),
    .r_data_o          ( inst_i                   ),

    .cache_ar_valid_o  ( axi_icache_sram_ar_valid ),
    .cache_ar_ready_i  ( axi_icache_sram_ar_ready ),
    .cache_ar_addr_o   ( axi_icache_sram_ar_addr  ),
    .cache_r_ready_o   ( axi_icache_sram_r_ready  ),
    .cache_r_valid_i   ( axi_icache_sram_r_valid  ),
    .cache_r_resp_i    ( axi_icache_sram_r_resp   ),
    .cache_r_data_i    ( axi_icache_sram_r_data   )
);

//***********************************************************************
// dcache的信号处理模块，包含uncache和的cache的分流处理
//***********************************************************************
//uncache的控制逻辑
//wire uncache=(((ram_waddr_lsu_mem|ram_raddr_lsu_mem)<32'h80000000)||(ram_waddr_lsu_mem|ram_raddr_lsu_mem)>32'h88000000);
wire uncache=1;
//=======================================================================
//dcache与uncache信号的生成与选择控制
wire        axi_lsu_dcache_aw_ready ;
wire        axi_lsu_dcache_aw_valid = uncache ? 0 : axi_lsu_sram_aw_valid;
wire [31:0] axi_lsu_dcache_aw_addr  = uncache ? 0 : ram_waddr_lsu_mem    ;
wire        axi_lsu_dcache_w_ready  ;
wire        axi_lsu_dcache_w_valid  = uncache ? 0 : axi_lsu_sram_w_valid ;
wire [63:0] axi_lsu_dcache_w_data   = uncache ? 0 : ram_wdata_lsu_mem    ;
wire [7:0]  axi_lsu_dcache_w_strb   = uncache ? 0 : wmask                ;
wire        axi_lsu_dcache_b_ready  = uncache ? 0 : axi_lsu_sram_b_ready ;
wire        axi_lsu_dcache_b_valid  ;
wire [1:0]  axi_lsu_dcache_b_resp   ; 
wire        axi_lsu_dcache_ar_ready ; 
wire        axi_lsu_dcache_ar_valid = uncache ? 0 : axi_lsu_sram_ar_valid; 
wire [31:0] axi_lsu_dcache_ar_addr  = uncache ? 0 : ram_raddr_lsu_mem    ; 
wire        axi_lsu_dcache_r_ready  = uncache ? 0 : axi_lsu_sram_r_ready ;
wire        axi_lsu_dcache_r_valid  ;
wire [1:0]  axi_lsu_dcache_r_resp   = uncache ? 0 : axi_lsu_sram_r_resp  ;    
wire [63:0] axi_lsu_dcache_r_data   ;

wire        axi_dcache_aw_ready    = uncache ? 0 : axi_dcache_arbiter_aw_ready  ; 
wire        axi_dcache_aw_valid    ;
wire [31:0] axi_dcache_aw_addr     ;
wire        axi_dcache_w_ready     = uncache ? 0 : axi_dcache_arbiter_w_ready   ; 
wire        axi_dcache_w_valid     ;
wire [63:0] axi_dcache_w_data      ;
wire [7:0]  axi_dcache_w_strb      ;
wire        axi_dcache_b_ready     ;
wire        axi_dcache_b_valid     = uncache ? 0 : axi_dcache_arbiter_b_valid   ; 
wire [1:0]  axi_dcache_b_resp      = uncache ? 0 : axi_dcache_arbiter_b_resp    ; 
wire        axi_dcache_ar_ready    = uncache ? 0 : axi_dcache_arbiter_ar_ready  ; 
wire        axi_dcache_ar_valid    ;
wire [31:0] axi_dcache_ar_addr     ;
wire        axi_dcache_r_ready     ;
wire        axi_dcache_r_valid     = uncache ? 0 : axi_dcache_arbiter_r_valid   ; 
wire [1:0]  axi_dcache_r_resp      = uncache ? 0 : axi_dcache_arbiter_r_resp    ; 
wire [63:0] axi_dcache_r_data      = uncache ? 0 : axi_dcache_arbiter_r_data    ; 

wire        axi_dcache_arbiter_aw_ready ;
wire        axi_dcache_arbiter_aw_valid = uncache ? axi_lsu_sram_aw_valid  : axi_dcache_aw_valid ;
wire [31:0] axi_dcache_arbiter_aw_addr  = uncache ? ram_waddr_lsu_mem[31:0]: axi_dcache_aw_addr  ;
wire        axi_dcache_arbiter_w_ready  ;
wire        axi_dcache_arbiter_w_valid  = uncache ? axi_lsu_sram_w_valid  : axi_dcache_w_valid  ;
wire [63:0] axi_dcache_arbiter_w_data   = uncache ? ram_wdata_lsu_mem     : axi_dcache_w_data   ;
wire [7:0]  axi_dcache_arbiter_w_strb   = uncache ? wmask                 : axi_dcache_w_strb   ;
wire        axi_dcache_arbiter_b_ready  = uncache ? axi_lsu_sram_b_ready  : axi_dcache_b_ready  ;
wire        axi_dcache_arbiter_b_valid  ;
wire [1:0]  axi_dcache_arbiter_b_resp   ;
wire        axi_dcache_arbiter_ar_ready ;
wire        axi_dcache_arbiter_ar_valid = uncache ? axi_lsu_sram_ar_valid : axi_dcache_ar_valid ;
wire [31:0] axi_dcache_arbiter_ar_addr  = uncache ? ram_raddr_lsu_mem[31:0]     : axi_dcache_ar_addr;
wire        axi_dcache_arbiter_r_ready  = uncache ? axi_lsu_sram_r_ready  : axi_dcache_r_ready  ;
wire        axi_dcache_arbiter_r_valid  ;
wire [1:0]  axi_dcache_arbiter_r_resp   ;
wire [63:0] axi_dcache_arbiter_r_data   ;

ysyx_22050019_dcache D_CACHE(
    .clk               ( clk                            ),
    .rst               ( rst_n                          ),
    .ar_valid_i        ( axi_lsu_dcache_ar_valid        ),
    .ar_ready_o        ( axi_lsu_dcache_ar_ready        ),
    .ar_addr_i         ( axi_lsu_dcache_ar_addr         ),
    .r_data_valid_o    ( axi_lsu_dcache_r_valid         ),
    .r_data_ready_i    ( axi_lsu_dcache_r_ready         ),
    .r_resp_i          ( axi_lsu_dcache_r_resp          ),
    .r_data_o          ( axi_lsu_dcache_r_data          ),
    .aw_valid_i        ( axi_lsu_dcache_aw_valid        ),
    .aw_ready_o        ( axi_lsu_dcache_aw_ready        ),
    .aw_addr_i         ( axi_lsu_dcache_aw_addr         ),
    .w_data_valid_i    ( axi_lsu_dcache_w_valid         ),
    .w_data_ready_o    ( axi_lsu_dcache_w_ready         ),
    .w_w_strb_i        ( axi_lsu_dcache_w_strb          ),
    .w_data_i          ( axi_lsu_dcache_w_data          ),
    .b_ready_i         ( axi_lsu_dcache_b_ready         ),
    .b_valid_o         ( axi_lsu_dcache_b_valid         ),
    .b_resp_o          ( axi_lsu_dcache_b_resp          ),
    
    .cache_aw_valid_o  ( axi_dcache_aw_valid  ),
    .cache_aw_ready_i  ( axi_dcache_aw_ready  ),
    .cache_aw_addr_o   ( axi_dcache_aw_addr   ),
    .cache_w_ready_i   ( axi_dcache_w_ready   ),
    .cache_w_valid_o   ( axi_dcache_w_valid   ),
    .cache_w_data_o    ( axi_dcache_w_data    ),
    .cache_w_strb_o    ( axi_dcache_w_strb    ),
    .cache_b_ready_o   ( axi_dcache_b_ready   ),
    .cache_b_valid_i   ( axi_dcache_b_valid   ),
    .cache_b_resp_i    ( axi_dcache_b_resp    ),
    .cache_ar_valid_o  ( axi_dcache_ar_valid  ),
    .cache_ar_ready_i  ( axi_dcache_ar_ready  ),
    .cache_ar_addr_o   ( axi_dcache_ar_addr   ),
    .cache_r_ready_o   ( axi_dcache_r_ready   ),
    .cache_r_valid_i   ( axi_dcache_r_valid   ),
    .cache_r_resp_i    ( axi_dcache_r_resp    ),
    .cache_r_data_i    ( axi_dcache_r_data    )
);

//***********************************************************************
//ifu没有写同到访问，这里用拉空接地来表示方便仿真
wire s1_axi_aw_ready_o;
wire s1_axi_w_ready_o ;
wire s1_axi_b_valid_o ;
wire [1:0] s1_axi_b_resp_o;
// ifu和lsu的仲裁
// 目前只做了读通道的仲裁，写通道展示没有需要仲裁的冲突点
ysyx_22050133_axi_arbiter ARBITER(
    .clk               ( clk                         ),
    .rst               ( rst_n                       ),

    // IFU<>ARBITER
    // Advanced eXtensible Interface Slave1
    .s1_axi_aw_ready_o ( s1_axi_aw_ready_o           ),
    .s1_axi_aw_valid_i ( 1'b0                        ),
    .s1_axi_aw_addr_i  ( 32'b0                       ),

    .s1_axi_w_ready_o  ( s1_axi_w_ready_o            ),
    .s1_axi_w_valid_i  ( 1'b0                        ),
    .s1_axi_w_data_i   ( 64'b0                       ),
    .s1_axi_w_strb_i   ( 8'b0                        ),

    .s1_axi_b_ready_i  ( 1'b0                        ),
    .s1_axi_b_valid_o  ( s1_axi_b_valid_o            ),
    .s1_axi_b_resp_o   ( s1_axi_b_resp_o             ),

    .s1_axi_ar_valid_i ( axi_icache_sram_ar_valid    ),
    .s1_axi_ar_ready_o ( axi_icache_sram_ar_ready    ),
    .s1_axi_ar_addr_i  ( axi_icache_sram_ar_addr     ),

    .s1_axi_r_valid_o  ( axi_icache_sram_r_valid     ),
    .s1_axi_r_ready_i  ( axi_icache_sram_r_ready     ),
    .s1_axi_r_resp_o   ( axi_icache_sram_r_resp      ),
    .s1_axi_r_data_o   ( axi_icache_sram_r_data      ),

    //LSU<>ARBITER
    // Advanced eXtensible Interface Slave2
    .s2_axi_aw_ready_o ( axi_dcache_arbiter_aw_ready ),
    .s2_axi_aw_valid_i ( axi_dcache_arbiter_aw_valid ),
    .s2_axi_aw_addr_i  ( axi_dcache_arbiter_aw_addr  ),

    .s2_axi_w_ready_o  ( axi_dcache_arbiter_w_ready  ),
    .s2_axi_w_valid_i  ( axi_dcache_arbiter_w_valid  ),
    .s2_axi_w_data_i   ( axi_dcache_arbiter_w_data   ),
    .s2_axi_w_strb_i   ( axi_dcache_arbiter_w_strb   ),

    .s2_axi_b_ready_i  ( axi_dcache_arbiter_b_ready  ),
    .s2_axi_b_valid_o  ( axi_dcache_arbiter_b_valid  ),
    .s2_axi_b_resp_o   ( axi_dcache_arbiter_b_resp   ),

    .s2_axi_ar_ready_o ( axi_dcache_arbiter_ar_ready ),
    .s2_axi_ar_valid_i ( axi_dcache_arbiter_ar_valid ),
    .s2_axi_ar_addr_i  ( axi_dcache_arbiter_ar_addr  ),
    
    .s2_axi_r_ready_i  ( axi_dcache_arbiter_r_ready  ),
    .s2_axi_r_valid_o  ( axi_dcache_arbiter_r_valid  ),
    .s2_axi_r_resp_o   ( axi_dcache_arbiter_r_resp   ),
    .s2_axi_r_data_o   ( axi_dcache_arbiter_r_data   ),
    
    // arbiter<>sram
    // Advanced eXtensible Interface  Master
    .axi_aw_ready_i    ( axi_arbitr_sram_aw_ready    ),
    .axi_aw_valid_o    ( axi_arbitr_sram_aw_valid    ),
    .axi_aw_addr_o     ( axi_arbitr_sram_aw_addr     ),
    
    .axi_w_ready_i     ( axi_arbitr_sram_w_ready     ),
    .axi_w_valid_o     ( axi_arbitr_sram_w_valid     ),
    .axi_w_data_o      ( axi_arbitr_sram_w_data      ),
    .axi_w_strb_o      ( axi_arbitr_sram_w_strb      ),
    
    .axi_b_ready_o     ( axi_arbitr_sram_b_ready     ),
    .axi_b_valid_i     ( axi_arbitr_sram_b_valid     ),
    .axi_b_resp_i      ( axi_arbitr_sram_b_resp      ),
    
    .axi_ar_ready_i    ( axi_arbitr_sram_ar_ready    ),
    .axi_ar_valid_o    ( axi_arbitr_sram_ar_valid    ),
    .axi_ar_addr_o     ( axi_arbitr_sram_ar_addr     ),
    
    .axi_r_ready_o     ( axi_arbitr_sram_r_ready     ),
    .axi_r_valid_i     ( axi_arbitr_sram_r_valid     ),
    .axi_r_resp_i      ( axi_arbitr_sram_r_resp      ),
    .axi_r_data_i      ( axi_arbitr_sram_r_data      )
);

// 读写取指令接口sram
// arbiter<>sram的连线
wire        axi_arbitr_sram_aw_ready ;
wire        axi_arbitr_sram_aw_valid ;
wire [31:0] axi_arbitr_sram_aw_addr  ;
wire        axi_arbitr_sram_w_ready  ;
wire        axi_arbitr_sram_w_valid  ;
wire [63:0] axi_arbitr_sram_w_data   ;
wire [7:0]  axi_arbitr_sram_w_strb   ;
wire        axi_arbitr_sram_b_ready  ;
wire        axi_arbitr_sram_b_valid  ;
wire [1:0]  axi_arbitr_sram_b_resp   ; 
wire        axi_arbitr_sram_ar_ready ; 
wire        axi_arbitr_sram_ar_valid ; 
wire [31:0] axi_arbitr_sram_ar_addr  ;
wire        axi_arbitr_sram_r_ready  ;
wire        axi_arbitr_sram_r_valid  ;
wire [1:0]  axi_arbitr_sram_r_resp   ;    
wire [63:0] axi_arbitr_sram_r_data   ;   
ysyx_22050019_AXI_LSU_SRAM lsu_sram(
 .clk            (clk                      ),
 .rst            (rst_n                    ),
 .axi_aw_ready_o (axi_arbitr_sram_aw_ready ),       
 .axi_aw_valid_i (axi_arbitr_sram_aw_valid ),
 .axi_aw_addr_i  (axi_arbitr_sram_aw_addr  ),
 .axi_w_ready_o  (axi_arbitr_sram_w_ready  ),        
 .axi_w_valid_i  (axi_arbitr_sram_w_valid  ),
 .axi_w_data_i   (axi_arbitr_sram_w_data   ),
 .axi_w_strb_i   (axi_arbitr_sram_w_strb   ),
 .axi_b_ready_i  (axi_arbitr_sram_b_ready  ),      
 .axi_b_valid_o  (axi_arbitr_sram_b_valid  ),
 .axi_b_resp_o   (axi_arbitr_sram_b_resp   ),          
 .axi_ar_ready_o (axi_arbitr_sram_ar_ready ),       
 .axi_ar_valid_i (axi_arbitr_sram_ar_valid ),
 .axi_ar_addr_i  (axi_arbitr_sram_ar_addr  ),
 .axi_r_ready_i  (axi_arbitr_sram_r_ready  ),            
 .axi_r_valid_o  (axi_arbitr_sram_r_valid  ),        
 .axi_r_resp_o   (axi_arbitr_sram_r_resp   ),
 .axi_r_data_o   (axi_arbitr_sram_r_data   )
);

//==================MEM/WBU=====================
//wb回写模块端口合一了因为wbu的事情太少了打算直接在寄存时合进来。
wire         reg_we_wbu   ;
wire [4:0]   reg_waddr_wbu;
wire [63:0]  reg_wdata_wbu;
/* verilator lint_off UNUSED */wire [63:0]csr_regs_diff_wbu[3:0];//验证用
wire commite_mem_wb;
ysyx_22050019_MEM_WB MEM_WB(
    .clk              ( clk              ),
    .rst_n            ( rst_n            ),
    .pc_i             ( pc_exu_mem       ),
    .inst_i           ( inst_exu_mem     ),
    .commite_i        ( commite_ex_mem    ),
    .reg_we_exu_lsu_i ( reg_we_exu_lsu   ),
    .reg_we_lsu_i     ( wen_lsu_reg      ),
    .reg_waddr_exu_i  ( reg_waddr_exu_lsu),
    .reg_waddr_lsu_i  ( waddr_lsu_reg    ),
    .reg_wdata_lsu_i  ( wdata_lsu_wb     ),
    .reg_wdata_csr_i  ( wdate_csr_lsu    ),
    .reg_wdata_exu_i  ( wdata_reg_exu_lsu),
    .csr_regs_diff_i  ( csr_regs_diff_lsu),

    .pc_o             ( pc               ),
    .inst_o           ( inst             ),
    .commite_o        ( commite_mem_wb   ), 
    .reg_we_wbu_o     ( reg_we_wbu       ),
    .reg_waddr_wbu_o  ( reg_waddr_wbu    ),
    .reg_wdata_wbu_o  ( reg_wdata_wbu    ),
    .csr_regs_diff_o  ( csr_regs_diff_wbu)
);

//寄存器组端口
ysyx_22050019_regs REGS(
 .clk        (clk                      ),
 .now_pc     (pc                       ),         
 .wdata      (reg_wdata_wbu            ),
 .waddr      (reg_waddr_wbu            ),
 .wen        (reg_we_wbu               ),

 .csr_regs_diff(csr_regs_diff_wbu      ),
 
 .raddr1     (raddr1_id_regs           ),
 .raddr2     (raddr2_id_regs           ),
 .rdata1     (rdata1_id_regs           ),
 .rdata2     (rdata2_id_regs           )
);

endmodule
