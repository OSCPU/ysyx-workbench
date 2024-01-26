#include <cstdint>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

#include <common.h>

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "svdpi.h"
#include "../build/obj-riscv32e-npc-interpreter/VTop__Dpi.h"
#include "../build/obj-riscv32e-npc-interpreter/VTop.h"
#include "../build/obj-riscv32e-npc-interpreter/VTop___024root.h"

void iringbuf_step(vaddr_t pc, uint32_t inst);

void npc_trap(word_t pc, int code) {
  npc_state.state = NPC_END;
  npc_state.halt_pc = pc;
  npc_state.halt_ret = code;
}

/* verilator simulation variables */
static VTop *top;
VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

/* verilater simulation api */
void sim_init();
void sim_exit();
static void sim_reset();
static void step_and_dump_wave();
static void sim_reg_copy();
vaddr_t sim_exec_once();

void sim_init(){
  top = new VTop;
#ifdef CONFIG_WAVE
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;

  top->trace(tfp, 0);
  contextp->traceEverOn(true);
  tfp->open("wave.vcd");
#endif

  sim_reset();
}

static void sim_reset() {
  int sim_time = 0;
  while (sim_time <= 3) {
    if (sim_time <= 2)
      top->reset = 1;
    else
      top->reset = 0;
    top->clock ^= 1;
    step_and_dump_wave();
    sim_time++;
  }
  sim_reg_copy();
  IFDEF(CONFIG_IRINGBUF, iringbuf_step(top->io_pc, top->io_inst));
}

static void step_and_dump_wave() {
  top->eval();
  IFDEF(CONFIG_WAVE, contextp->timeInc(1));
  IFDEF(CONFIG_WAVE, tfp->dump(contextp->time()));
}

void sim_exit(){
  step_and_dump_wave();
  IFDEF(CONFIG_WAVE, tfp->close());
}

vaddr_t sim_exec_once() {
  /* isa_exec_once simulation */

  /* sim posedge */
  top->clock ^= 1;
  step_and_dump_wave();

  /* sim negedge */
  top->clock ^= 1;
  step_and_dump_wave();

  /* save cpu state*/
  sim_reg_copy();
  IFDEF(CONFIG_IRINGBUF, iringbuf_step(top->io_pc, top->io_inst));
  if (top->io_halt) npc_trap(cpu.pc, cpu.gpr[10]);

  return cpu.pc;
}

static void sim_reg_copy() {
  // current pc
  cpu.pc = cpu.npc;
  // gpr
  cpu.gpr[0]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_0; 
  cpu.gpr[1]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_1; 
  cpu.gpr[2]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_2; 
  cpu.gpr[3]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_3; 
  cpu.gpr[4]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_4; 
  cpu.gpr[5]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_5; 
  cpu.gpr[6]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_6; 
  cpu.gpr[7]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_7; 
  cpu.gpr[8]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_8; 
  cpu.gpr[9]  = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_9; 
  cpu.gpr[10] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_10;
  cpu.gpr[11] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_11;
  cpu.gpr[12] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_12;
  cpu.gpr[13] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_13;
  cpu.gpr[14] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_14;
  cpu.gpr[15] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_15;
#ifndef CONFIG_RVE
  cpu.gpr[16] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_16;
  cpu.gpr[17] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_17;
  cpu.gpr[18] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_18;
  cpu.gpr[19] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_19;
  cpu.gpr[20] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_20;
  cpu.gpr[21] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_21;
  cpu.gpr[22] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_22;
  cpu.gpr[23] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_23;
  cpu.gpr[24] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_24;
  cpu.gpr[25] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_25;
  cpu.gpr[26] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_26;
  cpu.gpr[27] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_27;
  cpu.gpr[28] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_28;
  cpu.gpr[29] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_29;
  cpu.gpr[30] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_30;
  cpu.gpr[31] = top->rootp->Top__DOT__idu__DOT__regFile__DOT__regfile_31;
#endif
  cpu.csr.mcause  = top->rootp->Top__DOT__exu__DOT__csr__DOT__mcause;
  cpu.csr.mepc    = top->rootp->Top__DOT__exu__DOT__csr__DOT__mepc;
  cpu.csr.mstatus = top->rootp->Top__DOT__exu__DOT__csr__DOT__mstatus;
  cpu.csr.mtvec   = top->rootp->Top__DOT__exu__DOT__csr__DOT__mtvec;
  // next pc
  cpu.npc = top->io_pc;
}
