#ifndef __SDL_IMAGE_H__
#define __SDL_IMAGE_H__

#include <SDL.h>

#ifdef __cplusplus
extern "C" {
#endif

SDL_Surface* IMG_Load_RW(SDL_RWops *src, int freesrc);
SDL_Surface* IMG_Load(const char *filename);
SDL_Surface* IMG_LoadJPG_RW(SDL_RWops *src);
int IMG_isPNG(SDL_RWops *src);
char* IMG_GetError();

#ifdef __cplusplus
}
#endif

#endif
