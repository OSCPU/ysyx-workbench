#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>
enum {
  TK_NOTYPE = 256, TK_EQ=255,TK_NEQ=254,TK_OR=253,
  NUMBER=250,TK_REG=251,TK_and=252,TK_HEX=248,TK_LM=247,TK_RM=246,TK_PT=245
  ,TK_NEG=244,TK_NO=242,TK_BE=241,TK_SE=240
  /* TODO: Add more token types */

};
word_t eval(int p, int q, bool *success);
int Is_op(int type);
int check_parentheses(int p,int q);
int Min_priority(int p,int q);
static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
  {"\\$[\\$0|ra|sp|gp|tp|t0|t1|t2|s0|s1|a0|a1|a2|a3|a4|a5|a6|a7|s2|s3|s4|s5|s6|s7|s8|s9|s10|s11|t3|t4|t5|t6]+",TK_REG},
  {"/",'/'},          // "/"
  {"\\*",'*'},          // "*"
  {"\\)",')'},          // right_c
  {"\\(",'('},          // left_c
  {"0[xX][0-9A-Fa-f]+",TK_HEX},
  {"[0-9]+",NUMBER},    // number
  {"-",'-'},            // sub
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"!=", TK_NEQ},       // not equal
  {"==", TK_EQ},        // equal
  {"<=", TK_BE},
  {">=", TK_SE},
  {"!",TK_NO},
  {"<<",TK_LM},
  {">>",TK_RM},
  {"&&",TK_and},
  {"\\|\\|",TK_OR}    // or
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

static Token tokens[1024] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

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
        for (int j = 0; j < 32; ++j) {
            tokens[nr_token].str[j] = '\0';
        }
        position += substr_len; 

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case '-': if(nr_token==0 || tokens[nr_token-1].type=='(' || (Is_op(tokens[nr_token-1].type))==1){
                      tokens[nr_token++].type=TK_NEG;
                      Log("get a neg\n");
                    }
                    else {//if(tokens[nr_token-1].type==')' || tokens[nr_token-1].type==TK_HEX ||tokens[nr_token-1].type==NUMBER ||tokens[nr_token-1].type==TK_REG)
                      tokens[nr_token++].type=rules[i].token_type;
                      Log("now i is %d an op is - and nr_tokens is%d",i,nr_token);
                      }
                    break;
          case '*': if(nr_token==0 || tokens[nr_token-1].type=='(' || Is_op(tokens[nr_token-1].type)==1){
                      tokens[nr_token++].type=TK_PT;
                      Log("get a point\n");
                    }
                    else //if(tokens[nr_token-1].type==')' || tokens[nr_token-1].type==TK_HEX ||tokens[nr_token-1].type==NUMBER)
                      tokens[nr_token++].type=rules[i].token_type;
                    break;
          case '/':
          case '+':
          case TK_and:
          case TK_EQ:
          case TK_LM:
          case TK_RM:
          case TK_NEQ:
          case TK_NO:
          case TK_BE:
          case TK_SE:
          case TK_OR:
          case '(':
          case ')':
             tokens[nr_token++].type=rules[i].token_type;
             break;
          case TK_NOTYPE: 
                break;
          case NUMBER:
          case TK_HEX:
          case TK_REG:strncpy(tokens[nr_token].str,substr_start,substr_len);
                tokens[nr_token++].type=rules[i].token_type;
                Log("read a num %s",tokens[i].str);
                break;
          default:
          Log("REGEX wrong");
          assert(0);
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

int Is_op(int type){
  if(type=='/'|| type=='*' || type == '+' || type == '-' || type == TK_and 
  || type == TK_OR || type == TK_EQ || type == TK_NEQ || type == TK_NO || type == TK_NEG
  || type ==TK_BE || type ==TK_SE)
  return 1;
  else return 0;
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */

  *success=true;
  word_t ans=eval(0,nr_token-1,success);
  if(*success)
    return ans;
  else {
    Log(" wrong at least");
    return 0;
  }
}
word_t eval(int p, int q, bool *success) {
  //bool * success;
  uint64_t num,val1,val2;
  if (p > q) {
    *success=false;
    Log("p>q bad parentheses");
    return 0;
  }
  else if (p == q) {
    /* Single token.
     * For now this token should be a number.
     * Return the value of the number.
     */
    if(tokens[p].type == NUMBER){
      sscanf(tokens[p].str,"%lu",&num);
      return num;
    }
    else if(tokens[p].type==TK_HEX){
      sscanf(tokens[p].str,"%lx",&num);
      return num;
    }
    else if(tokens[p].type==TK_REG){
        if(isa_reg_str2val(tokens[p].str,success)==-1){
          Log(" No this reg %s",tokens[p].str);
          return 0;
        }
        return isa_reg_str2val(tokens[p].str,success);
    }
    else if(!*success) { Log("eval_reg wrong");return 0;}
    else{
    printf("p==q bad parentheses");
    assert(0);
    }
  }
  else if(q - p == 1){
    if(tokens[p].type==TK_PT){
      sscanf(tokens[q].str, "%lx", &num);
      num = paddr_read(num, 4);
      return num;
    }
    else if(tokens[p].type==TK_NEG)
      return (-eval(p+1,q,success));
    else if(tokens[p].type==TK_NO)
      return !eval(p+1,q,success);
    else {
      Log("q-p==1 wrong");
      assert(0);
    }
  }
  else if (check_parentheses(p, q) == true) {
    /* The expression is surrounded by a matched pair of parentheses.
     * If that is the case, just throw away the parentheses.
     */
    return eval(p + 1, q - 1,success);
  }
  
  else 
  {
    /* We should do more things here. */
    int op=Min_priority(p,q);
    if(op==-2){
      printf("p<q bad parentheses");
      assert(0);
    }
    // if(op==-1){
    //   Log(" no op");
    //   *success=false;
    //   return 0;
    // }
    val1 = eval(p, op - 1,success);
    val2 = eval(op + 1, q,success);
    switch (tokens[op].type) {
            case '+' :
                return val1 + val2;
            case '-' :
                return val1 - val2;
            case '*' :
                return val1 * val2;
            case '/' :
                return val1 / val2;
            case TK_LM:
                return val1 << val2;
            case TK_RM:
                return val1 >> val2;
            case TK_EQ  :
                return val1 == val2;
            case TK_BE:
                return val1 >= val2;
            case TK_SE:
                return val1 <= val2;
            case TK_NO :
                return !val2;
            case TK_NEQ :
                return val1 != val2;
            case TK_and:
                return val1 && val2;
            case TK_OR:
                return val1||val2;
            default:
                assert(0);
        }
  }
}

//根据讲义,()中从左边遍历,第一个遇见的不能是),因为这样说明()并没有包括所有,而是小括号,所以先判定为左括号
//同理,然后判断最后遇到的)不是q位置的),然后pq间的()匹配
int check_parentheses(int p,int q){
  int cnt=0;
  if(tokens[p].type=='('&& tokens[q].type==')'){
    for(int i=p+1;i<q;i++){
      if (tokens[i].type=='(')
        cnt++;
      if(tokens[i].type==')')
        cnt--;
      if(cnt<0)
        return 0;
    }
    return 1;
  }
  return 0;
}
// 找到优先级最小的操作符,然后对两边进行递归
int Min_priority(int p,int q){
    int pos = 0;
    int op = 6;
    int count=6;
    int flag;
    for (int i = p; i <= q; i++) {
        if (tokens[i].type == '(') pos++;
        else if (tokens[i].type == ')') pos--;
        if (pos == 0) {
            switch (tokens[i].type) {
              case TK_OR: 
                    flag=0;
                    count = flag <= count ? flag:count;
                    op =flag <= count ? i : op;
                    break;
              case TK_and: flag=1;
                    count = flag <= count ? flag:count;
                    op =flag <= count ? i : op;
                    break;
              case TK_EQ:
              case TK_NEQ:
              case TK_BE:
              case TK_SE:
                    flag=2;
                    count = flag <= count ? flag:count;
                    op =flag <= count ? i : op;
                    break;
              case TK_LM:
              case TK_RM:
                    flag=3;
                    count = flag <= count ? flag:count;
                    op =flag <= count ? i : op;
                    break;
              case '+':
              case '-':
              case TK_NO:
                    flag=4;
                    count = flag <= count ? flag:count;
                    op =flag <= count ? i : op;
                    break;
              case '*':
              case '/':
                    flag=5;
                    count = flag <= count ? flag:count;
                    op =flag <= count ? i : op;
              break;
            }
        } 
    }
    return op;
}