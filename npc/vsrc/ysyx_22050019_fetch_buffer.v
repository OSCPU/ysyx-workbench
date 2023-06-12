
module ysyx_22050019_fetch_buffer#(
  parameter   WIDTH = 128,
  parameter   DEPTH = 4
)(
  input           clk    , 
  input           rst_n  ,
  input           winc  ,
  input            rinc  ,
  input     [WIDTH-1:0]  wdata  ,

  output reg        wfull  ,
  output reg        rempty  ,
  output wire [WIDTH-1:0]  rdata
);
  // 用localparam定义一个参数，可以在文件内使用
    localparam ADDR_WIDTH = DEPTH;

    reg [ADDR_WIDTH:0] waddr;
    reg [ADDR_WIDTH:0] raddr;
    always @ (posedge clk) begin
        if(~rst_n) begin
            waddr <= 'b0;
        end 
        else begin
            if( winc && ~wfull ) begin
                waddr <= waddr + 1'b1;
            end 
            else begin
                waddr <= waddr;    
            end 
        end 
    end 

    always @ (posedge clk) begin
        if(~rst_n) begin
            raddr <= 'b0;
        end 
        else begin
            if( rinc && ~rempty ) begin
                raddr <= raddr + 1'b1;
            end 
            else begin
                raddr <= raddr;    
            end 
        end 
    end 


assign wfull  = (raddr == {~waddr[ADDR_WIDTH], waddr[ADDR_WIDTH-1:0]});
assign rempty = (raddr == waddr);

// 带有 parameter 参数的例化格式    
inst_buffer  fifo 
    (
    .clk  ( clk                   ),
    .wenc ( winc                  ),
    .waddr( waddr[ADDR_WIDTH-1:0] ), 
    .wdata( wdata                 ),        
    .raddr( raddr[ADDR_WIDTH-1:0] ), 
    .rdata( rdata                 )     
);       
endmodule

/**************RAM 子模块*************/
module inst_buffer #(
    parameter DEPTH = 4,
    parameter WIDTH = 128)
(
  input                     clk  , 
  input                     wenc ,
  input [DEPTH-1:0] waddr,  //深度对2取对数，得到地址的位宽。
  input [WIDTH-1:0]         wdata,  //数据写入
  input [DEPTH-1:0] raddr,  //深度对2取对数，得到地址的位宽。
  output[WIDTH-1:0]         rdata,  //数据输出
);

reg [WIDTH-1:0] RAM_MEM [0:DEPTH-1];

always @(posedge clk) begin
  if(wenc)
    RAM_MEM[waddr] <= wdata;
end 

assign rdata = wenc & (waddr == rdaar) ? wdata : RAM_MEM[raddr];
endmodule