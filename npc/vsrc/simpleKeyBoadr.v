
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
    output reg [9:0] keyboards

);
    
    reg [7:0]  sto[1:0];
    SimpleStorage ss(in , clk , sto);

    parameter [7:0 ] keyMap [9:0]= {8'h45 , 8'h16 , 8'h1e ,8'h26,8'h25,8'h2e,8'h36,8'h3d,8'h3e,8'h46} ;

    genvar  i ;
    generate
        
        
            for(i = 0 ; i<= 9 ;i = i +1) begin
                always @(posedge clk)
                        keyboards[i] <= (sto[0] == keyMap[i])?
                                            (
                                                (sto[1] == 8'hF0)?
                                                0:1
                                            ):
                                            (keyboards[i]);
                // assign keyboards[i] = (sto[1] == 8'hF0 )?
                //                         (
                //                         (keyMap[i] == sto)  
                //                         ):
                //                         (

                //                         );
                

            end

    endgenerate

endmodule