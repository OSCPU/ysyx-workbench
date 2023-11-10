#include <common.h>
#include <isa.h>
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <sys/types.h>

static int is_batch_mode = false;
void sdb_set_batch_mode() { is_batch_mode = true; }

void init_regex();
void init_wp_pool();

void cpu_exec(uint64_t n);
word_t expr(char *s, bool *success);
void isa_reg_display();
//watchpoint
typedef struct watchpoint WP;
void new_wp(char e[]);
void free_wp(WP* wp);
void print_wp_info();
void delete_wp(int NO);
//ftrace
#ifdef CONFIG_FTRACE
void ftrace();
void print_symbol_table();
#endif /* ifdef CONFIG_TRACE */

/* We use the `readline' library to provide more flexibility to read from stdin.
 */
static char *rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

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
  npc_state.state = NPC_QUIT;
  return -1; 
}

static int cmd_si(char *args) {
  /*extract the first argument */
  char *arg = strtok(NULL, " ");

  if (arg == NULL) cpu_exec(1);
  else cpu_exec(atoi(arg));

  return 0;
}

static int cmd_info(char *args) {
  /*extract the first argument*/
  char *arg = strtok(NULL, " ");

  if(*arg == 'r'){
    isa_reg_display();
  }
  else if(*arg == 'w'){
    print_wp_info();
  }
  else{
    printf("Usage:info r or info w\n");
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

  for(int i=0; i < n; i++){
    //printf("0x%8x:\t0x%08x\n",res+i*4,pmem_read(res+i*4, 4));
    printf(FMT_PADDR ":\t" FMT_WORD "\n",res+i*4, pmem_read(res+i*4, 4));
  }

  return 0;
}

static int cmd_p(char *args) {
  bool success;
  uint32_t res;

  res = expr(args, &success);

  if(strcmp(args,"pc")==0){
    printf("%#x\n", res);
  }
  else {
    printf("%#x\t%u\n", res, res);
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
#ifdef CONFIG_FTRACE
static int cmd_ftrace(char *args) {
  if(args == NULL) {
    ftrace();
  }else if(strcmp(args, "list") == 0){
    print_symbol_table();
  } else {
    printf("Usage: ftrace or ftrace list");
  }
  return 0;
}
#endif /* ifdef CONFIG_TRACE */

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display information about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NPC", cmd_q},
    {"si", "Cpu executes for n cycles", cmd_si},
    {"info", "Show information of regfile values or watchpoint", cmd_info},
    {"x", "Display memory",cmd_x},
    {"p", "Expressions evaluation",cmd_p},
    {"w", "Add watchpoint",cmd_w},
    {"d", "Delete watchpoint",cmd_d},
  #ifdef CONFIG_FTRACE
    {"ftrace", "function trace",cmd_ftrace},
  #endif /* ifdef CONFIG_FTRACE */
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
