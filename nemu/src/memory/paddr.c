#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif
#ifdef CONFIG_MTRACE
char mtrace_buf[16][100]={0};
int mtrace_count=0;
#endif

// 虚拟地址为load/store在指令中访问处，物理地址指虚拟地址在实际内存中的映射
// 虚拟地址padder转换为物理地址的值
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
// 物理地址haddr转换为虚拟地址
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

#ifdef CONFIG_MTRACE
void print_mtrace(){
  printf("mtrace:\n");
  for(int i=0;i<16;i++)
  {
    if(strlen(mtrace_buf[i])==0) break;
    if((i+1)%16==mtrace_count) printf("-->");
    else printf("   ");
    printf("%s\n",mtrace_buf[i]);
  }
}
#endif
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  #ifdef CONFIG_MTRACE
  sprintf(mtrace_buf[mtrace_count],"read:  addr:%016x len:%02d content:%016lx",addr,len,ret);
  mtrace_count=(mtrace_count+1)%16;
#endif
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
  #ifdef CONFIG_MTRACE
  sprintf(mtrace_buf[mtrace_count],"write: addr:%016x len:%02d content:%016lx",addr,len,data);
  mtrace_count=(mtrace_count+1)%16;
#endif
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR ") at pc = " FMT_WORD,
      addr, CONFIG_MBASE, CONFIG_MBASE + CONFIG_MSIZE, cpu.pc);
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
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]",
      (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE);
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
