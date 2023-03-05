#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// 打印寄存器的值
void isa_reg_display() {
    for (int i = 0; i < 32; i++){
        printf("%s:%lx", *(regs + i),cpu.gpr[i]);
        printf((i + 1) % 4 == 0 ?"\n":" ");
    }
}
// 通过名字获取寄存器的值
word_t isa_reg_str2val(const char *s, bool *success) {
    for (int i =0; i<32;i++){
        if(strcmp(regs[i],s) == 0){
            *success = true;
            printf("%s:%lx", *(regs + i),cpu.gpr[i]);
            return cpu.gpr[i];
        }
    }
    if (s[0] == 'p' && s[1] == 'c') {
        *success = true;
        return cpu.pc;
    }
    else printf("reg 匹配失败!");
    *success = false;
    return 0;
}
