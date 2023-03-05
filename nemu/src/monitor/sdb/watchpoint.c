#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
    int NO;
    struct watchpoint *next;
    char expr[512];
    uint64_t result;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

// 初始化32位链表连接，初始化链表连接，设为全部空闲
void init_wp_pool() {
    int i;
    for (i = 0; i < NR_WP; i ++) {
        wp_pool[i].NO = i;
        wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

    head = NULL;
    free_ = wp_pool;
}

// 取出free头元素添加到head头上
WP* new_wp() {
    // 检查free是否为空
    assert(free_ != NULL);
    WP *tmp = free_;
    free_ = free_ -> next;
    tmp -> next = head;
    head = tmp;
    return tmp;
}

// 删除根据id索引的wp监视点
void free_wp(WP *wp) {
    // hwp是head头
    if (head == wp) {
        WP *tmp = head;
        head = head -> next;
        tmp -> next = free_;
        memset(tmp -> expr, 0, sizeof(tmp -> expr));
        free_ = tmp;
    } 
    // 否则遍历head
    else {
        WP *pt = head;
        while (pt != NULL && pt -> next != wp) {
            pt = pt -> next;
        }
        // Cannot find wp.
        if (pt == NULL) {
            printf("No watchpoints number %d.\n", wp -> NO);
            return;
        }
        WP *tmp = pt -> next;
        pt -> next = tmp -> next;
        tmp -> next = free_;
        memset(tmp -> expr, 0, sizeof(tmp -> expr));
        free_ = tmp;
    }
}

// 添加监视点
void watchpoints_add(char *e) {
    bool success = true;
    // 计算表达式
    uint64_t ret = expr(e, &success);
    // 判断表达式正确性
    if (success) {
        WP *pt = new_wp();
        // 存储表达式
        memcpy(pt -> expr, e, strlen(e));
        // 存储表达式的值
        pt -> result = ret;
    } else {
        printf("%s: Syntax error.\n", e);
    }
}

// 添加监视点
void watchpoints_del(int id) {
    WP *pt = head;
    while (pt != NULL) {
        if (pt -> NO != id) {
            pt = pt -> next;
        } else {
            free_wp(pt);
            return;
        }
    }
    // Cannot find wp.
    printf("No watchpoints number %d.\n", id);
}

// 遍历监视点
void watchpoints_display() {
    WP *pt = head;
    if (pt == NULL) {
        printf("No watchpoints.\n");
    } else {
        printf("Watchpoints List\n");
        while (pt != NULL) {
            printf("No %d: %s\n", pt -> NO, pt -> expr);
            pt = pt -> next;
        }
    }
}

// 监视点值检查
bool watchpoints_check() {
    WP *pt = head;
    bool is_changed = false;
    while (pt != NULL) {
        bool success = true;
        uint64_t now = expr(pt -> expr, &success);
        assert(success);
        // 监视点的值发生差异
        if (now != pt -> result) {
            is_changed = true;
            printf("Watchpoint %d: %s\n\n", pt -> NO, pt -> expr);
            printf("Old value = %lx\n", pt -> result);
            printf("New value = %lx\n\n", now);
            pt -> result = now;
        }
        pt = pt -> next;
    }
    return is_changed;
}
/* TODO: Implement the functionality of watchpoint */

