#ifndef _ELFLOADER_H
#define _ELFLOADER_H

#include <common.h>
#include <stddef.h>

typedef struct __FUNC_INFO{
    char func_name[64];
    paddr_t start;
    size_t size;
}FUNC_INFO;

void init_elf(const char* elf_file, size_t global_offset);

FUNC_INFO* check_func(paddr_t addr);

#endif