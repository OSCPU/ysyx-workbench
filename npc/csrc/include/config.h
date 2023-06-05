
// =========================== CONFIG ============================// debug 工具
// debug 工具
#define CONFIG_GTKWAVE 1
#define CONFIG_ITRACE 1
#define CONFIG_DIFFTEST 1
//#define DEBUG_DIFFTRACE 1
//#define CONFIG_MTRACE 1
#define COUNT_IPC 1

// device 设备
#define CONFIG_DEVICE 1
#ifdef CONFIG_DEVICE
#define CONFIG_HAS_SERIAL 1
#define CONFIG_HAS_TIMER 1
#define CONFIG_HAS_VGA 1
#define CONFIG_HAS_KEYBOARD 1
#endif