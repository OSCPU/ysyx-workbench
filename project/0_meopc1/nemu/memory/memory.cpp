#include "include/memory.h"
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#define PG_ALIGN __attribute((aligned(4096)))
static uint8_t *pmem = NULL;
static uint8_t *img = NULL;


void init_mem(size_t size){ 
	pmem = (uint8_t *)malloc(size * sizeof(uint8_t));
	memcpy(pmem , img , sizeof(img));
	if(pmem == NULL){exit(0);}
	//Log("npc physical mrom area [%#x, %#lx]",RESET_VECTOR, RESET_VECTOR + size * sizeof(uint8_t));
}

uint8_t* guest_to_host(uint32_t paddr) { 
    return pmem + (uintptr_t)(paddr - 0x80000000); 
}

void pp(){
    printf("11111\n");
    return ;
}
