module ysyx_23060111_top(
  input       rst,
  input       clk,
  input[31:0] inst,
  output[31:0] val,
  output[31:0] snpc,
  output[31:0] dnpc,
  output[31:0] pc,
  output[31:20] imm,
  output[19:15] rs1,
  output[11:7] rd,
  //output[31:0] out1,
  output[31:0] out,
  output[31:0] reg_out,
  output[31:0] reg_out1,
  output[19:15] rbb,
  output[9:0] rbb1
);

assign val=inst;
assign snpc=pc+32'h4;
 
 //init reg
ysyx_23060111_reg #(1,32) reg_$0(clk,0,1'b0,1'b1,out);
//ysyx_23060111_reg #(1,32) reg_t0(clk,0,1'b1,1'b1,out1);

 //init IDU
 ysyx_23060111_IDU init_IDU (snpc,inst,dnpc,imm,rs1,rd,rbb1);

 //init EXU
 ysyx_23060111_EXU init_EXU (clk,rst,dnpc,imm,rs1,rd,pc,reg_out,reg_out1,rbb);
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
