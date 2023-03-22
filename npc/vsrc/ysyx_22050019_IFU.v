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
    output reg            m_axi_rready      ,
    input                 m_axi_rvalid      ,

    //output reg [63:0]     inst_addr         , //送出去看指令的地址
    input                 m_axi_arready     ,
    output reg            m_axi_arvalid     ,
    
    // 送出指令和对于pc的接口（打了一拍）
    output  [63:0]        inst_addr_o       , //到指令寄存器中取指令的地址
    output  [31:0]        inst_o
);
//=========================
  wire pc_wen = m_axi_rready && m_axi_rvalid ;// 暂停指示信号，目前用这个代替，后面需要参考优秀设计
  reg [63:0]     inst_addr;         
  // 状态准备
  localparam IDLE = 1'd0;
  localparam WAIT_READY = 1'd1;

  reg  state_reg;
  reg  next_state;

  // 状态转移
  always @(posedge clk) begin
    if (rst_n) begin
      state_reg <= IDLE;
    end else begin
      state_reg <= next_state;
    end
  end
 always@(*) begin
  if(rst_n) next_state = IDLE;
  else case(state_reg)
    IDLE :if(m_axi_arready) next_state = WAIT_READY;
      else next_state = IDLE;

    WAIT_READY : if(m_axi_rvalid)next_state = IDLE;
    else next_state = WAIT_READY;

    default : next_state = IDLE;
  endcase
end

  // 读的状态机
always@(posedge clk)begin
  if(rst_n)begin
        m_axi_arvalid   <= 1'b1;
        m_axi_rready    <= 1'b0;
  end
  else begin
    case(state_reg)
      IDLE:
      if(next_state==WAIT_READY) begin
        m_axi_arvalid   <= 1'b0;
        m_axi_rready    <= 1'b1;
      end
      else begin
        m_axi_arvalid   <= 1'b1;
        m_axi_rready    <= 1'b0;
      end

      WAIT_READY:if(next_state==IDLE)begin
        m_axi_arvalid   <= 1'b1;
        m_axi_rready    <= 1'b0;
      end
      else begin
        m_axi_arvalid   <= 1'b0;
        m_axi_rready    <= 1'b1;
      end
      default:begin
      end
    endcase
  end
end

//=========================
// pc 计数器
always @ (posedge clk) begin
    // 复位
    if (rst_n) begin
        inst_addr <= RESET_VAL;
    // 跳转
    end else if (inst_j && pc_wen) begin
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
//ysyx_22050019_Reg #(32,32'b0) i0 (clk,rst_n,inst_i,inst_o,1'b1);
//ysyx_22050019_Reg #(64,64'b0) i1 (clk,rst_n,inst_addr,inst_addr_o,1'b1);

assign inst_addr_o = inst_addr;
assign inst_o      = inst_i;

endmodule
