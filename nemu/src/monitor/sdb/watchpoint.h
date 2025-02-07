#ifndef _WATCHPOINT_H_
#define _WATCHPOINT_H_
#include <common.h>
// 将 struct watchpoint 定义移到这里
typedef struct watchpoint {
  int NO;
  char *expr;
  word_t value;
  struct watchpoint *next;
} WP;

void init_wp_pool();
WP* new_wp();
void free_wp(WP *wp);
WP* new_watchpoint(char *expr);

// 扫描所有监视点并检查它们的值是否发生变化
void check_watchpoints();

// 显示所有监视点信息
void info_watchpoints();

// 删除指定监视点
void delete_watchpoint(int no);
void print_watchpoints() ;
#endif  // _WATCHPOINT_H_
