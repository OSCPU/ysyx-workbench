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

void gen_rand_expr();
uint32_t choose(uint32_t n);
void gen_num();
void gen(char c);
void gen_rand_op();


// this should be enough
static char buf[65536] ={};
int count=0;
static char code_buf[65536] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

int main(int argc, char *argv[]) {
  int flat=0;
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) {
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
    memset(buf,'\0',sizeof(buf));
    count=0;
    memset(code_buf,'\0',sizeof(code_buf));
    //gen_rand_expr();
    if(flat==0)
    strcpy(buf,"55/(2-2)");
    else 
    strcpy(buf,"55/1");
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) continue; 
    
   

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;
    ret = fscanf(fp, "%d", &result);
    pclose(fp);
    printf("%d\n",ret);

    if(ret==1) 
    printf("%u %s\n", result, buf);
    else
    {
    i=i-1;
    flat=1;
    }
  }
  return 0;
}


uint32_t choose(uint32_t n)
{
	int flat = rand()%n;
	return flat;
}
void gen_num()
{
	int num =rand()%100+1;
	int num1=num;
	int a=1;
	while(num1)
	{
	num1=num1/10;
	a=a*10;
	}
	a=a/10;
	while(num)
	{
	char c=num/a + '0';
	num =num%a;	
 	a=a/10;
	buf[count]=c;
	count=count+1;
	}
}

void gen(char c)
{
	int a;
	if(c==' ')
	{
	 a=rand()%2;
	 for(int i=0;i<=a;i++)
	 {
	 	buf[count]=c;
		count=count+1;
	 }
	}
	else
	{
	buf[count]=c;
	count=count+1;
	}
}

void gen_rand_op()
{
	char op[4]={'+','-','*','/'};
	int rand_op=rand()%4;
	buf[count]=op[rand_op];
	count=count+1;
}

void gen_rand_expr()
{
	int a;
	if(count>55535)
        a=0;	
	else
	a=choose(3);
	switch(a)
	{
	case 0:
		gen(' ');
		gen_num();
		gen(' ');
		break;
	case 1:
		gen(' ');
		gen('(');
		gen(' ');
		gen_rand_expr();
		gen(' ');
		gen(')');
		gen(' ');
		break;
	default:
		gen_rand_expr();
		gen(' ');
		gen_rand_op();
		gen(' ');
		gen_rand_expr();
		break;
	}
}
