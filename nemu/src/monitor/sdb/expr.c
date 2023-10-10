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


#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>

enum {
  TK_NOTYPE = 256, TK_EQ,Num,

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
  {"[0-9]+",Num},
  {"==", TK_EQ},        // equal
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
	  case Num:
	  	tokens[nr_token].type=rules[i].token_type;
		strncpy(tokens[nr_token++].str,substr_start,substr_len);
		tokens[nr_token].str[substr_len] ='\0';
		break;
	  case TK_NOTYPE :break;

          default: TODO();
        }
          if(nr_token==65536)
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
  int num = eval(0,nr_token-1);
  return num;
}



bool check_parentheses(int p, int q)
{
	int count,a,flat1=0,flat2=0;
	if(tokens[p].type=='(')
	count=1;
	else if(tokens[p].type==Num)
	count=0;
	else if(tokens[p].type=='-')
	count=0;
	else
	{
	//Assert(0,"wrong expression");
	printf("wrong expression\n");
	assert(0);
	}
	 

	a=p+1;
	while(q>a)
	{
		if(flat1==1)
		//the ')' > '('
		break;
		else if(tokens[a].type=='(')
		count++;
		else if(tokens[a].type==')')
		{
			count--;
			if(count<0)
			flat1=1; //')' > '('
			else if(count==0)	
			flat2=1; // Not belong "(" <exper> ")"
		}
		a++;
	}
	


	if(flat1==1)
	{
		printf("flase,bad expressioan ')' > '('\n  ");
		return 0;
	}
	else if(tokens[q].type==')')
	{
		if(count-1!=0)
		{
			printf("flase,bad expression\n");
			return 0;	
		}		
		else
		{
			if(flat2==1||tokens[p].type==Num)
			{
				printf("Not belong '(' <exper> ')'\n ");
				return 0;
			}
			else if(flat2==0)
			{
				printf("true\n");
				return 1;
			}
		}
	}
	else if(tokens[q].type==Num)
	{
		if(count!=0)	
		{
			printf("bad expression\n");
			return 0;
		}
		else 
		{
			printf("Not belong '(' <exper> ')'\n ");
			return 0;
		}
	}
	else 
	{
		//Assert(0,"Wrong expression\n");
		printf("wrong expression\n");
	 	assert(0);
	}
	return 0;
}




uint32_t eval(int p, int q)
{
	if(p>q)
	{
		//Assert(0,"Form error the p>q");
		printf("Form error the p>q\n");
		assert(0);
		return -1;
	}
	else if(p==q)
	{
		return atoi(tokens[p].str);
	}
	else if (check_parentheses(p,q)==true)
	{
		return eval(p+1,q-1);
	}


	else
	{
		int op,val1,val2;
		op=-1;
		int count,a,ne,flat_ne_right,flat_ne_laft,y,x;
		count=0;
		flat_ne_right=0;
		flat_ne_laft=0;
		ne=0;//负数
		x=0;//记录负数时主运算符位置
		y=0;
		if(tokens[p].type=='(')
		count=1;
		else if(tokens[p].type==Num)
		count=0;
		else if(tokens[p].type=='-')
		{
		y=p+2;
		count=0;
		}

		a=p+1;
		while(q>a)
		{
		if(tokens[a].type=='(')
	        count++;
		else if(tokens[a].type==')')
		count--;
		else if(count==0)
		{
			if(op==-1&&(tokens[a].type=='+'||tokens[a].type=='-'||tokens[a].type=='/'||tokens[a].type=='*'))
			{
		        	op=a;		
				if(tokens[a+1].type=='-')
				ne=1;
				
			}
			else if(op!=-1&&(tokens[op].type=='*'||tokens[op].type=='/'))
			{
				if(ne==0&&(tokens[a].type=='+'||tokens[a].type=='-'||tokens[a].type=='/'||tokens[a].type=='*'))
			      {
				op=a;
				if(tokens[a+1].type=='-')
				ne=1;
			      }	
			      	else if(ne==1)
				{
					ne=0;	
					x=op;
				}
			}
			else if(op!=-1&&(tokens[op].type=='+'||tokens[op].type=='-'))
			{
				if(ne==0&&(tokens[a].type=='+'||tokens[a].type=='-'))
				{
					op=a;
					if(tokens[a+1].type=='-')	
					ne=1;
				}
				else if(ne==1)
				{
					ne=0;
					x=op;
				}
			}
		}
		a++;
		}


		if(op==x)
			flat_ne_right=1;
		if(op==y)
			flat_ne_laft=1;


		if(flat_ne_laft==1)
		{
		flat_ne_laft=0;
		val1 =-1*eval(p+1,op-1);
		}
		else val1 =eval(p,op-1);
		if(flat_ne_right==1)
		{
		  flat_ne_right=0;
		  val2 =-1*eval(op+2,q);
		}
		else val2=eval(op+1,q);


		switch(tokens[op].type)
		{
			case '+':return val1 + val2;
			case '-':return val1 - val2;
			case '*':return val1 * val2;
			case '/':return val1 / val2;
			default:assert(0);
		}
	   }
}
