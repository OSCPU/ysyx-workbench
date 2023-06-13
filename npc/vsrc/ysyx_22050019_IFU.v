//第一级流水，时序逻辑

module ysyx_22050019_IFU#(
  parameter RESET_VAL = 64'h80000000
)
(
    input                 clk               ,
    input                 rst_n             ,

    //pc 的跳转控制信号
    input                 inst_j            ,
    input   [63:0]        snpc              ,  
    
    input  [31:0]         inst_i            ,
    input                 inst_valid_i      ,
  
    output                inst_commite      ,

    //五级流水的适配控制信号的输入和输出
    input                 pc_stall_i        ,
    
    // 送出指令和对于pc的接口（打了一拍）
    output  [63:0]        inst_addr_o       , //到指令寄存器中取指令的地址
    output  [31:0]        inst_o
);

//=========================
// pc计数器逻辑
  wire pc_wen = inst_valid_i && (~pc_stall_i); //暂停指示信号，目前用这个代替，后面需要参考优秀设计
  reg [63:0]     inst_addr; 
// pc 计数器
always @ (posedge clk) begin
    // 复位
    if (rst_n) begin
        inst_addr <= RESET_VAL;
    // 跳转
    end else if (inst_j&(~pc_stall_i)) begin
        inst_addr <= snpc;
    // 暂停
    end else if (~pc_wen) begin
        inst_addr <= inst_addr;
    // 地址加4
    end else begin
        inst_addr <= inst_addr + 64'h4;
    end
end
//=========================
//IFU第一级取指令流水操作
assign inst_addr_o = inst_j&(~pc_stall_i) ? snpc : inst_addr;
assign inst_o      = inst_commite ? inst_i[31:0] :0;
assign inst_commite= pc_wen & ~inst_j;
endmodule
