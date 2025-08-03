module addr_gen(
  input         clock,
  input         reset,
  output        io_IFUReq_valid,
  output [31:0] io_IFUReq_bits_addr,
  input  [31:0] io_pc_in
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg  addr_state; // @[addr_gen.scala 12:27]
  reg [31:0] dataReg; // @[addr_gen.scala 15:24]
  assign io_IFUReq_valid = addr_state; // @[addr_gen.scala 26:34]
  assign io_IFUReq_bits_addr = dataReg; // @[addr_gen.scala 27:23]
  always @(posedge clock) begin
    if (reset) begin // @[addr_gen.scala 12:27]
      addr_state <= 1'h0; // @[addr_gen.scala 12:27]
    end else if (addr_state) begin // @[Mux.scala 81:58]
      addr_state <= 1'h0;
    end else begin
      addr_state <= 1'h1;
    end
    if (reset) begin // @[addr_gen.scala 15:24]
      dataReg <= 32'h80000000; // @[addr_gen.scala 15:24]
    end else if (~addr_state) begin // @[addr_gen.scala 17:17]
      dataReg <= io_pc_in;
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
  addr_state = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  dataReg = _RAND_1[31:0];
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
  input         io_addr_Req_valid,
  input  [31:0] io_addr_Req_bits_addr,
  output        io_sramReq_valid,
  output [31:0] io_sramReq_bits_addr
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg  state; // @[IFU.scala 12:22]
  reg [31:0] addrReg; // @[IFU.scala 15:24]
  assign io_sramReq_valid = state; // @[IFU.scala 27:30]
  assign io_sramReq_bits_addr = addrReg; // @[IFU.scala 28:24]
  always @(posedge clock) begin
    if (reset) begin // @[IFU.scala 12:22]
      state <= 1'h0; // @[IFU.scala 12:22]
    end else if (state) begin // @[Mux.scala 81:58]
      state <= 1'h0;
    end else begin
      state <= 1'h1;
    end
    if (reset) begin // @[IFU.scala 15:24]
      addrReg <= 32'h0; // @[IFU.scala 15:24]
    end else if (state & io_addr_Req_valid) begin // @[IFU.scala 18:17]
      addrReg <= io_addr_Req_bits_addr;
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
  state = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  addrReg = _RAND_1[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module SRAM(
  input         clock,
  input         reset,
  input         io_req_valid,
  input  [31:0] io_req_bits_addr,
  output [31:0] io_instOut
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] instReg; // @[SRAM.scala 15:24]
  assign io_instOut = instReg; // @[SRAM.scala 26:14]
  always @(posedge clock) begin
    if (reset) begin // @[SRAM.scala 15:24]
      instReg <= 32'h0; // @[SRAM.scala 15:24]
    end else if (!(io_req_valid)) begin // @[SRAM.scala 17:17]
      instReg <= io_req_bits_addr;
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
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module top(
  input         clock,
  input         reset,
  input  [31:0] io_addr_in,
  output [31:0] io_instOut,
  output [31:0] io_pc_count
);
  wire  addr_gen_clock; // @[top.scala 12:25]
  wire  addr_gen_reset; // @[top.scala 12:25]
  wire  addr_gen_io_IFUReq_valid; // @[top.scala 12:25]
  wire [31:0] addr_gen_io_IFUReq_bits_addr; // @[top.scala 12:25]
  wire [31:0] addr_gen_io_pc_in; // @[top.scala 12:25]
  wire  ifu_clock; // @[top.scala 13:20]
  wire  ifu_reset; // @[top.scala 13:20]
  wire  ifu_io_addr_Req_valid; // @[top.scala 13:20]
  wire [31:0] ifu_io_addr_Req_bits_addr; // @[top.scala 13:20]
  wire  ifu_io_sramReq_valid; // @[top.scala 13:20]
  wire [31:0] ifu_io_sramReq_bits_addr; // @[top.scala 13:20]
  wire  sram_clock; // @[top.scala 14:20]
  wire  sram_reset; // @[top.scala 14:20]
  wire  sram_io_req_valid; // @[top.scala 14:20]
  wire [31:0] sram_io_req_bits_addr; // @[top.scala 14:20]
  wire [31:0] sram_io_instOut; // @[top.scala 14:20]
  addr_gen addr_gen ( // @[top.scala 12:25]
    .clock(addr_gen_clock),
    .reset(addr_gen_reset),
    .io_IFUReq_valid(addr_gen_io_IFUReq_valid),
    .io_IFUReq_bits_addr(addr_gen_io_IFUReq_bits_addr),
    .io_pc_in(addr_gen_io_pc_in)
  );
  IFU ifu ( // @[top.scala 13:20]
    .clock(ifu_clock),
    .reset(ifu_reset),
    .io_addr_Req_valid(ifu_io_addr_Req_valid),
    .io_addr_Req_bits_addr(ifu_io_addr_Req_bits_addr),
    .io_sramReq_valid(ifu_io_sramReq_valid),
    .io_sramReq_bits_addr(ifu_io_sramReq_bits_addr)
  );
  SRAM sram ( // @[top.scala 14:20]
    .clock(sram_clock),
    .reset(sram_reset),
    .io_req_valid(sram_io_req_valid),
    .io_req_bits_addr(sram_io_req_bits_addr),
    .io_instOut(sram_io_instOut)
  );
  assign io_instOut = sram_io_instOut; // @[top.scala 20:14]
  assign io_pc_count = addr_gen_io_IFUReq_bits_addr; // @[top.scala 22:15]
  assign addr_gen_clock = clock;
  assign addr_gen_reset = reset;
  assign addr_gen_io_pc_in = io_addr_in; // @[top.scala 21:21]
  assign ifu_clock = clock;
  assign ifu_reset = reset;
  assign ifu_io_addr_Req_valid = addr_gen_io_IFUReq_valid; // @[top.scala 16:22]
  assign ifu_io_addr_Req_bits_addr = addr_gen_io_IFUReq_bits_addr; // @[top.scala 16:22]
  assign sram_clock = clock;
  assign sram_reset = reset;
  assign sram_io_req_valid = ifu_io_sramReq_valid; // @[top.scala 18:18]
  assign sram_io_req_bits_addr = ifu_io_sramReq_bits_addr; // @[top.scala 18:18]
endmodule
