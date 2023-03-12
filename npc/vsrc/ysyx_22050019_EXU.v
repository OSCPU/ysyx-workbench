module ysyx_22050019_EXU(
  input [`LEN:0]  alu_sel,

  input [63:0]    op1,
  input [63:0]    op2,

  input           reg_we_i,
  input  [4:0]    reg_waddr_i,
  
  output [63:0]   result,
  output [63:0]   wdata,
  output          reg_we,
  output [4:0]    waddr
);

ysyx_22050019_alu alu(
  .op_1(op1),
  .op_2(op2),
  .alu_sel(alu_sel),
  
  .result(result)
);

//reg_control
assign wdata  = reg_we_i ? result : 64'b0;
assign reg_we = reg_we_i ;
assign waddr  = reg_waddr_i ;

endmodule

