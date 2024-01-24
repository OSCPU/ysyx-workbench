#include <cstdint>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

#include "common.h"
#include "config.h"
#include "debug.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "svdpi.h"
#include "../build/obj-riscv32e-npc-interpreter/VTop__Dpi.h"
#include "../build/obj-riscv32e-npc-interpreter/VTop.h"
#include "../build/obj-riscv32e-npc-interpreter/VTop___024root.h"

void iringbuf_step(vaddr_t pc, uint32_t inst);
/********** verilater variable **********/
VerilatedContext *contextp = NULL;
VerilatedVcdC *tfp = NULL;

static VTop* top;

/********** verilater function **********/
void sim_exec_once();
void isa_reg_copy();
void isa_reg_display();
static void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

static void sim_reset() {
  int sim_time = 0;
  // while(sim_time <= 6) {
  //   if(sim_time >=3 && sim_time <= 5) {
  //     top->reset = 1;
  //   } else {
  //     top->reset = 0;
  //   }
  //   top->clock ^= 1;
  //   step_and_dump_wave();
  //   sim_time++;
  // }
  // top->clock ^= 1;
  while(sim_time <= 3) {
    if(sim_time <= 2) top->reset = 1;
    else top->reset = 0;
    top->clock ^= 1;
    step_and_dump_wave();
    sim_time++;
  }
  isa_reg_copy();
  IFDEF(CONFIG_IRINGBUF, iringbuf_step(top->io_pc, top->io_inst));
  //sim_exec_once();
}

void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new VTop;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("wave.vcd");

  sim_reset();
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

/********** memory **********/
extern uint8_t imem[CONFIG_MSIZE];

/********** regfile **********/
extern riscv32_CPU_state cpu;

#ifdef __riscv32_e
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
};
#else
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
#endif

void isa_reg_copy() {
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
#ifndef __riscv32_e
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

void isa_reg_display() {
  int i;
  printf("%s\n",ANSI_FMT("ISA RegFile Display", ANSI_FG_GREEN));
  for(i = 0;i < ARRLEN(regs); i++){
    printf("%2d\t%-3s\t%#8x%15d\n",i, regs[i], cpu.gpr[i], cpu.gpr[i]);
  }
  printf("pc      = %#x\n", cpu.pc);
  printf("mcause  = %#x\n", cpu.csr.mcause);
  printf("mepc    = %#x\n", cpu.csr.mepc);
  printf("mstatus = %#x\n", cpu.csr.mstatus);
  printf("mtvec   = %#x\n", cpu.csr.mtvec);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if(strcmp(s,"pc") == 0){
    return cpu.pc;
  } else{
    return cpu.gpr[atoi(s)];
  }
}

const char *isa_reg_val2str(int i) {
  return regs[i];
}

word_t isa_csr_val(const char *s) {
  if(strcmp(s, "mepc") == 0) return cpu.csr.mepc;
  else if(strcmp(s, "mstatus") == 0) return cpu.csr.mstatus;
  else if(strcmp(s, "mcause") == 0) return cpu.csr.mcause;
  else if(strcmp(s, "mtvec" ) == 0) return cpu.csr.mtvec;
  else panic("Invalid csr!");

  return 0;
}

void npc_trap(word_t pc, int code) {
  npc_state.state = NPC_END;
  npc_state.halt_pc = pc;
  npc_state.halt_ret = code;
}

/* isa_exec_once simulation */
void sim_exec_once() {
  // sim poedge
  top->clock ^= 1;
  step_and_dump_wave();
  // sim negedge
  top->clock ^= 1;
  step_and_dump_wave();
  // copy regfile and check halt
  isa_reg_copy();
  IFDEF(CONFIG_IRINGBUF, iringbuf_step(top->io_pc, top->io_inst));
  if(top->io_halt) npc_trap(cpu.pc, cpu.gpr[10]);
}
