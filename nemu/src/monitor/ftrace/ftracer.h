#ifndef _FTRACER_H_
#define _FTRACER_H_

#include "elfloader.h"

#define FT_CALL 0
#define FT_RET 1

typedef struct __STACK_ENTRY_{
    FUNC_INFO* cur_info;
    FUNC_INFO* des_info;
    paddr_t addr;
    int type;
    struct __STACK_ENTRY_ *next;
}STACK_ENTRY;

void init_ftracer(const char* elf_file, const char *ramdisk_file, const char *appname);

void stack_return(paddr_t cur, paddr_t des);

void stack_call(paddr_t cur, paddr_t des);

void print_stack_trace();

void error_finfo();

#endif