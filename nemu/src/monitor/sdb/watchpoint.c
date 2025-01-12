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

#include "sdb.h"
#include <assert.h>
#include <stdio.h>

#define NR_WP 32

// 将 struct watchpoint 定义移到这里
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
} WP;


static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;



/* TODO: Implement the functionality of watchpoint */
void init_wp_pool() {
  for (int i = 0; i < NR_WP; i++) {
    wp_pool[i].NO = i;  // 初始化编号
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }
  head = NULL;
  free_ = wp_pool;  // 初始化空闲链表为整个 wp_pool
}

// 从空闲链表中分配一个监视点
WP* new_wp() {
  if (free_ == NULL) {
    // 如果没有空闲监视点，终止程序
    printf("No free watchpoints available!\n");
    assert(0);
  }

  // 从空闲链表中取出第一个节点
  WP *wp = free_;
  free_ = free_->next;

  // 将该节点插入到活跃链表的头部
  wp->next = head;
  head = wp;

  return wp;
}

// 将一个监视点归还到空闲链表
void free_wp(WP *wp) {
  // 从活跃链表中移除该节点
  WP **prev = &head;
  while (*prev != NULL && *prev != wp) {
    prev = &(*prev)->next;
  }

  if (*prev == NULL) {
    printf("Watchpoint not found in active list!\n");
    assert(0);  // 如果监视点不在活跃链表中，终止程序
  }

  // 从活跃链表中移除
  *prev = wp->next;

  // 将该节点插入到空闲链表的头部
  wp->next = free_;
  free_ = wp;
}


