module top(
    input [31:0]a,
    input [31:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [31:0] result,
    output [31:0] B_eff
);
addsub addsub1(
    .a(a),
    .b(b),
    .add_sub(add_sub),
    .carry(carry),
    .zero(zero),
    .overflow(overflow),
    .result(result),
    .B_eff(B_eff)
);



endmodule
