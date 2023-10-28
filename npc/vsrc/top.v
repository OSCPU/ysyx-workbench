module top(
    input a , 
    input b,
    output c
);

    assign c = a ^ b;

initial begin 
    $display("Hello World"); 
    $finish; 
end
endmodule
