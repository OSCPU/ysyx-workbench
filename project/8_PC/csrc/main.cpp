#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Vtop.h"
#include <nvboard.h>
#include "verilated_fst_c.h"
 
#include "verilated_vcd_c.h"
 
static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);

static void single_cycle() {
  dut.clk = 0; dut.eval();
  dut.clk = 1; dut.eval();
}


int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();


  while(1) {
    nvboard_update();
    single_cycle();
  }
}
