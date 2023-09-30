module register(
	input [13:0]sw,
	input BTNC,
	output reg [15:0] ledr
	);
	//input:sw[7:0] sw[9:8] 00-->> 01--<< 10-->>> 11--<<<
	//sw[12:10] n位 sw[13] reset the input 
	reg [7:0] out;

	always @(posedge BTNC)
	begin
	if(sw[13])
	out[7:0]=sw[7:0];
	case(sw[9:8])
	2'b00:begin
		ledr[7:0]=sw[10]?{1'b0,out[7:1]}:out[7:0];
		ledr[7:0]=sw[11]?{2'b0,ledr[7:2]}:ledr[7:0];
		ledr[7:0]=sw[12]?{4'b0,ledr[7:4]}:ledr[7:0];
		out[7:0]=ledr[7:0];
              end
	2'b10:begin
		ledr[7:0]=sw[10]?{{out[7]},out[7:1]}:out[7:0];
		ledr[7:0]=sw[11]?{{2{ledr[7]}},ledr[7:2]}:ledr[7:0];
		ledr[7:0]=sw[12]?{{4{ledr[7]}},ledr[7:4]}:ledr[7:0];
		out[7:0]=ledr[7:0];
              end
	2'b11,2'b01:begin
		ledr[7:0]=sw[10]?{{out[6:0]},1'b0}:out[7:0];
		ledr[7:0]=sw[11]?{{ledr[5:0]},2'b0}:ledr[7:0];
		ledr[7:0]=sw[12]?{{ledr[3:0]},4'b0}:ledr[7:0];
		out[7:0]=ledr[7:0];
              end

	endcase
	end

	
endmodule
