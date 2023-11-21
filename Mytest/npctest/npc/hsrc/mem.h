#ifndef MEM_H
#define MEM_H

uint32_t pmem_read(uint32_t &ad,int len);
uint32_t pc_read(uint32_t &pc);
void pmem_write(uint32_t &ad,int len ,uint32_t data);
void init_mem();

#endif

