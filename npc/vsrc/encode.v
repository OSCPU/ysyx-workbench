module encode42(x,en,y);
  input  [3:0] x;
  input  en;
  output reg [1:0]y;

  always @(x or en) begin
    if (en) begin
      case (x)
          4'b0001 : y = 2'b00;
          4'b0010 : y = 2'b01;
          4'b0100 : y = 2'b10;
          4'b1000 : y = 2'b11;
          default: y = 2'b00;
      endcase
    end
    else  y = 2'b00;
  end
endmodule

module encode42_p (x,en,y);
  input  [3:0] x;
  input  en;
  output reg [1:0]y;
  integer i;
  always @(x or en) begin
    if (en) begin
      y = 0;
      for( i = 0; i <= 3; i = i+1)
          if(x[i] == 1)  y = i[1:0];
    end
    else  y = 0;
  end
endmodule

module encode83 (x,en,y);
input [7:0] x;
input en;
output reg [2:0] y;
always @(x or en) begin
  if(en) begin
  casez (x)
    8'b1???????: y = 3'b111;
    8'b01??????: y = 3'b110;
    8'b001?????: y = 3'b101;
    8'b0001????: y = 3'b100;
    8'b00001???: y = 3'b011;
    8'b000001??: y = 3'b010;
    8'b0000001?: y = 3'b001;
    8'b00000001: y = 3'b000;
  
   default: y = 3'b000;
  endcase
   end
  else y = 3'b000;
end


endmodule