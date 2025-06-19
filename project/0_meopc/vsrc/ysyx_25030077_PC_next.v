module ysyx_25030077_PC_next(
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

  wire [31:0] default_pc_next = io_pc_count + 32'h4; // @[module.scala 15:37]
  wire  is_type1 = io_pc_next_type == 4'h1; // @[module.scala 18:34]
  wire  is_type2 = io_pc_next_type == 4'h2; // @[module.scala 19:34]
  wire  is_type4 = io_pc_next_type == 4'h4; // @[module.scala 21:34]
  wire  is_type5 = io_pc_next_type == 4'h5; // @[module.scala 22:34]
  wire  is_type6 = io_pc_next_type == 4'h6; // @[module.scala 23:34]
  wire  is_type7 = io_pc_next_type == 4'h7; // @[module.scala 24:34]
  wire  is_type8 = io_pc_next_type == 4'h8; // @[module.scala 25:34]
  wire  is_type9 = io_pc_next_type == 4'h9; // @[module.scala 26:34]
  wire  is_type10 = io_pc_next_type == 4'ha; // @[module.scala 27:34]
  wire  is_type11 = (io_pc_next_type == 4'hb || io_pc_next_type == 4'hc); // @[module.scala 27:34]
  wire  is_eql = io_rs1_data == io_rs2_data; // @[module.scala 29:28]
  wire  is_more_equ = $signed(io_rs1_data) >= $signed(io_rs2_data); // @[module.scala 30:40]
  wire  is_less = $signed(io_rs1_data) < $signed(io_rs2_data); // @[module.scala 31:36]
  wire  is_more_equ_u = io_rs1_data >= io_rs2_data; // @[module.scala 32:35]
  wire  is_less_u = io_rs1_data < io_rs2_data; // @[module.scala 33:31]
  wire [18:0] _beq_result_T_2 = io_instruction[31] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _beq_result_T_7 = {_beq_result_T_2,io_instruction[31],io_instruction[7],io_instruction[30:25],
    io_instruction[11:8],1'h0}; // @[Cat.scala 31:58]
  wire [31:0] _beq_result_T_9 = io_pc_count + _beq_result_T_7; // @[module.scala 37:28]
  wire [31:0] beq_result = is_eql ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bge_result = is_more_equ ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] blt_result = is_less ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bltu_result = is_less_u ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [31:0] bgeu_result = is_more_equ_u ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire  _bne_result_T = ~is_eql; // @[module.scala 57:5]
  wire [31:0] bne_result = _bne_result_T ? _beq_result_T_9 : default_pc_next; // @[Mux.scala 101:16]
  wire [10:0] _io_pc_next_T_2 = io_instruction[31] ? 11'h7ff : 11'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_pc_next_T_7 = {_io_pc_next_T_2,io_instruction[31],io_instruction[19:12],io_instruction[20],
    io_instruction[30:21],1'h0}; // @[Cat.scala 31:58]
  wire [31:0] _io_pc_next_T_9 = io_pc_count + _io_pc_next_T_7; // @[module.scala 61:30]
  wire [19:0] _io_pc_next_T_12 = io_instruction[31] ? 20'hfffff : 20'h0; // @[Bitwise.scala 74:12]
  wire [31:0] _io_pc_next_T_14 = {_io_pc_next_T_12,io_instruction[31:20]}; // @[Cat.scala 31:58]
  wire [31:0] _io_pc_next_T_16 = io_rs1_data + _io_pc_next_T_14; // @[module.scala 62:31]
  wire [31:0] _io_pc_next_T_18 = _io_pc_next_T_16 & 32'hfffffffe; // @[module.scala 62:94]
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
  assign io_is_unknown_instruction = io_pc_next_type == 4'h3; // @[module.scala 20:34]
endmodule
