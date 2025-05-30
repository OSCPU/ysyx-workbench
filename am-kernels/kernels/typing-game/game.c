#include <am.h>
#include <klib.h>
#include <klib-macros.h>

#define FPS            30
#define CPS             5
#define CHAR_W          8
#define CHAR_H         16
#define NCHAR         128
#define COL_WHITE    0xeeeeee
#define COL_RED      0xff0033
#define COL_GREEN    0x00cc33
#define COL_PURPLE   0x2a0a29

enum { WHITE = 0, RED, GREEN, PURPLE };
struct character {
  char ch;
  int x, y, v, t;
} chars[NCHAR];

int screen_w, screen_h, hit, miss, wrong;
uint32_t texture[3][26][CHAR_W * CHAR_H], blank[CHAR_W * CHAR_H];

int min(int a, int b) {
  return (a < b) ? a : b;
}

int randint(int l, int r) {
  return l + (rand() & 0x7fffffff) % (r - l + 1);
}

void new_char() {
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (!c->ch) {
      c->ch = 'A' + randint(0, 25);
      c->x = randint(0, screen_w - CHAR_W);
      c->y = 0;
      c->v = (screen_h - CHAR_H + 1) / randint(FPS * 3 / 2, FPS * 2);
      c->t = 0;
      return;
    }
  }
}

void game_logic_update(int frame) {
  if (frame % (FPS / CPS) == 0) new_char();
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (c->ch) {
      if (c->t > 0) {
        if (--c->t == 0) {
          c->ch = '\0';
        }
      } else {
        c->y += c->v;
        if (c->y < 0) {
          c->ch = '\0';
        }
        if (c->y + CHAR_H >= screen_h) {
          miss++;
          c->v = 0;
          c->y = screen_h - CHAR_H;
          c->t = FPS;
        }
      }
    }
  }
}

void render() {
  static int x[NCHAR], y[NCHAR], n = 0;

  for (int i = 0; i < n; i++) {
    io_write(AM_GPU_FBDRAW, x[i], y[i], blank, CHAR_W, CHAR_H, false);
  }

  n = 0;
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (c->ch) {
      x[n] = c->x; y[n] = c->y; n++;
      int col = (c->v > 0) ? WHITE : (c->v < 0 ? GREEN : RED);
      io_write(AM_GPU_FBDRAW, c->x, c->y, texture[col][c->ch - 'A'], CHAR_W, CHAR_H, false);
    }
  }
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
  for (int i = 0; i < 40; i++) putch('\b');
  printf("Hit: %d; Miss: %d; Wrong: %d", hit, miss, wrong);
}

void check_hit(char ch) {
  int m = -1;
  for (int i = 0; i < LENGTH(chars); i++) {
    struct character *c = &chars[i];
    if (ch == c->ch && c->v > 0 && (m < 0 || c->y > chars[m].y)) {
      m = i;
    }
  }
  if (m == -1) {
    wrong++;
  } else {
    hit++;
    chars[m].v = -(screen_h - CHAR_H + 1) / (FPS);
  }
}


void video_init() {
  screen_w = io_read(AM_GPU_CONFIG).width;
  screen_h = io_read(AM_GPU_CONFIG).height;

  extern char font[];
  for (int i = 0; i < CHAR_W * CHAR_H; i++)
    blank[i] = COL_PURPLE;

  uint32_t blank_line[screen_w];
  for (int i = 0; i < screen_w; i++)
    blank_line[i] = COL_PURPLE;

  for (int y = 0; y < screen_h; y ++)
    io_write(AM_GPU_FBDRAW, 0, y, blank_line, screen_w, 1, false);

  for (int ch = 0; ch < 26; ch++) {
    char *c = &font[CHAR_H * ch];
    for (int i = 0, y = 0; y < CHAR_H; y++)
      for (int x = 0; x < CHAR_W; x++, i++) {
        int t = (c[y] >> (CHAR_W - x - 1)) & 1;
        texture[WHITE][ch][i] = t ? COL_WHITE : COL_PURPLE;
        texture[GREEN][ch][i] = t ? COL_GREEN : COL_PURPLE;
        texture[RED  ][ch][i] = t ? COL_RED   : COL_PURPLE;
      }
  }
}

char lut[256] = {
  [AM_KEY_A] = 'A', [AM_KEY_B] = 'B', [AM_KEY_C] = 'C', [AM_KEY_D] = 'D',
  [AM_KEY_E] = 'E', [AM_KEY_F] = 'F', [AM_KEY_G] = 'G', [AM_KEY_H] = 'H',
  [AM_KEY_I] = 'I', [AM_KEY_J] = 'J', [AM_KEY_K] = 'K', [AM_KEY_L] = 'L',
  [AM_KEY_M] = 'M', [AM_KEY_N] = 'N', [AM_KEY_O] = 'O', [AM_KEY_P] = 'P',
  [AM_KEY_Q] = 'Q', [AM_KEY_R] = 'R', [AM_KEY_S] = 'S', [AM_KEY_T] = 'T',
  [AM_KEY_U] = 'U', [AM_KEY_V] = 'V', [AM_KEY_W] = 'W', [AM_KEY_X] = 'X',
  [AM_KEY_Y] = 'Y', [AM_KEY_Z] = 'Z',
};

int main() {
  ioe_init();
  video_init();

  panic_on(!io_read(AM_TIMER_CONFIG).present, "requires timer");
  panic_on(!io_read(AM_INPUT_CONFIG).present, "requires keyboard");

  printf("Type 'ESC' to exit\n");

  int current = 0, rendered = 0;
  uint64_t t0 = io_read(AM_TIMER_UPTIME).us;
  while (1) {
    int frames = (io_read(AM_TIMER_UPTIME).us - t0) / (1000000 / FPS);

    for (; current < frames; current++) {
      game_logic_update(current);
    }

    while (1) {
      AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
      if (ev.keycode == AM_KEY_NONE) break;
      if (ev.keydown && ev.keycode == AM_KEY_ESCAPE) halt(0);
      if (ev.keydown && lut[ev.keycode]) {
        check_hit(lut[ev.keycode]);
      }
    };

    if (current > rendered) {
      render();
      rendered = current;
    }
  }
}
