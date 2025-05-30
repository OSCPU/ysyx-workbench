module Adder (
    input  [31:0] in_a,
    input  [31:0] in_b,
    output [31:0] out_sum
);
    import "DPI-C" function int add(input int a, input int b);
    assign out_sum = add(in_a, in_b);

endmodule


module top(
    input  [31:0] in_a,
    input  [31:0] in_b,
    output [31:0] out_sum
);
    // 实例化 Adder 模块
    Adder adder_inst (
        .in_a(in_a),
        .in_b(in_b),
        .out_sum(out_sum)
    );
endmodule

