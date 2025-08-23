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
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
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
      maybe_full <= 1'h1; // @[Decoupled.scala 262:27]
    end else if (do_enq != do_deq) begin // @[Decoupled.scala 279:27]
      maybe_full <= do_enq; // @[Decoupled.scala 280:16]
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
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 1; initvar = initvar+1)
    ram_addr[initvar] = _RAND_0[31:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  maybe_full = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module IFU(
  input         clock,
  input         reset,
  output        io_addr_Req_ready,
  input         io_addr_Req_valid,
  input  [31:0] io_addr_Req_bits_addr,
  input         io_sramReq_ready,
  output        io_sramReq_valid,
  output [31:0] io_sramReq_bits_addr
);
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
  assign io_addr_Req_ready = reqQ_io_enq_ready; // @[Decoupled.scala 365:17]
  assign io_sramReq_valid = reqQ_io_deq_valid; // @[IFU.scala 14:20]
  assign io_sramReq_bits_addr = reqQ_io_deq_bits_addr; // @[IFU.scala 15:24]
  assign reqQ_clock = clock;
  assign reqQ_reset = reset;
  assign reqQ_io_enq_valid = io_addr_Req_valid; // @[Decoupled.scala 363:22]
  assign reqQ_io_enq_bits_addr = io_addr_Req_bits_addr; // @[Decoupled.scala 364:21]
  assign reqQ_io_deq_ready = io_sramReq_ready; // @[IFU.scala 16:14]
endmodule
module SRAM(
  input         clock,
  input         reset,
  output        io_req_ready,
  input         io_req_valid,
  input  [31:0] io_req_bits_addr,
  input         io_iduReq_ready,
  output        io_iduReq_valid,
  output [31:0] io_iduReq_bits_inst,
  output [31:0] io_iduReq_bits_pc
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] instReg; // @[SRAM.scala 10:24]
  reg [31:0] pcReg; // @[SRAM.scala 11:24]
  reg  validReg; // @[SRAM.scala 12:25]
  wire  canAccept = ~validReg | io_iduReq_ready; // @[SRAM.scala 14:29]
  wire  _validReg_T = io_req_valid & canAccept; // @[SRAM.scala 20:32]
  wire  _validReg_T_1 = io_iduReq_ready ? 1'h0 : validReg; // @[SRAM.scala 21:18]
  assign io_req_ready = ~validReg | io_iduReq_ready; // @[SRAM.scala 14:29]
  assign io_iduReq_valid = validReg; // @[SRAM.scala 16:19]
  assign io_iduReq_bits_inst = instReg; // @[SRAM.scala 17:23]
  assign io_iduReq_bits_pc = pcReg; // @[SRAM.scala 18:21]
  always @(posedge clock) begin
    if (reset) begin // @[SRAM.scala 10:24]
      instReg <= 32'h413; // @[SRAM.scala 10:24]
    end else if (_validReg_T) begin // @[SRAM.scala 24:17]
      instReg <= io_req_bits_addr;
    end
    if (reset) begin // @[SRAM.scala 11:24]
      pcReg <= 32'h413; // @[SRAM.scala 11:24]
    end else if (_validReg_T) begin // @[SRAM.scala 25:15]
      pcReg <= io_req_bits_addr;
    end
    if (reset) begin // @[SRAM.scala 12:25]
      validReg <= 1'h0; // @[SRAM.scala 12:25]
    end else begin
      validReg <= io_req_valid & canAccept | _validReg_T_1; // @[SRAM.scala 20:12]
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
  instReg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  pcReg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  validReg = _RAND_2[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module IDU(
  input         clock,
  input         reset,
  output        io_inst_req_ready,
  input         io_inst_req_valid,
  input  [31:0] io_inst_req_bits_inst,
  input  [31:0] io_inst_req_bits_pc,
  output [2:0]  io_imm_type,
  output [4:0]  io_rs1,
  output [4:0]  io_rs2,
  output [4:0]  io_rd,
  input         io_ready,
  output        io_valid,
  output [2:0]  io_data_control,
  output [3:0]  io_ALU_ctrl,
  output [3:0]  io_pc_next_type,
  output [31:0] io_instruction_o,
  output [31:0] io_pc_o
);
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
`endif // RANDOMIZE_REG_INIT
  reg [31:0] inst_reg; // @[IDU.scala 20:25]
  reg [31:0] pc_reg; // @[IDU.scala 21:24]
  reg [2:0] imm_type_reg_o; // @[IDU.scala 22:31]
  reg [4:0] rs1_reg_o; // @[IDU.scala 23:26]
  reg [4:0] rs2_reg_o; // @[IDU.scala 24:26]
  reg [4:0] rd_reg_o; // @[IDU.scala 25:25]
  reg [3:0] ALU_ctrl_reg_o; // @[IDU.scala 26:31]
  reg [2:0] data_control_reg_o; // @[IDU.scala 27:35]
  reg [3:0] pc_next_type_reg_o; // @[IDU.scala 28:35]
  reg  validReg; // @[IDU.scala 29:25]
  wire  canAccept = ~validReg | io_ready; // @[IDU.scala 31:29]
  wire  _validReg_T = io_inst_req_valid & canAccept; // @[IDU.scala 44:37]
  wire  _validReg_T_1 = io_ready ? 1'h0 : validReg; // @[IDU.scala 45:18]
  wire [4:0] addi_Rs1 = io_inst_req_bits_inst[19:15]; // @[IDU.scala 57:39]
  wire [4:0] addi_Rd = io_inst_req_bits_inst[11:7]; // @[IDU.scala 58:39]
  wire [4:0] sltu_Rs2 = io_inst_req_bits_inst[24:20]; // @[IDU.scala 123:40]
  wire [9:0] _isaddi_T_2 = {io_inst_req_bits_inst[14:12],io_inst_req_bits_inst[6:0]}; // @[Cat.scala 31:58]
  wire  isaddi = _isaddi_T_2 == 10'h13; // @[IDU.scala 313:78]
  wire  isxori = _isaddi_T_2 == 10'h213; // @[IDU.scala 314:78]
  wire  isori = _isaddi_T_2 == 10'h313; // @[IDU.scala 315:78]
  wire  isandi = _isaddi_T_2 == 10'h393; // @[IDU.scala 316:78]
  wire [15:0] _issrai_T_3 = {io_inst_req_bits_inst[31:26],io_inst_req_bits_inst[14:12],io_inst_req_bits_inst[6:0]}; // @[Cat.scala 31:58]
  wire  issrai = _issrai_T_3 == 16'h4293; // @[IDU.scala 317:108]
  wire  issrli = _issrai_T_3 == 16'h293; // @[IDU.scala 318:108]
  wire  isslli = _issrai_T_3 == 16'h93; // @[IDU.scala 319:108]
  wire  issra = _issrai_T_3 == 16'h42b3; // @[IDU.scala 320:108]
  wire  issrl = _issrai_T_3 == 16'h2b3; // @[IDU.scala 321:108]
  wire  isbeq = _isaddi_T_2 == 10'h63; // @[IDU.scala 322:78]
  wire  isbne = _isaddi_T_2 == 10'he3; // @[IDU.scala 323:78]
  wire [16:0] _isadd_T_3 = {io_inst_req_bits_inst[31:25],io_inst_req_bits_inst[14:12],io_inst_req_bits_inst[6:0]}; // @[Cat.scala 31:58]
  wire  isadd = _isadd_T_3 == 17'h33; // @[IDU.scala 324:108]
  wire  isxor = _isadd_T_3 == 17'h233; // @[IDU.scala 325:108]
  wire  isand = _isadd_T_3 == 17'h3b3; // @[IDU.scala 326:108]
  wire  isor = _isadd_T_3 == 17'h333; // @[IDU.scala 327:108]
  wire  issub = _isadd_T_3 == 17'h8033; // @[IDU.scala 328:108]
  wire  islui = io_inst_req_bits_inst[6:0] == 7'h37; // @[IDU.scala 329:43]
  wire  isauipc = io_inst_req_bits_inst[6:0] == 7'h17; // @[IDU.scala 330:45]
  wire  isjal = io_inst_req_bits_inst[6:0] == 7'h6f; // @[IDU.scala 331:43]
  wire  isjalr = _isaddi_T_2 == 10'h67; // @[IDU.scala 332:79]
  wire  issw = _isaddi_T_2 == 10'h123; // @[IDU.scala 333:77]
  wire  isbge = _isaddi_T_2 == 10'h2e3; // @[IDU.scala 334:77]
  wire  isblt = _isaddi_T_2 == 10'h263; // @[IDU.scala 335:77]
  wire  isbltu = _isaddi_T_2 == 10'h363; // @[IDU.scala 336:77]
  wire  isbgeu = _isaddi_T_2 == 10'h3e3; // @[IDU.scala 337:77]
  wire  issb = _isaddi_T_2 == 10'h23; // @[IDU.scala 338:77]
  wire  issh = _isaddi_T_2 == 10'ha3; // @[IDU.scala 339:77]
  wire  islbu = _isaddi_T_2 == 10'h203; // @[IDU.scala 340:77]
  wire  islb = _isaddi_T_2 == 10'h3; // @[IDU.scala 341:77]
  wire  islw = _isaddi_T_2 == 10'h103; // @[IDU.scala 342:77]
  wire  islh = _isaddi_T_2 == 10'h83; // @[IDU.scala 343:77]
  wire  islhu = _isaddi_T_2 == 10'h283; // @[IDU.scala 344:77]
  wire  issll = _isadd_T_3 == 17'hb3; // @[IDU.scala 345:107]
  wire  isslt = _isadd_T_3 == 17'h133; // @[IDU.scala 346:109]
  wire  issltu = _isadd_T_3 == 17'h1b3; // @[IDU.scala 347:109]
  wire  issltiu = _isaddi_T_2 == 10'h193; // @[IDU.scala 348:79]
  wire  isslti = _isaddi_T_2 == 10'h113; // @[IDU.scala 349:79]
  wire  iscsrrw = _isaddi_T_2 == 10'hf3; // @[IDU.scala 350:81]
  wire  iscsrrs = _isaddi_T_2 == 10'h173; // @[IDU.scala 351:81]
  wire  isebreak = io_inst_req_bits_inst == 32'h100073; // @[IDU.scala 352:41]
  wire  isecall = io_inst_req_bits_inst == 32'h73; // @[IDU.scala 353:41]
  wire  ismret = io_inst_req_bits_inst == 32'h30200073; // @[IDU.scala 354:41]
  wire [2:0] _imm_type_reg_T = islb ? 3'h1 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_1 = islbu ? 3'h1 : _imm_type_reg_T; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_2 = islhu ? 3'h1 : _imm_type_reg_T_1; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_3 = islh ? 3'h1 : _imm_type_reg_T_2; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_4 = islw ? 3'h1 : _imm_type_reg_T_3; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_5 = issh ? 3'h4 : _imm_type_reg_T_4; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_6 = issb ? 3'h4 : _imm_type_reg_T_5; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_7 = issw ? 3'h4 : _imm_type_reg_T_6; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_8 = isjalr ? 3'h3 : _imm_type_reg_T_7; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_9 = isjal ? 3'h3 : _imm_type_reg_T_8; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_10 = isauipc ? 3'h2 : _imm_type_reg_T_9; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_11 = islui ? 3'h2 : _imm_type_reg_T_10; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_12 = isslti ? 3'h1 : _imm_type_reg_T_11; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_13 = issltiu ? 3'h1 : _imm_type_reg_T_12; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_14 = isslli ? 3'h5 : _imm_type_reg_T_13; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_15 = issrli ? 3'h5 : _imm_type_reg_T_14; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_16 = issrai ? 3'h5 : _imm_type_reg_T_15; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_17 = iscsrrs ? 3'h6 : _imm_type_reg_T_16; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_18 = iscsrrw ? 3'h6 : _imm_type_reg_T_17; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_19 = isandi ? 3'h1 : _imm_type_reg_T_18; // @[Mux.scala 101:16]
  wire [2:0] _imm_type_reg_T_20 = isori ? 3'h1 : _imm_type_reg_T_19; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T = isslt ? addi_Rs1 : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_1 = issltu ? addi_Rs1 : _rs1_reg_T; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_2 = isbne ? addi_Rs1 : _rs1_reg_T_1; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_3 = isbgeu ? addi_Rs1 : _rs1_reg_T_2; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_4 = isbltu ? addi_Rs1 : _rs1_reg_T_3; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_5 = isblt ? addi_Rs1 : _rs1_reg_T_4; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_6 = isbge ? addi_Rs1 : _rs1_reg_T_5; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_7 = isbeq ? addi_Rs1 : _rs1_reg_T_6; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_8 = issub ? addi_Rs1 : _rs1_reg_T_7; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_9 = isor ? addi_Rs1 : _rs1_reg_T_8; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_10 = isxor ? addi_Rs1 : _rs1_reg_T_9; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_11 = issrl ? addi_Rs1 : _rs1_reg_T_10; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_12 = issra ? addi_Rs1 : _rs1_reg_T_11; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_13 = issll ? addi_Rs1 : _rs1_reg_T_12; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_14 = isand ? addi_Rs1 : _rs1_reg_T_13; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_15 = isadd ? addi_Rs1 : _rs1_reg_T_14; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_16 = islb ? addi_Rs1 : _rs1_reg_T_15; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_17 = islbu ? addi_Rs1 : _rs1_reg_T_16; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_18 = islhu ? addi_Rs1 : _rs1_reg_T_17; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_19 = islh ? addi_Rs1 : _rs1_reg_T_18; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_20 = islw ? addi_Rs1 : _rs1_reg_T_19; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_21 = issh ? addi_Rs1 : _rs1_reg_T_20; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_22 = issb ? addi_Rs1 : _rs1_reg_T_21; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_23 = issw ? addi_Rs1 : _rs1_reg_T_22; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_24 = isjalr ? addi_Rs1 : _rs1_reg_T_23; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_25 = isslti ? addi_Rs1 : _rs1_reg_T_24; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_26 = issltiu ? addi_Rs1 : _rs1_reg_T_25; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_27 = isslli ? addi_Rs1 : _rs1_reg_T_26; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_28 = issrli ? addi_Rs1 : _rs1_reg_T_27; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_29 = issrai ? addi_Rs1 : _rs1_reg_T_28; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_30 = iscsrrs ? addi_Rs1 : _rs1_reg_T_29; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_31 = iscsrrw ? addi_Rs1 : _rs1_reg_T_30; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_32 = isandi ? addi_Rs1 : _rs1_reg_T_31; // @[Mux.scala 101:16]
  wire [4:0] _rs1_reg_T_33 = isori ? addi_Rs1 : _rs1_reg_T_32; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T = isslt ? sltu_Rs2 : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_1 = issltu ? sltu_Rs2 : _rs2_reg_T; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_2 = isbne ? sltu_Rs2 : _rs2_reg_T_1; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_3 = isbgeu ? sltu_Rs2 : _rs2_reg_T_2; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_4 = isbltu ? sltu_Rs2 : _rs2_reg_T_3; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_5 = isblt ? sltu_Rs2 : _rs2_reg_T_4; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_6 = isbge ? sltu_Rs2 : _rs2_reg_T_5; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_7 = isbeq ? sltu_Rs2 : _rs2_reg_T_6; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_8 = issub ? sltu_Rs2 : _rs2_reg_T_7; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_9 = isor ? sltu_Rs2 : _rs2_reg_T_8; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_10 = isxor ? sltu_Rs2 : _rs2_reg_T_9; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_11 = issrl ? sltu_Rs2 : _rs2_reg_T_10; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_12 = issra ? sltu_Rs2 : _rs2_reg_T_11; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_13 = issll ? sltu_Rs2 : _rs2_reg_T_12; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_14 = isand ? sltu_Rs2 : _rs2_reg_T_13; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_15 = isadd ? sltu_Rs2 : _rs2_reg_T_14; // @[Mux.scala 101:16]
  wire [4:0] _rs2_reg_T_16 = issh ? sltu_Rs2 : _rs2_reg_T_15; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T = isslt ? addi_Rd : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_1 = issltu ? addi_Rd : _rd_reg_T; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_2 = issub ? addi_Rd : _rd_reg_T_1; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_3 = isor ? addi_Rd : _rd_reg_T_2; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_4 = isxor ? addi_Rd : _rd_reg_T_3; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_5 = issrl ? addi_Rd : _rd_reg_T_4; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_6 = issra ? addi_Rd : _rd_reg_T_5; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_7 = issll ? addi_Rd : _rd_reg_T_6; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_8 = isand ? addi_Rd : _rd_reg_T_7; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_9 = isadd ? addi_Rd : _rd_reg_T_8; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_10 = islb ? addi_Rd : _rd_reg_T_9; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_11 = islbu ? addi_Rd : _rd_reg_T_10; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_12 = islhu ? addi_Rd : _rd_reg_T_11; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_13 = islh ? addi_Rd : _rd_reg_T_12; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_14 = islw ? addi_Rd : _rd_reg_T_13; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_15 = isjalr ? addi_Rd : _rd_reg_T_14; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_16 = isjal ? addi_Rd : _rd_reg_T_15; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_17 = isauipc ? addi_Rd : _rd_reg_T_16; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_18 = islui ? addi_Rd : _rd_reg_T_17; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_19 = isslti ? addi_Rd : _rd_reg_T_18; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_20 = issltiu ? addi_Rd : _rd_reg_T_19; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_21 = isslli ? addi_Rd : _rd_reg_T_20; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_22 = issrli ? addi_Rd : _rd_reg_T_21; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_23 = issrai ? addi_Rd : _rd_reg_T_22; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_24 = iscsrrs ? addi_Rd : _rd_reg_T_23; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_25 = iscsrrw ? addi_Rd : _rd_reg_T_24; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_26 = isandi ? addi_Rd : _rd_reg_T_25; // @[Mux.scala 101:16]
  wire [4:0] _rd_reg_T_27 = isori ? addi_Rd : _rd_reg_T_26; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T = issltu ? 5'h2 : 5'h0; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_1 = isslt ? 5'ha : _ALU_ctrl_reg_T; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_2 = isbne ? 5'h0 : _ALU_ctrl_reg_T_1; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_3 = isbgeu ? 5'h0 : _ALU_ctrl_reg_T_2; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_4 = isbltu ? 5'h0 : _ALU_ctrl_reg_T_3; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_5 = isblt ? 5'h0 : _ALU_ctrl_reg_T_4; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_6 = isbge ? 5'h0 : _ALU_ctrl_reg_T_5; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_7 = isbeq ? 5'h0 : _ALU_ctrl_reg_T_6; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_8 = issub ? 5'h1 : _ALU_ctrl_reg_T_7; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_9 = isor ? 5'h3 : _ALU_ctrl_reg_T_8; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_10 = isxor ? 5'h4 : _ALU_ctrl_reg_T_9; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_11 = issrl ? 5'h9 : _ALU_ctrl_reg_T_10; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_12 = issra ? 5'h5 : _ALU_ctrl_reg_T_11; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_13 = issll ? 5'h8 : _ALU_ctrl_reg_T_12; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_14 = isand ? 5'h6 : _ALU_ctrl_reg_T_13; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_15 = isadd ? 5'h0 : _ALU_ctrl_reg_T_14; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_16 = islb ? 5'h0 : _ALU_ctrl_reg_T_15; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_17 = islbu ? 5'h0 : _ALU_ctrl_reg_T_16; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_18 = islhu ? 5'h0 : _ALU_ctrl_reg_T_17; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_19 = islh ? 5'h0 : _ALU_ctrl_reg_T_18; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_20 = islw ? 5'h0 : _ALU_ctrl_reg_T_19; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_21 = issh ? 5'h0 : _ALU_ctrl_reg_T_20; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_22 = issb ? 5'h0 : _ALU_ctrl_reg_T_21; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_23 = issw ? 5'h0 : _ALU_ctrl_reg_T_22; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_24 = isjalr ? 5'h0 : _ALU_ctrl_reg_T_23; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_25 = isjal ? 5'h0 : _ALU_ctrl_reg_T_24; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_26 = isauipc ? 5'h0 : _ALU_ctrl_reg_T_25; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_27 = islui ? 5'h0 : _ALU_ctrl_reg_T_26; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_28 = isslti ? 5'ha : _ALU_ctrl_reg_T_27; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_29 = issltiu ? 5'h2 : _ALU_ctrl_reg_T_28; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_30 = isslli ? 5'h8 : _ALU_ctrl_reg_T_29; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_31 = issrli ? 5'h9 : _ALU_ctrl_reg_T_30; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_32 = issrai ? 5'h5 : _ALU_ctrl_reg_T_31; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_33 = iscsrrs ? 5'hc : _ALU_ctrl_reg_T_32; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_34 = iscsrrw ? 5'hb : _ALU_ctrl_reg_T_33; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_35 = isandi ? 5'h6 : _ALU_ctrl_reg_T_34; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_36 = isori ? 5'h3 : _ALU_ctrl_reg_T_35; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_T_37 = isxori ? 5'h4 : _ALU_ctrl_reg_T_36; // @[Mux.scala 101:16]
  wire [4:0] ALU_ctrl_reg = isaddi ? 5'h0 : _ALU_ctrl_reg_T_37; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T = issltu ? 3'h3 : 3'h0; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_1 = isslt ? 3'h3 : _data_control_reg_T; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_2 = isbne ? 3'h0 : _data_control_reg_T_1; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_3 = isbgeu ? 3'h0 : _data_control_reg_T_2; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_4 = isbltu ? 3'h0 : _data_control_reg_T_3; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_5 = isblt ? 3'h0 : _data_control_reg_T_4; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_6 = isbge ? 3'h0 : _data_control_reg_T_5; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_7 = isbeq ? 3'h0 : _data_control_reg_T_6; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_8 = issub ? 3'h3 : _data_control_reg_T_7; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_9 = isor ? 3'h3 : _data_control_reg_T_8; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_10 = isxor ? 3'h3 : _data_control_reg_T_9; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_11 = issrl ? 3'h3 : _data_control_reg_T_10; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_12 = issra ? 3'h3 : _data_control_reg_T_11; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_13 = issll ? 3'h3 : _data_control_reg_T_12; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_14 = isand ? 3'h3 : _data_control_reg_T_13; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_15 = isadd ? 3'h3 : _data_control_reg_T_14; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_16 = islb ? 3'h2 : _data_control_reg_T_15; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_17 = islbu ? 3'h2 : _data_control_reg_T_16; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_18 = islhu ? 3'h2 : _data_control_reg_T_17; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_19 = islh ? 3'h2 : _data_control_reg_T_18; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_20 = islw ? 3'h2 : _data_control_reg_T_19; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_21 = issh ? 3'h0 : _data_control_reg_T_20; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_22 = issb ? 3'h0 : _data_control_reg_T_21; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_23 = issw ? 3'h0 : _data_control_reg_T_22; // @[Mux.scala 101:16]
  wire [2:0] _data_control_reg_T_24 = isjalr ? 3'h1 : _data_control_reg_T_23; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T = isslti ? 4'h0 : 4'h3; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_1 = issltiu ? 4'h0 : _pc_next_type_reg_T; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_2 = isslt ? 4'h0 : _pc_next_type_reg_T_1; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_3 = issltu ? 4'h0 : _pc_next_type_reg_T_2; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_4 = isbne ? 4'h5 : _pc_next_type_reg_T_3; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_5 = isbgeu ? 4'h8 : _pc_next_type_reg_T_4; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_6 = isbltu ? 4'ha : _pc_next_type_reg_T_5; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_7 = isblt ? 4'h9 : _pc_next_type_reg_T_6; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_8 = isbge ? 4'h7 : _pc_next_type_reg_T_7; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_9 = isbeq ? 4'h6 : _pc_next_type_reg_T_8; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_10 = issub ? 4'h0 : _pc_next_type_reg_T_9; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_11 = isor ? 4'h0 : _pc_next_type_reg_T_10; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_12 = isxor ? 4'h0 : _pc_next_type_reg_T_11; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_13 = issrl ? 4'h0 : _pc_next_type_reg_T_12; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_14 = issra ? 4'h0 : _pc_next_type_reg_T_13; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_15 = issll ? 4'h0 : _pc_next_type_reg_T_14; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_16 = isand ? 4'h0 : _pc_next_type_reg_T_15; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_17 = isadd ? 4'h0 : _pc_next_type_reg_T_16; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_18 = islb ? 4'h0 : _pc_next_type_reg_T_17; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_19 = islbu ? 4'h0 : _pc_next_type_reg_T_18; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_20 = islhu ? 4'h0 : _pc_next_type_reg_T_19; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_21 = islh ? 4'h0 : _pc_next_type_reg_T_20; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_22 = islw ? 4'h0 : _pc_next_type_reg_T_21; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_23 = ismret ? 4'hc : _pc_next_type_reg_T_22; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_24 = isecall ? 4'hb : _pc_next_type_reg_T_23; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_25 = isebreak ? 4'h4 : _pc_next_type_reg_T_24; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_26 = issh ? 4'h0 : _pc_next_type_reg_T_25; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_27 = issb ? 4'h0 : _pc_next_type_reg_T_26; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_28 = issw ? 4'h0 : _pc_next_type_reg_T_27; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_29 = isslli ? 4'h0 : _pc_next_type_reg_T_28; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_30 = issrli ? 4'h0 : _pc_next_type_reg_T_29; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_31 = issrai ? 4'h0 : _pc_next_type_reg_T_30; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_32 = iscsrrs ? 4'h0 : _pc_next_type_reg_T_31; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_33 = iscsrrw ? 4'h0 : _pc_next_type_reg_T_32; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_34 = isandi ? 4'h0 : _pc_next_type_reg_T_33; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_35 = isori ? 4'h0 : _pc_next_type_reg_T_34; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_36 = isxori ? 4'h0 : _pc_next_type_reg_T_35; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_37 = isaddi ? 4'h0 : _pc_next_type_reg_T_36; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_38 = islui ? 4'h0 : _pc_next_type_reg_T_37; // @[Mux.scala 101:16]
  wire [3:0] _pc_next_type_reg_T_39 = isauipc ? 4'h0 : _pc_next_type_reg_T_38; // @[Mux.scala 101:16]
  wire [4:0] _ALU_ctrl_reg_o_T_1 = _validReg_T ? ALU_ctrl_reg : {{1'd0}, ALU_ctrl_reg_o}; // @[IDU.scala 598:24]
  wire [4:0] _GEN_0 = reset ? 5'h0 : _ALU_ctrl_reg_o_T_1; // @[IDU.scala 26:{31,31} 598:18]
  assign io_inst_req_ready = ~validReg | io_ready; // @[IDU.scala 31:29]
  assign io_imm_type = imm_type_reg_o; // @[IDU.scala 33:15]
  assign io_rs1 = rs1_reg_o; // @[IDU.scala 34:10]
  assign io_rs2 = rs2_reg_o; // @[IDU.scala 35:10]
  assign io_rd = rd_reg_o; // @[IDU.scala 36:9]
  assign io_valid = validReg; // @[IDU.scala 42:12]
  assign io_data_control = data_control_reg_o; // @[IDU.scala 38:19]
  assign io_ALU_ctrl = ALU_ctrl_reg_o; // @[IDU.scala 37:15]
  assign io_pc_next_type = pc_next_type_reg_o; // @[IDU.scala 39:19]
  assign io_instruction_o = inst_reg; // @[IDU.scala 40:20]
  assign io_pc_o = pc_reg; // @[IDU.scala 41:11]
  always @(posedge clock) begin
    if (reset) begin // @[IDU.scala 20:25]
      inst_reg <= 32'h413; // @[IDU.scala 20:25]
    end else if (_validReg_T) begin // @[IDU.scala 601:18]
      inst_reg <= io_inst_req_bits_inst;
    end
    if (reset) begin // @[IDU.scala 21:24]
      pc_reg <= 32'h413; // @[IDU.scala 21:24]
    end else if (_validReg_T) begin // @[IDU.scala 602:16]
      pc_reg <= io_inst_req_bits_pc;
    end
    if (reset) begin // @[IDU.scala 22:31]
      imm_type_reg_o <= 3'h0; // @[IDU.scala 22:31]
    end else if (_validReg_T) begin // @[IDU.scala 594:24]
      if (isaddi) begin // @[Mux.scala 101:16]
        imm_type_reg_o <= 3'h1;
      end else if (isxori) begin // @[Mux.scala 101:16]
        imm_type_reg_o <= 3'h1;
      end else begin
        imm_type_reg_o <= _imm_type_reg_T_20;
      end
    end
    if (reset) begin // @[IDU.scala 23:26]
      rs1_reg_o <= 5'h0; // @[IDU.scala 23:26]
    end else if (_validReg_T) begin // @[IDU.scala 595:19]
      if (isaddi) begin // @[Mux.scala 101:16]
        rs1_reg_o <= addi_Rs1;
      end else if (isxori) begin // @[Mux.scala 101:16]
        rs1_reg_o <= addi_Rs1;
      end else begin
        rs1_reg_o <= _rs1_reg_T_33;
      end
    end
    if (reset) begin // @[IDU.scala 24:26]
      rs2_reg_o <= 5'h0; // @[IDU.scala 24:26]
    end else if (_validReg_T) begin // @[IDU.scala 596:19]
      if (issw) begin // @[Mux.scala 101:16]
        rs2_reg_o <= sltu_Rs2;
      end else if (issb) begin // @[Mux.scala 101:16]
        rs2_reg_o <= sltu_Rs2;
      end else begin
        rs2_reg_o <= _rs2_reg_T_16;
      end
    end
    if (reset) begin // @[IDU.scala 25:25]
      rd_reg_o <= 5'h0; // @[IDU.scala 25:25]
    end else if (_validReg_T) begin // @[IDU.scala 597:19]
      if (isaddi) begin // @[Mux.scala 101:16]
        rd_reg_o <= addi_Rd;
      end else if (isxori) begin // @[Mux.scala 101:16]
        rd_reg_o <= addi_Rd;
      end else begin
        rd_reg_o <= _rd_reg_T_27;
      end
    end
    ALU_ctrl_reg_o <= _GEN_0[3:0]; // @[IDU.scala 26:{31,31} 598:18]
    if (reset) begin // @[IDU.scala 27:35]
      data_control_reg_o <= 3'h0; // @[IDU.scala 27:35]
    end else if (_validReg_T) begin // @[IDU.scala 599:28]
      if (isauipc) begin // @[Mux.scala 101:16]
        data_control_reg_o <= 3'h1;
      end else if (isjal) begin // @[Mux.scala 101:16]
        data_control_reg_o <= 3'h1;
      end else begin
        data_control_reg_o <= _data_control_reg_T_24;
      end
    end
    if (reset) begin // @[IDU.scala 28:35]
      pc_next_type_reg_o <= 4'h0; // @[IDU.scala 28:35]
    end else if (_validReg_T) begin // @[IDU.scala 600:28]
      if (isjal) begin // @[Mux.scala 101:16]
        pc_next_type_reg_o <= 4'h1;
      end else if (isjalr) begin // @[Mux.scala 101:16]
        pc_next_type_reg_o <= 4'h2;
      end else begin
        pc_next_type_reg_o <= _pc_next_type_reg_T_39;
      end
    end
    if (reset) begin // @[IDU.scala 29:25]
      validReg <= 1'h0; // @[IDU.scala 29:25]
    end else begin
      validReg <= io_inst_req_valid & canAccept | _validReg_T_1; // @[IDU.scala 44:12]
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
  inst_reg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  pc_reg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  imm_type_reg_o = _RAND_2[2:0];
  _RAND_3 = {1{`RANDOM}};
  rs1_reg_o = _RAND_3[4:0];
  _RAND_4 = {1{`RANDOM}};
  rs2_reg_o = _RAND_4[4:0];
  _RAND_5 = {1{`RANDOM}};
  rd_reg_o = _RAND_5[4:0];
  _RAND_6 = {1{`RANDOM}};
  ALU_ctrl_reg_o = _RAND_6[3:0];
  _RAND_7 = {1{`RANDOM}};
  data_control_reg_o = _RAND_7[2:0];
  _RAND_8 = {1{`RANDOM}};
  pc_next_type_reg_o = _RAND_8[3:0];
  _RAND_9 = {1{`RANDOM}};
  validReg = _RAND_9[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module imm(
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
  wire  is_type1 = io_imm_type == 3'h1; // @[imm.scala 21:31]
  wire  is_type2 = io_imm_type == 3'h2; // @[imm.scala 22:31]
  wire  is_type3 = io_imm_type == 3'h3; // @[imm.scala 23:31]
  wire  is_type4 = io_imm_type == 3'h4; // @[imm.scala 24:31]
  wire  is_type5 = io_imm_type == 3'h5; // @[imm.scala 25:31]
  wire  is_type6 = io_imm_type == 3'h6; // @[imm.scala 26:31]
  wire [31:0] _io_imm_T = is_type6 ? Imm_type6 : 32'h0; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_1 = is_type5 ? Imm_type5 : _io_imm_T; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_2 = is_type4 ? Imm_type4 : _io_imm_T_1; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_3 = is_type3 ? 32'h4 : _io_imm_T_2; // @[Mux.scala 101:16]
  wire [31:0] _io_imm_T_4 = is_type2 ? Imm_type2 : _io_imm_T_3; // @[Mux.scala 101:16]
  assign io_imm = is_type1 ? Imm_type1 : _io_imm_T_4; // @[Mux.scala 101:16]
endmodule
module gpr(
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
  reg [31:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [31:0] _RAND_34;
  reg [31:0] _RAND_35;
  reg [31:0] _RAND_36;
  reg [31:0] _RAND_37;
`endif // RANDOMIZE_REG_INIT
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
  _RAND_32 = {1{`RANDOM}};
  validReg = _RAND_32[0:0];
  _RAND_33 = {1{`RANDOM}};
  rs1_data_reg = _RAND_33[31:0];
  _RAND_34 = {1{`RANDOM}};
  rs2_data_reg = _RAND_34[31:0];
  _RAND_35 = {1{`RANDOM}};
  instruction_reg = _RAND_35[31:0];
  _RAND_36 = {1{`RANDOM}};
  pc_next_type_reg = _RAND_36[3:0];
  _RAND_37 = {1{`RANDOM}};
  pc_count_reg = _RAND_37[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module mem(
  input  [31:0] io_inst,
  input  [31:0] io_rs1,
  input  [31:0] io_rs2,
  input  [31:0] io_imm,
  output [31:0] io_mem_data
);
  wire [31:0] _io_mem_data_T = io_inst & io_rs1; // @[mem.scala 13:27]
  wire [31:0] _io_mem_data_T_1 = io_rs2 | io_imm; // @[mem.scala 13:47]
  assign io_mem_data = _io_mem_data_T ^ _io_mem_data_T_1; // @[mem.scala 13:37]
endmodule
module data_control(
  input  [3:0]  io_sw,
  input  [4:0]  io_rd_addr,
  input  [31:0] io_rs1_data,
  input  [31:0] io_rs2_data,
  input  [31:0] io_instruction,
  input  [3:0]  io_pc_next_type,
  input  [31:0] io_imm,
  input  [31:0] io_mem_data,
  input  [31:0] io_pc_count,
  input  [2:0]  io_data_control,
  input         io_alu_Req_ready,
  output        io_alu_Req_valid,
  output [31:0] io_alu_Req_bits_data1,
  output [31:0] io_alu_Req_bits_data2,
  output [3:0]  io_alu_Req_bits_sw,
  output [4:0]  io_alu_Req_bits_addr,
  output [31:0] io_alu_Req_bits_rs1_data,
  output [31:0] io_alu_Req_bits_rs2_data,
  output [31:0] io_alu_Req_bits_instruction,
  output [3:0]  io_alu_Req_bits_pc_next_type,
  output [31:0] io_alu_Req_bits_pc_count,
  output        io_ready,
  input         io_valid
);
  wire  control1 = io_data_control == 3'h1; // @[data_control.scala 23:34]
  wire  control2 = io_data_control == 3'h2; // @[data_control.scala 24:34]
  wire  control3 = io_data_control == 3'h3; // @[data_control.scala 25:34]
  wire [31:0] _io_alu_Req_bits_data1_T = control2 ? io_mem_data : io_rs1_data; // @[Mux.scala 101:16]
  wire [31:0] _io_alu_Req_bits_data2_T = control3 ? io_rs2_data : io_imm; // @[Mux.scala 101:16]
  assign io_alu_Req_valid = io_valid; // @[data_control.scala 48:20]
  assign io_alu_Req_bits_data1 = control1 ? io_pc_count : _io_alu_Req_bits_data1_T; // @[Mux.scala 101:16]
  assign io_alu_Req_bits_data2 = control2 ? 32'h0 : _io_alu_Req_bits_data2_T; // @[Mux.scala 101:16]
  assign io_alu_Req_bits_sw = io_sw; // @[data_control.scala 39:22]
  assign io_alu_Req_bits_addr = io_rd_addr; // @[data_control.scala 40:24]
  assign io_alu_Req_bits_rs1_data = io_rs1_data; // @[data_control.scala 41:28]
  assign io_alu_Req_bits_rs2_data = io_rs2_data; // @[data_control.scala 42:28]
  assign io_alu_Req_bits_instruction = io_instruction; // @[data_control.scala 43:31]
  assign io_alu_Req_bits_pc_next_type = io_pc_next_type; // @[data_control.scala 44:32]
  assign io_alu_Req_bits_pc_count = io_pc_count; // @[data_control.scala 45:28]
  assign io_ready = io_alu_Req_ready; // @[data_control.scala 46:12]
endmodule
module alu(
  input         clock,
  input         reset,
  output        io_alu_Req_ready,
  input         io_alu_Req_valid,
  input  [31:0] io_alu_Req_bits_data1,
  input  [31:0] io_alu_Req_bits_data2,
  input  [3:0]  io_alu_Req_bits_sw,
  input  [4:0]  io_alu_Req_bits_addr,
  input  [31:0] io_alu_Req_bits_rs1_data,
  input  [31:0] io_alu_Req_bits_rs2_data,
  input  [31:0] io_alu_Req_bits_instruction,
  input  [3:0]  io_alu_Req_bits_pc_next_type,
  input  [31:0] io_alu_Req_bits_pc_count,
  input         io_rd_Req_ready,
  output        io_rd_Req_valid,
  output [4:0]  io_rd_Req_bits_rd_addr,
  output [31:0] io_rd_Req_bits_rd_data,
  output [31:0] io_rd_Req_bits_rs1_data,
  output [31:0] io_rd_Req_bits_rs2_data,
  output [31:0] io_rd_Req_bits_instruction,
  output [3:0]  io_rd_Req_bits_pc_next_type,
  output [31:0] io_rd_Req_bits_pc_count
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] out_reg; // @[alu.scala 13:29]
  reg [4:0] rd_addr_reg; // @[alu.scala 16:28]
  reg [31:0] rs1_data_reg; // @[alu.scala 17:29]
  reg [31:0] rs2_data_reg; // @[alu.scala 18:29]
  reg [31:0] instruction_reg; // @[alu.scala 19:32]
  reg [3:0] pc_next_type_reg; // @[alu.scala 20:33]
  reg [31:0] pc_count_reg; // @[alu.scala 21:29]
  reg  validReg; // @[alu.scala 23:25]
  wire  canAccept = ~validReg | io_rd_Req_ready; // @[alu.scala 24:29]
  wire [15:0] oneHot = 16'h1 << io_alu_Req_bits_sw; // @[OneHot.scala 64:12]
  wire [32:0] add33 = io_alu_Req_bits_data1 + io_alu_Req_bits_data2; // @[alu.scala 30:39]
  wire [32:0] sub33 = io_alu_Req_bits_data1 - io_alu_Req_bits_data2; // @[alu.scala 31:39]
  wire [31:0] and32 = io_alu_Req_bits_data1 & io_alu_Req_bits_data2; // @[alu.scala 32:39]
  wire [31:0] or32 = io_alu_Req_bits_data1 | io_alu_Req_bits_data2; // @[alu.scala 33:39]
  wire [31:0] xor32 = io_alu_Req_bits_data1 ^ io_alu_Req_bits_data2; // @[alu.scala 34:39]
  wire [31:0] srai32 = $signed(io_alu_Req_bits_data1) >>> io_alu_Req_bits_data2[4:0]; // @[alu.scala 35:77]
  wire [31:0] srli32 = io_alu_Req_bits_data1 >> io_alu_Req_bits_data2[4:0]; // @[alu.scala 36:39]
  wire [62:0] _GEN_3 = {{31'd0}, io_alu_Req_bits_data1}; // @[alu.scala 38:39]
  wire [62:0] sll32 = _GEN_3 << io_alu_Req_bits_data2[4:0]; // @[alu.scala 38:39]
  wire  sltiu_b = io_alu_Req_bits_data1 < io_alu_Req_bits_data2; // @[alu.scala 39:40]
  wire  slt_b = $signed(io_alu_Req_bits_data1) < $signed(io_alu_Req_bits_data2); // @[alu.scala 40:47]
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
  wire  _validReg_T = io_alu_Req_valid & canAccept; // @[alu.scala 78:36]
  wire  _validReg_T_1 = io_rd_Req_ready ? 1'h0 : validReg; // @[alu.scala 79:18]
  assign io_alu_Req_ready = ~validReg | io_rd_Req_ready; // @[alu.scala 24:29]
  assign io_rd_Req_valid = validReg; // @[alu.scala 65:19]
  assign io_rd_Req_bits_rd_addr = rd_addr_reg; // @[alu.scala 67:26]
  assign io_rd_Req_bits_rd_data = out_reg; // @[alu.scala 66:27]
  assign io_rd_Req_bits_rs1_data = rs1_data_reg; // @[alu.scala 69:27]
  assign io_rd_Req_bits_rs2_data = rs2_data_reg; // @[alu.scala 70:27]
  assign io_rd_Req_bits_instruction = instruction_reg; // @[alu.scala 71:30]
  assign io_rd_Req_bits_pc_next_type = pc_next_type_reg; // @[alu.scala 72:31]
  assign io_rd_Req_bits_pc_count = pc_count_reg; // @[alu.scala 73:27]
  always @(posedge clock) begin
    if (reset) begin // @[alu.scala 13:29]
      out_reg <= 32'h0; // @[alu.scala 13:29]
    end else if (_validReg_T) begin // @[alu.scala 83:19]
      out_reg <= out33[31:0];
    end
    if (reset) begin // @[alu.scala 16:28]
      rd_addr_reg <= 5'h0; // @[alu.scala 16:28]
    end else if (_validReg_T) begin // @[alu.scala 84:21]
      rd_addr_reg <= io_alu_Req_bits_addr;
    end
    if (reset) begin // @[alu.scala 17:29]
      rs1_data_reg <= 32'h0; // @[alu.scala 17:29]
    end else if (_validReg_T) begin // @[alu.scala 86:22]
      rs1_data_reg <= io_alu_Req_bits_rs1_data;
    end
    if (reset) begin // @[alu.scala 18:29]
      rs2_data_reg <= 32'h0; // @[alu.scala 18:29]
    end else if (_validReg_T) begin // @[alu.scala 87:22]
      rs2_data_reg <= io_alu_Req_bits_rs2_data;
    end
    if (reset) begin // @[alu.scala 19:32]
      instruction_reg <= 32'h413; // @[alu.scala 19:32]
    end else if (_validReg_T) begin // @[alu.scala 88:25]
      instruction_reg <= io_alu_Req_bits_instruction;
    end
    if (reset) begin // @[alu.scala 20:33]
      pc_next_type_reg <= 4'h0; // @[alu.scala 20:33]
    end else if (_validReg_T) begin // @[alu.scala 89:26]
      pc_next_type_reg <= io_alu_Req_bits_pc_next_type;
    end
    if (reset) begin // @[alu.scala 21:29]
      pc_count_reg <= 32'h413; // @[alu.scala 21:29]
    end else if (_validReg_T) begin // @[alu.scala 90:22]
      pc_count_reg <= io_alu_Req_bits_pc_count;
    end
    if (reset) begin // @[alu.scala 23:25]
      validReg <= 1'h0; // @[alu.scala 23:25]
    end else begin
      validReg <= io_alu_Req_valid & canAccept | _validReg_T_1; // @[alu.scala 78:12]
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
  out_reg = _RAND_0[31:0];
  _RAND_1 = {1{`RANDOM}};
  rd_addr_reg = _RAND_1[4:0];
  _RAND_2 = {1{`RANDOM}};
  rs1_data_reg = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  rs2_data_reg = _RAND_3[31:0];
  _RAND_4 = {1{`RANDOM}};
  instruction_reg = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  pc_next_type_reg = _RAND_5[3:0];
  _RAND_6 = {1{`RANDOM}};
  pc_count_reg = _RAND_6[31:0];
  _RAND_7 = {1{`RANDOM}};
  validReg = _RAND_7[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module pc_next(
  input         clock,
  input         reset,
  output        io_pcnext_Req_ready,
  input         io_pcnext_Req_valid,
  input  [31:0] io_pcnext_Req_bits_rs1_data,
  input  [31:0] io_pcnext_Req_bits_rs2_data,
  input  [31:0] io_pcnext_Req_bits_instruction,
  input  [3:0]  io_pcnext_Req_bits_pc_next_type,
  input  [31:0] io_pcnext_Req_bits_pc_count,
  output        io_is_unknown_instruction,
  input         io_IFUReq_ready,
  output        io_IFUReq_valid,
  output [31:0] io_IFUReq_bits_addr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg  validReg; // @[pc_next.scala 12:25]
  reg [31:0] pc_next_reg; // @[pc_next.scala 13:28]
  reg  is_unknown_instruction_reg; // @[pc_next.scala 14:43]
  wire [31:0] default_pc_next = io_pcnext_Req_bits_pc_count + 32'h4; // @[pc_next.scala 16:53]
  wire  is_type1 = io_pcnext_Req_bits_pc_next_type == 4'h1; // @[pc_next.scala 19:50]
  wire  is_type2 = io_pcnext_Req_bits_pc_next_type == 4'h2; // @[pc_next.scala 20:50]
  wire  is_type3 = io_pcnext_Req_bits_pc_next_type == 4'h3; // @[pc_next.scala 21:50]
  wire  is_type4 = io_pcnext_Req_bits_pc_next_type == 4'h4; // @[pc_next.scala 22:50]
  wire  is_type5 = io_pcnext_Req_bits_pc_next_type == 4'h5; // @[pc_next.scala 23:50]
  wire  is_type6 = io_pcnext_Req_bits_pc_next_type == 4'h6; // @[pc_next.scala 24:50]
  wire  is_type7 = io_pcnext_Req_bits_pc_next_type == 4'h7; // @[pc_next.scala 25:50]
  wire  is_type8 = io_pcnext_Req_bits_pc_next_type == 4'h8; // @[pc_next.scala 26:50]
  wire  is_type9 = io_pcnext_Req_bits_pc_next_type == 4'h9; // @[pc_next.scala 27:50]
  wire  is_type10 = io_pcnext_Req_bits_pc_next_type == 4'ha; // @[pc_next.scala 28:50]
  wire  is_eql = io_pcnext_Req_bits_rs1_data == io_pcnext_Req_bits_rs2_data; // @[pc_next.scala 30:44]
  wire  is_more_equ = $signed(io_pcnext_Req_bits_rs1_data) >= $signed(io_pcnext_Req_bits_rs2_data); // @[pc_next.scala 31:56]
  wire  is_less = $signed(io_pcnext_Req_bits_rs1_data) < $signed(io_pcnext_Req_bits_rs2_data); // @[pc_next.scala 32:52]
  wire  is_more_equ_u = io_pcnext_Req_bits_rs1_data >= io_pcnext_Req_bits_rs2_data; // @[pc_next.scala 33:51]
  wire  is_less_u = io_pcnext_Req_bits_rs1_data < io_pcnext_Req_bits_rs2_data; // @[pc_next.scala 34:47]
  wire [18:0] _beq_result_T_2 = io_pcnext_Req_bits_instruction[31] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _beq_result_T_7 = {_beq_result_T_2,io_pcnext_Req_bits_instruction[31],io_pcnext_Req_bits_instruction[7],
    io_pcnext_Req_bits_instruction[30:25],io_pcnext_Req_bits_instruction[11:8],1'h0}; // @[Cat.scala 31:58]
  wire [31:0] _beq_result_T_9 = io_pcnext_Req_bits_pc_count + _beq_result_T_7; // @[pc_next.scala 38:44]
  wire [31:0] beq_result = is_eql ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bge_result = is_more_equ ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] blt_result = is_less ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bltu_result = is_less_u ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bgeu_result = is_more_equ_u ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire  _bne_result_T = ~is_eql; // @[pc_next.scala 58:5]
  wire [31:0] bne_result = _bne_result_T ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [10:0] _pc_nexto_T_2 = io_pcnext_Req_bits_instruction[31] ? 11'h7ff : 11'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _pc_nexto_T_7 = {_pc_nexto_T_2,io_pcnext_Req_bits_instruction[31],io_pcnext_Req_bits_instruction[19:12],
    io_pcnext_Req_bits_instruction[20],io_pcnext_Req_bits_instruction[30:21],1'h0}; // @[Cat.scala 31:58]
  wire [31:0] _pc_nexto_T_9 = io_pcnext_Req_bits_pc_count + _pc_nexto_T_7; // @[pc_next.scala 62:46]
  wire [19:0] _pc_nexto_T_12 = io_pcnext_Req_bits_instruction[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _pc_nexto_T_14 = {_pc_nexto_T_12,io_pcnext_Req_bits_instruction[31:20]}; // @[Cat.scala 31:58]
  wire [31:0] _pc_nexto_T_16 = io_pcnext_Req_bits_rs1_data + _pc_nexto_T_14; // @[pc_next.scala 63:47]
  wire [31:0] _pc_nexto_T_18 = _pc_nexto_T_16 & 32'hfffffffe; // @[pc_next.scala 63:142]
  wire [31:0] _pc_nexto_T_19 = is_type10 ? bltu_result : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] _pc_nexto_T_20 = is_type9 ? blt_result : _pc_nexto_T_19; // @[Mux.scala 101:16]
  wire [31:0] _pc_nexto_T_21 = is_type8 ? bgeu_result : _pc_nexto_T_20; // @[Mux.scala 101:16]
  wire [31:0] _pc_nexto_T_22 = is_type7 ? bge_result : _pc_nexto_T_21; // @[Mux.scala 101:16]
  wire [31:0] _pc_nexto_T_23 = is_type5 ? bne_result : _pc_nexto_T_22; // @[Mux.scala 101:16]
  wire [31:0] _pc_nexto_T_24 = is_type6 ? beq_result : _pc_nexto_T_23; // @[Mux.scala 101:16]
  wire [31:0] _pc_nexto_T_25 = is_type4 ? io_pcnext_Req_bits_pc_count : _pc_nexto_T_24; // @[Mux.scala 101:16]
  wire  canAccept = ~validReg | io_IFUReq_ready; // @[pc_next.scala 78:29]
  wire  _validReg_T = io_pcnext_Req_valid & canAccept; // @[pc_next.scala 80:39]
  wire  _validReg_T_1 = io_IFUReq_ready ? 1'h0 : validReg; // @[pc_next.scala 81:18]
  assign io_pcnext_Req_ready = ~validReg | io_IFUReq_ready; // @[pc_next.scala 78:29]
  assign io_is_unknown_instruction = is_unknown_instruction_reg; // @[pc_next.scala 89:29]
  assign io_IFUReq_valid = validReg; // @[pc_next.scala 88:19]
  assign io_IFUReq_bits_addr = pc_next_reg; // @[pc_next.scala 87:23]
  always @(posedge clock) begin
    if (reset) begin // @[pc_next.scala 12:25]
      validReg <= 1'h0; // @[pc_next.scala 12:25]
    end else begin
      validReg <= io_pcnext_Req_valid & canAccept | _validReg_T_1; // @[pc_next.scala 80:12]
    end
    if (reset) begin // @[pc_next.scala 13:28]
      pc_next_reg <= 32'h413; // @[pc_next.scala 13:28]
    end else if (_validReg_T) begin // @[pc_next.scala 84:21]
      if (is_type1) begin // @[Mux.scala 101:16]
        pc_next_reg <= _pc_nexto_T_9;
      end else if (is_type2) begin // @[Mux.scala 101:16]
        pc_next_reg <= _pc_nexto_T_18;
      end else begin
        pc_next_reg <= _pc_nexto_T_25;
      end
    end
    if (reset) begin // @[pc_next.scala 14:43]
      is_unknown_instruction_reg <= 1'h0; // @[pc_next.scala 14:43]
    end else if (_validReg_T) begin // @[pc_next.scala 85:36]
      is_unknown_instruction_reg <= is_type3;
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
  validReg = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  pc_next_reg = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  is_unknown_instruction_reg = _RAND_2[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module top(
  input   clock,
  input   reset,
  output  io_is_unknown_instruction
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
  IFU b_ifu ( // @[top.scala 12:22]
    .clock(b_ifu_clock),
    .reset(b_ifu_reset),
    .io_addr_Req_ready(b_ifu_io_addr_Req_ready),
    .io_addr_Req_valid(b_ifu_io_addr_Req_valid),
    .io_addr_Req_bits_addr(b_ifu_io_addr_Req_bits_addr),
    .io_sramReq_ready(b_ifu_io_sramReq_ready),
    .io_sramReq_valid(b_ifu_io_sramReq_valid),
    .io_sramReq_bits_addr(b_ifu_io_sramReq_bits_addr)
  );
  SRAM c_sram ( // @[top.scala 13:22]
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
  IDU d_idu ( // @[top.scala 14:21]
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
    .io_pc_o(d_idu_io_pc_o)
  );
  imm e_imm ( // @[top.scala 15:21]
    .io_instruction(e_imm_io_instruction),
    .io_imm_type(e_imm_io_imm_type),
    .io_imm(e_imm_io_imm)
  );
  gpr f_gpr ( // @[top.scala 16:21]
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
  mem g_mem ( // @[top.scala 17:21]
    .io_inst(g_mem_io_inst),
    .io_rs1(g_mem_io_rs1),
    .io_rs2(g_mem_io_rs2),
    .io_imm(g_mem_io_imm),
    .io_mem_data(g_mem_io_mem_data)
  );
  data_control h_data_control ( // @[top.scala 18:30]
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
  alu i_alu ( // @[top.scala 19:21]
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
    .io_rd_Req_bits_pc_count(i_alu_io_rd_Req_bits_pc_count)
  );
  pc_next j_pc_next ( // @[top.scala 20:25]
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
