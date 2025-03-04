#ifndef NPC_H
#define NPC_H

#include <stdint.h>
# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

/*static inline void npc_trap(int code) {
  __asm__ volatile (
    "mv a0,%0\n\t"  // 将code存入a0寄存器
    "ebreak"         // 触发断点
    :
    : "r"(code)      // 让编译器知道code是输入寄存器
    : "a0"           // 声明a0寄存器被修改
  );
}*/

#endif // NPC_H
