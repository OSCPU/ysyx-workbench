module encoder(
	input [8:0] sw,
	output [7:0] out,
	output reg [15:0] ledr);
	
	wire [7:0] hex;
	seg u0(ledr[2:0],hex);
	assign out=hex; 

	always @(*)
	begin
	if(sw[8])
	begin

	if(sw[7:0]==0)
	ledr[4]=0;
	else
	ledr[4]=1;

	casez(sw[7:0])
	8'b1zzzzzzz:ledr[2:0]=7;
	8'b01zzzzzz:ledr[2:0]=6;
	8'b001zzzzz:ledr[2:0]=5;
	8'b0001zzzz:ledr[2:0]=4;
	8'b00001zzz:ledr[2:0]=3;
	8'b000001zz:ledr[2:0]=2;
	8'b0000001z:ledr[2:0]=1;
	8'b00000001:ledr[2:0]=0;
	default :ledr[2:0]=0;
	endcase

	end

	else
	begin
	ledr[2:0]=0;
	ledr[4]=0;
	end
			
	end


endmodule

module seg(
	input [2:0] b,
	output reg [7:0] h);
	always @(*)
	begin
		case(b)
		3'b000:h=8'b00000011;
		3'b001:h=8'b10011111;
		3'b010:h=8'b00100101;
		3'b011:h=8'b00001101;
		3'b100:h=8'b10011001;
		3'b101:h=8'b01001001;
		3'b110:h=8'b01000001;
		3'b111:h=8'b00011111;
		default:h=8'b11111111;
		endcase
	end

endmodule
