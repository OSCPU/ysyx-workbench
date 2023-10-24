#include <am.h>
#include <nemu.h>
#include <klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

typedef struct screen {
  uint32_t W;
  uint32_t H;
} screen;
screen display;

void __am_gpu_init() {
  int i;
  display.W = inl(VGACTL_ADDR) >> 16;
  display.H = inl(VGACTL_ADDR) & 0xffff;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  for(i = 0; i< display.W * display.H; i++) fb[i] = 0;
  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = display.W, .height = display.H,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x;
  int y = ctl->y;
  int w = ctl->w;
  int h = ctl->h;
  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  
  int i,j;
  for(j = y; j < y + h; j++) {
    for(i = x; i < x + w; i++) {
      //fb[j][i] = pixels[j-y][i-x];
      fb[j * display.W + i] = pixels[(j-y) * w + (i-x)];
    }
  }
  
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
