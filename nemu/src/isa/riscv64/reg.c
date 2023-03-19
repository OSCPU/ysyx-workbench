#include <isa.h>
#include "local-include/reg.h"
const int reg_nums=32;
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
  printf("pc is %lx\n\n",cpu.pc);
  for(int i=0;i<reg_nums;i++){
    printf("%s is %lx\n",reg_name(i,64),gpr(i));
  }
}
word_t isa_reg_str2val(const char *s, bool *success) {
    
  for (int i = 0; i < reg_nums; i++){
    if (strcmp(reg_name(i,64), s+1) == 0){
      *success = true;
      Log("the reg is %s patch %s Now is %s and num is %lu",s,s+1,reg_name(i,64),gpr(i));
      return gpr(i);
    }
  }

  *success = false;
  return -1;
}
