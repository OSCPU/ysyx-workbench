#ifndef __RISCV64_REG_H__
#define __RISCV64_REG_H__

#include <common.h>

static inline int check_reg_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < 32));
  return idx;
}

static inline int check_csr_idx(uint32_t idx) 
{
  if(idx==0x305){
    return 0; //mtvec
  }
  else if(idx==0x342)
    return 3; //mcaurse
  else if(idx==0x300){
    return 2; //mstatus
  }
  else if(idx==0x341)
    return 1; //mepc
  Log("missing csr : 0x%x",idx);
  assert(0);
  return 0;
}

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])
#define csr(idx) (cpu.csr[check_csr_idx(idx)])

static inline const char* reg_name(int idx, int width) {
  extern const char* regs[];
  return regs[check_reg_idx(idx)];
}

#endif
