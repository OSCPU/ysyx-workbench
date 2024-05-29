module top(
    input [3:0]a,
    input [3:0]b,
    input add_sub,
    output carry,
    output zero,
    output overflow,
    output [3:0] result
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
