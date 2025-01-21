/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <limits.h>
#include <stdint.h>  // 引入 uintptr_t
#include <regex.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <memory/vaddr.h>
#include <memory/paddr.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ,
  TK_NEQ,          // !=
  TK_HEX,          // 十六进制数
  TK_DEC,          // 十进制数
  TK_REG,          // 寄存器
  TK_VAR,          // 变量
  TK_DEREF,        // 指针解引用 *
  TK_AND,          // &&
  TK_OR,           // ||
  TK_PLUS,          // +
  TK_MINUS,          // -
  TK_MUL,          // *
  TK_DIV,          // /
  TK_LP,           // (
  TK_RP,           // )
  /* TODO: Add more token types */
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {"-", TK_MINUS},                  // 减号
  {"\\*", TK_MUL},                // 乘号或解引用
  {"/", TK_DIV},                  // 除号
  {"\\(", '('},                // 左括号
  {"\\)", ')'},                // 右括号
  {"&&", TK_AND},              // 逻辑与
  {"\\|\\|", TK_OR},           // 逻辑或               
  {"!=", TK_NEQ},              // 不等于
  {"0[xX][0-9a-fA-F]+", TK_HEX},  // 十六进制数字
  {"[0-9]+", TK_DEC},          // 十进制数字
  {"\\$[a-zA-Z_][a-zA-Z0-9_]*", TK_REG}, // 寄存器
  {"[a-zA-Z_][a-zA-Z0-9_]*", TK_VAR},   // 变量名
 {"\\*", TK_DEREF},      // 指针解引用
  {" +", TK_NOTYPE},    // spaces
  {"\\+", TK_PLUS},         // plus
  {"==", TK_EQ},        // equal
};

#define NR_REGEX ARRLEN(rules)
#define MAX_TOKEN_LENGTH 32
static regex_t re[NR_REGEX] = {};
bool matched = false;
// 在文件的顶部或者调用前添加声明
int get_priority(int type);
int n=5;
int *p=&n;

bool check_parentheses(int p, int q);
int min_priority = INT_MAX; // 当前最低优先级
#define TK_NUM 260  // 或者其他适当的值
/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

typedef struct {
    bool success;
    int value;
} EvalResult;


static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

int find_main_operator(int p, int q) {
    int min_priority = INT_MAX;
    int main_op = -1;
    int balance = 0;

    for (int i = p; i <= q; i++) {
        if (tokens[i].type == '(') balance++;
        else if (tokens[i].type == ')') balance--;
        if (balance > 0) continue;  // 括号内的操作符跳过

        int priority = get_priority(tokens[i].type);
        if (priority >= 0 && priority <= min_priority) {
            min_priority = priority;
            main_op = i;
        }
    }
    printf("the return is %d ",main_op);
    return main_op;
}


int get_priority(int type) {
  switch (type) {
    case TK_PLUS: case TK_MINUS: 
      return 1;  // 加减运算符的优先级
    case TK_MUL: case TK_DIV: 
      return 2;  // 乘除运算符的优先级
    case TK_AND: 
      return 3;  // 与运算符的优先级
    case TK_OR: 
      return 4;  // 或运算符的优先级
    case TK_EQ:  
      return 5;  // 比较运算符的优先级
	 case TK_NEQ:
		return 6;
    default:
      return INT_MAX; // 非运算符的优先级
  }
}

// 假设物理内存的范围是 0x80000000 到 0x8FFFFFFF 
#define MEM_BASE 0x80000000 
#define MEM_SIZE 0x10000000 
 
bool is_address_mapped(uintptr_t addr) { 
    return addr >= MEM_BASE && addr < MEM_BASE + MEM_SIZE; 
} 
 





EvalResult eval(int p, int q) {
    EvalResult result;
    result.success = false;

    if (p > q) {
        // 无效表达式
        printf("Invalid expression from %d to %d\n", p, q);
        return result;
    }

    if (p == q) {
        // 单个 token，必须是数字
	printf("tokens[%d].type = %d, tokens[%d].str = %s\n", p, tokens[p].type, p, tokens[p].str);
        if (tokens[p].type == TK_NUM) {
            result.success = true;
            result.value = atoi(tokens[p].str);  // 将字符串转为整数
            return result;
        }else  if(tokens[p].type == TK_REG)
        {
                bool success = false;
            result.value = isa_reg_str2val(tokens[p].str + 1, &success);  // 去>掉 '$' 符号
            if (!success) {
                printf("Invalid register at position %d: %s\n", p, tokens[p].str);
                return result;
            }
            result.success = true;
            return result;



	}
   
           
	
    
    }
    // 括号匹配检测
    if (tokens[p].type == '(' && tokens[q].type == ')') {
        // 检查括号是否匹配
        int match = check_parentheses(p, q);
        if (match) {
            // 括号匹配，递归解析内部表达式
            return eval(p + 1, q - 1);
        } else {
            printf("Mismatched parentheses from %d to %d\n", p, q);
            return result;
        }
    }
 if (tokens[p].type == TK_DEREF) {
	 if (tokens[p+1].type==TK_HEX)
	 {
		// printf("fuckyoufuck ytouajikshjdoah");
		 uintptr_t addr = (uintptr_t)strtol(tokens[p+1].str, NULL, 16); // 将字符串转换为十六进制地址
    printf("Resolved address: 0x%lx\n", addr);

    // 检查地址是否有效
    if (addr == 0) {
        printf("Error: NULL pointer dereference!\n");
        result.success = false;
        return result;
    }

    // 使用 vaddr_ifetch 从虚拟地址中获取指令内容
     printf("Reading content at address 0x%lx...\n", addr);
    int value = paddr_read(addr, 4);  // 读取该地址内容
    printf("Content at address 0x%lx: 0x%x\n", addr, value);

    // 设置结果
    result.success = true;
    result.value = value; // 将读取的内容作为结果返回
    return result;
	 }
        }


    // 找到主操作符（优先级最低的）
    int op = find_main_operator(p, q);
    if (op == -1) {
        printf("No valid operator found from %d to %d\n", p, q);
        return result;
    }

    // 递归计算左右子表达式
    EvalResult left = eval(p, op - 1);
    EvalResult right = eval(op + 1, q);
    if (!left.success || !right.success) {
        return result;
    }

    // 根据操作符计算结果
    switch (tokens[op].type) {
        case TK_PLUS: result.value = left.value + right.value; break;
        case TK_MINUS: result.value = left.value - right.value; break;
        case TK_MUL: result.value = left.value * right.value; break;
        case TK_DIV:
            if (right.value == 0) {
                printf("Division by zero!\n");
                return result;
            }
            result.value = left.value / right.value;
            break;
	    case TK_EQ: result.value = (left.value == right.value);
///		printf(" %c\n", tokens[op].type);
       		printf("%d ",TK_EQ);
			break;
	    case TK_NEQ:result.value = (left.value != right.value);
			printf("%d ",TK_NEQ);
			break;
case TK_AND:result.value = (left.value &&  right.value);
                        
                        break;
	  


        default:
            printf("Unsupported operator at position %d: %c\n", op, tokens[op].type);
            return result;
    }
   

    result.success = true;
    return result;
}

bool check_parentheses(int p, int q) {
    int balance = 0;
    for (int i = p; i <= q; i++) {
        if (tokens[i].type == '(') balance++;
        else if (tokens[i].type == ')') balance--;
        if (balance < 0) return 0;  // 遇到未匹配的右括号
    }
    return balance == 0;
}


static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        assert(substr_len < MAX_TOKEN_LENGTH);

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

/*for (i = 0; i < nr_token; i ++) {
  if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type != TK_NUM) ) {
    tokens[i].type = TK_DEREF;
  }  if((i!=0)&&(tokens[i - 1].type == TK_NUM))  tokens[i].type = TK_MUL;
printf("%d ",tokens[i].type);
  
}*/
	

        switch (rules[i].token_type) {

	case TK_PLUS: {
    tokens[nr_token].type = TK_PLUS;  // 确保将 + 设置为 TK_PLUS
 printf("%d \n",TK_PLUS);
    strncpy(tokens[nr_token].str, substr_start, substr_len);
    tokens[nr_token].str[substr_len] = '\0';
    printf("Before increment: Token type: %d, Token string: %s\n", tokens[nr_token].type, tokens[nr_token].str);
    nr_token++;
    matched = true;
    printf("Token type: %d, Token string: %s\n", tokens[nr_token-1].type, tokens[nr_token-1].str);

    break;
}
  case TK_MINUS: {
        tokens[nr_token].type = TK_MINUS;
        strncpy(tokens[nr_token].str, substr_start, substr_len);
        tokens[nr_token].str[substr_len] = '\0';
        nr_token++;
        matched = true;
        break;
    }


case TK_MUL: {
        tokens[nr_token].type = TK_MUL;
        strncpy(tokens[nr_token].str, substr_start, substr_len);
        tokens[nr_token].str[substr_len] = '\0';
        nr_token++;
        matched = true;
        break;
    }
    case TK_DIV: {
        tokens[nr_token].type = TK_DIV;
        strncpy(tokens[nr_token].str, substr_start, substr_len);
        tokens[nr_token].str[substr_len] = '\0';
        nr_token++;
        matched = true;
        break;
    }
	
          case TK_NOTYPE: {
            // Ignore spaces, do nothing.
            matched = true;
            break;
          }
          case TK_EQ: {
            // Equals '=='
            tokens[nr_token].type = TK_EQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }
          case TK_HEX: {
            // Hexadecimal number like 0x123abc
            tokens[nr_token].type = TK_HEX;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }
          case TK_DEC: {
            // Decimal number like 123, 456
            tokens[nr_token].type = TK_DEC;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }
          case TK_REG: {
            // Register like $a0, $t1, etc.
            tokens[nr_token].type = TK_REG;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }
          case TK_VAR: {
            // Variable name
            tokens[nr_token].type = TK_VAR;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }
          case TK_DEREF: {
         tokens[nr_token].type = TK_DEREF;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;

          }
case TK_NEQ: {
            // Equals '=='
            tokens[nr_token].type = TK_NEQ;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }

case TK_AND: {
            // Equals '=='
            tokens[nr_token].type = TK_AND;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }




         // case '+':
          case '-':
          case '*':
          case '/':
          case '(':
          case ')': {

            // Operator or parenthesis
            tokens[nr_token].type = rules[i].token_type;
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            nr_token++;
            matched = true;
            break;
          }
          default:
            printf("Unexpected token type: %d\n", rules[i].token_type);
            return false;
        }

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}



word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
	 // printf("Error: Failed to tokenize expression: %s\n", e);
    *success = false;
    return 0;
  }	

/*for (i = 0; i < nr_token; i ++) {
  if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type == certain type) ) {
    tokens[i].type = TK_DEREF;
  }
}*/
        /* 遍历所有 token */
for (int i = 0; i < nr_token; i ++) {
  if (tokens[i].type == TK_MUL && (i == 0 || tokens[i - 1].type != TK_NUM )) {
   printf("wodiaonimade success:%d ",TK_DEREF);
    printf("wodiaonimade success:%d ",TK_HEX);

	 tokens[i].type = TK_DEREF;
  }
}



  /* TODO: Insert codes to evaluate the exression. */
   EvalResult result = eval(0, nr_token - 1);
  if (result.success) {
    *success = true;
    return result.value;
  } else {
    *success = false;
    return 0;
  }
}
