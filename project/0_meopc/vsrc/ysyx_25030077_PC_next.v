module ysyx_25030077_PC_next(
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

  export "DPI-C" function dnpc_read_data;
  function int dnpc_read_data();
    return {io_IFUReq_bits_addr};
  endfunction

  import "DPI-C" function bit[31:0] ecall_read(input bit[31:0] pc, input bit[3:0] type_p);
  wire [31:0] ecall_dnpc = ecall_read(io_pcnext_Req_bits_pc_count, io_pcnext_Req_bits_pc_next_type);

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
  wire  is_type11 = (io_pcnext_Req_bits_pc_next_type == 4'hb || io_pcnext_Req_bits_pc_next_type == 4'hc); // @[module.scala 27:34]
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
      validReg <= 1'h1; // @[pc_next.scala 12:25]
    end else begin
      validReg <= io_pcnext_Req_valid & canAccept | _validReg_T_1; // @[pc_next.scala 80:12]
    end
    if (reset) begin // @[pc_next.scala 13:28]
      pc_next_reg <= 32'h80000000; // @[pc_next.scala 13:28]
    end else if (_validReg_T) begin // @[pc_next.scala 84:21]
      if (is_type1) begin // @[Mux.scala 101:16]
        pc_next_reg <= _pc_nexto_T_9;
      end else if (is_type2) begin // @[Mux.scala 101:16]
        pc_next_reg <= _pc_nexto_T_18;
      end else if (is_type11) begin // @[Mux.scala 101:16]
        pc_next_reg <= ecall_dnpc;
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
endmodule
