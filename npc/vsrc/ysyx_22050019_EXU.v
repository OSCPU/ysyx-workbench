module ysyx_22050019_EXU(
  input [`LEN:0]  alu_sel,

  input [63:0]    op1,
  input [63:0]    op2,
  
  output [63:0]   result,
  output [63:0]   wdata
);

ysyx_22050019_alu alu(
  .op_1(op1),
  .op_2(op2),
  .alu_sel(alu_sel),
  
  .result(result)
);

//reg_control
assign wdata  =  result ;
endmodule

