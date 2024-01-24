//import "DPI-C" function void ebreak(input int inst);
module ysyx_23060111_top(
  input       rst,
  input       clk,
  input[31:0] inst,
  output [31:0] pc
 );

//pc
  wire[31:0] dnpc;
  wire[31:0] snpc;

//IDU
  wire[6:0] opcode;
  wire[11:7] rd;
  wire[14:12] funct3;
  wire[19:15] rs1;
  wire[24:20] rs2;
  wire[31:25] funct7;
  wire[3:0] type_i;
  wire[31:0] imm;

//reg
  wire[31:0] wdata;
  wire[4:0] waddr;
  wire[4:0] raddr;
  wire wen;
  wire[31:0] rout;


//init pc
ysyx_23060111_pc pc_renew (clk,rst,snpc,dnpc,pc);

//init reg
ysyx_23060111_reg #(5,32) reg_$0(clk,wdata,waddr,raddr,wen,rout);

 //init IDU
ysyx_23060111_IDU init_IDU (inst,opcode,rd,funct3,rs1,rs2,funct7,type_i,imm);

 //init EXU
ysyx_23060111_EXU init_EXU (rout,pc,snpc,opcode,rd,funct3,rs1,rs2,funct7,type_i,imm,wdata,waddr,raddr,dnpc,wen);



endmodule


