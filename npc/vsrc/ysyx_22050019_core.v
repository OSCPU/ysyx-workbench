module ysyx_22050019_core(
  input       clk,
  input       rst_n,
  
  //output [31:0]inst_i,         //1_inst
  //output[63:0]inst_addr,
  
  output[63:0]inst_addr_if_id, //2_inst(目前查看执行状态的指令)
  output[31:0]inst_if_id      
);

//取出指令的逻辑分离出来
wire [63:0]        inst_i ;
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
wire [1:0] axi_if_sram_resp  ;
wire axi_if_sram_arready;
wire axi_if_sram_arvalid;
/*
axi_lite_sram sram(
   .clk               (clk),
   .rst_n             (rst_n),
   
   .s_axi_arvalid     (axi_if_sram_arvalid),
   .s_axi_araddr      (inst_addr_if_id),
   .s_axi_arready     (axi_if_sram_arready),
   
   .s_axi_rready      (axi_if_sram_rready),
   .s_axi_rvalid      (axi_if_sram_rvalid),
   .s_axi_resp_o      (axi_if_sram_resp),
   .s_axi_rdata       (inst_i)
);
*/

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
    .m_axi_arready     (axi_if_sram_arready),
    .m_axi_arvalid     (axi_if_sram_arvalid),

    .inst_addr_o       (inst_addr_if_id    ), // 传入下级模块的地址
    .inst_o            (inst_if_id         )
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
wire [63:0] ram_wdata_id_lsu;//mem写数据
wire        ram_re_id_lsu   ;
wire [5:0]  mem_r_wdth     ;
wire [3:0]  mem_w_wdth     ;

ysyx_22050019_IDU IDU(
.inst_addr_pc  (inst_addr_if_id      ),
 .inst_i       (inst_if_id           ),
 
 .snpc         (snpc                 ),
 .inst_j       (inst_j               ),
 .ram_we       (ram_we_id_lsu        ),
 .ram_wdata    (ram_wdata_id_lsu     ),
 .ram_re       (ram_re_id_lsu        ),

 .raddr1       (raddr1_id_regs       ),
 .rdata1       (rdata1_id_regs       ),
 .raddr2       (raddr2_id_regs       ),
 .rdata2       (rdata2_id_regs       ),
 .op1          (op1_id_ex            ),
 .op2          (op2_id_ex            ),
 .reg_we_o     (reg_we_id_ex         ),
 .reg_waddr_o  (reg_waddr_id_ex      ),

 .csr_inst_type(csr_inst_type_id_ex),
 .csr_wen      (csr_wen_id_ex      ),
 .csr_addr     (csr_addr_id_ex     ),

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
wire [7:0] csr_inst_type_id_ex;
wire [11:0]csr_addr_id_ex;
wire       csr_wen_id_ex;
//wire [63:0]rdata1_reg_csr;/* verilator lint_off UNUSED */

wire [63:0]wdate_csr_reg;
/* verilator lint_off UNUSED */wire [63:0]csr_regs_diff[3:0];

wire [63:0]snpc_csr_id;
ysyx_22050019_CSR CSR(
    .clk            (clk                ),
    .rst_n          (rst_n              ),
    .pc             (inst_addr_if_id    ),
  
    .csr_inst_type  (csr_inst_type_id_ex),
    .csr_addr       (csr_addr_id_ex     ),
    .csr_wen        (csr_wen_id_ex      ),
    .rdata1_reg_csr (rdata1_id_regs     ),//从reg读到的数据

    .snpc           (snpc_csr_id        ),

    .csr_regs_diff  (csr_regs_diff      ),//csr to reg for diff
    .wdate_csr_reg  (wdate_csr_reg      )//向reg写的数据
    

);

//EXecut模块端口
wire [63:0]  wdata_ex_reg  ;
wire         reg_we_ex_reg ;
wire [4:0]   waddr_ex_reg  ;

ysyx_22050019_EXU EXU(
 .alu_sel(alu_sel),

 .op1         (op1_id_ex      ),
 .op2         (op2_id_ex      ),
 .reg_we_i    (reg_we_id_ex   ),
 .reg_waddr_i (reg_waddr_id_ex),

 .result      (result_exu_lsu ),
 .wdata       (wdata_ex_reg   ),
 .reg_we      (reg_we_ex_reg  ),
 .waddr       (waddr_ex_reg   )
);

// lsu模块端口
wire [63:0] wdata_lsu_wb;
//wire        ram_we_lsu_mem   ;//存储器写使能
wire [63:0] ram_waddr_lsu_mem ;//mem索引
wire        axi_lsu_sram_aw_ready;
wire        axi_lsu_sram_aw_valid;
wire [63:0] ram_wdata_lsu_mem ;
wire [7:0]  wmask             ;
wire        axi_lsu_sram_w_ready;
wire        axi_lsu_sram_w_valid;
wire [1:0]  axi_lsu_sram_b_wresp;
wire        axi_lsu_sram_b_ready;
wire        axi_lsu_sram_b_valid;
//wire        ram_re_lsu_mem   ;//存储器读使能
wire [63:0] ram_rdata_mem_lsu ;
wire [63:0] ram_raddr_lsu_mem ;//mem读索引
wire        axi_lsu_sram_ar_ready;
wire        axi_lsu_sram_ar_valid;
wire [1:0]  axi_lsu_sram_r_resp ;
wire        axi_lsu_sram_r_ready;
wire        axi_lsu_sram_r_valid;

wire [63:0] result_exu_lsu;
wire        wen_lsu_reg;
wire [4:0]  waddr_lsu_reg;
ysyx_22050019_LSU LSU(
 .clk            (clk                  ),
 .rst            (rst_n                ),
 .result         (result_exu_lsu       ),
 .ram_we_i       (ram_we_id_lsu        ),
 .ram_wdata_i    (ram_wdata_id_lsu     ),
 .ram_re_i       (ram_re_id_lsu        ),
 
 .mem_r_wdth     (mem_r_wdth           ),
 .mem_w_wdth     (mem_w_wdth           ),
   
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


 .waddr_reg_i    (waddr_ex_reg         ),
 .wen_reg_o      (wen_lsu_reg          ),
 .waddr_reg_o    (waddr_lsu_reg        ),
 .wdata_reg_o    (wdata_lsu_wb         )
);

/*
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
*/

//ifu没有写同到访问，这里用拉空接地来表示方便仿真
wire s1_axi_aw_ready_o;
wire s1_axi_w_ready_o ;
wire s1_axi_b_valid_o ;
wire [1:0] s1_axi_b_resp_o;
// ifu和lsu的仲裁
// 目前只做了读通道的仲裁，写通道展示没有需要仲裁的冲突点
ysyx_22050133_axi_arbiter ARBITER(
    .clk               ( clk                      ),
    .rst               ( rst_n                    ),

    // IFU<>ARBITER
    // Advanced eXtensible Interface Slave1
    .s1_axi_aw_ready_o ( s1_axi_aw_ready_o        ),
    .s1_axi_aw_valid_i ( 1'b0                     ),
    .s1_axi_aw_addr_i  ( 64'b0                    ),

    .s1_axi_w_ready_o  ( s1_axi_w_ready_o         ),
    .s1_axi_w_valid_i  ( 1'b0                     ),
    .s1_axi_w_data_i   ( 64'b0                    ),
    .s1_axi_w_strb_i   ( 8'b0                     ),

    .s1_axi_b_ready_i  ( 1'b0                     ),
    .s1_axi_b_valid_o  ( s1_axi_b_valid_o         ),
    .s1_axi_b_resp_o   ( s1_axi_b_resp_o          ),

    .s1_axi_ar_ready_o ( axi_if_sram_arready      ),
    .s1_axi_ar_valid_i ( axi_if_sram_arvalid      ),
    .s1_axi_ar_addr_i  ( inst_addr_if_id          ),

    .s1_axi_r_ready_i  ( axi_if_sram_rready       ),
    .s1_axi_r_valid_o  ( axi_if_sram_rvalid       ),
    .s1_axi_r_resp_o   ( axi_if_sram_resp         ),
    .s1_axi_r_data_o   ( inst_i                   ),

    //LSU<>ARBITER
    // Advanced eXtensible Interface Slave2
    .s2_axi_aw_ready_o ( axi_lsu_sram_aw_ready    ),
    .s2_axi_aw_valid_i ( axi_lsu_sram_aw_valid    ),
    .s2_axi_aw_addr_i  ( ram_waddr_lsu_mem        ),

    .s2_axi_w_ready_o  ( axi_lsu_sram_w_ready     ),
    .s2_axi_w_valid_i  ( axi_lsu_sram_w_valid     ),
    .s2_axi_w_data_i   ( ram_wdata_lsu_mem        ),
    .s2_axi_w_strb_i   ( wmask                    ),

    .s2_axi_b_ready_i  ( axi_lsu_sram_b_ready     ),
    .s2_axi_b_valid_o  ( axi_lsu_sram_b_valid     ),
    .s2_axi_b_resp_o   ( axi_lsu_sram_b_wresp     ),

    .s2_axi_ar_ready_o ( axi_lsu_sram_ar_ready    ),
    .s2_axi_ar_valid_i ( axi_lsu_sram_ar_valid    ),
    .s2_axi_ar_addr_i  ( ram_raddr_lsu_mem        ),
    
    .s2_axi_r_ready_i  ( axi_lsu_sram_r_ready     ),
    .s2_axi_r_valid_o  ( axi_lsu_sram_r_valid     ),
    .s2_axi_r_resp_o   ( axi_lsu_sram_r_resp      ),
    .s2_axi_r_data_o   ( ram_rdata_mem_lsu        ),
    
    // arbiter<>sram
    // Advanced eXtensible Interface  Master
    .axi_aw_ready_i    ( axi_arbitr_sram_aw_ready ),
    .axi_aw_valid_o    ( axi_arbitr_sram_aw_valid ),
    .axi_aw_addr_o     ( axi_arbitr_sram_aw_addr  ),
    
    .axi_w_ready_i     ( axi_arbitr_sram_w_ready  ),
    .axi_w_valid_o     ( axi_arbitr_sram_w_valid  ),
    .axi_w_data_o      ( axi_arbitr_sram_w_data   ),
    .axi_w_strb_o      ( axi_arbitr_sram_w_strb   ),
    
    .axi_b_ready_o     ( axi_arbitr_sram_b_ready  ),
    .axi_b_valid_i     ( axi_arbitr_sram_b_valid  ),
    .axi_b_resp_i      ( axi_arbitr_sram_b_resp   ),
    
    .axi_ar_ready_i    ( axi_arbitr_sram_ar_ready ),
    .axi_ar_valid_o    ( axi_arbitr_sram_ar_valid ),
    .axi_ar_addr_o     ( axi_arbitr_sram_ar_addr  ),
    
    .axi_r_ready_o     ( axi_arbitr_sram_r_ready  ),
    .axi_r_valid_i     ( axi_arbitr_sram_r_valid  ),
    .axi_r_resp_i      ( axi_arbitr_sram_r_resp   ),
    .axi_r_data_i      ( axi_arbitr_sram_r_data   )
);

// 读写取指令接口sram
// arbiter<>sram的连线
wire        axi_arbitr_sram_aw_ready ;
wire        axi_arbitr_sram_aw_valid ;
wire [63:0] axi_arbitr_sram_aw_addr  ;
wire        axi_arbitr_sram_w_ready  ;
wire        axi_arbitr_sram_w_valid  ;
wire [63:0] axi_arbitr_sram_w_data   ;
wire [7:0]  axi_arbitr_sram_w_strb   ;
wire        axi_arbitr_sram_b_ready  ;
wire        axi_arbitr_sram_b_valid  ;
wire [1:0]  axi_arbitr_sram_b_resp   ; 
wire        axi_arbitr_sram_ar_ready ; 
wire        axi_arbitr_sram_ar_valid ; 
wire [63:0] axi_arbitr_sram_ar_addr  ;
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

//wb回写模块端口
wire [63:0] wdata_wb_reg ;
ysyx_22050019_WBU WBU(
 // 写入寄存器控制信号
 .reg_wen      (reg_we_ex_reg),
 .reg_lsu_wen  (wen_lsu_reg  ),

 .wdata_exu_wbu(wdata_ex_reg ),
 .wdata_lsu_wbu(wdata_lsu_wb ),
 .wdata_csr_wbu(wdate_csr_reg),

 .wdata_o      (wdata_wb_reg )
);

//寄存器组端口
ysyx_22050019_regs REGS(
 .clk        (clk                       ),
 .now_pc     (inst_addr_if_id           ),         
 .wdata      (wdata_wb_reg              ),
 .waddr      (waddr_ex_reg|waddr_lsu_reg),
 .wen        (reg_we_ex_reg||wen_lsu_reg),

 .csr_regs_diff(csr_regs_diff           ),
 
 .raddr1     (raddr1_id_regs            ),
 .raddr2     (raddr2_id_regs            ),
 .rdata1     (rdata1_id_regs            ),
 .rdata2     (rdata2_id_regs            )
);

endmodule
