`ifndef SYNTHESIS
import "DPI-C" function int mem_read(input int addr);
import "DPI-C" function void mem_write(input int addr,input int data,input int wmask);

`endif
module IFU (
    input clk,
    input rst,
//    input [31:0] inst_in,   // 上一级传入的PC
  //  input [31:0] pc,
	 input wan,
    output reg[31:0] pc,
    output reg [31:0] instruction_out, // 输出指令
    output reg ebreak,
 //   output  reg [31:0] pc_out,
  //  output reg valid,
		
    output reg [31:0] pc_jal   // 新的跳转地址信
);
reg [31:0] inst_in;
reg [31:0] pc_out;
reg [31:0] next_pc;
wire [31:0] imm;
reg [4:0] rs1_jalr;
 // 组合逻辑计算 next_pc（无需 always @*，直接赋值）
   // assign next_pc = (rst) ? 32'h80000000 : pc + 4;
assign next_pc = (rst) ? 32'h80000000 : pc+4;

		 `ifndef SYNTHESIS
 	assign instruction_out= (rst)?mem_read(pc):mem_read(pc);
`endif

		 assign imm= {{11{instruction_out[31]}}, instruction_out[31], instruction_out[19:12], instruction_out[20], instruction_out[30:21], 1'b0};   
    always @(posedge clk ) begin
        if (rst) begin
		pc <= 32'h80000000;       // 复位时 PC 初始化
           
						
						pc_out <= 32'h80000000;   // 确保 pc_out 也是 80000000
        end else begin
			//			$display("%8x ",instruction_out);
		//				$display("0x%8x ",pc);
				`ifndef SYNTHESIS

        if (mem_read(pc)==32'h00100073) begin
                ebreak <= 1;  // ebreak指令，设置ebreak信号
								
            end else begin
                ebreak <= 0;
            end
						`endif

					 if (instruction_out[6:0]==7'b1101111) begin
            pc <= pc+imm;  // 跳转指令
           // $display("Jump to: 0x%08x", pc+imm);
            //$stop;
				 end
				  else if(instruction_out[6:0]!=7'b1100111&&instruction_out[6:0]!=7'b1100011) begin
            pc <= next_pc;  // PC 正常递增

        end
				 

            
					end
				end 
endmodule
