#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/paddr.h> // mem访问接口
#include <utils.h>
static int is_batch_mode = false;

// 初始化正则表达式
void init_regex();
// 初始化监视点池
void init_wp_pool();
// 添加监视点
void watchpoints_add(char *e);
// 删除监视点
void watchpoints_del(int id);
// 显示监视点
void watchpoints_display();

/* We use the `readline' library to provide more flexibility to read from stdin. */
// 读取（nemu）指示符后面的输入字符串
static char* rl_gets() {
  static char *line_read = NULL;
  // 如果line_read不为空，释放其内存并将其赋值为空
  if (line_read) {
    free(line_read);
    line_read = NULL;
  }
  // 使用readline函数读取输入"(nemu) "后的字符串赋值给line_read
  line_read = readline("(nemu) ");
  // 如果line_read不为空且其内容不为空，将该输入加入历史记录
  if (line_read && *line_read) {
    add_history(line_read);
  }
  // 返回读取到的字符串
  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

// 退出程序
static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

/* 单步执行 */
static int cmd_si(char *args) {
	int step;
	if (args == NULL) step = 1;
	else sscanf(args, "%d", &step);
  //printf("%d",step);
	cpu_exec(step);
	return 0;
}

// 扫描寄存器
static int cmd_info(char * args) {
    char *arg = strtok(NULL, " ");

    if (arg == NULL)  //this is for securaty
        printf("error arg for info\n");
    else if (arg[0] == 'r')
        isa_reg_display();
    else if (arg[0] == 'w')
        watchpoints_display();

    return 0;
}

// 扫描内存
static int cmd_x(char *args){
    int number;
    paddr_t address;
    sscanf(args,"%d %x",&number,&address);
    if(number && address){
    for(int i=0;i<number;i++){
      printf("0x%016X: 0x%08lX\n", address, paddr_read(address, 4));
      address = address +4;
    }
    }
    return 0;
}

// 表达式求值
static int cmd_p(char *args) {
    bool success = true;
    /* calculate expression */
    uint64_t ret = expr(args, &success);
    /* check if argument has errors */
    if (success == true)
        printf("%s = %lx(%lu)\n", args, ret, ret);
    else
        printf("%s: 计算错误\n", args);
    return 0;
}

// 添加监视点
static int cmd_w(char *args) {
    watchpoints_add(args);
    return 0;
}

// 删除监视点
static int cmd_d(char *args) {
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    unsigned id;
    if (arg == NULL || sscanf(arg, "%u", &id) != 1)
        printf("'%s' must be an integer.\n", arg);
    /* free watchpoint */
    watchpoints_del(id);
    return 0;
}

// 命令匹配表，通过命令名匹配相应函数，并将参数传入
static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "help <NAME>--获取命令的信息和使用方式", cmd_help },
  { "c",    "   继续运行被暂停的程序", cmd_c },
  { "q",    "   Exit NEMU", cmd_q },
  { "si",   "  si <N>   -- 单步执行", cmd_si},
  { "info", "info <R/W>打印寄存器或监视点状态", cmd_info },
  { "x",    "   x <N> <EXPR> 扫描EXPR地址后N字节内容", cmd_x },
  { "p",    "   p <EXPR> -- 表达式求值",cmd_p},
  { "w",    "   w <EXPR> -- 设置监视点", cmd_w},
  { "d",    "   d <N>    -- 删除监视点 N", cmd_d},
  /* TODO: Add more commands */

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

// 由外接参数开启的批处理模式内部开关
void sdb_set_batch_mode() {
  is_batch_mode = true;
}

// sdb主循环
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

    // 匹配命令表命令，执行相应命令
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

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
