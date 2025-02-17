module Top (
  input clk,
  input rst,
  reg [31:0] inst,
  reg [31:0]pc
  
);

 
  
  wire [4:0] rs1, rs2, rd;
  wire [31:0] rdata1, rdata2;
  wire [11:0] imm;
  wire [31:0] alu_result;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [31:0]instruction_out;
  wire wen;

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
    .instruction_out(instruction_out)
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
always @(posedge clk) begin
    $display("Executing ADDI: R1 = %b, Immediate = %b, Result = %b", inst, imm, alu_result);
end

     // 更新程序计数器
    /*always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h80000000;  // 如果 reset 为高电平，pc 重新初始化
        end else begin
            // 这里使用 pc + 4 作为默认更新方式
            // 你可以在这里根据控制信号（如跳转、分支）来更新 pc
            pc <= pc + 4;
        end
    end*/

  
  
endmodule

