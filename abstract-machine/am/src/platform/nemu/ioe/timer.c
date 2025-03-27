#include <am.h>
#include <nemu.h>
#include "am.h"  // 假设这个头文件定义了 AM_TIMER_RTC_T



void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
//  uptime->us = 0;
	uint32_t hi = inl(MMIO_BASE + 0x4c);
  uint32_t lo = inl(MMIO_BASE + 0x48);
  uint64_t time = ((uint64_t)hi << 32) | lo;
  uptime->us = time ;

                        
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
	
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
