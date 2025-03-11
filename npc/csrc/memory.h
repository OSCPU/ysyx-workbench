// memory.h
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int mem_read(uint32_t addr, uint32_t *data);

#ifdef __cplusplus
}
#endif

#endif

