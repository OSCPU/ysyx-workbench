#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {'\0'};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
for(int i=0;i<65536;i++)
  buf[i]='\0';
static void gen_num(){
  char *op=(char *)malloc(sizeof(char)*32);
  memset(op,'\0',32);
  if(rand()%2){
    sprintf(op, "%d",rand()%(2<<5)+1);
    Log("%d\n",rand()%(2<<5)+1);
  }
    
  else{
    sprintf(op, "0x%d",rand()%(2<<5)+1);
    Log("%x\n",rand()%(2<<5)+1);
    }
    strcat(buf,op);

}
static void gen_rand_op(){
  char *ops=(char *)malloc(sizeof(char)*3);
  memset(ops,'\0',3);
  switch(rand()%11){
  case 0: ops[0]='!';
          break;
  case 1: ops[0]='+';
          break;
  case 2: ops[0]='-';
          break;
  case 3: ops[0]='*';
          break;
  case 4: ops[0]='/';
          break;
  case 5: ops[0]='!';
          ops[1]='=';
          break;
  case 6: ops[0]='=';
          ops[1]='=';
          break;
  case 7: ops[0]='&';
          ops[1]='&';
          break;
  case 8: ops[0]='|';
          ops[1]='|';
          break;
  case 9: ops[0]='>';
          ops[1]='>';
          break;
  case 10:ops[0]='<';
          ops[1]='<';
          break; 
  }
  strcat(buf,ops);
}
static void gen(char k){
  char *op=(char *)malloc(sizeof(char)*2);
  memset(op,'\0',2);
  op[0]=k;
  strcat(buf,op);
} 
static void gen_space(){
  char *space=(char *)malloc(sizeof(char)*2);
  memset(space,'\0',32);
  for(int i=0;i<rand()%5;i++)
    strcat(buf,space);
}
static void gen_rand_expr() {

  switch (rand()%3) {
    case 0: gen_num(); gen_space();break;
    case 1: gen('('); gen_space();gen_rand_expr(); gen(')');gen_space(); break;
    default: gen_rand_expr();gen_space(); gen_rand_op(); gen_space();gen_rand_expr(); break;
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
    gen_rand_expr();

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
    int re=fscanf(fp, "%d", &result);
    if(re==1)
      pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}
