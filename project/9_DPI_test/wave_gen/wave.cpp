#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop__Dpi.h"
#include "svdpi.h"
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

int add(int a, int b) {
    return a + b;
}

int main(int argc, char** argv){
	int i,j,k,l;
	contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd

	for(i = 0; i <=100 ; i++){
		top -> in_a = i;
		top -> in_b = i + 2;
		step_and_dump_wave();
	}             
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 
 }
