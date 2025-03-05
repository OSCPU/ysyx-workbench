module Top (
  input clk,
  input rst,
  reg [31:0] inst,
   output reg [31:0]pc
  
);

 
 
  wire [4:0] rs1, rs2, rd;
  wire [31:0] rdata1, rdata2;
  wire [31:0] imm;
  wire [31:0] alu_result;
  wire [31:0] pc_out;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;
  wire pc_valid;
  wire [31:0]instruction_out;
  wire wen;
  wire ebreak_signal;
   wire [31:0]pc_result;
wire valid;



  // 寄存器文件实例
  RegisterFile rf (
    .clk(clk),
    .rst(rst),
    .wdata(alu_result),
    .waddr(rd),
    .wen(wen),
    .raddr1(rs1),
    .raddr2(rs2),
    .rdata1(rdata1),
   .rdata2(rdata2)
  );

  // IFU实例
  IFU ifu (
    .clk(clk),
    .rst(rst),
    .inst_in(inst),
    .instruction_out(instruction_out),
    .ebreak(ebreak_signal),
    .pc(pc),
    .pc_out(pc_out),
    .valid(valid),
    .pc_jal(pc_result)
   // .pc_jump(pc_jump)
  );
  
  IDU idu (
     .clk(clk),
    .instr(instruction_out),
    .rs1(rs1),
    .rs2(rs2),
    .rd(rd),
    .imm(imm),
    .opcode(opcode),
    .func3(func3),
    .func7(func7),
    .wen(wen)
  );

  // EXU实例
  EXU exu (
  .clk(clk),
    .rs1_data(rdata1),
    .rs2_data(rdata2),
    .imm(imm),
    .pc(pc),
    .func3(func3),
    .alu_op(opcode),  // ADDI 操作
    .alu_result(alu_result),
    //.pc_out(pc_result)
    .pc_result(pc_result),
    .pc_jump(valid)
  );

  // 控制逻辑（简化版）
 // assign wen = 1;  // 对应addi指令
 	
 	//assign pc=pc_out;
/*always @(posedge clk or posedge rst) begin
        if (rst) begin
            pc <= 32'h80000000;  // 复位时初始化 PC
        end else begin
        
            pc <= pc_out;  // 更新 top 的 PC 值
             $display("the  pc value is : 0x%08x instruction: %08x", pc,inst);
             
        end
    end*/
    
import "DPI-C" context function void ebreak_trigger();

  always @(posedge clk) begin
    
        if (ebreak_signal) begin
            ebreak_trigger();  // 触发 C++ 中的结束仿真函数
        end
    end
  
endmodule

