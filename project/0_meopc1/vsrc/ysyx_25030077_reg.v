module ysyx_25030077_reg(
  input         clock,
  input         reset,
  output        io_mem_Req_ready,
  input         io_mem_Req_valid,
  output        io_b_ready,
  input         io_b_valid,
  input  [31:0] io_pc_next,
  input  [4:0]  io_waddr_rd,
  input  [31:0] io_wdata_rd,
  input  [4:0]  io_raddr_rs1,
  output [31:0] io_rdata_rs1,
  input  [4:0]  io_raddr_rs2,
  output [31:0] io_rdata_rs2,
  input         io_ifu_Req_ready,
  output        io_ifu_Req_valid,
  output [31:0] io_ifu_Req_bits_addr
);
  // export "DPI-C" function reg_read_addr;
  // function int reg_read_addr();
  //   return {27'b0, io_waddr_rd};
  // endfunction

  // export "DPI-C" function reg_read_data;
  // function int reg_read_data();
  //   return {io_wdata_rd};
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
  reg [31:0] regs_0; // @[gpr.scala 19:21]
  reg [31:0] regs_1; // @[gpr.scala 19:21]
  reg [31:0] regs_2; // @[gpr.scala 19:21]
  reg [31:0] regs_3; // @[gpr.scala 19:21]
  reg [31:0] regs_4; // @[gpr.scala 19:21]
  reg [31:0] regs_5; // @[gpr.scala 19:21]
  reg [31:0] regs_6; // @[gpr.scala 19:21]
  reg [31:0] regs_7; // @[gpr.scala 19:21]
  reg [31:0] regs_8; // @[gpr.scala 19:21]
  reg [31:0] regs_9; // @[gpr.scala 19:21]
  reg [31:0] regs_10; // @[gpr.scala 19:21]
  reg [31:0] regs_11; // @[gpr.scala 19:21]
  reg [31:0] regs_12; // @[gpr.scala 19:21]
  reg [31:0] regs_13; // @[gpr.scala 19:21]
  reg [31:0] regs_14; // @[gpr.scala 19:21]
  reg [31:0] regs_15; // @[gpr.scala 19:21]
  reg [31:0] regs_16; // @[gpr.scala 19:21]
  reg [31:0] regs_17; // @[gpr.scala 19:21]
  reg [31:0] regs_18; // @[gpr.scala 19:21]
  reg [31:0] regs_19; // @[gpr.scala 19:21]
  reg [31:0] regs_20; // @[gpr.scala 19:21]
  reg [31:0] regs_21; // @[gpr.scala 19:21]
  reg [31:0] regs_22; // @[gpr.scala 19:21]
  reg [31:0] regs_23; // @[gpr.scala 19:21]
  reg [31:0] regs_24; // @[gpr.scala 19:21]
  reg [31:0] regs_25; // @[gpr.scala 19:21]
  reg [31:0] regs_26; // @[gpr.scala 19:21]
  reg [31:0] regs_27; // @[gpr.scala 19:21]
  reg [31:0] regs_28; // @[gpr.scala 19:21]
  reg [31:0] regs_29; // @[gpr.scala 19:21]
  reg [31:0] regs_30; // @[gpr.scala 19:21]
  reg [31:0] regs_31; // @[gpr.scala 19:21]
  reg  validReg; // @[gpr.scala 20:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[gpr.scala 21:27]
  reg [31:0] pc_next_reg; // @[gpr.scala 22:28]
  wire  _validReg_T_2 = io_ifu_Req_ready ? 1'h0 : validReg; // @[gpr.scala 26:20]
  wire [31:0] _GEN_1 = 5'h1 == io_raddr_rs1 ? regs_1 : regs_0; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_2 = 5'h2 == io_raddr_rs1 ? regs_2 : _GEN_1; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_3 = 5'h3 == io_raddr_rs1 ? regs_3 : _GEN_2; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_4 = 5'h4 == io_raddr_rs1 ? regs_4 : _GEN_3; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_5 = 5'h5 == io_raddr_rs1 ? regs_5 : _GEN_4; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_6 = 5'h6 == io_raddr_rs1 ? regs_6 : _GEN_5; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_7 = 5'h7 == io_raddr_rs1 ? regs_7 : _GEN_6; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_8 = 5'h8 == io_raddr_rs1 ? regs_8 : _GEN_7; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_9 = 5'h9 == io_raddr_rs1 ? regs_9 : _GEN_8; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_10 = 5'ha == io_raddr_rs1 ? regs_10 : _GEN_9; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_11 = 5'hb == io_raddr_rs1 ? regs_11 : _GEN_10; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_12 = 5'hc == io_raddr_rs1 ? regs_12 : _GEN_11; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_13 = 5'hd == io_raddr_rs1 ? regs_13 : _GEN_12; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_14 = 5'he == io_raddr_rs1 ? regs_14 : _GEN_13; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_15 = 5'hf == io_raddr_rs1 ? regs_15 : _GEN_14; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_16 = 5'h10 == io_raddr_rs1 ? regs_16 : _GEN_15; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_17 = 5'h11 == io_raddr_rs1 ? regs_17 : _GEN_16; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_18 = 5'h12 == io_raddr_rs1 ? regs_18 : _GEN_17; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_19 = 5'h13 == io_raddr_rs1 ? regs_19 : _GEN_18; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_20 = 5'h14 == io_raddr_rs1 ? regs_20 : _GEN_19; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_21 = 5'h15 == io_raddr_rs1 ? regs_21 : _GEN_20; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_22 = 5'h16 == io_raddr_rs1 ? regs_22 : _GEN_21; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_23 = 5'h17 == io_raddr_rs1 ? regs_23 : _GEN_22; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_24 = 5'h18 == io_raddr_rs1 ? regs_24 : _GEN_23; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_25 = 5'h19 == io_raddr_rs1 ? regs_25 : _GEN_24; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_26 = 5'h1a == io_raddr_rs1 ? regs_26 : _GEN_25; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_27 = 5'h1b == io_raddr_rs1 ? regs_27 : _GEN_26; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_28 = 5'h1c == io_raddr_rs1 ? regs_28 : _GEN_27; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_29 = 5'h1d == io_raddr_rs1 ? regs_29 : _GEN_28; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_30 = 5'h1e == io_raddr_rs1 ? regs_30 : _GEN_29; // @[gpr.scala 29:{16,16}]
  wire [31:0] _GEN_33 = 5'h1 == io_raddr_rs2 ? regs_1 : regs_0; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_34 = 5'h2 == io_raddr_rs2 ? regs_2 : _GEN_33; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_35 = 5'h3 == io_raddr_rs2 ? regs_3 : _GEN_34; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_36 = 5'h4 == io_raddr_rs2 ? regs_4 : _GEN_35; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_37 = 5'h5 == io_raddr_rs2 ? regs_5 : _GEN_36; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_38 = 5'h6 == io_raddr_rs2 ? regs_6 : _GEN_37; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_39 = 5'h7 == io_raddr_rs2 ? regs_7 : _GEN_38; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_40 = 5'h8 == io_raddr_rs2 ? regs_8 : _GEN_39; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_41 = 5'h9 == io_raddr_rs2 ? regs_9 : _GEN_40; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_42 = 5'ha == io_raddr_rs2 ? regs_10 : _GEN_41; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_43 = 5'hb == io_raddr_rs2 ? regs_11 : _GEN_42; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_44 = 5'hc == io_raddr_rs2 ? regs_12 : _GEN_43; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_45 = 5'hd == io_raddr_rs2 ? regs_13 : _GEN_44; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_46 = 5'he == io_raddr_rs2 ? regs_14 : _GEN_45; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_47 = 5'hf == io_raddr_rs2 ? regs_15 : _GEN_46; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_48 = 5'h10 == io_raddr_rs2 ? regs_16 : _GEN_47; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_49 = 5'h11 == io_raddr_rs2 ? regs_17 : _GEN_48; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_50 = 5'h12 == io_raddr_rs2 ? regs_18 : _GEN_49; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_51 = 5'h13 == io_raddr_rs2 ? regs_19 : _GEN_50; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_52 = 5'h14 == io_raddr_rs2 ? regs_20 : _GEN_51; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_53 = 5'h15 == io_raddr_rs2 ? regs_21 : _GEN_52; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_54 = 5'h16 == io_raddr_rs2 ? regs_22 : _GEN_53; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_55 = 5'h17 == io_raddr_rs2 ? regs_23 : _GEN_54; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_56 = 5'h18 == io_raddr_rs2 ? regs_24 : _GEN_55; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_57 = 5'h19 == io_raddr_rs2 ? regs_25 : _GEN_56; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_58 = 5'h1a == io_raddr_rs2 ? regs_26 : _GEN_57; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_59 = 5'h1b == io_raddr_rs2 ? regs_27 : _GEN_58; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_60 = 5'h1c == io_raddr_rs2 ? regs_28 : _GEN_59; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_61 = 5'h1d == io_raddr_rs2 ? regs_29 : _GEN_60; // @[gpr.scala 30:{16,16}]
  wire [31:0] _GEN_62 = 5'h1e == io_raddr_rs2 ? regs_30 : _GEN_61; // @[gpr.scala 30:{16,16}]
  wire  _regs_T = io_mem_Req_valid & canAccept; // @[gpr.scala 33:45]
  wire [31:0] _GEN_65 = 5'h1 == io_waddr_rd ? regs_1 : regs_0; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_66 = 5'h2 == io_waddr_rd ? regs_2 : _GEN_65; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_67 = 5'h3 == io_waddr_rd ? regs_3 : _GEN_66; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_68 = 5'h4 == io_waddr_rd ? regs_4 : _GEN_67; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_69 = 5'h5 == io_waddr_rd ? regs_5 : _GEN_68; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_70 = 5'h6 == io_waddr_rd ? regs_6 : _GEN_69; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_71 = 5'h7 == io_waddr_rd ? regs_7 : _GEN_70; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_72 = 5'h8 == io_waddr_rd ? regs_8 : _GEN_71; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_73 = 5'h9 == io_waddr_rd ? regs_9 : _GEN_72; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_74 = 5'ha == io_waddr_rd ? regs_10 : _GEN_73; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_75 = 5'hb == io_waddr_rd ? regs_11 : _GEN_74; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_76 = 5'hc == io_waddr_rd ? regs_12 : _GEN_75; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_77 = 5'hd == io_waddr_rd ? regs_13 : _GEN_76; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_78 = 5'he == io_waddr_rd ? regs_14 : _GEN_77; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_79 = 5'hf == io_waddr_rd ? regs_15 : _GEN_78; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_80 = 5'h10 == io_waddr_rd ? regs_16 : _GEN_79; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_81 = 5'h11 == io_waddr_rd ? regs_17 : _GEN_80; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_82 = 5'h12 == io_waddr_rd ? regs_18 : _GEN_81; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_83 = 5'h13 == io_waddr_rd ? regs_19 : _GEN_82; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_84 = 5'h14 == io_waddr_rd ? regs_20 : _GEN_83; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_85 = 5'h15 == io_waddr_rd ? regs_21 : _GEN_84; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_86 = 5'h16 == io_waddr_rd ? regs_22 : _GEN_85; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_87 = 5'h17 == io_waddr_rd ? regs_23 : _GEN_86; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_88 = 5'h18 == io_waddr_rd ? regs_24 : _GEN_87; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_89 = 5'h19 == io_waddr_rd ? regs_25 : _GEN_88; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_90 = 5'h1a == io_waddr_rd ? regs_26 : _GEN_89; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_91 = 5'h1b == io_waddr_rd ? regs_27 : _GEN_90; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_92 = 5'h1c == io_waddr_rd ? regs_28 : _GEN_91; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_93 = 5'h1d == io_waddr_rd ? regs_29 : _GEN_92; // @[gpr.scala 33:{27,27}]
  wire [31:0] _GEN_94 = 5'h1e == io_waddr_rd ? regs_30 : _GEN_93; // @[gpr.scala 33:{27,27}]
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
  assign io_mem_Req_ready = _canAccept_T[0]; // @[gpr.scala 21:27]
  assign io_b_ready = _canAccept_T[0]; // @[gpr.scala 21:27]
  assign io_rdata_rs1 = 5'h1f == io_raddr_rs1 ? regs_31 : _GEN_30; // @[gpr.scala 29:{16,16}]
  assign io_rdata_rs2 = 5'h1f == io_raddr_rs2 ? regs_31 : _GEN_62; // @[gpr.scala 30:{16,16}]
  assign io_ifu_Req_valid = validReg; // @[gpr.scala 35:20]
  assign io_ifu_Req_bits_addr = pc_next_reg; // @[gpr.scala 31:24]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[gpr.scala 19:21]
      regs_0 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h0 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_0 <= 32'h0;
        end else begin
          regs_0 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_0 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_0 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_1 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_1 <= 32'h0;
        end else begin
          regs_1 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_1 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_1 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_2 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h2 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_2 <= 32'h0;
        end else begin
          regs_2 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_2 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_2 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_3 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h3 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_3 <= 32'h0;
        end else begin
          regs_3 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_3 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_3 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_4 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h4 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_4 <= 32'h0;
        end else begin
          regs_4 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_4 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_4 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_5 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h5 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_5 <= 32'h0;
        end else begin
          regs_5 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_5 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_5 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_6 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h6 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_6 <= 32'h0;
        end else begin
          regs_6 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_6 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_6 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_7 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h7 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_7 <= 32'h0;
        end else begin
          regs_7 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_7 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_7 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_8 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h8 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_8 <= 32'h0;
        end else begin
          regs_8 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_8 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_8 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_9 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h9 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_9 <= 32'h0;
        end else begin
          regs_9 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_9 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_9 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_10 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'ha == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_10 <= 32'h0;
        end else begin
          regs_10 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_10 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_10 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_11 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'hb == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_11 <= 32'h0;
        end else begin
          regs_11 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_11 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_11 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_12 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'hc == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_12 <= 32'h0;
        end else begin
          regs_12 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_12 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_12 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_13 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'hd == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_13 <= 32'h0;
        end else begin
          regs_13 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_13 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_13 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_14 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'he == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_14 <= 32'h0;
        end else begin
          regs_14 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_14 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_14 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_15 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'hf == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_15 <= 32'h0;
        end else begin
          regs_15 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_15 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_15 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_16 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h10 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_16 <= 32'h0;
        end else begin
          regs_16 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_16 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_16 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_17 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h11 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_17 <= 32'h0;
        end else begin
          regs_17 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_17 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_17 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_18 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h12 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_18 <= 32'h0;
        end else begin
          regs_18 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_18 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_18 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_19 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h13 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_19 <= 32'h0;
        end else begin
          regs_19 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_19 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_19 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_20 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h14 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_20 <= 32'h0;
        end else begin
          regs_20 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_20 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_20 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_21 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h15 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_21 <= 32'h0;
        end else begin
          regs_21 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_21 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_21 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_22 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h16 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_22 <= 32'h0;
        end else begin
          regs_22 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_22 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_22 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_23 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h17 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_23 <= 32'h0;
        end else begin
          regs_23 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_23 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_23 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_24 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h18 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_24 <= 32'h0;
        end else begin
          regs_24 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_24 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_24 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_25 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h19 == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_25 <= 32'h0;
        end else begin
          regs_25 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_25 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_25 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_26 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1a == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_26 <= 32'h0;
        end else begin
          regs_26 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_26 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_26 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_27 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1b == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_27 <= 32'h0;
        end else begin
          regs_27 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_27 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_27 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_28 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1c == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_28 <= 32'h0;
        end else begin
          regs_28 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_28 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_28 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_29 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1d == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_29 <= 32'h0;
        end else begin
          regs_29 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_29 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_29 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_30 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1e == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_30 <= 32'h0;
        end else begin
          regs_30 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:27]
        regs_30 <= regs_31; // @[gpr.scala 33:27]
      end else begin
        regs_30 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 19:21]
      regs_31 <= 32'h0; // @[gpr.scala 19:21]
    end else if (5'h1f == io_waddr_rd) begin // @[gpr.scala 33:21]
      if (io_mem_Req_valid & canAccept) begin // @[gpr.scala 33:27]
        if (io_waddr_rd == 5'h0) begin // @[gpr.scala 24:27]
          regs_31 <= 32'h0;
        end else begin
          regs_31 <= io_wdata_rd;
        end
      end else if (!(5'h1f == io_waddr_rd)) begin // @[gpr.scala 33:27]
        regs_31 <= _GEN_94;
      end
    end
    if (reset) begin // @[gpr.scala 20:25]
      validReg <= 1'h1; // @[gpr.scala 20:25]
    end else begin
      validReg <= io_mem_Req_valid & canAccept | _validReg_T_2; // @[gpr.scala 25:12]
    end
    if (reset) begin // @[gpr.scala 22:28]
      pc_next_reg <= 32'h80000000; // @[gpr.scala 22:28]
    end else if (_regs_T) begin // @[gpr.scala 34:21]
      pc_next_reg <= io_pc_next;
    end
  end
endmodule
