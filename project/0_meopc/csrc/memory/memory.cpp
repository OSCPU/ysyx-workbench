#include "../include/memory.h"
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#define PG_ALIGN __attribute((aligned(4096)))
static uint8_t *pmem = NULL;
static uint8_t *img = NULL;

FILE *mtrace_Write;

void init_mem(size_t size){ 
	pmem = (uint8_t *)malloc(size * sizeof(uint8_t));
	//memcpy(pmem , img , sizeof(img));
	if(pmem == NULL){exit(0);}
	//Log("npc physical mrom area [%#x, %#lx]",RESET_VECTOR, RESET_VECTOR + size * sizeof(uint8_t));
}

uint8_t* guest_to_host(uint32_t paddr) { 
    return pmem + (uintptr_t)(paddr - 0x80000000); 
}

void write_addr(uint32_t paddr, uint32_t data, int size) {
	if(MTRACE){
		mtrace_Write=fopen("outputs/mtrace.txt","a");
		fprintf(mtrace_Write, "write   %x\n", paddr);
		fclose(mtrace_Write);
	} 
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
	else{
		return 0;
	}
}

svBitVecVal mem_data_read(const svBitVecVal* instruction_in, const svBitVecVal* rs1_data_in, const svBitVecVal* rs2_data_in, const svBitVecVal*  imm_data_in){
	int mem_addr, mem_data;
	switch (is_L(*instruction_in))
	{
		case 1:
			mem_addr = *rs1_data_in + *imm_data_in;
			if(MTRACE){
				mtrace_Write=fopen("outputs/mtrace.txt","a");
				fprintf(mtrace_Write, "read    %x\n", mem_addr);
				fclose(mtrace_Write);
			} 
			mem_data =  (static_cast<uint8_t>(guest_to_host(0)[mem_addr + 3]) << 24) |
						(static_cast<uint8_t>(guest_to_host(0)[mem_addr + 2]) << 16) |
						(static_cast<uint8_t>(guest_to_host(0)[mem_addr + 1]) << 8)  |
						 static_cast<uint8_t>(guest_to_host(0)[mem_addr    ]);
			return mem_data;
			break;
		case 2:
			mem_addr = *rs1_data_in + *imm_data_in;
			if(MTRACE){
				mtrace_Write=fopen("outputs/mtrace.txt","a");
				fprintf(mtrace_Write, "read    %x\n", mem_addr);
				fclose(mtrace_Write);
			} 
			mem_data =  (static_cast<uint8_t>(0 << 24)) |
						(static_cast<uint8_t>(0 << 16)) |
						(static_cast<uint8_t>(0 <<  8))  |
						 static_cast<uint8_t>(guest_to_host(0)[mem_addr    ]);
			//printf("-----%x  %x  %x-----\n",*rs1_data_in, *imm_data_in, mem_data);
			return mem_data;
			break;
		case 3:
			mem_addr = *rs1_data_in + *imm_data_in;
			if(MTRACE){
				mtrace_Write=fopen("outputs/mtrace.txt","a");
				fprintf(mtrace_Write, "read    %x\n", mem_addr);
				fclose(mtrace_Write);
			} 
			mem_data = SEXT((int64_t)((static_cast<uint8_t>(guest_to_host(0)[mem_addr + 1]) <<  8)|static_cast<uint8_t>(guest_to_host(0)[mem_addr])), 16);
			//printf("-----%x  %x  %x-----\n",guest_to_host(RESET_VECTOR)[mem_addr + 1], guest_to_host(RESET_VECTOR)[mem_addr], mem_data);
			return mem_data;
			break;
		case 4:
			mem_addr = *rs1_data_in + *imm_data_in;
			if(MTRACE){
				mtrace_Write=fopen("outputs/mtrace.txt","a");
				fprintf(mtrace_Write, "read    %x\n", mem_addr);
				fclose(mtrace_Write);
			} 
			mem_data =  (static_cast<uint8_t>(0 << 24)) |
						(static_cast<uint8_t>(0 << 16)) |
						(static_cast<uint8_t>(guest_to_host(0)[mem_addr + 1]) << 8)  |
						 static_cast<uint8_t>(guest_to_host(0)[mem_addr    ]);
			//printf("-----%x  %x  %x-----\n",*rs1_data_in, *imm_data_in, mem_data);
			return mem_data;
			break;
		default:
			return 0;
			break;
	}
}
