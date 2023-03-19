#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/vaddr.h>
static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
word_t expr(char *e, bool *success);


/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
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
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args) {
  int s;
	if(args==NULL) s=1;
  else {
    sscanf(args, "%d", &s);
  } 
  cpu_exec(s);
	return 1;
}

static int cmd_info(char *args) {
  char c;
  //char *reg=strtok(args, " ");
  sscanf(args,"%c",&c);
  if(c=='r')
    isa_reg_display();
  else if(c=='w') 
    dispaly_allwatchpoint();
  return 1;
}

static int cmd_p(char *args) {
  bool  success=true;
  if(args)
    printf("The ans is %lu\n",expr(args,&success));
  return 1;
}

static int cmd_x(char *args) {
  if (args==NULL)
  {
    printf("The form of command x dont match.");
    return 1;
  }
  int num,address;
  sscanf(args,"%d 0x%x",&num,&address);
  for(int i=0;i<num;i++){
    printf("0x%x 0x%lx\n",address+4*i,vaddr_read(address+4*i,4));
  }
  return 1;
}

static int cmd_w(char *args) {
  bool success = true;
  new_wp(args,&success);
  return 1;
}
static int cmd_d(char *args){
  if(args==NULL)
    free_wp();
  else {
    int i;
    sscanf(args,"%d",&i);
    free_wpn(i);
  }
  return 1;
}
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "The program execute N instructions in a single step and then pause execution,default 1",cmd_si },
  { "info", "Display the information of the program \n info r register \n info w monitoring point",cmd_info },
  { "p", "p EXPR \nFind the value of the expression EXPR",cmd_p},
  { "x", "x N EXPR \n scan memory make EXPR as the starting memory address to display consecutive 4-bytes in hex form",cmd_x },
  { "w", "w EXPR \n when the value of EXPR change,hint program",cmd_w},
  /* TODO: Add more commands */
  { "d","delete a watchpint",cmd_d}
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

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
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return ; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
