#include "../include/cpu_exec.h"
#include "verilated_dpi.h"
#include "Vtop__Dpi.h"
#include "../include/memory.h"
#include "../include/common.h"

int flag = 0;
VerilatedContext* contextp = new VerilatedContext;
VerilatedFstC* tfp = new VerilatedFstC;
Vtop* top = new Vtop{contextp};
extern int reg_read_addr();
extern int reg_read_data();
extern int pc_read_data();
void pc_new(int data);
void print_itrace(FILE *itrace, int pc_data, uint32_t insn32);
int is_S(int x);
int is_L(int x);
void reg_new(int addr, int data);
int  new_reg();
void write_addr(uint32_t paddr, uint32_t data, int size);
void ftrace_check(uint32_t pc, uint32_t dnpc, uint32_t inst);

void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

svBit is_break(const svBitVecVal* instruction_in){
	if(*instruction_in == 0b00000000000100000000000001110011){
		flag = 1;
		return 1;
	}	 
	return 0;
}

int success = 0;
uint32_t insn32;

svBitVecVal addr_read(const svBitVecVal* pc){
	svBitVecVal instruction;
    //printf("pc = %x\n", *pc);
	if(*pc < 0x80000000){
		instruction = 0;
	}
	else{
        int insert = (*pc - 0x80000000) + 3;
        // printf("insert = %d\n", insert);
        // printf("size : %d  %d\n", sizeof(guest_to_host(RESET_VECTOR)[0]), sizeof(insert));
        instruction = (static_cast<uint8_t>(guest_to_host(RESET_VECTOR)[insert]) << 24) |
                    (static_cast<uint8_t>(guest_to_host(RESET_VECTOR)[insert - 1]) << 16) |
                    (static_cast<uint8_t>(guest_to_host(RESET_VECTOR)[insert - 2]) << 8)  |
                    static_cast<uint8_t>(guest_to_host(RESET_VECTOR)[insert - 3]);
	}
    // printf("pc instruction =%x 0x%x\n",*pc, instruction);
	if(instruction == 1048691 and insn32 == 32871){
		// printf("instruction = %x\n", instruction);
		success = 1;
	}
	insn32 = instruction;
	//printf("instruction: %x\n",instruction);
	return instruction;
}


int cpu_init(int argc, char** argv){
    contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd
	top -> reset = 1;          
	return 0;
}
int cpu_exec(int n){
	FILE *itrace=fopen("outputs/itrace.txt","w");
	if(MTRACE){
		FILE *mtrace_Write=fopen("outputs/mtrace.txt","w");
		fclose(mtrace_Write);
	} 
	for(int i = 0; i < 2 * n; i++){
		//printf("i = %d\n", i);
		if(top -> clock){
			int pc_data = new_reg();
			uint32_t rs1_data, rs2_data, imm_data;
			svScope scope = svGetScopeFromName("TOP.ysyx_25030077_top.i5");
			svSetScope(scope);
			rs1_data = (uint32_t)reg_read_rs1();
			rs2_data = (uint32_t)reg_read_rs2();
			imm_data = (SEXT((int64_t)BITS(insn32, 31, 25), 7) << 5) | BITS(insn32, 11, 7);
			switch(is_S(insn32))
			{
				case 1:
					// printf("%x %x\n", rs1_data + imm_data, rs2_data);
					write_addr(rs1_data + imm_data, rs2_data, 4);
					break;
				case 2:
					write_addr(rs1_data + imm_data, rs2_data, 2);
					break;
				case 3:
					write_addr(rs1_data + imm_data, rs2_data, 1);
					break;
				default:
					break;
			}
			if(i >= 1 && insn32 != 0 && ITRACE){
				print_itrace(itrace, pc_data, insn32);
			}
			uint32_t dnpc_data;
			scope = svGetScopeFromName("TOP.ysyx_25030077_top.i7");
			svSetScope(scope);
			dnpc_data = (uint32_t)dnpc_read_data();
			ftrace_check(pc_data, dnpc_data, insn32);
		}
		if(i == 3){
			top -> reset = 0;
		}
		top -> clock = ~(top -> clock);
		step_and_dump_wave();
		if(flag){
			break;
		}
	} 
	fclose(itrace);          
	return 0;
}

int cpu_end(){
	step_and_dump_wave();
	delete top;
	tfp -> close();
	delete contextp;
	return success;
}