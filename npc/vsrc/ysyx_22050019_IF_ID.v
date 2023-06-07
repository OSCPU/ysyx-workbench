module ysyx_22050019_IF_ID (
    input     clk                 ,
    input     rst_n               ,
    input     [63:0] pc_i         ,
    input     [31:0] inst_i       ,

    input            ifu_ok_i     ,
    /* valid */
    input            commite_i    ,
    output reg       commite_o    ,

    /* control */
    input            if_id_stall_i,
    input            id_ex_stall_i,
    input            id_j_flush,

    output reg[63:0] pc_o         ,
    output reg[31:0] inst_o 
);
//id阶段暂停时如果是跳转指令，在跳转同时把上一级别寄存器状态刷新了，否则一直跳转阻塞
  always @(posedge clk) begin
    if (rst_n) begin
        pc_o     <= 0;
        inst_o   <= 0;
        commite_o<= 0;
    end
    else if (if_id_stall_i && (~id_ex_stall_i)) begin
        pc_o     <= 0;
        inst_o   <= 0;
        commite_o<= 0;
    end
    else if (~if_id_stall_i) begin
        pc_o     <= pc_i     ;
        inst_o   <= commite_i ? inst_i : 0;
        commite_o<= commite_i;
    end
    else begin
        pc_o     <= pc_o     ;
        inst_o   <= inst_o   ;
        commite_o<= commite_o;
    end

  end
endmodule