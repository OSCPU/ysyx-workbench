#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<cstdint>
#include<unistd.h>
#include"../hsrc/mem.h"

static long load_img();
static uint8_t pmem[0x8000000] __attribute((aligned(4096)))={};
static uint32_t img[]
{
	0x00110123,
	0x00110008,
	0x00100073, //ebreak
};

void init_mem()
{

	//long size=load_img();

	memcpy(pmem,img,sizeof(img));

	/*   print the pmem
	uint32_t b=0x80000000;
	int i=0;
	for(i=0;i<(size-1)/4;i++)
	{
		printf("%x\n",pmem_read(b,4));
		b=b+0x4;
	}
	*/
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
uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

static long load_img(){
   char *img_file=(char*)IMG;
   if (img_file == NULL) {
     printf("No image is given. Use the default build-in image.");
     return 4096; // built-in image size
   }           
               
   FILE *fp = fopen(img_file, "rb");
   //assert(fp==NULL);
               
   fseek(fp, 0, SEEK_END);
   long size = ftell(fp);
               
   printf("the size =%ld\n",size);           
   fseek(fp, 0, SEEK_SET);
   int ret = fread(guest_to_host(0x80000000), size, 1, fp);
   assert(ret == 1);
               
   fclose(fp); 
   return size;
}
