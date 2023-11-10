#include <common.h>
#include <assert.h>

#define NR_WP 32
#define LEN_EXPR 100

word_t expr(char *s, bool *success);

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
  printf("cnt_head:%d\tcnt_free:%d\tcnt_total:%d\n",cnt_head,cnt_free,cnt_free+cnt_head);

  return;
}

void new_wp(char e[])
{
  WP* tmp;
  uint32_t expr_value;
  bool success;
  // at least one watchpoint is availble
  if(free_ == NULL){
    assert(0);
  }
  tmp = free_;
  free_ = free_->next;

  tmp->next = head;
  head = tmp;
  
  // create a new node
  expr_value = expr(e,&success);
  tmp->last_value = expr_value;
  tmp->value = expr_value;
  strcpy(tmp->expr, e);
}

void free_wp(WP* wp){
  WP* tmp;
  // tranverse head list
  for(tmp=head; tmp!=NULL; tmp=tmp->next){
    if(tmp == wp && tmp == head){
      head = head->next;
      tmp->next = free_;
      free_ = wp;
      return;
    }
    else if(tmp->next == wp){
      tmp->next = wp->next;
      wp->next = free_;
      free_ = wp;
      return;
    }
  }
  // should not reach here
  assert(0);
}

int trace_wp_step() {
  WP* tmp;
  bool success;

  for(tmp = head; tmp != NULL; tmp = tmp->next){
    tmp->value = expr(tmp->expr, &success);
    if(tmp->value!=tmp->last_value){
      printf("Hit breakpoint:\t%d\t%s\n", tmp->NO,tmp->expr);
      return 1;
    }
  }
  return 0;
}

void print_wp_info() {
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
  //check_wp();
}

void delete_wp(int NO) {
  WP *tmp;

  for(tmp=head; tmp!=NULL; tmp=tmp->next){
    if(tmp->NO == NO){
      free_wp(tmp);
    }
  }
}

