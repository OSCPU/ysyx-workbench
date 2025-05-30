#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_fst_c.h"
#include "verilated_vcd_c.h"

VerilatedContext* contextp = new VerilatedContext;
VerilatedFstC* tfp = new VerilatedFstC;
Vtop* top = new Vtop{contextp};
 
void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

int main(int argc, char** argv){
	int i,j,k,l;
	contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd
	top -> reset = 1;
/*
	static const u_int32_t img[
		0b00000000010100000000000010010011, //addi x1 x0 5
		0b00000000000100000000000100010011, //addi x2 x0 1
		0b00000000001000000000000100010011, //addi x2 x0 2
		0b00000000010100001000000100010011  //addi x2 x1 5
	]
*/
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
