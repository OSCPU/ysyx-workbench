

module top(

    input [len:0] seed , 
    input  opt,
    input clk , 
    output [len:0] out
);
    parameter len = 7;
    always @(posedge clk )
        if(opt == 1'b0)begin
            for(integer  i=0; i<=len ; i= i + 1)begin
                
                out[i] <= seed[i] ^ 1 ;
            end
        end
        else begin

            out <= {out[len-1:0] , out[len] ^ out[len-1]};
        end
    
endmodule