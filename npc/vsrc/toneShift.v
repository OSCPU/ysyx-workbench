

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
    input [5:0] in,
    input  left, // 1left or  0right
    input logicORalg , // 1 logical //0 algorithm
    input shiftStep,
    output [5:0] out
);
    RegShift #(5 , shiftStep) rs(in , left , logicORalg  ,out) ;
    // rs(in , left , logicORalg , shiftStep);

endmodule