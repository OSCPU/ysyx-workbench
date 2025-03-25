#ifndef NPC_H
#define NPC_H

#include <stdint.h>

static inline void npc_trap(int code) {
  __asm__ volatile (
    "mv a0, %0\n\t"  // 将code存入a0寄存器
    "ebreak"         // 触发断点
    :
    : "r"(code)      // 让编译器知道code是输入寄存器
    : "a0"           // 声明a0寄存器被修改
  );
}

// 定义 MMIO 基地址
#define DEVICE_BASE  0xa0000000
#define MMIO_BASE    DEVICE_BASE

// 串口、时钟等 MMIO 设备地址定义
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)  // 串口地址
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)  // 键盘地址
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)  // 实时时钟地址
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)  // VGA 控制器地址
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)  // 音频地址
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)  // 磁盘地址
#define FB_ADDR         (MMIO_BASE   + 0x1000000)  // 帧缓冲区基地址
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)  // 音频缓冲区地址

// 物理内存范围
extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024) // 128MB
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

// NPC 的物理地址范围
#define NPC_PADDR_SPACE \
  RANGE(&_pmem_start, PMEM_END), \
  RANGE(FB_ADDR, FB_ADDR + 0x200000), \
  RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* serial, rtc, screen, keyboard */

typedef uintptr_t PTE;

#define PGSIZE  4096
#endif // NPC_H
