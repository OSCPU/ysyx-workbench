#include "config.h"
#include "debug.h"
#include "macro.h"
#include "paddr.h"
#include <common.h>

extern riscv32_CPU_state cpu;

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
uint8_t imem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return imem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - imem + CONFIG_MBASE; }

word_t pmem_read(paddr_t addr, int len) {
  word_t rdata = host_read(guest_to_host(addr), len);
  return rdata;
}

void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
#ifdef CONFIG_MEM_RANDOM
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }
#endif
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

extern "C" void paddr_read(int raddr, int *rdata) {
  if(likely(in_pmem(raddr))) {
    int len = 4;
    *rdata = pmem_read(raddr, len);
    IFDEF(CONFIG_MTRACE, printf("%s at " FMT_PADDR " len=%d data=" FMT_WORD "\n",ANSI_FMT("paddr  read", ANSI_FG_MAGENTA), raddr, len, *rdata));
    return;
  }
  //out_of_bound(raddr);
}

extern "C" void paddr_write(int waddr, int wdata, char wmask) {
  if(likely(in_pmem(waddr))) {
    int len;
    switch (wmask) {
      case 0x1: len = 1; break;
      case 0x3: len = 2; break;
      case 0xf: len = 4; break;
      default: assert(0);
    }
    pmem_write(waddr, len, wdata);
    IFDEF(CONFIG_MTRACE, printf("%s at " FMT_PADDR " len=%d data=" FMT_WORD "\n",ANSI_FMT("paddr write", ANSI_FG_MAGENTA), waddr, len, wdata));
    return;
  }
  out_of_bound(waddr);
}
#ifdef CONFIG_NATIVE_MEM
word_t paddr_read(paddr_t addr, int len) {
  if (1) {
  //if (likely(in_pmem(addr))) {
    IFDEF(CONFIG_MTRACE, printf("%s at " FMT_PADDR " len=%d data=" FMT_WORD "\n",ANSI_FMT("paddr  read", ANSI_FG_MAGENTA), addr, len, pmem_read(addr, len)));
    return pmem_read(addr, len);
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (1) {
  //if (likely(in_pmem(addr))) {
    IFDEF(CONFIG_MTRACE, printf("%s at " FMT_PADDR " len=%d data=" FMT_WORD "\n",ANSI_FMT("paddr write", ANSI_FG_MAGENTA), addr, len, data));
    pmem_write(addr, len, data); 
    return; 
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
#endif
