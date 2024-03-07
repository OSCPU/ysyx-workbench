module light (
    input clk,
    input rst,
    output reg [15:0] led
);
    reg [5:0] cnt;
    always @(posedge clk) begin
        if(rst) begin
            led <= 1;
            cnt <= 0;
        end
        else begin
            if (cnt == 0) led <= {led[14:0], led[15]};
            cnt <= (cnt + 1) & 1;
        end
    end
    
endmodule
