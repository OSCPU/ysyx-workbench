module m_mux21(a,b,s,y);
  input   a,b,s;        // 声明3个wire型输入变量a,b,和s，其宽度为1位。
  output  y;           // 声明1个wire型输出变量y，其宽度为1位。

  assign  y = (~s&a)|(s&b);  // 实现电路的逻辑功能。

endmodule