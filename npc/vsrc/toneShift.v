

module Tonetop(
    input [len:0] in,
    input  left, // 1left or  0right
    input logicORalg , // 1 logical //0 algorithm
    input [31:0]shiftStep,
    output reg [len:0] out
);
    parameter len = 6; // max 31
    // parameter sS = shiftStep %len;
    genvar  i  ;
    generate
        // always @(*) begin
        for (i=0;i<=len;i = i + 1) begin:gen0
            parameter c = i;
            // for (j=0;j< len+1; j = j +1) begin:gen1
                // if(j == shiftStep)begin
            assign out[i] = (left == 1 )?
                    (
                        (logicORalg == 1'b0 && c == len)?
                        (
                            in[i]
                        ):
                        (
                            (c  >= shiftStep)?
                            in[c-shiftStep]:0
                        )

                    ):
                    (
                        (logicORalg == 1'b1)?
                        (
                            (c + shiftStep <=len)?
                            in[c+shiftStep]: 0
                        ):
                        (
                            (c + shiftStep <=len)?
                            in[c+shiftStep]:in[len]
                        )
                    );

            // assign out[i] = (i==0 && left ==1 && logicORalg ==0)?
            //                 in[i] : out[i];
                            
                    // if(left == 1'b1) begin  
                    //     if(i  >= shiftStep)
                    //         assign out[i] = in[i-shiftStep];
                    //     else 
                    //         assign out[i] = 0;
                    // end
                    // else begin

                    //     if (logicORalg == 1'b1)begin
                    //         if(i + shiftStep <=len)
                    //             assign out[i] = in[i+shiftStep];
                    //         else 
                    //             assign out[i] = 0;
                    //     end
                    //     else begin
                    //         if(i + shiftStep <=len)
                    //             assign out[i] = in[i+shiftStep];
                    //         else 
                    //             assign out[i] = in[len];
                    //     end
                    // end
                // end
            // end
        end            
        // end
    endgenerate

endmodule