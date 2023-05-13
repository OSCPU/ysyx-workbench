module ysyx_22050019_CSR(
    input clk,
    input rst_n,
    input [63:0]pc,
    
    input [7:0]  csr_inst_type,
    input [11:0] csr_addr,
    input        csr_wen,
    input [63:0] rdata1_reg_csr,//从reg读到的数据

    output [63:0]snpc,

    output[63:0] csr_regs_diff [3:0],     //csr to reg for diff
    output[63:0] wdate_csr_reg//向reg写的数据

);
//csr指令信号接受---------------------
//csr信号助释---csrw[0],---mepc[1]---mcause[2]---mstatus[3]

// csr写入x[rd]，x[rs1]写入csr，
wire csrrw_w  = csr_inst_type[0];
// 环境调用
wire ecall_w  = csr_inst_type[1];

// csr写入x[rd]，csr与x[rs1]按位或，结果写入csr
/* verilator lint_off UNUSED */
wire csrrs_w  = csr_inst_type[2];
// 从中断异常处理程序返回
wire mret_w   = csr_inst_type[3];

//************
//csr_wdata->用mux通过通过类型控制读入数据
wire  [63:0] csr_wdata;
ysyx_22050019_mux #( .NR_KEY(3), .KEY_LEN(8), .DATA_LEN(64)) mux_csr_wdata
(
  .key         (csr_inst_type), //键
  .default_out (64'd0),
  .lut         ({
                8'b0000_0100,rdata1_reg_csr|rdata,
                8'b0000_0010,64'd0,
                8'b0000_0001,rdata1_reg_csr
                
                }),           
  .out         (csr_wdata)  //输出
);

// CSR local define 
`define CSR_MSTATUS       12'h300
`define CSR_MISA          12'h301
`define CSR_MEDELEG       12'h302
`define CSR_MIDELEG       12'h303
`define CSR_MIE           12'h304
`define CSR_MTVEC         12'h305
`define CSR_MSCRATCH      12'h340
`define CSR_MEPC          12'h341
`define CSR_MCAUSE        12'h342
`define CSR_MTVAL         12'h343
`define CSR_MIP           12'h344
/*csr寄存器的声明
csr[0] == mtvec csr[1] == mepc csr[2] == mstatus csr[3] == mcause  csr[4]= mstatus
*/
//************    

/* =========================mtvec==================================== */
// 机器模式异常入口基地址寄存器|_|mtvec = {base[maxlen-1:2], mode[1:0]}
reg [63:0] mtvec;
wire [61:0] mtvec_base = mtvec[63:2];
wire [1:0] mtvec_mode = mtvec[1:0];

  always @(posedge clk) begin
    if (rst_n) begin
      mtvec <= 64'b0;
    end
    else if (csrrw_w&&csr_addr == `CSR_MTVEC) begin
      mtvec <= csr_wdata;
    end
  end

/* ==============================mepc============================== */
// 机器模式异常PC寄存器
reg [63:0] mepc;

always @(posedge clk) begin
  if (rst_n) begin
    mepc <= 64'b0;
  end
  else if (ecall_w) begin
    mepc <= pc;
  end
  else if (csr_wen&&csr_addr == `CSR_MEPC)
    mepc <= csr_wdata;
end

/* =============================mcause============================= */
// 机器模式异常原因寄存器
// mcause = {interupt[63], Exception code}
reg [63:0] mcause;
wire mcause_int = mcause[63];
wire [62:0] mcause_cause = mcause[62:0];

always @(posedge clk) begin
  if (rst_n) begin
    mcause <= 64'b0;
  end
  else if (ecall_w) begin
      mcause <= 64'd11;
    end
  else if (csr_wen&&csr_addr == `CSR_MCAUSE)
      mcause <= csr_wdata;
end

/* =============================mstatus============================ */
// 跟踪控制处理器当前运行状态寄存器
/* 【12-11】MPP(2)[在trap前的特权模式],【7】MPIE(1)[trap前的mie位的值],【3】MIE(1)[启动禁用全局终端]*/
reg [63:0] mstatus;
wire mstatus_mpie = mstatus[7];
wire mstatus_mie = mstatus[3];

always @(posedge clk) begin
  if (rst_n) begin
    mstatus <= 64'hA00001800;
  end
  else if (csr_wen&&csr_addr == `CSR_MSTATUS)
    mstatus <= csr_wdata;
end
//*********************** CSR Read Sel********************************

//通过csr地址选择读取哪一个csr寄存器
reg [63:0] rdata;
always @(*) begin
  rdata = 64'b0;
  case(csr_addr)
    `CSR_MTVEC: rdata = mtvec;
    `CSR_MCAUSE:rdata = mcause;
    `CSR_MSTATUS:rdata= mstatus;
    `CSR_MEPC : rdata = mepc;
    default: rdata = 64'b0;
  endcase
end

//csr对外输出的信号的控制和处理

assign wdate_csr_reg = rdata;
assign snpc    = ecall_w?mtvec:
                 mret_w ?mepc :64'b0;

//*********************** csr_regs给diff传递部分csr信息******************

assign csr_regs_diff[0] =mtvec;
assign csr_regs_diff[1] =mepc;
assign csr_regs_diff[2] =mstatus;
assign csr_regs_diff[3] =mcause;

endmodule
