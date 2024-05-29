module addsub (
    input [31:0]a,
    input [31:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [31:0] result
);
    wire Cin;
    wire [31:0]B_eff;
    wire [32:0]mid ;
    assign Cin = add_sub;
    assign B_eff = b^{32{add_sub}}+{30'b0,Cin};
    assign mid = a + B_eff;


    assign {carry,result} = mid;
    assign zero= (result==0);
    assign overflow = (a[31]==B_eff[31]&&a[31]!=result[31]);

endmodule


