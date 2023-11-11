#include <am.h>
#include "../riscv.h"

#define TIMER_ADDR 0xa0000048
#define RTC_ADDR   0xa0000050

static uint64_t boot_time = 0;

static uint64_t read_time() {
  uint32_t lo = inl(TIMER_ADDR);
  uint32_t hi = inl(TIMER_ADDR + 4);
  uint64_t time = ((uint64_t)hi << 32) | (uint64_t)lo;
  return time;
}
void __am_timer_init() {
  boot_time = read_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = read_time() - boot_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  uint32_t lo = inl(RTC_ADDR);
	uint32_t hi = inl(RTC_ADDR + 4);
  rtc->second = lo & 0xff;
  rtc->minute = lo >> 8 & 0xff;
  rtc->hour   = lo >> 16 & 0xff;
  rtc->day    = lo >> 24 & 0xff;
  rtc->month  = hi & 0xff;
  rtc->year   = 1900 + (hi >> 8 & 0xff);
}
