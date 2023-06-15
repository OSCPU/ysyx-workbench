module ysyx_22050019_fetch_buffer#(
  parameter   WIDTH = 128,
  parameter   RESET_VAL = 64'h80000000
)(
  input                   clk         , 
  input                   rst_n       ,
  // axi-i_cahce
  input                   ar_ready_i  ,
  output                  ar_valid_o  ,
  output [31:0]           ar_addr_o   ,

  input                   r_valid_i   ,
  input  [127:0]          r_data_i    , 
  input  [1:0]            r_resp_i    ,  
  output                  r_ready_o   ,

  // ifu-fetch_buffer
  // control
  input                   jmp_flush_i ,

  input  [31:0]           pc_i        ,


  output                  inst_valid_o,
  output [31:0]           inst_o          
);
//=========================  
// 判断输入pc是否相等的逻辑
// buffer pc
reg [27:0]buffer_pc; //只保存pc在cache line的块映射，也就是说对于低4位偏移拉0来对比
always @ (posedge clk) begin
    if(rst_n)begin
        buffer_pc <= RESET_VAL[31:4];
    end
    else if(pc_equal) begin
        buffer_pc <= buffer_pc;
    end
    else begin
        buffer_pc <= pc_i[31:4];
    end
end

wire pc_equal   = (buffer_pc == pc_i[31:4]);
wire pc_changed = (buffer_pc != pc_i[31:4]);

// 读写记数器
reg rw_cnt;
always @ (posedge clk) begin
    if(rst_n) begin
        rw_cnt <= 0;
    end
    else if(jmp_flush_i) begin
        rw_cnt <= 0     ;
    end
    else if(rinc & winc) begin
        rw_cnt <= rw_cnt;
    end
    else if(winc) begin
        rw_cnt <= rw_cnt + 1'b1;
    end
    else if(rinc) begin
        rw_cnt <= rw_cnt - 1'b1;
    end
    else begin
        rw_cnt <= rw_cnt;
    end
end

// 根据pc_changed进行读地址使能变化的模块
// read_fifo_control
wire rinc = ~rempty && pc_changed;

// 根据buffer状态和pc输出指令和指令有效使能
assign inst_valid_o = pc_equal & ~rempty | ((pc_changed & ~jmp_flush_i) & rw_cnt != 1'b1)| rempty & r_valid_i & r_ready_o & ~jmp_flage & ~jmp_flush_i;

assign inst_o       = inst_valid_o ? (pc_i[3] ? pc_i [2] ? rdata[127:96] : rdata[95:64] : pc_i [2] ? rdata[63:32] : rdata[31:0]) : 0;//仿真调试bug用，后期删除
//=========================  
//=========================  
// AXI buffer <=> icache交流接口逻辑
// AXI - interface
  // 状态准备
  localparam IDLE       = 1'd0;
  localparam WAIT_READY = 1'd1;

  reg  state_reg;
  reg  next_state;
  
  reg [1:0] rresp;
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
    IDLE :
      if(ar_ready_i && ar_valid_o) begin next_state = WAIT_READY ; end
      else next_state = IDLE;

    WAIT_READY : 
      if(r_valid_i && r_ready_o) begin next_state = IDLE; end
      else next_state = WAIT_READY;

    default : next_state = IDLE;
  endcase
end
reg rready;
reg ar_valid;//跳转在传输过程中改变pc，为1说明pc改变的和访问的不一样需要重新传
reg jmp_flage;
  // 读的状态机
always@(posedge clk)begin
  if(rst_n)begin
        ar_valid        <= 1'b0;
        rready          <= 1'b0;
        rresp           <= 2'b0;
        jmp_flage       <= 1'b0;
  end
  else begin
    case(state_reg)
      IDLE:
      if(next_state==WAIT_READY) begin
        ar_valid        <= 1'b0;
        rready          <= 1;
      end
      else if(ar_valid_o) begin
        jmp_flage       <= 1'b0;
        rresp           <= 2'b0;
        ar_valid        <= 1'b1;
        rready          <= 1'b0;
      end
      else begin
        jmp_flage       <= 1'b0;
        rresp           <= 2'b0;
        ar_valid        <= 1'b0;
        rready          <= 1'b0;
      end

      WAIT_READY:begin  
      if(next_state==IDLE)begin
        jmp_flage       <= 0;
        ar_valid        <= 1'b1;
        rready          <= 1'b0;
        rresp           <= r_resp_i;
      end
      else begin 
      if(jmp_flush_i) begin
        jmp_flage       <= 1;
      end 
        ar_valid        <= 1'b0;
        rready          <= 1;
      end
      end
      default:begin
      end
    endcase
  end
end

// axi_interface
assign ar_valid_o   = (state_reg == IDLE) ? ~wfull :0;
assign ar_addr_o    = jmp_flush_i & (state_reg == IDLE) ? {pc_i[31:4],4'b0} : {(buffer_pc + {26'b0,rw_cnt}), 4'b0} ;

assign r_ready_o    = rready;

// write_fifo_control
wire winc         = r_valid_i & r_ready_o & ~jmp_flush_i & ~jmp_flage;//检测是否跳转，跳转的话本次cache访问无效
wire [WIDTH-1:0] wdata        = r_data_i;
//========================= 
//=========================  
  // 同步fifo的读写逻辑逻辑
/*
wire               rinc  ;
wire               winc  ; 
wire [WIDTH-1:0]   wdata ;
wire               wfull ;
wire               rempty;
*/
wire [WIDTH-1:0]   rdata ;
  // 用localparam定义一个参数，可以在文件内使用

    reg [1:0] waddr;
    reg [1:0] raddr;
  
    always @ (posedge clk) begin
        if(rst_n) begin
            waddr <= 0;
        end 
        else if( winc && ~wfull ) begin
                waddr <= waddr + 1;
        end 
        else begin
                waddr <= waddr;    
        end 
    end 

    always @ (posedge clk) begin
        if(rst_n) begin
            raddr <= 0;
        end 
        else if(jmp_flush_i) begin
                raddr <= waddr;
        end 
        else if( rinc && ~rempty ) begin
                raddr <= raddr + 1;
        end 
        else begin
                raddr <= raddr;    
        end 
    end 
    
wire wfull  = (raddr == {~waddr[1], waddr[0]});
wire rempty = (raddr == waddr);

// 带有 parameter 参数的例化格式    
inst_buffer  buffer_regs 
    (
    .clk  ( clk                   ),
    .wenc ( winc                  ),
    .waddr( waddr[0] ), 
    .wdata( wdata                 ),        
    .raddr( (pc_changed & ~jmp_flush_i) ? raddr[0] + 1'b1 : raddr[0] ), 
    .rdata( rdata                 )     
);
//=========================    
     
endmodule

/**************RAM 子模块*************/
module inst_buffer #(
    parameter DEPTH = 2,
    parameter WIDTH = 128)
(
  input                     clk  , 
  input                     wenc ,
  input                     waddr,  //深度对2取对数，得到地址的位宽。
  input [WIDTH-1:0]         wdata,  //数据写入
  input                     raddr,  //深度对2取对数，得到地址的位宽。
  output[WIDTH-1:0]         rdata   //数据输出
);

reg [WIDTH-1:0] RAM_MEM [DEPTH-1:0];

always @(posedge clk) begin
  if(wenc)
    RAM_MEM[waddr] <= wdata;
end 

assign rdata = wenc & (waddr == raddr) ? wdata : RAM_MEM[raddr];
endmodule