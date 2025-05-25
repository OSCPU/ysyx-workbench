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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536];
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

int i = 0;

int choose(int rang){ //决定生成数字/运算符/括号
	int a = 0;
	a = (rand() + a) % rang;
	return a;
}

void gen_num(){
	char str_1[100] = {};
	int b = rand() % 100 + 1;
	sprintf(str_1, "0x%x", b);
	strcat(buf, str_1);
}

void gen(char c){
	char str_2[100] = {};
	str_2 [0] = c;
	str_2 [1] = '\0';
	strcat(buf, str_2);
}

void gen_rand_op(){
	char e[100] = {};
	int d = 0;
	d = rand() % 4;
	switch (d){
		case 0 :
		case 7 :  strcpy(e,"+"); break;
		case 1 : 
		case 8 : strcpy(e,"-"); break;
		case 2 : 
		case 9 : strcpy(e,"*"); break;
		case 3 : 
		case 10 : strcpy(e,"/"); break;
		case 4 : strcpy(e,"=="); break;
		case 5 : strcpy(e,"!="); break;
		case 6 : strcpy(e,"&&"); break;
		default:  break;
	}
	strcat(buf, e);
}

static void gen_rand_expr() {
	switch (choose(5)) {
    case 0:
	case 3: if(strlen(buf) < 100)
    			gen_num(); 
    		break;
    case 1:
	case 4: if(strlen(buf) < 100){
    			gen('('); gen_rand_expr(); gen(')');
    		}
    		break;
    default: if(strlen(buf) < 100){
    			gen_rand_expr(); gen_rand_op(); gen_rand_expr();
    		}
    		break;
  }
}

int main(int argc, char *argv[]) {
  buf[0] = '\0';
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    gen_rand_expr();
    if(strlen(buf) > 100)
    {
    	strcpy(buf, "0x1+0x1");
    }
	sprintf(code_buf, code_format, buf);
	FILE *fp = fopen("/tmp/.code.c", "w");
	assert(fp != NULL);
	fprintf(fp, "%s\n", code_buf);
	fclose(fp);
	int ret = system("gcc -Wall -Werror /tmp/.code.c -o /tmp/.expr");
	if (ret != 0) continue;
	fp = popen("/tmp/.expr", "r");
	assert(fp != NULL);
	int result;
	ret = fscanf(fp, "%d", &result);
	pclose(fp);
	printf("0x%x %s\n", result, buf);
	strcpy(buf, "");
  }
  return 0;
}
