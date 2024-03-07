#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vpi.h"
#include "verilated_vcd_c.h"

#ifdef __SIM_TOP
#include "Vtop.h"
void sim_top(int sim_time) {
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  const std::unique_ptr<Vtop> top{new Vtop{contextp.get()}};
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("obj_dir/top-simx.vcd");
  while (contextp->time() < sim_time && !contextp->gotFinish()) {
    contextp->timeInc(1);
    top->a = rand() & 1;
    top->b = rand() & 1;
    top->eval();
    printf("a = %d, b = %d, f = %d\n", top->a, top->b, top->f);
    assert(top->f == (top->a ^ top->b));
    tfp->dump(contextp->time());
  }
  tfp->close();
}
#endif

// #define __SIM_LIGHT

#ifdef __SIM_LIGHT
#include "Vlight.h"
void sim_light(int sim_time) {
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  const std::unique_ptr<Vlight> top{new Vlight{contextp.get()}};
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("obj_dir/light-simx.vcd");
  auto single_cycle = [&] () {
    top->clk = 0; top->eval();
    top->clk = 1; top->eval();
  };
  auto reset = [&] (int n) {
    top->rst = 1;
    while (n-- > 0) single_cycle();
    top->rst = 0;
  };
  reset(10);
  while (contextp->time() < sim_time && !contextp->gotFinish()) {
    contextp->timeInc(1);
    single_cycle();
    auto led = top->led;
    // for (int i = 0; i < 16; i++) {
    //   printf("%d ", (led & (1 << i)) ? 1 : 0);
    // }
    // printf("\n");
    tfp->dump(contextp->time());
  }
  tfp->close();
}
#endif

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  printf("Hello, ysyx!\n");
  #ifdef __SIM_TOP
  sim_top(200);
  #endif
  #ifdef __SIM_LIGHT
  sim_light(200);
  #endif
  return 0;
}
