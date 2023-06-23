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
  input         clk         ,
  input         rst_n       ,
  input         div_valid   , // 除法器开始信号 
  input [7:0]   div_type_i  , // 除法类型
  input [63:0]  dividend_i  , // 被除数
  input [63:0]  divisor_i   , // 除数
  input         result_ready, // 是否准备接收
  output [63:0] div_out     , // 计算结果 
  output        div_stall   , // 计算暂停 
  output        result_ok     // 计算ok 
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
parameter DIV   = 8'b10000000; // 取余数 有符号 64位 
parameter DIVU  = 8'b01000000; // 取余数 无符号 64位 
parameter DIVUW = 8'b00100000; // 取余数 无符号 32位 
parameter DIVW  = 8'b00010000; // 取余数 有符号 32位 
parameter REM   = 8'b00001000; // 除法一 有符号 64位
parameter REMU  = 8'b00000100; // 除法一 无符号 64位
parameter REMUW = 8'b00000010; // 除法一 无符号 32位
parameter REMW  = 8'b00000001; // 除法一 有符号 32位
parameter ERROR = 8'b00000000; // 遇到了除0或溢出

reg [63:0] result_exception;// 异常结果输出
reg div_zero;// 除零通知
reg div_of  ;// 溢出通知

// 32位符号拓展
wire [63:0] dividend_sext32, divisor_sext32;
assign dividend_sext32      = {{32{dividend_i[31]}}, dividend_i[31:0]};
assign divisor_sext32       = {{32{divisor_i[31]}} , divisor_i [31:0]};

// 负数处理
wire [63:0] dividend_positive, divisor_positive;
assign dividend_positive    = ~dividend_i + 1;
assign divisor_positive     = ~divisor_i + 1;

wire [63:0] dividend_positive_32, divisor_positive_32;
assign dividend_positive_32 = ~dividend_sext32 + 1;
assign divisor_positive_32  = ~divisor_sext32  + 1;

//绝对值选择
wire [63:0] dividend_abs, divisor_abs;
assign dividend_abs         = dividend_i[63] ? dividend_positive : dividend_i;
assign divisor_abs          = divisor_i[63]  ? divisor_positive  : divisor_i;

wire [63:0] dividend_abs_32, divisor_abs_32;
assign dividend_abs_32      = dividend_sext32[63] ? dividend_positive_32 : dividend_sext32;
assign divisor_abs_32       = divisor_sext32[63]  ? divisor_positive_32  : divisor_sext32;

// 除法状态机的实现
parameter IDLE    = 2'b00;
parameter DO_DIV  = 2'b01;
parameter FINISH  = 2'b10;

reg [1:0]  state, next_state;

reg [6:0]  cnt, cnt_next;
wire [63:0] result_next;
reg quotient_sign, quotient_sign_next, rem_sign, rem_sign_next;

reg [127:0] quotient, quotient_next;
reg [63:0] divisor, divisor_next;
reg [7:0]  div_type;
wire [127:0] quotient_shift; 
wire [64:0] dividend_iter;
assign dividend_iter  = quotient_shift[127:64] - divisor;
assign quotient_shift = quotient << 1;

wire [63:0] quotient_abs, rem_abs;
assign quotient_abs   = quotient_sign ? (~quotient[63:0] + 1)   : quotient[63:0];
assign rem_abs        = rem_sign      ? (~quotient[127:64] + 1) : quotient[127:64];
//========================================
// 对溢出以及除零做检测
always @(*) begin
    case (div_type_i) 
      DIV: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_exception = {64{1'b1}};
        end
        else if (dividend_i == {1'b1, 63'b0} && &divisor_i) begin
          div_of = 1;
          result_exception = dividend_i;
        end
      end

      DIVU: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_exception = {64{1'b1}};
        end
      end

      DIVUW: begin
        if (~|(divisor_i[31:0])) begin
          div_zero = 1;
          result_exception = {64{1'b1}};
        end
      end

      DIVW: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_exception = {64{1'b1}};
        end
        else if (dividend_i[31:0] == {1'b1, 31'b0} && &(divisor_i[31:0])) begin
          div_of = 1;
          result_exception = dividend_sext32;
        end
      end

      REM: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_exception = dividend_i;
        end
        else if (dividend_i == {1'b1, 63'b0} && &divisor_i) begin
          div_of = 1;
          result_exception = 0;
        end
      end

      REMU: begin
        if (~|divisor_i) begin
          div_zero = 1;
          result_exception = dividend_i;
        end
      end

      REMUW: begin
        if (~|(divisor_i[31:0])) begin
          div_zero = 1;
          result_exception = dividend_sext32;
        end
      end

      REMW: begin
        if (~|(divisor_i[31:0])) begin
          div_zero = 1;
          result_exception = dividend_sext32;
        end
        else if (dividend_i[31:0] == {1'b1, 31'b0} && &(divisor_i[31:0])) begin
          div_of = 1;
          result_exception = 0;
        end
      end

      default:begin
          result_exception = 0;
          div_zero         = 0;
          div_of           = 0;
      end
    endcase
end

//========================================
// 3段式状态机构建乘法逻辑模块 
always@(posedge clk) begin
  if(rst_n)state<=IDLE;
  else    state<=next_state;
end

always @(posedge clk) begin
  if (rst_n) begin
    div_type      <= 0;
    cnt           <= 0;
    quotient_sign <= 0;
    rem_sign      <= 0;
    quotient      <= 0;
    divisor       <= 0;
  end
  else begin
    case (state)  
      IDLE : begin
        if(next_state == FINISH) begin
            div_type <= ERROR;
        end
        else if(next_state == DO_DIV) begin
            div_type      <= div_type_i        ;
            cnt           <= cnt_next          ;
            quotient_sign <= quotient_sign_next;
            rem_sign      <= rem_sign_next     ;
            quotient      <= quotient_next     ;
            divisor       <= divisor_next      ;  
        end
        else if(next_state == IDLE) begin
            div_type      <= 0                 ;
            cnt           <= 0                 ;
            quotient_sign <= 0                 ;
            rem_sign      <= 0                 ;
            quotient      <= 0                 ;
            divisor       <= 0                 ;  
        end
      end
      DO_DIV : begin
        if(next_state == FINISH) begin
        end
        else begin
            cnt           <= cnt_next          ;
            quotient      <= quotient_next     ;
        end
      end
      FINISH : begin
        if(next_state == IDLE) begin
            div_type      <= 0                 ;
            cnt           <= 0                 ;
            quotient_sign <= 0                 ;
            rem_sign      <= 0                 ;
            quotient      <= 0                 ;
            divisor       <= 0                 ; 
        end
        else begin
        end  
      end
      default :begin
      end
    endcase
  end
end

always @(*) begin
  next_state         = state         ; 
  cnt_next           = cnt           ;
  quotient_sign_next = quotient_sign ;
  rem_sign_next      = rem_sign      ;
  quotient_next      = quotient      ;
  divisor_next       = divisor       ;
  case(state)
    IDLE: begin
      if (div_valid) begin
        if (div_zero | div_of) begin
            quotient_next[127:64] = 0;
          quotient_next[63:0] = result_exception;
          next_state          = FINISH;
        end
        else begin
          next_state = DO_DIV;
          case (div_type_i)
              DIV : begin
                cnt_next              = 64;
                quotient_sign_next    = dividend_i[63] ^ divisor_i[63];
                rem_sign_next         = dividend_i[63];
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = dividend_abs;
                divisor_next          = divisor_abs;
              end

              DIVU: begin
                cnt_next              = 64;
                quotient_sign_next    = 0;
                rem_sign_next         = 0;
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = dividend_i;
                divisor_next          = divisor_i;
              end

              DIVUW: begin
                cnt_next              = 32;
                quotient_sign_next    = 0;
                rem_sign_next         = 0;
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = {dividend_i[31:0], 32'b0};
                divisor_next          = {32'b0, divisor_i[31:0]};
              end

              DIVW: begin
                cnt_next              = 32;
                quotient_sign_next    = dividend_i[31] ^ divisor_i[31];
                rem_sign_next         = dividend_i[31];
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = {dividend_abs_32[31:0], 32'b0};
                divisor_next          = divisor_abs_32;
              end

              REM: begin
                cnt_next              = 64;
                quotient_sign_next    = dividend_i[63] ^ divisor_i[63];
                rem_sign_next         = dividend_i[63];
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = dividend_abs;
                divisor_next          = divisor_abs;
              end

              REMU: begin
                cnt_next              = 64;
                quotient_sign_next    = 0;
                rem_sign_next         = 0;
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = dividend_i;
                divisor_next          = divisor_i;
              end

              REMUW: begin
                cnt_next              = 32;
                quotient_sign_next    = 0;
                rem_sign_next         = 0;
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = {dividend_i[31:0], 32'b0};
                divisor_next          = {32'b0, divisor_i[31:0]};
              end

              REMW: begin
                cnt_next              = 32;
                quotient_sign_next    = dividend_i[31] ^ divisor_i[31];
                rem_sign_next         = dividend_i[31];
                quotient_next[127:64] = 0;
                quotient_next[63:0]   = {dividend_abs_32[31:0], 32'b0};
                divisor_next          = divisor_abs_32;
              end

              default:begin
              end
            endcase
          end
        end
        else begin
          next_state = IDLE;
        end
      end
      DO_DIV: begin
        if (~|cnt) begin
          next_state = FINISH;
        end
        else begin
          cnt_next   = cnt - 1;
          next_state = DO_DIV;
          quotient_next[127:64] = dividend_iter[64] ? quotient_shift[127:64]       : dividend_iter[63:0];//迭代核心，相减为负，更新被除法
          quotient_next[63:0]   = dividend_iter[64] ? {quotient_shift[63:1], 1'b0} : {quotient_shift[63:1], 1'b1};
        end
      end
      FINISH: begin
        next_state = result_ready ? IDLE : FINISH;
      end
      default:begin
      end	    
      endcase
end

// 根据译码类型输出结果
ysyx_22050019_mux #( .NR_KEY(8), .KEY_LEN(8), .DATA_LEN(64)) mux_out
(
  .key         (div_type), 
  .default_out (quotient[63:0]),
  .lut         ({		
                    8'b10000000,quotient_abs,
                    8'b01000000,quotient[63:0],
                    8'b00100000,{{32{quotient[31]}},quotient[31:0]},
                    8'b00010000,{{32{quotient_abs[31]}}, quotient_abs[31:0]},
                    8'b00001000,rem_abs,
                    8'b00000100,quotient[127:64],
                    8'b00000010,{{32{quotient[95]}},quotient[95:64]},
                    8'b00000001,{{32{rem_abs[31]}}, rem_abs[31:0]}
                    }),          
  .out         (result_next)  
);

//========================================
// 输出控制
assign result_ok  = (state == FINISH);
assign div_stall  = (state == IDLE && next_state == DO_DIV) | (state == DO_DIV);
assign div_out    = (state == FINISH) ? result_next : 0;

endmodule