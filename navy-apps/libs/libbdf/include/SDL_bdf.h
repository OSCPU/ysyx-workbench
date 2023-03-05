#ifndef __SDL_BDF_H__
#define __SDL_BDF_H__

#include <BDF.h>
#include <SDL.h>

SDL_Surface* BDF_CreateSurface(BDF_Font *font, char ch, uint32_t fg, uint32_t bg);

#endif
