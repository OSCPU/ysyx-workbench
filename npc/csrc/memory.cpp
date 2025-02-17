#include <iostream>
#include <vector>
#include <cstdint>

constexpr size_t MEMORY_SIZE = 4ULL * 1024 * 1024 * 1024;  // 4GB

class Memory {
public:
    Memory() {
        memory.resize(MEMORY_SIZE / 4, 0);  // 初始化内存，单位为4字节
    }

    uint32_t read(uint32_t addr) {
        if (addr < MEMORY_SIZE) {
            return memory[addr / 4];  // 返回内存中的数据
        }
        std::cerr << "Memory read error: address out of range!" << std::endl;
        return 0;
    }

    void write(uint32_t addr, uint32_t data) {
        if (addr < MEMORY_SIZE) {
            memory[addr / 4] = data;
        } else {
            std::cerr << "Memory write error: address out of range!" << std::endl;
        }
    }

private:
    std::vector<uint32_t> memory;
};

