/* adapted from http://rosettacode.org/wiki/Conway%27s_Game_of_Life */

#include <stdio.h>
#include <stdlib.h>
#include <io.h>

static int w = 40, h = 25;
static unsigned *new_array = NULL;
static unsigned *univ_array = NULL;

void show(void *u) {
  int x,y;
  int (*univ)[w] = u;
  screen_clear();
  for (y=0;y<h;y++) {
    for (x=0;x<w;x++)
      print_char(univ[y][x] ? 'o' : ' ', y, x);
  }
  screen_refresh();
}

void evolve(void *u) {
  int x,y,x1,y1;
  unsigned (*univ)[w] = u;
  unsigned (*new)[w] = (void *)new_array;

  for (y=0;y<h;y++) for (x=0;x<w;x++) {
    int n = 0;
    for (y1 = y - 1; y1 <= y + 1; y1++)
      for (x1 = x - 1; x1 <= x + 1; x1++)
        if (univ[(y1 + h) % h][(x1 + w) % w])
          n++;

    if (univ[y][x]) n--;
    new[y][x] = (n == 3 || (n == 2 && univ[y][x]));
  }
  for (y=0;y<h;y++) for (x=0;x<w;x++) univ[y][x] = new[y][x];
}

void game_of_life(void) {
  w = screen_tile_width();
  h = screen_tile_height();
  univ_array = malloc(h * w * sizeof(unsigned));
  new_array  = malloc(h * w * sizeof(unsigned));
  unsigned (*univ)[w] = (void *)univ_array;

  int x,y;
  for (x=0;x<w;x++)
    for (y=0;y<h;y++) 
      univ[y][x] = rand() % 2;
  while (1) {
    show(univ);
    evolve(univ);
    usleep(200000);
  }
}
