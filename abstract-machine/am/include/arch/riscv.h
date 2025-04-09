#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
  // TODO: fix the order of these members to match trap.S
//  uintptr_t mepc, mcause, gpr[NR_REGS], mstatus;
	 uintptr_t gpr[NR_REGS];   // 先保存通用寄存器
  uintptr_t mcause;         // 然后是异常原因
  uintptr_t mstatus;        // 然后是机器状态
  uintptr_t mepc;           // 最后是异常返回地址
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
