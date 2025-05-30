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
	for(k = 0; k <= 7; k ++) {
		for(i = -8; i <= 7; i ++) {
			for(j = -8; j <= 7; j ++) {
				top->x = i; top->y = j; top -> sw = k; step_and_dump_wave();
				if(k == 0) l = i + j;
				else l = i - j;
				if(l < 0) l = 16 + l;
			}
		}
	}		
        step_and_dump_wave();              
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 
 }
