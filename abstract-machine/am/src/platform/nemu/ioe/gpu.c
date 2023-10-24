#include <am.h>
#include <nemu.h>
#include <klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  //int i;
  //int W = inl(VGACTL_ADDR) >> 16;
  //int H = inl(VGACTL_ADDR) & 0xffff;
  //uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  //for(i = 0; i< W * H; i++) fb[i] = i;
  //outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t vga_ctr = inl(VGACTL_ADDR);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = vga_ctr >> 16, .height = vga_ctr & 0xffff,
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

  uint32_t W = inl(VGACTL_ADDR) >> 16;
  uint32_t H = inl(VGACTL_ADDR) & 0xffff;

  assert(x < W && y < H);
  
  int i,j;
  for(j = y; j < y + h; j++) {
    for(i = x; i < x + w; i++) {
      //fb[j][i] = pixels[j-y][i-x];
      fb[j * W + i] = pixels[(j-y) * w + (i-x)];
    }
  }
  
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
