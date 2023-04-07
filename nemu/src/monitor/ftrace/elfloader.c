#include <elf.h>
#include <stdio.h>
#include <string.h>

#include "elfloader.h"

// typedef Elf32_Shdr Elf_Shdr;
// typedef Elf32_Ehdr Elf_Ehdr;

static FUNC_INFO elf_funcs[1024];

static void read_from_file(FILE *elf, size_t offset, size_t size, void* dest){
    fseek(elf, offset, SEEK_SET);
    int flag = fread(dest, size, 1, elf);
    assert(flag == 1);
}

static void get_str_from_file(FILE *elf, size_t offset, size_t n, void* dest){
    fseek(elf, offset, SEEK_SET);
    char* flag = fgets(dest, n, elf);
    assert(flag != NULL);
}

static int end;
static void append(char* func_name, paddr_t start, size_t size){
    strncpy(elf_funcs[end].func_name, func_name, sizeof(elf_funcs[0].func_name));
    elf_funcs[end].start = start;
    elf_funcs[end].size = size;
    end++;
}

void init_elf(const char* elf_file, size_t global_offset){
    // printf("Loading from %s\n", elf_file);
    FILE *elf = fopen(elf_file, "rb");
    assert(elf != NULL);
    Elf32_Ehdr elf_header;
    read_from_file(elf, global_offset + 0, sizeof elf_header, &elf_header);
    
    Elf32_Off section_header_offset = elf_header.e_shoff;
    size_t headers_entry_size = elf_header.e_shentsize;
    int headers_entry_num = elf_header.e_shnum;

    // printf("====== Reading ELF File ======\n");
    // printf("e_shoff: %d \n", section_header_offset);
    // printf("e_shentsize: %ld\t e_shnum: %d \n", headers_entry_size, headers_entry_num);
    
    assert(sizeof(Elf32_Shdr) == headers_entry_size);
    
    // printf("====== Selection Headers ======\n");

    Elf32_Off symbol_table_offset = 0, string_table_offset = 0;
    size_t symbol_table_total_size = 0;
    //size_t string_table_total_size;
    size_t symbol_table_entry_size = 0;
    for (int i = 0; i < headers_entry_num; ++i){
        Elf32_Shdr section_entry;
        read_from_file(elf, global_offset + i * headers_entry_size + section_header_offset,
            headers_entry_size, &section_entry);
        switch(section_entry.sh_type){
            case SHT_SYMTAB:
                symbol_table_offset = section_entry.sh_offset;
                symbol_table_total_size = section_entry.sh_size;
                symbol_table_entry_size = section_entry.sh_entsize;
            break;

            case SHT_STRTAB:
                if (i == elf_header.e_shstrndx){}else{
                    string_table_offset = section_entry.sh_offset;
                    //string_table_total_size = section_entry.sh_size;
                }
            break;
        }
    }

    // printf("String Table Offset: %#x\n", string_table_offset);
    // printf("Symbol Table Offset: %#x\n", symbol_table_offset);
    
    char function_name[64];
    assert(symbol_table_entry_size == sizeof(Elf32_Sym));
    for (int i = 0; i < symbol_table_total_size / symbol_table_entry_size; ++i){
        Elf32_Sym symbol_section_entry;
        read_from_file(elf, global_offset + i * symbol_table_entry_size + symbol_table_offset, 
            symbol_table_entry_size, &symbol_section_entry);
        switch(ELF32_ST_TYPE(symbol_section_entry.st_info)){
            case STT_FUNC:
            get_str_from_file(elf, global_offset + string_table_offset + symbol_section_entry.st_name, 
                sizeof(function_name), function_name);
            append(function_name, symbol_section_entry.st_value, symbol_section_entry.st_size);  
            break;
        }
    }
    // printf("====== Symbol Table ======\n");
    // for (int i = 0; i < end; ++i){
    //     FUNC_INFO *info = &elf_funcs[i];
    //     printf("Func: %12s | Start: %#x | Size: %ld\n", info->func_name, 
    //         info->start, info->size);
    // }
}

FUNC_INFO* check_func(paddr_t addr){
    for (int i = 0; i < end; ++i){
        FUNC_INFO *info = &elf_funcs[i];
        if (addr >= info->start && addr < info->start + info->size){
            return info;
        }
    }
    return NULL;
}