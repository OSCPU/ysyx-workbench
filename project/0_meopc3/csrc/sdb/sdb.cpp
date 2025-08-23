//#include "sdb.h"
//#include <isa.h>
#include "readline/readline.h"
#include "readline/history.h"
#include "../include/cpu_exec.h"

static char* rl_gets() {
    static char *line_read = NULL;
  
    if (line_read) {
      free(line_read);
      line_read = NULL;
    }
  
    line_read = readline("(meopc) ");
  
    if (line_read && *line_read) {
      add_history(line_read);
    }
  
    return line_read;
}
int isa_reg_str2val(const char *s);
static int cmd_c(char *args);
static int cmd_q(char *args);
static int cmd_help(char *args);
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_x(char *args);
unsigned int str_to_hex(char *str);
static int cmd_token(char *args);
int expr(char *e);
void init_regex();

static struct {
    const char *name;
    const char *description;
    int (*handler) (char *);
  } cmd_table [] = {
    { "help", "Display information about all supported commands", cmd_help },
    { "c", "Continue the execution of the program", cmd_c },
    { "q", "Exit NEMU", cmd_q },
    { "si", "Execute by step", cmd_si },
    { "info", "Print", cmd_info},
    { "x", "Print Memory", cmd_x},
    { "token", "Make Token", cmd_token}
    // { "token_test", "Make Token Test", cmd_token_test}
    // { "watch", "Add a watchpoint", cmd_watch},
    // { "d", "delet a watchpoint", cmd_d},
    /* TODO: Add more commands */
  };

#define NR_CMD 7

static int cmd_token(char *args) {
	char *arg = strtok(NULL, "");
	printf("%s\n", arg);
	unsigned post = expr(arg);
	printf("0x%x\n", post);
	uint64_t post_re;
	post_re = post;
	printf("0x%08lx\n", post_re);
	return 0;
}

static int cmd_c(char *args) {
    cpu_exec(-1);
    return 0;
}

static int cmd_q(char *args) {
    //nemu_state.state = NEMU_QUIT;
    return -1;
}

static int cmd_help(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");//截取‘ ’之前的字符串
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

  static int cmd_si(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    if (arg == NULL) { //输入si 默认执行一次
          cpu_exec(1);
        return 0;
      }
    else{
      if(strspn(arg, "0123456789") == strlen(arg)){//看字符串中数字的个数是否等于字符串长度
        int i;
        i = atoi(arg);
        cpu_exec(i);
        return 0;
      }
      else{
        printf("Unlegal command: %s\n", arg);
        return 0;
      }
    }
  }

  static int cmd_info(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    if (arg == NULL) {
      printf("Error, not whole command\n");
    }
    else {
      if(strcmp(arg, "r") == 0)
        isa_reg_str2val(strtok(NULL, " "));
      else
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
  }

unsigned int str_to_hex(char *str){
	int len = strlen(str);
	int result = 0;
	int temp = 268435456;
	if(len != 10)
	{
		printf("%d\n" ,len);
		printf("Wrong addr, 0x80000000 by default\n");
		return 0x80000000;
	}
	if(str[0] != '0' || ((str[1] != 'x') && (str[1] != 'X')))
	{
		printf("Wrong addr, 0x80000000 by default\n");
		return 0x80000000;
	}
	else
	{
		for(int i = 2; i <= 9; i++)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				result = result + (str[i] - '0') * temp;
			}
			temp = temp / 16;
		}
		return result;
	}
}
static int cmd_x(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
    printf("Error, not whole command\n");
  }
  else
  {
  	int i;
  	uint8_t *data; 
  	i = atoi(arg);
  	unsigned int a;
  	arg = strtok(NULL, " ");
  	if (arg == NULL) {
    	printf("Error, not whole command %d\n", i);
  	}
  	else{
  		a = str_to_hex(arg);
		for(;i > 0;i--)
		{
        uint32_t result1 = 0;
  			for(int j1 = 0; j1 < 4; j1++){
          data = guest_to_host(a);
          result1 = result1 + (*data << (8 * (j1)));
          a ++;
        }
        printf("0x%x\n", result1);
  		}
  	}
  }
  return 0;
}

  void sdb_mainloop(int is_batch_mode) {
    init_regex();
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
      int i;
      for (i = 0; i < NR_CMD; i ++) {
        if (strcmp(cmd, cmd_table[i].name) == 0) {
          if (cmd_table[i].handler(args) < 0) { return; }
          break;
        }
      }
  
      if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    }
  }