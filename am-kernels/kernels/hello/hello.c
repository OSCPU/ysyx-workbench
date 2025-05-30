#include <am.h>
#include <klib-macros.h>
#include <stdio.h>

int main(const char *args) {
  const char *fmt =
    "Hello, AbstractMachine!\n"
    "mainargs = '%'.\n";

  for (const char *p = fmt; *p; p++) {
    (*p == '%') ? putstr(args) : putch(*p);
  }
  char *str = "meowth!";
  int a = 1 * 7 *5;
  printf("11111  %s  %d\n", str, 10 + a);
  return 0;
}
