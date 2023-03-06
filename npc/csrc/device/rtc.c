#include <common.h>

static uint32_t *rtc_port_base = NULL;

uint64_t get_time();
static void rtc_io_handler(uint32_t offset, int len, bool is_write) {
  assert(offset == 0 || offset == 4);
  if (!is_write) {
    uint64_t us = get_time();
    rtc_port_base[0] = (uint32_t)us;
    rtc_port_base[1] = us >> 32;
  }
}

void init_timer() {
  rtc_port_base = (uint32_t *)new_space(8);

  add_mmio_map("rtc", RTC_ADDR, rtc_port_base, 8, rtc_io_handler);
}
