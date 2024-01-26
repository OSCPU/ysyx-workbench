#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

typedef struct {
	word_t mcause;
	word_t mepc;
	word_t mstatus;
  word_t mtvec;
} riscv32_CSR;

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  riscv32_CSR csr;
  vaddr_t npc;
}riscv32_CPU_state;

extern riscv32_CPU_state cpu;

#endif
