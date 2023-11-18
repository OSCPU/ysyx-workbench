#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<cstdint>
#include"../hsrc/mem.h"


static uint8_t pmem[0x8000000] __attribute((aligned(4096)))={};
static uint32_t img[]
{
	0x00110123,
	0x00100010,
};

void init_mem()
{

	memcpy(pmem,img,sizeof(img));
}


uint32_t pc_read(uint32_t &pc)
{
	uint32_t val=pmem_read(pc,4);
	return val;
}
uint32_t pmem_read(uint32_t &ad,int len)
{
        uint8_t *addr =pmem+ad-0x80000000;
	switch(len){
	case 1: return *(uint8_t *)addr;
	case 2: return *(uint16_t *)addr;
	case 4: return *(uint32_t *)addr;
	default:
	{ assert(0); printf("pmem_read error\n");   return 0;}
	}
}


void pmem_write(uint32_t &ad, int len, uint32_t data)
{
  	uint8_t *addr =pmem+ad-0x80000000;
  	switch (len) {
          case 1: *(uint8_t  *)addr = data; return;
    	  case 2: *(uint16_t *)addr = data; return;
    	  case 4: *(uint32_t *)addr = data; return;
    	  default:
	  { assert(0); printf("pmem_write error\n");   }
	}

   

}

