module register(
	input [8:0]sw,
	input BTNC,
	output reg [15:0] ledr,
	output reg [7:0] seg0,seg1);

	//clk:BTNC changeinput:sw[8] input:sw[7:0]

	seg u0(ledr[3:0],seg0);
	seg u1(ledr[7:4],seg1);

	integer i;
	reg[8:0] out;
	always @(ledr)
	begin
	out[8]=ledr[4]^ledr[3]^ledr[2]^ledr[0];
	out[7:0]=ledr[7:0];
	end

	always @(posedge BTNC)
	begin
		if(sw[8])
		ledr[7:0]=sw[7:0];
		else
		begin
			for(i=0;i<=255;i=i+1)
			begin
				if(i==255)
				begin
				if(ledr[7:0]==0)
				ledr[7:0]=8'b11111111;
				else
				ledr[7:0]={out[8],out[7:1]};
				end
			end
		end
	end
endmodule


module seg(
	input [3:0]ledr,
	output reg [7:0]seg0 );
	always @(*)	
	begin
	case(ledr[3:0])

	4'b0000:seg0[7:0]=8'b00000011;
	4'b0001:seg0[7:0]=8'b10011111;
	4'b0010:seg0[7:0]=8'b00100101;
	4'b0011:seg0[7:0]=8'b00001101;
	4'b0100:seg0[7:0]=8'b10011001;
	4'b0101:seg0[7:0]=8'b01001001;
	4'b0110:seg0[7:0]=8'b01000001;
	4'b0111:seg0[7:0]=8'b00011111;
	4'b1000:seg0[7:0]=8'b00000001;
	4'b1001:seg0[7:0]=8'b00011001;
	4'b1010:seg0[7:0]=8'b00010001;
	4'b1011:seg0[7:0]=8'b00000000;
	4'b1100:seg0[7:0]=8'b01100011;
	4'b1101:seg0[7:0]=8'b00000011;
	4'b1110:seg0[7:0]=8'b01100001;
	4'b1111:seg0[7:0]=8'b01110001;

	endcase
	end
endmodule
