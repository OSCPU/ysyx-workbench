

module RegShift#(int len ,int shiftStep)(

    input [len:0] in,
    input  left, // 1left or  0right
    input logicORalg , // 1 logical //0 algorithm
    output [len:0] out

);
    wire [len:0] tmp;
    always_latch
        if(logicORalg == 1)begin
           if(left ==1) begin
                out = in<<shiftStep;
           end 
           else begin
                out = (in>>shiftStep);
           end
        end
        else begin
            if(left ==1)begin
                out = {in[len] ,  (in[len-1 :0] )<< shiftStep};
            end
            else begin
                tmp = (in>>shiftStep);
                out = {{shiftStep{in[len]}}  , tmp[shiftStep-1:0]};
            end
        end

endmodule

module top(
    input [len:0] in,
    input  left, // 1left or  0right
    input logicORalg , // 1 logical //0 algorithm
    input shiftStep,
    output [len:0] out
);
    parameter len = 5; // max 31
    // RegShift #(len , shiftStep) rs(in , left , logicORalg  ,out) ;
    // rs(in , left , logicORalg , shiftStep);
    rs[shiftStep](in , left , logicORalg , out);

    initial begin

        parameter rs[32];
        for(integer i=0;i<32;i = i + 1) begin
            rs[i] = RegShift #(len,shiftStep);
        end
    end

endmodule