#include "../include/memory.h"
#include "../include/common.h"

void elf_print(int type, char *fname, uint32_t start, uint32_t end);
char *ftrace_find_symbol(uint32_t addr);

int is_jal(int x){
	uint32_t high = (x >> 12) & 0b111;
	uint32_t low = x & 0b1111111;
	uint32_t result = (high << 7) | low;
	if (low == 111){
		return 1;
	}
	else if(result == 103){
		return 2;
	}
	return 0;
}

void ftrace_check(uint32_t pc, uint32_t dnpc, uint32_t inst){
	int rd = BITS(inst, 11, 7);
	//printf("pc = %x  dnpc = %x  inst = %x  %d  %x\n", pc, dnpc, inst, is_jal(inst), rd);
	if(is_jal(inst) == 0)
		return;
	if(FTRACE){
	  int rs1 = BITS(inst, 19, 15);
	  char *prev_fname = ftrace_find_symbol(pc);
	  char *now_fname  = ftrace_find_symbol(dnpc);
	  //printf("pc = %x  dnpc = %x prev_fname = %s  now_fname = %s\n", pc, dnpc, prev_fname, now_fname);
	  if(strcmp(prev_fname,now_fname) == 0)	return;
	  if(is_jal(inst) == 1) elf_print(0,now_fname,dnpc,pc);
	  else if(is_jal(inst) == 2){
		int32_t imm = SEXT((int64_t)BITS(inst, 31, 20), 12);
		if(rs1 == 1 && imm == 0 && rd == 0)
		  elf_print(1,prev_fname,dnpc,pc);
		else 
		  elf_print(0,now_fname,dnpc,pc);
	  }
	}
}
