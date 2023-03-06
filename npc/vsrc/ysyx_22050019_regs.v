import "DPI-C" function void get_regs(input logic [63:0] a []);
module ysyx_22050019_regs #(ADDR_WIDTH = 5, DATA_WIDTH = 64) (
  input     clk,
  input     [DATA_WIDTH-1:0] now_pc,
  input     [DATA_WIDTH-1:0] wdata  ,
  input     [ADDR_WIDTH-1:0] waddr  ,
  input     wen                     ,

  input     [DATA_WIDTH-1:0] csr_regs_diff[3:0],

  input     [ADDR_WIDTH-1:0] raddr1 ,
  input     [ADDR_WIDTH-1:0] raddr2 ,
  output    [DATA_WIDTH-1:0] rdata1 ,
  output    [DATA_WIDTH-1:0] rdata2
);
  reg [DATA_WIDTH-1:0] regs [31:0];
  assign regs[0] = 64'b0 ;
//写寄存器
  always @(posedge clk) begin
    if (wen && waddr!= 5'b0) begin regs[waddr] <= wdata; end
  end
  assign    rdata1 = regs[raddr1] ;
  assign    rdata2 = regs[raddr2] ;
 
  wire [DATA_WIDTH-1:0] regs1 [36:0];
 
  assign regs1[36:33] = csr_regs_diff [3:0];
  assign regs1[32]    = now_pc;
  assign regs1[31:0]  = regs [31:0];
initial get_regs(regs1);  // regs1为通用寄存器的二维数组变量
endmodule

