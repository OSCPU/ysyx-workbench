module decode38(x,en,y);
  input  [2:0] x;
  input  en;
  output reg [7:0]y;
  integer i;

  always @(x or en)
    if (en) begin
      for( i = 0; i <= 7; i = i+1)
          if(x == i)
                y[i] = 1;
          else
                y[i] = 0;
    end
    else
      y = 8'b00000000;

endmodule