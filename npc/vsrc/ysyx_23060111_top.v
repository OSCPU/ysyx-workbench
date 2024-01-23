//import "DPI-C" function void ebreak(input int inst);
module ysyx_23060111_top(
  input       rst,
  input       clk,
  input[31:0] inst,
  output reg[31:0] pc,
  output[9:0] rbb
 );
  wire[31:0] dnpc;
  wire[31:0] snpc;
  wire[31:20] imm;
  wire[19:15] rs1;
  wire[14:12] funct3;
  wire[11:7] rd;
  wire[6:0] opcode;
  wire[31:0] wdata;
  wire[4:0] waddr;
  wire[4:0] raddr;
  wire wen;
  wire[31:0] rout;


//init reg
ysyx_23060111_reg #(5,32) reg_$0(clk,wdata,waddr,raddr,wen,rout);

 //init IDU
ysyx_23060111_IDU init_IDU (inst,imm,funct3,rs1,rd,opcode);

 //init EXU
ysyx_23060111_EXU init_EXU (dnpc,snpc,imm,rs1,funct3,rd,opcode,rout,wdata,waddr,raddr,rbb,wen);

ysyx_23060111_pc pc_renew (clk,rst,snpc,dnpc,pc);


endmodule



/*
module ysyx_23060111_MuxKeyInternal #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1, HAS_DEFAULT = 0) (
  output reg [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input [DATA_LEN-1:0] default_out,
  input [NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);

  localparam PAIR_LEN = KEY_LEN + DATA_LEN;
  wire [PAIR_LEN-1:0] pair_list [NR_KEY-1:0];
  wire [KEY_LEN-1:0] key_list [NR_KEY-1:0];
  wire [DATA_LEN-1:0] data_list [NR_KEY-1:0];

  generate
    for (genvar n = 0; n < NR_KEY; n = n + 1) begin
      assign pair_list[n] = lut[PAIR_LEN*(n+1)-1 : PAIR_LEN*n];
      assign data_list[n] = pair_list[n][DATA_LEN-1:0];
      assign key_list[n]  = pair_list[n][PAIR_LEN-1:DATA_LEN];
    end
  endgenerate

  reg [DATA_LEN-1 : 0] lut_out;
  reg hit;
  integer i;
  always @(*) begin
    lut_out = 0;
    hit = 0;
    for (i = 0; i < NR_KEY; i = i + 1) begin
      lut_out = lut_out | ({DATA_LEN{key == key_list[i]}} & data_list[i]);
      hit = hit | (key == key_list[i]);
    end
    if (!HAS_DEFAULT) out = lut_out;
    else out = (hit ? lut_out : default_out);
  end
endmodule
*/
