

module RegShift#(int len)(

    input [len:0] in,
    input  left, // 1left or  0right
    input logicORalg , // 1 logical //0 algorithm
    input reg[32:0] shiftStep,
    output [len:0] out

);
    wire [len:0] tmp;
    always @(*)
        if(logicORalg == 1)begin
           if(left ==1) begin
                out = in<<shiftStep;
           end 
           else begin
                tmp =  (in>>shiftStep);
                out = {{shiftStep{0}} , tmp[shiftStep-1:0]};
           end
        end
        else begin
            if(left ==1)begin
                out = {in[len] ,  (in[len-1 :0] )<< shiftStep};
            end
            else begin
                tmp = (in>>shiftStep)
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
    RegShift #(5) rs(in , left , logicORalg , shiftStep ,out) ;
    // rs(in , left , logicORalg , shiftStep);

endmodule