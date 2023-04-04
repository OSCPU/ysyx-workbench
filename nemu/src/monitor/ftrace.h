#ifndef _FTRACER_H_
#define _FTRACER_H_

#include "elfloader.h"

#define FT_CALL 0
#define FT_RET 1

typedef struct __StackEntry{
    FuncInfo *cur_func; // ��ǰλ�ú�����ַ 
    FuncInfo *dst_func; // Ŀ��λ�ú�����ַ
    paddr_t addr;       // ָ�����ڵ�ַ
    int type;           // call �� return
    struct __StackEntry *next;
}StackEntry;

void init_ftracer(const char* elf_file, const char *ramdisk_file, const char *appname);

void stack_return(paddr_t cur, paddr_t des);

void stack_call(paddr_t cur, paddr_t des);

void print_stack_trace();

void error_finfo();

#endif