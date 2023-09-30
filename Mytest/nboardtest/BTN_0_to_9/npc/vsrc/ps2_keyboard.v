module ps2_keyboard(clk,resetn,ps2_clk,ps2_data,seg7,seg6,seg4,seg3,seg1,seg0);


//  ps2  BTN0---->9
    input clk,resetn,ps2_clk,ps2_data;
    output reg[7:0] seg7,seg6,seg4,seg3,seg1,seg0;

    reg [9:0] buffer;        // ps2_data bits
    reg [3:0] count;  // count ps2_data bits
    reg [2:0] ps2_clk_sync;

    reg[3:0] c;//buffer count
    reg[8:1] b;//buffer[8;1]

    buffer_count co1(c,seg7,seg6);	
    ASCII a1(b,seg4,seg3,seg1,seg0);

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (resetn == 0) begin // reset
            count <= 0;
        end
        else begin
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit
                    (ps2_data)       &&  // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    $display("receive %x", buffer[8:1]);
		    if(buffer[8:1]==8'hF0)
			c=c+4'b1;
		    else
	            b=buffer[8:1];
                end
                count <= 0;     // for next
              end else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
    end

endmodule

module buffer_count(
	input [3:0] ct,
	output reg [7:0] seg7,seg6
	);
	always @(*)
	begin
	case(ct[3:0])
	4'b0000: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b00000011; end	
	4'b0001: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b10011111; end	
	4'b0010: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b00100101; end	
	4'b0011: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b00001101; end	
	4'b0100: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b10011001; end	
	4'b0101: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b01001001; end	
	4'b0110: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b01000001; end	
	4'b0111: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b00011111; end	
	4'b1000: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b00000001; end	
	4'b1001: begin seg7[7:0]=8'b00000011; seg6[7:0]=8'b00011001; end	
	4'b1010: begin seg7[7:0]=8'b10011111; seg6[7:0]=8'b00000011; end	
	default : begin seg7[7:0]=8'b11111111; seg6[7:0]=8'b11111111; end
	endcase
	end
endmodule

module ASCII(
	input [8:1] buffer,
	output reg[7:0] seg4,seg3,seg1,seg0);
	always @(buffer[8:1])
	begin
	case(buffer[8:1])
	8'h45:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b00100101;                   seg1[7:0]=8'b00000011;seg0[7:0]=8'b00000011; end
	8'h16:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b00001101;                   seg1[7:0]=8'b00000011;seg0[7:0]=8'b10011111; end
	8'h1E:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b10011001;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b00100101; end 
	8'h26:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b01001001;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b00001101; end 
	8'h25:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b01000001;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b10011001; end 
	8'h2E:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b00011111;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b01001001; end
	8'h36:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b00000001;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b01000001; end 
	8'h3D:begin seg4[7:0]=8'b00001101; seg3[7:0]=8'b00011001;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b00011111; end 
	8'h3E:begin seg4[7:0]=8'b10011001; seg3[7:0]=8'b00000011;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b00000001; end 
	8'h46:begin seg4[7:0]=8'b10011001; seg3[7:0]=8'b10011111;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b00011001; end
	default : begin seg4[7:0]=8'b00000011; seg3[7:0]=8'b00000011;                    seg1[7:0]=8'b00000011;seg0[7:0]=8'b00000011; end
	endcase
	end
endmodule
