#include <SDL_ttf.h>
#include <fixedptc.h>
#include <assert.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

int TTF_Init() {
  return 0;
}

TTF_Font* TTF_OpenFont(const char *file, int ptsize) {
  SDL_RWops *f = SDL_RWFromFile(file, "r");
  if (f == NULL) return NULL;
  size_t size = SDL_RWsize(f);
  void *buf = malloc(size);
  assert(buf);
  size_t nread = SDL_RWread(f, buf, size, 1);
  assert(nread == 1);
  SDL_RWclose(f);

  stbtt_fontinfo *finfo = malloc(sizeof(*finfo));
  assert(finfo);
  int ret = stbtt_InitFont(finfo, buf, stbtt_GetFontOffsetForIndex(buf,0));
  assert(ret == 1);

  TTF_Font *font = malloc(sizeof(*font));
  font->finfo = finfo;
  font->file.buf = buf;
  font->file.size = size;
  font->ptsize = ptsize;

  // pre-computed data
  fixedpt pixel = fixedpt_muli(fixedpt_rconst(1.333333), ptsize);
  font->factor = stbtt_ScaleForPixelHeight(finfo, pixel);
  stbtt_GetFontVMetrics(finfo, &font->ascent, &font->descent, NULL);
  font->height = fixedpt_toint(fixedpt_muli(font->factor, font->ascent - font->descent));
  font->ascent = fixedpt_toint(fixedpt_muli(font->factor, font->ascent));
  font->descent = fixedpt_toint(fixedpt_muli(font->factor, font->descent));

  return font;
}

TTF_Font *TTF_OpenFontRW(SDL_RWops *src, int freesrc, int ptsize) {
  assert(0);
  return NULL;
}

int TTF_GlyphMetrics(TTF_Font *font, Uint16 ch, int *minx, int *maxx, int *miny, int *maxy, int *advance) {
  stbtt_fontinfo *finfo = font->finfo;
  int glyphIndex = stbtt_FindGlyphIndex(finfo, ch);
  if (glyphIndex == 0) return -1;
  int ret = stbtt_GetGlyphBox(finfo, glyphIndex, minx, miny, maxx, maxy);
  if (ret == 0) return -1;
  if (minx) *minx = fixedpt_toint(fixedpt_muli(font->factor, *minx));
  if (miny) *miny = fixedpt_toint(fixedpt_muli(font->factor, *miny));
  if (maxx) *maxx = fixedpt_toint(fixedpt_muli(font->factor, *maxx));
  if (maxy) *maxy = fixedpt_toint(fixedpt_muli(font->factor, *maxy));
  assert(advance == NULL); // not implemented
  return 0;
}

int TTF_FontAscent(TTF_Font *font) {
  return font->ascent;
}

int TTF_FontHeight(TTF_Font *font) {
  return font->height;
}

static struct {
  SDL_Color fg, bg;
  SDL_Color palette[256];
} palCache = {};

SDL_Surface *TTF_RenderGlyph_Shaded(TTF_Font *font, Uint16 ch, SDL_Color fg, SDL_Color bg) {
  stbtt_fontinfo *finfo = font->finfo;
  int glyphIndex = stbtt_FindGlyphIndex(finfo, ch);
  if (glyphIndex == 0) return NULL;
  int w, h;
  uint8_t *pixels = stbtt_GetGlyphBitmap(finfo, 0, font->factor, glyphIndex, &w, &h, NULL, NULL);

  SDL_Surface *s = SDL_CreateRGBSurfaceFrom(pixels, w, h, 8, w, 0, 0, 0, 0);
  s->flags &= ~SDL_PREALLOC;
  if (!(fg.val == palCache.fg.val && bg.val == palCache.bg.val)) {
    // cache miss
    int rdiff = fg.r - bg.r;
    int gdiff = fg.g - bg.g;
    int bdiff = fg.b - bg.b;
    int adiff = fg.a - bg.a;
    for (int i = 0; i < 256; i ++) {
      palCache.palette[i].r = bg.r + (i*rdiff) / 255;
      palCache.palette[i].g = bg.g + (i*gdiff) / 255;
      palCache.palette[i].b = bg.b + (i*bdiff) / 255;
      palCache.palette[i].a = bg.a + (i*adiff) / 255;
    }
    palCache.palette[0].a = bg.a;
    palCache.fg.val = fg.val;
    palCache.bg.val = bg.val;
  }
  memcpy(s->format->palette->colors, palCache.palette, sizeof(palCache.palette));
  return s;
}
