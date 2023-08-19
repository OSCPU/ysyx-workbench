#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "Vtop.h"
#include"verilated.h"
#include"verilated_vcd_c.h"

int main(int argc ,char** argv, char** env)
{
	int count=0;
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc,argv);
	Vtop *top = new Vtop{contextp};

	VerilatedVcdC* tfp=new VerilatedVcdC;
	contextp->traceEverOn(true);
	top->trace(tfp,0);
	tfp->open("wave.vcd");

	while(count<=500&&!contextp->gotFinish())
	{
		int a = rand() & 1;
		int b = rand() & 1;
		top->a =a;
		top->b =b;
		top->eval();
		printf("a = %d, b = %d, f = %d\n",a,b,top->f);

		tfp->dump(contextp->time());
		contextp->timeInc(1);
		assert(top->f ==(a ^ b));
		count++;
	}
	delete top;
	tfp->close();
	delete contextp;
	return 0;
}
