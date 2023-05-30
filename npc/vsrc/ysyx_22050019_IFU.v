//第一级流水，时序逻辑

module ysyx_22050019_IFU#(
  RESET_VAL = 64'h80000000
)
(
    input                 clk               ,
    input                 rst_n             ,

    //pc 的跳转控制信号
    input                 inst_j            ,
    input   [63:0]        snpc              ,  
    
    output  [31:0]        inst_i            ,
    output  [63:0]        inst_addr_reg_o   , //送出去看指令的地址

    // 送出指令和对于pc的接口（打了一拍）
    output  [63:0]        inst_addr_o       , //到指令寄存器中取指令的地址
    output  [31:0]        inst_o
);
//=========================
// pc 计数器
wire [63:0]               inst_addr;
wire [63:0] inst_addr_reg = inst_addr+64'd4;

reg [63:0]  q;
always @(posedge clk) begin
    if (rst_n )
        q <= RESET_VAL ;
    else
        q <= inst_addr_reg    ;   
end

assign inst_addr = inst_j?snpc:q;
//=========================
/* verilator lint_off UNUSED */reg [63:0] fetchmem_rdata;
always @(*) begin
  if (~rst_n) pmem_read(inst_addr, fetchmem_rdata);
  else fetchmem_rdata = 64'b0;
end
assign inst_i = rst_n ? 32'b0 : fetchmem_rdata[31:0];

//IFU第一级取指令流水操作
ysyx_22050019_Reg #(32,32'b0) i0 (clk,rst_n,inst_i,inst_o,1'b1);
ysyx_22050019_Reg #(64,64'b0) i1 (clk,rst_n,inst_addr,inst_addr_o,1'b1);

assign inst_addr_reg_o = inst_addr;

endmodule
