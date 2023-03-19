#include "sdb.h"

#define NR_WP 32


static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;
int len=0;
void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    memset(wp_pool[i].par,'\0',strlen(wp_pool[i].par));
    wp_pool[i].rst=0;
  }
  head = NULL;
  free_ = wp_pool;
  Log("free head next NO :%d",free_->next->NO);
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp(char *exp,bool *success){
if (free_->next == NULL){
    assert(0);
  }
  
  WP* result = free_->next;
  //result->NO = len ++;
  free_->next = result->next;
  result->next = NULL;
  result->rst=expr(exp, success);
  strcpy(result->par, exp);
  
  if (head == NULL){
    head = result;
  }else{
    result->next = head->next;
    head->next = result;
  }

  return result;
}
void free_wpn(int no){
    if (head->NO == no){
    WP* buffer = head->next;
    head->next = head->next;
    free_->next = head;
    head = buffer;
    return ;
  }

  WP* prev = head;
  while (prev->next){
    if (prev->next->NO == no){
      WP* buffer = prev->next->next;
      prev->next->next = free_->next;
      free_->next = prev->next;
      prev->next = buffer;
      return ;
    }
    prev = prev->next;
  }
}
void free_wp(){
  WP* prev = head;
  while (prev->next){
    if (!prev->next->next ){
      WP* buffer = prev->next->next;
      prev->next->next = free_->next;
      free_->next = prev->next;
      prev->next = buffer;
      return ;
    }
    prev = prev->next;
  }
}
void dispaly_allwatchpoint(){
  WP * q;
  q=head;
  if(head==NULL)
    Log("no watchpoint now\n");
  for(;head!=NULL;head=head->next){
    Log("point %d the par is %s and result is %lu\n",head->NO,head->par,head->rst);
  }
  head=q;
}
bool check_watchpoint(WP **point){
  WP *cur = head;
  bool success = true;
  while (cur){
    if (expr(cur->par, &success)!=cur->rst){
      *point = cur;
      return true;
    }
    cur = cur->next;
  }
  return false;
}