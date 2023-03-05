#include <SDL_bdf.h>
#include <stdlib.h>
#include <assert.h>

SDL_Surface* BDF_CreateSurface(BDF_Font *font, char ch, uint32_t fg, uint32_t bg) {
  uint32_t *bm = font->font[ch];
  if (!bm) return NULL;
  int w = font->w, h = font->h;
  uint32_t *pixels = (uint32_t *)malloc(w * h * sizeof(uint32_t));
  assert(pixels);
  for (int j = 0; j < h; j ++) {
    for (int i = 0; i < w; i ++) {
      pixels[j * w + i] = ((bm[j] >> i) & 1) ? fg : bg;
    }
  }
  SDL_Surface *s = SDL_CreateRGBSurfaceFrom(pixels, w, h, 32, w * sizeof(uint32_t),
      DEFAULT_RMASK, DEFAULT_GMASK, DEFAULT_BMASK, DEFAULT_AMASK);
  s->flags &= ~SDL_PREALLOC;
  return s;
}
