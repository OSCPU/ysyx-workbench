/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
  uint32_t value;
  uint32_t last_value;
  char expr[100];

} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
void check_wp() {
  WP *tmp;
  int cnt_head;
  int cnt_free;

  cnt_head = 0;
  for(tmp=head;tmp!=NULL;tmp=tmp->next){
    cnt_head++;
  }

  cnt_free = 0;
  for(tmp=free_;tmp!=NULL;tmp=tmp->next){
    cnt_free++;
  }
  printf("cnt_head:%d\tcnt_free:%d\ttotal:%d\n",cnt_head,cnt_free,cnt_free+cnt_head);

  return;
}

void new_wp(char e[])
{
  WP* tmp;
  uint32_t expr_value;
  bool success;
  //所有监测点都被使用，终止程序
  if(free_ == NULL){
    assert(0);
  }
  //至少一个监测点空闲
  tmp = free_;
  free_ = free_->next;

  tmp->next = head;
  head = tmp;
  
  //赋值
  expr_value = expr(e,&success);
  tmp->last_value = expr_value;
  tmp->value = expr_value;
  strcpy(tmp->expr, e);

}

void free_wp(WP* wp){
  WP* tmp;

  //遍历head链表
  for(tmp=head; tmp!=NULL; tmp=tmp->next){
    if(tmp == wp && tmp == head){
      head = head->next;
      tmp->next = free_;
      free_ = wp;
      return;
    }
    if(tmp->next == wp){
      tmp->next = wp->next;
      wp->next = free_;
      free_ = wp;
      return;
    }
  }
  //wp不在已使用的监测点中，程序终止
  assert(0);
}

int scan_head_list() {
  WP* tmp;
  bool success;

  for(tmp=head; tmp!=NULL; tmp=tmp->next){
    tmp->value = expr(tmp->expr, &success);
    if(tmp->value!=tmp->last_value){
      printf("Breakpoint:\t%d\t%s\n", tmp->NO,tmp->expr);
      return 1;
    }
  }
  return 0;
}

void show_info_wp() {
  WP* tmp;
  int start;

  start = 0;
  for(tmp=head; tmp!=NULL; tmp=tmp->next){
    if(!start){
      printf("Num\tWhat\n");
      start = 1;
    }
    printf("%d\t%s\n", tmp->NO,tmp->expr);
  }
  //debug
  check_wp();
}

void delete_wp(int NO) {
  WP *tmp;

  for(tmp=head; tmp!=NULL; tmp=tmp->next){
    if(tmp->NO == NO){
      free_wp(tmp);
    }
  }
}

