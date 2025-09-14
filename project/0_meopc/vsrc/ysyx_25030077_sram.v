module ysyx_25030077_SRAM(
  input         clock,
  input         reset,
  output        io_ar_ready,
  input         io_ar_valid,
  input  [31:0] io_ar_bits_addr,
  input         io_ar1_ready,
  output        io_ar1_valid,
  input         io_aw_ready,
  output        io_aw_valid,
  input         io_w_ready,
  output        io_w_valid,
  output [31:0] io_r_data,

  input         io_b_ready,
  output        io_b_valid,
  input         io_aw1_valid,
  output        io_aw1_ready,
  input         io_w1_valid,
  output        io_w1_ready
);
  assign io_aw1_ready = 1'b0;
  assign io_w1_ready = 1'b0;
  assign io_b_valid = 1'b0;
  
  import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
  wire  canAccept_prng_clock; // @[PRNG.scala 91:22]
  wire  canAccept_prng_reset; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_0; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_1; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_2; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_3; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_4; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_5; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_6; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_7; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_8; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_9; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_10; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_11; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_12; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_13; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_14; // @[PRNG.scala 91:22]
  wire  canAccept_prng_io_out_15; // @[PRNG.scala 91:22]
  reg [31:0] instReg; // @[SRAM.scala 16:24]
  reg  validReg; // @[SRAM.scala 17:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[SRAM.scala 19:27]
  wire  _validReg_T = io_ar_valid & canAccept; // @[SRAM.scala 27:31]
  wire  _validReg_T_3 = io_ar1_ready & io_aw_ready & io_w_ready ? 1'h0 : validReg; // @[SRAM.scala 28:18]
  MaxPeriodFibonacciLFSR canAccept_prng ( // @[PRNG.scala 91:22]
    .clock(canAccept_prng_clock),
    .reset(canAccept_prng_reset),
    .io_out_0(canAccept_prng_io_out_0),
    .io_out_1(canAccept_prng_io_out_1),
    .io_out_2(canAccept_prng_io_out_2),
    .io_out_3(canAccept_prng_io_out_3),
    .io_out_4(canAccept_prng_io_out_4),
    .io_out_5(canAccept_prng_io_out_5),
    .io_out_6(canAccept_prng_io_out_6),
    .io_out_7(canAccept_prng_io_out_7),
    .io_out_8(canAccept_prng_io_out_8),
    .io_out_9(canAccept_prng_io_out_9),
    .io_out_10(canAccept_prng_io_out_10),
    .io_out_11(canAccept_prng_io_out_11),
    .io_out_12(canAccept_prng_io_out_12),
    .io_out_13(canAccept_prng_io_out_13),
    .io_out_14(canAccept_prng_io_out_14),
    .io_out_15(canAccept_prng_io_out_15)
  );
  assign io_ar_ready = _canAccept_T[0]; // @[SRAM.scala 19:27]
  assign io_ar1_valid = validReg; // @[SRAM.scala 21:17]
  assign io_aw_valid = validReg; // @[SRAM.scala 23:15]
  assign io_w_valid = validReg; // @[SRAM.scala 22:15]
  assign io_r_data = instReg; // @[SRAM.scala 25:13]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[SRAM.scala 16:24]
      instReg <= 32'h413; // @[SRAM.scala 16:24]
    end else if (_validReg_T) begin // @[SRAM.scala 31:17]
      instReg <= addr_read(io_ar_bits_addr);
    end
    validReg <= reset | (io_ar_valid & canAccept | _validReg_T_3); // @[SRAM.scala 17:{25,25} 27:12]
  end
endmodule
