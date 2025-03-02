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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
    bool sign = true;
  int i = 0;
  for(; i < 32; i++)
  {
//		printf("0x%8x  0x%8x ",cpu.gpr[i], ref_r->gpr[i]);
    if(cpu.gpr[i] != ref_r->gpr[i])
    {
			
      sign = false;
      break;
    }
  }
  if(sign && cpu.pc == ref_r->pc)
  {
//		printf("ssdasdad");
    return true;
  }
  pc = ref_r->pc;
//	printf("0x%8x",pc);
	return false;
}

void isa_difftest_attach() {
}
