#include "ftrace.h"

#include <utils.h>
#include <stdlib.h>
#include <isa.h>
#ifdef CONFIG_FTRACE
    static char *action_name[] = {"Call", "Ret"};
#endif
#ifdef CONFIG_FTRACE
typedef struct {
  char *name;
  size_t size;
  size_t disk_offset;
} Finfo;

static Finfo file_table[] __attribute__((used)) = {
};

#endif

StackEntry header;
StackEntry *end = &header;

void init_ftracer(const char* elf_file, const char *ramdisk_file, const char *appname){
  #ifdef CONFIG_FTRACE
    if(elf_file){
      init_elf(elf_file, 0);
    }if(ramdisk_file && appname){
      size_t offset = -1;
      for (int i = 0; i < sizeof(file_table)/sizeof(Finfo); ++i){
        if (strcmp(file_table[i].name, appname) == 0){
          offset = file_table[i].disk_offset;
          break;
        }
      }
      assert(offset != -1);
      //TOOD: fix this
      init_elf(ramdisk_file, offset);
    }
    header.des_info = NULL;
    header.cur_info = NULL;
    header.next = NULL;
    header.addr = 0;
  #endif
}

#ifdef CONFIG_FTRACE
static void append(paddr_t cur, paddr_t des, int type){
    StackEntry *node = malloc(sizeof(StackEntry));
    end->next = node;
    node->next = NULL;
    node->addr = cur;
    node->cur_info = check_func(cur);
    node->des_info = check_func(des);
    node->type = type;
    printf("<%#x>" ASNI_FMT(" %-12s ", ASNI_FG_BLUE) ASNI_FMT("%s", ASNI_FG_WHITE)  
            ASNI_FMT("\t<%#x> ", ASNI_FG_YELLOW) ASNI_FMT("%-12s \n", ASNI_FG_BLUE),  
            node->addr, node->cur_info ? node->cur_info->func_name :"", action_name[node->type], 
            node->des_info ? node->des_info->start : 0, node->des_info ? node->des_info->func_name : "");
    end = node;
}
#endif

void stack_call(paddr_t cur, paddr_t des){
  #ifdef CONFIG_FTRACE
    append(cur, des, FT_CALL);
  #endif
}

void stack_return(paddr_t cur, paddr_t des){
  #ifdef CONFIG_FTRACE
    append(cur, des, FT_RET);
  #endif
}




void print_stack_trace(){
  #ifdef CONFIG_FTRACE
    printf("====== " ASNI_FMT("Call Stack", ASNI_FG_BLUE) " ======\n");
    for (StackEntry* cur = &header; cur != end; cur = cur->next){
        StackEntry* r = cur->next;
        printf("<%#x>" ASNI_FMT(" %-12s ", ASNI_FG_BLUE) ASNI_FMT("%s", ASNI_FG_WHITE)  
            ASNI_FMT("\t<%#x> ", ASNI_FG_YELLOW) ASNI_FMT("%-12s \n", ASNI_FG_BLUE),  
            r->addr, r->cur_info ? r->cur_info->func_name :"", action_name[r->type], 
            r->des_info ? r->des_info->start : 0, r->des_info ? r->des_info->func_name : "");
    }
  #endif
}

void error_finfo(){
  #ifdef CONFIG_FTRACE
  vaddr_t pc = cpu.pc;
  FuncInfo *info = check_func(pc);
  printf(ASNI_FMT("Some error happended at %s(%#x).\n", ASNI_FG_RED), info->func_name, (unsigned)pc);
  #endif
}