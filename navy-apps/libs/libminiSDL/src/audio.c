#include <NDL.h>
#include <SDL.h>

int SDL_OpenAudio(SDL_AudioSpec *desired, SDL_AudioSpec *obtained) {
  //printf("[SDL_OpenAudio] 未实现\n");
  return 0;
}

void SDL_CloseAudio() {
  //printf("[SDL_CloseAudio] 未实现\n");
}

void SDL_PauseAudio(int pause_on) {
  //printf("[SDL_PauseAudio] 未实现\n");
}

void SDL_MixAudio(uint8_t *dst, uint8_t *src, uint32_t len, int volume) {
  //printf("[SDL_MixAudio] 未实现\n");
}

SDL_AudioSpec *SDL_LoadWAV(const char *file, SDL_AudioSpec *spec, uint8_t **audio_buf, uint32_t *audio_len) {
  //printf("[SDL_LoadWAV] 未实现\n");
  return NULL;
}

void SDL_FreeWAV(uint8_t *audio_buf) {
  //printf("[SDL_FreeWAV] 未实现\n");
}

void SDL_LockAudio() {
  //printf("[SDL_LockAudio] 未实现\n");
}

void SDL_UnlockAudio() {
  //printf("[SDL_UnlockAudio] 未实现\n");
}
