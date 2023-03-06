#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

//addr 为写入地址 buf为nemu的内存数据，通过*（*buf+i）管理指针指向的数据
// 在DUT host memory的`buf`和REF guest memory的`dest`之间拷贝`n`字节,
// `direction`指定拷贝的方向, `DIFFTEST_TO_DUT`表示往DUT拷贝, `DIFFTEST_TO_REF`表示往REF拷贝
void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
    if (direction == DIFFTEST_TO_REF) {
    for (size_t i=0; i<n; ++i){
      paddr_write(addr + i,1,*((uint8_t*)buf+i));
    }
  } else {
    assert(0);
  }
}

// `direction`为`DIFFTEST_TO_REF`时, 设置REF的寄存器状态为`dut`;
void difftest_regcpy(void *dut, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    cpu.pc = ((uint64_t*)dut)[32];
    cpu.csr[0] = ((uint64_t*)dut)[33];
    cpu.csr[1] = ((uint64_t*)dut)[34];
    cpu.csr[2] = ((uint64_t*)dut)[35];
    cpu.csr[3] = ((uint64_t*)dut)[36];
    for (int i = 0; i < 32; ++i) {
      cpu.gpr[i] = ((uint64_t*)dut)[i];
    }
  } else {
    ((uint64_t*)dut)[32] = cpu.pc;
    ((uint64_t*)dut)[33] = cpu.csr[0];
    ((uint64_t*)dut)[34] = cpu.csr[1];
    ((uint64_t*)dut)[35] = cpu.csr[2];
    ((uint64_t*)dut)[36] = cpu.csr[3];
    for (int i = 0; i < 32; ++i) {
      ((uint64_t*)dut)[i] = cpu.gpr[i];
    }
  }
}

void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

void difftest_raise_intr(word_t NO) {
  assert(0);
}

void difftest_init() {
  /* Perform ISA dependent initialization. */
  init_isa();
}
