#include "../include/memory.h"
#include "../include/common.h"

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

void print_itrace(FILE *itrace, int pc_data, uint32_t insn32){
	uint64_t pc_data1 = (uint64_t)pc_data;
	uint8_t code[] = {
					static_cast<uint8_t>(insn32 & 0xFF),
					static_cast<uint8_t>((insn32 >>  8) & 0xFF),
					static_cast<uint8_t>((insn32 >> 16) & 0xFF),
					static_cast<uint8_t>((insn32 >> 24) & 0xFF)
				};
	char buf[160];
	disassemble(buf, sizeof(buf), pc_data1 , code, 4);
	// printf("111\n");
	// printf("---0x%x  %s---\n",pc_data, buf);
	fprintf(itrace, "0x%x  %s\n",pc_data, buf);
}