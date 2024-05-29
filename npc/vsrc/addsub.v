module addsub (
    input [31:0]a,
    input [31:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [31:0] result
);
    wire [31:0]B_eff;
    assign B_eff = b^{32{add_sub}}+{30'b0,add_sub};


    assign {carry,result} = a + B_eff;
    assign zero= ~(| result);
    assign overflow = (a[31]==B_eff[31]&&a[31]!=result[31]);

endmodule


