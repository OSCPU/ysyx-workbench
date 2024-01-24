#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<cstdint>
#include "Vysyx_23060111_top.h"
#include"verilated.h"
#include"verilated_vcd_c.h"
#include"Vysyx_23060111_top__Dpi.h"
#include"svdpi.h"

#include <mem.h>
#include <cpu/cpu.h>


VerilatedContext* contextp=NULL; 
Vysyx_23060111_top *top=NULL; 
VerilatedVcdC* tfp=NULL;

int main_time=0;

void cpu_init();
void cpu_exce_once(VerilatedVcdC* tfp);
void ebreak(int inst);
void cpu_exce(uint64_t n);
void execute(uint64_t n);



int main(int argc ,char** argv, char** env)
{
	int count=40;
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
	//top->pc=0x80000000;
	/*
	while(count<=10&&!contextp->gotFinish())
	{
		if(count==2)
		{
		top->rst=1;
		}
		else
		{
		top->rst=0;
		}
		cpu_exce_once(tfp);

		//contextp->timeInc(1);
		count++;
	}
	*/
	cpu_exce(count);
	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
void cpu_init()
{
	top->rst=1;
	top->clk =0; top->eval();
	tfp->dump(main_time);
	main_time++;
	top->eval();
	top->clk =1; top->eval();
	top->rst=0;
	tfp->dump(main_time);
	main_time++;
	top->eval();

	
}
void cpu_exce_once(VerilatedVcdC* tfp)
{
		//top->snpc=top->pc;
		//top->dnpc=top->snpc;

		top->clk =0; top->eval();
		top->inst =pc_read(top->pc);
		tfp->dump(main_time);
		main_time++;
		top->eval();
		top->clk =1; top->eval();
		tfp->dump(main_time);
		main_time++;
		top->eval();

		//top->pc=top->dnpc;

}
void cpu_exce(uint64_t n)
{
	execute(n);
}
void execute(uint64_t n)
{
	for(;n>0;n--)
	{
		cpu_exce_once(tfp);
	}
}
void ebreak (int inst)
{
	if(inst == 0x00100073 )
	{
	printf("npc: %s at pc = 0x%x\n",ANSI_FMT("HIT GOOD TRAP",ANSI_FG_GREEN),top->pc);
	}
}


