module top(
  input   clock,
  input   reset,
  output  io_is_unknown_instruction,
  output  carry,
  output  overflow
);
  wire  b_ifu_clock; // @[top.scala 12:22]
  wire  b_ifu_reset; // @[top.scala 12:22]
  wire  b_ifu_io_addr_Req_ready; // @[top.scala 12:22]
  wire  b_ifu_io_addr_Req_valid; // @[top.scala 12:22]
  wire [31:0] b_ifu_io_addr_Req_bits_addr; // @[top.scala 12:22]
  wire  b_ifu_io_sramReq_ready; // @[top.scala 12:22]
  wire  b_ifu_io_sramReq_valid; // @[top.scala 12:22]
  wire [31:0] b_ifu_io_sramReq_bits_addr; // @[top.scala 12:22]
  wire  c_sram_clock; // @[top.scala 13:22]
  wire  c_sram_reset; // @[top.scala 13:22]
  wire  c_sram_io_req_ready; // @[top.scala 13:22]
  wire  c_sram_io_req_valid; // @[top.scala 13:22]
  wire [31:0] c_sram_io_req_bits_addr; // @[top.scala 13:22]
  wire  c_sram_io_iduReq_ready; // @[top.scala 13:22]
  wire  c_sram_io_iduReq_valid; // @[top.scala 13:22]
  wire [31:0] c_sram_io_iduReq_bits_inst; // @[top.scala 13:22]
  wire [31:0] c_sram_io_iduReq_bits_pc; // @[top.scala 13:22]
  wire  d_idu_clock; // @[top.scala 14:21]
  wire  d_idu_reset; // @[top.scala 14:21]
  wire  d_idu_io_inst_req_ready; // @[top.scala 14:21]
  wire  d_idu_io_inst_req_valid; // @[top.scala 14:21]
  wire [31:0] d_idu_io_inst_req_bits_inst; // @[top.scala 14:21]
  wire [31:0] d_idu_io_inst_req_bits_pc; // @[top.scala 14:21]
  wire [2:0] d_idu_io_imm_type; // @[top.scala 14:21]
  wire [4:0] d_idu_io_rs1; // @[top.scala 14:21]
  wire [4:0] d_idu_io_rs2; // @[top.scala 14:21]
  wire [4:0] d_idu_io_rd; // @[top.scala 14:21]
  wire  d_idu_io_ready; // @[top.scala 14:21]
  wire  d_idu_io_valid; // @[top.scala 14:21]
  wire [2:0] d_idu_io_data_control; // @[top.scala 14:21]
  wire [3:0] d_idu_io_ALU_ctrl; // @[top.scala 14:21]
  wire [3:0] d_idu_io_pc_next_type; // @[top.scala 14:21]
  wire [31:0] d_idu_io_instruction_o; // @[top.scala 14:21]
  wire [31:0] d_idu_io_pc_o; // @[top.scala 14:21]
  wire [31:0] e_imm_io_instruction; // @[top.scala 15:21]
  wire [2:0] e_imm_io_imm_type; // @[top.scala 15:21]
  wire [31:0] e_imm_io_imm; // @[top.scala 15:21]
  wire  f_gpr_clock; // @[top.scala 16:21]
  wire  f_gpr_reset; // @[top.scala 16:21]
  wire  f_gpr_io_rd_Req_ready; // @[top.scala 16:21]
  wire  f_gpr_io_rd_Req_valid; // @[top.scala 16:21]
  wire [4:0] f_gpr_io_rd_Req_bits_rd_addr; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rd_Req_bits_rd_data; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rd_Req_bits_rs1_data; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rd_Req_bits_rs2_data; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rd_Req_bits_instruction; // @[top.scala 16:21]
  wire [3:0] f_gpr_io_rd_Req_bits_pc_next_type; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rd_Req_bits_pc_count; // @[top.scala 16:21]
  wire  f_gpr_io_pcnext_Req_ready; // @[top.scala 16:21]
  wire  f_gpr_io_pcnext_Req_valid; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_pcnext_Req_bits_rs1_data; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_pcnext_Req_bits_rs2_data; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_pcnext_Req_bits_instruction; // @[top.scala 16:21]
  wire [3:0] f_gpr_io_pcnext_Req_bits_pc_next_type; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_pcnext_Req_bits_pc_count; // @[top.scala 16:21]
  wire [4:0] f_gpr_io_raddr_rs1; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rdata_rs1; // @[top.scala 16:21]
  wire [4:0] f_gpr_io_raddr_rs2; // @[top.scala 16:21]
  wire [31:0] f_gpr_io_rdata_rs2; // @[top.scala 16:21]
  wire [31:0] g_mem_io_inst; // @[top.scala 17:21]
  wire [31:0] g_mem_io_rs1; // @[top.scala 17:21]
  wire [31:0] g_mem_io_rs2; // @[top.scala 17:21]
  wire [31:0] g_mem_io_imm; // @[top.scala 17:21]
  wire [31:0] g_mem_io_mem_data; // @[top.scala 17:21]
  wire [3:0] h_data_control_io_sw; // @[top.scala 18:30]
  wire [4:0] h_data_control_io_rd_addr; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_rs1_data; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_rs2_data; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_instruction; // @[top.scala 18:30]
  wire [3:0] h_data_control_io_pc_next_type; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_imm; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_mem_data; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_pc_count; // @[top.scala 18:30]
  wire [2:0] h_data_control_io_data_control; // @[top.scala 18:30]
  wire  h_data_control_io_alu_Req_ready; // @[top.scala 18:30]
  wire  h_data_control_io_alu_Req_valid; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_alu_Req_bits_data1; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_alu_Req_bits_data2; // @[top.scala 18:30]
  wire [3:0] h_data_control_io_alu_Req_bits_sw; // @[top.scala 18:30]
  wire [4:0] h_data_control_io_alu_Req_bits_addr; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_alu_Req_bits_rs1_data; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_alu_Req_bits_rs2_data; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_alu_Req_bits_instruction; // @[top.scala 18:30]
  wire [3:0] h_data_control_io_alu_Req_bits_pc_next_type; // @[top.scala 18:30]
  wire [31:0] h_data_control_io_alu_Req_bits_pc_count; // @[top.scala 18:30]
  wire  h_data_control_io_ready; // @[top.scala 18:30]
  wire  h_data_control_io_valid; // @[top.scala 18:30]
  wire  i_alu_clock; // @[top.scala 19:21]
  wire  i_alu_reset; // @[top.scala 19:21]
  wire  i_alu_io_alu_Req_ready; // @[top.scala 19:21]
  wire  i_alu_io_alu_Req_valid; // @[top.scala 19:21]
  wire [31:0] i_alu_io_alu_Req_bits_data1; // @[top.scala 19:21]
  wire [31:0] i_alu_io_alu_Req_bits_data2; // @[top.scala 19:21]
  wire [3:0] i_alu_io_alu_Req_bits_sw; // @[top.scala 19:21]
  wire [4:0] i_alu_io_alu_Req_bits_addr; // @[top.scala 19:21]
  wire [31:0] i_alu_io_alu_Req_bits_rs1_data; // @[top.scala 19:21]
  wire [31:0] i_alu_io_alu_Req_bits_rs2_data; // @[top.scala 19:21]
  wire [31:0] i_alu_io_alu_Req_bits_instruction; // @[top.scala 19:21]
  wire [3:0] i_alu_io_alu_Req_bits_pc_next_type; // @[top.scala 19:21]
  wire [31:0] i_alu_io_alu_Req_bits_pc_count; // @[top.scala 19:21]
  wire  i_alu_io_rd_Req_ready; // @[top.scala 19:21]
  wire  i_alu_io_rd_Req_valid; // @[top.scala 19:21]
  wire [4:0] i_alu_io_rd_Req_bits_rd_addr; // @[top.scala 19:21]
  wire [31:0] i_alu_io_rd_Req_bits_rd_data; // @[top.scala 19:21]
  wire [31:0] i_alu_io_rd_Req_bits_rs1_data; // @[top.scala 19:21]
  wire [31:0] i_alu_io_rd_Req_bits_rs2_data; // @[top.scala 19:21]
  wire [31:0] i_alu_io_rd_Req_bits_instruction; // @[top.scala 19:21]
  wire [3:0] i_alu_io_rd_Req_bits_pc_next_type; // @[top.scala 19:21]
  wire [31:0] i_alu_io_rd_Req_bits_pc_count; // @[top.scala 19:21]
  wire  j_pc_next_clock; // @[top.scala 20:25]
  wire  j_pc_next_reset; // @[top.scala 20:25]
  wire  j_pc_next_io_pcnext_Req_ready; // @[top.scala 20:25]
  wire  j_pc_next_io_pcnext_Req_valid; // @[top.scala 20:25]
  wire [31:0] j_pc_next_io_pcnext_Req_bits_rs1_data; // @[top.scala 20:25]
  wire [31:0] j_pc_next_io_pcnext_Req_bits_rs2_data; // @[top.scala 20:25]
  wire [31:0] j_pc_next_io_pcnext_Req_bits_instruction; // @[top.scala 20:25]
  wire [3:0] j_pc_next_io_pcnext_Req_bits_pc_next_type; // @[top.scala 20:25]
  wire [31:0] j_pc_next_io_pcnext_Req_bits_pc_count; // @[top.scala 20:25]
  wire  j_pc_next_io_is_unknown_instruction; // @[top.scala 20:25]
  wire  j_pc_next_io_IFUReq_ready; // @[top.scala 20:25]
  wire  j_pc_next_io_IFUReq_valid; // @[top.scala 20:25]
  wire [31:0] j_pc_next_io_IFUReq_bits_addr; // @[top.scala 20:25]
  ysyx_25030077_IFU b_ifu ( // @[top.scala 12:22]
    .clock(b_ifu_clock),
    .reset(b_ifu_reset),
    .io_addr_Req_ready(b_ifu_io_addr_Req_ready),
    .io_addr_Req_valid(b_ifu_io_addr_Req_valid),
    .io_addr_Req_bits_addr(b_ifu_io_addr_Req_bits_addr),
    .io_sramReq_ready(b_ifu_io_sramReq_ready),
    .io_sramReq_valid(b_ifu_io_sramReq_valid),
    .io_sramReq_bits_addr(b_ifu_io_sramReq_bits_addr)
  );
  ysyx_25030077_sram c_sram ( // @[top.scala 13:22]
    .clock(c_sram_clock),
    .reset(c_sram_reset),
    .io_req_ready(c_sram_io_req_ready),
    .io_req_valid(c_sram_io_req_valid),
    .io_req_bits_addr(c_sram_io_req_bits_addr),
    .io_iduReq_ready(c_sram_io_iduReq_ready),
    .io_iduReq_valid(c_sram_io_iduReq_valid),
    .io_iduReq_bits_inst(c_sram_io_iduReq_bits_inst),
    .io_iduReq_bits_pc(c_sram_io_iduReq_bits_pc)
  );
  wire is_break_out_o;
  ysyx_25030077_IDU d_idu ( // @[top.scala 14:21]
    .clock(d_idu_clock),
    .reset(d_idu_reset),
    .io_inst_req_ready(d_idu_io_inst_req_ready),
    .io_inst_req_valid(d_idu_io_inst_req_valid),
    .io_inst_req_bits_inst(d_idu_io_inst_req_bits_inst),
    .io_inst_req_bits_pc(d_idu_io_inst_req_bits_pc),
    .io_imm_type(d_idu_io_imm_type),
    .io_rs1(d_idu_io_rs1),
    .io_rs2(d_idu_io_rs2),
    .io_rd(d_idu_io_rd),
    .io_ready(d_idu_io_ready),
    .io_valid(d_idu_io_valid),
    .io_data_control(d_idu_io_data_control),
    .io_ALU_ctrl(d_idu_io_ALU_ctrl),
    .io_pc_next_type(d_idu_io_pc_next_type),
    .io_instruction_o(d_idu_io_instruction_o),
    .io_pc_o(d_idu_io_pc_o),
    .is_break_out(is_break_out_o)
  );
  ysyx_25030077_Imm e_imm ( // @[top.scala 15:21]
    .io_instruction(e_imm_io_instruction),
    .io_imm_type(e_imm_io_imm_type),
    .io_imm(e_imm_io_imm)
  );
  ysyx_25030077_reg f_gpr ( // @[top.scala 16:21]
    .clock(f_gpr_clock),
    .reset(f_gpr_reset),
    .io_rd_Req_ready(f_gpr_io_rd_Req_ready),
    .io_rd_Req_valid(f_gpr_io_rd_Req_valid),
    .io_rd_Req_bits_rd_addr(f_gpr_io_rd_Req_bits_rd_addr),
    .io_rd_Req_bits_rd_data(f_gpr_io_rd_Req_bits_rd_data),
    .io_rd_Req_bits_rs1_data(f_gpr_io_rd_Req_bits_rs1_data),
    .io_rd_Req_bits_rs2_data(f_gpr_io_rd_Req_bits_rs2_data),
    .io_rd_Req_bits_instruction(f_gpr_io_rd_Req_bits_instruction),
    .io_rd_Req_bits_pc_next_type(f_gpr_io_rd_Req_bits_pc_next_type),
    .io_rd_Req_bits_pc_count(f_gpr_io_rd_Req_bits_pc_count),
    .io_pcnext_Req_ready(f_gpr_io_pcnext_Req_ready),
    .io_pcnext_Req_valid(f_gpr_io_pcnext_Req_valid),
    .io_pcnext_Req_bits_rs1_data(f_gpr_io_pcnext_Req_bits_rs1_data),
    .io_pcnext_Req_bits_rs2_data(f_gpr_io_pcnext_Req_bits_rs2_data),
    .io_pcnext_Req_bits_instruction(f_gpr_io_pcnext_Req_bits_instruction),
    .io_pcnext_Req_bits_pc_next_type(f_gpr_io_pcnext_Req_bits_pc_next_type),
    .io_pcnext_Req_bits_pc_count(f_gpr_io_pcnext_Req_bits_pc_count),
    .io_raddr_rs1(f_gpr_io_raddr_rs1),
    .io_rdata_rs1(f_gpr_io_rdata_rs1),
    .io_raddr_rs2(f_gpr_io_raddr_rs2),
    .io_rdata_rs2(f_gpr_io_rdata_rs2)
  );
  ysyx_25030077_MEM_read g_mem ( // @[top.scala 17:21]
    .io_inst(g_mem_io_inst),
    .io_rs1(g_mem_io_rs1),
    .io_rs2(g_mem_io_rs2),
    .io_imm(g_mem_io_imm),
    .io_mem_data(g_mem_io_mem_data)
  );
  ysyx_25030077_DATA_CONTROL h_data_control ( // @[top.scala 18:30]
    .io_sw(h_data_control_io_sw),
    .io_rd_addr(h_data_control_io_rd_addr),
    .io_rs1_data(h_data_control_io_rs1_data),
    .io_rs2_data(h_data_control_io_rs2_data),
    .io_instruction(h_data_control_io_instruction),
    .io_pc_next_type(h_data_control_io_pc_next_type),
    .io_imm(h_data_control_io_imm),
    .io_mem_data(h_data_control_io_mem_data),
    .io_pc_count(h_data_control_io_pc_count),
    .io_data_control(h_data_control_io_data_control),
    .io_alu_Req_ready(h_data_control_io_alu_Req_ready),
    .io_alu_Req_valid(h_data_control_io_alu_Req_valid),
    .io_alu_Req_bits_data1(h_data_control_io_alu_Req_bits_data1),
    .io_alu_Req_bits_data2(h_data_control_io_alu_Req_bits_data2),
    .io_alu_Req_bits_sw(h_data_control_io_alu_Req_bits_sw),
    .io_alu_Req_bits_addr(h_data_control_io_alu_Req_bits_addr),
    .io_alu_Req_bits_rs1_data(h_data_control_io_alu_Req_bits_rs1_data),
    .io_alu_Req_bits_rs2_data(h_data_control_io_alu_Req_bits_rs2_data),
    .io_alu_Req_bits_instruction(h_data_control_io_alu_Req_bits_instruction),
    .io_alu_Req_bits_pc_next_type(h_data_control_io_alu_Req_bits_pc_next_type),
    .io_alu_Req_bits_pc_count(h_data_control_io_alu_Req_bits_pc_count),
    .io_ready(h_data_control_io_ready),
    .io_valid(h_data_control_io_valid)
  );
  ysyx_25030077_ALU i_alu ( // @[top.scala 19:21]
    .clock(i_alu_clock),
    .reset(i_alu_reset),
    .io_alu_Req_ready(i_alu_io_alu_Req_ready),
    .io_alu_Req_valid(i_alu_io_alu_Req_valid),
    .io_alu_Req_bits_data1(i_alu_io_alu_Req_bits_data1),
    .io_alu_Req_bits_data2(i_alu_io_alu_Req_bits_data2),
    .io_alu_Req_bits_sw(i_alu_io_alu_Req_bits_sw),
    .io_alu_Req_bits_addr(i_alu_io_alu_Req_bits_addr),
    .io_alu_Req_bits_rs1_data(i_alu_io_alu_Req_bits_rs1_data),
    .io_alu_Req_bits_rs2_data(i_alu_io_alu_Req_bits_rs2_data),
    .io_alu_Req_bits_instruction(i_alu_io_alu_Req_bits_instruction),
    .io_alu_Req_bits_pc_next_type(i_alu_io_alu_Req_bits_pc_next_type),
    .io_alu_Req_bits_pc_count(i_alu_io_alu_Req_bits_pc_count),
    .io_rd_Req_ready(i_alu_io_rd_Req_ready),
    .io_rd_Req_valid(i_alu_io_rd_Req_valid),
    .io_rd_Req_bits_rd_addr(i_alu_io_rd_Req_bits_rd_addr),
    .io_rd_Req_bits_rd_data(i_alu_io_rd_Req_bits_rd_data),
    .io_rd_Req_bits_rs1_data(i_alu_io_rd_Req_bits_rs1_data),
    .io_rd_Req_bits_rs2_data(i_alu_io_rd_Req_bits_rs2_data),
    .io_rd_Req_bits_instruction(i_alu_io_rd_Req_bits_instruction),
    .io_rd_Req_bits_pc_next_type(i_alu_io_rd_Req_bits_pc_next_type),
    .io_rd_Req_bits_pc_count(i_alu_io_rd_Req_bits_pc_count),
    .io_carry(carry),
    .io_overflow(overflow)
  );
  ysyx_25030077_PC_next j_pc_next ( // @[top.scala 20:25]
    .clock(j_pc_next_clock),
    .reset(j_pc_next_reset),
    .io_pcnext_Req_ready(j_pc_next_io_pcnext_Req_ready),
    .io_pcnext_Req_valid(j_pc_next_io_pcnext_Req_valid),
    .io_pcnext_Req_bits_rs1_data(j_pc_next_io_pcnext_Req_bits_rs1_data),
    .io_pcnext_Req_bits_rs2_data(j_pc_next_io_pcnext_Req_bits_rs2_data),
    .io_pcnext_Req_bits_instruction(j_pc_next_io_pcnext_Req_bits_instruction),
    .io_pcnext_Req_bits_pc_next_type(j_pc_next_io_pcnext_Req_bits_pc_next_type),
    .io_pcnext_Req_bits_pc_count(j_pc_next_io_pcnext_Req_bits_pc_count),
    .io_is_unknown_instruction(j_pc_next_io_is_unknown_instruction),
    .io_IFUReq_ready(j_pc_next_io_IFUReq_ready),
    .io_IFUReq_valid(j_pc_next_io_IFUReq_valid),
    .io_IFUReq_bits_addr(j_pc_next_io_IFUReq_bits_addr)
  );
  ysyx_25030077_EXIT k_EXIT(
    .clock(clock),
    .reset(reset),
    .io_Pc_count(d_idu_io_pc_o),
    .is_break_out(is_break_out_o),
    .is_unknown_instruction(j_pc_next_io_is_unknown_instruction)
  );
  assign io_is_unknown_instruction = j_pc_next_io_is_unknown_instruction; // @[top.scala 61:29]

  assign b_ifu_clock = clock;
  assign b_ifu_reset = reset;
  assign b_ifu_io_addr_Req_valid = j_pc_next_io_IFUReq_valid; // @[top.scala 22:23]
  assign b_ifu_io_addr_Req_bits_addr = j_pc_next_io_IFUReq_bits_addr; // @[top.scala 22:23]
  assign b_ifu_io_sramReq_ready = c_sram_io_req_ready; // @[top.scala 24:20]
  assign c_sram_clock = clock;
  assign c_sram_reset = reset;
  assign c_sram_io_req_valid = b_ifu_io_sramReq_valid; // @[top.scala 24:20]
  assign c_sram_io_req_bits_addr = b_ifu_io_sramReq_bits_addr; // @[top.scala 24:20]
  assign c_sram_io_iduReq_ready = d_idu_io_inst_req_ready; // @[top.scala 26:20]
  assign d_idu_clock = clock;
  assign d_idu_reset = reset;
  assign d_idu_io_inst_req_valid = c_sram_io_iduReq_valid; // @[top.scala 26:20]
  assign d_idu_io_inst_req_bits_inst = c_sram_io_iduReq_bits_inst; // @[top.scala 26:20]
  assign d_idu_io_inst_req_bits_pc = c_sram_io_iduReq_bits_pc; // @[top.scala 26:20]
  assign d_idu_io_ready = h_data_control_io_ready; // @[top.scala 51:18]
  assign e_imm_io_instruction = d_idu_io_instruction_o; // @[top.scala 28:24]
  assign e_imm_io_imm_type = d_idu_io_imm_type; // @[top.scala 29:21]
  assign f_gpr_clock = clock;
  assign f_gpr_reset = reset;
  assign f_gpr_io_rd_Req_valid = i_alu_io_rd_Req_valid; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_rd_addr = i_alu_io_rd_Req_bits_rd_addr; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_rd_data = i_alu_io_rd_Req_bits_rd_data; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_rs1_data = i_alu_io_rd_Req_bits_rs1_data; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_rs2_data = i_alu_io_rd_Req_bits_rs2_data; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_instruction = i_alu_io_rd_Req_bits_instruction; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_pc_next_type = i_alu_io_rd_Req_bits_pc_next_type; // @[top.scala 56:19]
  assign f_gpr_io_rd_Req_bits_pc_count = i_alu_io_rd_Req_bits_pc_count; // @[top.scala 56:19]
  assign f_gpr_io_pcnext_Req_ready = j_pc_next_io_pcnext_Req_ready; // @[top.scala 58:27]
  assign f_gpr_io_raddr_rs1 = d_idu_io_rs1; // @[top.scala 31:22]
  assign f_gpr_io_raddr_rs2 = d_idu_io_rs2; // @[top.scala 32:22]
  assign g_mem_io_inst = d_idu_io_instruction_o; // @[top.scala 34:17]
  assign g_mem_io_rs1 = f_gpr_io_rdata_rs1; // @[top.scala 35:16]
  assign g_mem_io_rs2 = f_gpr_io_rdata_rs2; // @[top.scala 36:16]
  assign g_mem_io_imm = e_imm_io_imm; // @[top.scala 37:16]
  assign h_data_control_io_sw = d_idu_io_ALU_ctrl; // @[top.scala 43:24]
  assign h_data_control_io_rd_addr = d_idu_io_rd; // @[top.scala 39:29]
  assign h_data_control_io_rs1_data = f_gpr_io_rdata_rs1; // @[top.scala 40:30]
  assign h_data_control_io_rs2_data = f_gpr_io_rdata_rs2; // @[top.scala 41:30]
  assign h_data_control_io_instruction = d_idu_io_instruction_o; // @[top.scala 48:33]
  assign h_data_control_io_pc_next_type = d_idu_io_pc_next_type; // @[top.scala 47:34]
  assign h_data_control_io_imm = e_imm_io_imm; // @[top.scala 42:25]
  assign h_data_control_io_mem_data = g_mem_io_mem_data; // @[top.scala 44:30]
  assign h_data_control_io_pc_count = d_idu_io_pc_o; // @[top.scala 46:30]
  assign h_data_control_io_data_control = d_idu_io_data_control; // @[top.scala 45:34]
  assign h_data_control_io_alu_Req_ready = i_alu_io_alu_Req_ready; // @[top.scala 54:20]
  assign h_data_control_io_valid = d_idu_io_valid; // @[top.scala 50:27]
  assign i_alu_clock = clock;
  assign i_alu_reset = reset;
  assign i_alu_io_alu_Req_valid = h_data_control_io_alu_Req_valid; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_data1 = h_data_control_io_alu_Req_bits_data1; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_data2 = h_data_control_io_alu_Req_bits_data2; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_sw = h_data_control_io_alu_Req_bits_sw; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_addr = h_data_control_io_alu_Req_bits_addr; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_rs1_data = h_data_control_io_alu_Req_bits_rs1_data; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_rs2_data = h_data_control_io_alu_Req_bits_rs2_data; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_instruction = h_data_control_io_alu_Req_bits_instruction; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_pc_next_type = h_data_control_io_alu_Req_bits_pc_next_type; // @[top.scala 54:20]
  assign i_alu_io_alu_Req_bits_pc_count = h_data_control_io_alu_Req_bits_pc_count; // @[top.scala 54:20]
  assign i_alu_io_rd_Req_ready = f_gpr_io_rd_Req_ready; // @[top.scala 56:19]
  assign j_pc_next_clock = clock;
  assign j_pc_next_reset = reset;
  assign j_pc_next_io_pcnext_Req_valid = f_gpr_io_pcnext_Req_valid; // @[top.scala 58:27]
  assign j_pc_next_io_pcnext_Req_bits_rs1_data = f_gpr_io_pcnext_Req_bits_rs1_data; // @[top.scala 58:27]
  assign j_pc_next_io_pcnext_Req_bits_rs2_data = f_gpr_io_pcnext_Req_bits_rs2_data; // @[top.scala 58:27]
  assign j_pc_next_io_pcnext_Req_bits_instruction = f_gpr_io_pcnext_Req_bits_instruction; // @[top.scala 58:27]
  assign j_pc_next_io_pcnext_Req_bits_pc_next_type = f_gpr_io_pcnext_Req_bits_pc_next_type; // @[top.scala 58:27]
  assign j_pc_next_io_pcnext_Req_bits_pc_count = f_gpr_io_pcnext_Req_bits_pc_count; // @[top.scala 58:27]
  assign j_pc_next_io_IFUReq_ready = b_ifu_io_addr_Req_ready; // @[top.scala 22:23]
endmodule