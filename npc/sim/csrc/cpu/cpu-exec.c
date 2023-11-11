#include "common.h"
#include "config.h"
#include "macro.h"
#include <utils.h>

#define MAX_INST_TO_PRINT 10

riscv32_CPU_state cpu = {.pc=CONFIG_MBASE, .npc=CONFIG_MBASE};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void sim_exec_once();
void sim_exit();
void isa_reg_display();
void iringbuf_display();
void print_current_inst();
void trace_and_difftest();

static void exec_once() {
  sim_exec_once();
  trace_and_difftest();
	IFDEF(CONFIG_IRINGBUF, if(g_print_step) print_current_inst();)
}

static void execute(uint64_t n) {
  for(; n > 0; n--) {
    exec_once();
    g_nr_guest_inst ++;
    if(npc_state.state != NPC_RUNNING) break;
  }
}

static void statistic() {
  Log("host time spent = %lu us", g_timer);
  Log("total guest instructions = %lu" , g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = %lu inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  //IFDEF(CONFIG_FTRACE, ftrace());
  IFDEF(CONFIG_IRINGBUF, iringbuf_display());
  isa_reg_display();
  statistic();
}

void cpu_exec(uint64_t n) {
  g_print_step = (n <= MAX_INST_TO_PRINT);

  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. TO restart the program, exit NPC and run again\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (npc_state.state) {
    case NPC_RUNNING:
      npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      IFDEF(CONFIG_IRINGBUF, iringbuf_display());
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
            (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
              ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
                npc_state.halt_pc);
      // fall through
    case NPC_QUIT:
      statistic(); 
      sim_exit();
  }
}
