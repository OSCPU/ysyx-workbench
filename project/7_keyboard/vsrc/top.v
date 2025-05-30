module ps2_keyboard(clk,rst,ps2_clk,ps2_data,data,overflow,close,press_count);
	input clk,rst,ps2_clk,ps2_data;
	output [7:0] data;
	output reg overflow;     // fifo overflow
	output reg [1:0]close;//决定低四位数码管是亮还是灭
	output reg [7:0]press_count;
	// internal signal, for test
	reg [9:0] buffer;        // ps2_data bits
	reg [7:0] fifo[7:0];     // data fifo
	reg [2:0] w_ptr,r_ptr;   // fifo write and read pointers
	reg [3:0] count;  // count ps2_data bits
	// detect falling edge of ps2_clk
	reg [2:0] ps2_clk_sync;
	reg nextdata_n;
	reg ready;

	always @(posedge clk) begin
		ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
	end
	
	wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1]; //检测PS2时钟信号下降沿,即按键按下或松开
	
	always @(posedge clk) begin
		if (rst == 0) begin // reset
			count <= 0; w_ptr <= 0; r_ptr <= 0; overflow <= 0; ready<= 0; nextdata_n <= 0;press_count <= 0;
		end
		else begin
			if (ready) begin // read to output next data
				if(nextdata_n == 1'b1) //read next data
				begin
	 				nextdata_n <= 1'b0;
				end
				else if(nextdata_n == 1'b0) //read next data
				begin
	 				r_ptr <= r_ptr + 3'b1;
					if(w_ptr==(r_ptr+1'b1)) begin//empty
						ready <= 1'b0;
						w_ptr <= 0; r_ptr <= 0;
						nextdata_n <= 1'b1;
					end
				end
			end
			if (sampling) begin
				 if (count == 4'd10) begin
					if ((buffer[0] == 0) &&  // start bit
					    (ps2_data)       &&  // stop bit
					    (^buffer[9:1])) begin      // odd  parity
						fifo[w_ptr] <= buffer[8:1];  // kbd scan code
						w_ptr <= w_ptr+3'b1;
						ready <= 1'b1;
						overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
						if(buffer[8:1] == 8'b11110000) begin
							close <= 2'b11;
							press_count <= press_count + 1;
						end
						else close <= {{close[0]}, 1'b0};
						$display("receive %x %b %x", buffer[8:1], close, press_count);
					end
					count <= 0;     // for next
				end 
				else begin
					buffer[count] <= ps2_data;  // store ps2_data
					count <= count + 3'b1;
				end
			end
		end
	end
	assign data = fifo[r_ptr]; //always set output data
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
				4'b1110 : y <= 8'b10011110;
				4'b1111 : y <= 8'b10001110;
				4'b1000 : y <= 8'b11111110;
			endcase
		end

	end
	assign seg = ~y;
endmodule

module rom (outaddr, dout);
	input [7:0] outaddr;
	output reg [7:0] dout;
	reg [7:0]rom[255:0];
	initial
		$readmemh("/home/meowth/ysyx/ysyx-workbench/project/7_keyboard/ASCLL.txt", rom, 0, 255);
	begin
	end
assign  dout = rom[outaddr];
endmodule

module top(clk,rst,ps2_clk,ps2_data,overflow,seg_1,seg_2,seg_3,seg_4,seg_5,seg_6,seg_7,seg_8);
	input clk,rst,ps2_clk,ps2_data;
	output reg [7:0]seg_1;
	output reg [7:0]seg_2;
	output reg [7:0]seg_3;
	output reg [7:0]seg_4;
	output reg [7:0]seg_5;
	output reg [7:0]seg_6;
	output reg [7:0]seg_7;
	output reg [7:0]seg_8;
	output overflow;
	wire [1:0]close;
	wire [7:0]y_1;
	wire [7:0]press_count;
	ps2_keyboard i1(.clk(clk), .rst(rst), .ps2_clk(ps2_clk), .ps2_data(ps2_data), 
	.data(y_1), .overflow(overflow), .close(close), .press_count(press_count));
	wire [3:0]data_1;
	wire [3:0]data_2;
	wire [3:0]data_3;
	wire [3:0]data_4;
	wire [3:0]data_5;
	wire [3:0]data_6;
	wire [7:0]display_1;
	wire [7:0]display_2;
	wire [7:0]display_5;
	wire [7:0]display_6;
	wire [7:0]dout;
	assign data_1 = y_1[7:4];
	assign data_2 = y_1[3:0];
	assign data_3 = press_count[7:4];
	assign data_4 = press_count[3:0];
	
	
	smg i2(.x(data_1), .seg(display_1)); //键盘码字，扫描码
	smg i3(.x(data_2), .seg(display_2));  //键盘码字
	smg i4(.x(data_3), .seg(seg_3));  //按键次数
	smg i5(.x(data_4), .seg(seg_4));  //按键次数
	rom i6(.outaddr(y_1), .dout(dout)); //根据键盘码字找ascii
	
	assign data_5 = dout[7:4];
	assign data_6 = dout[3:0];
	smg i7(.x(data_5), .seg(display_5));
	smg i8(.x(data_6), .seg(display_6));

	
	always@(*) begin
		if (rst == 0) begin // reset
			seg_1 = 8'b11111111;
			seg_2 = 8'b11111111;
			seg_5 = 8'b11111111;
			seg_6 = 8'b11111111;
		end
		else
		begin
			if(close[1]) begin //由close[1]决定数码管的亮与灭
				seg_1 = 8'b11111111;
				seg_2 = 8'b11111111;
				seg_5 = 8'b11111111;
				seg_6 = 8'b11111111;
			end
			
			else begin
				seg_1 = display_1;
				seg_2 = display_2;
				seg_5 = display_5;
				seg_6 = display_6;
			end
		end
	end	
	assign seg_7 = 8'b11111111;
	assign seg_8 = 8'b11111111;
endmodule

