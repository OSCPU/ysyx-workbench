import "DPI-C" function void ebreak(input int inst);
module ysyx_23060111_IDU(
  input [31:0] inst,
  output [6:0] opcode,
  output [11:7] rd,
  output [14:12] funct3,
  output [19:15] rs1,
  output [24:20] rs2,
  output [31:25] funct7,
  output [3:0] type_i,
  output [31:0] imm

 );
always @(inst)
begin 
     ebreak(inst);
end
  
  assign opcode=inst[6:0];
  assign rd=inst[11:7];
  assign funct3=inst[14:12];
  assign rs1=inst[19:15];
  assign rs2=inst[24:20];
  assign funct7=inst[31:25];


ysyx_23060111_MuxKeyWithDefault #(5, 7, 36) typeMux ({type_i,imm}, opcode ,36'b0 , {
     					     //4'd0    type:Can't find the type
    7'b0010111, {4'b0001,inst[31:12],12'b0}, //auipc   type:UPC   4'd1
    7'b0110111, {4'b0010,inst[31:12],12'b0}, //lui     type:U   4'd2
    7'b1101111, {4'b0011,{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0}, 
                                             //jal     type:J  4'd3
    7'b0010011, {4'b0100,{20{inst[31]}},inst[31:20]}, //addi    type:I  4'd4
    7'b1100111, {4'b0101,{20{inst[31]}},inst[31:20]}  //jalr    type:JR
  });


endmodule
