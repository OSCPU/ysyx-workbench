


//  4 select 1
// module top(
//     input [7:0]a ,
//     input [7:0]b ,
//     input [7:0]c ,
//     input [7:0]d ,
//     input [1:0]s ,
//     output reg [7:0]o
// );
    

//     always @(*) begin

//         case(s)
//             0: o = a;
//             1: o = b;
//             2: o = c;
//             3: o = d;
//             default: o =0;
//         endcase
//     end

//     // assign ledup = sw[0] & sw[1];
//     // assign  ledr = { led , 7'b0000000 ,ledup};
// /*
// initial begin 
//     $display("Hello World"); 
//     //$finish; 
// end
// */
// endmodule


// encoder 
// module top(
//     input [1:0] x,
//     input en , 
//     output reg [4:0] y 
// );
    
//     always @(*)

//         if(en) begin
//             case(x) 
//                 0:y=1;
//                 1:y=2;
//                 2:y=4;
//                 3:y=8;
//             endcase
//         end
//         else begin
//             y = 0 ;
//         end

// endmodule

//decoder 
// module top(
//     input [4:0] y,
//     input en , 
//     output reg [1:0] x 
// );
    
//     always @(*)

//         if(en) begin
//             case(y) 
//                 1:x=0;
//                 2:x=1;
//                 4:x=2;
//                 8:x=3;
//             endcase
//         end
//         else begin
//             x = 0 ;
//         end

// endmodule


module top(
    input [2:0] a,
    input [2:0] b,
    input sub  , 
    output [2:0] res ,
    output Carry ,
    output Zero  , 
    output Overflow 
);
    wire [2:0] k;
    assign k = {  {3{sub}} ^b } + {2'b00 , sub }; 

    assign {Carry , res} = a + k ;

    assign Zero =  ~(|res) ;

    assign Overflow = (a[2-1] == sub && res[2-1] != a[2-1] ) ;

endmodule
