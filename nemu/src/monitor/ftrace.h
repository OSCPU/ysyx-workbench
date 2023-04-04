#ifndef _FTRACER_H_
#define _FTRACER_H_

#include "elfloader.h"

#define FT_CALL 0
#define FT_RET 1

typedef struct __StackEntry{
    FuncInfo *cur_func; // 当前位置函数地址 
    FuncInfo *dst_func; // 目标位置函数地址
    paddr_t addr;       // 指令所在地址
    int type;           // call 或 return
    struct __StackEntry *next;
}StackEntry;

void init_ftracer(const char* elf_file, const char *ramdisk_file, const char *appname);

void stack_return(paddr_t cur, paddr_t des);

void stack_call(paddr_t cur, paddr_t des);

void print_stack_trace();

void error_finfo();

#endif