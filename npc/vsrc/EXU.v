
module EXU (
	input clk,
  input [31:0] rs1_data,
  input [31:0] rs2_data,
  input [31:0] imm,
  input [6:0] alu_op,
  input [2:0] func3,
	input [31:0] instr,
  output reg [31:0]pc,
  output reg [31:0] alu_result,
  //output reg [31:0]pc_out
  output reg [31:0] pc_result
 // output pc_jump
 
);

reg [31:0]middle;
reg [31:0] mem_two;
reg [31:0]mem_data;
  always @(posedge clk) begin
  
    case (alu_op)
			7'b0110011:begin
				if(instr[31:25]==7'b0000000)begin
					alu_result=rs1_data+rs2_data;//add
					 if (func3 == 3'b011) begin//sltu
        alu_result = ($unsigned(rs1_data) < $unsigned(rs2_data)) ? 1 : 0;
    end
						if(func3 == 3'b010)begin//slt
							alu_result=(rs1_data<$signed(rs2_data))? 1 : 0;
					end
					if(func3 == 3'b100)begin // xor
						alu_result = rs1_data ^ rs2_data;
					end
					if(func3 == 3'b110)begin//or
						alu_result = rs1_data | rs2_data;
					end
					if(func3 == 3'b111)begin//and
						alu_result=rs1_data&rs2_data;
					end
					if(func3 == 3'b011)begin//sltu
						alu_result=(rs1_data<$unsigned(rs2_data))? 1 : 0;
					end
					if(func3 == 3'b001)begin//sll
						alu_result=rs1_data<<rs2_data;
					end
						if(func3 == 3'b101)begin//srl
							alu_result=rs1_data>>$unsigned(rs2_data);
						end	
				end else begin
					alu_result=rs1_data-rs2_data;
					if(func3 == 3'b101)begin//sra
									alu_result=$signed(rs1_data) >>> $signed(rs2_data);
					end
				end
			end
      7'b0010011: begin  //addi sltiu
      alu_result = rs1_data +imm;
			if(func3==3'b010)begin//slti
					alu_result=(rs1_data<$signed(imm))?1:0;
			end
			if(func3==3'b011)begin//sltiu
					alu_result=(rs1_data<$unsigned(imm))?1:0;
			end
			if(func3==3'b101&&instr[31:26]==6'b010000)begin//srai
				alu_result= $signed(rs1_data) >>>$signed(instr[25:20]);
			end
	if(func3==3'b101&&instr[31:26]==6'b000000)begin//srli
				alu_result= (rs1_data) >>$unsigned(imm);
			end
			if(func3==3'b111)begin//and
					alu_result= rs1_data & imm;
			end
			if(func3==3'b100)begin//xori
					alu_result=rs1_data ^ imm;
			end
			if(func3==3'b001)begin//slli
					alu_result=rs1_data<<imm;
			end
			if(func3==3'b110)begin//or
          alu_result = rs1_data | imm;
			end	
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
   	7'b0000011:begin  //lw
			if(func3==3'b010)begin
						alu_result=mem_read(rs1_data+imm);
	end
		if(func3==3'b000)begin
  mem_data = mem_read(rs1_data + imm);
      alu_result = {{24{mem_data[7]}}, mem_data[7:0]};

		end	
			if(func3==3'b100)begin

			 mem_data = mem_read(rs1_data + imm);
			//		$display("%08x",mem_data[7:0]);
    // 提取 mem_data 中的低 8 位字节并转换为无符号数
		 alu_result = {24'b0, mem_data[7:0]};
			end
		if(func3==3'b001)begin

		 mem_data = mem_read(rs1_data + imm);
			//		$display("%08x",mem_data[7:0]);
    // 提取 mem_data 中的低 8 位字节并转换为无符号数
	alu_result = {{16{mem_data[15]}}, mem_data[15:0]};		
					end
	if(func3==3'b101)begin

		 mem_data = mem_read(rs1_data + imm);
			//		$display("%08x",mem_data[7:0]);
    // 提取 mem_data 中的低 8 位字节并转换为无符号数
	alu_result = {16'b0, mem_data[15:0]};		
					end
	end
	
      7'b1100111:begin
       // $display("entering a jalr command\n");
     // pc_result = (rs1_data + imm) & ~1; // JALR 计算新的跳转地址，并清除最低位
      alu_result = pc + 4;
	
    end 
    7'b0100011:begin
			if(func3==3'b010)begin
			alu_result=0;
    		middle=rs1_data+imm;
    	`ifndef SYNTHESIS
				if(middle>=32'ha00003f8&&middle<=32'ha2000000)begin
						set_skip(1);
					end else begin
					        set_skip(0);
					end
    	mem_write(middle, rs2_data, 15);
    	
			`endif
		end
			if(func3==3'b001)begin
				alu_result=0;
					middle=rs1_data+imm;
if(middle>=32'ha00003f8&&middle<=32'ha2000000)begin
						set_skip(1);
					end else begin
					        set_skip(0);
					end
					mem_write(middle,rs2_data, 3);
						
				//mem_write(middle, {16'b0 ,rs2_data[15:0]});          // 写入低 8 位
    //mem_write(middle + 1, {16'b0 ,rs2_data[15:0]});     // 写入高 8 位	
			end
			if(func3==3'b000)begin
			alu_result=0;
					middle=rs1_data+imm;
	if(middle>=32'ha00003f8&&middle<=32'ha2000000)begin
						
						set_skip(1);
					end else begin
					        set_skip(0);
					end
					mem_write(middle,rs2_data, 1);
				
			end
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

