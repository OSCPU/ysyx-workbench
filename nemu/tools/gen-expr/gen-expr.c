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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 256] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"#pragma GCC diagnostic ignored \"-Wdiv-by-zero\"\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

static int buf_index;
static int depth_cnt;
static int isDiv;

static void gen_num() {
  char str[10];
  uint32_t num;

  // number range from 1 ~ 9
  num = rand()%9+1;
  // trans unsigned to str
  sprintf(str, "%u", num);
  //copy to buffer
  for(int i=0;i<strlen(str);i++){
    buf[buf_index++] = str[i];
  }
}
static void gen(char c){
  buf[buf_index++] = c;
}
static void gen_nonzero_expr()  {
  gen('(');
  gen_num();
  gen('+');
  gen_num();
  gen(')');
  //gen('1');
}
static void gen_rand_op(){
  switch (rand()%4) {
    case 0: buf[buf_index++] = '+';break;
    case 1: buf[buf_index++] = '-';break;
    case 2: buf[buf_index++] = '*';break;
    default: buf[buf_index++] = '/';isDiv = 1;
  }
}
static void gen_rand_expr() {
  depth_cnt++;
  if(depth_cnt > 30){
    gen_num();
    return;
  }
  switch (rand()%3) {
    case 0:gen_num();break;
    case 1:gen('(');gen_rand_expr();gen(')');break;
    default:gen_rand_expr();gen_rand_op();
      if(isDiv){
        gen_nonzero_expr();
        isDiv = 0;
      }
      else gen_rand_expr();
  }
  if(depth_cnt<10) {
    gen_rand_op();
    if(isDiv){
      gen_nonzero_expr();
      isDiv = 0;
    }
    else gen_rand_expr();
  }
}

int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    buf_index=0;
    memset(buf,'\0',sizeof(buf));
    depth_cnt = 0;

    gen_rand_expr();
    //debug
    //strcpy(buf, "-1/2");

    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -O2 -Wall -Werror /tmp/.code.c -o /tmp/.expr");
    //printf("%d",ret);

    if (ret != 0) continue;

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
