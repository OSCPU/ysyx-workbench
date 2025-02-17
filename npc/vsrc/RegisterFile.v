module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input clk,
  input rst,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  output reg [DATA_WIDTH-1:0] rdata1,
  
  input [ADDR_WIDTH-1:0] raddr1
 
);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];

  // 读寄存器
  assign rdata1 = (raddr1 == 0) ? 0 : rf[raddr1]; // 0号寄存器始终为0
  

  // 写寄存器
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      integer i;
      for (i = 0; i < 32; i = i + 1)
        rf[i] <= 0;
    end else if (wen && waddr != 0&&wdata!=0) begin // 0号寄存器不能写入
      
      rf[waddr] = wdata;
      $display("final register written: R1 = %d, wdata=%d", rf[waddr], wdata);
      
   
    end
  end
endmodule

