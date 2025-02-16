#include <iostream>
#include <vector>

class Memory {
public:
    std::vector<uint32_t> memory;

    Memory(size_t size) : memory(size, 0) {}

    uint32_t read(uint32_t addr) {
        return memory[addr / 4];  // 4字节对齐
    }

    void write(uint32_t addr, uint32_t data) {
        memory[addr / 4] = data;
    }
};

// 使用方法
Memory pmem(1024);  // 创建一个1024字节的内存

uint32_t pmem_read(uint32_t addr) {
    return pmem.read(addr);
}

void pmem_write(uint32_t addr, uint32_t data) {
    pmem.write(addr, data);
}

