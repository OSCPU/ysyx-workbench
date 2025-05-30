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
	printf("%d \n", argc);
	for(int i = 0; i < argc; i++){
		printf("%s \n", argv[i]);
	}
	contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd
	
	top->s=0b00;  top->a=0b10000000;  step_and_dump_wave();
		top->a=0b01000000;  step_and_dump_wave();
	top->s=0b01;  top->a=0b00100000;  step_and_dump_wave();
		top->a=0b00010000;  step_and_dump_wave();
	top->s=0b10;  top->a=0b00001000;  step_and_dump_wave();
		top->a=0b00000100;  step_and_dump_wave();
	top->s=0b11;  top->a=0b00000010;  step_and_dump_wave();
		top->a=0b00000001;  step_and_dump_wave();
                      
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 
 }
