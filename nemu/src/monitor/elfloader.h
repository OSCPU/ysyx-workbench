#ifndef _ELFLOADER_H
#define _ELFLOADER_H

#include <common.h>
#include <stddef.h>

typedef struct {
    char func_name[64]; // ������
    paddr_t start;      // ��ʼ��ַ
    size_t size;        // �������С
}FuncInfo;              // [start, start+size)
FuncInfo elf_funcs[1024];
void init_elf(const char* elf_file, size_t global_offset);

FuncInfo* check_func(paddr_t addr);

#endif