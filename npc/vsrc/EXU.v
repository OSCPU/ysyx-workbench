module EXU (
	input clk,
  input [31:0] rs1_data,
  input [31:0] rs2_data,
  input [31:0] imm,
  input [6:0] alu_op,
  input [2:0] func3,
  output reg [31:0]pc,
  output reg [31:0] alu_result,
  //output reg [31:0]pc_out
  output reg [31:0] pc_result
 // output pc_jump
 
);




  always @(posedge clk) begin
  
    case (alu_op)
      7'b0010011: begin
      alu_result = rs1_data +imm;
      //pc_result = pc+4; // 对于 ADDI, 不改变 PC
      //pc_jump=0;
     end
     7'b0110111: begin // LUI 操作
        alu_result = imm; // LUI 直接使用立即数
        //pc_result = pc+4;
      // pc_jump=0;
      end
      7'b0010111: begin // AUIPC 操作
        alu_result = pc + imm; // AUIPC 将立即数加到当前 PC 值
       // $display("0x%8x ",alu_result);
        //$stop;
        //pc_result = pc+4;
    // pc_jump=0;
      end
    
      7'b1101111: begin // J 型指令（如 jal 和 jalr）
      //$display("entering a jal command\n");
			 alu_result = pc + 4;
   	//pc_result = old_pc + imm; // JAL 跳转并保存返回地址
   //	pc_jump = 1;
   //	$display("0x%8x",pc_result);
   end
      7'b1100111:begin
       // $display("entering a jalr command\n");
     // pc_result = (rs1_data + imm) & ~1; // JALR 计算新的跳转地址，并清除最低位
      alu_result = pc + 4;
			//$stop;
		//	pc<=pc_result;
	//		 $display("Jump to: 0x%08x", pc_result);

	//		$stop;
     // pc_jump = 1;
     //   $display("0x%8x",pc_result);
    end 


      /*3'b010: begin // SW 操作
        pc_result = pc+4;
      end*/
      default: begin
        alu_result = 32'b0;
        ///pc_result = 32'b0;
      end
      endcase
      
  end
  

  
endmodule

