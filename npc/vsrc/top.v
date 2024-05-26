module top(
input [1:0] x,
input en,
output [3:0] y

);
decode24 u1(.x(x),.en(en),.y(y));








endmodule
