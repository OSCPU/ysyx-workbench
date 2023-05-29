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
    input            commite_i           ,

    /* control */
    input            mem_wb_stall_i      ,

    output reg       commite_o           ,
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
    else if(~mem_wb_stall_i)begin
        reg_we_wbu_o         <= reg_we_exu_lsu_i|reg_we_lsu_i  ;
        reg_waddr_wbu_o      <= reg_waddr_exu_i|reg_waddr_lsu_i;
        reg_wdata_wbu_o      <= reg_we_exu_lsu_i ? reg_wdata_exu_i|reg_wdata_csr_i : reg_we_lsu_i ? reg_wdata_lsu_i : 64'b0;
    end

  end
import "DPI-C" function void difftest_valid();
//======================================
//仿真信号
reg [63:0] mtvec   = csr_regs_diff_i[0];
reg [63:0] mepc    = csr_regs_diff_i[1];
reg [63:0] mstatus = csr_regs_diff_i[2];
reg [63:0] mcause  = csr_regs_diff_i[3];

  always @(posedge clk) begin
    if (rst_n) begin
        pc_o             <= 0;
        inst_o           <= 0;
        commite_o        <= 0;
        mtvec            <= 0;
        mepc             <= 0;
        mstatus          <= 0;
        mcause           <= 0;
    end
    else if (~mem_wb_stall_i) begin
        pc_o            <= pc_i           ;
        inst_o          <= inst_i         ;
        commite_o       <= commite_i      ;
        mtvec           <= csr_regs_diff_i[0];
        mepc            <= csr_regs_diff_i[1];
        mstatus         <= csr_regs_diff_i[2];
        mcause          <= csr_regs_diff_i[3];
    end
    else begin
        pc_o            <= pc_o     ;
        inst_o          <= inst_o   ;
        commite_o       <= 0        ;
        mtvec           <= mtvec    ;
        mepc            <= mepc     ;
        mstatus         <= mstatus  ;
        mcause          <= mcause   ;
    end

  end
assign csr_regs_diff_o[0] = mtvec  ;
assign csr_regs_diff_o[1] = mepc   ;
assign csr_regs_diff_o[2] = mstatus;
assign csr_regs_diff_o[3] = mcause ;

always@(posedge clk)begin
  if(commite_o) difftest_valid();
end
//=====================================================================
//inst，设置了捕捉没实现的csr指令
always @(*) begin
  if (inst_i == 32'b00000000000100000000000001110011)
    ebreak();
end
endmodule