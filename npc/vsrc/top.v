module top(
  input  [7:0] a,  // 声明一个wire型输入变量a，其变量宽度是4位的。
  input  [1:0] s,  // 声明一个wire型输入变量s，其变量宽度是2位的。
  output reg [1:0]y
  
);
m_mux41 mux41_0 (a, s, y);






endmodule
