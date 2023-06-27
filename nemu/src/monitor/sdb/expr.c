#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

#include <memory/paddr.h>

enum {
  TK_NOTYPE = 256,
  TK_EQ,
	TK_NOTEQ,
	TK_LOGAND,
  TK_DECNUM,
	TK_HEXNUM,
	TK_REG,
	TK_NEGATIVE,
	TK_POINTER
};

static int token_rank[512];

//正则表达式中\\匹配真正字符，\匹配转义字符
static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},            // spaces
  {"\\+", '+'},                 // +
  {"\\-", '-'},                 // -
  {"\\*", '*'},                 // *
  {"\\/", '/'},                 // /
  {"\\(", '('},                 // (
  {"\\)", ')'},                 // )
  {"==", TK_EQ},				        // ==
  {"!=", TK_NOTEQ},			        // !=
  {"&&", TK_LOGAND},		        // &&
  {"0x[0-9a-fA-F]+", TK_HEXNUM},// 16-based number
  {"[0-9]+", TK_DECNUM}, 			  // 10-based number
  {"\\$\\S+", TK_REG}			      // register
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

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

static Token tokens[65536] __attribute__((used)) = {};
// 已经被识别出的token数目
static int nr_token __attribute__((used))  = 0;

// 解析参数匹配表达式中的字符，将信息依次存入tokens数组中
static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        /* ignore whitespaces */
        if (rules[i].token_type == TK_NOTYPE)
          break;
        /* save token type */
        tokens[nr_token].type = rules[i].token_type;
        // 有值的str赋值操作
        switch (rules[i].token_type) {
					case TK_DECNUM:
					case TK_HEXNUM:
					case TK_REG:
            /* for TK_DECNUM and TK_HEXNUM, store its value */
            assert(substr_len <= 32); // str size check
            memset(tokens[nr_token].str, 0, sizeof(tokens[nr_token].str));
            memcpy(tokens[nr_token].str, substr_start, substr_len);
            break;
          default: break;
        }
        ++nr_token;
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

// 括号匹配
static bool check_parentheses(int p, int q, bool *success)
{
  if (tokens[p].type != '(' || tokens[q].type != ')'){
    printf("[check_parentheses] 未被括号包起无法去括号 \n");
    return false;
  }
  int par = 0;
  int i = p + 1;
  for (; i < q; i++) {
    if (tokens[i].type == '(') ++par;
    if (tokens[i].type == ')') --par;
    printf("%d-%d,",i,par);
    if (par < 0) {
			printf("[check_parentheses] 无法去括号-i=%d-par=%d.\n", i,par);
			return false;
		}
  }
  if(par == 0){ 
    printf("[check_parentheses] 正确括号规则 %d.\n", i);
    return true;
  }
  else{
    printf("[check_parentheses] 错误括号规则 par=%d\n", par);
    return false;
  }
}

// 转化10/16进制数转换为整数，
static uint64_t str_int(char *s, unsigned base)
{
	int len = strlen(s);
	uint64_t ret = 0;
	for (int i = 0; i < len; ++i) {
    // 字符转10进制偏移
		if (s[i] >= '0' && s[i] <= '9') ret = ret * base + s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f') ret = ret * base + s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F') ret = ret * base + s[i] - 'A' + 10;
	}
	return ret;
}

//递归表达式成子表达式求值计算
static uint64_t eval(int p, int q, bool *success)
{
  if (*success == false) return 0;
  if (p > q) {
    /* 错误的表达式 */
    *success = false;
		printf("Bad expression at eval(%d %d).\n", p, q);
		return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    // 获取返回相应类型的整数值
		if (tokens[p].type == TK_DECNUM) return str_int(tokens[p].str, 10);
		else if (tokens[p].type == TK_HEXNUM) return str_int(tokens[p].str + 2, 16);
		else if (tokens[p].type == TK_REG) {
			uint64_t ret = isa_reg_str2val(tokens[p].str + 1, success);
			if (*success == false) {
				printf("No such register '%s'.\n", tokens[p].str);
				return 0;
			}
			return ret;
		} else {
			printf("Token '%s' 不是寄存器\n", tokens[p].str);
			return 0;
		}
  }
  // 判断去括号的递归
  else if (check_parentheses(p, q, success) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1, success);
  }
  else {
      if (*success == false) return 0;
    int op = -1;
    int par = 0;
    for (int i = p; i <= q; i++) {
      if (tokens[i].type == '(') ++par;
      if (tokens[i].type == ')') --par;
      if (par == 0) {
          if (token_rank[tokens[i].type] == 0) continue;
          // Compare the level of operators, find the last lowest one.
          if (op == -1 || token_rank[tokens[i].type] >= token_rank[tokens[op].type]) {op = i;
			    printf("主运算符 %d temple %s.\n", i, rules[i].regex);
          }
      }
    }
    // printf("Eval(%d, %d): 主运算符 在 %d.\n", p, q, op);
    /* 如果没有找到主运算符 */
    if (op == -1) {
			*success = false;
			printf("无法找到主运算符 eval(%d, %d).\n", p, q);
			return 0;
		}
		// 获取指针或者负数的值, p = op
		if (p == op) {
			uint64_t res = eval(op + 1, q, success);
			if (*success == false) return 0;
			if (tokens[op].type == TK_POINTER)
				return (uint64_t)(*guest_to_host(res));
			if (tokens[op].type == TK_NEGATIVE)
				return (uint64_t)(-res);
			*success = false;
			return 0;
		}
    // 递归主符号左右操作数
    uint64_t val1 = eval(p, op - 1, success);
    uint64_t val2 = eval(op + 1, q, success);
		// printf("%d %d: %u %c %u\n", p, q, val1, tokens[op].type, val2);

		if (*success == false) return 0;

    // 计算主符号左右操作数字求值
    switch (tokens[op].type) {
      case '+':
        return val1 + val2;
      case '-':
        return val1 - val2;
      case '*':
        return val1 * val2;
      case '/':
        // The divisor cannot be zero
        if (val2 == 0) {
					*success = false;
					printf("0不能作为被除数 eval(%d, %d).\n", p, q);
					return 0;
				}
        return val1 / val2;
        case TK_EQ:
				return val1 == val2;
        case TK_NOTEQ:
				return val1 != val2;
			  case TK_LOGAND:
				return val1 && val2;
        default:
				*success = false;
				printf("未找到 token's type  %d.\n", op);
				return 0;
    }
  }
}

// 初始化优先级数组
static void init_token_rank()
{
	#define r token_rank
	// 1: ( )
	r['('] = r[')'] = 1;
	// 2: -(negative) *(pointer)
	r[TK_NEGATIVE] = r[TK_POINTER] = 2;
	// 3: / *
	r['/'] = r['*'] = 3;
	// 4: + -
	r['+'] = r['-'] = 4;
	// 5: == !=
	r[TK_EQ] = r[TK_NOTEQ] = 5;
	// 6: &&
	r[TK_LOGAND] = 6;
}

/*
      表达式求值主函数
执行内容
接受参数转化位token序列->初始化优先级数组->判断指针与负数->计算表达式的值
*/
word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

	init_token_rank();

	// */-前不是')'或数字或寄存器的数值
  for (int i = 0; i < nr_token; i++) {
		if (i == 0 || (tokens[i - 1].type != TK_DECNUM && tokens[i - 1].type != TK_HEXNUM
					&& tokens[i - 1].type != ')' && tokens[i - 1].type != TK_REG)) {
			// 指针
			if (tokens[i].type == '*') tokens[i].type = TK_POINTER;
			// 负数
			if (tokens[i].type == '-') tokens[i].type = TK_NEGATIVE;
		}
	}

  // 0号为p-token，nr_token - 1为m-token计算表达式的全部token
  uint64_t ret = eval(0, nr_token - 1, success);

  if (*success == false) return 0;

  return ret;
}
