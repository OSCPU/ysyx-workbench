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

int wp_display();

// iringbuf
#ifdef CONFIG_IRINGBUF

#define NR_IRINGBUF 32
#define LEN_IRINGBUF 64
#define iringbuf_next_index(iringbuf_index) ((iringbuf_index == NR_IRINGBUF - 1) ? 0 : iringbuf_index+1)

static char iringbuf[NR_IRINGBUF][LEN_IRINGBUF] = {};
static int  iringbuf_index;

void iringbuf_trace(Decode *_this) {
  strcpy(iringbuf[iringbuf_index],_this->logbuf);
  iringbuf_index = iringbuf_next_index(iringbuf_index);
}
void iringbuf_display() {
  int i;
  printf("%s\n",ANSI_FMT("Most Recently Used Instructions:", ANSI_FG_CYAN));
  for (i = 0; i < NR_IRINGBUF; i++) {
    if(strcmp(iringbuf[i],"") == 0) continue;
    else if(i == iringbuf_index) printf("--->\t%s\n",iringbuf[i]);
    else printf("\t%s\n",iringbuf[i]);
  }
}

#endif /* ifdef CONFIG_IRINGBUF */

// ftrace
#ifdef CONFIG_FTRACE

static Elf32_Sym *symtab;
static char *strtab;
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
void ftrace_init(char *elf_name) {
  // open elf file
  FILE *fp = fopen(elf_name, "rb");
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
void ftrace_once(Decode *s, vaddr_t dnpc) {
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
      if(!(s->pc >= sym->st_value && s->pc < (sym->st_value + sym->st_size)) && dnpc == sym->st_value ) { // function call
        //sprintf(ftrace_stack[stack_indx++], "0x%x:\tcall[ %s@0x%x ]\n", s->pc, name, dnpc);
        ftrace_buf_idx++;
        ftrace_spcae_cnt++;
        char *p = ftrace_buf[ftrace_buf_idx];
        p += sprintf(p,"0x%x:",s->pc);
        for(int j = 0; j < ftrace_spcae_cnt; j++) {
          p += sprintf(p, "  ");
        }
        p += sprintf(p, "call[%s@0x%x]\n", name, dnpc);
      }
      else if(!(s->pc >= sym->st_value && s->pc < (sym->st_value + sym->st_size)) && dnpc > sym->st_value && dnpc < (sym->st_value + sym->st_size) ) { //function return
        //sprintf(ftrace_stack[stack_indx++], "0x%x:\treturn[ %s@0x%x ]\n", s->pc, name, dnpc);
        ftrace_buf_idx++;
        char *p = ftrace_buf[ftrace_buf_idx];
        p += sprintf(p,"0x%x:",s->pc);
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

#endif /* ifdef CONFIG_FTRACE */

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif /* ifdef  */

#ifdef CONFIG_WATCHPOINT
  if(wp_display()){ nemu_state.state = NEMU_STOP; }
#endif 

  IFDEF(CONFIG_IRINGBUF, iringbuf_trace(_this));
  IFDEF(CONFIG_FTRACE, ftrace_once(_this, dnpc));

  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
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
  IFDEF(CONFIG_FTRACE, ftrace());
  IFDEF(CONFIG_IRINGBUF, iringbuf_display());
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
