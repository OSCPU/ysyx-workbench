module ysyx_23060111_EXU(
  input[31:0] rout,
  input [31:0] pc,
  output reg[31:0] dnpc,
  input[6:0] opcode,
  input[11:7] rd,
  input[14:12] funct3,
  input[19:15] rs1,
  input[24:20] rs2,
  input[31:25] funct7,
  input[3:0] type_i,
  input[31:0] imm,
  output reg [31:0] wdata,
  output[4:0] waddr,
  output[4:0] raddr,
  input [31:0] snpc,
  output  wen
);
  assign waddr=rd[11:7]; //R(rd)
  assign raddr=rs1[19:15]; //src1
  assign wen=1'b1;

/*
 ysyx_23060111_MuxKeyWithDefault #(5, 4, 64 ) i1 ({wdata,dnpc},type_i , {32'b0,snpc}, {
	4'b0001, {pc+imm,snpc},
	4'b0010, {imm,snpc},
	4'b0011, {snpc,pc+imm},
	4'b0100, {rout+imm,snpc},
	4'b0101, {snpc,imm+rout}
  });
  */

  always @(type_i)
	begin
	case(type_i)
	//auipc  UPC
	4'b0001:begin
 	     wdata=pc+imm;
	     dnpc=snpc;	
	     end
	//lui    U
	4'b0010:begin
	     wdata=imm;
	     dnpc=snpc;
	     end
	//jal    J
	4'b0011:begin
	     wdata=snpc;
	     dnpc=pc+imm;
             end
	//addi   I
	4'b0100:begin
	     wdata=rout+imm;
	     dnpc=snpc;
	     end
	//jalr   JR
	4'b0101:begin
	     wdata=snpc;
	     dnpc=imm+rout;
	     end
	default:begin 
	     wdata=32'h00000000;
	     dnpc=snpc;
	     end 
	endcase
	end

endmodule
  
