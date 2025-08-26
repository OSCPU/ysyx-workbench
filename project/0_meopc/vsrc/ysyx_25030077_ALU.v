module ysyx_25030077_ALU(
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
  output [31:0] io_rd_Req_bits_pc_count,
  output        io_carry,
  output        io_overflow
);
  reg [31:0] out_reg; // @[alu.scala 13:29]
  reg  carry_reg; // @[alu.scala 14:29]
  reg  overflow_reg; // @[alu.scala 15:29]
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
  wire [62:0] _GEN_4 = {{31'd0}, io_alu_Req_bits_data1}; // @[alu.scala 38:39]
  wire [62:0] sll32 = _GEN_4 << io_alu_Req_bits_data2[4:0]; // @[alu.scala 38:39]
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
  wire [31:0] _carry_reg_T_2 = _validReg_T ? {{31'd0}, out33[32]} : out_reg; // @[alu.scala 92:19]
  wire  a31 = io_alu_Req_bits_data1[31]; // @[alu.scala 94:34]
  wire  b31 = io_alu_Req_bits_data2[31]; // @[alu.scala 95:34]
  wire  s31 = out33[31]; // @[alu.scala 96:18]
  wire  _overflowAddBool_T = a31 ^ s31; // @[alu.scala 99:30]
  wire  _overflowAddBool_T_1 = a31 ^ b31; // @[alu.scala 99:45]
  wire  overflowAddBool = (a31 ^ s31) & ~(a31 ^ b31); // @[alu.scala 99:37]
  wire  overflowSubBool = _overflowAddBool_T & _overflowAddBool_T_1; // @[alu.scala 100:37]
  wire  overflow_rego = oneHot[0] & overflowAddBool | oneHot[1] & overflowSubBool; // @[Mux.scala 27:73]
  wire [31:0] _GEN_3 = reset ? 32'h0 : _carry_reg_T_2; // @[alu.scala 14:{29,29} 92:13]
  assign io_alu_Req_ready = ~validReg | io_rd_Req_ready; // @[alu.scala 24:29]
  assign io_rd_Req_valid = validReg; // @[alu.scala 65:19]
  assign io_rd_Req_bits_rd_addr = rd_addr_reg; // @[alu.scala 67:26]
  assign io_rd_Req_bits_rd_data = out_reg; // @[alu.scala 66:27]
  assign io_rd_Req_bits_rs1_data = rs1_data_reg; // @[alu.scala 69:27]
  assign io_rd_Req_bits_rs2_data = rs2_data_reg; // @[alu.scala 70:27]
  assign io_rd_Req_bits_instruction = instruction_reg; // @[alu.scala 71:30]
  assign io_rd_Req_bits_pc_next_type = pc_next_type_reg; // @[alu.scala 72:31]
  assign io_rd_Req_bits_pc_count = pc_count_reg; // @[alu.scala 73:27]
  assign io_carry = carry_reg; // @[alu.scala 75:15]
  assign io_overflow = overflow_reg; // @[alu.scala 76:15]
  always @(posedge clock) begin
    if (reset) begin // @[alu.scala 13:29]
      out_reg <= 32'h0; // @[alu.scala 13:29]
    end else if (_validReg_T) begin // @[alu.scala 83:19]
      out_reg <= out33[31:0];
    end
    carry_reg <= _GEN_3[0]; // @[alu.scala 14:{29,29} 92:13]
    if (reset) begin // @[alu.scala 15:29]
      overflow_reg <= 1'h0; // @[alu.scala 15:29]
    end else if (_validReg_T) begin // @[alu.scala 121:22]
      overflow_reg <= overflow_rego;
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
endmodule