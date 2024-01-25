#include <cpu/cpu.h>
extern unsigned char isa_logo[];
NEMUState nemu_state ={.state=NEMU_STOP};

int is_exit_status_bad() {
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||      (nemu_state.state == NEMU_QUIT);
  return !good;
}


void set_nemu_state(int state,int halt_ret)
{
	nemu_state.state=state;
	nemu_state.halt_ret=halt_ret;
}

void invalid_inst()
{	
        printf("invalid opcode (PC = 0x%x)\n",top->pc);
  printf("There are two cases which will trigger this unexpected exception:\n"
      "1. The instruction at PC = \" 0x%x \" is not implemented.\n"
      "2. Something is implemented incorrectly.\n", top->pc);
  printf("Find this PC(\" 0x%x \") in the disassembling result to distinguish which case it is.\n\n", top->pc);
  printf(ANSI_FMT("If it is the first case, see\n%s\nfor more details.\n\n"
        "If it is the second case, remember:\n"
        "* The machine is always right!\n"
        "* Every line of untested code is always wrong!\n\n", ANSI_FG_RED),isa_logo);

	set_nemu_state(NEMU_ABORT,-1);
}

