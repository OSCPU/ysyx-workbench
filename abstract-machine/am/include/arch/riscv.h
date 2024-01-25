#ifndef ARCH_H__
#define ARCH_H__

struct Context {
#ifdef __riscv_e
  uintptr_t gpr[16], mcause, mstatus, mepc;
#else
  uintptr_t gpr[32], mcause, mstatus, mepc;
#endif
  void *pdir;
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#endif
