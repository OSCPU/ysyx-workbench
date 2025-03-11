#ifndef DISASM_H
#define DISASM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// dasm: 将机器码反汇编为汇编字符串
// asm_str: 用于存储反汇编结果的缓冲区
// size: 缓冲区大小
// inst: 32 位指令（二进制）
// pc: 指令的程序计数器（用于定位，可能影响符号解析）
void dasm(char *asm_str, int size, uint32_t inst, uint32_t pc);

#ifdef __cplusplus
}
#endif

#endif // DISASM_H

