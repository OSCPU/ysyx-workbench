module top(
  input [3:0] x,
  input en,
  output reg [1:0] y

);
encode42_p enc42(
  .x(x),
  .en(en),
  .y(y)
);









endmodule
