module ysyx_23060111_reg #(ADDR_WIDTH = 1, DATA_WIDTH = 1) (
  input clk,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input [ADDR_WIDTH-1:0] raddr,
  input wen,
  output [DATA_WIDTH-1:0] rout,
  output [DATA_WIDTH-1:0] halt_ret
);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
  assign rout=rf[raddr];
  assign halt_ret=rf[10];
  always @(posedge clk) begin
    if (wen) rf[waddr] <= wdata;
  end
endmodule
