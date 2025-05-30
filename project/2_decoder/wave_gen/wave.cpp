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
	
	top->x = 0b11001000;  step_and_dump_wave();
	top->x = 0b01001000;  step_and_dump_wave();
	top->x = 0b00101000;  step_and_dump_wave();
	top->x = 0b00011000;  step_and_dump_wave();
	top->x = 0b00001100;  step_and_dump_wave();
	top->x = 0b00000100;  step_and_dump_wave();
	top->x = 0b00000011;  step_and_dump_wave();
	top->x = 0b00000001;  step_and_dump_wave();
	top->x = 0b00000000;  step_and_dump_wave();
		
        step_and_dump_wave();              
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 
 }
