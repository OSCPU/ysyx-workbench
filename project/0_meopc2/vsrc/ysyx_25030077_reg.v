module ysyx_25030077_reg(
  input         clock,
  input         reset,
  input  [4:0]  io_waddr,
  input  [31:0] io_wdata,
  input  [4:0]  io_raddr_rs1,
  output [31:0] io_rdata_rs1,
  input  [4:0]  io_raddr_rs2,
  output [31:0] io_rdata_rs2
);
  export "DPI-C" function reg_read_addr;
  function int reg_read_addr();
    return {27'b0, io_waddr};
  endfunction

  export "DPI-C" function reg_read_data;
  function int reg_read_data();
    return {io_wdata};
  endfunction
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] regs_0; // @[module.scala 14:21]
  reg [31:0] regs_1; // @[module.scala 14:21]
  reg [31:0] regs_2; // @[module.scala 14:21]
  reg [31:0] regs_3; // @[module.scala 14:21]
  reg [31:0] regs_4; // @[module.scala 14:21]
  reg [31:0] regs_5; // @[module.scala 14:21]
  reg [31:0] regs_6; // @[module.scala 14:21]
  reg [31:0] regs_7; // @[module.scala 14:21]
  reg [31:0] regs_8; // @[module.scala 14:21]
  reg [31:0] regs_9; // @[module.scala 14:21]
  reg [31:0] regs_10; // @[module.scala 14:21]
  reg [31:0] regs_11; // @[module.scala 14:21]
  reg [31:0] regs_12; // @[module.scala 14:21]
  reg [31:0] regs_13; // @[module.scala 14:21]
  reg [31:0] regs_14; // @[module.scala 14:21]
  reg [31:0] regs_15; // @[module.scala 14:21]
  reg [31:0] regs_16; // @[module.scala 14:21]
  reg [31:0] regs_17; // @[module.scala 14:21]
  reg [31:0] regs_18; // @[module.scala 14:21]
  reg [31:0] regs_19; // @[module.scala 14:21]
  reg [31:0] regs_20; // @[module.scala 14:21]
  reg [31:0] regs_21; // @[module.scala 14:21]
  reg [31:0] regs_22; // @[module.scala 14:21]
  reg [31:0] regs_23; // @[module.scala 14:21]
  reg [31:0] regs_24; // @[module.scala 14:21]
  reg [31:0] regs_25; // @[module.scala 14:21]
  reg [31:0] regs_26; // @[module.scala 14:21]
  reg [31:0] regs_27; // @[module.scala 14:21]
  reg [31:0] regs_28; // @[module.scala 14:21]
  reg [31:0] regs_29; // @[module.scala 14:21]
  reg [31:0] regs_30; // @[module.scala 14:21]
  reg [31:0] regs_31; // @[module.scala 14:21]
  wire  isReg0 = io_waddr == 5'h0; // @[module.scala 15:25]
  wire  _regs_T = ~isReg0; // @[module.scala 19:5]
  wire [31:0] _GEN_33 = 5'h1 == io_raddr_rs1 ? regs_1 : regs_0; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_34 = 5'h2 == io_raddr_rs1 ? regs_2 : _GEN_33; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_35 = 5'h3 == io_raddr_rs1 ? regs_3 : _GEN_34; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_36 = 5'h4 == io_raddr_rs1 ? regs_4 : _GEN_35; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_37 = 5'h5 == io_raddr_rs1 ? regs_5 : _GEN_36; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_38 = 5'h6 == io_raddr_rs1 ? regs_6 : _GEN_37; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_39 = 5'h7 == io_raddr_rs1 ? regs_7 : _GEN_38; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_40 = 5'h8 == io_raddr_rs1 ? regs_8 : _GEN_39; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_41 = 5'h9 == io_raddr_rs1 ? regs_9 : _GEN_40; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_42 = 5'ha == io_raddr_rs1 ? regs_10 : _GEN_41; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_43 = 5'hb == io_raddr_rs1 ? regs_11 : _GEN_42; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_44 = 5'hc == io_raddr_rs1 ? regs_12 : _GEN_43; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_45 = 5'hd == io_raddr_rs1 ? regs_13 : _GEN_44; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_46 = 5'he == io_raddr_rs1 ? regs_14 : _GEN_45; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_47 = 5'hf == io_raddr_rs1 ? regs_15 : _GEN_46; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_48 = 5'h10 == io_raddr_rs1 ? regs_16 : _GEN_47; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_49 = 5'h11 == io_raddr_rs1 ? regs_17 : _GEN_48; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_50 = 5'h12 == io_raddr_rs1 ? regs_18 : _GEN_49; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_51 = 5'h13 == io_raddr_rs1 ? regs_19 : _GEN_50; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_52 = 5'h14 == io_raddr_rs1 ? regs_20 : _GEN_51; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_53 = 5'h15 == io_raddr_rs1 ? regs_21 : _GEN_52; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_54 = 5'h16 == io_raddr_rs1 ? regs_22 : _GEN_53; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_55 = 5'h17 == io_raddr_rs1 ? regs_23 : _GEN_54; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_56 = 5'h18 == io_raddr_rs1 ? regs_24 : _GEN_55; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_57 = 5'h19 == io_raddr_rs1 ? regs_25 : _GEN_56; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_58 = 5'h1a == io_raddr_rs1 ? regs_26 : _GEN_57; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_59 = 5'h1b == io_raddr_rs1 ? regs_27 : _GEN_58; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_60 = 5'h1c == io_raddr_rs1 ? regs_28 : _GEN_59; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_61 = 5'h1d == io_raddr_rs1 ? regs_29 : _GEN_60; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_62 = 5'h1e == io_raddr_rs1 ? regs_30 : _GEN_61; // @[module.scala 21:{16,16}]
  wire [31:0] _GEN_65 = 5'h1 == io_raddr_rs2 ? regs_1 : regs_0; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_66 = 5'h2 == io_raddr_rs2 ? regs_2 : _GEN_65; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_67 = 5'h3 == io_raddr_rs2 ? regs_3 : _GEN_66; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_68 = 5'h4 == io_raddr_rs2 ? regs_4 : _GEN_67; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_69 = 5'h5 == io_raddr_rs2 ? regs_5 : _GEN_68; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_70 = 5'h6 == io_raddr_rs2 ? regs_6 : _GEN_69; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_71 = 5'h7 == io_raddr_rs2 ? regs_7 : _GEN_70; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_72 = 5'h8 == io_raddr_rs2 ? regs_8 : _GEN_71; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_73 = 5'h9 == io_raddr_rs2 ? regs_9 : _GEN_72; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_74 = 5'ha == io_raddr_rs2 ? regs_10 : _GEN_73; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_75 = 5'hb == io_raddr_rs2 ? regs_11 : _GEN_74; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_76 = 5'hc == io_raddr_rs2 ? regs_12 : _GEN_75; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_77 = 5'hd == io_raddr_rs2 ? regs_13 : _GEN_76; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_78 = 5'he == io_raddr_rs2 ? regs_14 : _GEN_77; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_79 = 5'hf == io_raddr_rs2 ? regs_15 : _GEN_78; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_80 = 5'h10 == io_raddr_rs2 ? regs_16 : _GEN_79; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_81 = 5'h11 == io_raddr_rs2 ? regs_17 : _GEN_80; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_82 = 5'h12 == io_raddr_rs2 ? regs_18 : _GEN_81; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_83 = 5'h13 == io_raddr_rs2 ? regs_19 : _GEN_82; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_84 = 5'h14 == io_raddr_rs2 ? regs_20 : _GEN_83; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_85 = 5'h15 == io_raddr_rs2 ? regs_21 : _GEN_84; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_86 = 5'h16 == io_raddr_rs2 ? regs_22 : _GEN_85; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_87 = 5'h17 == io_raddr_rs2 ? regs_23 : _GEN_86; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_88 = 5'h18 == io_raddr_rs2 ? regs_24 : _GEN_87; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_89 = 5'h19 == io_raddr_rs2 ? regs_25 : _GEN_88; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_90 = 5'h1a == io_raddr_rs2 ? regs_26 : _GEN_89; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_91 = 5'h1b == io_raddr_rs2 ? regs_27 : _GEN_90; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_92 = 5'h1c == io_raddr_rs2 ? regs_28 : _GEN_91; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_93 = 5'h1d == io_raddr_rs2 ? regs_29 : _GEN_92; // @[module.scala 22:{16,16}]
  wire [31:0] _GEN_94 = 5'h1e == io_raddr_rs2 ? regs_30 : _GEN_93; // @[module.scala 22:{16,16}]
  assign io_rdata_rs1 = 5'h1f == io_raddr_rs1 ? regs_31 : _GEN_62; // @[module.scala 21:{16,16}]
  assign io_rdata_rs2 = 5'h1f == io_raddr_rs2 ? regs_31 : _GEN_94; // @[module.scala 22:{16,16}]
  always @(posedge clock) begin
    if (reset) begin // @[module.scala 14:21]
      regs_0 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h0 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_0 <= io_wdata;
      end else begin
        regs_0 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_1 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_1 <= io_wdata;
      end else begin
        regs_1 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_2 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h2 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_2 <= io_wdata;
      end else begin
        regs_2 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_3 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h3 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_3 <= io_wdata;
      end else begin
        regs_3 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_4 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h4 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_4 <= io_wdata;
      end else begin
        regs_4 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_5 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h5 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_5 <= io_wdata;
      end else begin
        regs_5 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_6 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h6 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_6 <= io_wdata;
      end else begin
        regs_6 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_7 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h7 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_7 <= io_wdata;
      end else begin
        regs_7 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_8 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h8 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_8 <= io_wdata;
      end else begin
        regs_8 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_9 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h9 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_9 <= io_wdata;
      end else begin
        regs_9 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_10 <= 32'h0; // @[module.scala 14:21]
    end else if (5'ha == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_10 <= io_wdata;
      end else begin
        regs_10 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_11 <= 32'h0; // @[module.scala 14:21]
    end else if (5'hb == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_11 <= io_wdata;
      end else begin
        regs_11 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_12 <= 32'h0; // @[module.scala 14:21]
    end else if (5'hc == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_12 <= io_wdata;
      end else begin
        regs_12 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_13 <= 32'h0; // @[module.scala 14:21]
    end else if (5'hd == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_13 <= io_wdata;
      end else begin
        regs_13 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_14 <= 32'h0; // @[module.scala 14:21]
    end else if (5'he == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_14 <= io_wdata;
      end else begin
        regs_14 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_15 <= 32'h0; // @[module.scala 14:21]
    end else if (5'hf == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_15 <= io_wdata;
      end else begin
        regs_15 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_16 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h10 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_16 <= io_wdata;
      end else begin
        regs_16 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_17 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h11 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_17 <= io_wdata;
      end else begin
        regs_17 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_18 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h12 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_18 <= io_wdata;
      end else begin
        regs_18 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_19 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h13 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_19 <= io_wdata;
      end else begin
        regs_19 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_20 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h14 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_20 <= io_wdata;
      end else begin
        regs_20 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_21 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h15 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_21 <= io_wdata;
      end else begin
        regs_21 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_22 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h16 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_22 <= io_wdata;
      end else begin
        regs_22 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_23 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h17 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_23 <= io_wdata;
      end else begin
        regs_23 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_24 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h18 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_24 <= io_wdata;
      end else begin
        regs_24 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_25 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h19 == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_25 <= io_wdata;
      end else begin
        regs_25 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_26 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1a == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_26 <= io_wdata;
      end else begin
        regs_26 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_27 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1b == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_27 <= io_wdata;
      end else begin
        regs_27 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_28 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1c == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_28 <= io_wdata;
      end else begin
        regs_28 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_29 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1d == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_29 <= io_wdata;
      end else begin
        regs_29 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_30 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1e == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_30 <= io_wdata;
      end else begin
        regs_30 <= 32'h0;
      end
    end
    if (reset) begin // @[module.scala 14:21]
      regs_31 <= 32'h0; // @[module.scala 14:21]
    end else if (5'h1f == io_waddr) begin // @[module.scala 17:18]
      if (_regs_T) begin // @[Mux.scala 27:73]
        regs_31 <= io_wdata;
      end else begin
        regs_31 <= 32'h0;
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  regs_0 = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  regs_1 = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  regs_2 = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  regs_3 = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  regs_4 = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  regs_5 = _RAND_5[31:0];
  _RAND_6 = {1{`RANDOM}};
  regs_6 = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  regs_7 = _RAND_7[31:0];
  _RAND_8 = {1{`RANDOM}};
  regs_8 = _RAND_8[31:0];
  _RAND_9 = {1{`RANDOM}};
  regs_9 = _RAND_9[31:0];
  _RAND_10 = {1{`RANDOM}};
  regs_10 = _RAND_10[31:0];
  _RAND_11 = {1{`RANDOM}};
  regs_11 = _RAND_11[31:0];
  _RAND_12 = {1{`RANDOM}};
  regs_12 = _RAND_12[31:0];
  _RAND_13 = {1{`RANDOM}};
  regs_13 = _RAND_13[31:0];
  _RAND_14 = {1{`RANDOM}};
  regs_14 = _RAND_14[31:0];
  _RAND_15 = {1{`RANDOM}};
  regs_15 = _RAND_15[31:0];
  _RAND_16 = {1{`RANDOM}};
  regs_16 = _RAND_16[31:0];
  _RAND_17 = {1{`RANDOM}};
  regs_17 = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  regs_18 = _RAND_18[31:0];
  _RAND_19 = {1{`RANDOM}};
  regs_19 = _RAND_19[31:0];
  _RAND_20 = {1{`RANDOM}};
  regs_20 = _RAND_20[31:0];
  _RAND_21 = {1{`RANDOM}};
  regs_21 = _RAND_21[31:0];
  _RAND_22 = {1{`RANDOM}};
  regs_22 = _RAND_22[31:0];
  _RAND_23 = {1{`RANDOM}};
  regs_23 = _RAND_23[31:0];
  _RAND_24 = {1{`RANDOM}};
  regs_24 = _RAND_24[31:0];
  _RAND_25 = {1{`RANDOM}};
  regs_25 = _RAND_25[31:0];
  _RAND_26 = {1{`RANDOM}};
  regs_26 = _RAND_26[31:0];
  _RAND_27 = {1{`RANDOM}};
  regs_27 = _RAND_27[31:0];
  _RAND_28 = {1{`RANDOM}};
  regs_28 = _RAND_28[31:0];
  _RAND_29 = {1{`RANDOM}};
  regs_29 = _RAND_29[31:0];
  _RAND_30 = {1{`RANDOM}};
  regs_30 = _RAND_30[31:0];
  _RAND_31 = {1{`RANDOM}};
  regs_31 = _RAND_31[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
