#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <macro.h>

#include <assert.h>
#include <stdlib.h>

typedef uint64_t word_t;
typedef int64_t  sword_t;
#define FMT_WORD "0x%016lx"

typedef word_t   vaddr_t;
typedef uint64_t paddr_t;
#define FMT_PADDR "0x%016lx"
typedef uint16_t ioaddr_t;

#include <debug.h>
#include <utils.h>
#include <device.h>

// 相关库
#include <cstdio>
// Verilator with trace
#include "Vtop.h"
#include <verilated.h>
#include <verilated_vcd_c.h>    

// DPI-C
#include <svdpi.h>
#include <Vtop__Dpi.h>
#include <verilated_dpi.h>
// Difftest
#include <dlfcn.h>
// config
#include <config.h>
// =============== Memory ===============
typedef long long ll;
#define MEM_BASE 0x80000000
#define MEM_SIZE 0x08000000
static long long img_size = 0;

extern bool is_skip_ref;
extern uint64_t *cpu_gpr;
// ========================= Environment =========================
static Vtop *dut = new Vtop;   //将top设置为全局变量
static VerilatedVcdC *m_trace = new VerilatedVcdC; //波形跟踪时需设置全局变量　m_trace

extern uint8_t pmem[];
//颜色
#define COLOR_RED     "\33[1;31m"
#define COLOR_GREEN   "\33[1;32m"
#define COLOR_NONE    "\33[0m"

uint8_t* guest_to_host(ll addr);
extern "C" void disassemble(char *str, uint64_t pc, uint8_t *code, int nbyte);
extern "C" void init_disasm(const char *triple);
extern "C" void debug_exit(int status);
uint64_t get_time();

#endif
