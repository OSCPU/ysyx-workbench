module addsub (
    input [3:0]a,
    input [3:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [3:0] result
);
    wire [3:0]B_eff;
    assign B_eff = b^{4{add_sub}}+{3'b0,add_sub};


    assign {carry,result} = a + B_eff;
    assign zero= ~(| result);
    assign overflow = (a[3]==B_eff[3]&&a[3]!=result[3]);

endmodule


