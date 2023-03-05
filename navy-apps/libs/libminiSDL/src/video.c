#include <NDL.h>
#include <sdl-video.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect)
{
  // 判断本体src和被粘贴体dst指针不为空且像素格式相同
  assert(dst && src);
  assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);

  // 定义初始图像信息
  int screen_w,screen_h,x_src,y_src,x_dst,y_dst;

  // srcrect源画布指定位置指针存在
  if(srcrect){
    screen_w = srcrect->w; screen_h = srcrect->h;
    x_src = srcrect->x; y_src = srcrect->y; 
  }
  // 从头复制
  else{
    screen_w = src->w; screen_h = src->h;
    x_src = 0; y_src = 0;
  }
  // dstrect目标画布指定位置指针存在
  if (dstrect) {
    x_dst = dstrect->x, y_dst = dstrect->y;
  }
  // 从头粘贴
  else {
    x_dst = 0; y_dst = 0;
  }

  // 对于像素开始粘贴
  if(src->format->BitsPerPixel == 32){
    uint32_t *pixels_src = (uint32_t *)src->pixels;
    uint32_t *pixels_dst = (uint32_t *)dst->pixels;
    size_t src_pixels = screen_h * src->w;
      for (int i = 0; i < screen_h; ++i)
      {
        for (int j = 0; j < screen_w; ++j)
        {
          pixels_dst[(y_dst + i) * dst->w + x_dst + j] = pixels_src[(y_src + i) * src->w + x_src + j];
        }
      }
  }
  // 只有8位的可以在pal可以，在bird中不行，可能是源和目标图像的像素格式不同导致的。若这个也错就可以改成与上面一样
  else if(src->format->BitsPerPixel == 8){
    uint8_t* pixels_src = (uint8_t*)src->pixels;
    uint8_t* pixels_dst = (uint8_t*)dst->pixels;
    size_t src_pixels = screen_h * src->w;
      for (int i = 0; i < screen_h; ++i)
      {
        for (int j = 0; j < screen_w; ++j)
        {
          pixels_dst[(y_dst + i) * dst->w + x_dst + j] = pixels_src[(y_src + i) * src->w + x_src + j];
        }
      }
  }
  else{
    printf("[SDL_BlitSurface] 使用的像素格式%d未实现\n",src->format->BitsPerPixel);
    assert(0);
  }
}

// 向指定位置写颜色，32和8需要分别讨论因为32位颜色直接写入8位dst->pixels中与实际的8位颜色不一样（这里主要影响能量条和部分字体）
void SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, uint32_t color) {
  assert(dst);
  uint32_t *pixels_32 = (uint32_t *)dst->pixels;
  uint8_t  *pixels_8 = (uint8_t *)dst->pixels;

  // 在x,y处绘制w*h的矩形
  int x, y, w, h;

  // 如果为NULL则全屏幕覆盖
  if (dstrect == NULL) {
    x = 0;      y = 0;
    w = dst->w; h = dst->h;
  }
  // 存在限制向限制大小写颜色
  else {
    x = dstrect->x; y = dstrect->y;
    w = dstrect->w; h = dstrect->h;
  }
  if(dst->format->BitsPerPixel == 32){
  for (int i = 0; i < h; ++ i){
    for (int j = 0; j < w; ++ j){
      pixels_32[(y + i) * dst->w + (x + j)] = color;
    }
  }
  }
  else if(dst->format->BitsPerPixel == 8)
  for (int i = 0; i < h; ++ i){
    for (int j = 0; j < w; ++ j){
      pixels_8[(y + i) * dst->w + (x + j)] = color;
    }
  }
  else{
     printf("[SDL_FillRect] 使用的像素格式%d未实现\n",dst->format->BitsPerPixel);
     assert(0);
  }
}

/*
 SDL_Surface 实质是一个矩形的像素内存
 typedef struct {
   uint32_t flags; // 不用管，用不着
   SDL_PixelFormat *format; // 存储的像素格式，没那么用得着
   int w, h; // 图像的宽高
   uint16_t pitch; // 一行像素的长度（字节）
   uint8_t *pixels; // 指向数据的指针
 } SDL_Surface;
 
 typedef struct {
   SDL_Palette *palette;
   uint8_t BitsPerPixel;
   uint8_t BytesPerPixel;
   uint8_t Rloss, Gloss, Bloss, Aloss;
   uint8_t Rshift, Gshift, Bshift, Ashift;
   uint32_t Rmask, Gmask, Bmask, Amask;
 } SDL_PixelFormat;
typedef struct{
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
}SDL_Color;
*/
// 向s中设置x和y传入ndl，注意根据位数解码下像素
// 因此实际操作是先进行数据解读，再在x,y处绘制w*h的矩形
void SDL_UpdateRect(SDL_Surface *s, int x, int y, int w, int h) {
  assert(s != NULL);
  // 全零则更新写入的s中的默认位置
  if (x == 0 && y == 0 && w == 0 && h == 0) {
    w = s->w; h = s->h;
  }
  // 初始化内存空间用于储存转换后的数据
  uint32_t *pixels = malloc(w * h * sizeof(uint32_t));
  assert(pixels);

  // 32位时可以直接将像素送过去因为argb各8bit是默认配置（真彩色数据）。
  if (s->format->BitsPerPixel == 32) {
    NDL_DrawRect((uint32_t*)s->pixels + y * s->w + x, x, y, w, h);
  }

  // 8位时需要调用调色盘来从新索引像素
  else if (s->format->BitsPerPixel == 8) {
    uint8_t *index = (uint8_t *)s->pixels;
    SDL_Color color;

    for (int i = 0; i < h; ++ i) 
      for (int j = 0; j < w; ++ j) {
        color = s->format->palette->colors[index[(y + i) * s->w + x + j]];
        pixels[i * w + j] = ((color.a << 24) | (color.r << 16) | (color.g << 8) | color.b);
      }

    NDL_DrawRect(pixels, x, y, w, h);
  }
  else {
    printf("[SDL_UpdateRect] 使用的像素格式%d未实现\n",s->format->BitsPerPixel);
    assert(0);
  }

  if (pixels) free(pixels);
}

// APIs below are already implemented.

static inline int maskToShift(uint32_t mask) {
  switch (mask) {
    case 0x000000ff: return 0;
    case 0x0000ff00: return 8;
    case 0x00ff0000: return 16;
    case 0xff000000: return 24;
    case 0x00000000: return 24; // hack
    default: assert(0);
  }
}

SDL_Surface* SDL_CreateRGBSurface(uint32_t flags, int width, int height, int depth,
    uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask) {
  assert(depth == 8 || depth == 32);
  SDL_Surface *s = malloc(sizeof(SDL_Surface));
  assert(s);
  s->flags = flags;
  s->format = malloc(sizeof(SDL_PixelFormat));
  assert(s->format);
  if (depth == 8) {
    s->format->palette = malloc(sizeof(SDL_Palette));
    assert(s->format->palette);
    s->format->palette->colors = malloc(sizeof(SDL_Color) * 256);
    assert(s->format->palette->colors);
    memset(s->format->palette->colors, 0, sizeof(SDL_Color) * 256);
    s->format->palette->ncolors = 256;
  } else {
    s->format->palette = NULL;
    s->format->Rmask = Rmask; s->format->Rshift = maskToShift(Rmask); s->format->Rloss = 0;
    s->format->Gmask = Gmask; s->format->Gshift = maskToShift(Gmask); s->format->Gloss = 0;
    s->format->Bmask = Bmask; s->format->Bshift = maskToShift(Bmask); s->format->Bloss = 0;
    s->format->Amask = Amask; s->format->Ashift = maskToShift(Amask); s->format->Aloss = 0;
  }

  s->format->BitsPerPixel = depth;
  s->format->BytesPerPixel = depth / 8;

  s->w = width;
  s->h = height;
  s->pitch = width * depth / 8;
  assert(s->pitch == width * s->format->BytesPerPixel);

  if (!(flags & SDL_PREALLOC)) {
    s->pixels = malloc(s->pitch * height);
    assert(s->pixels);
  }

  return s;
}

SDL_Surface* SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth,
    int pitch, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask) {
  SDL_Surface *s = SDL_CreateRGBSurface(SDL_PREALLOC, width, height, depth,
      Rmask, Gmask, Bmask, Amask);
  assert(pitch == s->pitch);
  s->pixels = pixels;
  return s;
}

void SDL_FreeSurface(SDL_Surface *s) {
  if (s != NULL) {
    if (s->format != NULL) {
      if (s->format->palette != NULL) {
        if (s->format->palette->colors != NULL) free(s->format->palette->colors);
        free(s->format->palette);
      }
      free(s->format);
    }
    if (s->pixels != NULL && !(s->flags & SDL_PREALLOC)) free(s->pixels);
    free(s);
  }
}

SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, uint32_t flags) {
  if (flags & SDL_HWSURFACE) NDL_OpenCanvas(&width, &height);
  return SDL_CreateRGBSurface(flags, width, height, bpp,
      DEFAULT_RMASK, DEFAULT_GMASK, DEFAULT_BMASK, DEFAULT_AMASK);
}

void SDL_SoftStretch(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect) {
  assert(src && dst);
  assert(dst->format->BitsPerPixel == src->format->BitsPerPixel);
  assert(dst->format->BitsPerPixel == 8);

  int x = (srcrect == NULL ? 0 : srcrect->x);
  int y = (srcrect == NULL ? 0 : srcrect->y);
  int w = (srcrect == NULL ? src->w : srcrect->w);
  int h = (srcrect == NULL ? src->h : srcrect->h);

  assert(dstrect);
  if(w == dstrect->w && h == dstrect->h) {
    /* The source rectangle and the destination rectangle
     * are of the same size. If that is the case, there
     * is no need to stretch, just copy. */
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_BlitSurface(src, &rect, dst, dstrect);
  }
  else {
    assert(0);
  }
}

void SDL_SetPalette(SDL_Surface *s, int flags, SDL_Color *colors, int firstcolor, int ncolors) {
  assert(s);
  assert(s->format);
  assert(s->format->palette);
  assert(firstcolor == 0);

  s->format->palette->ncolors = ncolors;
  memcpy(s->format->palette->colors, colors, sizeof(SDL_Color) * ncolors);

  if(s->flags & SDL_HWSURFACE) {
    assert(ncolors == 256);
    for (int i = 0; i < ncolors; i ++) {
      uint8_t r = colors[i].r;
      uint8_t g = colors[i].g;
      uint8_t b = colors[i].b;
    }
    SDL_UpdateRect(s, 0, 0, 0, 0);
  }
}

static void ConvertPixelsARGB_ABGR(void *dst, void *src, int len) {
  int i;
  uint8_t (*pdst)[4] = dst;
  uint8_t (*psrc)[4] = src;
  union {
    uint8_t val8[4];
    uint32_t val32;
  } tmp;
  int first = len & ~0xf;
  for (i = 0; i < first; i += 16) {
#define macro(i) \
    tmp.val32 = *((uint32_t *)psrc[i]); \
    *((uint32_t *)pdst[i]) = tmp.val32; \
    pdst[i][0] = tmp.val8[2]; \
    pdst[i][2] = tmp.val8[0];

    macro(i + 0); macro(i + 1); macro(i + 2); macro(i + 3);
    macro(i + 4); macro(i + 5); macro(i + 6); macro(i + 7);
    macro(i + 8); macro(i + 9); macro(i +10); macro(i +11);
    macro(i +12); macro(i +13); macro(i +14); macro(i +15);
  }

  for (; i < len; i ++) {
    macro(i);
  }
}

SDL_Surface *SDL_ConvertSurface(SDL_Surface *src, SDL_PixelFormat *fmt, uint32_t flags) {
  assert(src->format->BitsPerPixel == 32);
  assert(src->w * src->format->BytesPerPixel == src->pitch);
  assert(src->format->BitsPerPixel == fmt->BitsPerPixel);

  SDL_Surface* ret = SDL_CreateRGBSurface(flags, src->w, src->h, fmt->BitsPerPixel,
    fmt->Rmask, fmt->Gmask, fmt->Bmask, fmt->Amask);

  assert(fmt->Gmask == src->format->Gmask);
  assert(fmt->Amask == 0 || src->format->Amask == 0 || (fmt->Amask == src->format->Amask));
  ConvertPixelsARGB_ABGR(ret->pixels, src->pixels, src->w * src->h);

  return ret;
}

uint32_t SDL_MapRGBA(SDL_PixelFormat *fmt, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  assert(fmt->BytesPerPixel == 4);
  uint32_t p = (r << fmt->Rshift) | (g << fmt->Gshift) | (b << fmt->Bshift);
  if (fmt->Amask) p |= (a << fmt->Ashift);
  return p;
}

int SDL_LockSurface(SDL_Surface *s) {
   printf("[SDL_LockSurface] 未实现\n");
  return 0;
}

void SDL_UnlockSurface(SDL_Surface *s) {
  printf("[SDL_UnlockSurface] 未实现\n");
}
