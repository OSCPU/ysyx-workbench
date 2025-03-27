#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>  // Linux 环境中需要这个头文件来使用 sleep
//#include <riscv/riscv.h>
//#include "klib.h"
//#include "klib-macros.h"
#define UART_MMIO_ADDR  0xa00003f8  // 串口 MMIO 地址
#define RTC_MMIO_ADDR   0xa0000048  // 假设时钟地址为 0xa0000048
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"
//int seconds=0;
// memory.cpp
//#include "memory.h"

//bool skip_ref = false;  // 定义并初始化 skip_ref 变量
constexpr size_t MEMORY_SIZE = 4ULL * 1024 * 1024 * 1024;  // 4GB
class Memory {
public:
  //std::vector<uint8_t> memory(MEMORY_SIZE, 0);  // 以字节为单位的内存
	std::vector<uint8_t> memory;
     Memory() {
        memory.resize(MEMORY_SIZE , 0);  // 初始化内存，单位为4字节
    }
    uint32_t pmem_read(int raddr) {
   // uint32_t aligned_addr = raddr & ~0x3u;  // 4字节对齐
		 uint32_t aligned_addr = raddr ;
		 static uint64_t fast_rtc_time = 0;  // 维护一个"加速"时钟
static uint64_t last_real_time = 0;
		 extern uint32_t npc_skip;  // 声明 main.cpp 里的变量
    if (aligned_addr >= MEMORY_SIZE) {
        std::cerr << "Memory read error: address out of range!" << std::endl;
        return 0;
     }
   if (raddr == RTC_MMIO_ADDR||raddr == RTC_MMIO_ADDR+4) {
		 npc_skip=1;
 

        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
      uint64_t real_time = ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;  // 获
        uint64_t us = ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;  // 获取当前时间（微秒）
				  if (last_real_time == 0) {
            last_real_time = real_time;  // 初始化基准时间
        }

        // 让时钟变快，比如加速 10 倍
        fast_rtc_time += real_time - last_real_time;
        last_real_time = real_time;

        if (raddr == RTC_MMIO_ADDR) {
            return (uint32_t)fast_rtc_time;  // 低32位
        } else {
            return (uint32_t)(fast_rtc_time >> 32);  // 高32位
        }
       /* if (raddr == RTC_MMIO_ADDR) {
            return (uint32_t)us;  // 低32位
        } else {
            return (uint32_t)(us >> 32);  // 高32位
        }*/
    }

    // 其他 MMIO 或内存读取逻辑
  
    // 读取4个字节并组合成32位整数
    return memory[aligned_addr] | (memory[aligned_addr + 1] << 8) |
           (memory[aligned_addr + 2] << 16) | (memory[aligned_addr + 3] << 24);
}

void pmem_write(int waddr, int wdata, int wmask) {
//	printf("0x%8x, %x\n ",waddr,wdata);
    uint32_t aligned_addr = waddr ;  // 4字节对齐
    if (aligned_addr >= MEMORY_SIZE) {
        std::cerr << "Memory write error: address out of range!" << std::endl;
        return;
    }
		 if (waddr == UART_MMIO_ADDR || waddr == UART_MMIO_ADDR+4) {
		putchar((char)wdata);
       fflush(stdout);
		
				return;
    }
		if (wmask == 3) {  // SH 操作，要求地址 2 字节对齐
        aligned_addr = waddr & ~0x1u;  // 2 字节对齐
			//	printf("SH write operation: address=%d, data=%x, mask=%x\n", waddr, wdata, wmask);
		}
if (wmask == 15) {  // 要求地址 4 字节对齐
        aligned_addr = waddr & ~0x3u;  // 4字节对齐
		//		printf("SH write operation: address=%d, data=%x, mask=%x\n", waddr, wdata, wmask);
		}
	
    // 遍历 wmask 控制写入的字节
    for (int i = 0; i < 4; i++) {
        if (wmask & (1 << i)) {
uint8_t byte_to_write = (wdata >> (8 * i)) & 0xFF;
          //  printf("Writing Byte %d: 0x%02X to Address: 0x%X\n", i, byte_to_write, aligned_addr + i);
            memory[aligned_addr + i] = byte_to_write;
				//		printf("Writing Byte :%08x to Address: 0x%X\n",  memory[aligned_addr + i] , aligned_addr + i);

        }
    }
}

};

