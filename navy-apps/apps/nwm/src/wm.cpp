#include <nwm.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <NDL.h>

const int tile_shift = 4;

WindowManager::WindowManager(int width, int height): w(width), h(height) {
  tw = w / (1 << tile_shift) + 1;
  th = h / (1 << tile_shift) + 1;
  changed = new bool [tw * th];
  fb = new uint32_t[w * h];
  font = new BDF_Font("/share/fonts/Courier-7.bdf");
  title_font = new BDF_Font("/share/fonts/Courier-8.bdf");
  focus = nullptr;
  display_switcher = false;
  display_appfinder = true;
  memset(windows, 0, sizeof(windows));
  background = new BgImage(this, width, height);
  switcher = new WindowSwitcher(this, width, height);
  appfinder = new AppFinder(this);
  render();
}

WindowManager::~WindowManager() {
  delete [] fb;
  delete [] changed;
  delete font;
  delete title_font;
  delete background;
  delete switcher;
}

Window *WindowManager::spawn(const char *path, const char *argv[]) {
  static int wx = 0, wy = 0;
  char navyhome[128];
  snprintf(navyhome, sizeof(navyhome), "NAVY_HOME=%s", getenv("NAVY_HOME"));
#ifdef __ISA_NATIVE__
  char ld_preload[256];
  snprintf(ld_preload, sizeof(ld_preload), "LD_PRELOAD=%s/libs/libos/build/native.so", getenv("NAVY_HOME"));
#endif
  const char *envp[] = {
    "NWM_APP=1",
#ifdef __ISA_NATIVE__
    ld_preload,
#endif
    navyhome,
    NULL,
  };
  for (Window *&win: windows) {
    if (!win) {
      win = new Window(this, path, argv, envp);
      focus = win;
      win->move(wx, wy);
      wx += 30; wy += 20;
      return win;
    }
  }
  return nullptr;
}

void WindowManager::render() {
  draw_window(background); // TODO: more gracefully handle these
  if (focus) {
    for (auto *win: windows) {
      if (win && win != focus) {
        draw_window(win);
      }
    }
    draw_window(focus);
    if (display_switcher) {
      ((WindowSwitcher*)switcher)->sync();
      draw_window(switcher);
    }
  }

  if (display_appfinder) {
    draw_window(appfinder);
  }

  const int T = 1 << tile_shift;
  for (int y = 0; y < th; y ++) {
    for (int x = 0; x < tw; x ++)
      if (changed[x + y * tw]) {
        int n = 1;
        while (x + n < tw && changed[x + n + y * tw]) n ++;
        for (int i = 0; i < T; i ++) {
          int x1 = x * T, y1 = y * T + i;
          if (y1 >= h) continue;
          int sz = T * n;
          if (x1 + T * n > w) {
            sz -= x1 + T * n - w;
          }
          NDL_DrawRect(&fb[y1 * w + x1], x1, y1, sz, 1);
        }
        x += n - 1;
      }
  }
  memset(changed, false, tw * th);
}

void WindowManager::set_focus(Window *win) {
  if (focus) focus->draw();
  focus = win;
  focus->draw();
}

void WindowManager::draw_px(int x, int y, uint32_t color, bool has_alpha) {
  if (x >= 0 && x < w && y >= 0 && y < h) {
    if (!(has_alpha && (color >> 24) != 0)) {
      fb[y * w + x] = color;
    }
  }
}

void WindowManager::draw_window(Window *win) {
  const int T = (1 << tile_shift);
  for (int x = 0; x < tw; x ++)
    for (int y = 0; y < th; y ++) 
      if (changed[x + y * tw]) {
        int basex = x * T, basey = y * T;
        if (basex + T < win->x) continue;
        if (basey + T < win->y) continue;
        if (basex >= win->x + win->w) continue;
        if (basey >= win->y + win->h) continue;
        for (int i = 0; i < T; i ++)
          for (int j = 0; j < T; j ++) {
            int x1 = basex + i - win->x, y1 = basey + j - win->y;
            if (x1 >= 0 && x1 < win->w && y1 >= 0 && y1 < win->h) {
              draw_px(basex + i, basey + j, win->canvas[y1 * win->w + x1], win->has_alpha);
            }
          }
      }
}

void WindowManager::mark_dirty(int x, int y) {
  if (x >= 0 && y >= 0 && x < w && y < h) {
    changed[tw * (y >> tile_shift) + (x >> tile_shift)] = true;
  }
}
