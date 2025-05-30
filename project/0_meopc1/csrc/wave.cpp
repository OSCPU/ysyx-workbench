#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cstdint> // 包含 uint32_t 类型定义
#include "Vtop.h"
#include "Vtop__Dpi.h"
#include "svdpi.h"
#include "verilated_fst_c.h"
#include "verilated_vcd_c.h"

VerilatedContext* contextp = new VerilatedContext;
VerilatedFstC* tfp = new VerilatedFstC;
Vtop* top = new Vtop{contextp};
static svBitVecVal img[100]; 
void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

// static svBitVecVal img[] = {
// 	0x00510093, //addi x2 x1 5 0x00000000010100010000000010010011
// 	0x00108113, //addi x1 x2 1
// 	0x00510093, //addi x2 x1 5 0x00000000010100010000000010010011
// 	0x00108113, //addi x1 x2 1
// 	//0x00510093  //addi x2 x1 2
// 	0x00100073  //ebreak
// };

svBit is_break(const svBitVecVal* instruction_in){
	if(*instruction_in == 0b00000000000100000000000001110011)
		exit(0); 
	return 0;
}

svBitVecVal addr_read(const svBitVecVal* pc){
	printf("pc = %x\n", *pc);
	svBitVecVal instruction;
	if(*pc < 0x80000000){
		instruction = 0;
	}
	else{
		instruction = img[(*pc - 0x80000000) / 4];
	}
	return instruction;
}

int main(int argc, char** argv){
	int i,j,k,l;
	for (k = 0; k < 5; k++){
		if(k == 4)
			img[k] = 0x00510093;
			//img[k] = 0x00100073; // ebreak
	 	else{
	 		if(k % 2 == 0)
	 			img[k] = 0x00510093;
	 		else
	 			img[k] = 0x00108113;
	 		}
	}
	k = 0;
	contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd
	top -> reset = 1;
	for(i = 0; i <=100 ; i++){
		if(i == 3){
			top -> reset = 0;
		}
		top -> clock = ~(top -> clock);
		step_and_dump_wave();
	}             
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 }
