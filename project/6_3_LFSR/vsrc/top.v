module LFSR(Clk, rst, y);
	input Clk;
	input rst;
	output reg [7:0]y;
	
	reg [7:0]data;
	always @(posedge Clk or rst) begin
		if(!rst) data <= 8'b00000001;
		else data <= {data[4]^data[3]^data[2]^data[0], data[7:1]};
	end
	assign y = data;
endmodule

module smg(x,seg);
	input  [3:0] x;
	output reg [7:0] seg;
	integer i;
	
	reg [7:0] y;
	always @(x) begin
		for(i = 0; i <= 7; i = i + 1) begin
			case(x)
				4'b0111 : y <= 8'b11100000;
				4'b0110 : y <= 8'b10111110;
				4'b0101 : y <= 8'b10110110;
				4'b0100 : y <= 8'b01100110;			
				4'b0011 : y <= 8'b11110010;
				4'b0010 : y <= 8'b11011010;
				4'b0001 : y <= 8'b01100000;
				4'b0000 : y <= 8'b11111100;
				4'b1001 : y <= 8'b11110110;
				4'b1010 : y <= 8'b11101110;
				4'b1011 : y <= 8'b00111110;
				4'b1100 : y <= 8'b10011100;			
				4'b1101 : y <= 8'b01111010;
				4'b1110 : y <= 8'b11110010;
				4'b1111 : y <= 8'b10001110;
				4'b1000 : y <= 8'b11111110;
			endcase
		end

	end
	assign seg = ~y;
endmodule

module top(Clk, rst, seg_1, seg_2, y);
	input Clk;
	input rst;
	output reg [7:0]seg_1;
	output reg [7:0]seg_2;
	output reg [7:0]y;
	
	wire [7:0]y_1;
	
	LFSR i1(.Clk(Clk), .rst(rst), .y(y_1));
	
	wire [3:0]data_1;
	wire [3:0]data_2;
	
	assign data_1 = y_1[7:4];
	assign data_2 = y_1[3:0];
	smg i2(.x(data_1), .seg(seg_1));
	smg i3(.x(data_2), .seg(seg_2));
	assign y = y_1;
	
endmodule
	
