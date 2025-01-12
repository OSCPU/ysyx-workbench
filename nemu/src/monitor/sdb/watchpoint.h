

#pragma once

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;
} WP;

void init_wp_pool();
WP* new_wp();
void free_wp(WP *wp);

