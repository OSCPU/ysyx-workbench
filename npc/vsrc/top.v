module top(
  input clk,
  input rst,
  output reg [15:0] led
);

light my_light(
  .clk(clk),
  .rst(rst),
  .led(led)
);


endmodule
