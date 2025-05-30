module ysyx_25020077_ALU(
  input  [31:0] io_in_a,
  input  [31:0] io_in_b,
  input  [2:0]  io_sw,
  output [31:0] io_out,
  output        io_carry,
  output        io_overflow
);
  wire [7:0] oneHot = 8'h1 << io_sw; // @[OneHot.scala 64:12]
  wire [32:0] addResult = $signed(io_in_a) + $signed(io_in_b); // @[module.scala 18:28]
  wire [32:0] subResult = $signed(io_in_a) - $signed(io_in_b); // @[module.scala 19:28]
  wire [32:0] _io_out_T_9 = $signed(io_in_a) + $signed(io_in_b); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_11 = $signed(io_in_a) - $signed(io_in_b); // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_13 = $signed(io_in_a) & $signed(io_in_b); // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_15 = $signed(io_in_a) | $signed(io_in_b); // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_17 = $signed(io_in_a) ^ $signed(io_in_b); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_24 = oneHot[0] ? $signed(_io_out_T_9) : $signed(33'sh0); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_25 = oneHot[1] ? $signed(_io_out_T_11) : $signed(33'sh0); // @[Mux.scala 27:73]
  wire [32:0] _io_out_WIRE_2 = {{1{_io_out_T_13[31]}},_io_out_T_13}; // @[Mux.scala 27:{73,73}]
  wire [32:0] _io_out_T_26 = oneHot[2] ? $signed(_io_out_WIRE_2) : $signed(33'sh0); // @[Mux.scala 27:73]
  wire [32:0] _io_out_WIRE_3 = {{1{_io_out_T_15[31]}},_io_out_T_15}; // @[Mux.scala 27:{73,73}]
  wire [32:0] _io_out_T_27 = oneHot[3] ? $signed(_io_out_WIRE_3) : $signed(33'sh0); // @[Mux.scala 27:73]
  wire [32:0] _io_out_WIRE_4 = {{1{_io_out_T_17[31]}},_io_out_T_17}; // @[Mux.scala 27:{73,73}]
  wire [32:0] _io_out_T_28 = oneHot[4] ? $signed(_io_out_WIRE_4) : $signed(33'sh0); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_33 = $signed(_io_out_T_24) | $signed(_io_out_T_25); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_35 = $signed(_io_out_T_33) | $signed(_io_out_T_26); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_37 = $signed(_io_out_T_35) | $signed(_io_out_T_27); // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_47 = $signed(_io_out_T_37) | $signed(_io_out_T_28); // @[Mux.scala 27:73]
  wire  _io_overflow_T_7 = io_in_a[31] == io_in_b[31] & io_in_a[31] != addResult[31]; // @[module.scala 50:49]
  wire  _io_overflow_T_15 = io_in_a[31] != io_in_b[31] & io_in_a[31] != subResult[31]; // @[module.scala 51:49]
  assign io_out = _io_out_T_47[31:0]; // @[module.scala 26:10]
  assign io_carry = oneHot[0] & addResult[32] | oneHot[1] & subResult[32]; // @[Mux.scala 27:73]
  assign io_overflow = oneHot[0] & _io_overflow_T_7 | oneHot[1] & _io_overflow_T_15; // @[Mux.scala 27:73]
endmodule
