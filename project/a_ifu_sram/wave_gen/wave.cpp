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
	int i = 0;
	top->reset = 1;
	while (i < 100){
		if (i >= 3) {
			top->reset = 0; // 复位信号在第一个周期后拉低
		}
		if(top->reset == 0){
			top -> io_addr_in = top -> io_addr_in + 4; // 设置地址输入
		}
		top->clock = ~top->clock;  
		step_and_dump_wave();                   
		i++;
	}
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 }
