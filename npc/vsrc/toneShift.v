

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
    input [32:0]shiftStep,
    output [len:0] out
);
    parameter len = 5; // max 31

    genvar  i;
    generate
        always @(*) begin
            for (i=0;i<len;i = i + 1) begin:gen0
                if(left == 1) begin
                    if(i - shiftStep >=0)
                        out[i] = in[i-shiftStep];
                    else 
                        out[i] = 0;
                end
                else begin

                    if (logicORalg == 1)begin
                        if(i + shiftStep <=len)
                            out[i] = in[i+shiftStep];
                        else 
                            out[i] = 0;
                    end
                    else begin
                        if(i + shiftStep <=len)
                            out[i] = in[i+shiftStep];
                        else 
                            out[i] = in[len];
                    end
                end
            end            
        end
    endgenerate

endmodule