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
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <readline/readline.h>
#include <readline/history.h>
/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <math.h>

enum {
  TK_NOTYPE = 256, TK_EQ, 

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
  {"\\-", '-'}, 
  {"\\*", '*'},         
  {"\\/", '/'},
  {"==", '='},
  {"!=", '!'}, 
  {"\\$[0-9a-z$]+", '$'}, 
  {"&&", '&'},       
  {"\\(", '('},         
  {"\\)", ')'},
  {"0[xX][0-9A-Fa-f]+", '0'},      //数字 十六进制形式 
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
  char str[128];
} Token;

static Token tokens[128] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;
int length = 0;
static bool make_token(char *e) {
  int position = 0;
  int i;
  
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) { 
    	int k = 0;
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
      	
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
        switch (rules[i].token_type) {
        	case'+': 
        		tokens[length].type= '+';
        		strcpy(tokens[length].str , "+");
        		length = length + 1;
        		break;
        	case'0': 
				for(k = 0; k < substr_len; k++){
					tokens[length].str[k] = substr_start[k];
				}
				tokens[length].str[k] = '\0';
        		tokens[length].type= 'N';
        		length = length + 1;
        		break;
        	case'-': 
        		tokens[length].type= '-';
        		strcpy(tokens[length].str , "-");
        		length = length + 1;
        		break;
        	case'*': 
        		if((length >= 1) && (tokens[length-1].type == ')' || tokens[length-1].type == 'N')){  //乘号
				tokens[length].type= '*';
				strcpy(tokens[length].str , "*");
				length = length + 1;
			}
			else //取指
			{
				tokens[length].type= 'x';
				strcpy(tokens[length].str , "*");
				length = length + 1;
			}
        		break;
        	case'/': 
        		tokens[length].type= '/';
        		strcpy(tokens[length].str , "/");
        		length = length + 1;
        		break;
        	case'=': 
        		tokens[length].type= '=';
        		strcpy(tokens[length].str , "==");
        		length = length + 1;
        		break;
        	case'!': 
        		tokens[length].type= '!';
        		strcpy(tokens[length].str , "!=");
        		length = length + 1;
        		break;
        	case'&': 
        		tokens[length].type= '&';
        		strcpy(tokens[length].str , "&&");
        		length = length + 1;
        		break;
        	case'(': 
        		tokens[length].type= '(';
        		strcpy(tokens[length].str , "(");
        		length = length + 1;
        		break;
        	case')': 
        		tokens[length].type= ')';
        		strcpy(tokens[length].str , ")");
        		length = length + 1;
        		break;
        	case'$': //寄存器把里边的值弄出来，视为数字
        		char str_reg[100];
        		for(k = 1; k < substr_len; k++){
					str_reg[k-1] = substr_start[k];
					//printf("???%c???\n",str_reg[k-1]);
				}
				//printf("!!!!%s  %ld\n", str_reg, strlen(str_reg));
				int reg_data = isa_reg_str2val(str_reg, false);//埋个雷
				sprintf(tokens[length].str, "0x%x", reg_data);
				tokens[length].type= 'N';
        		length = length + 1;
        		break;
        	default:
        		break;
        }
        //printf("%d     %c    %s\n", length - 1, tokens[length-1].type, tokens[length-1].str);
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

int check_whole(int p, int q, int flag){	//判断表达式的合法性
	int check_i;
	int count = 0;
	for(check_i = p; check_i <= q; check_i++){
		switch (tokens[check_i].type) {
			case '(':
				count ++;
				break;
			case ')':
				count --;
				break;
			default:
				break;
			}
			if(count < 0 && flag == 0){
				printf("Wrong expr\n");
				return 0;
			}
			else if(count < 0 && flag == 1){ //并不一定是错的表达式
				return 0;
			}
		}
	if(count > 0 && flag == 0){
		printf("%d---Wrong expr\n", count);
		return 0;
	}
	else if(count > 0 && flag == 1){
		return 0;
	}
	else{
		return 1;
	}
}

int main_find(int p, int q){
	int flag_par = 0; //确保运算符号在括号之外
	int find_i;
	int postion_0 = 0;
	int postion_1 = 0;
	int postion_2 = 0;
	int postion_3 = 0;
	int postion_4 = 0;
	if(check_whole(p, q, 0) == 1){
		for(find_i = q; find_i >= p; find_i--){
			switch (tokens[find_i].type) {
			case '(':
				flag_par --;
				break;
			case ')':
				flag_par ++;
				break;
			case '=': case '!':
				if(flag_par == 0 && postion_1 == 0)
					postion_1 = find_i;
				break;
			case '&':
				if(flag_par == 0 && postion_0 == 0)
					postion_0 = find_i;
				break;
			case '+': case '-':
				if(flag_par == 0 && postion_2 == 0)
					postion_2 = find_i;
				break;
			case '*': case '/':
				if(flag_par == 0 && postion_3 == 0)
					postion_3 = find_i;
				break;	
			case 'x': //最高级别运算符
				if(flag_par == 0 && postion_4 == 0)
					postion_4 = find_i;
				break;	
			default:
				break;
			}
		}
		if(postion_0 != 0)
			return postion_0;
		else if(postion_1 != 0)
			return postion_1;
		else if(postion_2 != 0)
			return postion_2;
		else if(postion_3 != 0)
			return postion_3;
		else if(postion_4 != 0)
			return postion_4;
		else
			return 0;
	}
	else
		assert(0);
}

int check_parentheses(int p, int q){ //判断表达式两端是否为一对括号
	if(check_whole(p + 1, q - 1, 1) == 1 && tokens[p].type == '(' && tokens[q].type == ')'){
		return 1;
	}
	else
		return 0;
}

unsigned int strtohex(char *str_x){ //字符串转16进制
	unsigned int result = 0;
	int len = strlen(str_x);
	//printf("%d\n", len);
	for(int i = len - 1; i >= 2; i --){
		if(str_x[i] >= '0' && str_x[i] <= '9')
			result = result + (str_x[i] - '0')*pow(16, len - i - 1);
		else if(str_x[i] >= 'a' && str_x[i] <= 'f')
			result = result + (str_x[i] - 'a' + 10)*pow(16, len - i - 1);
		else if(str_x[i] >= 'A' && str_x[i] <= 'F')
			result = result + (str_x[i] - 'A' + 10)*pow(16, len - i - 1);
	}
	return result;
}

int  eval(int p, int q) {
	int result;
	int op;
	int val1, val2;
	if (p > q) {
		assert(0);
	}
	else if (p == q) {
		if(tokens[p].type == 'N'){
			result = strtohex(tokens[p].str);
			//printf("------%s = 0x%d------\n",tokens[p].str, result);
			return result;
		}
		else{
			printf("Wrong expr\n");
			assert(0);
		}
	}
	else if (check_parentheses(p, q) == true) {
		return eval(p + 1, q - 1);
	}
	else {
		op = main_find(p, q);
		if(op != p){ 
			val1 = eval(p, op - 1);
			val2 = eval(op + 1, q);

			switch (tokens[op].type) {
				case '+': printf("%d %c %d = %d\n", val1, tokens[op].type, val2, val1 + val2); return val1 + val2;
				case '-': printf("%d %c %d = %d\n", val1, tokens[op].type, val2, val1 - val2); return val1 - val2;
				case '*': printf("%d %c %d = %d\n", val1, tokens[op].type, val2, val1 * val2); return val1 * val2;
				case '/': printf("%d %c %d = %d\n", val1, tokens[op].type, val2, val1 / val2); return val1 / val2;
				case '=': 
					if(val1 == val2)
						{printf("%d == %d\n", val1, val2); return 1;}
					else
						{printf("%d != %d\n", val1, val2); return 0;}
				case '!': 
					if(val1 == val2)
						{printf("%d == %d\n", val1, val2); return 0;}
					else
						{printf("%d != %d\n", val1, val2); return 1;}
				case '&': 
					if(val1 != 0 && val2 != 0)
						{return 1;}
					else
						{return 0;}
				default: assert(0);
			}
		}
		else {//*解指针需特殊考虑
			if(tokens[op].type == 'x'){
				val2 = eval(op + 1, q);
				uint8_t *dataz;
				dataz = guest_to_host(val2);
				//printf("*0x%08x = 0x%08x\n",val2, *dataz);
				return *dataz;
			}
			else
				assert(0);
		}
	}
}

int expr(char *e, bool *success) {
  length = 0;
  if (!make_token(e)) {
	*success = false;
    return 0;
  }
  int post;

  post = eval(0, length-1);

  return post;
}
