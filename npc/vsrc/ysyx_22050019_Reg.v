module ysyx_22050019_Reg #(DW = 32 ,RESET_VAL = 32'b0)(
    input               clk             ,
    input               rst_n           ,
    input   [DW-1:0]    din             ,
    output  [DW-1:0]    dout            ,
    input               wen             
);
reg [DW-1:0]  q;
always @(posedge clk) begin
    if (rst_n)
        q <= RESET_VAL ;
    else if ( wen )
        q <= din    ;   
end
assign  dout = q ;
endmodule

