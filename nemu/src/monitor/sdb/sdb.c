/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "sdb.h"
#include "memory/paddr.h"
#include <cpu/cpu.h>
#include <isa.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <sys/types.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

typedef struct watchpoint WP;
void new_wp(char e[]);
void free_wp(WP* wp);
void show_info_wp();
void delete_wp(int NO);

/* We use the `readline' library to provide more flexibility to read from stdin.
 */
static char *rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) { 
  //return -1; 
  exit(0);
}

static int cmd_si(char *args) {
  /*extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL)
    cpu_exec(1);
  else
    cpu_exec(atoi(arg));

  return 0;
}

static int cmd_info(char *args) {
  /*extract the first argument*/
  char *arg = strtok(NULL, " ");

  if (arg == NULL)
    printf("info arguments error!\nUsage:info r or info w\n");
  else if(*arg == 'r'){
    isa_reg_display();
  }
  else if(*arg == 'w'){
    show_info_wp();
  }

  return 0;
}

static int cmd_x(char *args) {
  /*extract the first argument*/
  char *arg1 = strtok(NULL, " ");
  /*extract the second argument*/
  char *arg2 = strtok(NULL, " ");

  int n = atoi(arg1);
  bool success;
  uint32_t res = expr(arg2, &success);
  //char *endPtr;
  //uint32_t expr = strtol(arg2,&endPtr,16);

  printf("Addr\t\tValue\n");
  for(int i=0; i < n; i++){
    printf("0x%8x:\t0x%08x\n",res+i*4,paddr_read(res+i*4, 4));
  }

  return 0;
}

static int cmd_p(char *args) {
  bool success;
  uint32_t res;

  res = expr(args, &success);
  if(strcmp(args,"$pc")==0){
    printf("0x%x\n", res);
  }
  else {
    printf("%u\n", res);
  }

  return 0;
}

static int cmd_w(char *args){
  new_wp(args);

  return 0;
}

static int cmd_d(char *args){
  int index;

  index = atoi(args);
  delete_wp(index);

  return 0;
}

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},

    /* TODO: Add more commands */
    {"si", "Cpu executes for n cycles", cmd_si},
    {"info", "Show information of regfile values or watchpoint", cmd_info},
    {"x", "Scan memory for n times",cmd_x},
    {"p", "Expressions evaluation",cmd_p},
    {"w", "Add watchpoint",cmd_w},
    {"d", "Delete watchpoint",cmd_d},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() { is_batch_mode = true; }

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) {
      continue;
    }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {
          return;
        }
        break;
      }
    }

    if (i == NR_CMD) {
      printf("Unknown command '%s'\n", cmd);
    }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
