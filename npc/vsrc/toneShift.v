

module RegShift#(int len)(

    input [len:0] in,
    input  left, // 1left or  0right
    input logicORalg , // 1 logical //0 algorithm
    input shiftStep,
    output [len:0] out

);

    always @(*)
        if(logicORalg == 1)begin
           if(left ==1) begin
                out = {in[len - shiftStep:0] , {shiftStep{0}}};
           end 
           else begin
                out = {{shiftStep{0}} , in[len:len - shiftStep + 1]};
           end
        end
        else begin
            if(left ==1)begin
                out = {in[len] , in[len - shiftStep -1 :0] , {shiftStep{0}}};
            end
            else begin
                out = {{(shiftStep+1){in[len]}} , in[len-1 : len-shiftStep]};
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
    RegShift #(5)(in , left , logicORalg , shiftStep) ;
    // rs(in , left , logicORalg , shiftStep);

endmodule