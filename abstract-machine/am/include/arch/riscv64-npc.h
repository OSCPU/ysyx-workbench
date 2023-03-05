#ifndef ARCH_H__
#define ARCH_H__

struct Context {
  // TODO: fix the order of these members to match trap.S
  uintptr_t gpr[32],mcause, mstatus, mepc  ;
};

#define GPR1 gpr[17] // a7
#define GPR2 gpr[10]//根据syscall.c中对gpr宏的分配得来2-4
#define GPR3 gpr[11]
#define GPR4 gpr[12]
#define GPRx gpr[10]/* 根据man syscall的说法，返回值是a0  */
#endif
