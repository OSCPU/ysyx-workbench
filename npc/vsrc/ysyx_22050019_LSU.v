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
ysyx_22050019_mux #( .NR_KEY(6), .KEY_LEN(6), .DATA_LEN(64)) mem_r_data_mux          //of32,16,8  || 32,16,8
(
  .key         (axi_m_mem_r_wdth),
  .default_out (ram_rdata_i),
  .lut         ({		 6'b100000,{{32{ram_rdata_i[31]}},ram_rdata_i[31:0]},
                 		 6'b010000,{{48{ram_rdata_i[15]}},ram_rdata_i[15:0]},
				             6'b001000,{{56{ram_rdata_i[7 ]}},ram_rdata_i[7 :0]},
				             6'b000100,{32'b0,ram_rdata_i[31:0]},
				             6'b000010,{48'b0,ram_rdata_i[15:0]},
				             6'b000001,{56'b0,ram_rdata_i[7 :0]}
                    }),        
  .out         (mem_r_data)  
);

//mem_w_wdth_mux
wire [7:0] mem_w_mask;
ysyx_22050019_mux #( .NR_KEY(4), .KEY_LEN(4), .DATA_LEN(8)) mem_w_wdth_mux             //basic-64---8---16---32--
(
  .key         (mem_w_wdth),
  .default_out (8'b11111111),
  .lut         ({		 4'b1000,8'b11111111,
                     4'b0100,8'b00000001,
                 		 4'b0010,8'b00000011,
				             4'b0001,8'b00001111
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
        ram_wdata      <= ram_wdata_i;
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

assign ram_waddr      = ram_we_i ? result : 64'b0;
assign m_axi_aw_valid = ram_we_i;

//=============================================================
//==========================读通道==============================
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
    RS_IDLE :if(m_axi_ar_ready&&m_axi_ar_valid) next_rstate = RS_RHS;
      else next_rstate = RS_IDLE;

    RS_RHS : if(m_axi_r_valid)next_rstate = RS_IDLE;
    else next_rstate = RS_RHS;

    default : next_rstate = RS_IDLE;
  endcase
end

always@(posedge clk)begin
  if(rst)begin
    rresp           <= 2'b0;
    waddr_reg       <= 5'b0;
    m_axi_r_ready   <= 1'b0;
    axi_m_mem_r_wdth<= 6'b0;
  end
  else begin
    case(rstate)
      RS_IDLE:
      if(next_rstate==RS_RHS) begin
        waddr_reg        <= waddr_reg_i;
        m_axi_r_ready    <= 1'b1;
        axi_m_mem_r_wdth <= mem_r_wdth;
      end
      else begin
        rresp            <= 2'b0;
        waddr_reg        <= 5'b0;
        m_axi_r_ready    <= 1'b0;
        axi_m_mem_r_wdth <= 6'b0;
      end

      RS_RHS:if(next_rstate==RS_IDLE)begin
        waddr_reg        <= 5'b0;
        m_axi_r_ready    <= 1'b0;
        axi_m_mem_r_wdth <= 6'b0;
        rresp            <= m_axi_r_resp;
      end
      else begin
        waddr_reg     <= waddr_reg;
        m_axi_r_ready <= 1'b1;
      end
      default:begin
      end
    endcase
  end
end

//reg_control
assign wen_reg_o    = m_axi_r_valid;
assign waddr_reg_o  = m_axi_r_valid ? waddr_reg : 5'b0;
assign wdata_reg_o  = m_axi_r_valid ? mem_r_data : 64'b0;


assign ram_raddr      = ram_re_i ? result : 64'b0;
assign m_axi_ar_valid = ram_re_i;

//=============================================================
endmodule

