#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<cstdint>
#include"svdpi.h"

#include <mem.h>
#include <cpu/cpu.h>
#include <sdb.h>

VerilatedContext* contextp=NULL; 
Vysyx_23060111_top *top=NULL; 
VerilatedVcdC* tfp=NULL;

int main_time=0;



int main(int argc ,char** argv, char** env)
{
	//int count=40;
	contextp = new VerilatedContext;
	contextp->commandArgs(argc,argv);
	top = new Vysyx_23060111_top{contextp};
	contextp->traceEverOn(true);
	tfp=new VerilatedVcdC;

	top->trace(tfp,0);
	tfp->open("wave.vcd");

	//init mem
	init_mem();

	//init cpu
	cpu_init();
	sdb_mainloop();
	//cpu_exec(count);
	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
void ebreak (int inst)
{
	if(inst == 0x00100073 )
	{
	   NPCTRAP(top->reg->rf[10]);
	}
}


