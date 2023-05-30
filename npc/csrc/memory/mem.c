#include <common.h>
uint8_t pmem[MEM_SIZE];
bool is_skip_ref = false;

// 虚拟地址为load/store在指令中访问处，物理地址指虚拟地址在实际内存中的映射
// 虚拟地址padder转换为物理地址的值
uint8_t* guest_to_host(ll addr) {return pmem + addr - MEM_BASE; }//将指令地址转变为mem内的地址
// 物理地址haddr转换为虚拟地址
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + MEM_BASE; }

// pemm地址检查
static inline bool in_pmem(ll addr) {
  return (addr >= MEM_BASE) && (addr < (ll )MEM_BASE + MEM_SIZE);
}

// 地址越界检查
/*
static void out_of_bound(ll addr) {
  printf("地址越界%016llx pc=0x%016lx\n",addr,cpu_gpr[32]);
  //assert(0);
}
*/

void difftest_skip_ref() {
  is_skip_ref = true;
  //printf("difftest_skip_ref =");
}
//读mem
extern "C" void pmem_read(ll raddr, ll *rdata)
 {
   // pemm地址内操作
   if (likely(in_pmem(raddr))){
   uint8_t *pt = guest_to_host(raddr) + 7;
   ll ret = 0;
   for (int i = 0; i < 8; ++i) {
     ret = (ret << 8) | (*pt--);
   }
   *rdata = ret;
   return ;
   }
   //printf("pmem_read-,addr = %016llx  rdata = %016llx is_skip_ref= %d\n",raddr,*rdata,is_skip_ref);
   //printf("[Mimo - Read]: addr = %016llx data = %016llx\n", raddr, *rdata);
   //if(raddr == 0xa000004c) debug_exit(1);
   // mimo设备访问
    *rdata=mmio_read((paddr_t)(raddr),8);
    return;
    //printf("time-,%016llx\n",*rdata);

  // 地址越界检查
  //out_of_bound(raddr); return;
#ifdef CONFIG_MTRACE
	printf("[MTrace - Read]: addr = %016llx data = %016llx\n", raddr, ret);
#endif
 }
//写mem
extern "C" void pmem_write(ll waddr, ll wdata, char mask)
 {
#ifdef CONFIG_MTRACE
	printf("[MTrace - Write]: addr = %016llx, data = %016llx  mask = 0x%02x\n", waddr, wdata, (unsigned char)mask);
#endif

  // pemm地址内操作
  if (likely(in_pmem(waddr))){
  //if(waddr == (ll)a00003f8) printf("[MTrace - Write]: addr = %016llx, data = %016llx  mask = 0x%02x\n", waddr, wdata, (unsigned char)mask);
   uint8_t *pt = guest_to_host(waddr);
   for (int i = 0; i < 8; ++i) {
     if (mask & 1) *pt = (wdata & 0xff);
     wdata >>= 8, mask >>= 1, pt++;
   }
   return;
   }

  uint8_t wlen=8;
  switch((unsigned char)mask){
    case(0x01):wlen=1;
        break;
    case(0x03):wlen=2;
        break;
    case(0x0f):wlen=4;
        break;
    case(0xf0):wlen=4;
        break;
    case(0xff):wlen=8;
        break;
    default:{
      	printf("[MTrace - Write]: addr = %016llx, data = %016llx  mask = 0x%02x\n", waddr, wdata, (unsigned char)mask);
        printf("Inst wrong:wrong wmem len");
        assert(0);
    }
  }
  while ((mask & 0x1) == 0) {
    mask  = mask >> 1;
    waddr = waddr + 1;
    wdata = wdata >> 8;
} 
  //printf("[Mimo - Write]: addr = %016llx, data = %016llx  mask = 0x%02x\n", waddr, wdata, (unsigned char)mask);
  // mimo设备访问
    mmio_write((paddr_t)waddr,wlen,(uint64_t)wdata); 
    return;

  // 地址越界检查
  //out_of_bound(waddr); return;


 }

