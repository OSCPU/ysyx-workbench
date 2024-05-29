module top(
    input [31:0]a,
    input [31:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [31:0] result
);
addsub addsub1(
    .a(a),
    .b(b),
    .add_sub(add_sub),
    .carry(carry),
    .zero(zero),
    .overflow(overflow),
    .result(result)
);



endmodule
