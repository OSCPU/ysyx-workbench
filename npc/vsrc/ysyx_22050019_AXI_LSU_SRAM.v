module ysyx_22050019_AXI_LSU_SRAM # (
    parameter AXI_DATA_WIDTH    = 64,
    parameter AXI_ADDR_WIDTH    = 64
    //parameter AXI_ID_WIDTH      = 4,
    //parameter AXI_USER_WIDTH    = 1
)(  // LSU&MEM输入信号
    input                               clk,
    input                               rst,

    // 写地址通道
    output reg                          axi_aw_ready_o,       
    input                               axi_aw_valid_i,
    input [AXI_ADDR_WIDTH-1:0]          axi_aw_addr_i ,

    // 写数据通道
    output reg                          axi_w_ready_o,        
    input                               axi_w_valid_i,
    input [AXI_DATA_WIDTH-1:0]          axi_w_data_i ,
    input [AXI_DATA_WIDTH/8-1:0]        axi_w_strb_i ,
    
    // 写回复通道
    input                               axi_b_ready_i,      
    output reg                          axi_b_valid_o,
    output reg  [1:0]                   axi_b_resp_o,          

    // 读地址通道
    output reg                          axi_ar_ready_o,       
    input                               axi_ar_valid_i,
    input [AXI_ADDR_WIDTH-1:0]          axi_ar_addr_i,
    
    // 读数据通道
    input                               axi_r_ready_i,            
    output reg                          axi_r_valid_o,        
    output reg  [1:0]                   axi_r_resp_o,
    output reg  [AXI_DATA_WIDTH-1:0]    axi_r_data_o
);

localparam RS_IDLE = 2'd1;
localparam RS_RHS  = 2'd2;

localparam WS_IDLE = 2'd1;
localparam WS_WHS  = 2'd2;
localparam WS_BHS  = 2'd3;

reg  [AXI_ADDR_WIDTH-1:0]   ar_addr;          //LSU&MEM输入信号
                                   
reg  [AXI_ADDR_WIDTH-1:0]   aw_addr;          //LSU&MEM输入信号
reg  [AXI_DATA_WIDTH-1:0]   w_data ;          //LSU&MEM输入信号
reg  [AXI_DATA_WIDTH/8-1:0] w_strb ;          //LSU&MEM输入信号

reg[1:0] rstate;
reg[1:0] next_rstate;
reg[1:0] wstate;
reg[1:0] next_wstate;
    //// ------------------State Machine------------------////
    
    // 写通道状态切换
    
always@(posedge clk)begin
  if(rst) wstate <= WS_IDLE;
  else    wstate <= next_wstate;
end

always@(*) begin
  if(rst) next_wstate = WS_IDLE;
  else case(wstate)
    WS_IDLE :if(axi_aw_valid_i) next_wstate = WS_WHS;
      else next_wstate = WS_IDLE;

    WS_WHS : if(axi_w_valid_i)   next_wstate = WS_BHS;
      else next_wstate = WS_WHS;

    WS_BHS : if(axi_b_ready_i)   next_wstate = WS_IDLE;
      else next_wstate = WS_BHS;

    default : next_wstate = RS_IDLE;
  endcase
end

always@(posedge clk)begin
  if(rst)begin
    axi_aw_ready_o <= 1'b1;
    aw_addr        <= 64'b0;
    axi_w_ready_o  <= 1'b0;
    w_data         <= 64'b0;
    w_strb         <= 8'b0;
    axi_b_valid_o  <= 1'b0;
    axi_b_resp_o   <= 2'b0;
  end
  else begin
    case(wstate)
      WS_IDLE:
      if(next_wstate==WS_WHS)begin
        axi_aw_ready_o <= 1'b0;
        aw_addr        <= axi_aw_addr_i;
        axi_w_ready_o  <= 1'b1;
      end
      else begin
        axi_aw_ready_o <= 1'b1;
        aw_addr        <= 64'b0;
        axi_w_ready_o  <= 1'b0;
        w_data         <= 64'b0;
        w_strb         <= 8'b0;
        axi_b_valid_o  <= 1'b0;
        axi_b_resp_o   <= 2'b0;
      end

      WS_WHS:if(next_wstate==WS_BHS)begin
        axi_w_ready_o  <= 1'b0;
        w_data         <= axi_w_data_i;
        w_strb         <= axi_w_strb_i;
        axi_b_valid_o  <= 1'b1;
        axi_b_resp_o   <= 2'b0;
      end
      
      WS_BHS:if(next_wstate==WS_IDLE)begin
        pmem_write(aw_addr, w_data, w_strb);
        axi_aw_ready_o <= 1'b1;
        axi_b_valid_o  <= 1'b0;
        axi_b_resp_o   <= 2'b0;
      end
      default:begin
      end
    endcase
  end
end

    // 读通道状态切换

always@(posedge clk)begin
  if(rst) rstate <= RS_IDLE;
  else rstate <= next_rstate;
end

always@(*) begin
  if(rst) next_rstate = RS_IDLE;
  else case(rstate)
    RS_IDLE :if(axi_ar_valid_i) next_rstate = RS_RHS;
      else next_rstate = RS_IDLE;

    RS_RHS : if(axi_r_ready_i&axi_r_valid_o)next_rstate = RS_IDLE;
    else next_rstate = RS_RHS;

    default : next_rstate = RS_IDLE;
  endcase
end

wire [63:0] din;

always@(posedge clk)begin
  if(rst)begin
    ar_addr       <= 64'b0;
    axi_ar_ready_o<= 1'b1;
    axi_r_valid_o <= 1'b0;
    axi_r_resp_o  <= 2'b0;
    axi_r_data_o  <= 64'b0;
  end
  else begin
    case(rstate)
      RS_IDLE:
      if(next_rstate==RS_RHS) begin
        ar_addr       <= axi_ar_addr_i;
        axi_ar_ready_o<= 1'b0;
      end
      else begin
        ar_addr       <= 64'b0;
        axi_ar_ready_o<= 1'b1;
        axi_r_valid_o <= 1'b0;
        axi_r_resp_o  <= 2'b0;
        axi_r_data_o  <= 64'b0;
      end

      RS_RHS:if(next_rstate==RS_IDLE)begin
        axi_ar_ready_o<= 1'b1;
        axi_r_valid_o <= 1'b0;
        axi_r_resp_o  <= 2'b0;
        axi_r_data_o  <= 64'b0;
      end
      else begin
        axi_r_valid_o <= 1'b1;
        axi_r_resp_o  <= 2'b0;
        pmem_read(ar_addr,din);
        axi_r_data_o  <= din;
      end
      default:begin
      end
    endcase
  end
end

endmodule
