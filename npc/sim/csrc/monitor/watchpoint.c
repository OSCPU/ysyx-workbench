#include <common.h>
#include <assert.h>
#include <cstdio>

#define NR_WP 32
#define LEN_EXPR 100

extern riscv32_CPU_state cpu;

word_t expr(char *s, bool *success);
word_t isa_reg_str2val(const char *s);
// watchpoint pool definition
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  uint32_t value;
  uint32_t last_value;
  char expr[LEN_EXPR];
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

void check_wp() {
  WP *node;
  int cnt_head;
  int cnt_free;

  cnt_head = 0;
  for(node=head;node!=NULL;node=node->next){
    cnt_head++;
  }

  cnt_free = 0;
  for(node=free_;node!=NULL;node=node->next){
    cnt_free++;
  }
  printf("cnt_head:%d\tcnt_free:%d\tcnt_total:%d\n",cnt_head,cnt_free,cnt_free+cnt_head);

  return;
}

void new_wp(char e[])
{
  WP* node;
  uint32_t expr_value;
  bool success;
  // at least one watchpoint is availble
  if(free_ == NULL){
    assert(0);
  }
  node = free_;
  free_ = free_->next;

  node->next = head;
  head = node;
  
  // create a new node
  expr_value = expr(e,&success);
  node->last_value = expr_value;
  node->value = expr_value;
  strcpy(node->expr, e);
}

void free_wp(WP* wp){
  WP* node;

  for(node = head; node != NULL; node = node->next){
    if(node == wp && node == head){
      head = head->next;
      node->next = free_;
      free_ = wp;
      return;
    }
    else if(node->next == wp){
      node->next = wp->next;
      wp->next = free_;
      free_ = wp;
      return;
    }
  }
  // should not reach here
  assert(0);
}

int trace_wp_step() {
  WP* node;

  for(node = head; node != NULL; node = node->next){
    node->value = expr(node->expr, NULL);
    if(node->value != node->last_value){
      printf("Hit breakpoint:\t%d\t%s\n", node->NO, node->expr);
      printf("change:%#x(%d) to %#x(%d)\t@ pc = %#x\n",
        node->last_value, node ->last_value, node->value, node->value, isa_reg_str2val("pc"));

      node->last_value = node->value;
      return 1;
    }
  }

  return 0;
}

void print_wp_info() {
  WP* node;

  printf("Num\tWhat\n");
  for(node = head; node != NULL; node = node->next){
    printf("%d\t%s\n", node->NO, node->expr);
  }
  //debug
  //check_wp();
}

void delete_wp(int NO) {
  WP *node;

  for(node = head; node != NULL; node = node->next){
    if(node->NO == NO){
      free_wp(node);
    }
  }
}

