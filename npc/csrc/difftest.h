#ifndef DIFFTEST_H
#define DIFFTEST_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
typedef uint32_t paddr_t;  // 如果你的地址宽度为32位
typedef uint32_t word_t;

// CPU_state 结构体，必须与 REF 保持一致
struct CPU_state {
  uint32_t gpr[32];
  uint32_t pc;
};

typedef void (*difftest_memcpy_t)(paddr_t, void *, size_t, bool);
typedef void (*difftest_regcpy_t)(void *, bool);
typedef void (*difftest_exec_t)(uint64_t);
typedef void (*difftest_raise_intr_t)(uint64_t);

// 定义 DIFFTEST_TO_REF 和 DIFFTEST_TO_DUT
#ifndef DIFFTEST_TO_REF
#define DIFFTEST_TO_REF true
#endif

#ifndef DIFFTEST_TO_DUT
#define DIFFTEST_TO_DUT false
#endif

// 假设 RESET_VECTOR 定义
#ifndef RESET_VECTOR
#define RESET_VECTOR 0x80000000
#endif

// 声明 guest_to_host 函数（你需要实现或包含该函数）
//extern void* guest_to_host(paddr_t addr);

#endif // DIFFTEST_H

