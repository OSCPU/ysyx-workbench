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

#include <common.h>
#include <string.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <isa.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <readline/readline.h>
#include <readline/history.h>

char buf[65536]={};

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();

word_t expr(char *e,bool *success);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
  /*
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif
*/

  /* Start engine. */
  //engine_start();
  for(int i=0;i <1000;i++)
  {
  FILE *fp;
  unsigned int result;
  fp =fopen("./tools/gen-expr/input","r");
  assert(fp!=NULL);
  int ret=fscanf(fp,"%u %[^\n]\n",&result,buf);
  if(ret==0) continue;
  fclose(fp);
  bool success=true;
  uint32_t num=expr(buf,&success);
  if(success==false)
  {
  printf("error\n");
  printf("%d\n",i);
  assert(0);
  }
  else
  {
  if(num==result)
  printf("%d\n",i);
  else
  printf("worng\n");
  } 
  memset(buf,'\0',sizeof(buf));
  }
	
  return is_exit_status_bad();
}
