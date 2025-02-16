module Top (
    input clk,
    input rst,
    output [31:0] result
);
    wire [31:0] pc;
    wire [31:0] instruction;
    wire [4:0] rs1, rs2, rd;
    wire [31:0] rs1_data, rs2_data, imm, exu_result;
    wire [6:0] opcode;
    
    // 生成模块实例
    PC pc_unit (.clk(clk), .rst(rst), .pc(pc));
    IFU ifu_unit (.clk(clk), .rst(rst), .pc(pc), .instruction(instruction));
    IDU idu_unit (.instruction(instruction), .rs1(rs1), .rs2(rs2), .rd(rd), .imm(imm), .opcode(opcode));
    RegisterFile rf_unit (.clk(clk), .rst(rst), .raddr1(rs1), .raddr2(rs2), .waddr(rd), .wdata(exu_result), .wen(1), .rdata1(rs1_data), .rdata2(rs2_data));
    EXU exu_unit (.rs1_data(rs1_data), .imm(imm), .opcode(opcode), .result(exu_result));

    assign result = exu_result;
endmodule

