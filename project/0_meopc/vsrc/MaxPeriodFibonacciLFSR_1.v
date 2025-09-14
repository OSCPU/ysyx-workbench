module MaxPeriodFibonacciLFSR_1(
  input   clock,
  input   reset,
  output  io_out_0,
  output  io_out_1,
  output  io_out_2
);
  reg  state_0; // @[PRNG.scala 55:49]
  reg  state_1; // @[PRNG.scala 55:49]
  reg  state_2; // @[PRNG.scala 55:49]
  wire  _T = state_2 ^ state_1; // @[LFSR.scala 15:41]
  assign io_out_0 = state_0; // @[PRNG.scala 78:10]
  assign io_out_1 = state_1; // @[PRNG.scala 78:10]
  assign io_out_2 = state_2; // @[PRNG.scala 78:10]
  always @(posedge clock) begin
    state_0 <= reset | _T; // @[PRNG.scala 55:{49,49}]
    if (reset) begin // @[PRNG.scala 55:49]
      state_1 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_1 <= state_0;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_2 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_2 <= state_1;
    end
  end
endmodule