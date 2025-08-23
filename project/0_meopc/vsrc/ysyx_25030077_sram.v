module ysyx_25030077_sram(
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
  import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
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
      instReg <= addr_read(io_req_bits_addr);
    end
    if (reset) begin // @[SRAM.scala 11:24]
      pcReg <= 32'h80000000; // @[SRAM.scala 11:24]
    end else if (_validReg_T) begin // @[SRAM.scala 25:15]
      pcReg <= io_req_bits_addr;
    end
    if (reset) begin // @[SRAM.scala 12:25]
      validReg <= 1'h0; // @[SRAM.scala 12:25]
    end else begin
      validReg <= io_req_valid & canAccept | _validReg_T_1; // @[SRAM.scala 20:12]
    end
  end
endmodule
