#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  /*printf("[trap] mepc = 0x%8x\n", c->mepc);
  printf("[trap] mcause = 0x%8x\n", c->mcause);
  printf("[trap] mstatus = 0x%8x\n", c->mstatus);
  for (int i = 0; i < NR_REGS; i++) {
    printf("[trap] gpr[%d] = 0x%8x\n", i, c->gpr[i]);
  }*/
	if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
			case (uintptr_t)-1: ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
    }
       //  IFDEF(CONFIG_ETRACE,printf("[etrace] exception @ 0x%08x cause = %d\n", c->mepc, c->mcause));

    c = user_handler(ev, c);
    assert(c != NULL);
  }
//	printf("djasd: ");
//c->mepc = c->mepc + 4;
//printf("0x%8x",c->mepc);
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
 asm volatile (
        "li t0, 0x1800\n"
        "csrw mstatus, t0\n"
    );
  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
