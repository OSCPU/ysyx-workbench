module top (
    input clk,
    input rst,
    input [13:0] sw,
    input ps2_clk,
    input ps2_data,
    input BTNC,
    input BTNU,
    input BTND,
    input BTNL,
    input BTNR,
    output [15:0] ledr,
    output VGA_CLK,
    output VGA_HSYNC,
    output VGA_VSYNC,
    output VGA_BLANK_N,
    output [7:0] VGA_R,
    output [7:0] VGA_G,
    output [7:0] VGA_B,
    output [7:0] seg0,
    output [7:0] seg1,
    output [7:0] seg2,
    output [7:0] seg3,
    output [7:0] seg4,
    output [7:0] seg5,
    output [7:0] seg6,
    output [7:0] seg7
);

ps2_keyboard my_keyboard(
	.clk(clk),
	.resetn(~rst),
	.ps2_clk(ps2_clk),
	.ps2_data(ps2_data),
	.seg7(seg7),
	.seg6(seg6),
	.seg4(seg4),
	.seg3(seg3),
	.seg1(seg1),
	.seg0(seg0)
);

endmodule

//seg 0-F
/*
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
	*/


