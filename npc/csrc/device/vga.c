#include <common.h>

#define SCREEN_W (MUXDEF(CONFIG_VGA_SIZE_800x600, 800, 400))
#define SCREEN_H (MUXDEF(CONFIG_VGA_SIZE_800x600, 600, 300))

static uint32_t screen_width() {
  return SCREEN_W;
}

static uint32_t screen_height() {
  return SCREEN_H;
}

static uint32_t screen_size() {
  return screen_width() * screen_height() * sizeof(uint32_t);
}

static void *vmem = NULL;
static uint32_t *vgactl_port_base = NULL;


#include <SDL2/SDL.h>

static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

#ifdef CONFIG_HAS_VGA
static void init_screen() {                                                  
  SDL_Window *window = NULL;
  char title[128];
  sprintf(title, "npc-riscv64");
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(
			SCREEN_W * 2,
			SCREEN_H * 2,
      0, &window, &renderer);
  SDL_SetWindowTitle(window, title);
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
}
#endif

static inline void update_screen() {
  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
}


void vga_update_screen() {
  // TODO: call `update_screen()` when the sync register is non-zero,
  // then zero out the sync register
  if(*(vgactl_port_base+1)!=0)
  {
    update_screen();
    (*(vgactl_port_base+1))=0;
  }
}

void init_vga() {
  vgactl_port_base = (uint32_t *)new_space(8);                         //vga_base
  vgactl_port_base[0] = (screen_width() << 16) | screen_height();
  add_mmio_map("vgactl", VGACTL_ADDR, vgactl_port_base, 8, NULL);

  vmem = new_space(screen_size());
  add_mmio_map("vmem", FB_ADDR, vmem, screen_size(), NULL);
  IFDEF(CONFIG_HAS_VGA, init_screen());
  IFDEF(CONFIG_HAS_VGA, memset(vmem, 0, screen_size()));
}
