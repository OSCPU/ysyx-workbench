module clint(
  input         clock,
  input         reset,
  output        io_ar_ready,
  input         io_ar_valid,
  input  [31:0] io_raddr,
  input  [2:0]  io_r_mask,
  input         io_r_valid,
  output [31:0] io_mem_data,
  output [2:0]  io_cnt,
  input         io_r__ready,
  output        io_r__valid
);
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
  wire  delayCnt_prng_clock; // @[PRNG.scala 91:22]
  wire  delayCnt_prng_reset; // @[PRNG.scala 91:22]
  wire  delayCnt_prng_io_out_0; // @[PRNG.scala 91:22]
  wire  delayCnt_prng_io_out_1; // @[PRNG.scala 91:22]
  wire  delayCnt_prng_io_out_2; // @[PRNG.scala 91:22]
  reg [63:0] mem_data_Reg; // @[clint.scala 15:29]
  reg  validReg; // @[clint.scala 16:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[clint.scala 17:28]
  reg [2:0] delayCnt; // @[clint.scala 19:25]
  wire  _startDelay_T = io_ar_valid & canAccept; // @[clint.scala 21:29]
  wire  startDelay = io_ar_valid & canAccept & io_r_valid; // @[clint.scala 21:42]
  wire [2:0] _delayCnt_T = {delayCnt_prng_io_out_2,delayCnt_prng_io_out_1,delayCnt_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [2:0] _delayCnt_T_3 = delayCnt - 3'h1; // @[clint.scala 25:46]
  wire  _io_r_valid_T = delayCnt == 3'h0; // @[clint.scala 28:39]
  wire  _validReg_T_3 = io_r__ready & _io_r_valid_T ? 1'h0 : validReg; // @[clint.scala 32:18]
//   wire [63:0] _GEN_0 = {{61'd0}, io_r_mask}; // @[clint.scala 34:62]
  wire [63:0] _mem_data_Reg_T_2 = mem_data_Reg + 64'h700; // @[clint.scala 34:62]
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
  MaxPeriodFibonacciLFSR_1 delayCnt_prng ( // @[PRNG.scala 91:22]
    .clock(delayCnt_prng_clock),
    .reset(delayCnt_prng_reset),
    .io_out_0(delayCnt_prng_io_out_0),
    .io_out_1(delayCnt_prng_io_out_1),
    .io_out_2(delayCnt_prng_io_out_2)
  );
  assign io_ar_ready = _canAccept_T[0]; // @[clint.scala 17:28]
  assign io_mem_data = io_raddr == 32'ha0000048 ? mem_data_Reg[31:0] : mem_data_Reg[63:32]; // @[clint.scala 30:21]
  assign io_cnt = delayCnt; // @[clint.scala 22:10]
  assign io_r__valid = validReg & delayCnt == 3'h0; // @[clint.scala 28:26]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  assign delayCnt_prng_clock = clock;
  assign delayCnt_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[clint.scala 15:29]
      mem_data_Reg <= 64'h0; // @[clint.scala 15:29]
    end else if (_startDelay_T) begin // @[clint.scala 34:22]
      mem_data_Reg <= _mem_data_Reg_T_2;
    end
    if (reset) begin // @[clint.scala 16:25]
      validReg <= 1'h0; // @[clint.scala 16:25]
    end else begin
      validReg <= _startDelay_T | _validReg_T_3; // @[clint.scala 31:12]
    end
    if (reset) begin // @[clint.scala 19:25]
      delayCnt <= 3'h0; // @[clint.scala 19:25]
    end else if (startDelay) begin // @[clint.scala 24:18]
      delayCnt <= _delayCnt_T;
    end else if (delayCnt != 3'h0) begin // @[clint.scala 25:18]
      delayCnt <= _delayCnt_T_3;
    end else begin
      delayCnt <= 3'h0;
    end
  end
endmodule