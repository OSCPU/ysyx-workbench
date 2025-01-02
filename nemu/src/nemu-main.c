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

#include <common.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
word_t expr(char *e, bool *success);

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
#else
  init_monitor(argc, argv);
#endif

  const char *default_file_path = "/home/jason/ssh/ysyx-workbench/nemu/tools/gen-expr/input";
  const char *filename = default_file_path;  // 默认使用默认文件路径
  const char *log_file = NULL;  // 默认为NULL，表示没有指定日志文件

  // 解析命令行参数
  for (int i = 1; i < argc; i++) {
    if (strncmp(argv[i], "--log=", 6) == 0) {
      // 处理日志路径
      log_file = argv[i] + 6;
      printf("Log file path: %s\n", log_file);
      // 你可以在这里添加日志的处理逻辑
    } else {
      // 处理输入文件，假设只处理一个输入文件路径
      filename = argv[i];
    }
  } 
  // 尝试打开文件
  FILE *file = fopen(filename, "r");
  if (!file) {
    perror("Failed to open input file");
    return 1;
  }

  char line[1024]; // 用于存储每行表达式
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

    // 转换预期结果为整数
    word_t expected_result = strtol(expected_result_str, NULL, 10);

    // 调用 expr() 计算表达式结果
    bool success = false;
    word_t result = expr(expression, &success);
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

  /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}

