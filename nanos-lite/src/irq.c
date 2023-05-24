#include <common.h>

static Context* do_event(Event e, Context* c) {
  switch (e.event) {
    default: panic("Unhandled event ID = %d", e.event);
  }

  return c;
}

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
}
