module IDU (
  input [31:0] instr,
  input clk,
  output reg [4:0] rs1,
  output reg [4:0] rs2,
  output reg [4:0] rd,
  output reg [31:0] imm,
  output reg [6:0] opcode,
  output reg [2:0] func3,
  output reg [6:0] func7,
  output wen
  
);


  
    // 提取基本字段
    assign opcode = instr[6:0];
    assign func3  = instr[14:12];
    assign func7  = instr[31:25];
    assign rs1    = instr[19:15];
    assign rs2    = instr[24:20];
    assign rd     = instr[11:7];
always @(posedge clk) begin	
    // 根据指令格式解码立即数
    case (opcode)
      7'b0110011: begin // R 型指令add sltu
        imm = 32'b0; // R 型指令没有立即数
        wen =1;
      end
      7'b0010011, 7'b0000011: begin // I 型指令（如 addi, lw, jalr）
        imm = {{20{instr[31]}}, instr[31:20]}; // 符号扩展addi
      		if(func3==3'b011)begin//lw
      			imm={20'b0,instr[31:20]};
						if(func3==3'b100)begin//xori
							imm={20'b0,instr[31:20]};
						end
						if(func3==3'b001)begin//slli
							imm={26'b0,instr[25:20]};
						end
						if(func3==3'b101)begin//srli srai除外
							imm={26'b0,instr[25:20]};
						end
      		end
					
        //$display("Instr: %h, RS1: %d, RS2: %d, RD: %d, Imm: %h, Opcode: %b, Func3: %b, Func7: %b",instr, rs1, rs2, rd, imm, opcode, func3, func7);
        wen =1;
      end
      7'b0100011: begin // S 型指令（如 sw, sh, sb）
        imm = {{20{instr[31]}}, instr[31:25], instr[11:7]}; // 符号扩展
				wen =0;
      end
      7'b1100011: begin // B 型指令（如 beq, bne）
        imm = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0}; // 符号扩展
       wen =0;
			
			end
      7'b0110111, 7'b0010111: begin // U 型指令（如 lui, auipc）
        imm = {instr[31:12], 12'b0}; // 高 20 位立即数，低 12 置 0
        //$display("Instr: %h, RS1: %d, RS2: %d, RD: %d, Imm: %h, Opcode: %b, Func3: %b, Func7: %b",instr,rs1,rs2,rd,imm,opcode, func3,func7);
        wen =1;
      end
      
      7'b1101111: begin // J 型指令（如 jal 和 jalr）
     // jal
      imm = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0}; // 符号扩展
      wen=1;
      end
  7'b1100111: begin // jalr
      imm = {{20{instr[31]}}, instr[31:20]}; // I 型指令的符号扩展
      wen=1;
    end 
 
      default: begin
        imm = 32'b0; // 其他情况，立即数默认 0
				wen =0;
      end
    endcase
  end

    
 
/*always @(posedge clk) begin
    $display("RS1: %b, RD: %b,fun:%b Imm: %b, Opcode: %b", rs1, rd,func3 ,imm, opcode);
end*/
//	assign func7 = instr[31:25];
endmodule

