module Queue(
  input         clock,
  input         reset,
  output        io_enq_ready,
  input         io_enq_valid,
  input  [31:0] io_enq_bits_addr,
  input         io_deq_ready,
  output        io_deq_valid,
  output [31:0] io_deq_bits_addr
);
  reg [31:0] ram_addr [0:0]; // @[Decoupled.scala 259:95]
  wire  ram_addr_io_deq_bits_MPORT_en; // @[Decoupled.scala 259:95]
  wire  ram_addr_io_deq_bits_MPORT_addr; // @[Decoupled.scala 259:95]
  wire [31:0] ram_addr_io_deq_bits_MPORT_data; // @[Decoupled.scala 259:95]
  wire [31:0] ram_addr_MPORT_data; // @[Decoupled.scala 259:95]
  wire  ram_addr_MPORT_addr; // @[Decoupled.scala 259:95]
  wire  ram_addr_MPORT_mask; // @[Decoupled.scala 259:95]
  wire  ram_addr_MPORT_en; // @[Decoupled.scala 259:95]
  reg  maybe_full; // @[Decoupled.scala 262:27]
  wire  empty = ~maybe_full; // @[Decoupled.scala 264:28]
  wire  do_enq = io_enq_ready & io_enq_valid; // @[Decoupled.scala 50:35]
  wire  do_deq = io_deq_ready & io_deq_valid; // @[Decoupled.scala 50:35]
  assign ram_addr_io_deq_bits_MPORT_en = 1'h1;
  assign ram_addr_io_deq_bits_MPORT_addr = 1'h0;
  assign ram_addr_io_deq_bits_MPORT_data = ram_addr[ram_addr_io_deq_bits_MPORT_addr]; // @[Decoupled.scala 259:95]
  assign ram_addr_MPORT_data = io_enq_bits_addr;
  assign ram_addr_MPORT_addr = 1'h0;
  assign ram_addr_MPORT_mask = 1'h1;
  assign ram_addr_MPORT_en = io_enq_ready & io_enq_valid;
  assign io_enq_ready = ~maybe_full; // @[Decoupled.scala 289:19]
  assign io_deq_valid = ~empty; // @[Decoupled.scala 288:19]
  assign io_deq_bits_addr = ram_addr_io_deq_bits_MPORT_data; // @[Decoupled.scala 296:17]
  always @(posedge clock) begin
    if (ram_addr_MPORT_en & ram_addr_MPORT_mask) begin
      ram_addr[ram_addr_MPORT_addr] <= ram_addr_MPORT_data; // @[Decoupled.scala 259:95]
    end
    if (reset) begin // @[Decoupled.scala 262:27]
      maybe_full <= 1'h0; // @[Decoupled.scala 262:27]
    end else if (do_enq != do_deq) begin // @[Decoupled.scala 279:27]
      maybe_full <= do_enq; // @[Decoupled.scala 280:16]
    end
  end
endmodule
module ysyx_25030077_IFU(
  input         clock,
  input         reset,
  output        io_rd_Req_ready,
  input         io_rd_Req_valid,
  input  [31:0] io_rd_Req_bits_addr,
  input         io_ar_ready,
  output        io_ar_valid,
  output [31:0] io_ar_bits_addr
);
  export "DPI-C" function pc_read_data;
  function int pc_read_data();
    return {io_ar_bits_addr};
  endfunction
  wire  reqQ_clock; // @[Decoupled.scala 361:21]
  wire  reqQ_reset; // @[Decoupled.scala 361:21]
  wire  reqQ_io_enq_ready; // @[Decoupled.scala 361:21]
  wire  reqQ_io_enq_valid; // @[Decoupled.scala 361:21]
  wire [31:0] reqQ_io_enq_bits_addr; // @[Decoupled.scala 361:21]
  wire  reqQ_io_deq_ready; // @[Decoupled.scala 361:21]
  wire  reqQ_io_deq_valid; // @[Decoupled.scala 361:21]
  wire [31:0] reqQ_io_deq_bits_addr; // @[Decoupled.scala 361:21]
  Queue reqQ ( // @[Decoupled.scala 361:21]
    .clock(reqQ_clock),
    .reset(reqQ_reset),
    .io_enq_ready(reqQ_io_enq_ready),
    .io_enq_valid(reqQ_io_enq_valid),
    .io_enq_bits_addr(reqQ_io_enq_bits_addr),
    .io_deq_ready(reqQ_io_deq_ready),
    .io_deq_valid(reqQ_io_deq_valid),
    .io_deq_bits_addr(reqQ_io_deq_bits_addr)
  );
  assign io_rd_Req_ready = reqQ_io_enq_ready; // @[Decoupled.scala 365:17]
  assign io_ar_valid = reqQ_io_deq_valid; // @[ysyx_25030077_IFU.scala 13:15]
  assign io_ar_bits_addr = reqQ_io_deq_bits_addr; // @[ysyx_25030077_IFU.scala 14:19]
  assign reqQ_clock = clock;
  assign reqQ_reset = reset;
  assign reqQ_io_enq_valid = io_rd_Req_valid; // @[Decoupled.scala 363:22]
  assign reqQ_io_enq_bits_addr = io_rd_Req_bits_addr; // @[Decoupled.scala 364:21]
  assign reqQ_io_deq_ready = io_ar_ready; // @[ysyx_25030077_IFU.scala 15:14]
endmodule
module ysyx_25030077_arbiter(
  input         clock,
  input         reset,
  input         io_ifu_valid,
  input  [2:0]  io_delay_cnt_mem,
  input  [2:0]  io_delay_cnt_clint,
  input  [31:0] io_pc,
  input  [31:0] io_rs1_data,
  input  [31:0] io_rs2_data,
  input  [31:0] io_imm,
  input  [2:0]  io_r_mask,
  input  [2:0]  io_w_mask,
  output        io_axi_ar_valid_mem,
  output [31:0] io_axi_ar_addr_mem,
  output [2:0]  io_axi_ar_strb_mem,
  input         io_axi_ar_ready_mem,
  output        io_axi_ar_valid_clint,
  output [31:0] io_axi_ar_addr_clint,
  output [2:0]  io_axi_ar_strb_clint,
  input         io_axi_ar_ready_clint,
  output        io_axi_aw_valid_mem,
  output [31:0] io_axi_aw_addr_mem,
  input         io_axi_aw_ready_mem,
  output        io_axi_w_valid_mem,
  output [31:0] io_axi_w_data_mem,
  output [2:0]  io_axi_w_strb_mem,
  input         io_axi_w_ready_mem,
  output        io_axi_aw_valid_uart,
  output [31:0] io_axi_aw_addr_uart,
  input         io_axi_aw_ready_uart,
  output        io_axi_w_valid_uart,
  output [31:0] io_axi_w_data_uart,
  output [2:0]  io_axi_w_strb_uart,
  input         io_axi_w_ready_uart,
  input         io_axi_r_valid_mem,
  input  [31:0] io_axi_r_data_mem,
  output        io_axi_r_ready_mem,
  input         io_axi_r_valid_clint,
  input  [31:0] io_axi_r_data_clint,
  output        io_axi_r_ready_clint,
  input         io_axi_b_valid,
  output        io_axi_b_ready,
  input  [1:0]  io_axi_b_resp,
  output [1:0]  io_gpr_b_resp,
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
  reg [1:0] state_reg; // @[ysyx_25030077_arbiter.scala 73:28]
  reg [31:0] inst_reg; // @[ysyx_25030077_arbiter.scala 74:27]
  wire [32:0] _axi_ar_addr_T = io_rs1_data + io_imm; // @[ysyx_25030077_arbiter.scala 76:44]
  wire  _axi_ar_addr_T_2 = state_reg == 2'h0; // @[ysyx_25030077_arbiter.scala 77:42]
  wire [31:0] axi_ar_addr = _axi_ar_addr_T_2 ? io_pc : _axi_ar_addr_T[31:0]; // @[Mux.scala 101:16]
  wire  _delay_cnt_T_2 = axi_ar_addr == 32'ha0000048 | axi_ar_addr == 32'ha000004c; // @[ysyx_25030077_arbiter.scala 80:58]
  wire [2:0] delay_cnt = axi_ar_addr == 32'ha0000048 | axi_ar_addr == 32'ha000004c ? io_delay_cnt_clint :
    io_delay_cnt_mem; // @[ysyx_25030077_arbiter.scala 80:24]
  wire  axi_r_valid = io_axi_r_valid_mem | io_axi_r_valid_clint; // @[ysyx_25030077_arbiter.scala 81:42]
  wire  axi_ar_ready = _delay_cnt_T_2 ? io_axi_ar_ready_clint : io_axi_ar_ready_mem; // @[ysyx_25030077_arbiter.scala 82:27]
  wire [31:0] axi_r_data = _delay_cnt_T_2 ? io_axi_r_data_clint : io_axi_r_data_mem; // @[ysyx_25030077_arbiter.scala 83:25]
  wire  _state_reg_T_1 = delay_cnt == 3'h1; // @[ysyx_25030077_arbiter.scala 86:46]
  wire  _state_reg_T_3 = state_reg == 2'h1; // @[ysyx_25030077_arbiter.scala 87:20]
  wire [1:0] _state_reg_T_6 = _state_reg_T_1 ? 2'h2 : 2'h1; // @[ysyx_25030077_arbiter.scala 88:71]
  wire  _state_reg_T_7 = ~io_r_valid_lsu; // @[ysyx_25030077_arbiter.scala 89:53]
  wire [1:0] _state_reg_T_10 = axi_r_valid & (io_axi_ar_ready_clint | io_axi_ar_ready_mem) ? 2'h2 : 2'h1; // @[ysyx_25030077_arbiter.scala 89:72]
  wire [1:0] _state_reg_T_11 = _state_reg_T_7 ? _state_reg_T_10 : 2'h0; // @[Mux.scala 101:16]
  wire  _state_reg_T_13 = state_reg == 2'h2; // @[ysyx_25030077_arbiter.scala 91:20]
  wire [1:0] _state_reg_T_15 = axi_r_valid & axi_ar_ready ? 2'h0 : 2'h2; // @[ysyx_25030077_arbiter.scala 91:35]
  wire [31:0] axi_aw_addr = _state_reg_T_3 ? _axi_ar_addr_T[31:0] : 32'h0; // @[Mux.scala 101:16]
  wire  _io_axi_aw_addr_mem_T = axi_aw_addr == 32'ha00003f8; // @[ysyx_25030077_arbiter.scala 97:44]
  wire  axi_aw_valid = _state_reg_T_3 & axi_r_valid; // @[Mux.scala 101:16]
  wire  axi_ar_valid = _axi_ar_addr_T_2 ? io_ifu_valid : axi_aw_valid; // @[Mux.scala 101:16]
  wire [2:0] _axi_ar_strb_T_2 = _state_reg_T_3 ? io_r_mask : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] axi_ar_strb = _axi_ar_addr_T_2 ? 3'h6 : _axi_ar_strb_T_2; // @[Mux.scala 101:16]
  wire [31:0] axi_w_data = _state_reg_T_3 ? io_rs2_data : 32'h0; // @[Mux.scala 101:16]
  wire [2:0] axi_w_strb = _state_reg_T_3 ? io_w_mask : 3'h0; // @[Mux.scala 101:16]
  wire  _inst_reg_T_2 = _state_reg_T_1 & _axi_ar_addr_T_2; // @[ysyx_25030077_arbiter.scala 159:50]
  assign io_axi_ar_valid_mem = _delay_cnt_T_2 ? 1'h0 : axi_ar_valid; // @[ysyx_25030077_arbiter.scala 113:34]
  assign io_axi_ar_addr_mem = _delay_cnt_T_2 ? 32'h80000000 : axi_ar_addr; // @[ysyx_25030077_arbiter.scala 106:33]
  assign io_axi_ar_strb_mem = _delay_cnt_T_2 ? 3'h0 : axi_ar_strb; // @[ysyx_25030077_arbiter.scala 120:33]
  assign io_axi_ar_valid_clint = _delay_cnt_T_2 & axi_ar_valid; // @[ysyx_25030077_arbiter.scala 114:34]
  assign io_axi_ar_addr_clint = _delay_cnt_T_2 ? axi_ar_addr : 32'h80000000; // @[ysyx_25030077_arbiter.scala 107:33]
  assign io_axi_ar_strb_clint = _delay_cnt_T_2 ? axi_ar_strb : 3'h0; // @[ysyx_25030077_arbiter.scala 121:33]
  assign io_axi_aw_valid_mem = _io_axi_aw_addr_mem_T ? 1'h0 : axi_aw_valid; // @[ysyx_25030077_arbiter.scala 103:32]
  assign io_axi_aw_addr_mem = axi_aw_addr == 32'ha00003f8 ? 32'h0 : axi_aw_addr; // @[ysyx_25030077_arbiter.scala 97:31]
  assign io_axi_w_valid_mem = _io_axi_aw_addr_mem_T ? 1'h0 : axi_aw_valid; // @[ysyx_25030077_arbiter.scala 126:31]
  assign io_axi_w_data_mem = _io_axi_aw_addr_mem_T ? 32'h0 : axi_w_data; // @[ysyx_25030077_arbiter.scala 132:30]
  assign io_axi_w_strb_mem = _io_axi_aw_addr_mem_T ? 3'h0 : axi_w_strb; // @[ysyx_25030077_arbiter.scala 138:30]
  assign io_axi_aw_valid_uart = _io_axi_aw_addr_mem_T & axi_aw_valid; // @[ysyx_25030077_arbiter.scala 104:32]
  assign io_axi_aw_addr_uart = _io_axi_aw_addr_mem_T ? 32'ha00003f8 : 32'h0; // @[ysyx_25030077_arbiter.scala 98:31]
  assign io_axi_w_valid_uart = _io_axi_aw_addr_mem_T & axi_aw_valid; // @[ysyx_25030077_arbiter.scala 127:31]
  assign io_axi_w_data_uart = _io_axi_aw_addr_mem_T ? axi_w_data : 32'h0; // @[ysyx_25030077_arbiter.scala 133:30]
  assign io_axi_w_strb_uart = _io_axi_aw_addr_mem_T ? axi_w_strb : 3'h0; // @[ysyx_25030077_arbiter.scala 139:30]
  assign io_axi_r_ready_mem = io_gpr_r_ready; // @[ysyx_25030077_arbiter.scala 142:27]
  assign io_axi_r_ready_clint = io_gpr_r_ready; // @[ysyx_25030077_arbiter.scala 141:27]
  assign io_axi_b_ready = io_gpr_b_ready; // @[ysyx_25030077_arbiter.scala 143:21]
  assign io_gpr_b_resp = _state_reg_T_13 ? io_axi_b_resp : 2'h0; // @[Mux.scala 101:16]
  assign io_gpr_r_valid = _state_reg_T_13 & axi_r_valid; // @[Mux.scala 101:16]
  assign io_gpr_b_valid = _state_reg_T_13 & io_axi_b_valid; // @[Mux.scala 101:16]
  assign io_gpr_data = _state_reg_T_13 ? axi_r_data : 32'h0; // @[Mux.scala 101:16]
  assign io_inst = inst_reg; // @[ysyx_25030077_arbiter.scala 161:21]
  assign io_ifu_ready = io_axi_ar_ready_mem; // @[ysyx_25030077_arbiter.scala 144:21]
  assign io_is_r = _axi_ar_addr_T_2 | _state_reg_T_3 & io_r_valid_lsu; // @[Mux.scala 101:16]
  always @(posedge clock) begin
    if (reset) begin // @[ysyx_25030077_arbiter.scala 73:28]
      state_reg <= 2'h0; // @[ysyx_25030077_arbiter.scala 73:28]
    end else if (_axi_ar_addr_T_2) begin // @[Mux.scala 101:16]
      state_reg <= {{1'd0}, _state_reg_T_1};
    end else if (_state_reg_T_3) begin // @[Mux.scala 101:16]
      if (io_r_valid_lsu) begin // @[Mux.scala 101:16]
        state_reg <= _state_reg_T_6;
      end else begin
        state_reg <= _state_reg_T_11;
      end
    end else if (_state_reg_T_13) begin // @[Mux.scala 101:16]
      state_reg <= _state_reg_T_15;
    end else begin
      state_reg <= 2'h0;
    end
    if (reset) begin // @[ysyx_25030077_arbiter.scala 74:27]
      inst_reg <= 32'h0; // @[ysyx_25030077_arbiter.scala 74:27]
    end else if (_inst_reg_T_2) begin // @[Mux.scala 101:16]
      if (_delay_cnt_T_2) begin // @[ysyx_25030077_arbiter.scala 83:25]
        inst_reg <= io_axi_r_data_clint;
      end else begin
        inst_reg <= io_axi_r_data_mem;
      end
    end
  end
endmodule
module ysyx_25030077_IDU(
  input  [31:0] io_instruction,
  output [2:0]  io_imm_type,
  output [4:0]  io_rs1,
  output [4:0]  io_rs2,
  output [4:0]  io_rd,
  output [2:0]  io_data_control,
  output [3:0]  io_ALU_ctrl,
  output [3:0]  io_pc_next_type,
  output [2:0]  io_r_mask,
  output [2:0]  io_w_mask,
  output        io_r_valid
);
  wire [4:0] addi_Rs1 = io_instruction[19:15]; // @[ysyx_25030077_IDU.scala 30:32]
  wire [4:0] addi_Rd = io_instruction[11:7]; // @[ysyx_25030077_IDU.scala 31:32]
  wire [4:0] sltu_Rs2 = io_instruction[24:20]; // @[ysyx_25030077_IDU.scala 96:33]
  wire [9:0] _isaddi_T_2 = {io_instruction[14:12],io_instruction[6:0]}; // @[Cat.scala 31:58]
  wire  isaddi = _isaddi_T_2 == 10'h13; // @[ysyx_25030077_IDU.scala 294:64]
  wire  isxori = _isaddi_T_2 == 10'h213; // @[ysyx_25030077_IDU.scala 295:64]
  wire  isori = _isaddi_T_2 == 10'h313; // @[ysyx_25030077_IDU.scala 296:64]
  wire  isandi = _isaddi_T_2 == 10'h393; // @[ysyx_25030077_IDU.scala 297:64]
  wire [15:0] _issrai_T_3 = {io_instruction[31:26],io_instruction[14:12],io_instruction[6:0]}; // @[Cat.scala 31:58]
  wire  issrai = _issrai_T_3 == 16'h4293; // @[ysyx_25030077_IDU.scala 298:87]
  wire  issrli = _issrai_T_3 == 16'h293; // @[ysyx_25030077_IDU.scala 299:87]
  wire  isslli = _issrai_T_3 == 16'h93; // @[ysyx_25030077_IDU.scala 300:87]
  wire  issra = _issrai_T_3 == 16'h42b3; // @[ysyx_25030077_IDU.scala 301:87]
  wire  issrl = _issrai_T_3 == 16'h2b3; // @[ysyx_25030077_IDU.scala 302:87]
  wire  isbeq = _isaddi_T_2 == 10'h63; // @[ysyx_25030077_IDU.scala 303:64]
  wire  isbne = _isaddi_T_2 == 10'he3; // @[ysyx_25030077_IDU.scala 304:64]
  wire [16:0] _isadd_T_3 = {io_instruction[31:25],io_instruction[14:12],io_instruction[6:0]}; // @[Cat.scala 31:58]
  wire  isadd = _isadd_T_3 == 17'h33; // @[ysyx_25030077_IDU.scala 305:87]
  wire  isxor = _isadd_T_3 == 17'h233; // @[ysyx_25030077_IDU.scala 306:87]
  wire  isand = _isadd_T_3 == 17'h3b3; // @[ysyx_25030077_IDU.scala 307:87]
  wire  isor = _isadd_T_3 == 17'h333; // @[ysyx_25030077_IDU.scala 308:87]
  wire  issub = _isadd_T_3 == 17'h8033; // @[ysyx_25030077_IDU.scala 309:87]
  wire  islui = io_instruction[6:0] == 7'h37; // @[ysyx_25030077_IDU.scala 310:36]
  wire  isauipc = io_instruction[6:0] == 7'h17; // @[ysyx_25030077_IDU.scala 311:38]
  wire  isjal = io_instruction[6:0] == 7'h6f; // @[ysyx_25030077_IDU.scala 312:36]
  wire  isjalr = _isaddi_T_2 == 10'h67; // @[ysyx_25030077_IDU.scala 313:65]
  wire  issw = _isaddi_T_2 == 10'h123; // @[ysyx_25030077_IDU.scala 314:63]
  wire  isbge = _isaddi_T_2 == 10'h2e3; // @[ysyx_25030077_IDU.scala 315:63]
  wire  isblt = _isaddi_T_2 == 10'h263; // @[ysyx_25030077_IDU.scala 316:63]
  wire  isbltu = _isaddi_T_2 == 10'h363; // @[ysyx_25030077_IDU.scala 317:63]
  wire  isbgeu = _isaddi_T_2 == 10'h3e3; // @[ysyx_25030077_IDU.scala 318:63]
  wire  issb = _isaddi_T_2 == 10'h23; // @[ysyx_25030077_IDU.scala 319:63]
  wire  issh = _isaddi_T_2 == 10'ha3; // @[ysyx_25030077_IDU.scala 320:63]
  wire  islbu = _isaddi_T_2 == 10'h203; // @[ysyx_25030077_IDU.scala 321:63]
  wire  islb = _isaddi_T_2 == 10'h3; // @[ysyx_25030077_IDU.scala 322:63]
  wire  islw = _isaddi_T_2 == 10'h103; // @[ysyx_25030077_IDU.scala 323:63]
  wire  islh = _isaddi_T_2 == 10'h83; // @[ysyx_25030077_IDU.scala 324:63]
  wire  islhu = _isaddi_T_2 == 10'h283; // @[ysyx_25030077_IDU.scala 325:63]
  wire  issll = _isadd_T_3 == 17'hb3; // @[ysyx_25030077_IDU.scala 326:86]
  wire  isslt = _isadd_T_3 == 17'h133; // @[ysyx_25030077_IDU.scala 327:88]
  wire  issltu = _isadd_T_3 == 17'h1b3; // @[ysyx_25030077_IDU.scala 328:88]
  wire  issltiu = _isaddi_T_2 == 10'h193; // @[ysyx_25030077_IDU.scala 329:65]
  wire  isslti = _isaddi_T_2 == 10'h113; // @[ysyx_25030077_IDU.scala 330:65]
  wire  iscsrrw = _isaddi_T_2 == 10'hf3; // @[ysyx_25030077_IDU.scala 331:67]
  wire  iscsrrs = _isaddi_T_2 == 10'h173; // @[ysyx_25030077_IDU.scala 332:67]
  wire  isebreak = io_instruction == 32'h100073; // @[ysyx_25030077_IDU.scala 333:34]
  wire  isecall = io_instruction == 32'h73; // @[ysyx_25030077_IDU.scala 334:34]
  wire  ismret = io_instruction == 32'h30200073; // @[ysyx_25030077_IDU.scala 335:34]
  wire [2:0] _io_imm_type_T = islb ? 3'h1 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_1 = islbu ? 3'h1 : _io_imm_type_T; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_2 = islhu ? 3'h1 : _io_imm_type_T_1; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_3 = islh ? 3'h1 : _io_imm_type_T_2; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_4 = islw ? 3'h1 : _io_imm_type_T_3; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_5 = issh ? 3'h4 : _io_imm_type_T_4; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_6 = issb ? 3'h4 : _io_imm_type_T_5; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_7 = issw ? 3'h4 : _io_imm_type_T_6; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_8 = isjalr ? 3'h3 : _io_imm_type_T_7; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_9 = isjal ? 3'h3 : _io_imm_type_T_8; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_10 = isauipc ? 3'h2 : _io_imm_type_T_9; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_11 = islui ? 3'h2 : _io_imm_type_T_10; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_12 = isslti ? 3'h1 : _io_imm_type_T_11; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_13 = issltiu ? 3'h1 : _io_imm_type_T_12; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_14 = isslli ? 3'h5 : _io_imm_type_T_13; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_15 = issrli ? 3'h5 : _io_imm_type_T_14; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_16 = issrai ? 3'h5 : _io_imm_type_T_15; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_17 = iscsrrs ? 3'h6 : _io_imm_type_T_16; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_18 = iscsrrw ? 3'h6 : _io_imm_type_T_17; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_19 = isandi ? 3'h1 : _io_imm_type_T_18; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_20 = isori ? 3'h1 : _io_imm_type_T_19; // @[Mux.scala 101:16]
  wire [2:0] _io_imm_type_T_21 = isxori ? 3'h1 : _io_imm_type_T_20; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T = isslt ? addi_Rs1 : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_1 = issltu ? addi_Rs1 : _io_rs1_T; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_2 = isbne ? addi_Rs1 : _io_rs1_T_1; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_3 = isbgeu ? addi_Rs1 : _io_rs1_T_2; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_4 = isbltu ? addi_Rs1 : _io_rs1_T_3; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_5 = isblt ? addi_Rs1 : _io_rs1_T_4; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_6 = isbge ? addi_Rs1 : _io_rs1_T_5; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_7 = isbeq ? addi_Rs1 : _io_rs1_T_6; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_8 = issub ? addi_Rs1 : _io_rs1_T_7; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_9 = isor ? addi_Rs1 : _io_rs1_T_8; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_10 = isxor ? addi_Rs1 : _io_rs1_T_9; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_11 = issrl ? addi_Rs1 : _io_rs1_T_10; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_12 = issra ? addi_Rs1 : _io_rs1_T_11; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_13 = issll ? addi_Rs1 : _io_rs1_T_12; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_14 = isand ? addi_Rs1 : _io_rs1_T_13; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_15 = isadd ? addi_Rs1 : _io_rs1_T_14; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_16 = islb ? addi_Rs1 : _io_rs1_T_15; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_17 = islbu ? addi_Rs1 : _io_rs1_T_16; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_18 = islhu ? addi_Rs1 : _io_rs1_T_17; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_19 = islh ? addi_Rs1 : _io_rs1_T_18; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_20 = islw ? addi_Rs1 : _io_rs1_T_19; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_21 = issh ? addi_Rs1 : _io_rs1_T_20; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_22 = issb ? addi_Rs1 : _io_rs1_T_21; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_23 = issw ? addi_Rs1 : _io_rs1_T_22; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_24 = isjalr ? addi_Rs1 : _io_rs1_T_23; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_25 = isslti ? addi_Rs1 : _io_rs1_T_24; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_26 = issltiu ? addi_Rs1 : _io_rs1_T_25; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_27 = isslli ? addi_Rs1 : _io_rs1_T_26; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_28 = issrli ? addi_Rs1 : _io_rs1_T_27; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_29 = issrai ? addi_Rs1 : _io_rs1_T_28; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_30 = iscsrrs ? addi_Rs1 : _io_rs1_T_29; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_31 = iscsrrw ? addi_Rs1 : _io_rs1_T_30; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_32 = isandi ? addi_Rs1 : _io_rs1_T_31; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_33 = isori ? addi_Rs1 : _io_rs1_T_32; // @[Mux.scala 101:16]
  wire [4:0] _io_rs1_T_34 = isxori ? addi_Rs1 : _io_rs1_T_33; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T = isslt ? sltu_Rs2 : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_1 = issltu ? sltu_Rs2 : _io_rs2_T; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_2 = isbne ? sltu_Rs2 : _io_rs2_T_1; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_3 = isbgeu ? sltu_Rs2 : _io_rs2_T_2; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_4 = isbltu ? sltu_Rs2 : _io_rs2_T_3; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_5 = isblt ? sltu_Rs2 : _io_rs2_T_4; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_6 = isbge ? sltu_Rs2 : _io_rs2_T_5; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_7 = isbeq ? sltu_Rs2 : _io_rs2_T_6; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_8 = issub ? sltu_Rs2 : _io_rs2_T_7; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_9 = isor ? sltu_Rs2 : _io_rs2_T_8; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_10 = isxor ? sltu_Rs2 : _io_rs2_T_9; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_11 = issrl ? sltu_Rs2 : _io_rs2_T_10; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_12 = issra ? sltu_Rs2 : _io_rs2_T_11; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_13 = issll ? sltu_Rs2 : _io_rs2_T_12; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_14 = isand ? sltu_Rs2 : _io_rs2_T_13; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_15 = isadd ? sltu_Rs2 : _io_rs2_T_14; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_16 = issh ? sltu_Rs2 : _io_rs2_T_15; // @[Mux.scala 101:16]
  wire [4:0] _io_rs2_T_17 = issb ? sltu_Rs2 : _io_rs2_T_16; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T = isslt ? addi_Rd : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_1 = issltu ? addi_Rd : _io_rd_T; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_2 = issub ? addi_Rd : _io_rd_T_1; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_3 = isor ? addi_Rd : _io_rd_T_2; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_4 = isxor ? addi_Rd : _io_rd_T_3; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_5 = issrl ? addi_Rd : _io_rd_T_4; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_6 = issra ? addi_Rd : _io_rd_T_5; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_7 = issll ? addi_Rd : _io_rd_T_6; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_8 = isand ? addi_Rd : _io_rd_T_7; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_9 = isadd ? addi_Rd : _io_rd_T_8; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_10 = islb ? addi_Rd : _io_rd_T_9; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_11 = islbu ? addi_Rd : _io_rd_T_10; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_12 = islhu ? addi_Rd : _io_rd_T_11; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_13 = islh ? addi_Rd : _io_rd_T_12; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_14 = islw ? addi_Rd : _io_rd_T_13; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_15 = isjalr ? addi_Rd : _io_rd_T_14; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_16 = isjal ? addi_Rd : _io_rd_T_15; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_17 = isauipc ? addi_Rd : _io_rd_T_16; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_18 = islui ? addi_Rd : _io_rd_T_17; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_19 = isslti ? addi_Rd : _io_rd_T_18; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_20 = issltiu ? addi_Rd : _io_rd_T_19; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_21 = isslli ? addi_Rd : _io_rd_T_20; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_22 = issrli ? addi_Rd : _io_rd_T_21; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_23 = issrai ? addi_Rd : _io_rd_T_22; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_24 = iscsrrs ? addi_Rd : _io_rd_T_23; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_25 = iscsrrw ? addi_Rd : _io_rd_T_24; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_26 = isandi ? addi_Rd : _io_rd_T_25; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_27 = isori ? addi_Rd : _io_rd_T_26; // @[Mux.scala 101:16]
  wire [4:0] _io_rd_T_28 = isxori ? addi_Rd : _io_rd_T_27; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T = issltu ? 5'h2 : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_1 = isslt ? 5'ha : _io_ALU_ctrl_T; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_2 = isbne ? 5'h0 : _io_ALU_ctrl_T_1; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_3 = isbgeu ? 5'h0 : _io_ALU_ctrl_T_2; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_4 = isbltu ? 5'h0 : _io_ALU_ctrl_T_3; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_5 = isblt ? 5'h0 : _io_ALU_ctrl_T_4; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_6 = isbge ? 5'h0 : _io_ALU_ctrl_T_5; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_7 = isbeq ? 5'h0 : _io_ALU_ctrl_T_6; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_8 = issub ? 5'h1 : _io_ALU_ctrl_T_7; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_9 = isor ? 5'h3 : _io_ALU_ctrl_T_8; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_10 = isxor ? 5'h4 : _io_ALU_ctrl_T_9; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_11 = issrl ? 5'h9 : _io_ALU_ctrl_T_10; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_12 = issra ? 5'h5 : _io_ALU_ctrl_T_11; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_13 = issll ? 5'h8 : _io_ALU_ctrl_T_12; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_14 = isand ? 5'h6 : _io_ALU_ctrl_T_13; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_15 = isadd ? 5'h0 : _io_ALU_ctrl_T_14; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_16 = islb ? 5'h0 : _io_ALU_ctrl_T_15; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_17 = islbu ? 5'h0 : _io_ALU_ctrl_T_16; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_18 = islhu ? 5'h0 : _io_ALU_ctrl_T_17; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_19 = islh ? 5'h0 : _io_ALU_ctrl_T_18; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_20 = islw ? 5'h0 : _io_ALU_ctrl_T_19; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_21 = issh ? 5'h0 : _io_ALU_ctrl_T_20; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_22 = issb ? 5'h0 : _io_ALU_ctrl_T_21; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_23 = issw ? 5'h0 : _io_ALU_ctrl_T_22; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_24 = isjalr ? 5'h0 : _io_ALU_ctrl_T_23; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_25 = isjal ? 5'h0 : _io_ALU_ctrl_T_24; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_26 = isauipc ? 5'h0 : _io_ALU_ctrl_T_25; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_27 = islui ? 5'h0 : _io_ALU_ctrl_T_26; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_28 = isslti ? 5'ha : _io_ALU_ctrl_T_27; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_29 = issltiu ? 5'h2 : _io_ALU_ctrl_T_28; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_30 = isslli ? 5'h8 : _io_ALU_ctrl_T_29; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_31 = issrli ? 5'h9 : _io_ALU_ctrl_T_30; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_32 = issrai ? 5'h5 : _io_ALU_ctrl_T_31; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_33 = iscsrrs ? 5'hc : _io_ALU_ctrl_T_32; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_34 = iscsrrw ? 5'hb : _io_ALU_ctrl_T_33; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_35 = isandi ? 5'h6 : _io_ALU_ctrl_T_34; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_36 = isori ? 5'h3 : _io_ALU_ctrl_T_35; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_37 = isxori ? 5'h4 : _io_ALU_ctrl_T_36; // @[Mux.scala 101:16]
  wire [4:0] _io_ALU_ctrl_T_38 = isaddi ? 5'h0 : _io_ALU_ctrl_T_37; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T = issltu ? 3'h3 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_1 = isslt ? 3'h3 : _io_data_control_T; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_2 = isbne ? 3'h0 : _io_data_control_T_1; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_3 = isbgeu ? 3'h0 : _io_data_control_T_2; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_4 = isbltu ? 3'h0 : _io_data_control_T_3; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_5 = isblt ? 3'h0 : _io_data_control_T_4; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_6 = isbge ? 3'h0 : _io_data_control_T_5; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_7 = isbeq ? 3'h0 : _io_data_control_T_6; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_8 = issub ? 3'h3 : _io_data_control_T_7; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_9 = isor ? 3'h3 : _io_data_control_T_8; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_10 = isxor ? 3'h3 : _io_data_control_T_9; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_11 = issrl ? 3'h3 : _io_data_control_T_10; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_12 = issra ? 3'h3 : _io_data_control_T_11; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_13 = issll ? 3'h3 : _io_data_control_T_12; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_14 = isand ? 3'h3 : _io_data_control_T_13; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_15 = isadd ? 3'h3 : _io_data_control_T_14; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_16 = islb ? 3'h2 : _io_data_control_T_15; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_17 = islbu ? 3'h2 : _io_data_control_T_16; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_18 = islhu ? 3'h2 : _io_data_control_T_17; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_19 = islh ? 3'h2 : _io_data_control_T_18; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_20 = islw ? 3'h2 : _io_data_control_T_19; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_21 = issh ? 3'h0 : _io_data_control_T_20; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_22 = issb ? 3'h0 : _io_data_control_T_21; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_23 = issw ? 3'h0 : _io_data_control_T_22; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_24 = isjalr ? 3'h1 : _io_data_control_T_23; // @[Mux.scala 101:16]
  wire [2:0] _io_data_control_T_25 = isjal ? 3'h1 : _io_data_control_T_24; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T = isslti ? 4'h0 : 4'h3; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_1 = issltiu ? 4'h0 : _io_pc_next_type_T; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_2 = isslt ? 4'h0 : _io_pc_next_type_T_1; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_3 = issltu ? 4'h0 : _io_pc_next_type_T_2; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_4 = isbne ? 4'h5 : _io_pc_next_type_T_3; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_5 = isbgeu ? 4'h8 : _io_pc_next_type_T_4; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_6 = isbltu ? 4'ha : _io_pc_next_type_T_5; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_7 = isblt ? 4'h9 : _io_pc_next_type_T_6; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_8 = isbge ? 4'h7 : _io_pc_next_type_T_7; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_9 = isbeq ? 4'h6 : _io_pc_next_type_T_8; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_10 = issub ? 4'h0 : _io_pc_next_type_T_9; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_11 = isor ? 4'h0 : _io_pc_next_type_T_10; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_12 = isxor ? 4'h0 : _io_pc_next_type_T_11; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_13 = issrl ? 4'h0 : _io_pc_next_type_T_12; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_14 = issra ? 4'h0 : _io_pc_next_type_T_13; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_15 = issll ? 4'h0 : _io_pc_next_type_T_14; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_16 = isand ? 4'h0 : _io_pc_next_type_T_15; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_17 = isadd ? 4'h0 : _io_pc_next_type_T_16; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_18 = islb ? 4'h0 : _io_pc_next_type_T_17; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_19 = islbu ? 4'h0 : _io_pc_next_type_T_18; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_20 = islhu ? 4'h0 : _io_pc_next_type_T_19; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_21 = islh ? 4'h0 : _io_pc_next_type_T_20; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_22 = islw ? 4'h0 : _io_pc_next_type_T_21; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_23 = ismret ? 4'hc : _io_pc_next_type_T_22; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_24 = isecall ? 4'hb : _io_pc_next_type_T_23; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_25 = isebreak ? 4'h4 : _io_pc_next_type_T_24; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_26 = issh ? 4'h0 : _io_pc_next_type_T_25; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_27 = issb ? 4'h0 : _io_pc_next_type_T_26; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_28 = issw ? 4'h0 : _io_pc_next_type_T_27; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_29 = isslli ? 4'h0 : _io_pc_next_type_T_28; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_30 = issrli ? 4'h0 : _io_pc_next_type_T_29; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_31 = issrai ? 4'h0 : _io_pc_next_type_T_30; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_32 = iscsrrs ? 4'h0 : _io_pc_next_type_T_31; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_33 = iscsrrw ? 4'h0 : _io_pc_next_type_T_32; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_34 = isandi ? 4'h0 : _io_pc_next_type_T_33; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_35 = isori ? 4'h0 : _io_pc_next_type_T_34; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_36 = isxori ? 4'h0 : _io_pc_next_type_T_35; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_37 = isaddi ? 4'h0 : _io_pc_next_type_T_36; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_38 = islui ? 4'h0 : _io_pc_next_type_T_37; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_39 = isauipc ? 4'h0 : _io_pc_next_type_T_38; // @[Mux.scala 101:16]
  wire [3:0] _io_pc_next_type_T_40 = isjalr ? 4'h2 : _io_pc_next_type_T_39; // @[Mux.scala 101:16]
  wire [2:0] _io_r_mask_T = islb ? 3'h5 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_r_mask_T_1 = islbu ? 3'h2 : _io_r_mask_T; // @[Mux.scala 101:16]
  wire [2:0] _io_r_mask_T_2 = islhu ? 3'h4 : _io_r_mask_T_1; // @[Mux.scala 101:16]
  wire [2:0] _io_r_mask_T_3 = islh ? 3'h3 : _io_r_mask_T_2; // @[Mux.scala 101:16]
  wire [2:0] _io_w_mask_T = issh ? 3'h2 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _io_w_mask_T_1 = issb ? 3'h3 : _io_w_mask_T; // @[Mux.scala 101:16]
  assign io_imm_type = isaddi ? 3'h1 : _io_imm_type_T_21; // @[Mux.scala 101:16]
  assign io_rs1 = isaddi ? addi_Rs1 : _io_rs1_T_34; // @[Mux.scala 101:16]
  assign io_rs2 = issw ? sltu_Rs2 : _io_rs2_T_17; // @[Mux.scala 101:16]
  assign io_rd = isaddi ? addi_Rd : _io_rd_T_28; // @[Mux.scala 101:16]
  assign io_data_control = isauipc ? 3'h1 : _io_data_control_T_25; // @[Mux.scala 101:16]
  assign io_ALU_ctrl = _io_ALU_ctrl_T_38[3:0]; // @[ysyx_25030077_IDU.scala 458:15]
  assign io_pc_next_type = isjal ? 4'h1 : _io_pc_next_type_T_40; // @[Mux.scala 101:16]
  assign io_r_mask = islw ? 3'h1 : _io_r_mask_T_3; // @[Mux.scala 101:16]
  assign io_w_mask = issw ? 3'h1 : _io_w_mask_T_1; // @[Mux.scala 101:16]
  assign io_r_valid = islw | (islh | (islhu | (islbu | islb))); // @[Mux.scala 101:16]
endmodule
module ysyx_25030077_imm(
  input  [31:0] io_instruction,
  input  [2:0]  io_imm_type,
  output [31:0] io_imm
);
  wire [19:0] _Imm_type1_T_2 = io_instruction[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] Imm_type1 = {_Imm_type1_T_2,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type2 = {io_instruction[31:12],12'h0}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type4 = {_Imm_type1_T_2,io_instruction[31:25],io_instruction[11:7]}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type5 = {27'h0,io_instruction[24:20]}; // @[Cat.scala 31:58]
  wire [31:0] Imm_type6 = {20'h0,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire  is_type1 = io_imm_type == 3'h1; // @[ysyx_25030077_imm.scala 21:31]
  wire  is_type2 = io_imm_type == 3'h2; // @[ysyx_25030077_imm.scala 22:31]
  wire  is_type3 = io_imm_type == 3'h3; // @[ysyx_25030077_imm.scala 23:31]
  wire  is_type4 = io_imm_type == 3'h4; // @[ysyx_25030077_imm.scala 24:31]
  wire  is_type5 = io_imm_type == 3'h5; // @[ysyx_25030077_imm.scala 25:31]
  wire  is_type6 = io_imm_type == 3'h6; // @[ysyx_25030077_imm.scala 26:31]
  wire [31:0] _io_imm_T = is_type6 ? Imm_type6 : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_1 = is_type5 ? Imm_type5 : _io_imm_T; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_2 = is_type4 ? Imm_type4 : _io_imm_T_1; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_3 = is_type3 ? 32'h4 : _io_imm_T_2; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_4 = is_type2 ? Imm_type2 : _io_imm_T_3; // @[Mux.scala 101:16]
  assign io_imm = is_type1 ? Imm_type1 : _io_imm_T_4; // @[Mux.scala 101:16]
endmodule
module MaxPeriodFibonacciLFSR(
  input   clock,
  input   reset,
  output  io_out_0,
  output  io_out_1,
  output  io_out_2,
  output  io_out_3,
  output  io_out_4,
  output  io_out_5,
  output  io_out_6,
  output  io_out_7,
  output  io_out_8,
  output  io_out_9,
  output  io_out_10,
  output  io_out_11,
  output  io_out_12,
  output  io_out_13,
  output  io_out_14,
  output  io_out_15
);
  reg  state_0; // @[PRNG.scala 55:49]
  reg  state_1; // @[PRNG.scala 55:49]
  reg  state_2; // @[PRNG.scala 55:49]
  reg  state_3; // @[PRNG.scala 55:49]
  reg  state_4; // @[PRNG.scala 55:49]
  reg  state_5; // @[PRNG.scala 55:49]
  reg  state_6; // @[PRNG.scala 55:49]
  reg  state_7; // @[PRNG.scala 55:49]
  reg  state_8; // @[PRNG.scala 55:49]
  reg  state_9; // @[PRNG.scala 55:49]
  reg  state_10; // @[PRNG.scala 55:49]
  reg  state_11; // @[PRNG.scala 55:49]
  reg  state_12; // @[PRNG.scala 55:49]
  reg  state_13; // @[PRNG.scala 55:49]
  reg  state_14; // @[PRNG.scala 55:49]
  reg  state_15; // @[PRNG.scala 55:49]
  wire  _T_2 = state_15 ^ state_13 ^ state_12 ^ state_10; // @[LFSR.scala 15:41]
  assign io_out_0 = state_0; // @[PRNG.scala 78:10]
  assign io_out_1 = state_1; // @[PRNG.scala 78:10]
  assign io_out_2 = state_2; // @[PRNG.scala 78:10]
  assign io_out_3 = state_3; // @[PRNG.scala 78:10]
  assign io_out_4 = state_4; // @[PRNG.scala 78:10]
  assign io_out_5 = state_5; // @[PRNG.scala 78:10]
  assign io_out_6 = state_6; // @[PRNG.scala 78:10]
  assign io_out_7 = state_7; // @[PRNG.scala 78:10]
  assign io_out_8 = state_8; // @[PRNG.scala 78:10]
  assign io_out_9 = state_9; // @[PRNG.scala 78:10]
  assign io_out_10 = state_10; // @[PRNG.scala 78:10]
  assign io_out_11 = state_11; // @[PRNG.scala 78:10]
  assign io_out_12 = state_12; // @[PRNG.scala 78:10]
  assign io_out_13 = state_13; // @[PRNG.scala 78:10]
  assign io_out_14 = state_14; // @[PRNG.scala 78:10]
  assign io_out_15 = state_15; // @[PRNG.scala 78:10]
  always @(posedge clock) begin
    state_0 <= reset | _T_2; // @[PRNG.scala 55:{49,49}]
    if (reset) begin // @[PRNG.scala 55:49]
      state_1 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_1 <= state_0;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_2 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_2 <= state_1;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_3 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_3 <= state_2;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_4 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_4 <= state_3;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_5 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_5 <= state_4;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_6 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_6 <= state_5;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_7 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_7 <= state_6;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_8 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_8 <= state_7;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_9 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_9 <= state_8;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_10 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_10 <= state_9;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_11 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_11 <= state_10;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_12 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_12 <= state_11;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_13 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_13 <= state_12;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_14 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_14 <= state_13;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_15 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_15 <= state_14;
    end
  end
endmodule
module ysyx_25030077_gpr(
  input         clock,
  input         reset,
  output        io_mem_Req_ready,
  input         io_mem_Req_valid,
  output        io_b_ready,
  input         io_b_valid,
  input  [1:0]  io_gpr_b_resp,
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
  export "DPI-C" function reg_read_addr;
  function int reg_read_addr();
    return {27'b0, io_waddr_rd};
  endfunction

  export "DPI-C" function reg_read_data;
  function int reg_read_data();
    return {io_wdata_rd};
  endfunction
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
  reg [31:0] regs_0; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_1; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_2; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_3; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_4; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_5; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_6; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_7; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_8; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_9; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_10; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_11; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_12; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_13; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_14; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_15; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_16; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_17; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_18; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_19; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_20; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_21; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_22; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_23; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_24; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_25; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_26; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_27; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_28; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_29; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_30; // @[ysyx_25030077_gpr.scala 21:21]
  reg [31:0] regs_31; // @[ysyx_25030077_gpr.scala 21:21]
  reg  validReg; // @[ysyx_25030077_gpr.scala 22:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[ysyx_25030077_gpr.scala 23:27]
  reg [31:0] pc_next_reg; // @[ysyx_25030077_gpr.scala 24:28]
  wire  _validReg_T = io_mem_Req_valid & canAccept; // @[ysyx_25030077_gpr.scala 27:36]
  wire  _validReg_T_1 = io_ifu_Req_ready ? 1'h0 : validReg; // @[ysyx_25030077_gpr.scala 28:20]
  wire [31:0] _GEN_1 = 5'h1 == io_raddr_rs1 ? regs_1 : regs_0; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_2 = 5'h2 == io_raddr_rs1 ? regs_2 : _GEN_1; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_3 = 5'h3 == io_raddr_rs1 ? regs_3 : _GEN_2; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_4 = 5'h4 == io_raddr_rs1 ? regs_4 : _GEN_3; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_5 = 5'h5 == io_raddr_rs1 ? regs_5 : _GEN_4; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_6 = 5'h6 == io_raddr_rs1 ? regs_6 : _GEN_5; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_7 = 5'h7 == io_raddr_rs1 ? regs_7 : _GEN_6; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_8 = 5'h8 == io_raddr_rs1 ? regs_8 : _GEN_7; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_9 = 5'h9 == io_raddr_rs1 ? regs_9 : _GEN_8; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_10 = 5'ha == io_raddr_rs1 ? regs_10 : _GEN_9; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_11 = 5'hb == io_raddr_rs1 ? regs_11 : _GEN_10; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_12 = 5'hc == io_raddr_rs1 ? regs_12 : _GEN_11; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_13 = 5'hd == io_raddr_rs1 ? regs_13 : _GEN_12; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_14 = 5'he == io_raddr_rs1 ? regs_14 : _GEN_13; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_15 = 5'hf == io_raddr_rs1 ? regs_15 : _GEN_14; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_16 = 5'h10 == io_raddr_rs1 ? regs_16 : _GEN_15; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_17 = 5'h11 == io_raddr_rs1 ? regs_17 : _GEN_16; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_18 = 5'h12 == io_raddr_rs1 ? regs_18 : _GEN_17; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_19 = 5'h13 == io_raddr_rs1 ? regs_19 : _GEN_18; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_20 = 5'h14 == io_raddr_rs1 ? regs_20 : _GEN_19; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_21 = 5'h15 == io_raddr_rs1 ? regs_21 : _GEN_20; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_22 = 5'h16 == io_raddr_rs1 ? regs_22 : _GEN_21; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_23 = 5'h17 == io_raddr_rs1 ? regs_23 : _GEN_22; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_24 = 5'h18 == io_raddr_rs1 ? regs_24 : _GEN_23; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_25 = 5'h19 == io_raddr_rs1 ? regs_25 : _GEN_24; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_26 = 5'h1a == io_raddr_rs1 ? regs_26 : _GEN_25; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_27 = 5'h1b == io_raddr_rs1 ? regs_27 : _GEN_26; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_28 = 5'h1c == io_raddr_rs1 ? regs_28 : _GEN_27; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_29 = 5'h1d == io_raddr_rs1 ? regs_29 : _GEN_28; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_30 = 5'h1e == io_raddr_rs1 ? regs_30 : _GEN_29; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  wire [31:0] _GEN_33 = 5'h1 == io_raddr_rs2 ? regs_1 : regs_0; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_34 = 5'h2 == io_raddr_rs2 ? regs_2 : _GEN_33; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_35 = 5'h3 == io_raddr_rs2 ? regs_3 : _GEN_34; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_36 = 5'h4 == io_raddr_rs2 ? regs_4 : _GEN_35; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_37 = 5'h5 == io_raddr_rs2 ? regs_5 : _GEN_36; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_38 = 5'h6 == io_raddr_rs2 ? regs_6 : _GEN_37; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_39 = 5'h7 == io_raddr_rs2 ? regs_7 : _GEN_38; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_40 = 5'h8 == io_raddr_rs2 ? regs_8 : _GEN_39; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_41 = 5'h9 == io_raddr_rs2 ? regs_9 : _GEN_40; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_42 = 5'ha == io_raddr_rs2 ? regs_10 : _GEN_41; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_43 = 5'hb == io_raddr_rs2 ? regs_11 : _GEN_42; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_44 = 5'hc == io_raddr_rs2 ? regs_12 : _GEN_43; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_45 = 5'hd == io_raddr_rs2 ? regs_13 : _GEN_44; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_46 = 5'he == io_raddr_rs2 ? regs_14 : _GEN_45; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_47 = 5'hf == io_raddr_rs2 ? regs_15 : _GEN_46; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_48 = 5'h10 == io_raddr_rs2 ? regs_16 : _GEN_47; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_49 = 5'h11 == io_raddr_rs2 ? regs_17 : _GEN_48; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_50 = 5'h12 == io_raddr_rs2 ? regs_18 : _GEN_49; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_51 = 5'h13 == io_raddr_rs2 ? regs_19 : _GEN_50; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_52 = 5'h14 == io_raddr_rs2 ? regs_20 : _GEN_51; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_53 = 5'h15 == io_raddr_rs2 ? regs_21 : _GEN_52; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_54 = 5'h16 == io_raddr_rs2 ? regs_22 : _GEN_53; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_55 = 5'h17 == io_raddr_rs2 ? regs_23 : _GEN_54; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_56 = 5'h18 == io_raddr_rs2 ? regs_24 : _GEN_55; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_57 = 5'h19 == io_raddr_rs2 ? regs_25 : _GEN_56; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_58 = 5'h1a == io_raddr_rs2 ? regs_26 : _GEN_57; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_59 = 5'h1b == io_raddr_rs2 ? regs_27 : _GEN_58; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_60 = 5'h1c == io_raddr_rs2 ? regs_28 : _GEN_59; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_61 = 5'h1d == io_raddr_rs2 ? regs_29 : _GEN_60; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_62 = 5'h1e == io_raddr_rs2 ? regs_30 : _GEN_61; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  wire [31:0] _GEN_65 = 5'h1 == io_waddr_rd ? regs_1 : regs_0; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_66 = 5'h2 == io_waddr_rd ? regs_2 : _GEN_65; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_67 = 5'h3 == io_waddr_rd ? regs_3 : _GEN_66; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_68 = 5'h4 == io_waddr_rd ? regs_4 : _GEN_67; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_69 = 5'h5 == io_waddr_rd ? regs_5 : _GEN_68; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_70 = 5'h6 == io_waddr_rd ? regs_6 : _GEN_69; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_71 = 5'h7 == io_waddr_rd ? regs_7 : _GEN_70; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_72 = 5'h8 == io_waddr_rd ? regs_8 : _GEN_71; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_73 = 5'h9 == io_waddr_rd ? regs_9 : _GEN_72; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_74 = 5'ha == io_waddr_rd ? regs_10 : _GEN_73; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_75 = 5'hb == io_waddr_rd ? regs_11 : _GEN_74; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_76 = 5'hc == io_waddr_rd ? regs_12 : _GEN_75; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_77 = 5'hd == io_waddr_rd ? regs_13 : _GEN_76; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_78 = 5'he == io_waddr_rd ? regs_14 : _GEN_77; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_79 = 5'hf == io_waddr_rd ? regs_15 : _GEN_78; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_80 = 5'h10 == io_waddr_rd ? regs_16 : _GEN_79; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_81 = 5'h11 == io_waddr_rd ? regs_17 : _GEN_80; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_82 = 5'h12 == io_waddr_rd ? regs_18 : _GEN_81; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_83 = 5'h13 == io_waddr_rd ? regs_19 : _GEN_82; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_84 = 5'h14 == io_waddr_rd ? regs_20 : _GEN_83; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_85 = 5'h15 == io_waddr_rd ? regs_21 : _GEN_84; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_86 = 5'h16 == io_waddr_rd ? regs_22 : _GEN_85; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_87 = 5'h17 == io_waddr_rd ? regs_23 : _GEN_86; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_88 = 5'h18 == io_waddr_rd ? regs_24 : _GEN_87; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_89 = 5'h19 == io_waddr_rd ? regs_25 : _GEN_88; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_90 = 5'h1a == io_waddr_rd ? regs_26 : _GEN_89; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_91 = 5'h1b == io_waddr_rd ? regs_27 : _GEN_90; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_92 = 5'h1c == io_waddr_rd ? regs_28 : _GEN_91; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_93 = 5'h1d == io_waddr_rd ? regs_29 : _GEN_92; // @[ysyx_25030077_gpr.scala 35:{27,27}]
  wire [31:0] _GEN_94 = 5'h1e == io_waddr_rd ? regs_30 : _GEN_93; // @[ysyx_25030077_gpr.scala 35:{27,27}]
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
  assign io_mem_Req_ready = _canAccept_T[0]; // @[ysyx_25030077_gpr.scala 23:27]
  assign io_b_ready = _canAccept_T[0]; // @[ysyx_25030077_gpr.scala 23:27]
  assign io_rdata_rs1 = 5'h1f == io_raddr_rs1 ? regs_31 : _GEN_30; // @[ysyx_25030077_gpr.scala 31:{16,16}]
  assign io_rdata_rs2 = 5'h1f == io_raddr_rs2 ? regs_31 : _GEN_62; // @[ysyx_25030077_gpr.scala 32:{16,16}]
  assign io_ifu_Req_valid = validReg; // @[ysyx_25030077_gpr.scala 37:20]
  assign io_ifu_Req_bits_addr = pc_next_reg; // @[ysyx_25030077_gpr.scala 33:24]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_0 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h0 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_0 <= 32'h0;
        end else begin
          regs_0 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_0 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_0 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_1 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_1 <= 32'h0;
        end else begin
          regs_1 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_1 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_1 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_2 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h2 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_2 <= 32'h0;
        end else begin
          regs_2 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_2 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_2 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_3 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h3 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_3 <= 32'h0;
        end else begin
          regs_3 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_3 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_3 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_4 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h4 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_4 <= 32'h0;
        end else begin
          regs_4 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_4 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_4 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_5 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h5 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_5 <= 32'h0;
        end else begin
          regs_5 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_5 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_5 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_6 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h6 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_6 <= 32'h0;
        end else begin
          regs_6 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_6 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_6 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_7 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h7 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_7 <= 32'h0;
        end else begin
          regs_7 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_7 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_7 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_8 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h8 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_8 <= 32'h0;
        end else begin
          regs_8 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_8 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_8 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_9 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h9 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_9 <= 32'h0;
        end else begin
          regs_9 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_9 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_9 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_10 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'ha == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_10 <= 32'h0;
        end else begin
          regs_10 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_10 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_10 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_11 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'hb == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_11 <= 32'h0;
        end else begin
          regs_11 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_11 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_11 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_12 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'hc == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_12 <= 32'h0;
        end else begin
          regs_12 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_12 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_12 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_13 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'hd == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_13 <= 32'h0;
        end else begin
          regs_13 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_13 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_13 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_14 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'he == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_14 <= 32'h0;
        end else begin
          regs_14 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_14 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_14 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_15 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'hf == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_15 <= 32'h0;
        end else begin
          regs_15 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_15 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_15 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_16 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h10 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_16 <= 32'h0;
        end else begin
          regs_16 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_16 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_16 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_17 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h11 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_17 <= 32'h0;
        end else begin
          regs_17 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_17 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_17 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_18 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h12 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_18 <= 32'h0;
        end else begin
          regs_18 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_18 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_18 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_19 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h13 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_19 <= 32'h0;
        end else begin
          regs_19 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_19 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_19 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_20 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h14 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_20 <= 32'h0;
        end else begin
          regs_20 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_20 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_20 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_21 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h15 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_21 <= 32'h0;
        end else begin
          regs_21 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_21 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_21 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_22 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h16 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_22 <= 32'h0;
        end else begin
          regs_22 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_22 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_22 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_23 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h17 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_23 <= 32'h0;
        end else begin
          regs_23 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_23 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_23 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_24 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h18 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_24 <= 32'h0;
        end else begin
          regs_24 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_24 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_24 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_25 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h19 == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_25 <= 32'h0;
        end else begin
          regs_25 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_25 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_25 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_26 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1a == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_26 <= 32'h0;
        end else begin
          regs_26 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_26 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_26 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_27 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1b == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_27 <= 32'h0;
        end else begin
          regs_27 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_27 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_27 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_28 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1c == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_28 <= 32'h0;
        end else begin
          regs_28 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_28 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_28 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_29 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1d == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_29 <= 32'h0;
        end else begin
          regs_29 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_29 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_29 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_30 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1e == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_30 <= 32'h0;
        end else begin
          regs_30 <= io_wdata_rd;
        end
      end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_30 <= regs_31; // @[ysyx_25030077_gpr.scala 35:27]
      end else begin
        regs_30 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 21:21]
      regs_31 <= 32'h0; // @[ysyx_25030077_gpr.scala 21:21]
    end else if (5'h1f == io_waddr_rd) begin // @[ysyx_25030077_gpr.scala 35:21]
      if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 35:27]
        if (io_waddr_rd == 5'h0) begin // @[ysyx_25030077_gpr.scala 26:27]
          regs_31 <= 32'h0;
        end else begin
          regs_31 <= io_wdata_rd;
        end
      end else if (!(5'h1f == io_waddr_rd)) begin // @[ysyx_25030077_gpr.scala 35:27]
        regs_31 <= _GEN_94;
      end
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 22:25]
      validReg <= 1'h1; // @[ysyx_25030077_gpr.scala 22:25]
    end else begin
      validReg <= io_mem_Req_valid & canAccept | _validReg_T_1; // @[ysyx_25030077_gpr.scala 27:12]
    end
    if (reset) begin // @[ysyx_25030077_gpr.scala 24:28]
      pc_next_reg <= 32'h80000000; // @[ysyx_25030077_gpr.scala 24:28]
    end else if (_validReg_T) begin // @[ysyx_25030077_gpr.scala 36:21]
      pc_next_reg <= io_pc_next;
    end
  end
endmodule
module MaxPeriodFibonacciLFSR_2(
  input   clock,
  input   reset,
  output  io_out_0,
  output  io_out_1,
  output  io_out_2
);
  reg  state_0; // @[PRNG.scala 55:49]
  reg  state_1; // @[PRNG.scala 55:49]
  reg  state_2; // @[PRNG.scala 55:49]
  wire  _T = state_2 ^ state_1; // @[LFSR.scala 15:41]
  assign io_out_0 = state_0; // @[PRNG.scala 78:10]
  assign io_out_1 = state_1; // @[PRNG.scala 78:10]
  assign io_out_2 = state_2; // @[PRNG.scala 78:10]
  always @(posedge clock) begin
    state_0 <= reset | _T; // @[PRNG.scala 55:{49,49}]
    if (reset) begin // @[PRNG.scala 55:49]
      state_1 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_1 <= state_0;
    end
    if (reset) begin // @[PRNG.scala 55:49]
      state_2 <= 1'h0; // @[PRNG.scala 55:49]
    end else begin
      state_2 <= state_1;
    end
  end
endmodule
module ysyx_25030077_mem(
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
  output        io_b_valid,
  output [1:0]  io_b_resp
);
  wire  [31:0] io_r_mask_ext = {29'b0, io_r_mask};
  wire  [31:0] io_w_mask_ext = {29'b0, io_w_mask};
  import "DPI-C" function bit[31:0] mem_data_read(input bit[31:0] mask, input bit[31:0] addr_in);
  import "DPI-C" function bit[31:0] addr_read(input bit[31:0] addr_in);
  export "DPI-C" function wmask_read;
  function int wmask_read();
    return {io_w_mask_ext};
  endfunction
  wire  [31:0] valid = {31'b0, io_aw_valid & canAccept};
  export "DPI-C" function valid_read;
  function int valid_read();
    return {valid};
  endfunction
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
  reg [31:0] mem_data_Reg; // @[ysyx_25030077_mem.scala 23:29]
  reg  validReg; // @[ysyx_25030077_mem.scala 24:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[ysyx_25030077_mem.scala 25:28]
  // wire [31:0] _read_data_T = io_rs1 & io_rs2; // @[mem.scala 20:27]
  // wire [31:0] _read_data_T_1 = {29'h0,io_r_mask}; // @[Cat.scala 31:58]
  // wire [31:0] _read_data_T_2 = io_imm ^ _read_data_T_1; // @[mem.scala 20:47]
  // wire [31:0] read_data = _read_data_T | _read_data_T_2; // @[mem.scala 20:37]
  wire [31:0] read_data = io_r_mask == 3'h6 ? addr_read(io_raddr) : mem_data_read({29'h0,io_r_mask},  io_raddr);
  reg [2:0] delayCnt; // @[ysyx_25030077_mem.scala 28:25]
  wire  _startDelay_T = io_ar_valid & canAccept; // @[ysyx_25030077_mem.scala 30:29]
  wire  startDelay = io_ar_valid & canAccept & io_r_valid; // @[ysyx_25030077_mem.scala 30:42]
  wire [2:0] _delayCnt_T = {delayCnt_prng_io_out_2,delayCnt_prng_io_out_1,delayCnt_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [2:0] _delayCnt_T_3 = delayCnt - 3'h1; // @[ysyx_25030077_mem.scala 34:46]
  wire  _io_r_valid_T = delayCnt == 3'h0; // @[ysyx_25030077_mem.scala 37:39]
  wire  _validReg_T_4 = io_b_ready & io_r__ready & _io_r_valid_T ? 1'h0 : validReg; // @[ysyx_25030077_mem.scala 44:18]
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
  MaxPeriodFibonacciLFSR_2 delayCnt_prng ( // @[PRNG.scala 91:22]
    .clock(delayCnt_prng_clock),
    .reset(delayCnt_prng_reset),
    .io_out_0(delayCnt_prng_io_out_0),
    .io_out_1(delayCnt_prng_io_out_1),
    .io_out_2(delayCnt_prng_io_out_2)
  );
  assign io_ar_ready = _canAccept_T[0]; // @[ysyx_25030077_mem.scala 25:28]
  assign io_aw_ready = _canAccept_T[0]; // @[ysyx_25030077_mem.scala 25:28]
  assign io_w_ready = _canAccept_T[0]; // @[ysyx_25030077_mem.scala 25:28]
  assign io_mem_data = mem_data_Reg; // @[ysyx_25030077_mem.scala 41:15]
  assign io_cnt = delayCnt; // @[ysyx_25030077_mem.scala 32:10]
  assign io_r__valid = validReg & delayCnt == 3'h0; // @[ysyx_25030077_mem.scala 37:26]
  assign io_b_valid = validReg & _io_r_valid_T; // @[ysyx_25030077_mem.scala 38:26]
  assign io_b_resp = 2'h0; // @[ysyx_25030077_mem.scala 39:13]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  assign delayCnt_prng_clock = clock;
  assign delayCnt_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[ysyx_25030077_mem.scala 23:29]
      mem_data_Reg <= 32'h0; // @[ysyx_25030077_mem.scala 23:29]
    end else if (_startDelay_T) begin // @[ysyx_25030077_mem.scala 46:22]
      mem_data_Reg <= read_data;
    end
    if (reset) begin // @[ysyx_25030077_mem.scala 24:25]
      validReg <= 1'h0; // @[ysyx_25030077_mem.scala 24:25]
    end else begin
      validReg <= _startDelay_T | _validReg_T_4; // @[ysyx_25030077_mem.scala 43:12]
    end
    if (reset) begin // @[ysyx_25030077_mem.scala 28:25]
      delayCnt <= 3'h0; // @[ysyx_25030077_mem.scala 28:25]
    end else if (startDelay) begin // @[ysyx_25030077_mem.scala 33:18]
      delayCnt <= _delayCnt_T;
    end else if (delayCnt != 3'h0) begin // @[ysyx_25030077_mem.scala 34:18]
      delayCnt <= _delayCnt_T_3;
    end else begin
      delayCnt <= 3'h0;
    end
  end
endmodule
module ysyx_25030077_data_control(
  input  [31:0] io_rs1_data,
  input  [31:0] io_rs2_data,
  input  [31:0] io_imm,
  input  [31:0] io_mem_data,
  input  [31:0] io_pc_count,
  input  [2:0]  io_data_control,
  output [31:0] io_data_1,
  output [31:0] io_data_2
);
  export "DPI-C" function reg_read_rs1;
  function int reg_read_rs1();
    return {io_rs1_data};
  endfunction

  export "DPI-C" function reg_read_rs2;
  function int reg_read_rs2();
    return {io_rs2_data};
  endfunction
  wire  control1 = io_data_control == 3'h1; // @[ysyx_25030077_data_control.scala 18:34]
  wire  control2 = io_data_control == 3'h2; // @[ysyx_25030077_data_control.scala 19:34]
  wire  control3 = io_data_control == 3'h3; // @[ysyx_25030077_data_control.scala 20:34]
  wire [31:0] _io_data_1_T = control2 ? io_mem_data : io_rs1_data; // @[Mux.scala 101:16]
  wire [31:0] _io_data_2_T = control3 ? io_rs2_data : io_imm; // @[Mux.scala 101:16]
  assign io_data_1 = control1 ? io_pc_count : _io_data_1_T; // @[Mux.scala 101:16]
  assign io_data_2 = control2 ? 32'h0 : _io_data_2_T; // @[Mux.scala 101:16]
endmodule
module ysyx_25030077_alu(
  input  [31:0] io_in_a,
  input  [31:0] io_in_b,
  input  [3:0]  io_sw,
  output [31:0] io_out
);
  import "DPI-C" function bit[31:0] csr_read(input bit[31:0] rs1, input bit[31:0] imm, input bit[3:0] sw);
  wire [31:0] csr_data = csr_read(io_in_a, io_in_b, io_sw);
  wire [15:0] oneHot = 16'h1 << io_sw; // @[OneHot.scala 64:12]
  wire [32:0] add33 = io_in_a + io_in_b; // @[ysyx_25030077_alu.scala 18:25]
  wire [32:0] sub33 = io_in_a - io_in_b; // @[ysyx_25030077_alu.scala 19:25]
  wire [31:0] and32 = io_in_a & io_in_b; // @[ysyx_25030077_alu.scala 20:25]
  wire [31:0] or32 = io_in_a | io_in_b; // @[ysyx_25030077_alu.scala 21:25]
  wire [31:0] xor32 = io_in_a ^ io_in_b; // @[ysyx_25030077_alu.scala 22:25]
  wire [31:0] srai32 = $signed(io_in_a) >>> io_in_b[4:0]; // @[ysyx_25030077_alu.scala 23:49]
  wire [31:0] srli32 = io_in_a >> io_in_b[4:0]; // @[ysyx_25030077_alu.scala 24:25]
  wire [62:0] _GEN_3 = {{31'd0}, io_in_a}; // @[ysyx_25030077_alu.scala 25:25]
  wire [62:0] sll32 = _GEN_3 << io_in_b[4:0]; // @[ysyx_25030077_alu.scala 25:25]
  wire  sltiu_b = io_in_a < io_in_b; // @[ysyx_25030077_alu.scala 26:26]
  wire  slt_b = $signed(io_in_a) < $signed(io_in_b); // @[ysyx_25030077_alu.scala 27:33]
  wire [32:0] _out33_T_3 = {32'h0,sltiu_b}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_5 = {1'h0,or32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_7 = {1'h0,xor32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_9 = {1'h0,srai32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_11 = {1'h0,and32}; // @[Cat.scala 31:58]
  wire [63:0] _out33_T_14 = {1'h0,sll32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_16 = {1'h0,srli32}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_18 = {32'h0,slt_b}; // @[Cat.scala 31:58]
  wire [32:0] _out33_T_24 = oneHot[0] ? add33 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_25 = oneHot[1] ? sub33 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_26 = oneHot[2] ? _out33_T_3 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_27 = oneHot[3] ? _out33_T_5 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_28 = oneHot[4] ? _out33_T_7 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_29 = oneHot[5] ? _out33_T_9 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_30 = oneHot[6] ? _out33_T_11 : 33'h0; // @[Mux.scala 27:73]
  wire [63:0] _out33_T_32 = oneHot[8] ? _out33_T_14 : 64'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_33 = oneHot[9] ? _out33_T_16 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_34 = oneHot[10] ? _out33_T_18 : 33'h0; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_40 = _out33_T_24 | _out33_T_25; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_41 = _out33_T_40 | _out33_T_26; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_42 = _out33_T_41 | _out33_T_27; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_43 = _out33_T_42 | _out33_T_28; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_44 = _out33_T_43 | _out33_T_29; // @[Mux.scala 27:73]
  wire [32:0] _out33_T_45 = _out33_T_44 | _out33_T_30; // @[Mux.scala 27:73]
  wire [63:0] _GEN_0 = {{31'd0}, _out33_T_45}; // @[Mux.scala 27:73]
  wire [63:0] _out33_T_47 = _GEN_0 | _out33_T_32; // @[Mux.scala 27:73]
  wire [63:0] _GEN_1 = {{31'd0}, _out33_T_33}; // @[Mux.scala 27:73]
  wire [63:0] _out33_T_48 = _out33_T_47 | _GEN_1; // @[Mux.scala 27:73]
  wire [63:0] _GEN_2 = {{31'd0}, _out33_T_34}; // @[Mux.scala 27:73]
  wire [63:0] out33 = _out33_T_48 | _GEN_2; // @[Mux.scala 27:73]
  assign io_out = (oneHot[11] || oneHot[12]) ? csr_data :out33[31:0]; // @[module.scala 30:10]
endmodule
module ysyx_25030077_pc_next(
  input  [31:0] io_rs1_data,
  input  [31:0] io_rs2_data,
  input  [31:0] io_instruction,
  input  [3:0]  io_pc_next_type,
  input  [31:0] io_pc_count,
  output [31:0] io_pc_next,
  output        io_is_unknown_instruction
);
  export "DPI-C" function dnpc_read_data;
  function int dnpc_read_data();
    return {io_pc_next};
  endfunction
  import "DPI-C" function bit[31:0] ecall_read(input bit[31:0] pc, input bit[3:0] type_p);
  wire [31:0] ecall_dnpc = ecall_read(io_pc_count, io_pc_next_type);
  wire [31:0] default_pc_next = io_pc_count + 32'h4; // @[ysyx_25030077_pc_next.scala 15:37]
  wire  is_type1 = io_pc_next_type == 4'h1; // @[ysyx_25030077_pc_next.scala 18:34]
  wire  is_type2 = io_pc_next_type == 4'h2; // @[ysyx_25030077_pc_next.scala 19:34]
  wire  is_type4 = io_pc_next_type == 4'h4; // @[ysyx_25030077_pc_next.scala 21:34]
  wire  is_type5 = io_pc_next_type == 4'h5; // @[ysyx_25030077_pc_next.scala 22:34]
  wire  is_type6 = io_pc_next_type == 4'h6; // @[ysyx_25030077_pc_next.scala 23:34]
  wire  is_type7 = io_pc_next_type == 4'h7; // @[ysyx_25030077_pc_next.scala 24:34]
  wire  is_type8 = io_pc_next_type == 4'h8; // @[ysyx_25030077_pc_next.scala 25:34]
  wire  is_type9 = io_pc_next_type == 4'h9; // @[ysyx_25030077_pc_next.scala 26:34]
  wire  is_type10 = io_pc_next_type == 4'ha; // @[ysyx_25030077_pc_next.scala 27:34]
  wire  is_type11 = (io_pc_next_type == 4'hb || io_pc_next_type == 4'hc); // @[module.scala 27:34]
  wire  is_eql = io_rs1_data == io_rs2_data; // @[ysyx_25030077_pc_next.scala 29:28]
  wire  is_more_equ = $signed(io_rs1_data) >= $signed(io_rs2_data); // @[ysyx_25030077_pc_next.scala 30:40]
  wire  is_less = $signed(io_rs1_data) < $signed(io_rs2_data); // @[ysyx_25030077_pc_next.scala 31:36]
  wire  is_more_equ_u = io_rs1_data >= io_rs2_data; // @[ysyx_25030077_pc_next.scala 32:35]
  wire  is_less_u = io_rs1_data < io_rs2_data; // @[ysyx_25030077_pc_next.scala 33:31]
  wire [18:0] _beq_result_T_2 = io_instruction[31] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _beq_result_T_7 = {_beq_result_T_2,io_instruction[31],io_instruction[7],io_instruction[30:25],
    io_instruction[11:8],1'h0}; // @[Cat.scala 31:58]
  wire [31:0] _beq_result_T_9 = io_pc_count + _beq_result_T_7; // @[ysyx_25030077_pc_next.scala 37:28]
  wire [31:0] beq_result = is_eql ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bge_result = is_more_equ ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] blt_result = is_less ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bltu_result = is_less_u ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bgeu_result = is_more_equ_u ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire  _bne_result_T = ~is_eql; // @[ysyx_25030077_pc_next.scala 57:5]
  wire [31:0] bne_result = _bne_result_T ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [10:0] _io_pc_next_T_2 = io_instruction[31] ? 11'h7ff : 11'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_pc_next_T_7 = {_io_pc_next_T_2,io_instruction[31],io_instruction[19:12],io_instruction[20],
    io_instruction[30:21],1'h0}; // @[Cat.scala 31:58]
  wire [31:0] _io_pc_next_T_9 = io_pc_count + _io_pc_next_T_7; // @[ysyx_25030077_pc_next.scala 61:30]
  wire [19:0] _io_pc_next_T_12 = io_instruction[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_pc_next_T_14 = {_io_pc_next_T_12,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire [31:0] _io_pc_next_T_16 = io_rs1_data + _io_pc_next_T_14; // @[ysyx_25030077_pc_next.scala 62:31]
  wire [31:0] _io_pc_next_T_18 = _io_pc_next_T_16 & 32'hfffffffe; // @[ysyx_25030077_pc_next.scala 62:94]
  wire [31:0] _io_pc_next_T_19 = is_type10 ? bltu_result : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_20 = is_type9 ? blt_result : _io_pc_next_T_19; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_21 = is_type8 ? bgeu_result : _io_pc_next_T_20; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_22 = is_type7 ? bge_result : _io_pc_next_T_21; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_23 = is_type5 ? bne_result : _io_pc_next_T_22; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_24 = is_type6 ? beq_result : _io_pc_next_T_23; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_25 = is_type4 ? io_pc_count : _io_pc_next_T_24; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_26 = is_type2 ? _io_pc_next_T_18 : _io_pc_next_T_25; // @[Mux.scala 101:16]
  wire [31:0] _io_pc_next_T_27 = is_type1 ? _io_pc_next_T_9 : _io_pc_next_T_26; // @[Mux.scala 101:16]
  assign io_pc_next = is_type11 ? ecall_dnpc : _io_pc_next_T_27; // @[Mux.scala 101:16]
  // assign io_pc_next = is_type1 ? _io_pc_next_T_9 : _io_pc_next_T_26; // @[Mux.scala 101:16]
  assign io_is_unknown_instruction = io_pc_next_type == 4'h3; // @[ysyx_25030077_pc_next.scala 20:34]
endmodule
module ysyx_25030077_UART(
  input         clock,
  input         reset,
  output        io_aw_ready,
  input         io_aw_valid,
  output        io_w_ready,
  input         io_w_valid,
  input  [31:0] io_waddr,
  input  [31:0] io_wdata,
  input  [2:0]  io_w_mask
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
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[ysyx_25030077_UART.scala 14:30]
  wire [7:0] charToPrint = io_wdata[7:0]; // @[ysyx_25030077_UART.scala 21:31]
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
  assign io_aw_ready = _canAccept_T[0]; // @[ysyx_25030077_UART.scala 14:30]
  assign io_w_ready = _canAccept_T[0]; // @[ysyx_25030077_UART.scala 14:30]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (~reset) begin
            if (io_aw_valid & canAccept & io_w_valid & io_waddr == 32'ha00003f8) begin
                $fwrite(32'h80000002,"%c",charToPrint); // @[UART.scala 21:11]
            end
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module ysyx_25030077_clint(
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
  reg [63:0] mem_data_Reg; // @[ysyx_25030077_clint.scala 17:29]
  reg  validReg; // @[ysyx_25030077_clint.scala 18:25]
  wire [7:0] canAccept_lo = {canAccept_prng_io_out_7,canAccept_prng_io_out_6,canAccept_prng_io_out_5,
    canAccept_prng_io_out_4,canAccept_prng_io_out_3,canAccept_prng_io_out_2,canAccept_prng_io_out_1,
    canAccept_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [15:0] _canAccept_T = {canAccept_prng_io_out_15,canAccept_prng_io_out_14,canAccept_prng_io_out_13,
    canAccept_prng_io_out_12,canAccept_prng_io_out_11,canAccept_prng_io_out_10,canAccept_prng_io_out_9,
    canAccept_prng_io_out_8,canAccept_lo}; // @[PRNG.scala 95:17]
  wire  canAccept = _canAccept_T[0]; // @[ysyx_25030077_clint.scala 19:28]
  reg [2:0] delayCnt; // @[ysyx_25030077_clint.scala 21:25]
  wire  _startDelay_T = io_ar_valid & canAccept; // @[ysyx_25030077_clint.scala 23:29]
  wire  startDelay = io_ar_valid & canAccept & io_r_valid; // @[ysyx_25030077_clint.scala 23:42]
  wire [2:0] _delayCnt_T = {delayCnt_prng_io_out_2,delayCnt_prng_io_out_1,delayCnt_prng_io_out_0}; // @[PRNG.scala 95:17]
  wire [2:0] _delayCnt_T_3 = delayCnt - 3'h1; // @[ysyx_25030077_clint.scala 27:46]
  wire  _io_r_valid_T = delayCnt == 3'h0; // @[ysyx_25030077_clint.scala 30:39]
  wire  _validReg_T_3 = io_r__ready & _io_r_valid_T ? 1'h0 : validReg; // @[ysyx_25030077_clint.scala 34:18]
  wire [63:0] _mem_data_Reg_T_2 = mem_data_Reg + 64'h700; // @[ysyx_25030077_clint.scala 36:62]
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
  MaxPeriodFibonacciLFSR_2 delayCnt_prng ( // @[PRNG.scala 91:22]
    .clock(delayCnt_prng_clock),
    .reset(delayCnt_prng_reset),
    .io_out_0(delayCnt_prng_io_out_0),
    .io_out_1(delayCnt_prng_io_out_1),
    .io_out_2(delayCnt_prng_io_out_2)
  );
  assign io_ar_ready = _canAccept_T[0]; // @[ysyx_25030077_clint.scala 19:28]
  assign io_mem_data = io_raddr == 32'ha0000048 ? mem_data_Reg[31:0] : mem_data_Reg[63:32]; // @[ysyx_25030077_clint.scala 32:21]
  assign io_cnt = delayCnt; // @[ysyx_25030077_clint.scala 24:10]
  assign io_r__valid = validReg & delayCnt == 3'h0; // @[ysyx_25030077_clint.scala 30:26]
  assign canAccept_prng_clock = clock;
  assign canAccept_prng_reset = reset;
  assign delayCnt_prng_clock = clock;
  assign delayCnt_prng_reset = reset;
  always @(posedge clock) begin
    if (reset) begin // @[ysyx_25030077_clint.scala 17:29]
      mem_data_Reg <= 64'h0; // @[ysyx_25030077_clint.scala 17:29]
    end else if (_startDelay_T) begin // @[ysyx_25030077_clint.scala 36:22]
      mem_data_Reg <= _mem_data_Reg_T_2;
    end
    if (reset) begin // @[ysyx_25030077_clint.scala 18:25]
      validReg <= 1'h0; // @[ysyx_25030077_clint.scala 18:25]
    end else begin
      validReg <= _startDelay_T | _validReg_T_3; // @[ysyx_25030077_clint.scala 33:12]
    end
    if (reset) begin // @[ysyx_25030077_clint.scala 21:25]
      delayCnt <= 3'h0; // @[ysyx_25030077_clint.scala 21:25]
    end else if (startDelay) begin // @[ysyx_25030077_clint.scala 26:18]
      delayCnt <= _delayCnt_T;
    end else if (delayCnt != 3'h0) begin // @[ysyx_25030077_clint.scala 27:18]
      delayCnt <= _delayCnt_T_3;
    end else begin
      delayCnt <= 3'h0;
    end
  end
endmodule
module ysyx_25030077(
  input   clock,
  input   reset,
  output  io_is_unknown_instruction
);
  wire  b_ifu_clock; // @[ysyx_25030077.scala 12:22]
  wire  b_ifu_reset; // @[ysyx_25030077.scala 12:22]
  wire  b_ifu_io_rd_Req_ready; // @[ysyx_25030077.scala 12:22]
  wire  b_ifu_io_rd_Req_valid; // @[ysyx_25030077.scala 12:22]
  wire [31:0] b_ifu_io_rd_Req_bits_addr; // @[ysyx_25030077.scala 12:22]
  wire  b_ifu_io_ar_ready; // @[ysyx_25030077.scala 12:22]
  wire  b_ifu_io_ar_valid; // @[ysyx_25030077.scala 12:22]
  wire [31:0] b_ifu_io_ar_bits_addr; // @[ysyx_25030077.scala 12:22]
  wire  c_arbiter_clock; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_reset; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_ifu_valid; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_delay_cnt_mem; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_delay_cnt_clint; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_pc; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_rs1_data; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_rs2_data; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_imm; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_r_mask; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_w_mask; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_ar_valid_mem; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_ar_addr_mem; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_axi_ar_strb_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_ar_ready_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_ar_valid_clint; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_ar_addr_clint; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_axi_ar_strb_clint; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_ar_ready_clint; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_aw_valid_mem; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_aw_addr_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_aw_ready_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_w_valid_mem; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_w_data_mem; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_axi_w_strb_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_w_ready_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_aw_valid_uart; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_aw_addr_uart; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_aw_ready_uart; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_w_valid_uart; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_w_data_uart; // @[ysyx_25030077.scala 13:25]
  wire [2:0] c_arbiter_io_axi_w_strb_uart; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_w_ready_uart; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_r_valid_mem; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_r_data_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_r_ready_mem; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_r_valid_clint; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_axi_r_data_clint; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_r_ready_clint; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_b_valid; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_axi_b_ready; // @[ysyx_25030077.scala 13:25]
  wire [1:0] c_arbiter_io_axi_b_resp; // @[ysyx_25030077.scala 13:25]
  wire [1:0] c_arbiter_io_gpr_b_resp; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_gpr_r_valid; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_gpr_b_valid; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_gpr_r_ready; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_gpr_b_ready; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_gpr_data; // @[ysyx_25030077.scala 13:25]
  wire [31:0] c_arbiter_io_inst; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_ifu_ready; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_r_valid_lsu; // @[ysyx_25030077.scala 13:25]
  wire  c_arbiter_io_is_r; // @[ysyx_25030077.scala 13:25]
  wire [31:0] d_idu_io_instruction; // @[ysyx_25030077.scala 14:21]
  wire [2:0] d_idu_io_imm_type; // @[ysyx_25030077.scala 14:21]
  wire [4:0] d_idu_io_rs1; // @[ysyx_25030077.scala 14:21]
  wire [4:0] d_idu_io_rs2; // @[ysyx_25030077.scala 14:21]
  wire [4:0] d_idu_io_rd; // @[ysyx_25030077.scala 14:21]
  wire [2:0] d_idu_io_data_control; // @[ysyx_25030077.scala 14:21]
  wire [3:0] d_idu_io_ALU_ctrl; // @[ysyx_25030077.scala 14:21]
  wire [3:0] d_idu_io_pc_next_type; // @[ysyx_25030077.scala 14:21]
  wire [2:0] d_idu_io_r_mask; // @[ysyx_25030077.scala 14:21]
  wire [2:0] d_idu_io_w_mask; // @[ysyx_25030077.scala 14:21]
  wire  d_idu_io_r_valid; // @[ysyx_25030077.scala 14:21]
  wire [31:0] e_imm_io_instruction; // @[ysyx_25030077.scala 15:21]
  wire [2:0] e_imm_io_imm_type; // @[ysyx_25030077.scala 15:21]
  wire [31:0] e_imm_io_imm; // @[ysyx_25030077.scala 15:21]
  wire  f_gpr_clock; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_reset; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_io_mem_Req_ready; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_io_mem_Req_valid; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_io_b_ready; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_io_b_valid; // @[ysyx_25030077.scala 16:21]
  wire [1:0] f_gpr_io_gpr_b_resp; // @[ysyx_25030077.scala 16:21]
  wire [31:0] f_gpr_io_pc_next; // @[ysyx_25030077.scala 16:21]
  wire [4:0] f_gpr_io_waddr_rd; // @[ysyx_25030077.scala 16:21]
  wire [31:0] f_gpr_io_wdata_rd; // @[ysyx_25030077.scala 16:21]
  wire [4:0] f_gpr_io_raddr_rs1; // @[ysyx_25030077.scala 16:21]
  wire [31:0] f_gpr_io_rdata_rs1; // @[ysyx_25030077.scala 16:21]
  wire [4:0] f_gpr_io_raddr_rs2; // @[ysyx_25030077.scala 16:21]
  wire [31:0] f_gpr_io_rdata_rs2; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_io_ifu_Req_ready; // @[ysyx_25030077.scala 16:21]
  wire  f_gpr_io_ifu_Req_valid; // @[ysyx_25030077.scala 16:21]
  wire [31:0] f_gpr_io_ifu_Req_bits_addr; // @[ysyx_25030077.scala 16:21]
  wire  g_mem_clock; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_reset; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_ar_ready; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_ar_valid; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_aw_ready; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_aw_valid; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_w_ready; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_w_valid; // @[ysyx_25030077.scala 17:21]
  wire [31:0] g_mem_io_waddr; // @[ysyx_25030077.scala 17:21]
  wire [31:0] g_mem_io_raddr; // @[ysyx_25030077.scala 17:21]
  wire [31:0] g_mem_io_wdata; // @[ysyx_25030077.scala 17:21]
  wire [2:0] g_mem_io_r_mask; // @[ysyx_25030077.scala 17:21]
  wire [2:0] g_mem_io_w_mask; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_r_valid; // @[ysyx_25030077.scala 17:21]
  wire [31:0] g_mem_io_mem_data; // @[ysyx_25030077.scala 17:21]
  wire [2:0] g_mem_io_cnt; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_r__ready; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_r__valid; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_b_ready; // @[ysyx_25030077.scala 17:21]
  wire  g_mem_io_b_valid; // @[ysyx_25030077.scala 17:21]
  wire [1:0] g_mem_io_b_resp; // @[ysyx_25030077.scala 17:21]
  wire [31:0] h_data_control_io_rs1_data; // @[ysyx_25030077.scala 18:30]
  wire [31:0] h_data_control_io_rs2_data; // @[ysyx_25030077.scala 18:30]
  wire [31:0] h_data_control_io_imm; // @[ysyx_25030077.scala 18:30]
  wire [31:0] h_data_control_io_mem_data; // @[ysyx_25030077.scala 18:30]
  wire [31:0] h_data_control_io_pc_count; // @[ysyx_25030077.scala 18:30]
  wire [2:0] h_data_control_io_data_control; // @[ysyx_25030077.scala 18:30]
  wire [31:0] h_data_control_io_data_1; // @[ysyx_25030077.scala 18:30]
  wire [31:0] h_data_control_io_data_2; // @[ysyx_25030077.scala 18:30]
  wire [31:0] i_alu_io_in_a; // @[ysyx_25030077.scala 19:21]
  wire [31:0] i_alu_io_in_b; // @[ysyx_25030077.scala 19:21]
  wire [3:0] i_alu_io_sw; // @[ysyx_25030077.scala 19:21]
  wire [31:0] i_alu_io_out; // @[ysyx_25030077.scala 19:21]
  wire [31:0] j_pc_next_io_rs1_data; // @[ysyx_25030077.scala 20:25]
  wire [31:0] j_pc_next_io_rs2_data; // @[ysyx_25030077.scala 20:25]
  wire [31:0] j_pc_next_io_instruction; // @[ysyx_25030077.scala 20:25]
  wire [3:0] j_pc_next_io_pc_next_type; // @[ysyx_25030077.scala 20:25]
  wire [31:0] j_pc_next_io_pc_count; // @[ysyx_25030077.scala 20:25]
  wire [31:0] j_pc_next_io_pc_next; // @[ysyx_25030077.scala 20:25]
  wire  j_pc_next_io_is_unknown_instruction; // @[ysyx_25030077.scala 20:25]
  wire  l_uart_clock; // @[ysyx_25030077.scala 21:22]
  wire  l_uart_reset; // @[ysyx_25030077.scala 21:22]
  wire  l_uart_io_aw_ready; // @[ysyx_25030077.scala 21:22]
  wire  l_uart_io_aw_valid; // @[ysyx_25030077.scala 21:22]
  wire  l_uart_io_w_ready; // @[ysyx_25030077.scala 21:22]
  wire  l_uart_io_w_valid; // @[ysyx_25030077.scala 21:22]
  wire [31:0] l_uart_io_waddr; // @[ysyx_25030077.scala 21:22]
  wire [31:0] l_uart_io_wdata; // @[ysyx_25030077.scala 21:22]
  wire [2:0] l_uart_io_w_mask; // @[ysyx_25030077.scala 21:22]
  wire  m_clint_clock; // @[ysyx_25030077.scala 22:23]
  wire  m_clint_reset; // @[ysyx_25030077.scala 22:23]
  wire  m_clint_io_ar_ready; // @[ysyx_25030077.scala 22:23]
  wire  m_clint_io_ar_valid; // @[ysyx_25030077.scala 22:23]
  wire [31:0] m_clint_io_raddr; // @[ysyx_25030077.scala 22:23]
  wire [2:0] m_clint_io_r_mask; // @[ysyx_25030077.scala 22:23]
  wire  m_clint_io_r_valid; // @[ysyx_25030077.scala 22:23]
  wire [31:0] m_clint_io_mem_data; // @[ysyx_25030077.scala 22:23]
  wire [2:0] m_clint_io_cnt; // @[ysyx_25030077.scala 22:23]
  wire  m_clint_io_r__ready; // @[ysyx_25030077.scala 22:23]
  wire  m_clint_io_r__valid; // @[ysyx_25030077.scala 22:23]
  ysyx_25030077_IFU b_ifu ( // @[ysyx_25030077.scala 12:22]
    .clock(b_ifu_clock),
    .reset(b_ifu_reset),
    .io_rd_Req_ready(b_ifu_io_rd_Req_ready),
    .io_rd_Req_valid(b_ifu_io_rd_Req_valid),
    .io_rd_Req_bits_addr(b_ifu_io_rd_Req_bits_addr),
    .io_ar_ready(b_ifu_io_ar_ready),
    .io_ar_valid(b_ifu_io_ar_valid),
    .io_ar_bits_addr(b_ifu_io_ar_bits_addr)
  );
  ysyx_25030077_arbiter c_arbiter ( // @[ysyx_25030077.scala 13:25]
    .clock(c_arbiter_clock),
    .reset(c_arbiter_reset),
    .io_ifu_valid(c_arbiter_io_ifu_valid),
    .io_delay_cnt_mem(c_arbiter_io_delay_cnt_mem),
    .io_delay_cnt_clint(c_arbiter_io_delay_cnt_clint),
    .io_pc(c_arbiter_io_pc),
    .io_rs1_data(c_arbiter_io_rs1_data),
    .io_rs2_data(c_arbiter_io_rs2_data),
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
    .io_axi_aw_valid_mem(c_arbiter_io_axi_aw_valid_mem),
    .io_axi_aw_addr_mem(c_arbiter_io_axi_aw_addr_mem),
    .io_axi_aw_ready_mem(c_arbiter_io_axi_aw_ready_mem),
    .io_axi_w_valid_mem(c_arbiter_io_axi_w_valid_mem),
    .io_axi_w_data_mem(c_arbiter_io_axi_w_data_mem),
    .io_axi_w_strb_mem(c_arbiter_io_axi_w_strb_mem),
    .io_axi_w_ready_mem(c_arbiter_io_axi_w_ready_mem),
    .io_axi_aw_valid_uart(c_arbiter_io_axi_aw_valid_uart),
    .io_axi_aw_addr_uart(c_arbiter_io_axi_aw_addr_uart),
    .io_axi_aw_ready_uart(c_arbiter_io_axi_aw_ready_uart),
    .io_axi_w_valid_uart(c_arbiter_io_axi_w_valid_uart),
    .io_axi_w_data_uart(c_arbiter_io_axi_w_data_uart),
    .io_axi_w_strb_uart(c_arbiter_io_axi_w_strb_uart),
    .io_axi_w_ready_uart(c_arbiter_io_axi_w_ready_uart),
    .io_axi_r_valid_mem(c_arbiter_io_axi_r_valid_mem),
    .io_axi_r_data_mem(c_arbiter_io_axi_r_data_mem),
    .io_axi_r_ready_mem(c_arbiter_io_axi_r_ready_mem),
    .io_axi_r_valid_clint(c_arbiter_io_axi_r_valid_clint),
    .io_axi_r_data_clint(c_arbiter_io_axi_r_data_clint),
    .io_axi_r_ready_clint(c_arbiter_io_axi_r_ready_clint),
    .io_axi_b_valid(c_arbiter_io_axi_b_valid),
    .io_axi_b_ready(c_arbiter_io_axi_b_ready),
    .io_axi_b_resp(c_arbiter_io_axi_b_resp),
    .io_gpr_b_resp(c_arbiter_io_gpr_b_resp),
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
  ysyx_25030077_IDU d_idu ( // @[ysyx_25030077.scala 14:21]
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
    .io_r_valid(d_idu_io_r_valid)
  );
  ysyx_25030077_imm e_imm ( // @[ysyx_25030077.scala 15:21]
    .io_instruction(e_imm_io_instruction),
    .io_imm_type(e_imm_io_imm_type),
    .io_imm(e_imm_io_imm)
  );
  ysyx_25030077_gpr f_gpr ( // @[ysyx_25030077.scala 16:21]
    .clock(f_gpr_clock),
    .reset(f_gpr_reset),
    .io_mem_Req_ready(f_gpr_io_mem_Req_ready),
    .io_mem_Req_valid(f_gpr_io_mem_Req_valid),
    .io_b_ready(f_gpr_io_b_ready),
    .io_b_valid(f_gpr_io_b_valid),
    .io_gpr_b_resp(f_gpr_io_gpr_b_resp),
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
  ysyx_25030077_mem g_mem ( // @[ysyx_25030077.scala 17:21]
    .clock(g_mem_clock),
    .reset(g_mem_reset),
    .io_ar_ready(g_mem_io_ar_ready),
    .io_ar_valid(g_mem_io_ar_valid),
    .io_aw_ready(g_mem_io_aw_ready),
    .io_aw_valid(g_mem_io_aw_valid),
    .io_w_ready(g_mem_io_w_ready),
    .io_w_valid(g_mem_io_w_valid),
    .io_waddr(g_mem_io_waddr),
    .io_raddr(g_mem_io_raddr),
    .io_wdata(g_mem_io_wdata),
    .io_r_mask(g_mem_io_r_mask),
    .io_w_mask(g_mem_io_w_mask),
    .io_r_valid(g_mem_io_r_valid),
    .io_mem_data(g_mem_io_mem_data),
    .io_cnt(g_mem_io_cnt),
    .io_r__ready(g_mem_io_r__ready),
    .io_r__valid(g_mem_io_r__valid),
    .io_b_ready(g_mem_io_b_ready),
    .io_b_valid(g_mem_io_b_valid),
    .io_b_resp(g_mem_io_b_resp)
  );
  ysyx_25030077_data_control h_data_control ( // @[ysyx_25030077.scala 18:30]
    .io_rs1_data(h_data_control_io_rs1_data),
    .io_rs2_data(h_data_control_io_rs2_data),
    .io_imm(h_data_control_io_imm),
    .io_mem_data(h_data_control_io_mem_data),
    .io_pc_count(h_data_control_io_pc_count),
    .io_data_control(h_data_control_io_data_control),
    .io_data_1(h_data_control_io_data_1),
    .io_data_2(h_data_control_io_data_2)
  );
  ysyx_25030077_alu i_alu ( // @[ysyx_25030077.scala 19:21]
    .io_in_a(i_alu_io_in_a),
    .io_in_b(i_alu_io_in_b),
    .io_sw(i_alu_io_sw),
    .io_out(i_alu_io_out)
  );
  ysyx_25030077_pc_next j_pc_next ( // @[ysyx_25030077.scala 20:25]
    .io_rs1_data(j_pc_next_io_rs1_data),
    .io_rs2_data(j_pc_next_io_rs2_data),
    .io_instruction(j_pc_next_io_instruction),
    .io_pc_next_type(j_pc_next_io_pc_next_type),
    .io_pc_count(j_pc_next_io_pc_count),
    .io_pc_next(j_pc_next_io_pc_next),
    .io_is_unknown_instruction(j_pc_next_io_is_unknown_instruction)
  );
  ysyx_25030077_UART l_uart ( // @[ysyx_25030077.scala 21:22]
    .clock(l_uart_clock),
    .reset(l_uart_reset),
    .io_aw_ready(l_uart_io_aw_ready),
    .io_aw_valid(l_uart_io_aw_valid),
    .io_w_ready(l_uart_io_w_ready),
    .io_w_valid(l_uart_io_w_valid),
    .io_waddr(l_uart_io_waddr),
    .io_wdata(l_uart_io_wdata),
    .io_w_mask(l_uart_io_w_mask)
  );
  ysyx_25030077_clint m_clint ( // @[ysyx_25030077.scala 22:23]
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
  assign io_is_unknown_instruction = j_pc_next_io_is_unknown_instruction; // @[ysyx_25030077.scala 108:29]
  assign b_ifu_clock = clock;
  assign b_ifu_reset = reset;
  assign b_ifu_io_rd_Req_valid = f_gpr_io_ifu_Req_valid; // @[ysyx_25030077.scala 65:20]
  assign b_ifu_io_rd_Req_bits_addr = f_gpr_io_ifu_Req_bits_addr; // @[ysyx_25030077.scala 65:20]
  assign b_ifu_io_ar_ready = c_arbiter_io_ifu_ready; // @[ysyx_25030077.scala 24:21]
  assign c_arbiter_clock = clock;
  assign c_arbiter_reset = reset;
  assign c_arbiter_io_ifu_valid = b_ifu_io_ar_valid; // @[ysyx_25030077.scala 26:26]
  assign c_arbiter_io_delay_cnt_mem = g_mem_io_cnt; // @[ysyx_25030077.scala 47:30]
  assign c_arbiter_io_delay_cnt_clint = m_clint_io_cnt; // @[ysyx_25030077.scala 48:32]
  assign c_arbiter_io_pc = b_ifu_io_ar_bits_addr; // @[ysyx_25030077.scala 27:19]
  assign c_arbiter_io_rs1_data = f_gpr_io_rdata_rs1; // @[ysyx_25030077.scala 28:25]
  assign c_arbiter_io_rs2_data = f_gpr_io_rdata_rs2; // @[ysyx_25030077.scala 29:25]
  assign c_arbiter_io_imm = e_imm_io_imm; // @[ysyx_25030077.scala 30:20]
  assign c_arbiter_io_r_mask = d_idu_io_r_mask; // @[ysyx_25030077.scala 31:23]
  assign c_arbiter_io_w_mask = d_idu_io_w_mask; // @[ysyx_25030077.scala 32:23]
  assign c_arbiter_io_axi_ar_ready_mem = g_mem_io_ar_ready; // @[ysyx_25030077.scala 33:33]
  assign c_arbiter_io_axi_ar_ready_clint = m_clint_io_ar_ready; // @[ysyx_25030077.scala 36:35]
  assign c_arbiter_io_axi_aw_ready_mem = g_mem_io_aw_ready; // @[ysyx_25030077.scala 34:33]
  assign c_arbiter_io_axi_w_ready_mem = g_mem_io_w_ready; // @[ysyx_25030077.scala 35:32]
  assign c_arbiter_io_axi_aw_ready_uart = l_uart_io_aw_ready; // @[ysyx_25030077.scala 37:34]
  assign c_arbiter_io_axi_w_ready_uart = l_uart_io_w_ready; // @[ysyx_25030077.scala 38:33]
  assign c_arbiter_io_axi_r_valid_mem = g_mem_io_r__valid; // @[ysyx_25030077.scala 39:32]
  assign c_arbiter_io_axi_r_data_mem = g_mem_io_mem_data; // @[ysyx_25030077.scala 40:31]
  assign c_arbiter_io_axi_r_valid_clint = m_clint_io_r__valid; // @[ysyx_25030077.scala 41:34]
  assign c_arbiter_io_axi_r_data_clint = m_clint_io_mem_data; // @[ysyx_25030077.scala 42:33]
  assign c_arbiter_io_axi_b_valid = g_mem_io_b_valid; // @[ysyx_25030077.scala 43:28]
  assign c_arbiter_io_axi_b_resp = g_mem_io_b_resp; // @[ysyx_25030077.scala 49:27]
  assign c_arbiter_io_gpr_r_ready = f_gpr_io_mem_Req_ready; // @[ysyx_25030077.scala 45:28]
  assign c_arbiter_io_gpr_b_ready = f_gpr_io_b_ready; // @[ysyx_25030077.scala 46:28]
  assign c_arbiter_io_r_valid_lsu = d_idu_io_r_valid; // @[ysyx_25030077.scala 44:28]
  assign d_idu_io_instruction = c_arbiter_io_inst; // @[ysyx_25030077.scala 51:24]
  assign e_imm_io_instruction = c_arbiter_io_inst; // @[ysyx_25030077.scala 67:24]
  assign e_imm_io_imm_type = d_idu_io_imm_type; // @[ysyx_25030077.scala 68:21]
  assign f_gpr_clock = clock;
  assign f_gpr_reset = reset;
  assign f_gpr_io_mem_Req_valid = c_arbiter_io_gpr_r_valid; // @[ysyx_25030077.scala 75:26]
  assign f_gpr_io_b_valid = c_arbiter_io_gpr_b_valid; // @[ysyx_25030077.scala 76:20]
  assign f_gpr_io_gpr_b_resp = c_arbiter_io_gpr_b_resp; // @[ysyx_25030077.scala 77:23]
  assign f_gpr_io_pc_next = j_pc_next_io_pc_next; // @[ysyx_25030077.scala 72:20]
  assign f_gpr_io_waddr_rd = d_idu_io_rd; // @[ysyx_25030077.scala 73:21]
  assign f_gpr_io_wdata_rd = i_alu_io_out; // @[ysyx_25030077.scala 74:21]
  assign f_gpr_io_raddr_rs1 = d_idu_io_rs1; // @[ysyx_25030077.scala 70:22]
  assign f_gpr_io_raddr_rs2 = d_idu_io_rs2; // @[ysyx_25030077.scala 71:22]
  assign f_gpr_io_ifu_Req_ready = b_ifu_io_rd_Req_ready; // @[ysyx_25030077.scala 65:20]
  assign g_mem_clock = clock;
  assign g_mem_reset = reset;
  assign g_mem_io_ar_valid = c_arbiter_io_axi_ar_valid_mem; // @[ysyx_25030077.scala 53:21]
  assign g_mem_io_aw_valid = c_arbiter_io_axi_aw_valid_mem; // @[ysyx_25030077.scala 54:21]
  assign g_mem_io_w_valid = c_arbiter_io_axi_w_valid_mem; // @[ysyx_25030077.scala 55:20]
  assign g_mem_io_waddr = c_arbiter_io_axi_aw_addr_mem; // @[ysyx_25030077.scala 56:18]
  assign g_mem_io_raddr = c_arbiter_io_axi_ar_addr_mem; // @[ysyx_25030077.scala 57:18]
  assign g_mem_io_wdata = c_arbiter_io_axi_w_data_mem; // @[ysyx_25030077.scala 58:18]
  assign g_mem_io_r_mask = c_arbiter_io_axi_ar_strb_mem; // @[ysyx_25030077.scala 59:19]
  assign g_mem_io_w_mask = c_arbiter_io_axi_w_strb_mem; // @[ysyx_25030077.scala 60:19]
  assign g_mem_io_r_valid = c_arbiter_io_is_r; // @[ysyx_25030077.scala 61:20]
  assign g_mem_io_r__ready = c_arbiter_io_axi_r_ready_mem; // @[ysyx_25030077.scala 62:20]
  assign g_mem_io_b_ready = c_arbiter_io_axi_b_ready; // @[ysyx_25030077.scala 63:20]
  assign h_data_control_io_rs1_data = f_gpr_io_rdata_rs1; // @[ysyx_25030077.scala 85:30]
  assign h_data_control_io_rs2_data = f_gpr_io_rdata_rs2; // @[ysyx_25030077.scala 86:30]
  assign h_data_control_io_imm = e_imm_io_imm; // @[ysyx_25030077.scala 87:25]
  assign h_data_control_io_mem_data = c_arbiter_io_gpr_data; // @[ysyx_25030077.scala 88:30]
  assign h_data_control_io_pc_count = b_ifu_io_rd_Req_bits_addr; // @[ysyx_25030077.scala 90:30]
  assign h_data_control_io_data_control = d_idu_io_data_control; // @[ysyx_25030077.scala 89:34]
  assign i_alu_io_in_a = h_data_control_io_data_1; // @[ysyx_25030077.scala 92:17]
  assign i_alu_io_in_b = h_data_control_io_data_2; // @[ysyx_25030077.scala 93:17]
  assign i_alu_io_sw = d_idu_io_ALU_ctrl; // @[ysyx_25030077.scala 94:15]
  assign j_pc_next_io_rs1_data = f_gpr_io_rdata_rs1; // @[ysyx_25030077.scala 79:25]
  assign j_pc_next_io_rs2_data = f_gpr_io_rdata_rs2; // @[ysyx_25030077.scala 80:25]
  assign j_pc_next_io_instruction = c_arbiter_io_inst; // @[ysyx_25030077.scala 81:28]
  assign j_pc_next_io_pc_next_type = d_idu_io_pc_next_type; // @[ysyx_25030077.scala 83:29]
  assign j_pc_next_io_pc_count = b_ifu_io_rd_Req_bits_addr; // @[ysyx_25030077.scala 82:25]
  assign l_uart_clock = clock;
  assign l_uart_reset = reset;
  assign l_uart_io_aw_valid = c_arbiter_io_axi_aw_valid_uart; // @[ysyx_25030077.scala 96:22]
  assign l_uart_io_w_valid = c_arbiter_io_axi_w_valid_uart; // @[ysyx_25030077.scala 97:21]
  assign l_uart_io_waddr = c_arbiter_io_axi_aw_addr_uart; // @[ysyx_25030077.scala 98:19]
  assign l_uart_io_wdata = c_arbiter_io_axi_w_data_uart; // @[ysyx_25030077.scala 99:19]
  assign l_uart_io_w_mask = c_arbiter_io_axi_w_strb_uart; // @[ysyx_25030077.scala 100:20]
  assign m_clint_clock = clock;
  assign m_clint_reset = reset;
  assign m_clint_io_ar_valid = c_arbiter_io_axi_ar_valid_clint; // @[ysyx_25030077.scala 102:23]
  assign m_clint_io_raddr = c_arbiter_io_axi_ar_addr_clint; // @[ysyx_25030077.scala 103:20]
  assign m_clint_io_r_mask = c_arbiter_io_axi_ar_strb_clint; // @[ysyx_25030077.scala 104:21]
  assign m_clint_io_r_valid = c_arbiter_io_is_r; // @[ysyx_25030077.scala 105:22]
  assign m_clint_io_r__ready = c_arbiter_io_axi_r_ready_clint; // @[ysyx_25030077.scala 106:22]
endmodule
