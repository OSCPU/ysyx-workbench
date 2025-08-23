#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vtop.h"
#include "verilated_fst_c.h"
#include "verilated_vcd_c.h"

VerilatedContext* contextp = new VerilatedContext;
VerilatedFstC* tfp = new VerilatedFstC;
Vtop* top = new Vtop{contextp};
 
void step_and_dump_wave(){
	top->eval();
	contextp->timeInc(1);
	tfp->dump(contextp->time());
}

// uint32_t instructions[15] = {
// 	0x00000413, // lui x8, 0x00000
// 	0x00140413, // addi x8, x8, 1
// 	0x00250593, // addi x11, x10, 2
// 	0x00360613, // addi x12, x12, 3
// 	0x00470713, // addi x14, x14, 4
// 	0x00580813, // addi x16, x16, 5
// 	0x00690913, // addi x18, x18, 6
// 	0x007a0a13, // addi x20, x20, 7
// 	0x008b0b13, // addi x22, x22, 8
// 	0x009c0c13, // addi x24, x24, 9
// 	0x00ad0d13, // addi x26, x26, 10
// 	0x00be0e13, // addi x28, x28, 11
// 	0x00cf0f13  // addi x30, x30, 12
// };

int main(int argc, char** argv){
	contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("obj_dir/wave.fst");//设置输出的文件wave.vcd
	int i = 0;
	top->reset = 1;
	while (i < 232){
		if (i >= 3) {
			top->reset = 0; // 复位信号在第一个周期后拉低
		}
		top->clock = ~top->clock;
		// if(top->clock)
		// 	top->io_addr_in = instructions[(i / 2) % 12]; // 模拟输入地址
		step_and_dump_wave();                   
		i++;
	}
	delete top;
	tfp -> close();
	delete contextp;
	return 0;
 }
