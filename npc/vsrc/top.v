

module top(
    input [7:0]a ,
    input [7:0]b ,
    input [7:0]c ,
    input [7:0]d ,
    input [1:0]s ,
    output [7:0]o
);
    

    always @(*) begin

        case(s)
            0: o = a;
            1: o = b;
            2: o = c;
            3: o = d;
            default: o =0;
        endcase
    end

    // assign ledup = sw[0] & sw[1];
    // assign  ledr = { led , 7'b0000000 ,ledup};
/*
initial begin 
    $display("Hello World"); 
    //$finish; 
end
*/
endmodule
