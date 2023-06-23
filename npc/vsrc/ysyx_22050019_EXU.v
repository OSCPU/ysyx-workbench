module ysyx_22050019_EXU(
  input           clk,
  input           rst_n,
  input           wen_i,
  input [4:0]     waddr_i,
  input [`LEN:0]  alu_sel,

  input [63:0]    op1,
  input [63:0]    op2,
  input           lsu_stall,

  output [63:0]   result,
  output          alu_stall,
  output          exu_wen  ,
  output [4:0]    exu_waddr, 
  output [63:0]   wdata
);

ysyx_22050019_alu alu(
  .clk  (clk) ,
  .rst_n(rst_n) ,
  .op_1(op1),
  .op_2(op2),
  .alu_sel(alu_sel),
  .lsu_stall(lsu_stall),
  
  .alu_stall(alu_stall),
  .alu_ok(wen),
  .result(result)
);
wire wen;
//reg_control
assign wdata    = result ;
assign exu_waddr= alu_stall ? 0 : (wen ? waddr : 0) | waddr_i;
assign exu_wen  = alu_stall ? 0 : wen_i | wen;

reg[4:0] waddr;
always @(posedge clk)begin
  if(rst_n) waddr <= 0;
  else if(|alu_sel [33:21])
            waddr <= waddr_i;
  else if(exu_wen)
            waddr <= 0;
end
endmodule

