#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>


#if   defined(CONFIG_TARGET_AM)
static uint8_t *pmem = NULL;
#else
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

// extern paddr_t m_tra[M_TRACEL];
// extern int m_len[M_TRACEL];
// extern int m_cnt;
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

void init_mem() {
#if   defined(CONFIG_TARGET_AM)
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
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]",
      (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE);
}

word_t paddr_read(paddr_t addr, int len) {
  #ifdef CONFIG_MTRACE
    if (likely(in_pmem(addr))){
      word_t w = pmem_read(addr, len);
        Log(" Read  from memory at %#.8x for %d bytes for %x.", addr, len, (unsigned)w);
    }
  #endif
  // m_tra[m_cnt]=addr;
  // m_len[m_cnt]=len;
  // m_cnt++;
  // m_cnt%=M_TRACEL;
  if (likely(in_pmem(addr))) {
    return pmem_read(addr, len);
  }
  // for(int i=(m_cnt+1)%M_TRACEL;i!=(m_cnt)%M_TRACEL;i++,(i)%=M_TRACEL){
  //   Log(" Read  from memory at %#.8x for %d bytes for %x.", m_tra[i], m_len[i], (unsigned)pmem_read(m_tra[i], m_len[i]));
  // }
  
  MUXDEF(CONFIG_DEVICE, return mmio_read(addr, len),
    panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR ") at pc = " FMT_WORD,
      addr, CONFIG_MBASE, CONFIG_MBASE + CONFIG_MSIZE, cpu.pc));
}

void paddr_write(paddr_t addr, int len, word_t data) {
  #ifdef CONFIG_MTRACE
      Log("Write %x to memory at %#.8x for %d bytes.", (unsigned)data, addr, len);
    #endif
  if (likely(in_pmem(addr))) { 
    pmem_write(addr, len, data); 
    return; }
  MUXDEF(CONFIG_DEVICE, mmio_write(addr, len, data),
    panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR ") at pc = " FMT_WORD,
      addr, CONFIG_MBASE, CONFIG_MBASE + CONFIG_MSIZE, cpu.pc));
}
