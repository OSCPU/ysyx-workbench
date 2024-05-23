#include <stdio.h>
#include <nvboard.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include "verilated.h"
//static TOP_NAME dut;
static Vtop top;
void nvboard_bind_all_pins(Vtop* top);

int main(int argc, char** argv) {

	//VerilatedContext* contextp = new VerilatedContext;
	//contextp->commandArgs(argc, argv);
	//Vtop* top = new Vtop{contextp};


	//VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
	//contextp->traceEverOn(true); //打开追踪功能
	//top->trace(tfp, 0); //
	//tfp->open("wave.vcd"); //设置输出的文件wave.vcd



	nvboard_bind_all_pins(&top);
	nvboard_init();
//!contextp->gotFinish()
	while (1) {
		//int a = rand() & 1;
		//int b = rand() & 1;
		//top->a = a;
		//top->b = b;
		//top->eval();
		//printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		//tfp->dump(contextp->time()); //dump wave
		//contextp->timeInc(1); //推动仿真时间
		//assert(top->f == (a ^ b));
		nvboard_update();
	}
	//delete top;
	//tfp->close();
	//delete contextp;
	nvboard_quit();
	return 0;
}
