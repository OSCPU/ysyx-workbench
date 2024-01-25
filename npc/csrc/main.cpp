#include<stdio.h>
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
	delete top;
	tfp->close();
	delete contextp;
	return is_exit_status_bad();
}
void ebreak (int inst)
{
	if(inst == 0x00100073 )
	{
	   NPCTRAP(top->halt_ret);
	}
	if(inst!=0&&top->inv_flag==1)
	{
		INV();
	}
	else if(inst==0&&top->inv_flag==1)
	{
		top->inv_flag=0;
	}
}


