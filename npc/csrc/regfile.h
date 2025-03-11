// regfile.h
#ifndef __REGFILE_H__
#define __REGFILE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// 声明 DPI-C 接口函数，注意这里的具体符号名与 RTL 中导出的函数名需一致
void get_gpr(uint32_t regs[32]);

#ifdef __cplusplus
}
#endif

#endif

