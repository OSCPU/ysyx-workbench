/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "utils.h"
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <elf.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

int scan_head_list();

// iringbuf
#define NR_IRINGBUF 32
#define LEN_IRINGBUF 64
static char iringbuf[NR_IRINGBUF][LEN_IRINGBUF] = {};
static int index_iringbuf;
#define next(index_iringbuf) ((index_iringbuf == NR_IRINGBUF - 1) ? 0 : index_iringbuf+1)
void init_iringbuf() {
  int i,j;
  for(i = 0; i < NR_IRINGBUF; i++) {
    for(j = 0; j < LEN_IRINGBUF; j++) {
      iringbuf[i][j] = '\0';
    }
  }
}
static void scan_iringbuf() {
  int i;
  for (i = 0; i < NR_IRINGBUF; i++) {
    if(strcmp(iringbuf[i],"") == 0) continue;
    else if(i == index_iringbuf) printf("--->\t%s\n",iringbuf[i]);
    else printf("\t%s\n",iringbuf[i]);
  }
}
// ftrace
static Elf32_Sym *symtab;
static char *strtab;
static Elf32_Shdr *symtab_shdr;
static Elf32_Shdr *strtab_shdr;

static char ftrace_stack[1024][128];
static int stack_indx;
static int stack_cnt;

void print_symbol_table(Elf32_Shdr *shdr, Elf32_Sym *symtab, char *strtab) {
  int i;
  printf("Function Table:\n");
  printf("Num:\tValue:\t\tSize:\tName:\n");
  for (i = 0; i < shdr->sh_size / sizeof(Elf32_Sym); i++) {
    Elf32_Sym *sym = &symtab[i];
    char *name = &strtab[sym->st_name];
    if(ELF32_ST_TYPE(sym->st_info) == 2)
      printf("%3d:\t%x\t%u\t%s\n", i, sym->st_value, sym->st_size, name);
  }
}
void ftrace_init(char *elf_name) {
  // open elf file
  char file_name[100] = "/home/wophere/ysyx-workbench/am-kernels/tests/cpu-tests/build/";
  strcat(file_name,elf_name);
  FILE *fp = fopen(file_name, "rb");
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
  print_symbol_table(symtab_shdr, symtab, strtab);

  // close elf file
  fclose(fp);

  // init ftrace_stack
  memset(ftrace_stack, '\0', sizeof(ftrace_stack));
}
void ftrace_once(Decode *s, vaddr_t dnpc) {
  //sprintf(ftrace_stack[stack_indx++], "0x%x:\tcall[ %s@0x%x ]\n", s->pc, "hello", dnpc);
  int i;
  char name_pre[32] = "";
  for (i = 0; i < symtab_shdr->sh_size / sizeof(Elf32_Sym); i++) {
    Elf32_Sym *sym = &symtab[i];
    char *name = &strtab[sym->st_name];
    if(stack_cnt == 0) stack_indx = 0;
    if(s->snpc != dnpc && strcmp(name,name_pre) && ELF32_ST_TYPE(sym->st_info) == 2 ) {
      if( dnpc == sym->st_value ) {
        stack_cnt++;
        //sprintf(ftrace_stack[stack_indx++], "0x%x:\tcall[ %s@0x%x ]\n", s->pc, name, dnpc);
        char *p = ftrace_stack[stack_indx++];
        p += sprintf(p,"0x%x:",s->pc);
        for(int j = 0; j < stack_cnt; j++) {
          p += sprintf(p, "  ");
        }
        p += sprintf(p, "call[%s@0x%x]\n", name, dnpc);
      }
      else if( dnpc > sym->st_value && dnpc < (sym->st_value + sym->st_size) ) {
        //sprintf(ftrace_stack[stack_indx++], "0x%x:\treturn[ %s@0x%x ]\n", s->pc, name, dnpc);
        char *p = ftrace_stack[stack_indx++];
        p += sprintf(p,"0x%x:",s->pc);
        for(int j = 0; j < stack_cnt; j++) {
          p += sprintf(p, "  ");
        }
        p += sprintf(p, "return[%s@0x%x]\n", name, dnpc);
        stack_cnt--;
      }
      strcpy(name_pre, name);
    }
  }
}
void ftrace() {
  int i;
  for(i = 0; i < stack_indx; i++) {
    printf("%s\n",ftrace_stack[i]);
  }
}

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

  //memset(iringbuf[index_iringbuf], '\0', LEN_IRINGBUF);
  strcpy(iringbuf[index_iringbuf],_this->logbuf);
  if(nemu_state.state != NEMU_RUNNING)
    scan_iringbuf();
  index_iringbuf = next(index_iringbuf);

  ftrace_once(_this, dnpc);

#ifdef CONFIG_WATCHPOINT
  if(scan_head_list()){ nemu_state.state = NEMU_STOP; }
#endif 
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    case NEMU_QUIT:
      statistic();
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
