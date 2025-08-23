#include "../include/common.h"
#include <elf.h>
#include <malloc.h>

struct function_list {
    char name[15];
    uint32_t start;
    uint32_t end;
};

struct function_list *funtions;
int nums = 0;
int taps = 0;
int c_or_r = 1;
void init_elf(const char *elf_file) {
    if(elf_file == NULL) { 
		Log("No elf is given.turn off ftrace");
		assert(0);
	}
    //printf("elf_file = %s\n", elf_file);
    FILE *fp = fopen(elf_file, "rb");
    Elf32_Ehdr ehdr;
    if (fread(&ehdr, 1, sizeof(ehdr), fp) != sizeof(ehdr)) {
        perror("fread ELF header");
        fclose(fp);
        exit(1);
    }
    // 检查是否为 ELF 文件
    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: %s is not an ELF file\n", elf_file);
        fclose(fp);
        exit(1);
    }

    // 2. 读取节区表
    Elf32_Shdr *sh_table =  static_cast<Elf32_Shdr*>(malloc(ehdr.e_shentsize * ehdr.e_shnum));
    if (!sh_table) {
        perror("malloc section table");
        fclose(fp);
        exit(1);
    }

    // 将文件指针定位到节区表位置
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(sh_table, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum) {
        perror("fread section table");
        free(sh_table);
        fclose(fp);
        exit(1);
    }

    // 3. 读取节区头字符串表 (section header string table)
    Elf32_Shdr sh_strtab_hdr = sh_table[ehdr.e_shstrndx];
    char *sh_strtab =  static_cast<char*>(malloc(sh_strtab_hdr.sh_size));
    if (!sh_strtab) {
        perror("malloc sh_strtab");
        free(sh_table);
        fclose(fp);
        exit(1);
    }
    fseek(fp, sh_strtab_hdr.sh_offset, SEEK_SET);
    if (fread(sh_strtab, 1, sh_strtab_hdr.sh_size, fp) != sh_strtab_hdr.sh_size) {
        perror("fread sh_strtab");
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }
    // 4. 查找符号表 ".symtab" 节区
    Elf32_Shdr symtab_hdr;
    int found = 0;
    for (int i = 0; i < ehdr.e_shnum; i++) {
        // 每个节区的名字都存放在 sh_strtab 中，由 sh_name 给出偏移值
        const char *section_name = sh_strtab + sh_table[i].sh_name;
        if (strcmp(section_name, ".symtab") == 0) {
            symtab_hdr = sh_table[i];
            found = 1;
            break;
        }
    }
    if (!found) {
        fprintf(stderr, "Error: No symbol table (.symtab) found!\n");
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }

    // 5. 根据符号表头的 sh_link 字段，获取关联的字符串表 (通常为 .strtab)
    if (symtab_hdr.sh_link >= ehdr.e_shnum) {
        fprintf(stderr, "Error: Invalid sh_link index for symbol table\n");
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }
    Elf32_Shdr strtab_hdr = sh_table[symtab_hdr.sh_link];

    // 6. 读取符号表数据
    int num_symbols = symtab_hdr.sh_size / sizeof(Elf32_Sym);
    
    Elf32_Sym *symtab = static_cast<Elf32_Sym*>(malloc(symtab_hdr.sh_size));
    if (!symtab) {
        perror("malloc symtab");
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }
    fseek(fp, symtab_hdr.sh_offset, SEEK_SET);
    if (fread(symtab, sizeof(Elf32_Sym), num_symbols, fp) != num_symbols) {
        perror("fread symtab");
        free(symtab);
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }

    // 7. 读取符号字符串表数据
    char *strtab = static_cast<char*>(malloc(strtab_hdr.sh_size));
    if (!strtab) {
        perror("malloc strtab");
        free(symtab);
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }
    fseek(fp, strtab_hdr.sh_offset, SEEK_SET);
    if (fread(strtab, 1, strtab_hdr.sh_size, fp) != strtab_hdr.sh_size) {
        perror("fread strtab");
        free(strtab);
        free(symtab);
        free(sh_strtab);
        free(sh_table);
        fclose(fp);
        exit(1);
    }
    funtions = static_cast<function_list*>(malloc(sizeof(struct function_list) * (num_symbols + 3)));
    // 8. 遍历符号表，输出符号信息
    //printf("共找到 %d 个符号：\n", num_symbols);
    int j = 0;
    for (int i = 0; i < num_symbols; i++) {
        // 每个符号的名字存储在字符串表中，其偏移量为 st_name
        if (symtab[i].st_info == 18){
            strcpy(funtions[j].name , strtab + symtab[i].st_name);
            funtions[j].start = symtab[i].st_value;
            funtions[j].end = symtab[i].st_value + symtab[i].st_size;
            printf("函数%d: 名称: %-20s 起始地址: 0x%x 结束地址: 0x%x 大小: %u\n",
                    j, funtions[j].name, funtions[j].start, funtions[j].end, symtab[i].st_size);
            j++;
        }
    }
    const char *start = "_start";
    strcpy(funtions[j].name , start);
    funtions[j].start = 0x80000000;
    funtions[j].end = 0x80000010;
    nums = j + 1;
    j = 0;
    // 释放分配的资源
    free(strtab);
    free(symtab);
    free(sh_strtab);
    free(sh_table);
    fclose(fp);

    FILE *fq = fopen("outputs/ftrace.txt", "w");
    fclose(fq);
    return;
}

void elf_print(int type, char *fname, uint32_t start, uint32_t end) {
    FILE *fq = fopen("outputs/ftrace.txt", "a");
    if(type == 0){
        if(c_or_r == 0)
            taps++;
        for(int i = 0; i < taps; i++){
            fprintf(fq, "\t");
        }
        fprintf(fq, "call   : ");
        for(int i = 0; i < taps; i++){
        fprintf(fq, "\t");
    }
        c_or_r = 0;
    }
    else{
        if(c_or_r == 1)
            taps--;
        for(int i = 0; i < taps; i++){
            fprintf(fq, "\t");
        }
        fprintf(fq, "return : ");
        c_or_r = 1;
    }
    fprintf(fq, "fname = %-30s  ", fname);
    fprintf(fq, "start = %#x  ", start);
    fprintf(fq, "end = %#x\n", end);
    fclose(fq);
}

char *ftrace_find_symbol(uint32_t addr){
	int i;
	for(i = 0;i < nums; i++){
		if(addr >= funtions[i].start && addr < funtions[i].end){
            //printf("----%d   0x%x  %-30s----\n",i, addr, funtions[i].name);
			return funtions[i].name;
		}
	}
	return NULL;
}