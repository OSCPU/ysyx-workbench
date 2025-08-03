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

  export "DPI-C" function pc_read_data;
  function int pc_read_data();
    return {io_IFUReq_bits_addr};
  endfunction

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
  output [31:0] io_instOut,
  output inst_valid
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] instReg; // @[SRAM.scala 15:24]
  assign io_instOut = instReg; // @[SRAM.scala 26:14]

  wire [31:0] dpi_inst;
  import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
  assign dpi_inst = addr_read(io_req_bits_addr);

  always @(posedge clock) begin
    if (reset) begin // @[SRAM.scala 15:24]
      instReg <= 32'h413; // @[SRAM.scala 15:24]
    end else if (!(io_req_valid)) begin // @[SRAM.scala 17:17]
      instReg <= dpi_inst;
    end
  end
  assign inst_valid = io_req_valid; // @[SRAM.scala 19:20]
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
module ysyx_25030077_IFU(
  input         clock,
  input         reset,
  input  [31:0] io_addr_in,
  output [31:0] io_instOut,
  output [31:0] io_pc_count,
  output        io_inst_valid
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
    .io_instOut(sram_io_instOut),
    .inst_valid(io_inst_valid)
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


// module IFU(
//   input         clock,
//   input         reset,
//   input  [31:0] io_addrIn,
//   output        io_sramReq_valid,
//   output [31:0] io_sramReq_bits_addr,
//   output        io_sramResp_ready,
//   input         io_sramResp_valid,
//   input  [31:0] io_sramResp_bits_inst,
//   output [31:0] io_instOut
// );
// `ifdef RANDOMIZE_REG_INIT
//   reg [31:0] _RAND_0;
//   reg [31:0] _RAND_1;
// `endif // RANDOMIZE_REG_INIT
//   reg  reqValid; // @[IFU.scala 13:25]
//   reg [31:0] instReg; // @[IFU.scala 14:21]
//   wire  respFire = io_sramResp_ready & io_sramResp_valid; // @[Decoupled.scala 50:35]
//   assign io_sramReq_valid = reqValid; // @[IFU.scala 28:20]
//   assign io_sramReq_bits_addr = io_addrIn; // @[IFU.scala 16:24]
//   assign io_sramResp_ready = 1'h1; // @[IFU.scala 18:21]
//   assign io_instOut = instReg; // @[IFU.scala 30:14]
//   always @(posedge clock) begin
//     if (reset) begin // @[IFU.scala 13:25]
//       reqValid <= 1'h0; // @[IFU.scala 13:25]
//       instReg <=  32'h413;
//     end else begin
//       reqValid <= 1'h1; // @[IFU.scala 22:12]
//     end
//     if (respFire) begin // @[IFU.scala 27:17]
//       instReg <= io_sramResp_bits_inst;
//     end
//   end
// // Register and memory initialization
// `ifdef RANDOMIZE_GARBAGE_ASSIGN
// `define RANDOMIZE
// `endif
// `ifdef RANDOMIZE_INVALID_ASSIGN
// `define RANDOMIZE
// `endif
// `ifdef RANDOMIZE_REG_INIT
// `define RANDOMIZE
// `endif
// `ifdef RANDOMIZE_MEM_INIT
// `define RANDOMIZE
// `endif
// `ifndef RANDOM
// `define RANDOM $random
// `endif
// `ifdef RANDOMIZE_MEM_INIT
//   integer initvar;
// `endif
// `ifndef SYNTHESIS
// `ifdef FIRRTL_BEFORE_INITIAL
// `FIRRTL_BEFORE_INITIAL
// `endif
// initial begin
//   `ifdef RANDOMIZE
//     `ifdef INIT_RANDOM
//       `INIT_RANDOM
//     `endif
//     `ifndef VERILATOR
//       `ifdef RANDOMIZE_DELAY
//         #`RANDOMIZE_DELAY begin end
//       `else
//         #0.002 begin end
//       `endif
//     `endif
// `ifdef RANDOMIZE_REG_INIT
//   _RAND_0 = {1{`RANDOM}};
//   reqValid = _RAND_0[0:0];
//   _RAND_1 = {1{`RANDOM}};
//   instReg = _RAND_1[31:0];
// `endif // RANDOMIZE_REG_INIT
//   `endif // RANDOMIZE
// end // initial
// `ifdef FIRRTL_AFTER_INITIAL
// `FIRRTL_AFTER_INITIAL
// `endif
// `endif // SYNTHESIS
// endmodule
// module SRAM(
//   input         clock,
//   input         reset,
//   output        io_req_ready,
//   input         io_req_valid,
//   input  [31:0] io_req_bits_addr,
//   output        io_resp_valid,
//   output [31:0] io_resp_bits_inst
// );
// `ifdef RANDOMIZE_REG_INIT
//   reg [31:0] _RAND_0;
//   reg [31:0] _RAND_1;
// `endif // RANDOMIZE_REG_INIT
//   reg [31:0] addrReg; // @[SRAM.scala 13:20]
//   reg  validReg; // @[SRAM.scala 15:25]
//   wire  reqFire = io_req_ready & io_req_valid; // @[Decoupled.scala 50:35]
//   assign io_req_ready = 1'h1; // @[SRAM.scala 11:16]
//   assign io_resp_valid = validReg; // @[SRAM.scala 27:17]
//   import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
//   assign io_resp_bits_inst = addrReg;
//   // addr_read(io_req_bits_addr);
//   always @(posedge clock) begin
//     if (reqFire) begin // @[SRAM.scala 18:17]
//       $display("当前PC = 0x%08x", io_req_bits_addr);
//       addrReg <= addr_read(io_req_bits_addr);
//     end
//     if (reset) begin // @[SRAM.scala 15:25]
//       addrReg <=  32'h413; // @[SRAM.scala 15:25]
//       validReg <= 1'h0; // @[SRAM.scala 15:25]
//     end else begin
//       validReg <= 1'h1; // @[SRAM.scala 21:12]
//     end
//   end
// // Register and memory initialization
// `ifdef RANDOMIZE_GARBAGE_ASSIGN
// `define RANDOMIZE
// `endif
// `ifdef RANDOMIZE_INVALID_ASSIGN
// `define RANDOMIZE
// `endif
// `ifdef RANDOMIZE_REG_INIT
// `define RANDOMIZE
// `endif
// `ifdef RANDOMIZE_MEM_INIT
// `define RANDOMIZE
// `endif
// `ifndef RANDOM
// `define RANDOM $random
// `endif
// `ifdef RANDOMIZE_MEM_INIT
//   integer initvar;
// `endif
// `ifndef SYNTHESIS
// `ifdef FIRRTL_BEFORE_INITIAL
// `FIRRTL_BEFORE_INITIAL
// `endif
// initial begin
//   `ifdef RANDOMIZE
//     `ifdef INIT_RANDOM
//       `INIT_RANDOM
//     `endif
//     `ifndef VERILATOR
//       `ifdef RANDOMIZE_DELAY
//         #`RANDOMIZE_DELAY begin end
//       `else
//         #0.002 begin end
//       `endif
//     `endif
// `ifdef RANDOMIZE_REG_INIT
//   _RAND_0 = {1{`RANDOM}};
//   addrReg = _RAND_0[31:0];
//   _RAND_1 = {1{`RANDOM}};
//   validReg = _RAND_1[0:0];
// `endif // RANDOMIZE_REG_INIT
//   `endif // RANDOMIZE
// end // initial
// `ifdef FIRRTL_AFTER_INITIAL
// `FIRRTL_AFTER_INITIAL
// `endif
// `endif // SYNTHESIS
// endmodule
// module ysyx_25030077_IFU(
//   input         clock,
//   input         reset,
//   input  [31:0] io_addrIn,
//   output [31:0] io_instOut
// );
//   wire  ifu_clock; // @[top.scala 11:20]
//   wire  ifu_reset; // @[top.scala 11:20]
//   wire [31:0] ifu_io_addrIn; // @[top.scala 11:20]
//   wire  ifu_io_sramReq_valid; // @[top.scala 11:20]
//   wire [31:0] ifu_io_sramReq_bits_addr; // @[top.scala 11:20]
//   wire  ifu_io_sramResp_ready; // @[top.scala 11:20]
//   wire  ifu_io_sramResp_valid; // @[top.scala 11:20]
//   wire [31:0] ifu_io_sramResp_bits_inst; // @[top.scala 11:20]
//   wire [31:0] ifu_io_instOut; // @[top.scala 11:20]
//   wire  sram_clock; // @[top.scala 12:20]
//   wire  sram_reset; // @[top.scala 12:20]
//   wire  sram_io_req_ready; // @[top.scala 12:20]
//   wire  sram_io_req_valid; // @[top.scala 12:20]
//   wire [31:0] sram_io_req_bits_addr; // @[top.scala 12:20]
//   wire  sram_io_resp_valid; // @[top.scala 12:20]
//   wire [31:0] sram_io_resp_bits_inst; // @[top.scala 12:20]
//   IFU ifu ( // @[top.scala 11:20]
//     .clock(ifu_clock),
//     .reset(ifu_reset),
//     .io_addrIn(ifu_io_addrIn),
//     .io_sramReq_valid(ifu_io_sramReq_valid),
//     .io_sramReq_bits_addr(ifu_io_sramReq_bits_addr),
//     .io_sramResp_ready(ifu_io_sramResp_ready),
//     .io_sramResp_valid(ifu_io_sramResp_valid),
//     .io_sramResp_bits_inst(ifu_io_sramResp_bits_inst),
//     .io_instOut(ifu_io_instOut)
//   );
//   SRAM sram ( // @[top.scala 12:20]
//     .clock(sram_clock),
//     .reset(sram_reset),
//     .io_req_ready(sram_io_req_ready),
//     .io_req_valid(sram_io_req_valid),
//     .io_req_bits_addr(sram_io_req_bits_addr),
//     .io_resp_valid(sram_io_resp_valid),
//     .io_resp_bits_inst(sram_io_resp_bits_inst)
//   );
//   assign io_instOut = ifu_io_instOut; // @[top.scala 22:14]
//   assign ifu_clock = clock;
//   assign ifu_reset = reset;
//   assign ifu_io_addrIn = io_addrIn; // @[top.scala 19:17]
//   assign ifu_io_sramResp_valid = sram_io_resp_valid; // @[top.scala 16:16]
//   assign ifu_io_sramResp_bits_inst = sram_io_resp_bits_inst; // @[top.scala 16:16]
//   assign sram_clock = clock;
//   assign sram_reset = reset;
//   assign sram_io_req_valid = ifu_io_sramReq_valid; // @[top.scala 15:15]
//   assign sram_io_req_bits_addr = ifu_io_sramReq_bits_addr; // @[top.scala 15:15]
// endmodule
// module ysyx_25030077_IFU(
//   input         clock,
//   input         reset,
//   input  [31:0] io_addrIn,
//   output [31:0] io_instOut
// );

//   import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
//   assign io_instOut = addr_read(io_addrIn);
// endmodule