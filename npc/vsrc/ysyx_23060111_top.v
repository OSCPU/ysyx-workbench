//import "DPI-C" function void ebreak(input int inst);
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
  output[14:12] funct3,
  output[11:7] rd,
  output[6:0] opcode,
  output[31:0] wdata,
  output[4:0] waddr,
  output[4:0] raddr,
  output wen,
  output[31:0] rout,
  output[20:1] rbb
);

assign val=inst;
assign snpc=pc;

 
 //init reg
ysyx_23060111_reg #(5,32) reg_$0(clk,wdata,waddr,raddr,wen,rout);
assign wdata=0;
assign waddr=5'd0;
assign raddr=5'd0;
assign wen=1'b1;
/*
ysyx_23060111_reg #(5,32) reg_$1(clk,0,5'd1,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$2(clk,0,5'd2,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$3(clk,0,5'd3,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$4(clk,0,5'd4,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$5(clk,0,5'd5,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$6(clk,0,5'd6,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$7(clk,0,5'd7,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$8(clk,0,5'd8,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$9(clk,0,5'd9,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$10(clk,0,5'd10,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$11(clk,0,5'd11,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$12(clk,0,5'd12,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$13(clk,0,5'd13,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$14(clk,0,5'd14,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$15(clk,0,5'd15,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$16(clk,0,5'd16,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$17(clk,0,5'd17,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$18(clk,0,5'd18,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$19(clk,0,5'd19,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$20(clk,0,5'd20,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$21(clk,0,5'd21,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$22(clk,0,5'd22,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$23(clk,0,5'd23,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$24(clk,0,5'd24,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$25(clk,0,5'd25,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$26(clk,0,5'd26,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$27(clk,0,5'd27,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$28(clk,0,5'd28,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$29(clk,0,5'd29,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$30(clk,0,5'd30,1'b1,out);
ysyx_23060111_reg #(5,32) reg_$31(clk,0,5'd31,1'b1,out);
*/



 //init IDU
 ysyx_23060111_IDU init_IDU (snpc,inst,dnpc,imm,funct3,rs1,rd,opcode);

 //init EXU
 ysyx_23060111_EXU init_EXU (clk,rst,dnpc,imm,rs1,funct3,rd,opcode,pc,rbb,rout,wdata,waddr,raddr,wen);
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
