// 目前写的aw_valid信号是用ram写使能暂时代替，这意味着无法持续，当写请求需要等待时，需要修改这里的逻辑
module ysyx_22050019_LSU# (
    parameter AXI_DATA_WIDTH    = 64,
    parameter AXI_ADDR_WIDTH    = 64
    //parameter AXI_ID_WIDTH      = 4,
    //parameter AXI_USER_WIDTH    = 1
)(
  input               clk,
  input               rst,
  // 读写位宽
  input [5:0]         mem_r_wdth ,
  input [3:0]         mem_w_wdth ,

  // 读写数据
  input [63:0]        ram_wdata_i ,
  input               ram_we_i    ,

  input               ram_re_i    ,
  
  // alu 结果
  input [63:0]        result,
  input  [4:0]        waddr_reg_i ,
  // 向reg的写数据
  output              wen_reg_o   ,
  output     [4:0]    waddr_reg_o ,
  output     [63:0]   wdata_reg_o ,

  // 分为读写两个通道描述信号
  // 写通道
  //output              ram_we      ,

  output     [63:0]   ram_waddr   ,
  input               m_axi_aw_ready,
  output              m_axi_aw_valid,

  output reg [63:0]   ram_wdata   ,
  output reg [7:0]    wmask       ,
  input               m_axi_w_ready,
  output reg          m_axi_w_valid,

  input [1:0]         ram_wresp_i  ,
  output reg          m_axi_b_ready,
  input               m_axi_b_valid,

  // 读通道
  //output              ram_re      ,

  input [63:0]        ram_rdata_i ,
  input [1:0]         m_axi_r_resp ,
  output reg          m_axi_r_ready,
  input               m_axi_r_valid,

  input               m_axi_ar_ready,
  output              m_axi_ar_valid,
  output  [63:0]      ram_raddr   

);
//==========================信号初始化==============================
//mem_r_data_mux
wire [63:0] mem_r_data;
wire [31:0] strb_rdata = ram_raddr[2] ? ram_rdata_i[63:32] >> {ar_addr[1:0],3'b0}: ram_rdata_i[31:0] >> {ar_addr[1:0],3'b0};
ysyx_22050019_mux #( .NR_KEY(6), .KEY_LEN(6), .DATA_LEN(64)) mem_r_data_mux          //of32,16,8  || 32,16,8
(
  .key         (axi_m_mem_r_wdth),
  .default_out (ram_rdata_i),
  .lut         ({		 6'b100000,{{32{strb_rdata[31]}},strb_rdata[31:0]} ,
                 		 6'b010000,{{48{strb_rdata[15]}},strb_rdata[15:0]} ,
				             6'b001000,{{56{strb_rdata[7 ]}},strb_rdata[7 :0]} ,
				             6'b000100,{32'b0,strb_rdata[31:0]}                 ,
				             6'b000010,{48'b0,strb_rdata[15:0]}                 ,
				             6'b000001,{56'b0,strb_rdata[7 :0]}                 
                    }),        
  .out         (mem_r_data)  
);

//mem_w_wdth_mux
wire [7:0] mem_w_mask;
wire [63:0]strb_wdata = result[2] ? {ram_wdata_i[31: 0],ram_wdata_i[63:32]} << {result[1:0],3'b0} : ram_wdata_i[63:0] << {result[1:0],3'b0} ;
ysyx_22050019_mux #( .NR_KEY(4), .KEY_LEN(4), .DATA_LEN(8)) mem_w_wdth_mux             //basic-64---8---16---32--
(
  .key         (mem_w_wdth),
  .default_out (8'b11111111),
  .lut         ({		 4'b1000,8'b11111111,
                     4'b0100,result[2] ? 8'b00010000 << result[1:0] : 8'b00000001 << result[1:0],
                 		 4'b0010,result[2] ? 8'b00110000 << result[1:0] : 8'b00000011 << result[1:0],
				             4'b0001,result[2] ? 8'b11110000 << result[1:0] : 8'b00001111 << result[1:0]
                    }),        
  .out         (mem_w_mask)  
);

//=============================================================
//==========================写通道==============================
localparam WS_IDLE = 2'd1;
localparam WS_WHS  = 2'd2;
localparam WS_BHS  = 2'd3;

reg[1:0] wstate;
reg[1:0] next_wstate;

reg [1:0] wresp;
    //// ------------------State Machine------------------////
    
    // 写通道状态切换
    
always@(posedge clk)begin
  if(rst) wstate <= WS_IDLE;
  else    wstate <= next_wstate;
end

always@(*) begin
  if(rst) next_wstate = WS_IDLE;
  else case(wstate)
    WS_IDLE :if(m_axi_aw_ready&&m_axi_aw_valid) next_wstate = WS_WHS;
      else next_wstate = WS_IDLE;

    WS_WHS : if(m_axi_w_ready)   next_wstate = WS_BHS;
      else next_wstate = WS_WHS;

    WS_BHS : if(m_axi_b_valid)   next_wstate = WS_IDLE;
      else next_wstate = WS_BHS;

    default : next_wstate = RS_IDLE;
  endcase
end

always@(posedge clk)begin
  if(rst)begin
    ram_wdata      <= 64'b0;
    wmask          <= 8'b0;
    m_axi_w_valid  <= 1'b0;
    m_axi_b_ready  <= 1'b0;
    wresp          <= 2'b0;
    
  end
  else begin
    case(wstate)
      WS_IDLE:
      if(next_wstate==WS_WHS)begin
        ram_wdata      <= strb_wdata;
        wmask          <= mem_w_mask;
        m_axi_w_valid  <= 1'b1;
      end

      WS_WHS:if(next_wstate==WS_BHS)begin
        ram_wdata      <= 64'b0;
        wmask          <= 8'b0;
        m_axi_w_valid  <= 1'b0;
        m_axi_b_ready  <= 1'b1;
      end
      
      WS_BHS:if(next_wstate==WS_IDLE)begin
        m_axi_b_ready  <= 1'b0;
      end
      default:begin
      end
    endcase
  end
end

reg [63:0] aw_addr ;
always@(posedge clk) begin
  if(rst) 
    aw_addr <= 64'b0;
  else if(ram_we_i)
    aw_addr <= result;
  else if (m_axi_b_valid&&m_axi_b_ready)
    aw_addr <= 64'b0;
  else aw_addr <= aw_addr;
end

assign ram_waddr      = ram_we_i ? result : 64'b0|aw_addr;
assign m_axi_aw_valid = ram_we_i;

//=============================================================
//==========================读通道==============================
import "DPI-C" function void arbiter_wait();
localparam RS_IDLE = 2'd1;
localparam RS_RHS  = 2'd2;

reg[1:0] rstate;
reg[1:0] next_rstate;

reg [1:0] rresp;
reg [4:0] waddr_reg;
reg [5:0] axi_m_mem_r_wdth;
    //// ------------------State Machine------------------////
    // 读通道状态切换

always@(posedge clk)begin
  if(rst) rstate <= RS_IDLE;
  else rstate <= next_rstate;
end

always@(*) begin
  if(rst) next_rstate = RS_IDLE;
  else case(rstate)
    RS_IDLE :if(m_axi_ar_ready&&m_axi_ar_valid) begin
             next_rstate = RS_RHS;
    end
      else next_rstate = RS_IDLE;

    RS_RHS : if(m_axi_r_valid)next_rstate = RS_IDLE;
    else next_rstate = RS_RHS;

    default : next_rstate = RS_IDLE;
  endcase
end

// 握手信号状态机
always@(posedge clk)begin
  if(rst)begin
    rresp           <= 2'b0;
    m_axi_r_ready   <= 1'b0;
  end
  else begin
    case(rstate)
      RS_IDLE:
      if(next_rstate==RS_RHS) begin
        m_axi_r_ready    <= 1'b1;
        arbiter_wait()                ;//多跑3个周期平衡
      end
      else begin
        rresp            <= 2'b0;
        m_axi_r_ready    <= 1'b0;

      end

      RS_RHS:if(next_rstate==RS_IDLE)begin
        m_axi_r_ready    <= 1'b0;
        rresp            <= m_axi_r_resp;
      end
      else begin

        m_axi_r_ready <= 1'b1;
      end
      default:begin
      end
    endcase
  end
end

// 寄存器写使能控制
always@(posedge clk) begin
  if(rst) 
    waddr_reg     <= 5'b0;
  else if(ram_re_i)
        waddr_reg        <= waddr_reg_i;
  else if (m_axi_r_valid)
        waddr_reg        <= 5'b0;
  else 
    waddr_reg     <= waddr_reg;
end

always@(posedge clk) begin
  if(rst) 
    axi_m_mem_r_wdth <= 6'b0;
  else if(ram_re_i)
        axi_m_mem_r_wdth <= mem_r_wdth;
  else if (m_axi_r_valid)
        axi_m_mem_r_wdth <= 6'b0;
  else 
    axi_m_mem_r_wdth <= axi_m_mem_r_wdth;
end

//reg_control
assign wen_reg_o    = m_axi_r_valid;
assign waddr_reg_o  = m_axi_r_valid ? waddr_reg : 5'b0;
assign wdata_reg_o  = m_axi_r_valid ? mem_r_data : 64'b0;

//ram的读地址发送端信号控制
reg ar_valid;
reg [63:0] ar_addr ;
always@(posedge clk) begin
  if(rst) 
    ar_valid <= 1'b0;
  else if(ram_re_i)
    ar_valid <= 1'1;
  else if (m_axi_ar_ready&&m_axi_ar_valid)
    ar_valid <= 1'b0;
  else ar_valid <= ar_valid;
end

always@(posedge clk) begin
  if(rst) 
    ar_addr <= 64'b0;
  else if(ram_re_i)
    ar_addr <= result;
  else if (m_axi_r_ready&&m_axi_r_valid)
    ar_addr <= 64'b0;
  else ar_addr <= ar_addr;
end

assign ram_raddr      = ram_re_i ? result : 64'b0 | ar_addr;
assign m_axi_ar_valid = ram_re_i | ar_valid;

//=============================================================
endmodule

