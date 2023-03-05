#include <isa.h>
word_t isa_raise_intr(word_t NO, vaddr_t epc)
{
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  /// csr[0] == mtvec csr[1] == mepc csr[2] == mstatus csr[3] == mcause
  cpu.csr[1] = epc;
  cpu.csr[3] = NO;
#ifdef CONFIG_ETRACE
  printf("ecall return 0x%lx\n",cpu.csr[0]);
#endif

  return cpu.csr[0];
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
