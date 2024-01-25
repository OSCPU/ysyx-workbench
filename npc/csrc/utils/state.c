#include <utils.h>

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
