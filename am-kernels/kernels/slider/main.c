#include <am.h>
#include <klib.h>
#include <klib-macros.h>

extern uint32_t image[][400][300];
extern uint32_t image_end[][400][300];
#define NR_IMG (image_end - image)

void display_image(int i) {
  io_write(AM_GPU_FBDRAW, 0, 0, &image[i][0][0], 400, 300, true);
}

int main() {
  ioe_init();

  int i = 0;
  unsigned long last = 0;
  unsigned long current;

  display_image(i);

  while (1) {
    current = io_read(AM_TIMER_UPTIME).us / 1000;
    if (current - last > 5000) {
      // change image every 5s
      i = (i + 1) % NR_IMG;
      display_image(i);
      last = current;
    }
  }
  return 0;
}
