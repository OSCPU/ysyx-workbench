module top(
    input[1:0] sw , 
    output [15:0]ledr
);

    reg flag;
    assign ledr[0] = sw[0] & sw[1];
    
    always @(*) begin
        if (flag == 1'b0) begin
            ledr[8] = 1;   
        end
        else begin
            ledr[15:8] = {ledr[14:8] , ledr[15]};
        end
    end
    

/*
initial begin 
    $display("Hello World"); 
    //$finish; 
end
*/
endmodule
