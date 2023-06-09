module ysyx_22050019_forwarding (
  input    [4:0] reg_raddr_1_id     ,
  input    [4:0] reg_raddr_2_id     ,
  input    [4:0] reg_waddr_exu      ,
  input    [4:0] reg_waddr_lsu      ,
  input          reg_wen_exu        ,
  input          reg_wen_lsu        ,
  input    [63:0]reg_wen_wdata_exu_i,
  input    [63:0]reg_wen_wdata_lsu_i,
  input    [63:0]reg_r_data1_id_i   ,
  input    [63:0]reg_r_data2_id_i   ,

  output         forwarding_stall_o ,
  output   [63:0]reg_r_data1_id__o  ,
  output   [63:0]reg_r_data2_id__o  
);

  /* 对于将lsu写wb的写寄存器通路与来自exu写的进行了合并，这样如果exu拉下的数据的前递，在lsu阶段有机会补上 */
  //reg_wen_lsu && 这里的删除是因为两周期流水线会出现exu遗漏前递的情况发生，删除了这个可以让exu遗漏的在lsu补上，前提条件是对于waddr和wdata在发出时进行使能控制，减少乱传可能性
  /* rs1 exu前推 */
  wire ForwardA_exu = reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_1_id);
  /* rs1 lsu前推 */
  wire ForwardA_lsu = reg_wen_lsu && (reg_waddr_lsu != 0) && (!(reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_1_id))) && (reg_waddr_lsu == reg_raddr_1_id);

  /* rs2 exu前推 */
  wire ForwardB_exu = reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_2_id);
  /* rs2 lsu前推 */
  wire ForwardB_lsu = reg_wen_lsu && (reg_waddr_lsu != 0) && (!(reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_2_id))) && (reg_waddr_lsu == reg_raddr_2_id);

// 10-exu前递出、01-lsu前递，00-原来值，11-在上面的逻辑中不会出现因为两个使能是互斥的
wire [1:0]raddr1_sel   = {ForwardA_exu ,ForwardA_lsu};
ysyx_22050019_mux #( .NR_KEY(3), .KEY_LEN(2), .DATA_LEN(64) ) mux_r_data1
(
  .key         (raddr1_sel), //键
  .default_out (64'b0),
  .lut         ({2'b10,reg_wen_wdata_exu_i,
                 2'b01,reg_wen_wdata_lsu_i,
                 2'b00,reg_r_data1_id_i 
                 }), //键和输出的表           
  .out         (reg_r_data1_id__o)  //输出
);

//op2_sel
wire [1:0]raddr2_sel   = {ForwardB_exu ,ForwardB_lsu};
ysyx_22050019_mux #( .NR_KEY(3), .KEY_LEN(2), .DATA_LEN(64)) mux_r_data2
(
  .key         (raddr2_sel), //键
  .default_out (64'b0),
  .lut         ({
                 2'b10,reg_wen_wdata_exu_i,
                 2'b01,reg_wen_wdata_lsu_i,
                 2'b00,reg_r_data2_id_i 
                 }),         
  .out         (reg_r_data2_id__o)  //输出
);

// lsu对于idu的暂停（插入nop）这里的操作是提前阻塞if_id然后把l指令传下去给lsu执行（传递过后这个信号就拉低了类似一个补充信号）
assign forwarding_stall_o = ~reg_wen_exu & (reg_waddr_exu != 0) && ((reg_waddr_exu == reg_raddr_1_id) || (reg_waddr_exu == reg_raddr_2_id));
endmodule
