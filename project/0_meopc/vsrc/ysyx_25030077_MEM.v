module ysyx_25030077_MEM(
  input         clock,
  input         reset,
  output        io_sram_Req_ready,
  input         io_sram_Req_valid,
  input  [31:0] io_rs1,
  input  [31:0] io_rs2,
  input  [31:0] io_imm,
  input  [2:0]  io_r_mask,
  input  [2:0]  io_w_mask,
  output [31:0] io_mem_data,
  input         io_gpr_Req_ready,
  output        io_gpr_Req_valid
);
  wire  [31:0] io_r_mask_ext = {29'b0, io_r_mask};
  wire  [31:0] io_w_mask_ext = {29'b0, io_w_mask};
  import "DPI-C" function bit[31:0] mem_data_read(input bit[31:0] instruction_in, input bit[31:0] rs1_data_in, input bit[31:0] rs2_data_in, input bit[31:0] imm_data_in);
   
  export "DPI-C" function wmask_read;
  function int wmask_read();
    return {io_w_mask_ext};

  endfunction
  wire  [31:0] valid = {31'b0, io_sram_Req_valid};
  export "DPI-C" function valid_read;
  function int valid_read();
    return {valid};
  endfunction
 

  reg [31:0] mem_data_Reg; // @[mem.scala 16:29]
  reg  validReg; // @[mem.scala 17:25]
  wire  canAccept = ~validReg | io_gpr_Req_ready; // @[mem.scala 18:29]
  wire  _validReg_T = io_sram_Req_valid & canAccept; // @[mem.scala 24:37]
  wire  _validReg_T_1 = io_gpr_Req_ready ? 1'h0 : validReg; // @[mem.scala 25:18]
  
  assign io_sram_Req_ready = ~validReg | io_gpr_Req_ready; // @[mem.scala 18:29]
  assign io_mem_data = mem_data_Reg; // @[mem.scala 22:15]
  assign io_gpr_Req_valid = validReg; // @[mem.scala 21:20]
  always @(posedge clock) begin
    if (reset) begin // @[mem.scala 16:29]
      mem_data_Reg <= 32'h0; // @[mem.scala 16:29]
    end else if (_validReg_T) begin // @[mem.scala 27:22]
      mem_data_Reg <= mem_data_read(io_r_mask_ext, io_rs1, io_rs2, io_imm);
    end
    if (reset) begin // @[mem.scala 17:25]
      validReg <= 1'h0; // @[mem.scala 17:25]
    end else begin
      validReg <= io_sram_Req_valid & canAccept | _validReg_T_1; // @[mem.scala 24:12]
    end
  end
endmodule
