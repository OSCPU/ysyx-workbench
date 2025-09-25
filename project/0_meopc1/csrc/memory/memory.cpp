#include "../include/memory.h"
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include "../include/common.h"

extern "C" {
	#include <sys/time.h>
}

#define PG_ALIGN __attribute((aligned(4096)))
static uint8_t *pmem = NULL;
static uint8_t *img = NULL;

FILE *mtrace_Write;
static uint64_t boot_time = 0;
void init_mem(size_t size){ 
	pmem = (uint8_t *)malloc(size * sizeof(uint8_t));
	//memcpy(pmem , img , sizeof(img));
	if(pmem == NULL){exit(0);}
	//Log("npc physical mrom area [%#x, %#lx]",RESET_VECTOR, RESET_VECTOR + size * sizeof(uint8_t));
}

uint8_t* guest_to_host(uint32_t paddr) { 
    return pmem + (uintptr_t)(paddr - 0x80000000); 
}

int ix = 0;
void write_addr(uint32_t paddr, uint32_t data, int size) {
	if(paddr == 0xa00003f8){
		putchar(data);
		//printf("write_addr: paddr = %x, data = %x, size = %d\n", paddr, data, size);
		return;
	}
	// printf("write_addr: paddr = %x, data = %x, size = %d\n", paddr, data, size);
	if(MTRACE){
		mtrace_Write=fopen("outputs/mtrace.txt","a");
		fprintf(mtrace_Write, "write   %x\n", paddr);
		fclose(mtrace_Write);
	} 
	// printf("write_addr: paddr = %x\n", paddr);
	// if(paddr < 0x80000000 || paddr >= 0x8fffffff){
	// 	return;
	// }
	for(int i = 0; i < size; i++){
		(pmem)[paddr - RESET_VECTOR  + i] = BITS(data, (i + 1) * 8 - 1 , i * 8);
	}
	return; 
}

int is_S(int x){ //存字节指令判断
	uint32_t high = (x >> 12) & 0b111;      // 提取14~12位
    uint32_t low = x & 0b1111111;           // 提取6~0位
    uint32_t result = (high << 7) | low;
	switch (result)
	{
		case 291:
			return 1;
			break;
		case 163:
			return 2;
			break;
		case 35:
			return 3;
			break;
		default:
			return 0;
			break;
	}
}

int is_L(int x){ //取字节指令判断

	uint32_t high = (x >> 12) & 0b111;      // 提取14~12位
    uint32_t low = x & 0b1111111;           // 提取6~0位
    uint32_t result = (high << 7) | low;
	if (result == 259){
		return 1;
	}
	if (result == 515){
		return 2;
	}
	if (result == 131){
		return 3;
	}
	if (result == 643){
		return 4;
	}
	if (result == 3){
		return 5;
	}
	else{
		return 0;
	}
}
static uint64_t get_time_internal() {
	struct timeval now;
	gettimeofday(&now, NULL);
	uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
	return us;
}
uint64_t get_time() {
	if (boot_time == 0) boot_time = get_time_internal();
	uint64_t now = get_time_internal();
	return now - boot_time;
}
svBitVecVal mem_data_read(const svBitVecVal* w_mask, const svBitVecVal* addr){
	int mem_addr, mem_data;
	mem_addr = *addr;
	if(*w_mask == 0){
		return 0; // 如果不是取字节指令，返回0
	}
	if(MTRACE){
		if(ix % 6 == 0){
			mtrace_Write=fopen("outputs/mtrace.txt","a");
			fprintf(mtrace_Write, "read    %x\n", mem_addr);
			fclose(mtrace_Write);
		}
		ix = ix + 1;
	} 
	if(mem_addr == 0xa0000048 || mem_addr == 0xa000004C){
		uint64_t time_now = get_time();
		if(mem_addr == 0xa0000048){
			return (uint32_t)(time_now & 0xFFFFFFFFu);
		}
		return (uint32_t)(time_now >> 32);
	}
	// printf("mem_addr = %x\n", mem_addr);
	if(mem_addr < 0x80000000 || mem_addr >= 0x8fffffff)
		return 0;
	// printf("mem_addr = %x\n", mem_addr);
	switch (*w_mask)
	{
		case 1:
			//printf("read addr = %x\n", mem_addr);	
			mem_data =  (static_cast<uint8_t>(guest_to_host(0)[mem_addr + 3]) << 24) |
						(static_cast<uint8_t>(guest_to_host(0)[mem_addr + 2]) << 16) |
						(static_cast<uint8_t>(guest_to_host(0)[mem_addr + 1]) << 8)  |
						 static_cast<uint8_t>(guest_to_host(0)[mem_addr    ]);
			return mem_data;
			break;
		case 2:
			mem_data =  (static_cast<uint8_t>(0 << 24)) |
						(static_cast<uint8_t>(0 << 16)) |
						(static_cast<uint8_t>(0 <<  8))  |
						 static_cast<uint8_t>(guest_to_host(0)[mem_addr    ]);
			// printf("-----%x  %x  %x-----\n",*rs1_data_in, mem_addr, mem_data);
			return mem_data;
			break;
		case 3:
			mem_data = SEXT((int64_t)((static_cast<uint8_t>(guest_to_host(0)[mem_addr + 1]) <<  8)|static_cast<uint8_t>(guest_to_host(0)[mem_addr])), 16);
			//printf("-----%x  %x  %x-----\n",guest_to_host(RESET_VECTOR)[mem_addr + 1], guest_to_host(RESET_VECTOR)[mem_addr], mem_data);
			return mem_data;
			break;
		case 5:
			mem_data = SEXT((int64_t)(static_cast<uint8_t>(guest_to_host(0)[mem_addr])), 8);
			//printf("-----%x  %x  %x-----\n",guest_to_host(RESET_VECTOR)[mem_addr + 1], guest_to_host(RESET_VECTOR)[mem_addr], mem_data);
			return mem_data;
			break;
		case 4:
			mem_data =  (static_cast<uint8_t>(0 << 24)) |
						(static_cast<uint8_t>(0 << 16)) |
						(static_cast<uint8_t>(guest_to_host(0)[mem_addr + 1]) << 8)  |
						 static_cast<uint8_t>(guest_to_host(0)[mem_addr    ]);
			//printf("-----%x  %x  %x-----\n",*rs1_data_in, *imm_data_in, mem_data);
			return mem_data;
			break;
		default:
			return 0; // 如果不是取字节指令，返回0
			break;
	}
}
