#include <common.h>

void init_monitor(int, char *[]);
void cpu_exec(uint64_t n);
void sdb_mainloop();
int  is_exit_status_bad();

int main(int argc, char *argv[])
{
  init_monitor(argc, argv);

  sdb_mainloop();

  return is_exit_status_bad();
}
