#ifndef __TRACE_H__
#define __TRACE_H__

#include <common.h>

#define INST_NUM 16

// iringbuf
typedef struct {
    word_t pc;
    uint32_t inst;
} InstBuf;

// Function declarations
void trace_inst(word_t pc, uint32_t inst);
void display_inst();

#endif // __TRACE_H__

