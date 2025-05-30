#ifndef __COMMOM_H__
#define __COMMOM_H__
//#include <macro.h>

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <assert.h>
#include <stdlib.h>
#include <getopt.h>
#include <cstdint>

#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "svdpi.h"
#include "verilated_fst_c.h"
#include "verilated_vcd_c.h"

#include "autoconf.h"
#include "macro.h"

// typedef uint32_t word_t;
// #define FMT_WORD "0x%08x"

// typedef word_t vaddr_t;
// typedef uint32_t paddr_t;
#define PMEM_LEFT  ((paddr_t)0x80000000)
#define RESET_VECTOR (PMEM_LEFT + 0)
//#include <debug.h>

#define ITRACE 1
#define FTRACE 0
#define MTRACE 0

typedef uint32_t word_t;
typedef int32_t  sword_t;
#define FMT_WORD "0x%08"

typedef word_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_PADDR "0x%08"
typedef uint16_t ioaddr_t;

#include "debug.h"

#endif