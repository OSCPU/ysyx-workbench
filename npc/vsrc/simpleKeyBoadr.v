
module SimpleStorage(
    input [7:0] in ,
    input clk ,  
    output reg [7:0]  storage[1:0]
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
    
    reg [7:0]  sto[1:0];
    SimpleStorage ss(in , clk , sto);

    assign ta = sto[1];
    assign tb = sto[0];



endmodule