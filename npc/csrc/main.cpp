#include <stdio.h>
#include <nvboard.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"
//static TOP_NAME dut;
static Vtop* top;
void nvboard_bind_all_pins(Vtop* top);

void single_cycle() {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}

void reset(int n) {
  top->rst = 1;
  while (n -- > 0) single_cycle();
  top->rst = 0;
}

int main(int argc, char** argv) {
/*
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc, argv);
	Vtop* top = new Vtop{contextp};




	VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
	contextp->traceEverOn(true); //打开追踪功能
	top->trace(tfp, 0); //
	tfp->open("wave.vcd"); //设置输出的文件wave.vcd

*/

	nvboard_bind_all_pins(top);

	nvboard_init();
	reset(10);

//!contextp->gotFinish()
	while (1) {



		top->eval();
		//printf("a = %d, b = %d, f = %d\n", top->a, top->b, top->f);



		//tfp->dump(contextp->time()); //dump wave
		//contextp->timeInc(1); //推动仿真时间
		//assert(top->f == (a ^ b));
		nvboard_update();
		single_cycle();
	}
	//delete top;
	//tfp->close();
	//delete contextp;
	nvboard_quit();
	return 0;
}
