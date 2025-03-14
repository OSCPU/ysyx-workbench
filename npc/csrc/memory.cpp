#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdio>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"
constexpr size_t MEMORY_SIZE = 4ULL * 1024 * 1024 * 1024;  // 4GB

class Memory {
public:
    Memory() {
        memory.resize(MEMORY_SIZE / 4, 0);  // 初始化内存，单位为4字节
    }

    uint32_t read(uint32_t addr) {
        if (addr < MEMORY_SIZE) {
					// printf("read memory:0x%8x",addr);
            return memory[addr / 4];  // 返回内存中的数据
        }
        std::cerr << "Memory read error: address out of range!" << std::endl;
        return 0;
    }

    void write(uint32_t addr, uint32_t data) {
        if (addr < MEMORY_SIZE) {
            memory[addr / 4] = data;
// printf(BOLD YELLOW "Memory Write: " RESET 
  //             "Address: " BLUE "0x%08x" RESET 
    //           " Data: " GREEN "%08x\n" RESET, addr, data);
        } else {
            std::cerr << "Memory write error: address out of range!" << std::endl;
        }
    }

private:
    std::vector<uint32_t> memory;
};

