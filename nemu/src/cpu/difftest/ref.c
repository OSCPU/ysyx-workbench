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

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
    printf("difftest_memcpy called with addr = 0x%8x, buf = %p, size = %zu, direction = %d\n", addr, buf, n, direction);

    if (direction == DIFFTEST_TO_REF) {
        printf("Direction: DIFFTEST_TO_REF, writing data to NEMU memory.\n");

        for (size_t i = 0; i < n; i += 4) {
            uint32_t data = *(uint32_t *)((char *)buf + i); // 读取 4 字节数据
            printf("Writing data: addr = 0x%lx, data = 0x%08x\n", addr + i, data);

            paddr_write(addr + i, 4, data);  // 写入数据到指定地址
        }
    } else {
        printf("Direction: From NEMU, reading data.\n");

        memcpy(buf, guest_to_host(addr), n);  // 从 NEMU 内存读取数据
    }

    printf("difftest_memcpy completed.\n");
}


__EXPORT void difftest_regcpy(void *dut, bool direction) {
 
// direction=0: DUT->REF ; direction=1: REF->DUT
  CPU_state *ref_regs = &cpu;
  if (direction == DIFFTEST_TO_REF) 
	{
    memcpy(ref_regs, dut, sizeof(CPU_state));
  } else {
    memcpy(dut, ref_regs, sizeof(CPU_state));
  }
}



__EXPORT void difftest_exec(uint64_t n) {
if (cpu.pc == 0) {
    cpu.pc = 0x80000000;
    printf("Starting execution at PC = 0x%08x\n", cpu.pc);
  }
	cpu_exec(n);
   // 执行完成后，你可以打印或查看 PC 的状态
  printf("\n");
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
