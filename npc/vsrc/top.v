module top(
  input clk,
  input rst,
  input a,b,s,
  output reg [15:0] led,
  output y
);

m_mux21 my_mux21(
  .a(a),
  .b(b),
  .s(s),
  .y(y)
);



light my_light(
  .clk(clk),
  .rst(rst),
  .led(led)
);


endmodule
