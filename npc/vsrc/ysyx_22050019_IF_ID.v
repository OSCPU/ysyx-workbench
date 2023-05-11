module ysyx_22050019_IF_ID (
    input     clk          ,
    input     rst_n        ,
    input     [63:0] pc_i  ,
    input     [31:0] inst_i,

    output reg[63:0] pc_o  ,
    output reg[31:0] inst_o 
);
  always @(posedge clk) begin
    if(rst_n) begin
        pc_o   <= 0;
        inst_o <= 0;
    end
    else begin
        pc_o   <= pc_i  ;
        inst_o <= inst_i;
    end
  end
endmodule