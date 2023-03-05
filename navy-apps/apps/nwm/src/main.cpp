#include <nwm.h>
#include <NDL.h>

#define RENDER_FPS 30

int main() {
  int w = 0, h = 0;
  NDL_Init(0);
  NDL_OpenCanvas(&w, &h);
  WindowManager *wm = new WindowManager(w, h);

  uint32_t last = 0, now = 0;
  char buf[64];
  while (1) {
    if (NDL_PollEvent(buf, sizeof(buf))) {
      wm->handle_event(buf);
    }

    if ((now = NDL_GetTicks()) - last > 1000 / RENDER_FPS) {
      wm->handle_event("t");
      last = now;
    }
  }
  return 0;
}
