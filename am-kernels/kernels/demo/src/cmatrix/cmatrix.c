/************************************************************************

  The Matrix Rain Screen Saver

  This code is converted from QBASIC to C.

  QBasic Code from
http://codegolf.stackexchange.com/questions/17285/make-the-matrix-digital-rain-using-the-shortest-amount-of-code

 ************************************************************************/

#include <stdlib.h>
#include <am.h>
#include <io.h>

#define W 80
#define H 24

static int t[W];

static void sub_d(int p, int s, int x, int y) {
  uint8_t r = (p % 16) * 16;
  uint8_t g = 180 - p;
  if (r < 10) {
//    set_color(ANSI_COLOR_RESET);
  }
  else {
    if (g > 170) {
      set_color(ANSI_COLOR_WHITE);
    }
    else if (g < 170) {
      set_color(ANSI_COLOR_GREEN);
    }
  }

  if ((y >= 0) && (y < H) && (x < W)) {
    char c = (r < 10 ? ' ' : 33 + (x * y) % 94);
    print_char(c, y, x);
        //)vt_draw_char_at(y, x, c);
  }
}

void cmatrix() {
  int i, x, y, k;
  screen_clear();

  x = rand();
  for (i = 0; i < W; i++) {
    t[i] = - rand() % 50;
  }

  sub_d(1,1,10,10);

  while (1) {
    for (k = 1; k < W; k++) {
      i = rand() % (W-1);
      if (t[i] > 28)t[i] = 0;
      t[i] = t[i] + 1;
      y = t[i];
      sub_d( 0     , 0, i, y - 6);
      sub_d( 2  + x, 0, i, y - 5);
      sub_d( 2  + x, 0, i, y - 4);
      sub_d( 10 + x, 0, i, y - 3);
      sub_d( 10 + x, 0, i, y - 2);
      sub_d( 11 + x, 0, i, y - 1);
      sub_d( 0     , 2 + x, i, y);
    }

    screen_refresh();
    usleep(100000);
  }
}
