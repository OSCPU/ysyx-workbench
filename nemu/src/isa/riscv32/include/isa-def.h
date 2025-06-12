/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __ISA_RISCV_H__
#define __ISA_RISCV_H__

#include <common.h>

typedef struct {
  word_t gpr[MUXDEF(CONFIG_RVE, 16, 32)];
  vaddr_t pc;
  word_t csr[4096];
} MUXDEF(CONFIG_RV64, riscv64_CPU_state, riscv32_CPU_state);

// decode
typedef struct {
  uint32_t inst;
} MUXDEF(CONFIG_RV64, riscv64_ISADecodeInfo, riscv32_ISADecodeInfo);

typedef enum {
  INSTRUCTION_ADDRESS_MISALIGNED = 0,
  INSTRUCTION_ACCESS_FAULT,
  ILLEGAL_INSTRUCTION,
  BREAKPOINT,
  LOAD_ADDRESS_MISALIGNED,
  LOAD_ACCESS_FAULT,
  STORE_AMO_ADDRESS_MISALIGNED,
  STORE_AMO_ACCESS_FAULT,
  ENVIRONMENT_CALL_FROM_U_MODE,
  ENVIRONMENT_CALL_FROM_S_MODE,
  RESERVED_1,
  ENVIRONMENT_CALL_FROM_M_MODE,
  INSTRUCTION_PAGE_FAULT,
  LOAD_PAGE_FAULT,
  RESERVED_2,
  STORE_AMO_PAGE_FAULT,
  RESERVED_3,
  SOFTWARE_CHECK,
  HARDWARE_ERROR,
  RESERVED_4,
  DESIGNATED_FOR_CUSTOM_USE_1,
  RESERVED_5,
  DESIGNATED_FOR_CUSTOM_USE_2,
  RESERVED_6,
} mcause_no;

#endif
