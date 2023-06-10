/*
 * icache - config_Fire
 * 只能读取
 *
 *  |     Tag     |     Index     |          Offset          |
 *  |             |               |                          |
 * 31            10|9            4|3                         0
 * 
 * 每行共2字即16字节即128位，2路组相联
 * 共128行，总大小为8KiB

 * 物理地址总长为32位
 * 每一行字长合计16字节 - Byte  4位
 * 共128行,2路组相连   - Index 6位
 * Tag = 32 - 3 - 6  = 22位
 */
module ysyx_22050019_dcache#(
  parameter DATA_WIDTH      = 64,
  parameter R_ADDR_WIDTH      = 64,
  parameter ADDR_WIDTH        = 32,
  parameter TAG_WIDTH         = 22,
  parameter INDEX_WIDTH       = 6 ,
  parameter INDEX_DEPTH       = 64,//$pow(2,INDEX_WIDTH),
  parameter OFFSET_WIDTH      = 4 ,
  parameter WAY_DEPTH         = 2 ,
  parameter WAY_WIDTH         = 1  //$clog2(WAY_DEPTH)
)(
  input  clk                                             ,
  input  rst                                             ,

  input                              ar_valid_i          ,         
  output reg                         ar_ready_o          ,     
  input     [ADDR_WIDTH-1:0]         ar_addr_i           ,             
  output                             r_data_valid_o      ,     
  input                              r_data_ready_i      ,
  input     [1:0]                    r_resp_i            ,     
  output    [DATA_WIDTH-1:0]         r_data_o            ,
  input                              aw_valid_i          ,         
  output reg                         aw_ready_o          ,     
  input     [ADDR_WIDTH-1:0]         aw_addr_i           ,             
  input                              w_data_valid_i      ,     
  output reg                         w_data_ready_o      ,
  input     [DATA_WIDTH/8-1:0]       w_w_strb_i          ,     
  input     [DATA_WIDTH-1:0]         w_data_i            ,   
  input                              b_ready_i           ,      
  output reg                         b_valid_o           ,
  output reg  [1:0]                  b_resp_o            , 

  output reg                         cache_aw_valid_o    ,       
  input                              cache_aw_ready_i    ,     
  output reg[ADDR_WIDTH-1:0]         cache_aw_addr_o     ,
  output reg                         cache_rw_len_o      ,           
  input                              cache_w_ready_i     ,     
  output reg                         cache_w_valid_o     ,     
  output reg[DATA_WIDTH-1:0]         cache_w_data_o      ,
  output reg[DATA_WIDTH/8-1:0]       cache_w_strb_o      ,
  output reg                         cache_b_ready_o     ,          
  input                              cache_b_valid_i     ,
  input  [1:0]                       cache_b_resp_i      , 
  output reg                         cache_ar_valid_o    ,       
  input                              cache_ar_ready_i    ,     
  output reg[ADDR_WIDTH-1:0]         cache_ar_addr_o     ,          
  output reg                         cache_r_ready_o     ,     
  input                              cache_r_valid_i     ,
  input     [1:0]                    cache_r_resp_i      ,      
  input     [DATA_WIDTH-1:0]         cache_r_data_i
);
parameter TAGL     = ADDR_WIDTH-1                        ;//31
parameter TAGR     = ADDR_WIDTH-TAG_WIDTH                ;//10
parameter INDEXL   = TAGR-1                              ;//9              
parameter INDEXR   = TAGR-INDEX_WIDTH                    ;//4

parameter RAM_WIDTH= INDEXR-1                            ;//3
parameter RAM_DEPTH= INDEX_DEPTH                         ;//64$pow(2,INDEX_WIDTH) 
parameter RAML     = INDEX_WIDTH+OFFSET_WIDTH-1          ;//9
parameter RAMR     = OFFSET_WIDTH                        ;//4

wire [ADDR_WIDTH-1:0]  rw_addr_i = ar_addr_i|aw_addr_i   ;

// 保存地址，miss后的写数据，偏移寄存器
reg [ADDR_WIDTH-1:0]   addr  ;
wire[INDEX_WIDTH-1:0]  index = addr[INDEXL:INDEXR];
reg rw_control;
// tag和标记位的寄存器值
reg [TAG_WIDTH-1:0] tag  [WAY_DEPTH-1:0][INDEX_DEPTH-1:0];
reg                 valid[WAY_DEPTH-1:0][INDEX_DEPTH-1:0];
reg                 dirty[WAY_DEPTH-1:0][INDEX_DEPTH-1:0];

// wire类型传入的地址解析
wire[TAG_WIDTH-1:0]    tag_in  = rw_addr_i[TAGL:TAGR]    ;
wire[INDEX_WIDTH-1:0]  index_in= rw_addr_i[INDEXL:INDEXR];
wire[OFFSET_WIDTH-1:0] OFFSET0 = 0                       ;//3'b0对于这里是持有怀疑态度的

// 命中路的判断逻辑      0-1 两路
wire[WAY_DEPTH-1:0]hit_wayflag;
wire[WAY_WIDTH-1:0]hit_waynum_i=hit_wayflag==2'b01 ? 0
                          :hit_wayflag==2'b10 ? 1
                          :0;
reg[WAY_WIDTH-1:0]waynum;
reg[WAY_WIDTH-1:0]random;
always@(posedge clk)begin//随机替换的替换策略
  if(rst)random<=0;
  else random<=random+1;
end

// ram的一些配置信息
wire [127:0]           RAM_Q [WAY_DEPTH-1:0]                                                            ;//读出的cache数据
wire                   RAM_CEN = 0                                                                      ;//为0有效，为1是无效（2个使能信号需要同时满足不然会读出随机数）使能信号控制
wire                   RAM_WEN[WAY_DEPTH-1:0]                                                           ;//为0是写使能1是读使能，读写控制hit是读数据
wire [DATA_WIDTH-1:0]  maskn   = (state == S_HIT) ? {{8{w_w_strb_i[7]}},{8{w_w_strb_i[6]}},{8{w_w_strb_i[5]}},{8{w_w_strb_i[4]}},{8{w_w_strb_i[3]}},{8{w_w_strb_i[2]}},{8{w_w_strb_i[1]}},{8{w_w_strb_i[0]}}}
                                                               : 64'hffffffffffffffff                   ;//写掩码，目前是全位写，掩码在发送端处理了                                                               
wire                   shift   = (state == S_HIT) ? addr[3] : ~cache_rw_len_o                         ;//写使能的地址偏移shift为1代表高64位
wire [127:0]           RAM_BWEN= ~(shift ? {maskn,64'd0}  : {64'd0,maskn})                              ;//ram写掩码目前一样不用过多处理
wire [INDEX_WIDTH-1:0] RAM_A   = (next_state == S_HIT)|(next_state == S_AW) ? index_in : addr[RAML:RAMR];//ram地址索引
wire [DATA_WIDTH-1:0]  wdata   = cache_r_valid_i&&cache_r_ready_o ? cache_r_data_i : w_data_i           ;
wire [127:0]           RAM_D   = shift ? {wdata,64'd0} : {64'd0,wdata}                                  ;//更新ram数据

wire write_enable = (state == S_R)&(cache_r_valid_i&cache_r_ready_o)|(state == S_HIT)&w_data_valid_i ? 0 : 1 ;
assign  RAM_WEN[0] = waynum ? 1 :write_enable;
assign  RAM_WEN[1] = waynum ? write_enable :1;

//实例化两块ram以及他们的命中逻辑的添加
generate
  genvar i;
  for(i=0;i<WAY_DEPTH;i=i+1)begin
  assign hit_wayflag[i]=((tag[i][index_in]==tag_in)&&valid[i][index_in]);
      S011HD1P_X32Y2D128_BW S011HD1P_X32Y2D128_BW_U0
      (
        .Q(RAM_Q[i]),
        .CLK(clk),
        .CEN(RAM_CEN),
        .WEN(RAM_WEN[i]),
        .BWEN(RAM_BWEN),
        .A(RAM_A),
        .D(RAM_D)
      );
    end
endgenerate

parameter S_IDLE =0;
parameter S_HIT  =1;
parameter S_AR   =2;
parameter S_R    =3;
parameter S_AW   =4;
parameter S_W    =5;
parameter S_B    =6;

reg[15:0] state;
reg[15:0] next_state;

always@(posedge clk) begin
  if(rst)state<=S_IDLE;
  else state<=next_state;
end

// 一些ifu接口的输出信号中间态定义
reg                   r_data_valid;
reg [DATA_WIDTH-1:0]  r_data;

always@(*) begin
  if(rst)next_state=S_IDLE;
  else case(state)
    S_IDLE:if(ar_valid_i&ar_ready_o|aw_valid_i&aw_ready_o)begin
            if(|hit_wayflag)next_state=S_HIT;
            else if(dirty[random][index_in])next_state=S_AW;
            else next_state=S_AR;
          end
        else next_state=S_IDLE;

    S_HIT:if((r_data_ready_i&r_data_valid_o)|(b_ready_i&b_valid_o))next_state=S_IDLE;
      else next_state=S_HIT;

    S_AW:if(cache_aw_valid_o&cache_aw_ready_i)next_state=S_W;
      else next_state=S_AW;

    S_W:if(cache_w_ready_i&cache_w_valid_o&(cache_rw_len_o == 0))next_state=S_B;
      else next_state=S_W;

    S_B:if(cache_b_valid_i&cache_b_ready_o)next_state=S_AR;
      else next_state=S_B;

    S_AR:if(cache_ar_valid&cache_ar_ready_i)next_state=S_R;
      else next_state=S_AR;

    S_R:if(cache_r_ready_o&cache_r_valid_i&(cache_rw_len_o == 0))begin
      if(~rw_control&r_data_ready_i) next_state = S_IDLE;
      else next_state=S_HIT;
    end
      else next_state=S_R;

    default:next_state=S_IDLE;
  endcase
end
//import "DPI-C" function void icache_wait();
always@(posedge clk)begin
  if(rst)begin
    rw_control                    <= 0                                     ;
		ar_ready_o                    <= 0                                     ;
    aw_ready_o                    <= 0                                     ;
		r_data_valid                  <= 0                                     ;
		r_data                        <= 0                                     ;
    w_data_ready_o                <= 0                                     ;
    b_valid_o                     <= 0                                     ;
    b_resp_o                      <= 0                                     ;
    cache_ar_valid                <= 0                                     ;
    cache_ar_addr_o               <= 0                                     ;
		cache_r_ready_o               <= 0                                     ;
    waynum                        <= 0                                     ;
    addr                          <= 0                                     ;
    cache_rw_len_o                <= 0                                     ;
  end
  else begin
    case(state)
      S_IDLE:if(next_state==S_HIT)begin
					ar_ready_o              <= 0                                     ;
          aw_ready_o              <= 0                                     ;
          r_data_valid            <= 0                                     ; 
          waynum                  <= hit_waynum_i                          ;
          addr                    <= rw_addr_i[TAGL:0]                     ;
          if(aw_valid_i&aw_ready_o) begin
          rw_control              <= 1                                     ;
          w_data_ready_o          <= 1                                     ;
          end
        end
        else if(next_state==S_AR)begin
//          icache_wait()                                                    ;//多跑2个周期平衡
					ar_ready_o              <= 0                                     ;
          aw_ready_o              <= 0                                     ;
          waynum                  <= random                                ;
          addr                    <= rw_addr_i[TAGL:0]                     ;
          valid[random][index_in] <= 0                                     ;
          tag[random][index_in]   <= rw_addr_i[TAGL:TAGR]                  ;
          cache_ar_valid          <= 1                                     ;
          cache_ar_addr_o         <= {rw_addr_i[TAGL:INDEXR],OFFSET0}      ;
          cache_rw_len_o          <= 1                                     ;
          if(aw_valid_i&aw_ready_o) begin
          rw_control              <= 1                                     ;
          w_data_ready_o          <= 0                                     ;
          end
        end
        else if(next_state==S_AW)begin
//          icache_wait()                                                  ;//多跑2个周期平衡
					ar_ready_o              <= 0                                     ;
          aw_ready_o              <= 0                                     ;
          waynum                  <= random                                ;
          addr                    <= rw_addr_i[TAGL:0]                     ;
          valid[random][index_in] <= 0                                     ;
          if(aw_valid_i&aw_ready_o) begin
          rw_control              <= 1                                     ;
          end

          cache_aw_valid_o        <= 1;
          cache_aw_addr_o         <= {tag[random][index_in],index_in,OFFSET0};
          cache_rw_len_o          <= 1                                     ;
        end
        else begin
					ar_ready_o              <= 1                                     ;
          aw_ready_o              <= 1                                     ;
					r_data_valid            <= 0                                     ;
					cache_r_ready_o         <= 0                                     ;
        end

      S_HIT:if(next_state==S_IDLE)begin
          rw_control              <= 0                                     ;
					ar_ready_o              <= 1                                     ;
          aw_ready_o              <= 1                                     ;
					r_data_valid            <= 0                                     ;
          waynum                  <= 0                                     ;
          r_data                  <= 0                                     ;
          b_valid_o               <= 0                                     ;
      end
      else if(rw_control) begin
         if(w_data_valid_i) begin
         dirty[waynum][index]     <= 1                                     ;
         w_data_ready_o           <= 0                                     ;
         b_valid_o                <= 1                                     ;
         b_resp_o                 <= 0                                     ;
         end
      end
      else if(~rw_control) begin
          r_data_valid            <= 1                                     ; 
          r_data                  <= addr[3] ? RAM_Q[waynum][127:64] : RAM_Q[waynum][63:0];
      end

      S_AW:if(next_state==S_W)begin
          cache_aw_valid_o        <= 0                                     ;
          cache_w_valid_o         <= 1                                     ;
          cache_w_strb_o          <= 8'hff                                 ;
          cache_w_data_o          <= RAM_Q[waynum][63:0]                   ;
        end

      S_W:if(cache_w_ready_i&cache_w_valid_o&(cache_rw_len_o != 0))begin
              cache_rw_len_o <= cache_rw_len_o -1;
              cache_w_data_o <= RAM_Q[waynum][127:64]                      ;
          end
          else if(next_state==S_B)begin
          cache_w_valid_o         <= 0                                     ;
          cache_b_ready_o         <= 1                                     ;
          dirty[waynum][index]    <= 0                                     ;
          valid[waynum][index]    <= 0                                     ;
          tag[waynum][index]      <= addr[TAGL:TAGR]                       ;
            end

      S_B:if(next_state==S_AR)begin
          cache_b_ready_o         <= 0                                     ;
          cache_ar_valid          <= 1                                     ;
          cache_ar_addr_o         <= {addr[TAGL:INDEXR],OFFSET0}           ;
          cache_rw_len_o          <= 1                                     ;
        end

      S_AR:if(next_state==S_R)begin
          cache_ar_valid          <= 0                                     ;
          cache_r_ready_o         <= 1                                     ;
          end

      S_R:if(cache_r_valid_i&cache_r_ready_o&(cache_rw_len_o != 0))begin
              cache_rw_len_o <= cache_rw_len_o -1;
              r_data         <= cache_r_data_i;
          end
          else if(next_state==S_IDLE)begin
					    ar_ready_o          <= 1                                  ;
              aw_ready_o          <= 1                                  ;
					    r_data_valid        <= 0                                  ;
              waynum              <= 0                                  ;
              r_data              <= 0                                  ;
              cache_r_ready_o     <= 0                                  ;
              valid[waynum][index]<= 1                                  ; 
            end
          else if(next_state==S_HIT)begin
              cache_r_ready_o     <= 0                                  ;
              valid[waynum][index]<= 1                                  ; 
              if(rw_control) begin
              w_data_ready_o      <= 1                                  ;
              end
              else begin
              r_data              <= addr[3] ? cache_r_data_i : r_data  ; 
              r_data_valid        <= 1                                  ;
              end
            end

      default:begin
      end
    endcase
  end
end
//axi的一些需要适配仲裁器的信号
reg cache_ar_valid;
assign cache_ar_valid_o = cache_ar_valid|next_state==S_AR;

//与外部ifu访问的改善信号
assign r_data_valid_o  = cache_r_ready_o&cache_r_valid_i&(cache_rw_len_o == 0)& ~rw_control|(state == S_HIT)&(~rw_control) ? 1 : r_data_valid;
assign r_data_o        = cache_r_ready_o&cache_r_valid_i&(cache_rw_len_o == 0)& ~rw_control|(state == S_HIT)&(~rw_control) ? ((state == S_HIT) ? (addr[3] ? RAM_Q[waynum][127:64] : RAM_Q[waynum][63:0]) : (addr[3] ? cache_r_data_i : r_data)) : r_data;
//仿真程序接入
/*
always@(posedge clk) begin
  if(RAM_A == 6'h1b &&~RAM_WEN[0]) begin
  $display("rwaddr   = %h\n\
     w_data_i       = %h\n\
     cache_r_data_i       = %h\n\
    ",rw_addr_i|addr,w_data_i,cache_r_data_i );
  end
end
*/
endmodule