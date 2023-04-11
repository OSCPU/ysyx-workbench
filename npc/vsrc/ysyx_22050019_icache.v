/*
 * icache - config_Fire
 * 只能读取
 *
 *  |     Tag     |     Index     |          Offset          |
 *  |             |               |                          |
 * 31            9|8             3|2                         0
 * 
 * 每行共2字即16字节即128位，2路组相联
 * 共128行，总大小为8KiB

 * 物理地址总长为32位
 * 字长为8字节 - Byte 3位
 * 共128行，2路组相联 - Index 6位
 * Tag = 32 - 3 - 6 = 23位
 */
module ysyx_22050019_icache#(
  parameter R_DATA_WIDTH      = 64,
  parameter R_ADDR_WIDTH      = 64,
  parameter ADDR_WIDTH        = 32,
  parameter TAG_WIDTH         = 23,
  parameter INDEX_WIDTH       = 6 ,
  parameter INDEX_DEPTH       = 64,//$pow(2,INDEX_WIDTH),
  parameter OFFSET_WIDTH      = 3 ,
  parameter WAY_DEPTH         = 2 ,
  parameter WAY_WIDTH         = 1  //$clog2(WAY_DEPTH)
)(
  input  clk                                             ,
  input  rst                                             ,

  input                              ar_valid_i          ,         
  output reg                         ar_ready_o          ,     
  input     [R_ADDR_WIDTH-1:0]       ar_addr_i           ,             
  output reg                         r_data_valid_o      ,     
  input                              r_data_ready_i      ,
  input     [1:0]                    r_resp_i            ,     
  output reg[R_DATA_WIDTH-1:0]       r_data_o            ,  

  output reg                         cache_ar_valid_o    ,       
  input                              cache_ar_ready_i    ,     
  output reg[R_ADDR_WIDTH-1:0]       cache_ar_addr_o     ,          
  output reg                         cache_r_ready_o     ,     
  input                              cache_r_valid_i     ,
  input     [1:0]                    cache_r_resp_i      ,      
  input     [R_DATA_WIDTH-1:0]       cache_r_data_i
);
parameter TAGL     = ADDR_WIDTH-1                        ;//31
parameter TAGR     = ADDR_WIDTH-TAG_WIDTH                ;//9
parameter INDEXL   = TAGR-1                              ;//8              
parameter INDEXR   = TAGR-INDEX_WIDTH                    ;//3

parameter RAM_WIDTH= INDEXR-1                            ;//2
parameter RAM_DEPTH= INDEX_DEPTH                         ;//64$pow(2,INDEX_WIDTH) 
parameter RAML     = INDEX_WIDTH+OFFSET_WIDTH-1          ;//8
parameter RAMR     = OFFSET_WIDTH                        ;//3




// 保存地址，miss后的写数据，偏移寄存器
reg [ADDR_WIDTH-1:0]   addr  ;
wire[INDEX_WIDTH-1:0]  index = addr[INDEXL:INDEXR];

// tag和标记位的寄存器值
reg [TAG_WIDTH-1:0] tag  [WAY_DEPTH-1:0][INDEX_DEPTH-1:0];
reg                 valid[WAY_DEPTH-1:0][INDEX_DEPTH-1:0];

// wire类型传入的地址解析
wire[TAG_WIDTH-1:0]    tag_in  = ar_addr_i[TAGL:TAGR]    ;
wire[INDEX_WIDTH-1:0]  index_in= ar_addr_i[INDEXL:INDEXR];
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
wire [INDEX_DEPTH-1:0] RAM_Q  [WAY_DEPTH-1:0]                                    ;//读出的cache数据
reg                    RAM_CEN[WAY_DEPTH-1:0]                                    ;//为0有效，为1是无效（2个使能信号需要同时满足不然会读出随机数）使能信号控制
wire                   RAM_WEN = (state == S_IDLE)&(next_state == S_HIT)         ;//为0是写使能1是读使能，读写控制hit是读数据
wire [R_DATA_WIDTH-1:0]maskn   = 64'h0                                           ;//写掩码，目前是全位写，掩码在发送端处理了
wire [INDEX_DEPTH-1:0] RAM_BWEN= maskn                                           ;//ram写掩码目前一样不用过多处理
wire [INDEX_WIDTH-1:0] RAM_A   = (next_state == S_HIT) ? index_in : addr[RAML:RAMR] ;//ram地址索引
wire [INDEX_DEPTH-1:0] RAM_D   = cache_r_data_i                                  ;//更新ram数据

always@(*) begin
  if(rst)begin
    RAM_CEN[0] = 1;
    RAM_CEN[1] = 1;
  end
  else if((state == S_IDLE)&(next_state == S_HIT)|(state == S_R)&(next_state == S_HIT))
  RAM_CEN[hit_waynum_i|waynum] = 0;
  else
  RAM_CEN[hit_waynum_i|waynum] = 1;
end

//实例化两块ram以及他们的命中逻辑的添加
generate
  genvar i;
  for(i=0;i<WAY_DEPTH;i=i+1)begin
  assign hit_wayflag[i]=((tag[i][index_in]==tag_in)&&valid[i][index_in]);
      S011HD1P_X32Y2D128_BW S011HD1P_X32Y2D128_BW_U0
      (
        .Q(RAM_Q[i]),
        .CLK(clk),
        .CEN(RAM_CEN[i]),
        .WEN(RAM_WEN),
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

reg[15:0] state;
reg[15:0] next_state;

always@(posedge clk) begin
  if(rst)state<=S_IDLE;
  else state<=next_state;
end

always@(*) begin
  if(rst)next_state=S_IDLE;
  else case(state)
    S_IDLE:if(ar_valid_i&ar_ready_o)begin
            if(|hit_wayflag)next_state=S_HIT;
            else next_state=S_AR;
          end
        else next_state=S_IDLE;

    S_HIT:if(r_data_ready_i&r_data_valid_o)next_state=S_IDLE;
      else next_state=S_HIT;

    S_AR:if(cache_ar_valid_o&cache_ar_ready_i)next_state=S_R;
      else next_state=S_AR;

    S_R:if(cache_r_ready_o&cache_r_valid_i)next_state=S_HIT;
      else next_state=S_R;

    default:next_state=S_IDLE;
  endcase
end
import "DPI-C" function void icache_wait();
always@(posedge clk)begin
  if(rst)begin
		ar_ready_o          <= 1;
		r_data_valid_o      <= 0;
		r_data_o            <= 0;
    cache_ar_valid_o    <= 0;
    cache_ar_addr_o     <= 0;
		cache_r_ready_o     <= 0;
    waynum              <= 0;
    addr                <= 0;
  end
  else begin
    case(state)
      S_IDLE:if(next_state==S_HIT)begin
					ar_ready_o              <= 0           ;
          r_data_valid_o          <= 0           ; 
          waynum                  <= hit_waynum_i;
          addr                    <= {ar_addr_i[TAGL:INDEXR],OFFSET0};
        end
        else if(next_state==S_AR)begin
          icache_wait()               ;//多跑2个周期平衡
					ar_ready_o              <= 0;
          waynum                  <= random;
          addr                    <= {ar_addr_i[TAGL:INDEXR],OFFSET0};
          valid[random][index_in] <= 0;
          tag[random][index_in]   <= ar_addr_i[TAGL:TAGR];
          cache_ar_valid_o        <= 1;
          cache_ar_addr_o         <= {32'b0,ar_addr_i[TAGL:INDEXR],OFFSET0};
        end
        else begin
					ar_ready_o              <= 1;
					r_data_valid_o          <= 0;
					cache_r_ready_o         <= 0;
        end
      S_HIT:if(next_state==S_IDLE)begin
					ar_ready_o          <= 1;
					r_data_valid_o      <= 0;
          waynum              <= 0;
          r_data_o            <= 0;
      end
      else begin
          r_data_valid_o          <= 1            ; 
          r_data_o                <= RAM_Q[waynum];
      end
      S_AR:if(next_state==S_R)begin
          cache_ar_valid_o  <= 0;
          cache_r_ready_o  <= 1;
          end
      S_R:if(next_state==S_HIT)begin
          cache_r_ready_o     <= 0             ;
          valid[waynum][index]<= 1             ;
          r_data_o            <= cache_r_data_i;
          r_data_valid_o      <= 1             ;
          end
      default:begin
      end
    endcase
  end
end
endmodule
