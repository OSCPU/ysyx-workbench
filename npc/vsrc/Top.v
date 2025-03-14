import "DPI-C" function void set_pc(input int pc);
import "DPI-C" function void set_inst(input int inst);

module Top (
  input clk,
  input rst,
// output reg [31:0] inst,
   output reg [31:0]pc
  
);

 
  reg [4:0] rs1, rs2, rd;
  reg [31:0] rdata1, rdata2;
  reg [31:0] imm;
  reg [31:0] alu_result;
  reg  [31:0] pc_out;
  reg [6:0] opcode;
  reg [2:0] func3;
  reg [6:0] func7;
  wire pc_valid;
  reg [31:0]instruction_out;
  wire wen;
  wire ebreak_signal;
   reg [31:0]pc_result;
	 reg [31:0]rs_jalr;
//wire  valid;



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
		.pc(pc),
	//	.ins(inst),
   .rdata2(rdata2)
  );

  // IFU实例
  IFU ifu (
    .clk(clk),
    .rst(rst),
    //.inst_in(inst),
    .instruction_out(instruction_out),
    .ebreak(ebreak_signal),
    .pc(pc),
   // .pc_out(pc_out),
   // .valid(valid),
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
    .pc_result(pc_result)
    //.pc_jump(valid)
  );

  /* always @(posedge clk or posedge rst) begin
        if (rst) begin
            // 初始值由 main.cpp 传入，也可以在这里复位
            pc <= 32'h80000000;
        end else begin
            // 用 IFU 计算得到的 pc 值更新 Top 中的 pc
            pc <= pc_out+4;
						$display("the pc value is: 0x%08x ", pc);
    end
	end*/
import "DPI-C"  function void ebreak_trigger();

always @(posedge clk or posedge rst) begin
    set_pc(pc);
    set_inst(instruction_out);
end
//export "DPI-C" function void get_gpr;
  always @(posedge clk) begin
    
        if (ebreak_signal) begin
            ebreak_trigger();  // 触发 C++ 中的结束仿真函数
        end
    end
  
endmodule

