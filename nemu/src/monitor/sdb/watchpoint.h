#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include <common.h>
word_t expr(char *e,bool *success);
#define NR_WP 32

typedef struct watchpoint {
  int NO;
  int flat;
  struct watchpoint *next;
  char *args;
  word_t val;
} WP;

WP* new_wp();
//extern WP wp_pool[NR_WP];
void free_wp(int no);
bool check_wp();
void watchpoint_display();
void create_wp(char* args);
#endif
