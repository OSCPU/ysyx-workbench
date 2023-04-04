#include <isa.h>
#include <memory/paddr.h>

// paddr_t m_tra[M_TRACEL];
// int m_len[M_TRACEL];
// int m_cnt=0;
word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
  paddr_write(addr, len, data);
}
