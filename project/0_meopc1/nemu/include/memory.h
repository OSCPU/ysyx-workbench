#ifndef __MEMORY_H__
#define __MEMORY_H__
#include "common.h"
void init_mem();
uint8_t *guest_to_host(uint32_t addr);
void pp();
#endif