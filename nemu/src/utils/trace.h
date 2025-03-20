#ifndef __TRACE_H__
#define __TRACE_H__

#include <common.h>
#include <device/map.h>
#define INST_NUM 16

// iringbuf
typedef struct {
    word_t pc;
    uint32_t inst;
} InstBuf;

// Function declarations
void trace_inst(word_t pc, uint32_t inst);
void display_inst();
void display_memory_read(paddr_t addr, int len);
void display_memory_write(paddr_t addr, int len, word_t data);
void display_call_func(word_t pc, word_t func_addr);
void display_ret_func(word_t pc);
void display_device_read(paddr_t addr, int len, IOMap *map);
void display_device_write(paddr_t addr, int len, word_t data, IOMap *map);
#endif // __TRACE_H__

