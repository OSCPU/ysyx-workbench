module mux41(a,s,y);
  input  [3:0] a;  // 声明一个wire型输入变量a，其变量宽度是4位的。
  input  [1:0] s;  // 声明一个wire型输入变量s，其变量宽度是2位的。
  output reg y;   // 声明一个1位reg型的输出变量y。

MuxKeyWithDefault #(4, 2, 1) mux41_0 (y, s, 1'b0, {
  2'b00, a[0], 
  2'b01, a[1], 
  2'b10, a[2], 
  2'b11, a[3]});

endmodule