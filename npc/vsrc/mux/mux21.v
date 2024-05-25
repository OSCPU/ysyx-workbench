module mux21(a,b,s,y);
  input   a,b,s;        // 声明3个wire型输入变量a,b,和s，其宽度为1位。
  output  y;           // 声明1个wire型输出变量y，其宽度为1位。

MuxKeyWithDefault #(2, 1, 1) mux21_0 (y, s, 1'b0, {1'b0, a, 1'b0, b});

endmodule