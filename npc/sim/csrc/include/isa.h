#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

#ifdef __riscv32_e
#define REG_LEN 16
#else
#define REG_LEN 32
#endif

typedef struct {
	word_t mcause;
	word_t mepc;
	word_t mstatus;
  word_t mtvec;
} riscv32_CSR;

typedef struct {
  word_t gpr[REG_LEN];
  vaddr_t pc;
  riscv32_CSR csr;
  vaddr_t npc;
}riscv32_CPU_state;

#endif
