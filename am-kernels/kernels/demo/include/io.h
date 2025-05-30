#ifndef __DRAW_H__

#define HAS_GUI

#include <stdio.h>
#include <am.h>
#include <amdev.h>
#include <klib-macros.h>

#define ANSI_COLOR_RED   31
#define ANSI_COLOR_GREEN 32
#define ANSI_COLOR_WHITE 37
#define ANSI_COLOR_RESET 0

#ifdef HAS_GUI
#define TILE_W 4
#define SCREEN_W 320
#define SCREEN_H 200
static inline void set_color(int c) {
}

static inline void print_char(char c, int y, int x) {
  static char last_c = 0xff;
  static uint32_t buf[TILE_W * TILE_W];
  if (last_c != c) {
    last_c = c;
    uint32_t color = 0x0;
    if (c != ' ') { // convert different character to different color
      uint8_t r = c / 25;
      c -= r * 25;
      uint8_t g = c / 5;
      c -= g * 5;
      uint8_t b = c;
      r = r * 0x100 / 5;
      g = g * 0x100 / 5;
      b = b * 0x100 / 5;
      color = (r << 16) | (g << 8) | b;
    }
    int i;
    for (i = 0; i < TILE_W * TILE_W; i ++) {
      buf[i] = color;
    }
  }
  io_write(AM_GPU_FBDRAW, x * TILE_W, y * TILE_W, buf, TILE_W, TILE_W, false);
}

static inline void screen_clear() {
  static uint32_t buf[SCREEN_W];
  int i;
  for (i = 0; i < SCREEN_H; i ++) {
    io_write(AM_GPU_FBDRAW, 0, i, buf, SCREEN_W, 1, false);
  }
}

static inline void screen_refresh() {
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
}

static inline int screen_tile_height() {
  return io_read(AM_GPU_CONFIG).height / TILE_W;
}

static inline int screen_tile_width() {
  return io_read(AM_GPU_CONFIG).width / TILE_W;
}
#else
static inline void set_color(int c) {
  printf("\033[%dm", c);
}

static inline void print_char(char c, int y, int x) {
  printf("\033[%d;%dH%c", y + 1, x + 1, c);
}

static inline void screen_clear() {
  printf("\033[H\033[J");
}

static inline void screen_refresh() {
}

static inline int screen_tile_height() {
  return 24;
}

static inline int screen_tile_width() {
  return 80;
}
#endif

static inline void usleep(int us) {
  uint64_t now = io_read(AM_TIMER_UPTIME).us;
  uint64_t next = now + us;
  while (io_read(AM_TIMER_UPTIME).us < next) ;
}

#endif
