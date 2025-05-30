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
	
	contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd
	
	int count = 0;
	while(count <= 500)
	{
		top -> clk = (top -> clk == 1)? 0 : 1;
		if(count < 10)
			top -> rst = 1;
		else
			top -> rst = 0;
		count ++;
		step_and_dump_wave();
	}                
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 
 }
