/*
#include <cstdint>
#include <mem.h>
#include "Vysyx_23060111_top.h"
#include"verilated.h"
#include"verilated_vcd_c.h"
#include"Vysyx_23060111_top__Dpi.h"

*/
#include <cpu/cpu.h>
/*
extern int main_time;
extern VerilatedContext* contextp;
extern Vysyx_23060111_top *top;
extern VerilatedVcdC* tfp;
*/


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
void cpu_exec_once(VerilatedVcdC* tfp)
{

		top->clk =0; top->eval();
		top->inst =pc_read(top->pc);
		tfp->dump(main_time);
		main_time++;
		top->eval();
		top->clk =1; top->eval();
		tfp->dump(main_time);
		main_time++;
		top->eval();


}

static void execute(uint64_t n)
{
	for(;n>0;n--)
	{
		cpu_exec_once(tfp);
	}
}

void cpu_exec(uint64_t n)
{
	execute(n);
}


