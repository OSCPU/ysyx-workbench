#include <NDL.h>
#include <stdio.h>

int SDL_Init(uint32_t flags) {
  return NDL_Init(flags);
}

void SDL_Quit() {
  NDL_Quit();
}

char *SDL_GetError() {
  return "Navy does not support SDL_GetError()";
}

int SDL_SetError(const char* fmt, ...) {
  printf("[SDL_SetError] 未实现\n");
  return -1;
}

int SDL_ShowCursor(int toggle) {
  printf("[SDL_ShowCursor] 未实现\n");
  return 0;
}

void SDL_WM_SetCaption(const char *title, const char *icon) {
  //printf("[SDL_WM_SetCaption] 未实现\n");
}
