module m_mux41(a,s,y);
  input  [7:0] a;  // 声明一个wire型输入变量a，其变量宽度是4位的。
  input  [1:0] s;  // 声明一个wire型输入变量s，其变量宽度是2位的。
  output reg [1:0]y; 
  
  
  
  
    // 声明一个1位reg型的输出变量y。
MuxKeyWithDefault #(4, 2, 2) mux41_0 (y, s, 2'b00, {
  2'b00, a[1:0], 
  2'b01, a[3:2], 
  2'b10, a[5:4], 
  2'b11, a[7:6]});


endmodule