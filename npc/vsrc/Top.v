module Top (
  input clk,
  input rst,
  reg [31:0] inst,
  output reg [31:0]pc
  
);

 
  
  wire [4:0] rs1, rs2, rd;
  wire [31:0] rdata1, rdata2;
  wire [11:0] imm;
  wire [31:0] alu_result;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [31:0]instruction_out;
  wire wen;
  wire ebreak_signal;

  // 寄存器文件实例
  RegisterFile rf (
    .clk(clk),
    .rst(rst),
    .wdata(alu_result),
    .waddr(rd),
    .wen(wen),
    .raddr1(rs1),
    .rdata1(rdata1)
   
  );

  // IFU实例
  IFU ifu (
    .clk(clk),
    .rst(rst),
    .inst_in(inst),
    .instruction_out(instruction_out),
    .ebreak(ebreak_signal)
  );
  
  IDU idu (
     .clk(clk),
    .instr(instruction_out),
    .rs1(rs1),
    .rd(rd),
    .imm(imm),
    .opcode(opcode),
    .func3(func3)
  );

  // EXU实例
  EXU exu (
    .rs1_data(rdata1),
    .imm(imm),
    .alu_op(func3),  // ADDI 操作
    .alu_result(alu_result)
  );

  // 控制逻辑（简化版）
  assign wen = (opcode == 7'b0010011);  // 对应addi指令
 
import "DPI-C" context function void ebreak_trigger();

    always @(posedge clk) begin
    if (rst) begin
            pc = 32'h0;  // 复位时将 PC 清零
            
        end else begin
            pc = pc + 4;  // 每个时钟周期，PC 自增 4
            $display("0x%08x:0x%08x",pc,inst);
        end
        if (ebreak_signal) begin
            ebreak_trigger();  // 触发 C++ 中的结束仿真函数
        end
    end
/*always @(posedge clk) begin
    $display("Executing ADDI: R1 = %b, Immediate = %b, Result = %b", inst, imm, alu_result);
end*/

     // 更新程序计数器
    /*always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 0;  // 如果 reset 为高电平，pc 重新初始化
        end else begin
            // 这里使用 pc + 4 作为默认更新方式
            // 你可以在这里根据控制信号（如跳转、分支）来更新 pc
            pc <= pc + 4;
        end
    end*/

  
  
endmodule

