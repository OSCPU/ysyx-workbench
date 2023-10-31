module top(
    input[1:0] sw ,
    input clk ,  
    input rst , 
    output [15:0]ledr
);
    
    reg [31:0] count;
    reg ledup;
    reg [7:0] led;
    // wire[]led_l 

    always @(posedge clk) begin
        if (rst == 1'b1) begin
            led <= 1;  
            count <= 0 ;
        end
        else begin
            
            if (count == 500000 )led <= {led[6:0] , led[7]};
            count <= (count > 500000)?0:count +1;
        end
    end

    assign ledup = sw[0] & sw[1];
    assign  ledr = { led , 7'b0000000 ,ledup};
/*
initial begin 
    $display("Hello World"); 
    //$finish; 
end
*/
endmodule
