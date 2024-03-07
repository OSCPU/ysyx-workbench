#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated.h"
#include "verilated_vpi.h"
#include "Vtop.h"
#include "verilated_vcd_c.h"

void sim_top(int sim_time) {
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  const std::unique_ptr<Vtop> top{new Vtop{contextp.get()}};
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace(tfp, 99);
  tfp->open("obj_dir/simx.vcd");
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

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  printf("Hello, ysyx!\n");
  sim_top(200);
  return 0;
}
