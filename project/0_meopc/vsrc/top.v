module top(
  input   clock,
  input   reset,
  output  io_is_unknown_instruction,
  output  io_carry,
  output  io_isoverflow,
  output  sram_b_valid,
  output  sram_aw1_ready,
  output  sram_w1_ready
);
  wire  b_ifu_clock; // @[top.scala 14:22]
  wire  b_ifu_reset; // @[top.scala 14:22]
  wire  b_ifu_io_rd_Req_ready; // @[top.scala 14:22]
  wire  b_ifu_io_rd_Req_valid; // @[top.scala 14:22]
  wire [31:0] b_ifu_io_rd_Req_bits_addr; // @[top.scala 14:22]
  wire  b_ifu_io_ar_ready; // @[top.scala 14:22]
  wire  b_ifu_io_ar_valid; // @[top.scala 14:22]
  wire [31:0] b_ifu_io_ar_bits_addr; // @[top.scala 14:22]
  wire  c_sram_clock; // @[top.scala 15:22]
  wire  c_sram_reset; // @[top.scala 15:22]
  wire  c_sram_io_ar_ready; // @[top.scala 15:22]
  wire  c_sram_io_ar_valid; // @[top.scala 15:22]
  wire [31:0] c_sram_io_ar_bits_addr; // @[top.scala 15:22]
  wire  c_sram_io_ar1_ready; // @[top.scala 15:22]
  wire  c_sram_io_ar1_valid; // @[top.scala 15:22]
  wire  c_sram_io_aw_ready; // @[top.scala 15:22]
  wire  c_sram_io_aw_valid; // @[top.scala 15:22]
  wire  c_sram_io_w_ready; // @[top.scala 15:22]
  wire  c_sram_io_w_valid; // @[top.scala 15:22]
  wire [31:0] c_sram_io_r_data; // @[top.scala 15:22]
  wire [31:0] d_idu_io_instruction; // @[top.scala 16:21]
  wire [2:0] d_idu_io_imm_type; // @[top.scala 16:21]
  wire [4:0] d_idu_io_rs1; // @[top.scala 16:21]
  wire [4:0] d_idu_io_rs2; // @[top.scala 16:21]
  wire [4:0] d_idu_io_rd; // @[top.scala 16:21]
  wire [2:0] d_idu_io_data_control; // @[top.scala 16:21]
  wire [3:0] d_idu_io_ALU_ctrl; // @[top.scala 16:21]
  wire [3:0] d_idu_io_pc_next_type; // @[top.scala 16:21]
  wire [2:0] d_idu_io_r_mask; // @[top.scala 16:21]
  wire [2:0] d_idu_io_w_mask; // @[top.scala 16:21]
  wire  d_idu_io_r_valid; // @[top.scala 16:21]
  wire [31:0] e_imm_io_instruction; // @[top.scala 17:21]
  wire [2:0] e_imm_io_imm_type; // @[top.scala 17:21]
  wire [31:0] e_imm_io_imm; // @[top.scala 17:21]
  wire  f_gpr_clock; // @[top.scala 18:21]
  wire  f_gpr_reset; // @[top.scala 18:21]
  wire  f_gpr_io_mem_Req_ready; // @[top.scala 18:21]
  wire  f_gpr_io_mem_Req_valid; // @[top.scala 18:21]
  wire  f_gpr_io_b_ready; // @[top.scala 18:21]
  wire  f_gpr_io_b_valid; // @[top.scala 18:21]
  wire [31:0] f_gpr_io_pc_next; // @[top.scala 18:21]
  wire [4:0] f_gpr_io_waddr_rd; // @[top.scala 18:21]
  wire [31:0] f_gpr_io_wdata_rd; // @[top.scala 18:21]
  wire [4:0] f_gpr_io_raddr_rs1; // @[top.scala 18:21]
  wire [31:0] f_gpr_io_rdata_rs1; // @[top.scala 18:21]
  wire [4:0] f_gpr_io_raddr_rs2; // @[top.scala 18:21]
  wire [31:0] f_gpr_io_rdata_rs2; // @[top.scala 18:21]
  wire  f_gpr_io_ifu_Req_ready; // @[top.scala 18:21]
  wire  f_gpr_io_ifu_Req_valid; // @[top.scala 18:21]
  wire [31:0] f_gpr_io_ifu_Req_bits_addr; // @[top.scala 18:21]
  wire  g_mem_clock; // @[top.scala 19:21]
  wire  g_mem_reset; // @[top.scala 19:21]
  wire  g_mem_io_ar_ready; // @[top.scala 19:21]
  wire  g_mem_io_ar_valid; // @[top.scala 19:21]
  wire  g_mem_io_aw_ready; // @[top.scala 19:21]
  wire  g_mem_io_aw_valid; // @[top.scala 19:21]
  wire  g_mem_io_w_ready; // @[top.scala 19:21]
  wire  g_mem_io_w_valid; // @[top.scala 19:21]
  wire [31:0] g_mem_io_rs1; // @[top.scala 19:21]
  wire [31:0] g_mem_io_rs2; // @[top.scala 19:21]
  wire [31:0] g_mem_io_imm; // @[top.scala 19:21]
  wire [2:0] g_mem_io_r_mask; // @[top.scala 19:21]
  wire [2:0] g_mem_io_w_mask; // @[top.scala 19:21]
  wire  g_mem_io_r_valid; // @[top.scala 19:21]
  wire [31:0] g_mem_io_mem_data; // @[top.scala 19:21]
  wire  g_mem_io_r__ready; // @[top.scala 19:21]
  wire  g_mem_io_r__valid; // @[top.scala 19:21]
  wire  g_mem_io_b_ready; // @[top.scala 19:21]
  wire  g_mem_io_b_valid; // @[top.scala 19:21]
  wire [31:0] h_data_control_io_rs1_data; // @[top.scala 20:30]
  wire [31:0] h_data_control_io_rs2_data; // @[top.scala 20:30]
  wire [31:0] h_data_control_io_imm; // @[top.scala 20:30]
  wire [31:0] h_data_control_io_mem_data; // @[top.scala 20:30]
  wire [31:0] h_data_control_io_pc_count; // @[top.scala 20:30]
  wire [2:0] h_data_control_io_data_control; // @[top.scala 20:30]
  wire [31:0] h_data_control_io_data_1; // @[top.scala 20:30]
  wire [31:0] h_data_control_io_data_2; // @[top.scala 20:30]
  wire [31:0] i_alu_io_in_a; // @[top.scala 21:21]
  wire [31:0] i_alu_io_in_b; // @[top.scala 21:21]
  wire [3:0] i_alu_io_sw; // @[top.scala 21:21]
  wire [31:0] i_alu_io_out; // @[top.scala 21:21]
  wire  i_alu_io_carry; // @[top.scala 21:21]
  wire  i_alu_io_overflow; // @[top.scala 21:21]
  wire [31:0] j_pc_next_io_rs1_data; // @[top.scala 22:25]
  wire [31:0] j_pc_next_io_rs2_data; // @[top.scala 22:25]
  wire [31:0] j_pc_next_io_instruction; // @[top.scala 22:25]
  wire [3:0] j_pc_next_io_pc_next_type; // @[top.scala 22:25]
  wire [31:0] j_pc_next_io_pc_count; // @[top.scala 22:25]
  wire [31:0] j_pc_next_io_pc_next; // @[top.scala 22:25]
  wire  j_pc_next_io_is_unknown_instruction; // @[top.scala 22:25]

  ysyx_25030077_IFU b_ifu ( // @[top.scala 14:22]
    .clock(b_ifu_clock),
    .reset(b_ifu_reset),
    .io_rd_Req_ready(b_ifu_io_rd_Req_ready),
    .io_rd_Req_valid(b_ifu_io_rd_Req_valid),
    .io_rd_Req_bits_addr(b_ifu_io_rd_Req_bits_addr),
    .io_ar_ready(b_ifu_io_ar_ready),
    .io_ar_valid(b_ifu_io_ar_valid),
    .io_ar_bits_addr(b_ifu_io_ar_bits_addr)
  );
  ysyx_25030077_SRAM c_sram ( // @[top.scala 15:22]
    .clock(c_sram_clock),
    .reset(c_sram_reset),
    .io_ar_ready(c_sram_io_ar_ready),
    .io_ar_valid(c_sram_io_ar_valid),
    .io_ar_bits_addr(c_sram_io_ar_bits_addr),
    .io_ar1_ready(c_sram_io_ar1_ready),
    .io_ar1_valid(c_sram_io_ar1_valid),
    .io_aw_ready(c_sram_io_aw_ready),
    .io_aw_valid(c_sram_io_aw_valid),
    .io_w_ready(c_sram_io_w_ready),
    .io_w_valid(c_sram_io_w_valid),
    .io_r_data(c_sram_io_r_data),

    .io_b_ready(1'b0),
    .io_b_valid(sram_b_valid),
    .io_aw1_valid(1'b0),
    .io_aw1_ready(sram_aw1_ready),
    .io_w1_valid(1'b0),
    .io_w1_ready(sram_w1_ready)
  );
  wire is_break_out_o;
  ysyx_25030077_IDU d_idu ( // @[top.scala 16:21]
    .io_instruction(d_idu_io_instruction),
    .io_imm_type(d_idu_io_imm_type),
    .io_rs1(d_idu_io_rs1),
    .io_rs2(d_idu_io_rs2),
    .io_rd(d_idu_io_rd),
    .io_data_control(d_idu_io_data_control),
    .io_ALU_ctrl(d_idu_io_ALU_ctrl),
    .io_pc_next_type(d_idu_io_pc_next_type),
    .io_r_mask(d_idu_io_r_mask),
    .io_w_mask(d_idu_io_w_mask),
    .io_r_valid(d_idu_io_r_valid),
    .is_break_out(is_break_out_o)
  );
  ysyx_25030077_Imm e_imm ( // @[top.scala 17:21]
    .io_instruction(e_imm_io_instruction),
    .io_imm_type(e_imm_io_imm_type),
    .io_imm(e_imm_io_imm)
  );
  ysyx_25030077_reg f_gpr ( // @[top.scala 18:21]
    .clock(f_gpr_clock),
    .reset(f_gpr_reset),
    .io_mem_Req_ready(f_gpr_io_mem_Req_ready),
    .io_mem_Req_valid(f_gpr_io_mem_Req_valid),
    .io_b_ready(f_gpr_io_b_ready),
    .io_b_valid(f_gpr_io_b_valid),
    .io_pc_next(f_gpr_io_pc_next),
    .io_waddr_rd(f_gpr_io_waddr_rd),
    .io_wdata_rd(f_gpr_io_wdata_rd),
    .io_raddr_rs1(f_gpr_io_raddr_rs1),
    .io_rdata_rs1(f_gpr_io_rdata_rs1),
    .io_raddr_rs2(f_gpr_io_raddr_rs2),
    .io_rdata_rs2(f_gpr_io_rdata_rs2),
    .io_ifu_Req_ready(f_gpr_io_ifu_Req_ready),
    .io_ifu_Req_valid(f_gpr_io_ifu_Req_valid),
    .io_ifu_Req_bits_addr(f_gpr_io_ifu_Req_bits_addr)
  );
  ysyx_25030077_MEM g_mem ( // @[top.scala 19:21]
    .clock(g_mem_clock),
    .reset(g_mem_reset),
    .io_ar_ready(g_mem_io_ar_ready),
    .io_ar_valid(g_mem_io_ar_valid),
    .io_aw_ready(g_mem_io_aw_ready),
    .io_aw_valid(g_mem_io_aw_valid),
    .io_w_ready(g_mem_io_w_ready),
    .io_w_valid(g_mem_io_w_valid),
    .io_rs1(g_mem_io_rs1),
    .io_rs2(g_mem_io_rs2),
    .io_imm(g_mem_io_imm),
    .io_r_mask(g_mem_io_r_mask),
    .io_w_mask(g_mem_io_w_mask),
    .io_r_valid(g_mem_io_r_valid),
    .io_mem_data(g_mem_io_mem_data),
    .io_r__ready(g_mem_io_r__ready),
    .io_r__valid(g_mem_io_r__valid),
    .io_b_ready(g_mem_io_b_ready),
    .io_b_valid(g_mem_io_b_valid)
  );
  ysyx_25030077_DATA_CONTROL h_data_control ( // @[top.scala 20:30]
    .io_rs1_data(h_data_control_io_rs1_data),
    .io_rs2_data(h_data_control_io_rs2_data),
    .io_imm(h_data_control_io_imm),
    .io_mem_data(h_data_control_io_mem_data),
    .io_pc_count(h_data_control_io_pc_count),
    .io_data_control(h_data_control_io_data_control),
    .io_data_1(h_data_control_io_data_1),
    .io_data_2(h_data_control_io_data_2)
  );
  ysyx_25030077_ALU i_alu ( // @[top.scala 21:21]
    .io_in_a(i_alu_io_in_a),
    .io_in_b(i_alu_io_in_b),
    .io_sw(i_alu_io_sw),
    .io_out(i_alu_io_out),
    .io_carry(i_alu_io_carry),
    .io_overflow(i_alu_io_overflow)
  );
  ysyx_25030077_PC_next j_pc_next ( // @[top.scala 22:25]
    .io_rs1_data(j_pc_next_io_rs1_data),
    .io_rs2_data(j_pc_next_io_rs2_data),
    .io_instruction(j_pc_next_io_instruction),
    .io_pc_next_type(j_pc_next_io_pc_next_type),
    .io_pc_count(j_pc_next_io_pc_count),
    .io_pc_next(j_pc_next_io_pc_next),
    .io_is_unknown_instruction(j_pc_next_io_is_unknown_instruction)
  );

  ysyx_25030077_EXIT k_EXIT(
    .clock(clock),
    .reset(reset),
    .io_Pc_count(c_sram_io_ar_bits_addr),
    .is_break_out(is_break_out_o),
    .is_unknown_instruction(j_pc_next_io_is_unknown_instruction)
  );

  assign io_is_unknown_instruction = j_pc_next_io_is_unknown_instruction; // @[top.scala 71:29]
  assign io_carry = i_alu_io_carry; // @[top.scala 72:12]
  assign io_isoverflow = i_alu_io_overflow; // @[top.scala 73:17]
  assign b_ifu_clock = clock;
  assign b_ifu_reset = reset;
  assign b_ifu_io_rd_Req_valid = f_gpr_io_ifu_Req_valid; // @[top.scala 33:20]
  assign b_ifu_io_rd_Req_bits_addr = f_gpr_io_ifu_Req_bits_addr; // @[top.scala 33:20]
  assign b_ifu_io_ar_ready = c_sram_io_ar_ready; // @[top.scala 24:15]
  assign c_sram_clock = clock;
  assign c_sram_reset = reset;
  assign c_sram_io_ar_valid = b_ifu_io_ar_valid; // @[top.scala 24:15]
  assign c_sram_io_ar_bits_addr = b_ifu_io_ar_bits_addr; // @[top.scala 24:15]
  assign c_sram_io_ar1_ready = g_mem_io_ar_ready; // @[top.scala 26:17]
  assign c_sram_io_aw_ready = g_mem_io_aw_ready; // @[top.scala 27:16]
  assign c_sram_io_w_ready = g_mem_io_w_ready; // @[top.scala 28:15]
  assign d_idu_io_instruction = c_sram_io_r_data; // @[top.scala 35:24]
  assign e_imm_io_instruction = c_sram_io_r_data; // @[top.scala 37:24]
  assign e_imm_io_imm_type = d_idu_io_imm_type; // @[top.scala 38:21]
  assign f_gpr_clock = clock;
  assign f_gpr_reset = reset;
  assign f_gpr_io_mem_Req_valid = g_mem_io_r__valid; // @[top.scala 30:14]
  assign f_gpr_io_b_valid = g_mem_io_b_valid; // @[top.scala 31:14]
  assign f_gpr_io_pc_next = j_pc_next_io_pc_next; // @[top.scala 42:20]
  assign f_gpr_io_waddr_rd = d_idu_io_rd; // @[top.scala 43:21]
  assign f_gpr_io_wdata_rd = i_alu_io_out; // @[top.scala 44:21]
  assign f_gpr_io_raddr_rs1 = d_idu_io_rs1; // @[top.scala 40:22]
  assign f_gpr_io_raddr_rs2 = d_idu_io_rs2; // @[top.scala 41:22]
  assign f_gpr_io_ifu_Req_ready = b_ifu_io_rd_Req_ready; // @[top.scala 33:20]
  assign g_mem_clock = clock;
  assign g_mem_reset = reset;
  assign g_mem_io_ar_valid = c_sram_io_ar1_valid; // @[top.scala 26:17]
  assign g_mem_io_aw_valid = c_sram_io_aw_valid; // @[top.scala 27:16]
  assign g_mem_io_w_valid = c_sram_io_w_valid; // @[top.scala 28:15]
  assign g_mem_io_rs1 = f_gpr_io_rdata_rs1; // @[top.scala 53:16]
  assign g_mem_io_rs2 = f_gpr_io_rdata_rs2; // @[top.scala 54:16]
  assign g_mem_io_imm = e_imm_io_imm; // @[top.scala 55:16]
  assign g_mem_io_r_mask = d_idu_io_r_mask; // @[top.scala 56:19]
  assign g_mem_io_w_mask = d_idu_io_w_mask; // @[top.scala 57:19]
  assign g_mem_io_r_valid = d_idu_io_r_valid; // @[top.scala 58:20]
  assign g_mem_io_r__ready = f_gpr_io_mem_Req_ready; // @[top.scala 30:14]
  assign g_mem_io_b_ready = f_gpr_io_b_ready; // @[top.scala 31:14]
  assign h_data_control_io_rs1_data = f_gpr_io_rdata_rs1; // @[top.scala 60:30]
  assign h_data_control_io_rs2_data = f_gpr_io_rdata_rs2; // @[top.scala 61:30]
  assign h_data_control_io_imm = e_imm_io_imm; // @[top.scala 62:25]
  assign h_data_control_io_mem_data = g_mem_io_mem_data; // @[top.scala 63:30]
  assign h_data_control_io_pc_count = b_ifu_io_rd_Req_bits_addr; // @[top.scala 65:30]
  assign h_data_control_io_data_control = d_idu_io_data_control; // @[top.scala 64:34]
  assign i_alu_io_in_a = h_data_control_io_data_1; // @[top.scala 67:17]
  assign i_alu_io_in_b = h_data_control_io_data_2; // @[top.scala 68:17]
  assign i_alu_io_sw = d_idu_io_ALU_ctrl; // @[top.scala 69:15]
  assign j_pc_next_io_rs1_data = f_gpr_io_rdata_rs1; // @[top.scala 47:25]
  assign j_pc_next_io_rs2_data = f_gpr_io_rdata_rs2; // @[top.scala 48:25]
  assign j_pc_next_io_instruction = c_sram_io_r_data; // @[top.scala 49:28]
  assign j_pc_next_io_pc_next_type = d_idu_io_pc_next_type; // @[top.scala 51:29]
  assign j_pc_next_io_pc_count = b_ifu_io_rd_Req_bits_addr; // @[top.scala 50:25]
endmodule
