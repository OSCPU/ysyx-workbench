/*
 * 一位恢复余数绝对值迭代 64/64 除法器
 *
 * 初始化：
 * 被除数寄存器为被除数的初始值，商寄存器为0，余数寄存器为0
 * 
 * 迭代计算：
 * 将余数寄存器与商寄存器相连接，被除数存在该寄存器低64位
 * 如果带符号的被除数-除数的一半，将商寄存器的最低位设为1，被除数为带符号被除数减去除数
 * 如果带符号的除被数-除数的一半，将商寄存器的最低位设为0，被除数不变
 * 
 * 结束判断：
 * 检查是否已经完成对所有商位的计算
 * 如果还没有完成，返回到步骤2进行下一次迭代
 * 如果已经完成，余数除法计算结束
 * 
 * 完成阶段：
 * 当余数除法计算结束时，商寄存器中存储的值即为最终的商，余数寄存器中存储的值即为最终的余数
 */
module ysyx_22050019_divider (
  input         clk          ,
  input         rst_n        ,
  input         div_valid    , // 除法器开始信号 
  input [7:0]   div_type_i   , // 除法类型
  input [63:0]  dividend_i   , // 被除数
  input [63:0]  divisor_i    , // 除数
  input         result_ready , // 是否准备接收
  output [63:0] div_out      , // 计算结果 
  output        div_stall    , // 计算暂停 
  output        result_ok      // 计算ok 
);
//========================================
// 除法类型判断
/*
div   : x[rd] = x[rs1] ÷𝑠 x[rs2]
divu  : x[rd] = x[rs1] ÷𝑢 x[rs2]
divuw : x[rd] = sext(x[rs1][31:0] ÷𝑢 x[rs2][31:0])
divw  : x[rd] = sext(x[rs1][31:0] ÷𝑠 x[rs2][31:0])
remu  : x[rd] = x[rs1] %𝑢 x[rs2]
rem   : x[rd] = x[rs1] %𝑠 x[rs2]
remuw : x[rd] = sext(x[rs1][31: 0] %𝑢 x[rs2][31: 0])
remw  : x[rd] = sext(x[rs1][31: 0] %𝑠 x[rs2][31: 0])
*/
parameter REM   = 8'b10000000; // 取余数 有符号 64位 
parameter REMU  = 8'b01000000; // 取余数 无符号 64位 
parameter REMUW = 8'b00100000; // 取余数 无符号 32位 
parameter REMW  = 8'b00010000; // 取余数 有符号 32位 
parameter DIV   = 8'b00001000; // 除法一 有符号 64位
parameter DIVU  = 8'b00000100; // 除法一 无符号 64位
parameter DIVUW = 8'b00000010; // 除法一 无符号 32位
parameter DIVW  = 8'b00000001; // 除法一 有符号 32位
parameter ERROR = 8'b00000000; // 遇到了除0或溢出

// 使用信号声明与准备
reg [63:0] result_div_exception;// 异常结果输出
reg div_zero; // 除零通知
reg div_of  ; // 溢出通知

// 除法状态机的实现
parameter IDLE    = 2'b00;
parameter DO_DIV  = 2'b01;
parameter FINISH  = 2'b10;

reg [1:0] state, next_state;
reg [7:0] div_type;
reg [6:0] cnt;
reg quotient_sign, rem_sign;
reg [127:0] quotient;
reg [63:0]  divisor;

// 负数处理
wire [63:0] dividend_64_positive, divisor_64_positive;
assign dividend_64_positive    = ~(quotient_sign ? quotient[63:0]  : dividend_i) + 1;
assign divisor_64_positive     = ~(rem_sign      ? quotient[127:64]: divisor_i ) + 1;


//绝对值选择
wire [63:0] dividend_64_abs, divisor_64_abs;
assign dividend_64_abs         = dividend_i[63] ? dividend_64_positive : dividend_i;
assign divisor_64_abs          = divisor_i[63]  ? divisor_64_positive  : divisor_i;

// 迭代被除数判断
wire [64:0] dividend_iter   = quotient[127:63] - {1'b0,divisor};
wire [127:0] quotient_shift = quotient << 1;
//========================================
// 对溢出以及除零做检测
always @(*) begin
    div_zero = 0;
    div_of = 0;
    case (div_type_i) 
      REM: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_div_exception = dividend_i;
        end
        else if (dividend_i == {1'b1, 63'b0} && &divisor_i) begin
          div_of = 1;
          result_div_exception = 0;
        end
      end

      DIV: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_div_exception = {64{1'b1}};
        end
        else if (dividend_i == {1'b1, 63'b0} && &divisor_i) begin
          div_of = 1;
          result_div_exception = dividend_i;
        end
      end

      default:begin
          result_div_exception = 0;
          div_zero         = 0;
          div_of           = 0;
      end
    endcase
end

//========================================

// 3段式状态机构建乘法逻辑模块 
always@(posedge clk) begin
  if(rst_n)state<=IDLE;
  else   state<=next_state;
end
/*
被除数 除数 商 余数
+     +   +  +
+     -   -  +
-     +   -  -
-     -   +  -
*/
always @(*) begin
        case(state)
          IDLE  : if(div_valid)  next_state = (div_zero | div_of) ? FINISH : DO_DIV;
                  else           next_state = IDLE  ;
          DO_DIV: if(~|cnt) begin
                      next_state = FINISH ;
                  end
                  else next_state = DO_DIV  ;
          FINISH: if(result_ready)next_state = IDLE ;
                  else next_state = FINISH ;
        default : next_state=IDLE ;
        endcase
end

always @(posedge clk) begin
    if(rst_n) begin
        div_type     <= 0;
        cnt          <= 0;
        quotient_sign<= 0;
        rem_sign     <= 0; 
        divisor      <= 0;
        quotient     <= 0;
    end
    
end

// 根据译码类型输出结果
ysyx_22050019_mux #( .NR_KEY(8), .KEY_LEN(8), .DATA_LEN(64)) mux_out
(
  .key         (div_type), 
  .default_out (quotient[63:0]),
  .lut         ({		
                    8'b10000000,divisor_64_positive,
                    8'b01000000,64'b0,
                    8'b00100000,64'b0,
                    8'b00010000,64'b0,
                    8'b00001000,dividend_64_positive,
                    8'b00000100,64'b0,
                    8'b00000010,64'b0,
                    8'b00000001,64'b0
                    }),          
  .out         (div_out)  
);

//========================================
// 输出控制
assign result_ok  = (state == FINISH);
assign div_stall  = (state == IDLE && next_state == DO_DIV) | (state == DO_DIV);

endmodule
