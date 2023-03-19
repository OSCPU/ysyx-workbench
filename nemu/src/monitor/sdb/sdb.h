#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
  
  /* TODO: Add more members if necessary */
  uint64_t rst;
  char par[32];
} WP;
word_t expr(char *e, bool *success);
void dispaly_allwatchpoint();
void free_wp();
void free_wpn(int no);
WP* new_wp(char *exp,bool *success);
bool check_watchpoint(WP **pnt);
#endif
