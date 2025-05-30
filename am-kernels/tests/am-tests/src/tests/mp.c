#include <amtest.h>

void mp_print() {
  while (1) {
    printf("%d", cpu_current());
  }
}
