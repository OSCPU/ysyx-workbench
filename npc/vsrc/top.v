module top(
    input[1:0] sw , 
    output reg [15:0]ledr
);
    
    reg flag;
    reg[7:0] led;
    reg ledup;
    
    // wire[]led_l 

    always @(*) begin
        if (flag == 1'b0) begin
            led = 8'b1;   
            flag = 1;
        end
        else begin
            led = {ledr[14:8] , ledr[15]};
        end
    end

    assign ledup = sw[0] & sw[1];
    assign  ledr = {led , 7'b0000000 ,ledup};
/*
initial begin 
    $display("Hello World"); 
    //$finish; 
end
*/
endmodule
