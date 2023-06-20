module ysyx_22050019_pipeline_Control (

  input              lsu_stall_req  ,
  input              alu_stall_req  ,
  input              forwarding_req ,

  output wire        pc_stall_o     ,
  output wire        if_id_stall_o  ,
  output wire        id_ex_stall_o  ,
  output wire        ex_mem_stall_o ,
  output wire        mem_wb_stall_o
);

  /* 
   * stall-保持流水线寄存器的值不随时钟而刷新，完成流水线的暂停
   */

  assign pc_stall_o     = if_id_stall_o;
  assign if_id_stall_o  = id_ex_stall_o;
  assign id_ex_stall_o  = ex_mem_stall_o | forwarding_req | alu_stall_req;
  assign ex_mem_stall_o = mem_wb_stall_o | lsu_stall_req;
  assign mem_wb_stall_o = 0;

endmodule
