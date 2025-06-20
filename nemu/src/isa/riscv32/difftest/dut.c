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
#define NUM_REG 32

const char *regs_diff[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

bool isa_difftest_checkregs(CPU_state *ref_r , vaddr_t pc){
  bool flag = true;
  int i;
  if(ref_r -> pc != cpu.pc) flag = false;
  for(i = 0;i < NUM_REG;i++){
    if(ref_r -> gpr[i] != cpu.gpr[i])
      flag = false;
  }
  if(flag == false){
    printf("ref-pc=%x\n",ref_r -> pc);
    for(i = 0;i < NUM_REG;i++){
    if(ref_r -> gpr[i] >= 0x80000000){
        printf("ref-%3s = %-#11x",regs_diff[i],ref_r -> gpr[i]);
        if(i % 3 == 0) printf("\n");
        }
    else{
        printf("ref-%3s = %-11d",regs_diff[i],ref_r -> gpr[i]);
        if(i % 3 == 0) printf("\n");
        } 
    }
    printf("\n");
  }
  return flag;
}

void isa_difftest_attach() {
}
