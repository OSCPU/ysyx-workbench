#include "isa.h"
#include "macro.h"
#include <common.h>
#include <elf.h>

extern riscv32_CPU_state cpu;

void ftrace_once(vaddr_t pc, vaddr_t dnpc);
void difftest_step(vaddr_t pc);
int trace_wp_step();

/*************** trace_and_difftest ***************/
void trace_and_difftest() {
  IFDEF(CONFIG_FTRACE,ftrace_once(cpu.pc,cpu.npc));
  IFDEF(CONFIG_DIFFTEST, difftest_step(cpu.pc));
  IFDEF(CONFIG_WATCHPOINT, if(trace_wp_step()){ npc_state.state = NPC_STOP;});
}
/******************** iringbuf ********************/
#ifdef CONFIG_IRINGBUF

#define NR_IRINGBUF  32
#define LEN_IRINGBUF 64

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
static char iringbuf[NR_IRINGBUF][LEN_IRINGBUF] = {};
static int  iringbuf_curidx = 0;

void iringbuf_step(vaddr_t pc, uint32_t inst) {
  char *p = iringbuf[iringbuf_curidx];
  // trace pc
  p += snprintf(p, LEN_IRINGBUF, FMT_WORD ":", pc);
  // trace inst
  int ilen = 4;
  uint8_t *pinst = (uint8_t *)&inst;
  int i;
  for(i = ilen - 1; i >=0; i--) {
    p += snprintf(p, 4, " %02x", pinst[i]);
  }
  int space_len = 1;
  memset(p, ' ', space_len);
  p += space_len;
  // trace assemble
  char *buf = iringbuf[iringbuf_curidx];
  disassemble(p, buf + LEN_IRINGBUF - p, pc, (uint8_t *)&inst, ilen);

  // puts to log
  log_write("%s\n", iringbuf[iringbuf_curidx]);
  // next indx
  iringbuf_curidx = (iringbuf_curidx + 1) % NR_IRINGBUF;
}

void iringbuf_display() {
  int i;
  printf("%s\n",ANSI_FMT("Most Recently Used Instructions:", ANSI_FG_CYAN));
  for (i = 0; i < NR_IRINGBUF; i++) {
    if(strcmp(iringbuf[i],"") == 0) continue;
    else if(i == ((iringbuf_curidx - 1) % NR_IRINGBUF)) printf("--->\t%s\n",iringbuf[i]);
    else printf("\t%s\n",iringbuf[i]);
  }
}

void print_current_inst() {
  int i = (iringbuf_curidx - 2) % NR_IRINGBUF;
	printf("%s\n",iringbuf[i]);
}
#endif /* ifdef CONFIG_IRINGBUF */

/******************** ftrace ********************/
static Elf32_Sym  *symtab;
static char       *strtab;
static Elf32_Shdr *symtab_shdr;
static Elf32_Shdr *strtab_shdr;

static char ftrace_buf[1024][128] = {};
static int  ftrace_buf_idx = -1; 
static int  ftrace_spcae_cnt;

void print_symbol_table() {
  int i;
  printf("%s\n",ANSI_FMT("Function Table", ANSI_FG_CYAN));
  printf("Num:\tValue:\t\tSize:\tName:\n");
  for (i = 0; i < symtab_shdr->sh_size / sizeof(Elf32_Sym); i++) {
    Elf32_Sym *sym = &symtab[i];
    char *name = &strtab[sym->st_name];
    if(ELF32_ST_TYPE(sym->st_info) == 2)
      printf("%3d:\t%x\t%u\t%s\n", i, sym->st_value, sym->st_size, name);
  }
}
void init_elf(const char *elf_file) {
  // open elf file
  FILE *fp = fopen(elf_file, "rb");
  if(fp == NULL) assert(0);

  // read elf header
  Elf32_Ehdr elf_head;
  if(fread(&elf_head, sizeof(Elf32_Ehdr), 1, fp) == 0) assert(0);

  //read section table
  Elf32_Shdr *shdr = (Elf32_Shdr *)malloc(sizeof(Elf32_Shdr) * elf_head.e_shnum);
  if(shdr == NULL) assert(0);

  if(fseek(fp, elf_head.e_shoff, SEEK_SET) != 0) assert(0);

  if(fread(shdr, sizeof(Elf32_Shdr) * elf_head.e_shnum, 1, fp) == 0) assert(0);

  // find symbol table && string table
  symtab_shdr = NULL;
  strtab_shdr = NULL;
  int i;
  for(i = 0; i < elf_head.e_shnum; i++) {
    if(shdr[i].sh_type == SHT_SYMTAB) {
      symtab_shdr = &shdr[i];
      strtab_shdr = &shdr[symtab_shdr->sh_link];
      break;
    }
  }
  if(symtab_shdr == NULL) assert(0);

  // read symbol table && string table
  symtab = (Elf32_Sym *) malloc(symtab_shdr->sh_size);
  if(fseek(fp, symtab_shdr->sh_offset, SEEK_SET) != 0) assert(0);
  if(fread(symtab, symtab_shdr->sh_size, 1, fp) == 0)  assert(0);
  strtab = (char *) malloc(strtab_shdr->sh_size);
  if(fseek(fp, strtab_shdr->sh_offset, SEEK_SET) != 0) assert(0);
  if(fread(strtab, strtab_shdr->sh_size, 1, fp) == 0)  assert(0);

  // debug
  //print_symbol_table();

  // close elf file
  fclose(fp);

  // init ftrace_stack
  memset(ftrace_buf, '\0', sizeof(ftrace_buf));
}

#ifdef CONFIG_FTRACE
void ftrace_once(vaddr_t pc, vaddr_t dnpc) {
  //sprintf(ftrace_stack[stack_indx++], "0x%x:\tcall[ %s@0x%x ]\n", s->pc, "hello", dnpc);
  int i;
  for (i = 0; i < symtab_shdr->sh_size / sizeof(Elf32_Sym); i++) {
    Elf32_Sym *sym = &symtab[i];
    char *name = &strtab[sym->st_name];
    if(ELF32_ST_TYPE(sym->st_info) == 2 ) { // match function
      if(ftrace_buf_idx >= 1000) {
        ftrace_buf_idx = 0;
        ftrace_spcae_cnt = 0;
        memset(ftrace_buf, '\0', sizeof(ftrace_buf));
      }
      if(!(pc >= sym->st_value && pc < (sym->st_value + sym->st_size)) && dnpc == sym->st_value ) { // function call
        //sprintf(ftrace_stack[stack_indx++], "0x%x:\tcall[ %s@0x%x ]\n", s->pc, name, dnpc);
        ftrace_buf_idx++;
        ftrace_spcae_cnt++;
        char *p = ftrace_buf[ftrace_buf_idx];
        p += sprintf(p,"0x%x:",pc);
        for(int j = 0; j < ftrace_spcae_cnt; j++) {
          p += sprintf(p, "  ");
        }
        p += sprintf(p, "call[%s@0x%x]\n", name, dnpc);
      }
      else if(!(pc >= sym->st_value && pc < (sym->st_value + sym->st_size)) && dnpc > sym->st_value && dnpc < (sym->st_value + sym->st_size) ) { //function return
        //sprintf(ftrace_stack[stack_indx++], "0x%x:\treturn[ %s@0x%x ]\n", s->pc, name, dnpc);
        ftrace_buf_idx++;
        char *p = ftrace_buf[ftrace_buf_idx];
        p += sprintf(p,"0x%x:",pc);
        for(int j = 0; j < ftrace_spcae_cnt; j++) {
          p += sprintf(p, "  ");
        }
        //p += sprintf(p, "return to[%s@0x%x]\n", name, dnpc);
        p += sprintf(p, "ret\n");
        ftrace_spcae_cnt--;
      }
    }
  }
}
void ftrace() {
  int i;
  for(i = 0; i <= ftrace_buf_idx; i++) {
    if(i != ftrace_buf_idx) printf("%s\n",ftrace_buf[i]);
    else printf("%s",ftrace_buf[i]);
  }
}
#endif
