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
    
    input  [31:0]         inst_i            ,
    //input                 m_axi_arvalid     ,
    //output                m_axi_arready     ,

    output  [63:0]        inst_addr_reg_o   , //送出去看指令的地址
    //input                 m_axi_arready     ,
    //output                m_axi_arvalid     ,
    
    // 送出指令和对于pc的接口（打了一拍）
    output  [63:0]        inst_addr_o       , //到指令寄存器中取指令的地址
    output  [31:0]        inst_o
);
//=========================

//=========================
// pc 计数器
reg [63:0]               inst_addr;
always @(posedge clk) begin
    if (rst_n )
        inst_addr <= RESET_VAL ;
    else if (inst_j)
        inst_addr <= snpc ;   
end

assign inst_addr_o = inst_addr;
assign inst_o      = inst_i;

assign inst_addr_reg_o = inst_addr;

endmodule