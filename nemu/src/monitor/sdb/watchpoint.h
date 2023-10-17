#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#include "common.h"
#define NR_WP 32
word_t expr(char *e,bool *success);

typedef struct watchpoint{
  int NO;
  struct watchpoint *next;
  bool flat;
  char expr[100];
  int  new_value;
  int  old_value;
}WP;

extern WP wp_pool[NR_WP];
WP* new_wp();
void free_wp(WP* wp);
#endif
