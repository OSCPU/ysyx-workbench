module top(
  input        clk,
  input        rst_n,
  
  output[31:0] inst,
  output[63:0] inst_addr_o,
  
  output[63:0] now_addr,
  output[31:0] now_inst
);

ysyx_22050019_core ysyx_22050019_core_inst(
 .clk      (clk),
 .rst_n    (rst_n),
 .inst_addr(inst_addr_o),
 .inst_i   (inst),
 
 .inst_addr_if_id(now_addr),
 .inst_if_id     (now_inst)
);
endmodule

