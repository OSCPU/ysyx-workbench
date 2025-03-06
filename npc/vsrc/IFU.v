module IFU (
    input clk,
    input rst,
    input [31:0] inst_in,   // 上一级传入的PC
  //  input [31:0] pc,
    output reg[31:0] pc,
    output reg [31:0] instruction_out, // 输出指令
    output reg ebreak,
 //   output  reg [31:0] pc_out,
  //  output reg valid,
		
    output reg [31:0] pc_jal   // 新的跳转地址信
);
reg [31:0] pc_out;
reg [31:0] next_pc;
reg [31:0] imm;
reg [4:0] rs1_jalr;
always @*  begin
	if (rst)
        next_pc = 32'h80000000;  // 复位时 PC 初始化
    else
        next_pc = pc + 4;
end

    always @(posedge clk ) begin
        if (rst) begin
			//		pc <= 32'h80000000;
				//		ebreak<=0;
	//					valid <=0;
            instruction_out <= 32'b0;
						pc <= 32'h80000000;       // 复位时 PC 初始化
						pc_out <= 32'h80000000;   // 确保 pc_out 也是 80000000
        end else begin
					instruction_out <= inst_in;  // 更新指令
        if (inst_in == 32'h00100073) begin
                ebreak = 1;  // ebreak指令，设置ebreak信号
            end else begin
                ebreak = 0;
            end
					 if (inst_in[6:0]==7'b1101111) begin
						 assign imm= {{11{inst_in[31]}}, inst_in[31], inst_in[19:12], inst_in[20], inst_in[30:21], 1'b0};
            pc <= pc+imm;  // 跳转指令
            pc_out <= pc+imm;
            $display("Jump to: 0x%08x", pc+imm);
           // $stop;
				 end
				  else if(inst_in[6:0]!=7'b1100111) begin
            pc <= next_pc;  // PC 正常递增
            pc_out <= next_pc;
        end
				 

            
					end
				end 
endmodule
