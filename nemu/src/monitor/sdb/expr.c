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

#include "memory/paddr.h"
#include <assert.h>
#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <stdbool.h>

enum {
  TK_NOTYPE = 256, TK_EQ,

  /* TODO: Add more token types */
  TK_NUM,TK_REG,TK_HEX,TK_NOTEQ,TK_AND,TK_OR,TK_DEREF,TK_MIN,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {"( +|u)", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\-", '-'},         // subtract
  {"\\*", '*'},         // multiply
  {"/", '/'},           // divider
  {"\\(", '('},         // left parantheses
  {"\\)", ')'},         // right parantheses
  {"\\$([0-9]+|pc)", TK_REG},  //reg
  {"(0x|0X)[0-9a-fA-F]+",TK_HEX},  //hex
  {"==", TK_EQ},        // equal
  {"!=", TK_NOTEQ},     // not equal
  {"&&", TK_AND},       // and
  {"\\|\\|", TK_OR},    // or 
  {"[0-9]+", TK_NUM},   // number
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

static Token tokens[128] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;


bool check_parentheses(int p ,int q){
  int i;
  int pstack;
  int stack[128];

  //init stack pointer
  pstack = 0;
  //traverse tokens
  for(i=p;i<=q;i++){
    // push
    if(tokens[i].type == '('){
      stack[pstack] = (i==p) ? 0 : 1;
      pstack++;
    }
    //pop
    else if(tokens[i].type == ')'){
      pstack--;
      if(pstack<0) {
        assert(0);
      }
    }
  }

  if(pstack != 0) {
    assert(0);
  }
  else if(stack[pstack] == 0 && tokens[p].type == '(' && tokens[q].type == ')') {
    return true;
  }
  else {
    return false;
  }
}

int position_of_mainop(int p,int q){
  int i;
  int priority[128];
  int op_index = 0;
  int op[128];
  int max_index;
  int isInBracket = 0;
  int bracket_cnt = 0;

  for(i=p;i<=q;i++){
    // check isInBracket
    if(tokens[i].type == '(') {
      bracket_cnt++;
    }
    else if(tokens[i].type == ')') {
      bracket_cnt--;
    }
    isInBracket = bracket_cnt > 0;
    // show priority
    if(isInBracket && (tokens[i].type == '+'||tokens[i].type == '-'||\
                       tokens[i].type == '*'||tokens[i].type == '/'||\
                       tokens[i].type == TK_OR||tokens[i].type == TK_AND||\
                       tokens[i].type == TK_EQ||tokens[i].type == TK_NOTEQ)){
      op[op_index] = i;
      priority[op_index] = 1;
      op_index++;
    }
    else if(tokens[i].type == '*' || tokens[i].type == '/'){
      op[op_index] = i;
      priority[op_index] = 2;
      op_index++;
    }
    else if(tokens[i].type == '+' || tokens[i].type == '-'){
      op[op_index] = i;
      priority[op_index] = 3;
      op_index++;
    }
    else if(tokens[i].type == TK_AND){
      op[op_index] = i;
      priority[op_index] = 4;
      op_index++;
    }
    else if(tokens[i].type == TK_OR){
      op[op_index] = i;
      priority[op_index] = 5;
      op_index++;
    }
    else if(tokens[i].type == TK_EQ || tokens[i].type == TK_NOTEQ ){
      op[op_index] = i;
      priority[op_index] = 6;
      op_index++;
    }
  }
  // find the main op index
  max_index = 0;
  for(i=0;i< op_index;i++){
    if(priority[i] >= priority[max_index]) {
      max_index = i;
    }
  }
  return op[max_index];
}

uint32_t eval(int p, int q)
{
  int op;
  bool success;
  uint32_t val1,val2,res = 0;

  if(p > q){
    assert(0);
  }
  else if(p==q){
    switch (tokens[p].type) {
      case TK_NUM:
        res = atoi(tokens[p].str);
        break;
      case TK_HEX:
        sscanf(tokens[p].str, "%x", &res);
        break; 
      case TK_REG:
        res = isa_reg_str2val(tokens[p].str, &success);
        break;
      case TK_DEREF:
        res = atoi(tokens[p].str);
        break;
      case TK_MIN:
        res = -atoi(tokens[p].str);
        break;
    }
    return res;
  }
  else if(check_parentheses(p,q)){
    return eval(p+1,q-1);
  }
  else{
    op = position_of_mainop(p,q);
    val1 = eval(p,op-1);
    val2 = eval(op+1,q);

    switch (tokens[op].type) {
      case '+': return val1 + val2;
      case '-': return val1 - val2;
      case '*': return val1 * val2;
      case '/':
        if(val2==0){
          Log("Warning:divided by zero");
          return -1;
        }
        else return val1 / val2;
      case TK_AND:   return val1 && val2;
      case TK_OR:    return val1 || val2;
      case TK_EQ:    return val1 == val2;
      case TK_NOTEQ: return val1 != val2;
      default:printf("undefined operation");assert(0);
    }
  }
}

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

        //Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            //i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        int j;
        switch (rules[i].token_type) {
          case TK_NUM:
            tokens[nr_token].type = TK_NUM;
            for(j=0;j<substr_len;j++){
              tokens[nr_token].str[j] = substr_start[j];
            }
            tokens[nr_token].str[j] = '\0';
            nr_token++;
            break;
          case '+':
            tokens[nr_token].type = '+';
            nr_token++;
            break;
          case '-':
            tokens[nr_token].type = '-';
            nr_token++;
            break;
          case '*':
            tokens[nr_token].type = '*';
            nr_token++;
            break;
          case '/':
            tokens[nr_token].type = '/';
            nr_token++;
            break;
          case '(':
            tokens[nr_token].type = '(';
            nr_token++;
            break;
          case ')':
            tokens[nr_token].type = ')';
            nr_token++;
            break;
          case TK_HEX:
            tokens[nr_token].type = TK_HEX;
            for(j=2;j<substr_len;j++){
              tokens[nr_token].str[j-2] = substr_start[j];
            }
            tokens[nr_token].str[j-2] = '\0';
            nr_token++;
            break;
          case TK_REG:
            tokens[nr_token].type = TK_REG;
            for(j=1;j<substr_len;j++){
              tokens[nr_token].str[j-1] = substr_start[j];
            }
            tokens[nr_token].str[j-1] = '\0';
            nr_token++;
            break;
          case TK_EQ:
            tokens[nr_token].type = TK_EQ;
            nr_token++;
            break;
          case TK_NOTEQ:
            tokens[nr_token].type = TK_NOTEQ;
            nr_token++;
            break;
          case TK_AND:
            tokens[nr_token].type = TK_AND;
            nr_token++;
            break;
          case TK_OR:
            tokens[nr_token].type = TK_OR;
            nr_token++;
            break;
          case TK_NOTYPE:
            break;
          default: TODO();
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
  uint32_t mem_addr,mem_value;
  int right_parentheses_index = 0;

  for (int i = 0; i < nr_token; i ++) {
    if (tokens[i].type == '*' && (i == 0 || tokens[i - 1].type == '+'||\
                                            tokens[i - 1].type == '-'||\
                                            tokens[i - 1].type == '*'||\
                                            tokens[i - 1].type == '/'||\
                                            tokens[i - 1].type == TK_EQ||\
                                            tokens[i - 1].type == TK_NOTEQ||\
                                            tokens[i - 1].type == TK_AND||\
                                            tokens[i - 1].type == TK_OR)) {
      tokens[i].type = TK_DEREF;    
      // caculate mem_addr
      switch (tokens[i+1].type) {
        case TK_REG: mem_addr = isa_reg_str2val(tokens[i+1].str, success); break;
        case TK_HEX: mem_addr = (uint32_t)strtol(tokens[i+1].str,NULL,16); break;
        case '(':
          for(int ii = i+1; ii < nr_token; ii++) {
            if(tokens[ii].type == ')') right_parentheses_index = ii;
          }
          mem_addr = eval(i+1, right_parentheses_index);
          break;
        default: assert(0);
      }
      // caculate mem_value
      mem_value = paddr_read(mem_addr, 4);
      sprintf(tokens[i].str, "%u", mem_value);
      // shift tokens
      switch (tokens[i+1].type) {
        case TK_HEX:case TK_REG:
          for(int j=i+1; j+1 < nr_token; j++){
            tokens[j] = tokens[j+1];
          }
          nr_token--;
          break;
        case '(':
          for(int j=i+1,k=right_parentheses_index; k+1 < nr_token; j++,k++){
            tokens[j] = tokens[k+1];
          }
          nr_token = nr_token - (right_parentheses_index - i);
          break;
        default: assert(0);
      }
    }
    if (tokens[i].type == '-' && (i == 0 || tokens[i - 1].type == '+'||\
                                            tokens[i - 1].type == '-'||\
                                            tokens[i - 1].type == '*'||\
                                            tokens[i - 1].type == '/'||\
                                            tokens[i - 1].type == TK_EQ||\
                                            tokens[i - 1].type == TK_NOTEQ||\
                                            tokens[i - 1].type == TK_AND||\
                                            tokens[i - 1].type == TK_OR)) {
      if(tokens[i+1].type == '-') {
        tokens[i].type = TK_NUM;
        strcpy(tokens[i].str, tokens[i+2].str);
        for(int j=i+1; j+2 < nr_token; j++){
          tokens[j] = tokens[j+2];
        }
        nr_token = nr_token - 2;
      }
      else {
        tokens[i].type = TK_MIN;
        strcpy(tokens[i].str, tokens[i+1].str);
        for(int j=i+1; j+1 < nr_token; j++){
          tokens[j] = tokens[j+1];
        }
        nr_token--;
      }
    }
  }
  uint32_t res;
  res = eval(0, nr_token-1);

  return res;
}

