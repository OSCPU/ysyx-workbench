module top(
  input [7:0] x,
  input en,
  output reg [6:0] h,
  output reg dec
);
reg [2:0] y;
encode83 e83(x,en,y);
bcd7seg bcd({1'b0,y},h,dec);


endmodule
