module ysyx_25030077_MEM(
  input         clock,
  input         reset,
  output        io_ar_ready,
  input         io_ar_valid,
  output        io_aw_ready,
  input         io_aw_valid,
  output        io_w_ready,
  input         io_w_valid,
  input  [31:0] io_waddr,
  input  [31:0] io_raddr,
  input  [31:0] io_wdata,
  input  [2:0]  io_r_mask,
  input  [2:0]  io_w_mask,
  input         io_r_valid,
  output [31:0] io_mem_data,
  output [2:0]  io_cnt,
  input         io_r__ready,
  output        io_r__valid,
  input         io_b_ready,
  output        io_b_valid
);
  wire  [31:0] io_r_mask_ext = {29'b0, io_r_mask};
  wire  [31:0] io_w_mask_ext = {29'b0, io_w_mask};
  // import "DPI-C" function bit[31:0] mem_data_read(input bit[31:0] mask, input bit[31:0] addr_in);
  // import "DPI-C" function bit[31:0] addr_read(input bit[31:0] addr_in);
   
  // export "DPI-C" function wmask_read;
  // function int wmask_read();
  //   return {io_w_mask_ext};

  // endfunction
  // wire  [31:0] valid = {31'b0, io_ar_valid & canAccept};
  // export "DPI-C" function valid_read;
  // function int valid_read();
  //   return {valid};
  // endfunction

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
  reg [31:0] mem_data_Reg; // @[mem.scala 21:29]
  reg  validReg; // @[mem.scala 22:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[mem.scala 23:28]
  wire [31:0] _read_data_T = io_rs1 & io_rs2; // @[mem.scala 20:27]
  wire [31:0] _read_data_T_1 = {29'h0,io_r_mask}; // @[Cat.scala 31:58]
  wire [31:0] _read_data_T_2 = io_imm ^ _read_data_T_1; // @[mem.scala 20:47]
  wire [31:0] read_data = _read_data_T | _read_data_T_2; // @[mem.scala 20:37]
  // wire [31:0] read_data = io_r_mask == 3'h6 ? addr_read(io_raddr) : mem_data_read({29'h0,io_r_mask},  io_raddr);
  reg [2:0] delayCnt; // @[mem.scala 26:25]
  wire  _startDelay_T = io_ar_valid & canAccept; // @[mem.scala 28:29]
  wire  startDelay = io_ar_valid & canAccept & io_r_valid; // @[mem.scala 28:42]
  wire [2:0] _delayCnt_T = {delayCnt_prng_io_out_2,delayCnt_prng_io_out_1,delayCnt_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [2:0] _delayCnt_T_3 = delayCnt - 3'h1; // @[mem.scala 32:46]
  wire  _io_r_valid_T = delayCnt == 3'h0; // @[mem.scala 35:39]
  wire  _validReg_T_4 = io_b_ready & io_r__ready & _io_r_valid_T ? 1'h0 : validReg; // @[mem.scala 41:18]
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
  assign io_ar_ready = _canAccept_T[0]; // @[mem.scala 23:28]
  assign io_aw_ready = _canAccept_T[0]; // @[mem.scala 23:28]
  assign io_w_ready = _canAccept_T[0]; // @[mem.scala 23:28]
  assign io_mem_data = mem_data_Reg; // @[mem.scala 38:15]
  assign io_cnt = delayCnt; // @[mem.scala 30:10]
  assign io_r__valid = validReg & delayCnt == 3'h0; // @[mem.scala 35:26]
  assign io_b_valid = validReg & _io_r_valid_T; // @[mem.scala 36:26]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  assign delayCnt_prng_clock = clock;
  assign delayCnt_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[mem.scala 21:29]
      mem_data_Reg <= 32'h0; // @[mem.scala 21:29]
    end else if (_startDelay_T) begin // @[mem.scala 43:22]
      mem_data_Reg <= read_data;
    end
    if (reset) begin // @[mem.scala 22:25]
      validReg <= 1'h0; // @[mem.scala 22:25]
    end else begin
      validReg <= _startDelay_T | _validReg_T_4; // @[mem.scala 40:12]
    end
    if (reset) begin // @[mem.scala 26:25]
      delayCnt <= 3'h0; // @[mem.scala 26:25]
    end else if (startDelay) begin // @[mem.scala 31:18]
      delayCnt <= _delayCnt_T;
    end else if (delayCnt != 3'h0) begin // @[mem.scala 32:18]
      delayCnt <= _delayCnt_T_3;
    end else begin
      delayCnt <= 3'h0;
    end
  end  
endmodule