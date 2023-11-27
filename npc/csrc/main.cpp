#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<cstdint>
#include "Vysyx_23060111_top.h"
#include"verilated.h"
#include"verilated_vcd_c.h"
#include"Vysyx_23060111_top__Dpi.h"
#include"svdpi.h"
#include"../hsrc/mem.h"

void ebreak (int inst)
{
	if(inst == 0x00100073 )
	{
	printf("error --------- ebreak\n");
	assert(0);
	}
}

int main(int argc ,char** argv, char** env)
{
	//init
	int count=0;
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc,argv);
	Vysyx_23060111_top *top = new Vysyx_23060111_top{contextp};

	VerilatedVcdC* tfp=new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("wave.vcd");

	//init mem
	init_mem();
        uint32_t a=0x80000000;
	top->pc=a;

	while(count<=3&&!contextp->gotFinish())
	{
		top->inst =pc_read(top->pc);
		if(count==2)
		{
		top->rst=1;
		}
		else
		{
		top->rst=0;
		}
		top->clk =0; top->eval();
		top->clk =1; top->eval();

		printf("------%x\n",top->pc);
		printf("------top->reg_out1 %x\n",top->reg_out1);
		printf("------top->imm %x\n",top->imm);
		printf("------top->val %x\n",top->inst);


		top->eval();

		tfp->dump(contextp->time());
		contextp->timeInc(1);
		count++;
	}
	delete top;
	tfp->close();
	delete contextp;
	return 0;
}


