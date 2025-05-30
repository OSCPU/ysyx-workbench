/* from http://rosettacode.org/wiki/Galton_box_animation#C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#define BALLS 1024
#define N 8
#define W (N * 2 + 1)
#define H_MAX 50
#define H_MIN 30
static int h = 0;
static int *x = NULL, *y = NULL, cnt = 0;
static char *b = NULL;

#define B(y, x) b[(y)*W + x]
#define C(y, x) ' ' == b[(y)*W + x]
#define V(i) B(y[i], x[i])
static int rnd(int a) { return rand() % a; }

static void show_board() {
  int i, j;
  for (i = 0; i < h; i++)
    for (j = 0; j < W; j++) {
      if (B(i, j) == '*') {
        set_color(C(i - 1, j) ? ANSI_COLOR_GREEN : ANSI_COLOR_RED);
        print_char(B(i, j), i, 2 * j);
        set_color(ANSI_COLOR_RESET);
      } else {
        print_char(B(i, j), i, 2 * j);
      }
      print_char(' ', i, 2 * j + 1);
    }
  screen_refresh();
}

static void init() {
  int i, j;
  screen_clear();
  b = malloc(W * h);
  memset(b, ' ', W * h);

  x = malloc(sizeof(int) * BALLS * 2);
  y = x + BALLS;

  for (i = 0; i < N; i++)
    for (j = -i; j <= i; j += 2)
      B(2 * i+2, j + W/2) = '*';
}

static void move(int idx) {
  int xx = x[idx], yy = y[idx], c, kill = 0, sl = 3, o = 0;

  if (yy < 0) return;
  if (yy == h - 1) { y[idx] = -1; return; }

  switch(c = B(yy + 1, xx)) {
    case ' ':	yy++; break;
    case '*':	sl = 1;
    default:	if (xx < W - 1 && C(yy, xx + 1) && C(yy + 1, xx + 1))
                if (!rnd(sl++)) o = 1;
              if (xx && C(yy, xx - 1) && C(yy + 1, xx - 1))
                if (!rnd(sl++)) o = -1;
              if (!o) kill = 1;
              xx += o;
  }

  c = V(idx); V(idx) = ' ';
  idx[y] = yy, idx[x] = xx;
  B(yy, xx) = c;
  if (kill) idx[y] = -1;
}

static int run(void) {
  static int step = 0;
  int i;
  for (i = 0; i < cnt; i++) move(i);
  if (2 == ++step && cnt < BALLS) {
    step = 0;
    x[cnt] = W/2;
    y[cnt] = 0;
    if (V(cnt) != ' ') return 0;
    V(cnt) = rnd(80) + 43;
    cnt++;
  }
  return 1;
}

void galton() {
  h = screen_tile_height() - 2;
  if (h > H_MAX) h = H_MAX;
  if (h < H_MIN) h = H_MIN;
  init();
  do { show_board(), usleep(6000); } while (run());
  free(x);
  free(b);
}
