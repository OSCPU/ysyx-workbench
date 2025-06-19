module ysyx_25030077_ALU(
  input  [31:0] io_in_a,
  input  [31:0] io_in_b,
  input  [3:0]  io_sw,
  output [31:0] io_out,
  output        io_carry,
  output        io_overflow
);
  import "DPI-C" function bit[31:0] csr_read(input bit[31:0] rs1, input bit[31:0] imm, input bit[3:0] sw);
  wire [31:0] csr_data = csr_read(io_in_a, io_in_b, io_sw);

  wire [15:0] oneHot = 16'h1 << io_sw; // @[OneHot.scala 64:12]
  wire [32:0] addResult = io_in_a + io_in_b; // @[module.scala 17:28]
  wire [32:0] subResult = io_in_a - io_in_b; // @[module.scala 18:28]
  wire  sltiuResult = io_in_a < io_in_b; // @[module.scala 19:30]
  wire  sltResult = $signed(io_in_a) < $signed(io_in_b); // @[module.scala 20:35]
  wire [31:0] andResult = io_in_a & io_in_b; // @[module.scala 21:28]
  wire [31:0] orResult = io_in_a | io_in_b; // @[module.scala 22:28]
  wire [31:0] xorResult = io_in_a ^ io_in_b; // @[module.scala 23:28]
  wire [31:0] sraiResult = $signed(io_in_a) >>> io_in_b; // @[module.scala 24:48]
  wire [31:0] srliResult = io_in_a >> io_in_b; // @[module.scala 25:29]
  wire [62:0] _GEN_8 = {{31'd0}, io_in_a}; // @[module.scala 26:29]
  wire [62:0] sllResult = _GEN_8 << io_in_b[4:0]; // @[module.scala 26:29]
  wire [32:0] _io_out_T_16 = oneHot[0] ? addResult : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_17 = oneHot[1] ? subResult : 33'h0; // @[Mux.scala 27:73]
  wire  _io_out_T_18 = oneHot[2] & sltiuResult; // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_19 = oneHot[3] ? orResult : 32'h0; // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_20 = oneHot[4] ? xorResult : 32'h0; // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_21 = oneHot[5] ? sraiResult : 32'h0; // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_22 = oneHot[6] ? andResult : 32'h0; // @[Mux.scala 27:73]
  wire [62:0] _io_out_T_24 = oneHot[8] ? sllResult : 63'h0; // @[Mux.scala 27:73]
  wire [31:0] _io_out_T_25 = oneHot[9] ? srliResult : 32'h0; // @[Mux.scala 27:73]
  wire  _io_out_T_26 = oneHot[10] & sltResult; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_32 = _io_out_T_16 | _io_out_T_17; // @[Mux.scala 27:73]
  wire [32:0] _GEN_0 = {{32'd0}, _io_out_T_18}; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_33 = _io_out_T_32 | _GEN_0; // @[Mux.scala 27:73]
  wire [32:0] _GEN_1 = {{1'd0}, _io_out_T_19}; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_34 = _io_out_T_33 | _GEN_1; // @[Mux.scala 27:73]
  wire [32:0] _GEN_2 = {{1'd0}, _io_out_T_20}; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_35 = _io_out_T_34 | _GEN_2; // @[Mux.scala 27:73]
  wire [32:0] _GEN_3 = {{1'd0}, _io_out_T_21}; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_36 = _io_out_T_35 | _GEN_3; // @[Mux.scala 27:73]
  wire [32:0] _GEN_4 = {{1'd0}, _io_out_T_22}; // @[Mux.scala 27:73]
  wire [32:0] _io_out_T_37 = _io_out_T_36 | _GEN_4; // @[Mux.scala 27:73]
  wire [62:0] _GEN_5 = {{30'd0}, _io_out_T_37}; // @[Mux.scala 27:73]
  wire [62:0] _io_out_T_39 = _GEN_5 | _io_out_T_24; // @[Mux.scala 27:73]
  wire [62:0] _GEN_6 = {{31'd0}, _io_out_T_25}; // @[Mux.scala 27:73]
  wire [62:0] _io_out_T_40 = _io_out_T_39 | _GEN_6; // @[Mux.scala 27:73]
  wire [62:0] _GEN_7 = {{62'd0}, _io_out_T_26}; // @[Mux.scala 27:73]
  wire [62:0] _io_out_T_41 = _io_out_T_40 | _GEN_7; // @[Mux.scala 27:73]
  wire  _io_overflow_T_7 = io_in_a[31] == io_in_b[31] & io_in_a[31] != addResult[31]; // @[module.scala 70:49]
  wire  _io_overflow_T_15 = io_in_a[31] != io_in_b[31] & io_in_a[31] != subResult[31]; // @[module.scala 71:49]
  assign io_out = (oneHot[11] || oneHot[12]) ? csr_data :_io_out_T_41[31:0]; // @[module.scala 30:10]
  assign io_carry = oneHot[0] & addResult[32] | oneHot[1] & subResult[32]; // @[Mux.scala 27:73]
  assign io_overflow = oneHot[0] & _io_overflow_T_7 | oneHot[1] & _io_overflow_T_15; // @[Mux.scala 27:73]
endmodule
