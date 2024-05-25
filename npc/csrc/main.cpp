#include <stdio.h>
#include <nvboard.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"
// static TOP_NAME top;
VerilatedContext *contextp = NULL;
Vtop *top = NULL;
VerilatedVcdC *tfp = NULL;

void nvboard_bind_all_pins(Vtop *top);
void sim_init(int argc, char **argv);

/*
void single_cycle(Vtop* top) {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}

void reset(int n, Vtop* top) {
  top->rst = 1;
  while (n -- > 0) single_cycle(top);
  top->rst = 0;
}
*/

int main(int argc, char **argv)
{

	sim_init(argc, argv);

	// nvboard_bind_all_pins(top);

	// nvboard_init();

	//! contextp->gotFinish()
	while (1)
	{

		// printf("a = %d, b = %d, f = %d\n", top->a, top->b, top->f);

		/**/
		top->a = rand() % 2;
		top->b = rand() % 2;
		top->s = rand() % 2;

		top->eval();
		contextp->timeInc(1);		 // 推动仿真时间
		tfp->dump(contextp->time()); // dump wave

		// nvboard_update();
	}
	delete top;
	tfp->close();
	delete contextp;
	// nvboard_quit();
	return 0;
}

void sim_init(int argc, char **argv)
{
	contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	top = new Vtop{contextp};
	tfp = new VerilatedVcdC;	 // 初始化VCD对象指针
	contextp->traceEverOn(true); // 打开追踪功能
	top->trace(tfp, 0);			 //
	tfp->open("wave.vcd");		 // 设置输出的文件wave.vcd
}