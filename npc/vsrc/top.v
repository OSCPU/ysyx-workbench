module top(
    input[1:0] sw , 
    output ledr
);

    assign ledr = sw[0] & sw[1];

/*
initial begin 
    $display("Hello World"); 
    //$finish; 
end
*/
endmodule
