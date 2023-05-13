#include <am.h>
#include <nemu.h>
#include <klib.h>

static uint32_t boot_time=0;
void __am_timer_init() {
    //boot_time = (((uint64_t)inl(RTC_ADDR+4)<<32) + (uint64_t)inl(RTC_ADDR));
    //printf("Initializing timer is %d\n",(int)boot_time);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  //uptime->us = 0;
  //printf("uptime->us is %d\n",(int)uptime->us);
  uptime->us = (((uint64_t)inl(RTC_ADDR+4)<<32) + (uint64_t)inl(RTC_ADDR)) - boot_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
