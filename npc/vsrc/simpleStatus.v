

module SimpleStatustop(

    input in , 
    input clk , 
    output c
);
    reg [31:0] cnt_zero , cnt_one;

    always @(posedge clk)
        if(in == 1'b1) begin
            cnt_one <= cnt_one + 1;
            cnt_zero <= 0 ;
        end
        else
            begin
            cnt_zero <= cnt_zero +1;
            cnt_one <=0;
            end
    assign c = (cnt_one >=4 || cnt_zero >=4) ? 1:0;

endmodule