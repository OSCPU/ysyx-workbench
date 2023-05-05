#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <common.h>

#ifdef CONFIG_FTRACE
typedef struct
{
    uint64_t fun_addr;
    uint64_t fun_size;
    char *fun_name;
} elf_info;
elf_info elf_func[1000];
int elf_cnt = 0;

int ftrace_cnt = 0;
char ftrace_buf[100][100];
int fun_dep = 0;
void ftrace_judge(uint64_t pc, uint64_t dnpc, int is_call)
{
    int pc_fun = -1, dnpc_fun = -1;
    for (int i = 0; i < elf_cnt; i++)
    {
        if (elf_func[i].fun_addr <= pc && pc < elf_func[i].fun_addr + elf_func[i].fun_size)
            pc_fun = i;
        if (elf_func[i].fun_addr <= dnpc && dnpc < elf_func[i].fun_addr + elf_func[i].fun_size)
            dnpc_fun = i;
    }
    if (pc_fun == dnpc_fun)
        return;
    char empty[100] = {0};
    for (int i = 0; i < fun_dep; i++)
        empty[i] = ' ';
    if (elf_func[dnpc_fun].fun_addr == dnpc)
    {
        if (is_call)
        {
            sprintf(ftrace_buf[ftrace_cnt], "%lx: %scall [%s@%lx]", pc, empty, elf_func[dnpc_fun].fun_name, elf_func[dnpc_fun].fun_addr);
            ftrace_cnt++;
            fun_dep++;
        }
    }
    else
    {
        sprintf(ftrace_buf[ftrace_cnt], "%lx: %sret [%s]", pc, empty, elf_func[pc_fun].fun_name);
        ftrace_cnt++;
        fun_dep--;
    }
    ftrace_cnt %= 100;
}

void print_ftrace()
{
    for (int i = 0; i < ftrace_cnt; i++)
    {
        if ((i + 1) % 100 == ftrace_cnt)
            printf("-->%s\n", ftrace_buf[i]);
        else
            printf("   %s\n", ftrace_buf[i]);
    }
}

void read_elf(char *elf_name)
{
    if (elf_name == NULL)
    {
        Log("no input elf file");
        return;
    }
    FILE *stream;
    stream = fopen(elf_name, "rb");
    Assert(stream, "Can not open '%s'", elf_name);

    unsigned char *buffer;
    buffer = (unsigned char *)malloc(100500 * sizeof(unsigned char));
    int ret = fread(buffer, sizeof(unsigned char), 100500, stream);
    Assert(ret != 0, "Can not open '%s'", elf_name);

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)buffer;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(buffer + ehdr->e_shoff);
    Elf64_Shdr *shdr_strtab = NULL;
    Elf64_Shdr *shdr_symtab = NULL;

    for (int i = 0; shdr_strtab == NULL || shdr_symtab == NULL; i++)
    {
        if (shdr[i].sh_type == SHT_SYMTAB)
        {
            shdr_symtab = &shdr[i];
        }
        else if (shdr[i].sh_type == SHT_STRTAB)
        {
            shdr_strtab = &shdr[i];
            break;
        }
    }

    Elf64_Sym *table_sym = (Elf64_Sym *)(buffer + shdr_symtab->sh_offset);

    for (int i = 0; i <= shdr_symtab->sh_size / shdr_symtab->sh_entsize; i++)
    {
        if (ELF64_ST_TYPE(table_sym[i].st_info) == STT_FUNC)
        {
            elf_func[elf_cnt].fun_addr = table_sym[i].st_value;
            elf_func[elf_cnt].fun_size = table_sym[i].st_size;
            elf_func[elf_cnt].fun_name = (char *)(buffer + shdr_strtab->sh_offset + table_sym[i].st_name);
            Log("%lx %lx %s", elf_func[elf_cnt].fun_addr, elf_func[elf_cnt].fun_size, elf_func[elf_cnt].fun_name);
            elf_cnt++;
        }
    }

    // for (int i = 0; i < elf_cnt; i++)
    //    Log("%lx %lx %s", elf_func[i].fun_addr, elf_func[i].fun_size, elf_func[i].fun_name);
    return;
}
#endif