module ysyx_22050019_alu(
 input        clk,
 input        rst_n,
 input [63:0] op_1,
 input [63:0] op_2,
 input [`LEN:0] alu_sel,
 input        lsu_stall,

 output       alu_stall,
 output       alu_ok   ,
 output[63:0] result
);
// 复用加法器的控制信号处理
wire  op_suber    = {op_sltu|op_sub|op_slt|op_subw_32} ;

wire  op_sub      = alu_sel [2] ;
wire  op_subw_32  = alu_sel [3] ;
wire  op_slt      = alu_sel [4] ;
wire  op_sltu     = alu_sel [5] ;

// 把移位输入复用的控制信号(op2)
wire  op_shamt    = {op_slli_64|op_srli_64|op_srai_64} ;
wire  data_shamt  = op_shamt ? op_2[5] : 1'b0;

wire  op_slli_64  = alu_sel [10];
wire  op_srli_64  = alu_sel [14];
wire  op_srai_64  = alu_sel [18];

// 被移位的输入选择填充信号(op1)
wire [63:0]ushif_1= (op_srli_32|op_srl_32) ? {{32{1'b0}},op_1[31:0]} : op_1;

wire  op_srli_32  = alu_sel [15];
wire  op_srl_32   = alu_sel [16];

wire [63:0]sshif_1= (op_srai_32|op_sra_32) ? {{32{op_1[31]}},op_1[31:0]} : op_1;

wire  op_srai_32  = alu_sel [19];
wire  op_sra_32   = alu_sel [20];

/*    alu_sel 各个位的执行命令查看表
wire  op_add_64   = alu_sel [0] ;
wire  op_add_32   = alu_sel [1] ;

wire  op_and      = alu_sel [6] ;
wire  op_or       = alu_sel [7] ;
wire  op_xor      = alu_sel [8] ;

wire  op_sll_64   = alu_sel [9] ;
wire  op_slli_32  = alu_sel [11];
wire  op_sll_32   = alu_sel [12];

// 右移时32位需要考虑截取,有符号用符号位填充无符号用0填充
wire  op_srl_64   = alu_sel [13];

wire  op_sra_64   = alu_sel [17];

wire  op_rem_64   = alu_sel [21];
wire  op_remu_64  = alu_sel [22];
wire  op_divu_64  = alu_sel [26];
wire  op_rem_32   = alu_sel [24];

wire  op_div_64   = alu_sel [25];
wire  op_div_32   = alu_sel [28];

wire  op_mul      = alu_sel [29];
wire  op_mulh     = alu_sel [30];
wire  op_mulhsu   = alu_sel [31];
wire  op_mulh u   = alu_sel [32];
wire  op_mul_64   = alu_sel [33];
*/

//加减判断，add 结果有op_suber控制为加或者减
wire [63:0] op_2_in    = op_suber ?  (~op_2 + 64'b1) : op_2  ;//加减匹配位置
wire [63:0] add        = op_1 +op_2_in;

//对add的结果进行32位截断符号拓展
wire [63:0] SEXT_add_32= {{32{add[31]}},add[31:0]};

//有符号小于则置位
wire [63:0] slt        = ( ( ( op_1[63] == 1'b1 ) && ( op_2[63] == 1'b0 ) ) 
                        | ( (op_1[63] == op_2[63] ) && ( add[63] == 1'b1 ) ) ) ? 64'b1 : 64'b0 ;

//小于则置位，无符号
wire [63:0] sltu       = ( ( ( op_1[63] == 1'b0 ) && ( op_2[63] == 1'b1 ) ) 
                        | ( (op_1[63] == op_2[63] ) && ( add[63] == 1'b1 ) ) ) ? 64'b1 : 64'b0 ;

//对操作数1逻辑右移shanmt位（空位填0)
wire [63:0] srl        = ushif_1 >> {data_shamt,op_2[4:0]};

//对操作数1算术右移位shanmt位（rs1最高位填冲)
wire [63:0] sra        = $signed(sshif_1[63:0]) >>> {data_shamt,op_2[4:0]};// 有符号数64位的需要前面也带sign不然被转为无符号数 

//对操作数1进行逻辑左移（空位填0)
wire [63:0] sll        = op_1 << {data_shamt,op_2[4:0]};

//按位与
wire [63:0] and64      = op_1 & op_2 ;

//按位或
wire [63:0] or64       = op_1 | op_2 ;

//按位异或
wire [63:0] xor64      = op_1 ^ op_2 ;

//乘法器
wire mult_valid  = |alu_sel [33:29]; 
wire result_ready= ~lsu_stall;
wire [63:0]mult_out;
wire mult_stall;
wire result_ok_mul;
ysyx_22050019_multiplier_cycle multiplier_cycle(
    .clk            ( clk            ),
    .rst_n          ( rst_n          ),
    .mult_valid     ( mult_valid     ),
    .mult_type      ( alu_sel[33:29] ),
    .multiplicand_i ( op_1           ),
    .multiplier_i   ( op_2           ),
    .result_ready   ( result_ready   ),
    .mult_out       ( mult_out       ),
    .mult_stall     ( mult_stall     ),
    .result_ok      ( result_ok_mul  )
);

//除法器
wire div_valid  = |alu_sel[28:21]; 
wire [63:0]div_out;
wire div_stall;
wire result_ok_div;
ysyx_22050019_divider divider(
    .clk           ( clk            ),
    .rst_n         ( rst_n          ),
    .div_valid     ( div_valid      ),
    .div_type_i    ( alu_sel[28:21] ),
    .dividend_i    ( op_1           ),
    .divisor_i     ( op_2           ),
    .result_ready  ( result_ready   ),
    .div_out       ( div_out        ),
    .div_stall     ( div_stall      ),
    .result_ok     ( result_ok_div  )
);
//========================================
// alu的控制信号
assign alu_stall = mult_stall    | div_stall;
assign alu_ok    = result_ok_mul | result_ok_div;
// alu的控制信号译码（用宏定义方便添加）
ysyx_22050019_mux #( .NR_KEY(`LEN+1-13), .KEY_LEN(`LEN+1-13), .DATA_LEN(64) ) mux_alu_result
(
  .key         (alu_sel[20:0]), 
  .default_out (mult_out | div_out),
  .lut         ({
                 21'b100000000000000000000,{{32{sra[31]}},sra[31:0]},
                 21'b010000000000000000000,{{32{sra[31]}},sra[31:0]},
                 21'b001000000000000000000,sra,
                 21'b000100000000000000000,sra,
                 21'b000010000000000000000,{{32{srl[31]}},srl[31:0]},
                 21'b000001000000000000000,{{32{srl[31]}},srl[31:0]},
                 21'b000000100000000000000,srl,
                 21'b000000010000000000000,srl,
                 21'b000000001000000000000,{{32{sll[31]}},sll[31:0]},
                 21'b000000000100000000000,{{32{sll[31]}},sll[31:0]},
                 21'b000000000010000000000,sll,
                 21'b000000000001000000000,sll,
                 21'b000000000000100000000,xor64,
                 21'b000000000000010000000,or64,
                 21'b000000000000001000000,and64,
                 21'b000000000000000100000,sltu,
                 21'b000000000000000010000,slt,
                 21'b000000000000000001000,SEXT_add_32,
                 21'b000000000000000000100,add,
                 21'b000000000000000000010,SEXT_add_32,
                 21'b000000000000000000001,add
                 }),           
  .out         (result)  
);
endmodule