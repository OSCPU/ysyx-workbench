module top(
  input   clock,
  input   reset,
  output  io_is_unknown_instruction,
  output  io_carry,
  output  io_isoverflow
);
    wire  b_ifu_clock; // @[top.scala 14:22]
  wire  b_ifu_reset; // @[top.scala 14:22]
  wire  b_ifu_io_rd_Req_ready; // @[top.scala 14:22]
  wire  b_ifu_io_rd_Req_valid; // @[top.scala 14:22]
  wire [31:0] b_ifu_io_rd_Req_bits_addr; // @[top.scala 14:22]
  wire  b_ifu_io_ar_ready; // @[top.scala 14:22]
  wire  b_ifu_io_ar_valid; // @[top.scala 14:22]
  wire [31:0] b_ifu_io_ar_bits_addr; // @[top.scala 14:22]
  wire  c_arbiter_clock; // @[top.scala 15:25]
  wire  c_arbiter_reset; // @[top.scala 15:25]
  wire  c_arbiter_io_ifu_valid; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_delay_cnt_mem; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_delay_cnt_clint; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_pc; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_rs1_data; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_imm; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_r_mask; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_w_mask; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_ar_valid_mem; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_ar_addr_mem; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_axi_ar_strb_mem; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_ar_ready_mem; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_ar_valid_clint; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_ar_addr_clint; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_axi_ar_strb_clint; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_ar_ready_clint; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_aw_valid; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_aw_addr; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_w_valid; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_axi_w_strb; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_r_valid_mem; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_r_data_mem; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_r_ready_mem; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_r_valid_clint; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_r_data_clint; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_r_ready_clint; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_b_ready; // @[top.scala 15:25]
  wire  c_arbiter_io_gpr_r_valid; // @[top.scala 15:25]
  wire  c_arbiter_io_gpr_b_valid; // @[top.scala 15:25]
  wire  c_arbiter_io_gpr_r_ready; // @[top.scala 15:25]
  wire  c_arbiter_io_gpr_b_ready; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_gpr_data; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_inst; // @[top.scala 15:25]
  wire  c_arbiter_io_ifu_ready; // @[top.scala 15:25]
  wire  c_arbiter_io_r_valid_lsu; // @[top.scala 15:25]
  wire  c_arbiter_io_is_r; // @[top.scala 15:25]
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
  wire  g_mem_io_aw_valid; // @[top.scala 19:21]
  wire  g_mem_io_w_valid; // @[top.scala 19:21]
  wire [31:0] g_mem_io_waddr; // @[top.scala 19:21]
  wire [31:0] g_mem_io_raddr; // @[top.scala 19:21]
  wire [2:0] g_mem_io_r_mask; // @[top.scala 19:21]
  wire [2:0] g_mem_io_w_mask; // @[top.scala 19:21]
  wire  g_mem_io_r_valid; // @[top.scala 19:21]
  wire [31:0] g_mem_io_mem_data; // @[top.scala 19:21]
  wire [2:0] g_mem_io_cnt; // @[top.scala 19:21]
  wire  g_mem_io_r__ready; // @[top.scala 19:21]
  wire  g_mem_io_r__valid; // @[top.scala 19:21]
  wire  g_mem_io_b_ready; // @[top.scala 19:21]
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
  wire  m_clint_clock; // @[top.scala 24:23]
  wire  m_clint_reset; // @[top.scala 24:23]
  wire  m_clint_io_ar_ready; // @[top.scala 24:23]
  wire  m_clint_io_ar_valid; // @[top.scala 24:23]
  wire [31:0] m_clint_io_raddr; // @[top.scala 24:23]
  wire [2:0] m_clint_io_r_mask; // @[top.scala 24:23]
  wire  m_clint_io_r_valid; // @[top.scala 24:23]
  wire [31:0] m_clint_io_mem_data; // @[top.scala 24:23]
  wire [2:0] m_clint_io_cnt; // @[top.scala 24:23]
  wire  m_clint_io_r__ready; // @[top.scala 24:23]
  wire  m_clint_io_r__valid; // @[top.scala 24:23]

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
  wire [31:0] c_arbiter_io_axi_w_data;
  wire c_arbiter_io_axi_b_valid;
  wire g_mem_io_w_ready;
  wire g_mem_io_aw_ready;

  wire  c_arbiter_io_axi_aw_valid_uart; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_aw_addr_uart; // @[top.scala 15:25]
  wire  c_arbiter_io_axi_w_valid_uart; // @[top.scala 15:25]
  wire [31:0] c_arbiter_io_axi_w_data_uart; // @[top.scala 15:25]
  wire [2:0] c_arbiter_io_axi_w_strb_uart; // @[top.scala 15:25]

  ysyx_25030077_arbiter c_arbiter ( // @[top.scala 15:22]
    .clock(c_arbiter_clock),
    .reset(c_arbiter_reset),
    .io_ifu_valid(c_arbiter_io_ifu_valid),
    .io_delay_cnt_mem(c_arbiter_io_delay_cnt_mem),
    .io_delay_cnt_clint(c_arbiter_io_delay_cnt_clint),
    .io_pc(c_arbiter_io_pc),
    .io_rs1_data(c_arbiter_io_rs1_data),
    .io_rs2_data(f_gpr_io_rdata_rs2),
    .io_imm(c_arbiter_io_imm),
    .io_r_mask(c_arbiter_io_r_mask),
    .io_w_mask(c_arbiter_io_w_mask),
    .io_axi_ar_valid_mem(c_arbiter_io_axi_ar_valid_mem),
    .io_axi_ar_addr_mem(c_arbiter_io_axi_ar_addr_mem),
    .io_axi_ar_strb_mem(c_arbiter_io_axi_ar_strb_mem),
    .io_axi_ar_ready_mem(c_arbiter_io_axi_ar_ready_mem),
    .io_axi_ar_valid_clint(c_arbiter_io_axi_ar_valid_clint),
    .io_axi_ar_addr_clint(c_arbiter_io_axi_ar_addr_clint),
    .io_axi_ar_strb_clint(c_arbiter_io_axi_ar_strb_clint),
    .io_axi_ar_ready_clint(c_arbiter_io_axi_ar_ready_clint),
    .io_axi_aw_valid_mem(c_arbiter_io_axi_aw_valid),
    .io_axi_aw_addr_mem(c_arbiter_io_axi_aw_addr),
    .io_axi_aw_ready_mem(g_mem_io_aw_ready),
    .io_axi_w_valid_mem(c_arbiter_io_axi_w_valid),
    .io_axi_w_data_mem(c_arbiter_io_axi_w_data),
    .io_axi_w_strb_mem(c_arbiter_io_axi_w_strb),
    .io_axi_w_ready_mem(g_mem_io_w_ready),
    .io_axi_aw_valid_uart(c_arbiter_io_axi_aw_valid_uart),
    .io_axi_aw_addr_uart(c_arbiter_io_axi_aw_addr_uart),
    .io_axi_w_valid_uart(c_arbiter_io_axi_w_valid_uart),
    .io_axi_w_data_uart(c_arbiter_io_axi_w_data_uart),
    .io_axi_w_strb_uart(c_arbiter_io_axi_w_strb_uart),
    .io_axi_r_valid_mem(c_arbiter_io_axi_r_valid_mem),
    .io_axi_r_data_mem(c_arbiter_io_axi_r_data_mem),
    .io_axi_r_ready_mem(c_arbiter_io_axi_r_ready_mem),
    .io_axi_r_valid_clint(c_arbiter_io_axi_r_valid_clint),
    .io_axi_r_data_clint(c_arbiter_io_axi_r_data_clint),
    .io_axi_r_ready_clint(c_arbiter_io_axi_r_ready_clint),
    .io_axi_b_valid(c_arbiter_io_axi_b_valid),
    .io_axi_b_ready(c_arbiter_io_axi_b_ready),
    .io_gpr_r_valid(c_arbiter_io_gpr_r_valid),
    .io_gpr_b_valid(c_arbiter_io_gpr_b_valid),
    .io_gpr_r_ready(c_arbiter_io_gpr_r_ready),
    .io_gpr_b_ready(c_arbiter_io_gpr_b_ready),
    .io_gpr_data(c_arbiter_io_gpr_data),
    .io_inst(c_arbiter_io_inst),
    .io_ifu_ready(c_arbiter_io_ifu_ready),
    .io_r_valid_lsu(c_arbiter_io_r_valid_lsu),
    .io_is_r(c_arbiter_io_is_r)
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
    .io_w_valid(g_mem_io_w_valid),
    .io_w_ready(g_mem_io_w_ready),
    .io_waddr(g_mem_io_waddr),
    .io_raddr(g_mem_io_raddr),
    .io_wdata(c_arbiter_io_axi_w_data),
    .io_r_mask(g_mem_io_r_mask),
    .io_w_mask(g_mem_io_w_mask),
    .io_r_valid(g_mem_io_r_valid),
    .io_mem_data(g_mem_io_mem_data),
    .io_cnt(g_mem_io_cnt),
    .io_r__ready(g_mem_io_r__ready),
    .io_r__valid(g_mem_io_r__valid),
    .io_b_ready(g_mem_io_b_ready),
    .io_b_valid(c_arbiter_io_axi_b_valid)
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
    // .io_Pc_count(c_sram_io_ar_bits_addr),
    .is_break_out(is_break_out_o),
    .is_unknown_instruction(j_pc_next_io_is_unknown_instruction)
  );

  wire  l_uart_clock; // @[top.scala 23:22]
  wire  l_uart_reset; // @[top.scala 23:22]
  wire  l_uart_io_aw_valid; // @[top.scala 23:22]
  wire  l_uart_io_w_valid; // @[top.scala 23:22]
  wire [31:0] l_uart_io_waddr; // @[top.scala 23:22]
  wire [31:0] l_uart_io_wdata; // @[top.scala 23:22]

  ysyx_25030077_UART l_uart ( // @[top.scala 23:22]
    .clock(l_uart_clock),
    .reset(l_uart_reset),
    .io_aw_valid(l_uart_io_aw_valid),
    .io_w_valid(l_uart_io_w_valid),
    .io_waddr(l_uart_io_waddr),
    .io_wdata(l_uart_io_wdata)
  );

  clint m_clint ( // @[top.scala 24:23]
    .clock(m_clint_clock),
    .reset(m_clint_reset),
    .io_ar_ready(m_clint_io_ar_ready),
    .io_ar_valid(m_clint_io_ar_valid),
    .io_raddr(m_clint_io_raddr),
    .io_r_mask(m_clint_io_r_mask),
    .io_r_valid(m_clint_io_r_valid),
    .io_mem_data(m_clint_io_mem_data),
    .io_cnt(m_clint_io_cnt),
    .io_r__ready(m_clint_io_r__ready),
    .io_r__valid(m_clint_io_r__valid)
  );

  assign io_is_unknown_instruction = j_pc_next_io_is_unknown_instruction; // @[top.scala 89:29]
  assign io_carry = i_alu_io_carry; // @[top.scala 90:12]
  assign io_isoverflow = i_alu_io_overflow; // @[top.scala 91:17]
  assign b_ifu_clock = clock;
  assign b_ifu_reset = reset;
  assign b_ifu_io_rd_Req_valid = f_gpr_io_ifu_Req_valid; // @[top.scala 58:20]
  assign b_ifu_io_rd_Req_bits_addr = f_gpr_io_ifu_Req_bits_addr; // @[top.scala 58:20]
  assign b_ifu_io_ar_ready = c_arbiter_io_ifu_ready; // @[top.scala 24:21]
  assign c_arbiter_clock = clock;
  assign c_arbiter_reset = reset;
  assign c_arbiter_io_ifu_valid = b_ifu_io_ar_valid; // @[top.scala 26:26]
  assign c_arbiter_io_delay_cnt_mem = g_mem_io_cnt; // @[top.scala 42:26]
  assign c_arbiter_io_delay_cnt_clint = m_clint_io_cnt; // @[top.scala 43:27]
  assign c_arbiter_io_pc = b_ifu_io_ar_bits_addr; // @[top.scala 27:19]
  assign c_arbiter_io_rs1_data = f_gpr_io_rdata_rs1; // @[top.scala 28:25]
  assign c_arbiter_io_imm = e_imm_io_imm; // @[top.scala 30:20]
  assign c_arbiter_io_r_mask = d_idu_io_r_mask; // @[top.scala 31:23]
  assign c_arbiter_io_w_mask = d_idu_io_w_mask; // @[top.scala 32:23]
  assign c_arbiter_io_axi_ar_ready_mem = g_mem_io_ar_ready; // @[top.scala 33:29]
  assign c_arbiter_io_axi_r_valid_mem = g_mem_io_r__valid; // @[top.scala 36:28]
  assign c_arbiter_io_axi_r_data_mem = g_mem_io_mem_data; // @[top.scala 37:27]
  assign c_arbiter_io_axi_ar_ready_clint = m_clint_io_ar_ready; // @[top.scala 34:30]
  assign c_arbiter_io_gpr_r_ready = f_gpr_io_mem_Req_ready; // @[top.scala 40:28]
  assign c_arbiter_io_gpr_b_ready = f_gpr_io_b_ready; // @[top.scala 41:28]
  assign c_arbiter_io_axi_r_valid_clint = m_clint_io_r__valid; // @[top.scala 43:34]
  assign c_arbiter_io_r_valid_lsu = d_idu_io_r_valid; // @[top.scala 39:28]
  assign c_arbiter_io_axi_r_data_clint = m_clint_io_mem_data; // @[top.scala 38:27]
  assign d_idu_io_instruction = c_arbiter_io_inst; // @[top.scala 44:24]
  assign e_imm_io_instruction = c_arbiter_io_inst; // @[top.scala 60:24]
  assign e_imm_io_imm_type = d_idu_io_imm_type; // @[top.scala 61:21]
  assign f_gpr_clock = clock;
  assign f_gpr_reset = reset;
  assign f_gpr_io_mem_Req_valid = c_arbiter_io_gpr_r_valid; // @[top.scala 68:26]
  assign f_gpr_io_b_valid = c_arbiter_io_gpr_b_valid; // @[top.scala 69:20]
  assign f_gpr_io_pc_next = j_pc_next_io_pc_next; // @[top.scala 65:20]
  assign f_gpr_io_waddr_rd = d_idu_io_rd; // @[top.scala 66:21]
  assign f_gpr_io_wdata_rd = i_alu_io_out; // @[top.scala 67:21]
  assign f_gpr_io_raddr_rs1 = d_idu_io_rs1; // @[top.scala 63:22]
  assign f_gpr_io_raddr_rs2 = d_idu_io_rs2; // @[top.scala 64:22]
  assign f_gpr_io_ifu_Req_ready = b_ifu_io_rd_Req_ready; // @[top.scala 58:20]
  assign g_mem_clock = clock;
  assign g_mem_reset = reset;
  assign g_mem_io_ar_valid = c_arbiter_io_axi_ar_valid_mem; // @[top.scala 46:21]
  assign g_mem_io_aw_valid = c_arbiter_io_axi_aw_valid; // @[top.scala 47:21]
  assign g_mem_io_w_valid = c_arbiter_io_axi_w_valid; // @[top.scala 48:20]
  assign g_mem_io_waddr = c_arbiter_io_axi_aw_addr; // @[top.scala 49:18]
  assign g_mem_io_raddr = c_arbiter_io_axi_ar_addr_mem; // @[top.scala 50:18]
  assign g_mem_io_r_mask = c_arbiter_io_axi_ar_strb_mem; // @[top.scala 52:19]
  assign g_mem_io_w_mask = c_arbiter_io_axi_w_strb; // @[top.scala 53:19]
  assign g_mem_io_r_valid = c_arbiter_io_is_r; // @[top.scala 54:20]
  assign g_mem_io_r__ready = c_arbiter_io_axi_r_ready_mem; // @[top.scala 55:20]
  assign g_mem_io_b_ready = c_arbiter_io_axi_b_ready; // @[top.scala 56:20]
  assign h_data_control_io_rs1_data = f_gpr_io_rdata_rs1; // @[top.scala 78:30]
  assign h_data_control_io_rs2_data = f_gpr_io_rdata_rs2; // @[top.scala 79:30]
  assign h_data_control_io_imm = e_imm_io_imm; // @[top.scala 80:25]
  assign h_data_control_io_mem_data = c_arbiter_io_gpr_data; // @[top.scala 81:30]
  assign h_data_control_io_pc_count = b_ifu_io_rd_Req_bits_addr; // @[top.scala 83:30]
  assign h_data_control_io_data_control = d_idu_io_data_control; // @[top.scala 82:34]
  assign i_alu_io_in_a = h_data_control_io_data_1; // @[top.scala 85:17]
  assign i_alu_io_in_b = h_data_control_io_data_2; // @[top.scala 86:17]
  assign i_alu_io_sw = d_idu_io_ALU_ctrl; // @[top.scala 87:15]
  assign j_pc_next_io_rs1_data = f_gpr_io_rdata_rs1; // @[top.scala 72:25]
  assign j_pc_next_io_rs2_data = f_gpr_io_rdata_rs2; // @[top.scala 73:25]
  assign j_pc_next_io_instruction = c_arbiter_io_inst; // @[top.scala 74:28]
  assign j_pc_next_io_pc_next_type = d_idu_io_pc_next_type; // @[top.scala 76:29]
  assign j_pc_next_io_pc_count = b_ifu_io_rd_Req_bits_addr; // @[top.scala 75:25]

  assign l_uart_clock = clock;
  assign l_uart_reset = reset;
  assign l_uart_io_aw_valid = c_arbiter_io_axi_aw_valid_uart; // @[top.scala 93:22]
  assign l_uart_io_w_valid = c_arbiter_io_axi_w_valid_uart; // @[top.scala 94:21]
  assign l_uart_io_waddr = c_arbiter_io_axi_aw_addr_uart; // @[top.scala 95:19]
  assign l_uart_io_wdata = c_arbiter_io_axi_w_data_uart; // @[top.scala 96:19]

  assign m_clint_clock = clock;
  assign m_clint_reset = reset;
  assign m_clint_io_ar_valid = c_arbiter_io_axi_ar_valid_clint; // @[top.scala 104:23]
  assign m_clint_io_raddr = c_arbiter_io_axi_ar_addr_clint; // @[top.scala 105:20]
  assign m_clint_io_r_mask = c_arbiter_io_axi_ar_strb_clint; // @[top.scala 106:21]
  assign m_clint_io_r_valid = c_arbiter_io_is_r; // @[top.scala 107:22]
  assign m_clint_io_r__ready = c_arbiter_io_axi_r_ready_clint; // @[top.scala 108:22]
endmodule
