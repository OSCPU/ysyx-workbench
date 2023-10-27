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
#include <string.h>

#define NR_WP 32
#include "watchpoint.h"

WP wp_pool[NR_WP] = {};
static WP *wp_head = NULL, *wp_tail = NULL,           // watch point list
          *free_ = NULL;            // free nodes list

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

void free_wp(int no){
  if (wp_head->NO == no) {
    if (wp_tail == wp_head) {
      wp_tail = NULL;
    while(free_->next==NULL)
    {
    	free_=free_->next;
    }
    WP *p=free_;
    free_=wp_head;
    free_->next=p;
    wp_head=NULL;
    }
    else
    {
    while(free_->next==NULL)
    {
    	free_=free_->next;
    }
    WP *p=free_;
    free_=wp_head;
    wp_head=wp_head->next;//要放在 free_->next=p  前面
    free_->next=p;
    
    }
    
    return;
  }
  else
    {
    WP *pre = wp_head;
    while (pre->next && pre->next->NO != no) {
      pre = pre->next;
    }
    if (pre->next) {
      if (pre->next == wp_tail) {
        wp_tail = pre;
	while(free_->next==NULL)
        {
    	free_=free_->next;
        }
	WP *wp=pre->next;
        pre->next = wp->next;
        WP *p=free_;
        free_=wp;
        free_->next=p;

      }
      else{
      WP *wp = pre->next;              // search wp successfully
      while(free_->next==NULL)
      {
    	free_=free_->next;
      }
      pre->next = wp->next;
      WP *p=free_;
      free_=wp;
      free_->next=p;
      }
  }
  else
  {
      panic("Fail to free!\n");
  }
  }
}

WP* new_wp() {
  if (free_) {
    WP *new = free_;
    if (free_->next) {
      free_ = free_->next;
    }
    new->next = NULL;
    if (wp_head == NULL) {
      wp_head = new;
      wp_tail = new;
    }
    else
    {
      wp_tail->next = new;
      wp_tail = new;
    }
    return new;
  }
  else
  {
    panic("No more free watch point nodes in wp_pool!\n");
    return free_;
  }
}

// return false if val change
bool check_wp() {
  if (!wp_head) {
    return true;
  }
  WP *cur = wp_head;
  bool success = true;
  while (cur) {
    if (cur->val != expr(cur->args, &success)) {
      if (!success) {
        printf("Bad expression,try again.\n");
        return false;
      }
      printf("NO. %d watchpoint's value changed.\n", cur->NO);
      return false;
    }
    cur = cur->next;
  }
  return true;
}

void watchpoint_display() {
  if (wp_head == NULL) {
    printf("No watchpoint.\n");
  }
  else
  {
    WP *cur = wp_head;
    while (cur) {
      printf("NO.%d expression: %s  , init_value= %d.\n", cur->NO, cur->args, cur->val);
      cur = cur->next;
    }
  }
}

void create_wp(char* args)
{
  bool success = true;
  WP *new = new_wp();
  strcpy(new->args,args);
  new->val = expr(args, &success);
  if (!success) {
    printf("Bad expression,try again.\n");
    }

}
