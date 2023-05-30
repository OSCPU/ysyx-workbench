module ysyx_22050019_EX_MEM (
    input              clk                 ,
    input              rst_n               ,
    input     [63:0]   pc_i                ,
    input     [31:0]   inst_i              ,
    input     [63:0]   result_i            ,
    input     [63:0]   wdata_exu_reg_i     ,
    input              ram_we_i            ,
    input     [63:0]   ram_wdata_i         ,
    input     [3:0]    mem_w_wdth_i        ,
    input              ram_re_i            ,
    input     [5:0]    mem_r_wdth_i        ,
    input              reg_we_i            ,
    input     [4:0]    reg_waddr_i         ,
    input     [63:0]   wdate_csr_reg_i     ,
    input     [63:0]   csr_regs_diff_i[3:0],
    input              commite_i           ,

    output reg         commite_o           ,
    output reg[63:0]   pc_o                ,
    output reg[31:0]   inst_o              ,
    output reg[63:0]   result_o            ,
    output reg[63:0]   wdata_exu_reg_o     ,
    output reg         ram_we_o            ,
    output reg[63:0]   ram_wdata_o         ,
    output reg[3:0]    mem_w_wdth_o        ,
    output reg         ram_re_o            ,
    output reg[5:0]    mem_r_wdth_o        ,
    output reg         reg_we_o            ,
    output reg[4:0]    reg_waddr_o         ,
    output reg[63:0]   wdate_csr_reg_o     ,
    output    [63:0]   csr_regs_diff_o[3:0]
);
  always @(posedge clk) begin
    if(rst_n) begin
        result_o        <= 0;   
        wdata_exu_reg_o <= 0;   
        ram_we_o        <= 0;   
        ram_wdata_o     <= 0;   
        mem_w_wdth_o    <= 0;   
        ram_re_o        <= 0;   
        mem_r_wdth_o    <= 0;   
        reg_we_o        <= 0;   
        reg_waddr_o     <= 0;   
        wdate_csr_reg_o <= 0;    
    end
    else begin
        result_o        <= result_i       ;   
        wdata_exu_reg_o <= wdata_exu_reg_i;   
        ram_we_o        <= ram_we_i       ;   
        ram_wdata_o     <= ram_wdata_i    ;   
        mem_w_wdth_o    <= mem_w_wdth_i   ;   
        ram_re_o        <= ram_re_i       ;   
        mem_r_wdth_o    <= mem_r_wdth_i   ;   
        reg_we_o        <= reg_we_i       ;   
        reg_waddr_o     <= reg_waddr_i    ;   
        wdate_csr_reg_o <= wdate_csr_reg_i;    
    end
  end

//======================================
//仿真信号
reg [63:0] mtvec   = csr_regs_diff_i[0];
reg [63:0] mepc    = csr_regs_diff_i[1];
reg [63:0] mstatus = csr_regs_diff_i[2];
reg [63:0] mcause  = csr_regs_diff_i[3];

  always @(posedge clk) begin
    if(rst_n) begin
        pc_o             <= 0;
        inst_o           <= 0;
        commite_o        <= 0;
        mtvec            <= 0;
        mepc             <= 0;
        mstatus          <= 0;
        mcause           <= 0;
    end
    else begin
        pc_o            <= pc_i           ;
        inst_o          <= inst_i         ;
        commite_o       <= commite_i      ;
        mtvec           <= csr_regs_diff_i[0];
        mepc            <= csr_regs_diff_i[1];
        mstatus         <= csr_regs_diff_i[2];
        mcause          <= csr_regs_diff_i[3];
    end
  end
assign csr_regs_diff_o[0] = mtvec  ;
assign csr_regs_diff_o[1] = mepc   ;
assign csr_regs_diff_o[2] = mstatus;
assign csr_regs_diff_o[3] = mcause ;
endmodule

