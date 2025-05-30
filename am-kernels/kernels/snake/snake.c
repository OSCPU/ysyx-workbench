#include <stdlib.h>
#include <stdio.h>
#include <am.h>
#include <amdev.h>
#include <klib-macros.h>

#define MAX_LENGTH 100
#define TILE_W 8

typedef enum { NONE, UP, DOWN, LEFT, RIGHT } dir_t;

typedef struct {
  int x, y;
} point_t;

typedef struct {
  int width, height;
} dim_t;

typedef struct {
  int top, bottom, left, right;
} rect_t;

typedef struct {
  point_t body[MAX_LENGTH];
  int length;
  int index;
  int dead;
} snake_t;

static void refresh() {
  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);
}

static void draw_tile(int y, int x, uint32_t color) {
  static uint32_t buf[TILE_W * TILE_W];
  uint32_t last_color = 0xffffffff;
  if (last_color != color) {
    for (int i = 0; i < LENGTH(buf); i ++) { buf[i] = color; }
  }
  io_write(AM_GPU_FBDRAW, x * TILE_W, y * TILE_W, buf, TILE_W, TILE_W, false);
}

static int read_key() {
  while (1) {
    AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
    if (ev.keydown || ev.keycode == AM_KEY_NONE) return ev.keycode;
  }
}

static point_t create_food(dim_t game_size) {
  point_t f;
  f.x = rand() % game_size.width;
  f.y = rand() % game_size.height;
  return f;
}

static void print_board(rect_t board) {
  uint32_t color = 0x0000ff00;
  for (int i = board.left; i <= board.right; i++) {
    draw_tile(board.top, i, color);
    draw_tile(board.bottom, i, color);
  }
  for (int i = board.top; i <= board.bottom; i++) {
    draw_tile(i, board.left, color);
    draw_tile(i, board.right, color);
  }
}

static void print_food(point_t food, rect_t board) {
  draw_tile(food.y + board.top + 1, food.x + board.left + 1, 0x000000ff);
}

static void print_head(snake_t* snake, rect_t board) {
  point_t *p = &snake->body[snake->index];
  draw_tile(p->y + board.top + 1, p->x + board.left + 1, 0x00ff0000);
}

static void clear_tail(snake_t* snake, rect_t board) {
  int t = snake->index-snake->length;
  if (t < 0) { t += MAX_LENGTH; }
  draw_tile(snake->body[t].y + board.top + 1, snake->body[t].x + board.left + 1, 0);
}

static dir_t get_dir(int c) {
  switch (c) {
    case AM_KEY_LEFT:  return LEFT;
    case AM_KEY_UP:    return UP;
    case AM_KEY_RIGHT: return RIGHT;
    case AM_KEY_DOWN:  return DOWN;
    default: return NONE;
  }
}

static void move_snake(snake_t* snake, dir_t dir) {
  point_t p = snake->body[snake->index];
  switch (dir) {
    case LEFT:  p.x --; break;
    case DOWN:  p.y ++; break;
    case RIGHT: p.x ++; break;
    case UP:    p.y --; break;
    default: break;
  }
  snake->index ++;
  if (snake->index == MAX_LENGTH) { snake->index = 0; }
  snake->body[snake->index] = p;
}

static int is_dead(snake_t* snake, dim_t game_size) {
  point_t head = snake->body[snake->index];
  if (head.x == -1) return 1;
  if (head.x == game_size.width) return 1;
  if (head.y == -1) return 1;
  if (head.y == game_size.height) return 1;

  for (int i = 1; i != snake->length; i ++) {
    int j = snake->index-i;
    if (j < 0) { j += MAX_LENGTH; }
    if (head.x == snake->body[j].x && head.y == snake->body[j].y) { return 1; }
  }
  return 0;
}

static int has_food(snake_t* snake, point_t food) {
  return snake->body[snake->index].x == food.x && snake->body[snake->index].y == food.y;
}

int main() {
  snake_t snake = {0};
  rect_t board;
  dim_t screen;
  dim_t game_size;
  dir_t dir = RIGHT;

  ioe_init();
  screen.height = io_read(AM_GPU_CONFIG).height / TILE_W;
  screen.width  = io_read(AM_GPU_CONFIG).width / TILE_W;

  game_size.width  = screen.width - 2;
  game_size.height = screen.height - 2;

  snake.body[0].x = game_size.width  / 2;
  snake.body[0].y = game_size.height / 2;
  snake.body[1].x = game_size.width  / 2;
  snake.body[1].y = game_size.height / 2 + 1;
  snake.length = 2;
  snake.index = 1;

  board.left   = screen.width / 2 - game_size.width / 2 - 1;
  board.right  = board.left + game_size.width + 1;
  board.top    = screen.height / 2 - game_size.height / 2 - 1;
  board.bottom = board.top + game_size.height + 1;
  print_board(board);

  point_t food = create_food(game_size);
  print_food(food, board);
  do {
    print_head(&snake, board);
    clear_tail(&snake, board);

    dir_t move_dir = get_dir(read_key());
    switch (move_dir) {
      case UP:    if (dir != DOWN)  dir = move_dir; break;
      case DOWN:  if (dir != UP)    dir = move_dir; break;
      case LEFT:  if (dir != RIGHT) dir = move_dir; break;
      case RIGHT: if (dir != LEFT)  dir = move_dir; break;
      default: break;
    }

    move_snake(&snake, dir);
    snake.dead = is_dead(&snake, game_size);

    if (has_food(&snake, food)) {
      snake.length ++;
      food = create_food(game_size);
      print_food(food, board);
    }
    refresh();

    uint64_t sleep = 100000 - snake.length * 5000 < 5000 ? 5000 : 100000 - snake.length * 5000;
    uint64_t next_us = io_read(AM_TIMER_UPTIME).us + sleep;
    while (io_read(AM_TIMER_UPTIME).us < next_us) ;
  } while (!snake.dead);

  printf("GAME OVER\nPress Q to Exit\n");
  while (read_key() != AM_KEY_Q);
  return 0;
}
