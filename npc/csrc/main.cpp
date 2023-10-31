#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Vtop.h"  // create `top.v`,so use `Vtop.h`
#include "verilated.h"
 
#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
 
// int main(int argc, char** argv, char** env) {
 
//   VerilatedContext* contextp = new VerilatedContext;
//   contextp->commandArgs(argc, argv);
//   Vtop* top = new Vtop{contextp};
  
 
//   VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
//   contextp->traceEverOn(true); //打开追踪功能
//   top->trace(tfp, 0); //
//   tfp->open("wave.vcd"); //设置输出的文件wave.vcd
 
 
//   while (!contextp->gotFinish()) {
//     int a = rand() & 1;
//     int b = rand() & 1;
//     top->a = a;
//     top->b = b;
//     top->eval();
//     printf("a = %d, b = %d, f = %d\n", a, b, top->c);
 
//     tfp->dump(contextp->time()); //dump wave
//     contextp->timeInc(1); //推动仿真时间
 
//     assert(top->c == a ^ b);
//   }
//   delete top;
//   tfp->close();
//   delete contextp;
//   return 0;
// }

#include <nvboard.h>
#include <Vtop.h>

extern void nvboard_bind_all_pins(Vtop* top);

void single_cycle(Vtop* top ) {
  top->clk = 0; top->eval();
  top->clk = 1; top->eval();
}

void reset(Vtop* top , int n) {
  top->rst = 1;
  while (n -- > 0) single_cycle( top );
  top->rst = 0;
}

int main(){

  VerilatedContext* contextp = new VerilatedContext;
  Vtop* top = new Vtop{contextp};
  nvboard_bind_all_pins(top);
  nvboard_init();

  reset(top , 10);
  while(1) {
    nvboard_update();
    single_cycle(top);
    // top ->eval();
    // top.clk = 0; dut.eval();
    // top.clk = 1; dut.eval();
  }
}
