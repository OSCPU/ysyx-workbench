//import "DPI-C" function void ebreak(input int inst);
module ysyx_23060111_top(
  input       rst,
  input       clk,
  input[31:0] inst,
  output [31:0] pc,
  output [31:0] halt_ret,
  output inv_flag//invalid_opcode
  
 );

//pc
  //wire[31:0] dnpc;
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
ysyx_23060111_pc pc_renew (clk,rst,snpc,pc);

//init reg
ysyx_23060111_reg #(5,32) reg_$0(clk,wdata,waddr,raddr,wen,rout,halt_ret);

 //init IDU
ysyx_23060111_IDU init_IDU (inst,opcode,rd,funct3,rs1,rs2,funct7,type_i,imm,inv_flag);

 //init EXU
ysyx_23060111_EXU init_EXU (rout,pc,snpc,opcode,rd,funct3,rs1,rs2,funct7,type_i,imm,wdata,waddr,raddr,wen);



endmodule


