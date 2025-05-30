module top(Clk, x, sw, data, key, y);
	input Clk;
	input [7:0]x;
	input [2:0]sw;
	input [3:0]data;
	input key;
	output reg [7:0]y;
	
	always @(posedge Clk) begin
		case (sw)
			3'b000: y <= 8'b00000000;
			3'b001: y <= {data, data};
			3'b010: y <= {1'b0, x[7:1]};
			3'b011: y <= {x[6:0], 1'b0};
			3'b100: y <= {x[7], x[7:1]};
			3'b101: y <= {key, x[7:1]};
			3'b110: y <= {x[0], x[7:1]};
			3'b111: y <= {x[6:0], x[7]};
		endcase
	end
endmodule
	
