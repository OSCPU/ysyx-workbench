module ysyx_25030077_reg(
  input         clock,
  input         reset,
  output        io_rd_Req_ready,
  input         io_rd_Req_valid,
  input  [4:0]  io_rd_Req_bits_rd_addr,
  input  [31:0] io_rd_Req_bits_rd_data,
  input  [31:0] io_rd_Req_bits_rs1_data,
  input  [31:0] io_rd_Req_bits_rs2_data,
  input  [31:0] io_rd_Req_bits_instruction,
  input  [3:0]  io_rd_Req_bits_pc_next_type,
  input  [31:0] io_rd_Req_bits_pc_count,
  input         io_pcnext_Req_ready,
  output        io_pcnext_Req_valid,
  output [31:0] io_pcnext_Req_bits_rs1_data,
  output [31:0] io_pcnext_Req_bits_rs2_data,
  output [31:0] io_pcnext_Req_bits_instruction,
  output [3:0]  io_pcnext_Req_bits_pc_next_type,
  output [31:0] io_pcnext_Req_bits_pc_count,
  input  [4:0]  io_raddr_rs1,
  output [31:0] io_rdata_rs1,
  input  [4:0]  io_raddr_rs2,
  output [31:0] io_rdata_rs2
);
  export "DPI-C" function reg_read_addr;
  function int reg_read_addr();
    return {27'b0, io_rd_Req_bits_rd_addr};
  endfunction

  export "DPI-C" function reg_read_data;
  function int reg_read_data();
    return {io_rd_Req_bits_rd_data};
  endfunction
  
  reg [31:0] regs_0; // @[gpr.scala 17:21]
  reg [31:0] regs_1; // @[gpr.scala 17:21]
  reg [31:0] regs_2; // @[gpr.scala 17:21]
  reg [31:0] regs_3; // @[gpr.scala 17:21]
  reg [31:0] regs_4; // @[gpr.scala 17:21]
  reg [31:0] regs_5; // @[gpr.scala 17:21]
  reg [31:0] regs_6; // @[gpr.scala 17:21]
  reg [31:0] regs_7; // @[gpr.scala 17:21]
  reg [31:0] regs_8; // @[gpr.scala 17:21]
  reg [31:0] regs_9; // @[gpr.scala 17:21]
  reg [31:0] regs_10; // @[gpr.scala 17:21]
  reg [31:0] regs_11; // @[gpr.scala 17:21]
  reg [31:0] regs_12; // @[gpr.scala 17:21]
  reg [31:0] regs_13; // @[gpr.scala 17:21]
  reg [31:0] regs_14; // @[gpr.scala 17:21]
  reg [31:0] regs_15; // @[gpr.scala 17:21]
  reg [31:0] regs_16; // @[gpr.scala 17:21]
  reg [31:0] regs_17; // @[gpr.scala 17:21]
  reg [31:0] regs_18; // @[gpr.scala 17:21]
  reg [31:0] regs_19; // @[gpr.scala 17:21]
  reg [31:0] regs_20; // @[gpr.scala 17:21]
  reg [31:0] regs_21; // @[gpr.scala 17:21]
  reg [31:0] regs_22; // @[gpr.scala 17:21]
  reg [31:0] regs_23; // @[gpr.scala 17:21]
  reg [31:0] regs_24; // @[gpr.scala 17:21]
  reg [31:0] regs_25; // @[gpr.scala 17:21]
  reg [31:0] regs_26; // @[gpr.scala 17:21]
  reg [31:0] regs_27; // @[gpr.scala 17:21]
  reg [31:0] regs_28; // @[gpr.scala 17:21]
  reg [31:0] regs_29; // @[gpr.scala 17:21]
  reg [31:0] regs_30; // @[gpr.scala 17:21]
  reg [31:0] regs_31; // @[gpr.scala 17:21]
  reg  validReg; // @[gpr.scala 19:25]
  reg [31:0] rs1_data_reg; // @[gpr.scala 20:29]
  reg [31:0] rs2_data_reg; // @[gpr.scala 21:29]
  reg [31:0] instruction_reg; // @[gpr.scala 22:32]
  reg [3:0] pc_next_type_reg; // @[gpr.scala 23:33]
  reg [31:0] pc_count_reg; // @[gpr.scala 24:29]
  wire  canAccept = ~validReg | io_pcnext_Req_ready; // @[gpr.scala 28:29]
  wire  _regs_T = io_rd_Req_valid & canAccept; // @[gpr.scala 31:55]
  wire [31:0] _GEN_1 = 5'h1 == io_rd_Req_bits_rd_addr ? regs_1 : regs_0; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_2 = 5'h2 == io_rd_Req_bits_rd_addr ? regs_2 : _GEN_1; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_3 = 5'h3 == io_rd_Req_bits_rd_addr ? regs_3 : _GEN_2; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_4 = 5'h4 == io_rd_Req_bits_rd_addr ? regs_4 : _GEN_3; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_5 = 5'h5 == io_rd_Req_bits_rd_addr ? regs_5 : _GEN_4; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_6 = 5'h6 == io_rd_Req_bits_rd_addr ? regs_6 : _GEN_5; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_7 = 5'h7 == io_rd_Req_bits_rd_addr ? regs_7 : _GEN_6; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_8 = 5'h8 == io_rd_Req_bits_rd_addr ? regs_8 : _GEN_7; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_9 = 5'h9 == io_rd_Req_bits_rd_addr ? regs_9 : _GEN_8; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_10 = 5'ha == io_rd_Req_bits_rd_addr ? regs_10 : _GEN_9; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_11 = 5'hb == io_rd_Req_bits_rd_addr ? regs_11 : _GEN_10; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_12 = 5'hc == io_rd_Req_bits_rd_addr ? regs_12 : _GEN_11; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_13 = 5'hd == io_rd_Req_bits_rd_addr ? regs_13 : _GEN_12; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_14 = 5'he == io_rd_Req_bits_rd_addr ? regs_14 : _GEN_13; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_15 = 5'hf == io_rd_Req_bits_rd_addr ? regs_15 : _GEN_14; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_16 = 5'h10 == io_rd_Req_bits_rd_addr ? regs_16 : _GEN_15; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_17 = 5'h11 == io_rd_Req_bits_rd_addr ? regs_17 : _GEN_16; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_18 = 5'h12 == io_rd_Req_bits_rd_addr ? regs_18 : _GEN_17; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_19 = 5'h13 == io_rd_Req_bits_rd_addr ? regs_19 : _GEN_18; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_20 = 5'h14 == io_rd_Req_bits_rd_addr ? regs_20 : _GEN_19; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_21 = 5'h15 == io_rd_Req_bits_rd_addr ? regs_21 : _GEN_20; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_22 = 5'h16 == io_rd_Req_bits_rd_addr ? regs_22 : _GEN_21; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_23 = 5'h17 == io_rd_Req_bits_rd_addr ? regs_23 : _GEN_22; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_24 = 5'h18 == io_rd_Req_bits_rd_addr ? regs_24 : _GEN_23; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_25 = 5'h19 == io_rd_Req_bits_rd_addr ? regs_25 : _GEN_24; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_26 = 5'h1a == io_rd_Req_bits_rd_addr ? regs_26 : _GEN_25; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_27 = 5'h1b == io_rd_Req_bits_rd_addr ? regs_27 : _GEN_26; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_28 = 5'h1c == io_rd_Req_bits_rd_addr ? regs_28 : _GEN_27; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_29 = 5'h1d == io_rd_Req_bits_rd_addr ? regs_29 : _GEN_28; // @[gpr.scala 31:{38,38}]
  wire [31:0] _GEN_30 = 5'h1e == io_rd_Req_bits_rd_addr ? regs_30 : _GEN_29; // @[gpr.scala 31:{38,38}]
  wire  _validReg_T_1 = io_pcnext_Req_ready ? 1'h0 : validReg; // @[gpr.scala 34:20]
  wire [31:0] _GEN_65 = 5'h1 == io_raddr_rs1 ? regs_1 : regs_0; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_66 = 5'h2 == io_raddr_rs1 ? regs_2 : _GEN_65; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_67 = 5'h3 == io_raddr_rs1 ? regs_3 : _GEN_66; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_68 = 5'h4 == io_raddr_rs1 ? regs_4 : _GEN_67; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_69 = 5'h5 == io_raddr_rs1 ? regs_5 : _GEN_68; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_70 = 5'h6 == io_raddr_rs1 ? regs_6 : _GEN_69; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_71 = 5'h7 == io_raddr_rs1 ? regs_7 : _GEN_70; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_72 = 5'h8 == io_raddr_rs1 ? regs_8 : _GEN_71; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_73 = 5'h9 == io_raddr_rs1 ? regs_9 : _GEN_72; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_74 = 5'ha == io_raddr_rs1 ? regs_10 : _GEN_73; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_75 = 5'hb == io_raddr_rs1 ? regs_11 : _GEN_74; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_76 = 5'hc == io_raddr_rs1 ? regs_12 : _GEN_75; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_77 = 5'hd == io_raddr_rs1 ? regs_13 : _GEN_76; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_78 = 5'he == io_raddr_rs1 ? regs_14 : _GEN_77; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_79 = 5'hf == io_raddr_rs1 ? regs_15 : _GEN_78; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_80 = 5'h10 == io_raddr_rs1 ? regs_16 : _GEN_79; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_81 = 5'h11 == io_raddr_rs1 ? regs_17 : _GEN_80; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_82 = 5'h12 == io_raddr_rs1 ? regs_18 : _GEN_81; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_83 = 5'h13 == io_raddr_rs1 ? regs_19 : _GEN_82; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_84 = 5'h14 == io_raddr_rs1 ? regs_20 : _GEN_83; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_85 = 5'h15 == io_raddr_rs1 ? regs_21 : _GEN_84; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_86 = 5'h16 == io_raddr_rs1 ? regs_22 : _GEN_85; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_87 = 5'h17 == io_raddr_rs1 ? regs_23 : _GEN_86; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_88 = 5'h18 == io_raddr_rs1 ? regs_24 : _GEN_87; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_89 = 5'h19 == io_raddr_rs1 ? regs_25 : _GEN_88; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_90 = 5'h1a == io_raddr_rs1 ? regs_26 : _GEN_89; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_91 = 5'h1b == io_raddr_rs1 ? regs_27 : _GEN_90; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_92 = 5'h1c == io_raddr_rs1 ? regs_28 : _GEN_91; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_93 = 5'h1d == io_raddr_rs1 ? regs_29 : _GEN_92; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_94 = 5'h1e == io_raddr_rs1 ? regs_30 : _GEN_93; // @[gpr.scala 37:{16,16}]
  wire [31:0] _GEN_97 = 5'h1 == io_raddr_rs2 ? regs_1 : regs_0; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_98 = 5'h2 == io_raddr_rs2 ? regs_2 : _GEN_97; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_99 = 5'h3 == io_raddr_rs2 ? regs_3 : _GEN_98; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_100 = 5'h4 == io_raddr_rs2 ? regs_4 : _GEN_99; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_101 = 5'h5 == io_raddr_rs2 ? regs_5 : _GEN_100; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_102 = 5'h6 == io_raddr_rs2 ? regs_6 : _GEN_101; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_103 = 5'h7 == io_raddr_rs2 ? regs_7 : _GEN_102; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_104 = 5'h8 == io_raddr_rs2 ? regs_8 : _GEN_103; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_105 = 5'h9 == io_raddr_rs2 ? regs_9 : _GEN_104; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_106 = 5'ha == io_raddr_rs2 ? regs_10 : _GEN_105; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_107 = 5'hb == io_raddr_rs2 ? regs_11 : _GEN_106; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_108 = 5'hc == io_raddr_rs2 ? regs_12 : _GEN_107; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_109 = 5'hd == io_raddr_rs2 ? regs_13 : _GEN_108; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_110 = 5'he == io_raddr_rs2 ? regs_14 : _GEN_109; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_111 = 5'hf == io_raddr_rs2 ? regs_15 : _GEN_110; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_112 = 5'h10 == io_raddr_rs2 ? regs_16 : _GEN_111; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_113 = 5'h11 == io_raddr_rs2 ? regs_17 : _GEN_112; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_114 = 5'h12 == io_raddr_rs2 ? regs_18 : _GEN_113; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_115 = 5'h13 == io_raddr_rs2 ? regs_19 : _GEN_114; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_116 = 5'h14 == io_raddr_rs2 ? regs_20 : _GEN_115; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_117 = 5'h15 == io_raddr_rs2 ? regs_21 : _GEN_116; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_118 = 5'h16 == io_raddr_rs2 ? regs_22 : _GEN_117; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_119 = 5'h17 == io_raddr_rs2 ? regs_23 : _GEN_118; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_120 = 5'h18 == io_raddr_rs2 ? regs_24 : _GEN_119; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_121 = 5'h19 == io_raddr_rs2 ? regs_25 : _GEN_120; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_122 = 5'h1a == io_raddr_rs2 ? regs_26 : _GEN_121; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_123 = 5'h1b == io_raddr_rs2 ? regs_27 : _GEN_122; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_124 = 5'h1c == io_raddr_rs2 ? regs_28 : _GEN_123; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_125 = 5'h1d == io_raddr_rs2 ? regs_29 : _GEN_124; // @[gpr.scala 38:{16,16}]
  wire [31:0] _GEN_126 = 5'h1e == io_raddr_rs2 ? regs_30 : _GEN_125; // @[gpr.scala 38:{16,16}]
  assign io_rd_Req_ready = ~validReg | io_pcnext_Req_ready; // @[gpr.scala 28:29]
  assign io_pcnext_Req_valid = validReg; // @[gpr.scala 40:23]
  assign io_pcnext_Req_bits_rs1_data = rs1_data_reg; // @[gpr.scala 41:31]
  assign io_pcnext_Req_bits_rs2_data = rs2_data_reg; // @[gpr.scala 42:31]
  assign io_pcnext_Req_bits_instruction = instruction_reg; // @[gpr.scala 43:34]
  assign io_pcnext_Req_bits_pc_next_type = pc_next_type_reg; // @[gpr.scala 44:35]
  assign io_pcnext_Req_bits_pc_count = pc_count_reg; // @[gpr.scala 45:31]
  assign io_rdata_rs1 = 5'h1f == io_raddr_rs1 ? regs_31 : _GEN_94; // @[gpr.scala 37:{16,16}]
  assign io_rdata_rs2 = 5'h1f == io_raddr_rs2 ? regs_31 : _GEN_126; // @[gpr.scala 38:{16,16}]
  always @(posedge clock) begin
    if (reset) begin // @[gpr.scala 17:21]
      regs_0 <= 32'h0; // @[gpr.scala 17:21]
    end else if (5'h0 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_0 <= 32'h0;
        end else begin
          regs_0 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_0 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_0 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_1 <= 32'h1; // @[gpr.scala 17:21]
    end else if (5'h1 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_1 <= 32'h0;
        end else begin
          regs_1 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_1 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_1 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_2 <= 32'h2; // @[gpr.scala 17:21]
    end else if (5'h2 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_2 <= 32'h0;
        end else begin
          regs_2 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_2 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_2 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_3 <= 32'h3; // @[gpr.scala 17:21]
    end else if (5'h3 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_3 <= 32'h0;
        end else begin
          regs_3 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_3 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_3 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_4 <= 32'h4; // @[gpr.scala 17:21]
    end else if (5'h4 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_4 <= 32'h0;
        end else begin
          regs_4 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_4 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_4 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_5 <= 32'h5; // @[gpr.scala 17:21]
    end else if (5'h5 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_5 <= 32'h0;
        end else begin
          regs_5 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_5 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_5 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_6 <= 32'h6; // @[gpr.scala 17:21]
    end else if (5'h6 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_6 <= 32'h0;
        end else begin
          regs_6 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_6 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_6 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_7 <= 32'h7; // @[gpr.scala 17:21]
    end else if (5'h7 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_7 <= 32'h0;
        end else begin
          regs_7 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_7 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_7 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_8 <= 32'h8; // @[gpr.scala 17:21]
    end else if (5'h8 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_8 <= 32'h0;
        end else begin
          regs_8 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_8 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_8 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_9 <= 32'h9; // @[gpr.scala 17:21]
    end else if (5'h9 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_9 <= 32'h0;
        end else begin
          regs_9 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_9 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_9 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_10 <= 32'ha; // @[gpr.scala 17:21]
    end else if (5'ha == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_10 <= 32'h0;
        end else begin
          regs_10 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_10 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_10 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_11 <= 32'hb; // @[gpr.scala 17:21]
    end else if (5'hb == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_11 <= 32'h0;
        end else begin
          regs_11 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_11 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_11 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_12 <= 32'hc; // @[gpr.scala 17:21]
    end else if (5'hc == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_12 <= 32'h0;
        end else begin
          regs_12 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_12 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_12 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_13 <= 32'hd; // @[gpr.scala 17:21]
    end else if (5'hd == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_13 <= 32'h0;
        end else begin
          regs_13 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_13 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_13 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_14 <= 32'he; // @[gpr.scala 17:21]
    end else if (5'he == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_14 <= 32'h0;
        end else begin
          regs_14 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_14 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_14 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_15 <= 32'hf; // @[gpr.scala 17:21]
    end else if (5'hf == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_15 <= 32'h0;
        end else begin
          regs_15 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_15 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_15 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_16 <= 32'h10; // @[gpr.scala 17:21]
    end else if (5'h10 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_16 <= 32'h0;
        end else begin
          regs_16 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_16 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_16 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_17 <= 32'h11; // @[gpr.scala 17:21]
    end else if (5'h11 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_17 <= 32'h0;
        end else begin
          regs_17 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_17 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_17 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_18 <= 32'h12; // @[gpr.scala 17:21]
    end else if (5'h12 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_18 <= 32'h0;
        end else begin
          regs_18 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_18 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_18 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_19 <= 32'h13; // @[gpr.scala 17:21]
    end else if (5'h13 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_19 <= 32'h0;
        end else begin
          regs_19 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_19 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_19 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_20 <= 32'h14; // @[gpr.scala 17:21]
    end else if (5'h14 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_20 <= 32'h0;
        end else begin
          regs_20 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_20 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_20 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_21 <= 32'h15; // @[gpr.scala 17:21]
    end else if (5'h15 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_21 <= 32'h0;
        end else begin
          regs_21 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_21 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_21 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_22 <= 32'h16; // @[gpr.scala 17:21]
    end else if (5'h16 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_22 <= 32'h0;
        end else begin
          regs_22 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_22 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_22 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_23 <= 32'h17; // @[gpr.scala 17:21]
    end else if (5'h17 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_23 <= 32'h0;
        end else begin
          regs_23 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_23 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_23 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_24 <= 32'h18; // @[gpr.scala 17:21]
    end else if (5'h18 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_24 <= 32'h0;
        end else begin
          regs_24 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_24 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_24 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_25 <= 32'h19; // @[gpr.scala 17:21]
    end else if (5'h19 == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_25 <= 32'h0;
        end else begin
          regs_25 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_25 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_25 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_26 <= 32'h1a; // @[gpr.scala 17:21]
    end else if (5'h1a == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_26 <= 32'h0;
        end else begin
          regs_26 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_26 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_26 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_27 <= 32'h1b; // @[gpr.scala 17:21]
    end else if (5'h1b == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_27 <= 32'h0;
        end else begin
          regs_27 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_27 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_27 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_28 <= 32'h1c; // @[gpr.scala 17:21]
    end else if (5'h1c == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_28 <= 32'h0;
        end else begin
          regs_28 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_28 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_28 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_29 <= 32'h1d; // @[gpr.scala 17:21]
    end else if (5'h1d == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_29 <= 32'h0;
        end else begin
          regs_29 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_29 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_29 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_30 <= 32'h1e; // @[gpr.scala 17:21]
    end else if (5'h1e == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_30 <= 32'h0;
        end else begin
          regs_30 <= io_rd_Req_bits_rd_data;
        end
      end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:38]
        regs_30 <= regs_31; // @[gpr.scala 31:38]
      end else begin
        regs_30 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 17:21]
      regs_31 <= 32'h1f; // @[gpr.scala 17:21]
    end else if (5'h1f == io_rd_Req_bits_rd_addr) begin // @[gpr.scala 31:32]
      if (io_rd_Req_valid & canAccept) begin // @[gpr.scala 31:38]
        if (io_rd_Req_bits_rd_addr == 5'h0) begin // @[gpr.scala 29:27]
          regs_31 <= 32'h0;
        end else begin
          regs_31 <= io_rd_Req_bits_rd_data;
        end
      end else if (!(5'h1f == io_rd_Req_bits_rd_addr)) begin // @[gpr.scala 31:38]
        regs_31 <= _GEN_30;
      end
    end
    if (reset) begin // @[gpr.scala 19:25]
      validReg <= 1'h0; // @[gpr.scala 19:25]
    end else begin
      validReg <= _regs_T | _validReg_T_1; // @[gpr.scala 33:12]
    end
    if (reset) begin // @[gpr.scala 20:29]
      rs1_data_reg <= 32'h0; // @[gpr.scala 20:29]
    end else if (_regs_T) begin // @[gpr.scala 47:22]
      rs1_data_reg <= io_rd_Req_bits_rs1_data;
    end
    if (reset) begin // @[gpr.scala 21:29]
      rs2_data_reg <= 32'h0; // @[gpr.scala 21:29]
    end else if (_regs_T) begin // @[gpr.scala 48:22]
      rs2_data_reg <= io_rd_Req_bits_rs2_data;
    end
    if (reset) begin // @[gpr.scala 22:32]
      instruction_reg <= 32'h413; // @[gpr.scala 22:32]
    end else if (_regs_T) begin // @[gpr.scala 49:25]
      instruction_reg <= io_rd_Req_bits_instruction;
    end
    if (reset) begin // @[gpr.scala 23:33]
      pc_next_type_reg <= 4'h0; // @[gpr.scala 23:33]
    end else if (_regs_T) begin // @[gpr.scala 50:26]
      pc_next_type_reg <= io_rd_Req_bits_pc_next_type;
    end
    if (reset) begin // @[gpr.scala 24:29]
      pc_count_reg <= 32'h413; // @[gpr.scala 24:29]
    end else if (_regs_T) begin // @[gpr.scala 51:22]
      pc_count_reg <= io_rd_Req_bits_pc_count;
    end
  end
endmodule