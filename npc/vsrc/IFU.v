module IFU (
    input clk,
    input rst,
    input [31:0] inst_in,   // 上一级传入的PC
    //input [31:0] pc,
    output reg[31:0] pc,
    output reg [31:0] instruction_out, // 输出指令
    output reg ebreak,
    output  reg [31:0] pc_out,
    input valid,
    input [31:0] pc_jal   // 新的跳转地址信号
);
reg [31:0] pc_next;
	
    always @(posedge clk ) begin
        if (rst) begin
            instruction_out <= 32'b0;
        end else begin
        /*if (inst_in == 32'h00100073) begin
                ebreak = 1;  // ebreak指令，设置ebreak信号
            end else begin
                ebreak = 0;
            end*/
            
            instruction_out <= inst_in;  // 直接传递来自 top 的指令
             pc_next <= pc + 4;

        // 更新 PC
        pc <= pc_next;
           
               

            // 更新 PC
            //pc <= pc_next;

            // 输出 PC 和指令
            $display("the pc value is: 0x%08x instruction: 0x%08x", pc, inst_in);
               
            if(valid==1)begin
            	pc_out <= pc_jal;$stop;
            end
             //
            // 假设mem是已经初始化的内存系统，通过地址获取指令
            
        end
    end
   
  
endmodule
