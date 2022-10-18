#include "Vtop.h"  //这里因为新建的rtl文件为top.c，所以需要改为Vtop.h即可。
#include "verilated.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <nvboard.h>
vluint64_t main_time = 0;  //initial 仿真时间
static TOP_NAME dut;
void nvboard_bind_all_pins(Vtop* top);
static void single_cycle(){
//	int a = rand() & 1;
//	int b = rand() & 1;
//	dut.a = a;
//	dut.b = b;
	dut.eval();
}
static void reset(int n){
	while(n-- > 0) single_cycle();
}
int main(int argc, char** argv, char** env) {
	nvboard_bind_all_pins(&dut);
	nvboard_init();
//	int a = rand() & 1;
//	int b = rand() & 1;
	while(1){
		nvboard_update();
//		single_cycle();
//		dut.a=a;
//		dut.b=b;
		dut.f=dut.a^dut.b;
		dut.eval();
		
	}
}
