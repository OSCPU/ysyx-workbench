#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    //printf("%d---\n", c->mcause);
    switch (c->mcause) {
      case ENVIRONMENT_CALL_FROM_M_MODE:
        ev.event =  EVENT_YIELD;
        c->mepc += 4;
        break;
      default: ev.event = EVENT_ERROR; break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
  }
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));
  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *c = (Context *)kstack.end - 1; //先设定上下文地址在栈底
  c->mepc = (uintptr_t)entry;
  c->mstatus = 0x1800;//mret后进入Machine模式
  c->gpr[10] = (uintptr_t)arg;//设置寄存器a0为参数arg，将参数arg传给即将执行的entry()函数
  return c;
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
