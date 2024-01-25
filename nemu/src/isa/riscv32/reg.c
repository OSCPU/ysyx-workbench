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

#include <isa.h>
#include "common.h"
#include "debug.h"
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  int i;
  printf("%s\n",ANSI_FMT("ISA RegFile Display", ANSI_FG_GREEN));
  for (i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    printf("%2d\t%-3s\t%#8x%15d\n",i, regs[i], cpu.gpr[i], cpu.gpr[i]);
  }
  printf("pc = %#x\n",cpu.pc);
  printf("mcause = %#x\n", cpu.csr.mcause);
  printf("mstatus = %#x\n", cpu.csr.mstatus);
  printf("mepc = %#x\n", cpu.csr.mepc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if(strcmp(s, "pc") == 0){
    return cpu.pc;
  } else if (strcmp(s, "mcause") == 0) {
    return cpu.csr.mcause;
  } else if (strcmp(s, "mepc") == 0) {
    return cpu.csr.mepc;
  } else if (strcmp(s, "mstatus") == 0) {
    return cpu.csr.mstatus;
  } else if (strcmp(s, "mtvec") == 0) {
    return cpu.csr.mtvec;
  } else{
    return cpu.gpr[check_reg_idx(atoi(s))];
  }
}

const char *isa_reg_val2str(int i) {
  return regs[check_reg_idx(i)];
}

const char* csrs[] = {
  "mstatus","mtvec","mepc","mcause"
};

vaddr_t *isa_csr(int addr) {
  switch (addr) {
    case 0x300:
      return &(cpu.csr.mstatus);
    case 0x305:
      return &(cpu.csr.mtvec);
    case 0x341:
      return &(cpu.csr.mepc);
    case 0x342:
      return &(cpu.csr.mcause);
    default:
      panic("ERROR: Invalid CSR addr");
  }
}

word_t isa_csr_fetch(int addr) {
  switch (addr) {
    case 0x300:
      return cpu.csr.mstatus;
    case 0x305:
      return cpu.csr.mtvec;
    case 0x341:
      return cpu.csr.mepc;
    case 0x342:
      return cpu.csr.mcause;
    default:
      panic("ERROR: Invalid CSR addr");
  }
}

int isa_csr_str2addr(char *s) {
  if (strcmp(s, "mstatus") == 0)
    return 0x300;
  else if (strcmp(s, "mtvec") == 0)
    return 0x305;
  else if (strcmp(s, "mepc") == 0)
    return 0x341;
  else if (strcmp(s, "mcause") == 0)
    return 0x342;
  else
    panic("ERROR: Invalid CSR addr");
}
