

module ShiftRegister(

    input in,
    input clk,
    input [2:0] opt,
    output [7:0] out

);
    always *(posedge clk)
        case(opt)
            3'b000:begin
                out<=0;
            end
            3'b001:begin
                out<= { in,out[7:1]};
            end
            3'b010:begin
                out<= {out[7] , out[7:1]};
            end
            3'b011:begin
                out<= {out[7] , out[5:0] , 1'b0};
            end
            3'b100:begin
                out<={0 , out[7:1]};
            end
            3'b101:begin
                out<= { in,out[7:1]};
            end
            3'b110:begin
                out<={out[0] , out[7:1]};
            end
            3'b111:begin
                out<={out[6,0] , out[7]};
            end
        endcase

endmodule

module top(
    input in,
    input clk,
    input [2:0] opt,
    output [7:0] out
);
    ShiftRegister sr(in ,clk ,opt , out);

endmodule