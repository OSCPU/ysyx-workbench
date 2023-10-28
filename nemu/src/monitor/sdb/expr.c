/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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


#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
bool check_parentheses(int p, int q);
uint32_t eval(int p , int q);
int char_to_int(char s[]);
void int_to_char(int x,char str[]);
int flat_HEX=0;
#define max(a,b) (((a)>(b))?(a):(b))


#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256,EQ,Num,LEQ,NOTEQ,OR,AND,RESGISTER,HEX,

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-",'-'},
  {"\\*",'*'},
  {"/",'/'},
  {"\\(",'('},
  {"\\)",')'},
  {"==", EQ},        // equal
  {"\\<\\=",LEQ},
  {"\\!\\=",NOTEQ},
  {"\\|\\|",OR},
  {"\\&\\&",AND},
  {"\\!",'!'},
  {"\\$[a-zA-Z]*[0-9]*",RESGISTER},//下面顺序不可倒过来
  {"0[xX][0-9a-fA-F]+",HEX},
  {"[0-9]+",Num},


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

static Token tokens[32] __attribute__((used)) = {};
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

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
	  case '+':
	  case '-':
	  case ')':
	  case '(':
	  case '/':
	  case '*':
	  case '!':
	  case RESGISTER:
	  case HEX:
	  case EQ:
	  case NOTEQ:
	  case LEQ:
	  case OR:
	  case AND:
	  case Num:
	  	tokens[nr_token].type=rules[i].token_type;
		strncpy(tokens[nr_token++].str,substr_start,substr_len);
		tokens[nr_token].str[substr_len] ='\0';
		break;
	  case TK_NOTYPE :break;

          default: TODO();
        }
          if(nr_token==32)
	  {
	     Assert(0,"the tokens full");
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
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
int tokens_len = nr_token;
     /*
     * Register
     */

    for(int i = 0 ; i < tokens_len ; i ++)
    {
	if(tokens[i].type == RESGISTER)
	{
	    bool flat = true;
	    int tmp = isa_reg_str2val(tokens[i].str, &flat);
	    if(flat)
	    {
		int_to_char(tmp, tokens[i].str); // transfrom the str --> $egx
	    }
	    else
	    {
		printf("Transfrom error. \n");
		assert(0);
	    }
	}
    }
    /*
     * HEX
     */
    for(int i = 0 ; i < tokens_len ; i ++)
    {
        if(tokens[i].type == HEX)// Hex num
        {
	    flat_HEX=1;
            int value = strtol(tokens[i].str, NULL, 16);
            int_to_char(value, tokens[i].str);
        }
    }
    /*
     * 负数
     */
    for(int i = 0 ; i < tokens_len ; i ++)
    {
	if((tokens[i].type == '-' && i > 0 && tokens[i-1].type != Num && tokens[i+1].type == Num)
		||
		(tokens[i].type == '-' && i == 0)
	  )
	{
	    tokens[i].type = TK_NOTYPE;
	    for(int j = 31 ; j >= 0 ; j --){
		tokens[i+1].str[j] = tokens[i+1].str[j-1];
	    }
	    tokens[i+1].str[0] = '-';
	    for(int j = 0 ; j < tokens_len ; j ++){
		if(tokens[j].type == TK_NOTYPE)
		{
		    for(int k = j +1 ; k < tokens_len ; k ++){
			tokens[k - 1] = tokens[k];
		    }
		    tokens_len -- ;
		}
	    }
	}
    }

     // ! reverse
    for(int i = 0 ; i < tokens_len ; i ++)
    {
	if(tokens[i].type == '!')
	{
	    tokens[i].type = TK_NOTYPE;
	    int tmp = char_to_int(tokens[i+1].str);
	    if(tmp == 0){
		memset(tokens[i+1].str, 0 ,sizeof(tokens[i+1].str));
		tokens[i+1].str[0] = '1';
	    }
	    else
	    {
		memset(tokens[i+1].str, 0 , sizeof(tokens[i+1].str));
	    }
	    for(int j = 0 ; j < tokens_len ; j ++){
		if(tokens[j].type == TK_NOTYPE)
		{
		    for(int k = j +1 ; k < tokens_len ; k ++){
			tokens[k - 1] = tokens[k];
		    }
		    tokens_len -- ;
		}
	    }
	}
    }
    /*
     *   the *()
     * */
    for(int i = 0 ; i < tokens_len ; i ++)
    {
	if(	(tokens[i].type == '*' && i > 0 
		    && tokens[i-1].type != Num && tokens[i-1].type != HEX && tokens[i-1].type != RESGISTER
		    && tokens[i+1].type == Num 
		    )
                ||
		(tokens[i].type == '*' && i > 0
                    && tokens[i-1].type != Num && tokens[i-1].type != HEX && tokens[i-1].type != RESGISTER
                    && tokens[i+1].type == HEX
                    )
		||
                (tokens[i].type == '*' && i == 0)
          )
		{
            tokens[i].type = TK_NOTYPE;
            int tmp = char_to_int(tokens[i+1].str);
            uintptr_t a = (uintptr_t)tmp;//int <-> *()
            int value = *((int*)a);
            int_to_char(value, tokens[i+1].str);	    
            for(int j = 0 ; j < tokens_len ; j ++){
                if(tokens[j].type == TK_NOTYPE){
                    for(int k = j +1 ; k < tokens_len ; k ++){
                    tokens[k - 1] = tokens[k];
                }
                    tokens_len -- ;
                }
            }
		}
    }


  return eval(0,tokens_len-1);
}


bool check_parentheses(int p, int q)
{
    if(tokens[p].type != '('  || tokens[q].type != ')')
        return false;
    int l = p , r = q;
    while(l < r)
    {
        if(tokens[l].type == '('){
            if(tokens[r].type == ')')
            {
                l ++ , r --;
                continue;
            }

            else
                r --;
        }
        else if(tokens[l].type == ')')
            return false;
        else l ++;
    }
    return true;
}




uint32_t eval(int p, int q) {
    if (p > q) {
        /* Bad expression */
        assert(0);
        return -1;
    }
    else if (p == q) {
        return atoi(tokens[p].str);
    }
    else if (check_parentheses(p, q) == true) {

        return eval(p + 1, q - 1);
    }

    else {
        int op = -1; 
        bool flag = false;
        for(int i = p ; i <= q ; i ++)
        {
            if(tokens[i].type == '(')
            {
                while(tokens[i].type != ')')
                    i ++;
            }
            if(!flag && tokens[i].type == OR){
                flag = true;
                op = max(op,i);
            }

            if(!flag && tokens[i].type == AND ){
				flag = true;
                op = max(op,i);
            }

            if(!flag && tokens[i].type == NOTEQ){
                flag = true;
                op = max(op,i);
            }

            if(!flag && tokens[i].type == EQ){
                flag = true;
                op = max(op,i);
            }
            if(!flag && tokens[i].type == LEQ){
                flag = true;
                op = max(op, i);
            }
            if(!flag && (tokens[i].type == '+' || tokens[i].type == '-')){
                flag = true;
                op = max(op, i);
            }
            if(!flag && (tokens[i].type == '*' || tokens[i].type == '/') ){
                op = max(op, i);
            }
        }

        int  op_type = tokens[op].type;


        uint32_t  val1 = eval(p, op - 1);
        uint32_t  val2 = eval(op + 1, q);

        switch (op_type) {
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
            case '/':
                if(val2 == 0){
		    printf("/0\n");
                    return 0;
                }
                return val1 / val2;
            case EQ:
                return val1 == val2;
            case NOTEQ:
                return val1 != val2;
            case OR:
                return val1 || val2;
            case AND:
                return val1 && val2;
            default:
                printf("error type.");
                assert(0);
        }
    }
}


int char_to_int(char s[]){
    int s_size = strlen(s);
    int res = 0 ;
    for(int i = 0 ; i < s_size ; i ++)
    {
	res += s[i] - '0';
	res *= 10;
    }
    res /= 10;
    return res;
}
void int_to_char(int x, char str[]){
    int len = strlen(str);
    memset(str, 0, len);
    int tmp_index = 0;
    int tmp_x = x;
    int x_size = 0, flag = 1;
    while(tmp_x){
	tmp_x /= 10;
	x_size ++;
	flag *= 10;
    }
    flag /= 10;
    while(x)
    {
	int a = x / flag; 
	x %= flag;
	flag /= 10;
	str[tmp_index ++] = a + '0';
    }
}

