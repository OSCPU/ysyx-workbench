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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include "watchpoint.h"  // 包含监视点相关函数和结构
#include <stdlib.h>  // 引入 exit 函数的头文件


static int is_batch_mode = false;
int exit_flag = 0;  // 标记是否退出主循环

void init_regex();
void init_wp_pool();
int is_exit_status_bad();

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

static int cmd_info_r(char *args) {
    // 当用户输入 "info r" 时，调用打印寄存器值的函数
    isa_reg_display();
    return 0;  // 返回成功
}



static int cmd_q(char *args) {
//	exit(0);
//
//nemu_state.state = NEMU_END;
 // return 0;
 
    // 更新 nemu_state 状态为退出状态
//return   nemu_state.state = NEMU_QUIT;  // 设置退出状态
   // nemu_state.halt_ret = 0;       // 退出返回值可以设置为 0，表示正常退出
 nemu_state.state = NEMU_END;  // 设置退出状态
    nemu_state.halt_ret = 0;       // 退出返回值可以设置为 0，表示正常退出

    // 打印退出信息
    printf("Exiting the program...\n");

    // 设置 exit_flag 为 true，通知主循环退出
    exit_flag = 1;

    return 0 ;	


}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_x(char *args);

static int cmd_watch(char *args);
static int cmd_info_w(char *args);
static int cmd_d(char *args);



void mem_scan(char *args);
static int cmd_p(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
	{ "si", "Execute one or more instructions step by step", cmd_si },
 { "info_r", "Display register values", cmd_info_r},

  { "x", "Scan memory (usage: x <num> <address>)", cmd_x },
  /* TODO: Add more commands */
  {"p","the machine is reading file..",cmd_p},
   { "watch", "Set a watchpoint (usage: watch <expression>)", cmd_watch },
  { "info_w", "Display all watchpoints", cmd_info_w },
  { "d", "Delete a watchpoint (usage: d <watchpoint_number>)", cmd_d }
};


static int cmd_x(char *args) {
    mem_scan(args);
    return 0;
}

static int cmd_p(char *args)

{
	 const char *default_file_path = "/home/jason/ssh/ysyx-workbench/nemu/tools/gen-expr/input";
  const char *filename = default_file_path;  // 默认使用默认文件路径
  const char *log_file = NULL;  // 默认为NULL，表示没有指定日志文件



      // 解析命令行参数
    if (args != NULL) {
        char *arg = strtok(args, " ");
        while (arg != NULL) {
            if (strncmp(arg, "--log=", 6) == 0) {
                // 处理日志路径
                log_file = arg + 6;
                printf("Log file path: %s\n", log_file);
                // 你可以在这里添加日志的处理逻辑
            } else {
                // 处理输入文件，假设只处理一个输入文件路径
                filename = arg;
            }
            arg = strtok(NULL, " ");
        }
    }

    // 尝试打开文件
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open input file");
        return 1;
    }

    char line[2048]; // 用于存储每行表达式
    printf("Reading expressions from %s...\n", filename);

    while (fgets(line, sizeof(line), file)) {
        // 去掉换行符
        line[strcspn(line, "\n")] = '\0';

        // 分割预期结果和表达式
        char *expected_result_str = strtok(line, " ");
        char *expression = strtok(NULL, "");

        if (!expected_result_str || !expression) {
            printf("Invalid format in line: %s\n", line);
            continue;
        }
	
	 char wrapped_expression[2048];
        snprintf(wrapped_expression, sizeof(wrapped_expression), "(%s)", expression);

        // 转换预期结果为整数
        word_t expected_result = strtol(expected_result_str, NULL, 10);

        // 调用 expr() 计算表达式结果
        bool success = false;
        word_t result = expr(wrapped_expression, &success);
        if (!success) {
            printf("Failed to evaluate expression: %s\n", expression);
            continue;
        }

        // 比较结果并输出
        if (result == expected_result) {
            printf("PASS: %s = %u\n", expression, result);
        } else {
            printf("FAIL: %s = %u (expected %u)\n", expression, result, expected_result);
        }
    }

  fclose(file);
 return 0;
}

// 设置监视点
static int cmd_watch(char *args) {

 if (args == NULL || strlen(args) == 0) {
        printf("Usage: watch <expression>\n");
        return 0;
    }

    WP *wp = new_wp();  // 申请一个新的监视点
    if (wp == NULL) {
        printf("No free watchpoint slots available.\n");
        return 0;
    }

    bool success = true;
    wp->value = expr(args, &success);  // 计算表达式的初始值
    if (!success) {
        printf("Failed to evaluate expression: %s\n", args);
        free_wp(wp);  // 如果表达式无效，释放监视点
        return 0;
    }

    // 动态分配内存以存储表达式
    wp->expr = malloc(strlen(args) + 1);  // 分配空间，+1 用于 '\0'
    if (wp->expr == NULL) {
        printf("Memory allocation failed.\n");
        free_wp(wp);
        return 0;
    }
    strcpy(wp->expr, args);  // 复制表达式内容到监视点

    printf("Watchpoint %d set: %s\n", wp->NO, wp->expr);
    return 0;	
	/*    if (args == NULL) {
        printf("Usage: watch <expression>\n");
        return 0;
    }
    WP *wp = new_wp(args);  // 创建一个新的监视点
    if (wp) {
        printf("Watchpoint %d set: %s\n", wp->NO, wp->expr);
    }
    return 0;*/
}

// 显示所有监视点
static int cmd_info_w(char *args) {
    info_watchpoints();  // 显示所有监视点
    return 0;
}

// 删除指定的监视点
static int cmd_d(char *args) {
    if (args == NULL) {
        printf("Usage: d <watchpoint_number>\n");
        return 0;
    }
    int no = atoi(args);  // 获取监视点编号
	print_watchpoints();
    delete_watchpoint(no);  // 删除监视点
	print_watchpoints();
    return 0;
}

static int cmd_si(char *args) {
  int n = 1; // 默认执行1条指令
  if (args != NULL) {
    n = atoi(args); // 将参数转换为整数，表示执行的指令数量
    if (n <= 0) {
      printf("Invalid argument. Please provide a positive integer.\n");
      return 0;
    }
  }
  cpu_exec(n); // 调用cpu_exec执行n条指令
  return 0;
}


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
  #ifdef CONFIG_BATCH_MODE
  sdb_set_batch_mode();  // 设置批处理模式
#endif
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
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
    if (exit_flag==1) {
   		 return;
  	}


  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
