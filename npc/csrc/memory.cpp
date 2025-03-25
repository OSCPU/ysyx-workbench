#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>  // Linux 环境中需要这个头文件来使用 sleep

//#include <riscv/riscv.h>
#include <klib.h>
#include <klib-macros.h>
#define UART_MMIO_ADDR  0xa00003f8  // 串口 MMIO 地址
#define RTC_MMIO_ADDR   0xa0000048  // 假设时钟地址为 0xa0000048
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"
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
    if (aligned_addr >= MEMORY_SIZE) {
        std::cerr << "Memory read error: address out of range!" << std::endl;
        return 0;
     }
   if (raddr == RTC_MMIO_ADDR) {

 struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
        uint32_t time_sec = (uint32_t)(ts.tv_sec);
				sleep(1);
        return time_sec;

    }

    // 其他 MMIO 或内存读取逻辑
  
    // 读取4个字节并组合成32位整数
    return memory[aligned_addr] | (memory[aligned_addr + 1] << 8) |
           (memory[aligned_addr + 2] << 16) | (memory[aligned_addr + 3] << 24);
} 

void pmem_write(int waddr, int wdata, int wmask) {
//	printf("%8x\n ",waddr);
    uint32_t aligned_addr = waddr ;  // 4字节对齐
    if (aligned_addr >= MEMORY_SIZE) {
        std::cerr << "Memory write error: address out of range!" << std::endl;
        return;
    }
		 if (waddr == UART_MMIO_ADDR) {
			// printf("skdandoasn");
			// printf("%c",(char)wdata);
        putchar(wdata);  // 发送数据到终端
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
   /* uint32_t read(uint32_t addr) {
        if (addr+3 < MEMORY_SIZE) {
					// printf("read memory:0x%8x",addr);
            return memory[addr / 4];  // 返回内存中的数据
        }
        std::cerr << "Memory read error: address out of range!" << std::endl;
        return 0;
    }*/
	/*	uint8_t read_byte(uint32_t addr) {
    if (addr < MEMORY_SIZE) {
			uint32_t word = memory[addr / 4];
      uint8_t byte = (word >> (8 * (addr % 4))) & 0xFF;  // 提取目标字节  
			return byte;  // 扩展为 32 位无符号整数
    }
    std::cerr << "Memory read error: address out of range!" << std::endl;
    return 0;
}*/

   /* void write(uint32_t addr, uint32_t data) {
        if (addr % 4 != 0) {
        std::cerr << "Memory write error: Address must be 4-byte aligned!" << std::endl;
        return; // 终止写入
    } 
		 	if (addr < MEMORY_SIZE) {
            memory[addr / 4] = data;
 printf(BOLD YELLOW "Memory Write: " RESET 
               "Address: " BLUE "0x%08x" RESET 
               " Data: " GREEN "%08x\n" RESET, addr, data);
        } else {
            std::cerr << "Memory write error: address out of range!" << std::endl;
        }
    }*/

//private:
 //   std::vector<uint32_t> memory;
};

