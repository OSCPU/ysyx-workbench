


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

// ADDER
// module top(
//     input [31:0] a,
//     input [31:0] b,
//     input sub     , 
//     output [31:0] res ,
//     output Carry ,
//     output Zero  , 
//     output Overflow 
// );
//     wire [31:0] k;
//     assign k = {  {32{sub}} ^b } ; 

//     assign {Carry , res} = a + k + {31'b000 , sub } ;

//     assign Zero =  ~(|res) ;

//     assign Overflow = (a[31] == k[31] && res[31] != a[31] ) ;

// endmodule


module ALU(
    input[31:0] A , 
    input[31:0] B ,
    input[2:0] OPT,

    output reg[31:0] Output , 
    output reg Overflow ,
    output reg EqualZero,
    output reg Carry , 
    output reg Compare , 
    output reg Equal 
);
    parameter fff = 32'hffffffff;
    reg [31:0]tmp;
    always_latch

        case(OPT)
            3'b000:begin 
                {Carry , Output} = A + B ;
                EqualZero = (Output == 0) ? 1: 0 ;
                Overflow = A[31] == B[31] && A[31] != Output[31];
                
            end
            3'b001:begin

                tmp = fff^ B;
                {Carry , Output} = A + tmp + 1 ;
                EqualZero = (Output == 0) ? 1: 0 ;
                Overflow = A[31] == tmp[31] && A[31] != Output[31];

            end
            3'b010:begin
                Output = ~A;

            end
            3'b011:begin
                Output = A & B;

            end

            3'b100:begin
                Output = A | B;

            end
            3'b101:begin
                Output = A ^ B;

            end
            3'b110:begin

                Compare = (A < B) ? 1 : 0 ;

            end
            3'b111:begin

                Equal = (A == B) ? 1: 0 ;

            end
        endcase
            


endmodule

module top(
    input[31:0] A , 
    input[31:0] B ,
    input[2:0] OPT,

    output reg[31:0] Output , 
    output reg Overflow ,
    output reg EqualZero,
    output reg Carry , 
    output reg Compare , 
    output reg Equal 
);
    ALU alu(A,B,OPT,Output,Overflow,EqualZero,Carry,Compare,Equal);

endmodule