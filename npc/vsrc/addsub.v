module addsub (
    input [31:0]a,
    input [31:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [31:0]result
);
    wire carry_in;
    wire [31:0] B_eff;
    assign carry_in = add_sub;
    assign B_eff = add_sub ? ~b+1 : b;


    assign {carry,result} = a + B_eff + {31'b0,carry_in};
    assign zero= (result==0&&carry==0);
    assign overflow = (a[31]==B_eff[31]&&a[31]!=result[31]);

endmodule


