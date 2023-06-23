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
  output [63:0] result_o    , // 计算结果 
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

reg [63:0] result_exception;// 异常结果输出
reg div_zero;// 除零通知
reg div_of  ;// 溢出通知

// 32位符号拓展
wire [63:0] dividend_sext32, divisor_sext32;
assign dividend_sext32      = {{32{dividend_i[31]}}, dividend_i[31:0]};
assign divisor_sext32       = {{32{divisor_i[31]}} , divisor_i [31:0]};

// 负数处理
wire [63:0] dividend_positive, divisor_positive;
assign dividend_positive = ~dividend_i + 'h1;
assign divisor_positive = ~divisor_i + 'h1;

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
//========================================
// 对溢出以及除零做检测
always @(*) begin
    case (div_type_i) 
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

      default:begin
          result_exception = 0;
          div_zero         = 0;
          div_of           = 0;
      end
    endcase
end

//========================================
// 除法状态机的实现
parameter IDLE    = 2'b00;
parameter DO_DIV  = 2'b01;
parameter FINISH  = 2'b10;

reg [1:0] state, next_state;

reg [6:0] cnt, cnt_d;
reg [63:0] result,result_next;
reg neg_q, neg_q_d, neg_s, neg_s_d;

reg [127:0] res, res_d;
reg [63:0] divisor, divisor_d;
reg [7:0]  div_type;
wire [127:0] res_shifted; // {s[63:0], q[63:0]}
wire [64:0] s_minus_di;
assign s_minus_di = res_shifted[127:64] - divisor;
assign res_shifted = res << 1;

wire [63:0] q_positive, s_positive;
assign q_positive = neg_q ? (~res[63:0] + 'h1) : res[63:0];
assign s_positive = neg_s ? (~res[127:64] + 'h1) : res[127:64];

  always @(*) begin
    next_state  = state ; 
    result_next = result;
    cnt_d       = cnt   ;
    neg_q_d     = neg_q ;
    neg_s_d     = neg_s ;
    res_d       = res   ;
    divisor_d = divisor ;
	    case(state)
        IDLE: begin
          if (div_valid) begin
            /* 如果是除0或溢出则IDLE态 */
            if (div_zero | div_of) begin
              result_next = result_exception;
              next_state  = FINISH;
            end
            else begin
              next_state = DO_DIV;
              //cnt_d = ;
              //neg_q_d = ;
              //neg_s_d = ;
              //res_d = ;
              //divisor_d = ;
              case (div_type_i)
              DIV: begin
                  cnt_d = {1'b1, 6'b0};
                  neg_q_d = dividend_i[63] ^ divisor_i[63];
                  neg_s_d = dividend_i[63];
                  res_d[127:64] = 0;
                  res_d[63:0] = dividend_abs;
                  divisor_d = divisor_abs;
                end

                DIVU: begin
                  cnt_d = {1'b1, 6'b0};
                  neg_q_d = 0;
                  neg_s_d = 0;
                  res_d[127:64] = 0;
                  res_d[63:0] = dividend_i;
                  divisor_d = divisor_i;
                end

                DIVUW: begin
                  cnt_d = {1'b0, 1'b1, 5'b0};
                  neg_q_d = 0;
                  neg_s_d = 0;
                  res_d[127:64] = 0;
                  res_d[63:0] = {dividend_i[31:0], {32{1'b0}}};
                  divisor_d = {{32{1'b0}}, divisor_i[31:0]};
                end

                DIVW: begin
                  cnt_d = {1'b0, 1'b1, 5'b0};
                  neg_q_d = dividend_i[31] ^ divisor_i[31];
                  neg_s_d = dividend_i[31];
                  res_d[127:64] = 0;
                  res_d[63:0] = {dividend_abs_32[31:0], 32'b0};
                  divisor_d = divisor_abs_32;
                end

                REMU: begin
                  cnt_d = {1'b1, 6'b0};
                  neg_q_d = 0;
                  neg_s_d = 0;
                  res_d[127:64] = 0;
                  res_d[63:0] = dividend_i;
                  divisor_d = divisor_i;
                end

                REM: begin
                  cnt_d = {1'b1, 6'b0};
                  neg_q_d = dividend_i[63] ^ divisor_i[63];
                  neg_s_d = dividend_i[63];
                  res_d[127:64] = 0;
                  res_d[63:0] = dividend_abs;
                  divisor_d = divisor_abs;
                end

                REMUW: begin
                  cnt_d = {1'b0, 1'b1, 5'b0};
                  neg_q_d = 0;
                  neg_s_d = 0;
                  res_d[127:64] = 0;
                  res_d[63:0] = {dividend_i[31:0], {32{1'b0}}};
                  divisor_d = {{32{1'b0}}, divisor_i[31:0]};
                end

                REMW: begin
                  cnt_d = {1'b0, 1'b1, 5'b0};
                  neg_q_d = dividend_i[31] ^ divisor_i[31];
                  neg_s_d = dividend_i[31];
                  res_d[127:64] = 0;
                  res_d[63:0] = {dividend_abs_32[31:0], 32'b0};
                  divisor_d = divisor_abs_32;
                end

                default:;
              endcase
            end
          end
          /* 否则就是IDLE */
          else begin
            next_state = IDLE;
          end
        end

        DO_DIV: begin
          if (~|cnt) begin
            next_state = FINISH;
          end
          else begin
            cnt_d = cnt - 1;
            next_state = DO_DIV;
            if (s_minus_di[64]) begin
              res_d[127:64] = res_shifted[127:64];
              res_d[63:0] = {res_shifted[63:1], 1'b0};
            end
            else begin
              res_d[127:64] = s_minus_di[63:0];
              res_d[63:0] = {res_shifted[63:1], 1'b1};
            end
          end
        end

        FINISH: begin
          if(result_ready) next_state = IDLE;
          case (div_type)
          DIV: begin
              result_next = q_positive;
            end
            DIVU: begin
              result_next = res[63:0];
            end
            DIVUW: begin
              result_next = {{32{res[31]}}, res[31:0]};
            end
            DIVW: begin
              result_next = {{32{q_positive[31]}}, q_positive[31:0]};
            end
            REMU: begin
              result_next = res[127:64];
            end
            REM: begin
              result_next = s_positive;
            end
            REMUW: begin
              result_next = {{32{res[95]}}, res[95:64]};
            end
            REMW: begin
              result_next = {{32{s_positive[31]}}, s_positive[31:0]};
            end
            default: begin
              result_next = 0;
            end
          endcase
        end

        default:;
	    endcase
  end

  always @(posedge clk) begin
    if (rst_n) begin
	  state <= IDLE;
      div_type <= 0;
      cnt <= 0;
      neg_q <= 0;
      neg_s <= 0;
      res <= 0;
      divisor <= 0;
      result <= 0;
	  end
	  else begin
	  state <= next_state;
      div_type <= (state == IDLE && next_state == DO_DIV) ? div_type_i : div_type;
      cnt <= cnt_d;
      neg_q <= neg_q_d;
      neg_s <= neg_s_d;
      res <= res_d;
      divisor <= divisor_d;
      result <= result_next;
	  end
  end

//========================================
// 输出控制
assign result_ok  = (state == FINISH);
assign div_stall  = (state == IDLE && next_state == DO_DIV) | (state == DO_DIV);
assign result_o = (state == FINISH) ? result_next : 0;

endmodule