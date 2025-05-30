#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Vtop.h"
#include <nvboard.h>
#include "verilated_fst_c.h"
 
#include "verilated_vcd_c.h"
 
static TOP_NAME dut;
 
void nvboard_bind_all_pins(TOP_NAME* top);
 
 
int main(int argc, char** argv){
 
	nvboard_bind_all_pins(&dut);
	nvboard_init();
	int i = 1;
	while(i <= 10000) {
		nvboard_update();
		dut.a = rand() & 1;
		dut.b = rand() & 1;
		dut.eval();
		printf("a = %d, b = %d, f = %d\n", dut.a, dut.b, dut.f);
		assert(dut.f == (dut.a ^ dut.b));
		i++;
	}
	return 0;
}
