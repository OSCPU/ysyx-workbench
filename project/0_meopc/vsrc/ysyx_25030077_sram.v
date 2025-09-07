module ysyx_25030077_SRAM(
  input         clock,
  input         reset,
  output        io_ifu_Req_ready,
  input         io_ifu_Req_valid,
  input  [31:0] io_ifu_Req_bits_addr,
  input         io_mem_Req_ready,
  output        io_mem_Req_valid,
  output [31:0] io_inst
);
  import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
  reg [31:0] instReg; // @[SRAM.scala 11:24]
  reg  validReg; // @[SRAM.scala 12:25]
  wire  canAccept = ~validReg | io_mem_Req_ready; // @[SRAM.scala 14:29]
  wire  _validReg_T = io_ifu_Req_valid & canAccept; // @[SRAM.scala 19:36]
  wire  _validReg_T_1 = io_mem_Req_ready ? 1'h0 : validReg; // @[SRAM.scala 20:18]
  assign io_ifu_Req_ready = ~validReg | io_mem_Req_ready; // @[SRAM.scala 14:29]
  assign io_mem_Req_valid = validReg; // @[SRAM.scala 16:20]
  assign io_inst = instReg; // @[SRAM.scala 17:11]
  always @(posedge clock) begin
    if (reset) begin // @[SRAM.scala 11:24]
      instReg <= 32'h413; // @[SRAM.scala 11:24]
    end else if (_validReg_T) begin // @[SRAM.scala 23:17]
      instReg <= addr_read(io_ifu_Req_bits_addr);;
    end
    if (reset) begin // @[SRAM.scala 12:25]
      validReg <= 1'h1; // @[SRAM.scala 12:25]
    end else begin
      validReg <= io_ifu_Req_valid & canAccept | _validReg_T_1; // @[SRAM.scala 19:12]
    end
  end
endmodule
