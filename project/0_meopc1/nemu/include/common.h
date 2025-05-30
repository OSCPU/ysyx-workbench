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

typedef uint32_t word_t;
#define FMT_WORD "0x%08x"

typedef word_t vaddr_t;
typedef uint32_t paddr_t;
#define PMEM_LEFT  ((paddr_t)0x80000000)
#define RESET_VECTOR (PMEM_LEFT + 0)
//#include <debug.h>
#endif