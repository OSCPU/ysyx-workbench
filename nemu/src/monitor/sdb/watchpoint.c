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
#include <stdlib.h>
#include <stdbool.h>
#include "watchpoint.h"  // 引入头文件
#define NR_WP 32



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
/*  if (free_ == NULL) {
    // 如果没有空闲监视点，终止程序
    printf("No free watchpoints available!\n");
    assert(0);
  }

  // 从空闲链表中取出第一个节点
  WP *wp = free_;
  free_ = free_->next;
 wp->NO = wp->NO;  // 设置监视点编号（可以进一步优化为自增编号）
  wp->expr = NULL;
  wp->value = 0;
  wp->next = NULL;
  // 将该节点插入到活跃链表的头部
  wp->next = head;
  head = wp;

  return wp;*/
	 if (free_ == NULL) {
    printf("No free watchpoints available!\n");
    assert(0);  // 如果没有空闲监视点，终止程序
  }

  // 从空闲链表中取出第一个节点
  WP *wp = free_;
  free_ = free_->next;

  // 确保每个监视点在链表中有唯一编号
 // wp->NO = wp->NO == 0 ? 1 : wp->NO;  // 监视点编号（可以增加编号逻辑）

  // 初始化监视点
  wp->expr = NULL;
  wp->value = 0;
  wp->next = head;
  head = wp;  // 将该节点插入到活跃链表的头部

  printf("New watchpoint %d created.\n", wp->NO);
  return wp;
}

// 将一个监视点归还到空闲链表
void free_wp(WP *wp) {
  // 从活跃链表中移除该节点
/*  WP **prev = &head;
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
  free_ = wp;*/
  if (wp == NULL) {
    printf("Cannot free a NULL watchpoint!\n");
    return;
  }

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

  printf("Watchpoint %d deleted.\n", wp->NO);
}

// 创建一个新的监视点并记录表达式

WP* new_watchpoint(char *expr_str) {
/*    WP *wp = malloc(sizeof(WP));
    if (wp == NULL) {
        printf("Memory allocation failed for new watchpoint\n");
        return NULL;
    }

    // 使用 expr_str 计算表达式值
    bool success = false;
    wp->value = expr(expr_str, &success);  // expr 函数计算表达式
    if (!success) {
        printf("Failed to evaluate expression: %s\n", expr_str);
        free(wp);
        return NULL;
    }

    wp->expr = expr_str;  // 存储表达式字符串
    wp->next = NULL;  // 设置为链表的最后一个节点

    return wp;*/  
   // 从空闲链表分配一个监视点
  WP *wp = new_wp();
  if (wp == NULL) {
    return NULL;  // 如果没有空闲监视点，返回 NULL
  }

  // 分配内存存储表达式字符串
  wp->expr = malloc(strlen(expr_str) + 1);  // 分配内存来存储表达式
  if (wp->expr == NULL) {
    printf("Memory allocation failed for watchpoint expression\n");
    free_wp(wp);  // 释放监视点
    return NULL;
  }

  // 将表达式字符串复制到监视点中
  strcpy(wp->expr, expr_str);

  // 使用 expr_str 计算表达式的值
  bool success = false;
  wp->value = expr(expr_str, &success);  // 假设 expr 函数计算表达式
  if (!success) {
    printf("Failed to evaluate expression: %s\n", expr_str);
    free(wp->expr);  // 释放表达式字符串内存
    free_wp(wp);     // 释放监视点
    return NULL;
  }

  // 成功设置监视点，输出信息
  printf("Watchpoint %d set: %s\n", wp->NO, expr_str);

  return wp;  // 返回新创建的监视点
}




// 扫描所有监视点并检查它们的值是否发生变化
void check_watchpoints() {
    WP *wp = head;
    while (wp != NULL) {
        bool success = false;
        word_t new_value = expr(wp->expr, &success);  // 计算新的表达式值
        if (!success) {
            printf("Failed to evaluate expression: %s\n", wp->expr);
            wp = wp->next;
            continue;
        }

        // 如果监视点的值发生变化，则暂停程序
        if (new_value != wp->value) {
            wp->value = new_value;  // 更新监视点的值
            nemu_state.state = NEMU_STOP;  // 设置程序为暂停状态
            printf("Watchpoint %d triggered: %s = %u\n", wp->NO, wp->expr, wp->value);
            return;  // 触发后暂停，退出函数
        }

        wp = wp->next;  // 继续检查下一个监视点
    }
}

// 显示所有监视点的状态
void info_watchpoints() {
    WP *wp = head;
    if (wp == NULL) {
        printf("No watchpoints currently set.\n");
        return;
    }
    printf("Watchpoint list:\n");
    while (wp != NULL) {
        printf("Watchpoint %d: %s = %u\n", wp->NO, wp->expr, wp->value);
        wp = wp->next;
    }
}

// 删除指定监视点
void delete_watchpoint(int no) {     WP **prev = &head;
    WP *wp = NULL;

    // 查找指定编号的监视点
    while (*prev != NULL) {
        if ((*prev)->NO == no) {
            wp = *prev;
            break;
        }
        prev = &(*prev)->next;
    }

    // 如果没有找到该监视点
    if (wp == NULL) {
        printf("Watchpoint %d not found.\n", no);
        return;
    }

    // 打印监视点信息
    printf("Deleting watchpoint %d at address %p\n", wp->NO, wp);

    // 从链表中移除该监视点
    *prev = wp->next;

    // 释放监视点表达式字符串内存
    if (wp->expr != NULL) {
	    printf("fuck you");
        free(wp->expr);
    }

    // 不再使用 wp 指针后才可以释放内存
//    free(wp);  // 释放监视点结构体
}

void print_watchpoints() {
    WP *wp = head;
    printf("Active watchpoints:\n");
    while (wp != NULL) {
        printf("Watchpoint %d at %p\n", wp->NO, wp);
        wp = wp->next;
    }
}

