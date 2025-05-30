module encoder(x,y,flag);
	input  [7:0] x;
	output reg [2:0] y;
	output reg flag;
	integer i;
	
	always @(x) begin
		if(x == 8'b00000000) begin
			//无开关处于1,flag置0,数码管不显示
			y <= 3'b000;
			flag <= 1'b0;
		end
		else begin
			flag <= 1'b1;
			for( i = 7; i >= 0; i = i-1) begin
				if(x[i] == 1) begin
					y <= i[2:0];
					break;
				end
			end
		end	
	end
endmodule

module decoder(x,flag,seg);
	input  [2:0] x;
	input flag;
	output reg [7:0] seg;
	integer i;
	
	reg [7:0] y;
	always @(x or flag) begin
		if(flag == 1'b0) y <= 8'b00000000;
		else begin
			for(i = 0; i <= 7; i = i + 1) begin
				case(x)
					3'd7 : y <= 8'b11100000;
					3'd6 : y <= 8'b10111110;
					3'd5 : y <= 8'b10110110;
					3'd4 : y <= 8'b01100110;			
					3'd3 : y <= 8'b11110010;
					3'd2 : y <= 8'b11011010;
					3'd1 : y <= 8'b01100000;
					3'd0 : y <= 8'b11111100;
				endcase
			end
		end
	end
	assign seg = ~y;
endmodule

module top(x, seg, led, flag);
	input [7:0]x;
	output [7:0]seg;
	output [2:0]led;
	output flag;
	
	wire [2:0] y;
	encoder i1(.x(x), .y(y), .flag(flag));
	decoder i2(.x(y), .flag(flag), .seg(seg));
	assign led = y;
endmodule	
	
