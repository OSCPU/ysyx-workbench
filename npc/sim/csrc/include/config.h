#ifndef __CONFIG_H__

#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

#define CONFIG_TIMER_GETTIMEOFDAY 1
#define CONFIG_TARGET_NATIVE_ELF 1

/* Debug Options: trace, difftest, watchpoint, wave*/

/* trace */
#define CONFIG_TRACE 1

#ifdef CONFIG_TRACE

//#define CONFIG_FTRACE   1
#define CONFIG_IRINGBUF 1
//#define CONFIG_MTRACE 1

#endif

/* difftest */
#define CONFIG_DIFFTEST 1

/* watchpoint */
//#define CONFIG_WATCHPOINT 1

/* wave */
//#define CONFIG_WAVE

#endif // !__CONFIG_H__
