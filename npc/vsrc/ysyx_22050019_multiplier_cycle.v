/*
 * Radix-4 Booth 64x64 乘法器
 * 设置原因 :
 * 适配有符号数拓展为65*65，根据指令类型截取结果为输出，结果共130位数
 * 输入为64位被乘数与乘数，由于指令类型中有符号之分，因此扩展一位用于确定符号
 * 65位的被乘数再符号扩展成为130位被乘数
 * 65位的乘数，由于Booth的要求，最低位补0，最高位还需要再补符号位，结果是67位的乘数
 *
 * 计算过程 : 
 * 每次生成130位的部分积，与累加寄存器相加
 * 然后乘数右移两位，被乘数左移两位
 *
 * 结束判断 : 乘数为0，则乘法计算结束
 */
module ysyx_22050019_multiplier_cycle (
    input clk                  ,
    input rst_n                ,
    input mult_valid           , // 乘法器是否合法输入
    input [4:0] mult_type      , // 乘法类型
    input [63:0] multiplicand_i, // 被乘数
    input [63:0] multiplier_i  , // 乘数
    input        result_ready  , // 是否准备接收
    output [63:0] mult_out     , // 计算结果
    output mult_stall          , // 计算暂停 
    output result_ok             // 计算ok 
);
//========================================
// 乘法类型判断
/*
mul    : x[rd] = (x[rs1] × x[rs2])[63:0]
mulh   : x[rd] = (x[rs1]𝑠 × x[rs2]𝑠)[127:64]
mulhu  : x[rd] = (x[rs1]𝑢 × x[rs2]𝑢)[127:64]
mulhsu : x[rd] = (x[rs1]𝑠 × x[rs2]𝑢)[127:64]
mulw   : x[rd] = sext((x[rs1] × x[rs2])[31: 0])
*/
parameter MUL    = 5'b00001; // 乘
parameter MULH   = 5'b00010; // 高位乘
parameter MULHSU = 5'b00100; // 高位有符号-无符号乘
parameter MULHU  = 5'b01000; // 高位无符号乘
parameter MULW   = 5'b10000; // 乘字

// 状态机定义
parameter IDLE   = 2'b00;
parameter MULTI  = 2'b01;
parameter FINISH = 2'b10;

// 输入数根据指令类型符号拓展
// 被乘数信号声明
wire [129:0]multiplicand_trans;
reg  [129:0]multiplicand;

// 乘数信号声明
wire [64:0]multiplier_trans;
reg  [66:0]multiplier;

// 结果
reg [129:0] result;
//========================================
// 根据指令类型将输入符号拓展加入计算乘数和被乘数中
assign multiplicand_trans[129:64] = ((mult_type == MULHU) | (mult_type == MULW)) ? 66'b0 : {66{multiplicand_i[63]}};
assign multiplicand_trans[63:32]  = (mult_type == MULW) ? 32'b0 : multiplicand_i[63:32];
assign multiplicand_trans[31:0]   = multiplicand_i[31:0];

assign multiplier_trans  [64]     = ((mult_type == MULW) | (mult_type == MULHSU) | (mult_type == MULHU)) ? 1'b0 : multiplier_i[63];
assign multiplier_trans  [63:32]  = (mult_type == MULW) ? 32'b0 : multiplier_i[63:32];
assign multiplier_trans  [31:0]   = multiplier_i[31:0];

// 乘数进一步拓展，根据booth算法，乘数需要偶数，故拓展一个符号位，低位隐式补0
wire [66:0] multiplier_sext;
assign multiplier_sext            = {multiplier_trans[64], multiplier_trans[64:0], 1'b0};

//========================================
// 状态机进行部分积求和处理
reg [1:0] state, next_state;
reg [4:0] mul_type;
wire [129:0] partial_product;
ysyx_22050019_booth_code #(130)booth_code(
    .multiplicand     ( multiplicand     ),
    .code             ( multiplier[2:0]  ),
    .partial_product  ( partial_product  )
);

// 3段式状态机构建乘法逻辑模块 
always@(posedge clk) begin
  if(rst_n)state<=IDLE;
  else   state<=next_state;
end

always @(*) begin
        case(state)
          IDLE  : if(mult_valid) next_state = MULTI ;
                  else           next_state = IDLE  ;
          MULTI : if(~|multiplier) begin
                      next_state = FINISH ;
                  end
                  else next_state = MULTI  ;
          FINISH: if(result_ready)next_state = IDLE ;
                  else next_state = FINISH ;
        default : next_state=IDLE ;
        endcase
end

always @(posedge clk) begin
    if(rst_n) begin
        mul_type     <= 0;
        multiplicand <= 0;
        multiplier   <= 0;
        result       <= 0;
    end
    else begin
        case(state)
          IDLE : if(next_state == MULTI) begin
            mul_type     <= mult_type         ;
            multiplicand <= multiplicand_trans;
            multiplier   <= multiplier_sext   ;
            result       <= 0                 ;
            end
            else begin
            mul_type     <= 0                 ;
            multiplicand <= 0                 ;
            multiplier   <= 0                 ;
            result       <= 0                 ;   
            end
          MULTI: if(next_state == FINISH) begin
            result       <= result            ;
            end
            else begin
            multiplicand <= multiplicand << 2 ;
            multiplier   <= multiplier   >> 2 ;
            result       <= result + partial_product;
            end
          FINISH:if(next_state == IDLE) begin
            mul_type     <= 0                 ;
            multiplicand <= 0                 ;
            multiplier   <= 0                 ;
            result       <= 0                 ; 
            end
            else begin
            mul_type     <= mul_type          ;
            multiplicand <= multiplicand      ;
            multiplier   <= multiplier        ;
            result       <= result            ;   
            end
            default :begin
            end
        endcase
    end
    
end

ysyx_22050019_mux #( .NR_KEY(5), .KEY_LEN(5), .DATA_LEN(64)) ysyx_22050019_mux
(
  .key         (mul_type), //键
  .default_out (64'b0),
  .lut         ({		
                 	5'b00001,result[63:0],
				          5'b00010,result[127:64],
				          5'b00100,result[127:64],
				          5'b01000,result[127:64],
				          5'b10000,{{32{result[31]}}, result[31:0]}
                    }), //键和输出的表           
  .out         (mult_out)  //输出
);

//========================================
// 输出控制
assign result_ok  = (state == FINISH);
assign mult_stall = (state == IDLE && next_state == MULTI) | (state == MULTI);

endmodule

module ysyx_22050019_booth_code #(DATA_WIDTH = 64) (
    input  [DATA_WIDTH-1:0] multiplicand   , //
    input  [2:0]            code           , //
    output [DATA_WIDTH-1:0] partial_product  //
);
/*   B      操作  verilog描述
     000	  0     全0
     001	+ B     +B ={ sign,B} +0
     010	+ B     +B ={ sign,B} +0
     011	+2B     +2B={ B,0}    +0
     100	-2B     -2B={~B,1}    +1
     101	- B     -B ={~sign,~B}+1
     110	- B     -B ={~sign,~B}+1
     111	  0     全0
*/

// 被乘法数符号
wire sign = multiplicand[DATA_WIDTH-1];

// 部分积结果生成，有乘数的低3位决定
wire [DATA_WIDTH:0]op1; //符号位拓展和补1，取反等操作
wire op2;               //是否要＋1的负数补码补充

ysyx_22050019_mux #( .NR_KEY(8), .KEY_LEN(3), .DATA_LEN(DATA_WIDTH + 1)) op1_sel
(
  .key         (code), //键
  .default_out ({ (DATA_WIDTH + 1){1'b0}}),
  .lut         ({		
                 	3'b000,{ (DATA_WIDTH + 1){1'b0}},
				          3'b001,{ sign, multiplicand    },
				          3'b010,{ sign, multiplicand    },
                 	3'b011,{ multiplicand, 1'b0    },
				          3'b100,{~multiplicand, 1'b1    },
				          3'b101,{~sign, ~multiplicand   },
				          3'b110,{~sign, ~multiplicand   },
				          3'b111,{ (DATA_WIDTH + 1){1'b0}}
                    }), //键和输出的表           
  .out         (op1)  //输出
);

ysyx_22050019_mux #( .NR_KEY(8), .KEY_LEN(3), .DATA_LEN(1)) op2_sel
(
  .key         (code), //键
  .default_out (1'b0),
  .lut         ({		
                 	3'b000,1'b0,
				          3'b001,1'b0,
				          3'b010,1'b0,
                 	3'b011,1'b0,
				          3'b100,1'b1,
				          3'b101,1'b1,
				          3'b110,1'b1,
				          3'b111,1'b0
                    }), //键和输出的表           
  .out         (op2)  //输出
);
assign partial_product = op1[DATA_WIDTH-1:0] + {{(DATA_WIDTH-1){1'b0}},op2};//加法这里可以把结果扔寄存器里中继一下再加，如果这里延时太大的话可以砍一刀
endmodule