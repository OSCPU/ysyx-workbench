
module SimpleStorage(
    input [7:0] in , 
    output [7:0] storage[1:0]
);

    assign storage[1] = storage[0];
    assign storage[0] = in;

endmodule

module top(

    input [7:0]in , 
    // output [9:0]c

    output ta , 
    output tb
);
    
    wire [7:0] sto[1:0];
    SimpleStorage ss(in , sto);

    assign ta = sto[1];
    assign tb = stop[0];



endmodule