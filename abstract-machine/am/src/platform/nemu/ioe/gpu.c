#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)
#define WIDTH_ADDR (VGACTL_ADDR + 2)
#define HIGH_ADDR (VGACTL_ADDR)
#define WIDTH 400
#define HIGH  300

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = 0, .height = 0,
    .vmemsz = 0
  };
  cfg->width = inw(WIDTH_ADDR);
  cfg->height = inw(HIGH_ADDR);
}
 //int x, y; void *pixels; int w, h; bool sync
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int i,j;
  if (ctl->sync) {
    outl(SYNC_ADDR, 1); //向vgactl_port_base[1]中写入1,更新画面
  }
  uint32_t *p = (uint32_t *)ctl->pixels; 
  uint32_t *fb = (uint32_t *)(uintptr_t)(FB_ADDR + (ctl->y*WIDTH + ctl->x) * sizeof(uint32_t));
  for(i = 0;i < ctl->h;i++){
    for(j = 0;j < ctl->w;j++)
      fb[j] = *p++;
    fb += WIDTH;
  }
    
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
