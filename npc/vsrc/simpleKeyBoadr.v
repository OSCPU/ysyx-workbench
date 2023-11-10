
module SimpleStorage(
    input [7:0] in ,
    input clk ,  
    output [7:0] reg storage[1:0]
);

    always @(posedge clk) begin
        storage[1] <= storage[0];
        storage[0] <= in;
    end

endmodule

module top(

    input [7:0]in , 
    input clk , 
    // output [9:0]c

    output ta , 
    output tb
);
    
    wire [7:0] sto[1:0];
    SimpleStorage ss(in , sto);

    assign ta = sto[1];
    assign tb = sto[0];



endmodule