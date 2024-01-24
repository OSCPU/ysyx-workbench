module ysyx_23060111_pc(	
	input clk,
	input rst,
	input [31:0]snpc,
	//input  [31:0] dnpc,
	output [31:0]pc
);
	//assign snpc=pc+32'h4;
 	ysyx_23060111_trigger #(32,32'h80000000) renew_pc(clk,rst,snpc,pc,1'b1);
	
endmodule
