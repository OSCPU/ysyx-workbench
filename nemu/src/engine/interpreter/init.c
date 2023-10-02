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
//#define EXPR_TEST 
#include <cpu/cpu.h>

void sdb_mainloop();
void expr_test();
word_t expr(char *e, bool *success);

void engine_start() {
#ifdef CONFIG_TARGET_AM
  cpu_exec(-1);
#else
  /* Receive commands from user. */
  sdb_mainloop();
#endif
#ifdef EXPR_TEST
  expr_test();
#endif /* ifdef EXPR_TEST */
}

void expr_test() {
  uint32_t res_func;
  uint32_t res_gcc;
  FILE *file;
  char line[1024];

  // 打开文件
  file = fopen("/home/wophere/ysyx-workbench/nemu/tools/gen-expr/input", "r"); 
  if (file == NULL) { 
    perror("无法打开文件");
  }

  // 逐行读取文件内容
  while (fgets(line, sizeof(line), file) != NULL) {
    //printf("读取的行内容：%s", line);
    char *res_str = strtok(line," ");
    char *e = strtok(NULL," ");
    for(int i=0;i<strlen(e);i++) {
      if(e[i] == '\n' ) {
        e[i] = '\0';
      }
    }

    res_gcc = atoi(res_str);
    res_func = expr(e,NULL);

    if(res_gcc != res_func) {
      printf("%u\t%u\n",res_gcc,res_func);
      assert(0);
    }
  }

  // 关闭文件
  fclose(file);
  printf("expr test pass\n");
}


