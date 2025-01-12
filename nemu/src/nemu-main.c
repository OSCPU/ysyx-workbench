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

#include "monitor/sdb/watchpoint.h"  // 引入 watchpoint.h 头文件

#include <common.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <assert.h>
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

  init_wp_pool();  // 初始化监视点池

    // 分配三个监视点
    WP *wp1 = new_wp();
    WP *wp2 = new_wp();
    WP *wp3 = new_wp();

    printf("Allocated watchpoints: %d, %d, %d\n", wp1->NO, wp2->NO, wp3->NO);

    // 释放一个监视点
    free_wp(wp2);
    printf("Freed watchpoint: %d\n", wp2->NO);

    // 再次分配一个监视点，应该是刚刚释放的 wp2
    WP *wp4 = new_wp();
    printf("Re-allocated watchpoint: %d\n", wp4->NO);
 /* Start engine. */
  engine_start();

  return is_exit_status_bad();
}

