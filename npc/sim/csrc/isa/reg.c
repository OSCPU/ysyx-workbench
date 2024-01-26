#include <common.h>

#ifdef CONFIG_RVE
const char *regs[] = {"$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"};
#else
const char *regs[] = {"$0", "ra", "sp",  "gp",  "tp", "t0", "t1", "t2",
                      "s0", "s1", "a0",  "a1",  "a2", "a3", "a4", "a5",
                      "a6", "a7", "s2",  "s3",  "s4", "s5", "s6", "s7",
                      "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};
#endif

void isa_reg_display() {
  int i;
  printf("%s\n", ANSI_FMT("ISA RegFile Display", ANSI_FG_GREEN));
  for (i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    printf("%2d\t%-3s\t%#8x%15d\n", i, regs[i], cpu.gpr[i], cpu.gpr[i]);
  }
  printf("pc      = %#x\n", cpu.pc);
  printf("mcause  = %#x\n", cpu.csr.mcause);
  printf("mepc    = %#x\n", cpu.csr.mepc);
  printf("mstatus = %#x\n", cpu.csr.mstatus);
  printf("mtvec   = %#x\n", cpu.csr.mtvec);
}

word_t isa_reg_str2val(const char *s) {
  if (strcmp(s, "pc") == 0) {
    return cpu.pc;
  } else if (strcmp(s, "mcause") == 0) {
    return cpu.csr.mcause;
  } else if (strcmp(s, "mepc") == 0) {
    return cpu.csr.mepc;
  } else if (strcmp(s, "mstatus") == 0) {
    return cpu.csr.mstatus;
  } else if (strcmp(s, "mtvec") == 0) {
    return cpu.csr.mtvec;
  } else {
    return cpu.gpr[check_reg_idx(atoi(s))];
  }
}