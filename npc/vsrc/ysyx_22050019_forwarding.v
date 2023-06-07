module ysyx_22050019_forwarding (
  input  wire  [4:0] reg_raddr_1_id     ,
  input  wire  [4:0] reg_raddr_2_id     ,
  input  wire  [4:0] reg_waddr_exu      ,
  input  wire  [4:0] reg_waddr_lsu      ,
  input  wire        reg_wen_exu        ,
  input  wire        reg_wen_lsu        ,
  input  wire  [63:0]reg_wen_wdata_exu_i,
  input  wire  [63:0]reg_wen_wdata_lsu_i,
  input  wire  [63:0]reg_r_data1_id_i   ,
  input  wire  [63:0]reg_r_data2_id_i   ,

  output  wire  [63:0]reg_r_data1_id__o  ,
  output  wire  [63:0]reg_r_data2_id__o  
);

  /* 对于将lsu写wb的写寄存器通路与来自exu写的进行了合并，这样如果exu拉下的数据的前递，在lsu阶段有机会补上 */
  /* rs1 exu前推 */
  wire ForwardA_exu = reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_1_id);
  /* rs1 lsu前推 */
  wire ForwardA_lsu = reg_wen_lsu && (reg_waddr_lsu != 0) && (!(reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_1_id))) && (reg_waddr_lsu == reg_raddr_1_id);

  /* rs2 exu前推 */
  wire ForwardB_exu = reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_2_id);
  /* rs2 lsu前推 */
  wire ForwardBlsu = reg_wen_lsu && (reg_waddr_lsu != 0) && (!(reg_wen_exu && (reg_waddr_exu != 0) && (reg_waddr_exu == reg_raddr_2_id))) && (reg_waddr_lsu == reg_raddr_2_id);

// 10-exu前递出、01-lsu前递，00-原来值，11-在上面的逻辑中不会出现因为两个使能是互斥的
wire [1:0]raddr1_sel   = {ForwardA_exu ,ForwardA_lsu};
ysyx_22050019_mux #( .NR_KEY(3), .KEY_LEN(2), .DATA_LEN(64) ) mux_op1
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
wire [1:0]raddr2_sel   = {ForwardB_exu ,ForwardBlsu};
ysyx_22050019_mux #( .NR_KEY(3), .KEY_LEN(2), .DATA_LEN(64)) mux_op2
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

endmodule
