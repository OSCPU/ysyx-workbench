module ysyx_22050019_IF_ID (
    input     clk                 ,
    input     rst_n               ,
    input     [63:0] pc_i         ,
    input     [31:0] inst_i       ,

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
//跳转的时刻ifu是不能向下发送commite的确认的，跳转后需要重新取一条对应指令的数据，因为暂停期间跳转送进来的地址只有在结束时刻才能确认是对的。
// 对于跳转进行了两个保险，其实现在来看ifu哪一个就够了，主要起作用的是在ifu，跳转后会进行一个nop操作，把这个commite_i的输出反压位0作为nop吧
//id阶段暂停时如果是跳转指令，在跳转同时把上一级别寄存器状态刷新了，否则一直跳转阻塞
  always @(posedge clk) begin
    if (rst_n) begin
        pc_o     <= 0;
        inst_o   <= 0;
        commite_o<= 0;
    end
    else if (commite_i && id_j_flush) begin
        pc_o     <= pc_i;
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