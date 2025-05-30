/*
module comp(x,y);
	input  [3:0] x;
	output reg[3:0] y;
	
	reg[2:0] x_1;
	always @(x) begin
		x_1 = ~(x[2:0]) + 1;
		y = (x[3] == 0)? x : {x[3],x_1[2:0]};
	end
endmodule
*/
module add(
  input  [3:0] io_in_a,
  input  [3:0] io_in_b,
  output [3:0] io_out,
  input  [2:0] io_sw,
  output       io_carry,
  output       io_overflow
);
  wire [7:0] oneHot = 8'h1 << io_sw; // @[OneHot.scala 64:12]
  wire [4:0] addResult = $signed(io_in_a) + $signed(io_in_b); // @[module.scala 18:28]
  wire [4:0] subResult = $signed(io_in_a) - $signed(io_in_b); // @[module.scala 19:28]
  wire [4:0] _io_out_T_9 = $signed(io_in_a) + $signed(io_in_b); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_11 = $signed(io_in_a) - $signed(io_in_b); // @[Mux.scala 27:73]
  wire [3:0] _io_out_T_13 = $signed(io_in_a) & $signed(io_in_b); // @[Mux.scala 27:73]
  wire [3:0] _io_out_T_15 = $signed(io_in_a) | $signed(io_in_b); // @[Mux.scala 27:73]
  wire [3:0] _io_out_T_17 = $signed(io_in_a) ^ $signed(io_in_b); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_24 = oneHot[0] ? $signed(_io_out_T_9) : $signed(5'sh0); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_25 = oneHot[1] ? $signed(_io_out_T_11) : $signed(5'sh0); // @[Mux.scala 27:73]
  wire [4:0] _io_out_WIRE_2 = {{1{_io_out_T_13[3]}},_io_out_T_13}; // @[Mux.scala 27:{73,73}]
  wire [4:0] _io_out_T_26 = oneHot[2] ? $signed(_io_out_WIRE_2) : $signed(5'sh0); // @[Mux.scala 27:73]
  wire [4:0] _io_out_WIRE_3 = {{1{_io_out_T_15[3]}},_io_out_T_15}; // @[Mux.scala 27:{73,73}]
  wire [4:0] _io_out_T_27 = oneHot[3] ? $signed(_io_out_WIRE_3) : $signed(5'sh0); // @[Mux.scala 27:73]
  wire [4:0] _io_out_WIRE_4 = {{1{_io_out_T_17[3]}},_io_out_T_17}; // @[Mux.scala 27:{73,73}]
  wire [4:0] _io_out_T_28 = oneHot[4] ? $signed(_io_out_WIRE_4) : $signed(5'sh0); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_33 = $signed(_io_out_T_24) | $signed(_io_out_T_25); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_35 = $signed(_io_out_T_33) | $signed(_io_out_T_26); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_37 = $signed(_io_out_T_35) | $signed(_io_out_T_27); // @[Mux.scala 27:73]
  wire [4:0] _io_out_T_47 = $signed(_io_out_T_37) | $signed(_io_out_T_28); // @[Mux.scala 27:73]
  wire  _io_overflow_T_7 = io_in_a[3] == io_in_b[3] & io_in_a[3] != addResult[3]; // @[module.scala 50:47]
  wire  _io_overflow_T_15 = io_in_a[3] != io_in_b[3] & io_in_a[3] != subResult[3]; // @[module.scala 51:47]
  assign io_out = _io_out_T_47[3:0]; // @[module.scala 26:10]
  assign io_carry = oneHot[0] & addResult[4] | oneHot[1] & subResult[4]; // @[Mux.scala 27:73]
  assign io_overflow = oneHot[0] & _io_overflow_T_7 | oneHot[1] & _io_overflow_T_15; // @[Mux.scala 27:73]
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
				
				4'b1001 : y <= 8'b11100001;
				4'b1010 : y <= 8'b10111111;
				4'b1011 : y <= 8'b10110111;
				4'b1100 : y <= 8'b01100111;			
				4'b1101 : y <= 8'b11110011;
				4'b1110 : y <= 8'b11011011;
				4'b1111 : y <= 8'b01100001;
				4'b1000 : y <= 8'b11111111;
				
			endcase
		end

	end
	assign seg = ~y;
endmodule

module top(x, y, sw, result, Carry, Overflow, Zero, smg_1, smg_2, smg_3, smg_4, smg_5, smg_6, smg_7, smg_8);
	input [3:0]x;
	input [3:0]y;
	input [2:0]sw;
	
	output [3:0]result;
	output Carry;
	output Overflow;
	output Zero;
	output [7:0]smg_1;
	output [7:0]smg_2;
	output [7:0]smg_3;
	
	output [7:0]smg_4;
	output [7:0]smg_5;
	output [7:0]smg_6;
	output [7:0]smg_7;
	output [7:0]smg_8;
	
	//wire [3:0] data_x;
	//wire [3:0] data_y;
	
	//comp i1(.x(x), .y(data_x));
	//comp i2(.x(y), .y(data_y));
	
	wire [3:0] result;
	wire Carry;
	add i3(.io_in_a(x), .io_in_b(y), .io_out(result), .io_sw(sw), .io_carry(Carry), .io_overflow(Overflow));
	
	//assign Overflow = ((x[3] == y[3]) && (y[3] != result[3]) )? 1:0;
	assign Zero = (result == 4'b0000)? 1:0;
	
	smg i4(.x(x), .seg(smg_1));
	smg i5(.x(y), .seg(smg_2));
	smg i6(.x(result), .seg(smg_3));
	
	assign smg_4 = 8'b11111111;
	assign smg_5 = 8'b11111111;
	assign smg_6 = 8'b11111111;
	assign smg_7 = 8'b11111111;
	assign smg_8 = 8'b11111111;
endmodule
	
