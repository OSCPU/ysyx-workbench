module ysyx_22050019_MEM_WB (
    input            clk                 ,
    input            rst_n               ,
    input     [63:0] pc_i                ,
    input     [31:0] inst_i              ,
    input            reg_we_exu_lsu_i    ,
    input            reg_we_lsu_i        ,
    input     [4:0]  reg_waddr_exu_i     ,
    input     [4:0]  reg_waddr_lsu_i     ,
    input     [63:0] reg_wdata_lsu_i     ,
    input     [63:0] reg_wdata_csr_i     ,
    input     [63:0] reg_wdata_exu_i     ,
    input     [63:0] csr_regs_diff_i[3:0],

    output reg[63:0]pc_o                 ,
    output reg[31:0]inst_o               ,
    output reg      reg_we_wbu_o         ,
    output reg[4:0] reg_waddr_wbu_o      ,
    output reg[63:0]reg_wdata_wbu_o      ,
    output    [63:0]csr_regs_diff_o[3:0] 
);

  always @(posedge clk) begin
    if(rst_n) begin
        reg_we_wbu_o         <= 0;
        reg_waddr_wbu_o      <= 0;
        reg_wdata_wbu_o      <= 0;
    end
    else begin
        reg_we_wbu_o         <= reg_we_exu_lsu_i|reg_we_lsu_i  ;
        reg_waddr_wbu_o      <= reg_waddr_exu_i|reg_waddr_lsu_i;
        reg_wdata_wbu_o      <= reg_we_exu_lsu_i ? reg_wdata_exu_i|reg_wdata_csr_i : reg_we_lsu_i ? reg_wdata_lsu_i : 64'b0;
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
        mtvec            <= 0;
        mepc             <= 0;
        mstatus          <= 0;
        mcause           <= 0;
    end
    else begin
        pc_o            <= pc_i           ;
        inst_o          <= inst_i         ;
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