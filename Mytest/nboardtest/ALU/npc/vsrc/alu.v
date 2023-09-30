module alu(
	input [10:0]sw,
	output reg [15:0]ledr);
	wire [3:0] op;
	reg [3:0] out1,out0,out2;
	reg overflow1,overflow0;
	//A:sw[3:0] B:sw[7:4] select:sw[10:8] out:ledr[3:0] overflow:ledr[4]
	assign op=~sw[7:4];
	adre u1(sw[3:0],op,1,out1,overflow1);
	adre u0(sw[3:0],sw[7:4],0,out0,overflow0);
	cp u3(sw[3:0],sw[7:4],out2);
	always @(*)
	begin
		case(sw[10:8])
		3'b000:begin ledr[3:0]=out0;ledr[4]=overflow0; end
		3'b001:begin ledr[3:0]=out1;ledr[4]=overflow1; end
		3'b010:ledr[3:0]=~sw[3:0];
		3'b011:ledr[3:0]=sw[3:0]&sw[7:4];
		3'b100:ledr[3:0]=sw[3:0]|sw[7:4];
		3'b101:ledr[3:0]=sw[3:0]^sw[7:4];
		3'b110:ledr[3:0]=out2;
		3'b111:ledr[3:0]=out2;
		default : ledr[4:0]=0;
		endcase
		
	end
endmodule

module adre(
	input [3:0] a,b,cin,
	output [3:0]sum,
	output cout);
	assign {cout,sum}=a+b+cin;
endmodule

module cp(
	input [3:0] a,b,
	output reg [3:0] out);
	always @(*)
	begin
	if(a==b)
	out=1;
	else if(a<b)
	out=1;
	else
	out=0;
	end
endmodule
