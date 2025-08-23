#ifndef __MEMORY_H__
#define __MEMORY_H__
#include "common.h"
#define REGNUM 32
void init_mem();
uint8_t *guest_to_host(uint32_t addr);
void write_addr(uint32_t paddr, uint32_t data);
void pp();
#endif