module ysyx_25030077_arbiter(
  input         clock,
  input         reset,
  input         io_ifu_valid,
  input  [2:0]  io_delay_cnt,
  input  [31:0] io_pc,
  input  [31:0] io_rs1_data,
  input  [31:0] io_rs2_data,
  input  [31:0] io_imm,
  input  [2:0]  io_r_mask,
  input  [2:0]  io_w_mask,
  output        io_axi_ar_valid,
  output [31:0] io_axi_ar_addr,
  output [2:0]  io_axi_ar_strb,
  input         io_axi_ar_ready,
  output        io_axi_aw_valid,
  output [31:0] io_axi_aw_addr,
  input         io_axi_aw_ready,
  output        io_axi_w_valid,
  output [31:0] io_axi_w_data,
  output [2:0]  io_axi_w_strb,
  input         io_axi_w_ready,
  input         io_axi_r_valid,
  input  [31:0] io_axi_r_data,
  output        io_axi_r_ready,
  input         io_axi_b_valid,
  output        io_axi_b_ready,
  output        io_gpr_r_valid,
  output        io_gpr_b_valid,
  input         io_gpr_r_ready,
  input         io_gpr_b_ready,
  output [31:0] io_gpr_data,
  output [31:0] io_inst,
  output        io_ifu_ready,
  input         io_r_valid_lsu,
  output        io_is_r
);
  reg [1:0] state_reg; // @[arbiter.scala 49:28]
  reg [31:0] inst_reg; // @[arbiter.scala 50:27]
  wire  _state_reg_T = state_reg == 2'h0; // @[arbiter.scala 53:20]
  wire  _state_reg_T_1 = io_delay_cnt == 3'h1; // @[arbiter.scala 53:49]
  wire  _state_reg_T_3 = state_reg == 2'h1; // @[arbiter.scala 54:20]
  wire [1:0] _state_reg_T_6 = _state_reg_T_1 ? 2'h2 : 2'h1; // @[arbiter.scala 55:71]
  wire  _state_reg_T_7 = ~io_r_valid_lsu; // @[arbiter.scala 56:53]
  wire  _state_reg_T_8 = io_axi_r_valid & io_axi_ar_ready; // @[arbiter.scala 56:88]
  wire [1:0] _state_reg_T_9 = io_axi_r_valid & io_axi_ar_ready ? 2'h2 : 2'h1; // @[arbiter.scala 56:72]
  wire [1:0] _state_reg_T_10 = _state_reg_T_7 ? _state_reg_T_9 : 2'h0; // @[Mux.scala 101:16]
  wire  _state_reg_T_12 = state_reg == 2'h2; // @[arbiter.scala 58:20]
  wire [1:0] _state_reg_T_14 = _state_reg_T_8 ? 2'h0 : 2'h2; // @[arbiter.scala 58:35]
  wire [32:0] _io_axi_aw_addr_T_1 = io_rs1_data + io_imm; // @[arbiter.scala 62:67]
  wire [31:0] _io_axi_aw_addr_T_3 = _state_reg_T_3 ? _io_axi_aw_addr_T_1[31:0] : 32'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_axi_ar_strb_T_2 = _state_reg_T_3 ? io_r_mask : 3'h0; // @[Mux.scala 101:16]
  wire  _inst_reg_T_2 = _state_reg_T_1 & _state_reg_T; // @[arbiter.scala 104:53]
  assign io_axi_ar_valid = _state_reg_T ? io_ifu_valid : _state_reg_T_3 & io_axi_r_valid; // @[Mux.scala 101:16]
  assign io_axi_ar_addr = _state_reg_T ? io_pc : _io_axi_aw_addr_T_3; // @[Mux.scala 101:16]
  assign io_axi_ar_strb = _state_reg_T ? 3'h6 : _io_axi_ar_strb_T_2; // @[Mux.scala 101:16]
  assign io_axi_aw_valid = _state_reg_T_3 & io_axi_r_valid; // @[Mux.scala 101:16]
  assign io_axi_aw_addr = _state_reg_T_3 ? _io_axi_aw_addr_T_1[31:0] : 32'h0; // @[Mux.scala 101:16]
  assign io_axi_w_valid = _state_reg_T_3 & io_axi_r_valid; // @[Mux.scala 101:16]
  assign io_axi_w_data = _state_reg_T_3 ? io_rs2_data : 32'h0; // @[Mux.scala 101:16]
  assign io_axi_w_strb = _state_reg_T_3 ? io_w_mask : 3'h0; // @[Mux.scala 101:16]
  assign io_axi_r_ready = io_gpr_r_ready; // @[arbiter.scala 90:21]
  assign io_axi_b_ready = io_gpr_b_ready; // @[arbiter.scala 91:21]
  assign io_gpr_r_valid = _state_reg_T_12 & io_axi_r_valid; // @[Mux.scala 101:16]
  assign io_gpr_b_valid = _state_reg_T_12 & io_axi_b_valid; // @[Mux.scala 101:16]
  assign io_gpr_data = _state_reg_T_12 ? io_axi_r_data : 32'h0; // @[Mux.scala 101:16]
  assign io_inst = inst_reg; // @[arbiter.scala 106:21]
  assign io_ifu_ready = io_axi_ar_ready; // @[arbiter.scala 92:21]
  assign io_is_r = _state_reg_T | _state_reg_T_3 & io_r_valid_lsu; // @[Mux.scala 101:16]
  always @(posedge clock) begin
    if (reset) begin // @[arbiter.scala 49:28]
      state_reg <= 2'h0; // @[arbiter.scala 49:28]
    end else if (_state_reg_T) begin // @[Mux.scala 101:16]
      state_reg <= {{1'd0}, _state_reg_T_1};
    end else if (_state_reg_T_3) begin // @[Mux.scala 101:16]
      if (io_r_valid_lsu) begin // @[Mux.scala 101:16]
        state_reg <= _state_reg_T_6;
      end else begin
        state_reg <= _state_reg_T_10;
      end
    end else if (_state_reg_T_12) begin // @[Mux.scala 101:16]
      state_reg <= _state_reg_T_14;
    end else begin
      state_reg <= 2'h0;
    end
    if (reset) begin // @[arbiter.scala 50:27]
      inst_reg <= 32'h0; // @[arbiter.scala 50:27]
    end else if (_inst_reg_T_2) begin // @[Mux.scala 101:16]
      inst_reg <= io_axi_r_data;
    end
  end
endmodule
