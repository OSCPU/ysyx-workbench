#include <nterm.h>
#include <SDL.h>
#include <SDL_bdf.h>

static const char *font_fname = "/share/fonts/Courier-7.bdf";
static BDF_Font *font = NULL;
static SDL_Surface *screen = NULL;
Terminal *term = NULL;

void builtin_sh_run();
void extern_app_run(const char *app_path);

int main(int argc, char *argv[]) {
  SDL_Init(0);
  font = new BDF_Font(font_fname);

  // setup display
  int win_w = font->w * W;
  int win_h = font->h * H;
  screen = SDL_SetVideoMode(win_w, win_h, 32, SDL_HWSURFACE);

  term = new Terminal(W, H);

  if (argc < 2) { builtin_sh_run(); }
  else { extern_app_run(argv[1]); }

  // should not reach here
  assert(0);
}

static void draw_ch(int x, int y, char ch, uint32_t fg, uint32_t bg) {
  SDL_Surface *s = BDF_CreateSurface(font, ch, fg, bg);
  SDL_Rect dstrect = { .x = x, .y = y };
  SDL_BlitSurface(s, NULL, screen, &dstrect);
  SDL_FreeSurface(s);
}

void refresh_terminal() {
  int needsync = 0;
  for (int i = 0; i < W; i ++)
    for (int j = 0; j < H; j ++)
      if (term->is_dirty(i, j)) {
        draw_ch(i * font->w, j * font->h, term->getch(i, j), term->foreground(i, j), term->background(i, j));
        needsync = 1;
      }
  term->clear();

  static uint32_t last = 0;
  static int flip = 0;
  uint32_t now = SDL_GetTicks();
  if (now - last > 500 || needsync) {
    int x = term->cursor.x, y = term->cursor.y;
    uint32_t color = (flip ? term->foreground(x, y) : term->background(x, y));
    draw_ch(x * font->w, y * font->h, ' ', 0, color);
    SDL_UpdateRect(screen, 0, 0, 0, 0);
    if (now - last > 500) {
      flip = !flip;
      last = now;
    }
  }
}

#define ENTRY(KEYNAME, NOSHIFT, SHIFT) { SDLK_##KEYNAME, #KEYNAME, NOSHIFT, SHIFT }
static const struct {
  int keycode;
  const char *name;
  char noshift, shift;
} SHIFT[] = {
  ENTRY(ESCAPE,       '\033', '\033'),
  ENTRY(SPACE,        ' ' , ' '),
  ENTRY(RETURN,       '\n', '\n'),
  ENTRY(BACKSPACE,    '\b', '\b'),
  ENTRY(1,            '1',  '!'),
  ENTRY(2,            '2',  '@'),
  ENTRY(3,            '3',  '#'),
  ENTRY(4,            '4',  '$'),
  ENTRY(5,            '5',  '%'),
  ENTRY(6,            '6',  '^'),
  ENTRY(7,            '7',  '&'),
  ENTRY(8,            '8',  '*'),
  ENTRY(9,            '9',  '('),
  ENTRY(0,            '0',  ')'),
  ENTRY(GRAVE,        '`',  '~'),
  ENTRY(MINUS,        '-',  '_'),
  ENTRY(EQUALS,       '=',  '+'),
  ENTRY(SEMICOLON,    ';',  ':'),
  ENTRY(APOSTROPHE,   '\'', '"'),
  ENTRY(LEFTBRACKET,  '[',  '{'),
  ENTRY(RIGHTBRACKET, ']',  '}'),
  ENTRY(BACKSLASH,    '\\', '|'),
  ENTRY(COMMA,        ',',  '<'),
  ENTRY(PERIOD,       '.',  '>'),
  ENTRY(SLASH,        '/',  '?'),
  ENTRY(A,            'a',  'A'),
  ENTRY(B,            'b',  'B'),
  ENTRY(C,            'c',  'C'),
  ENTRY(D,            'd',  'D'),
  ENTRY(E,            'e',  'E'),
  ENTRY(F,            'f',  'F'),
  ENTRY(G,            'g',  'G'),
  ENTRY(H,            'h',  'H'),
  ENTRY(I,            'i',  'I'),
  ENTRY(J,            'j',  'J'),
  ENTRY(K,            'k',  'K'),
  ENTRY(L,            'l',  'L'),
  ENTRY(M,            'm',  'M'),
  ENTRY(N,            'n',  'N'),
  ENTRY(O,            'o',  'O'),
  ENTRY(P,            'p',  'P'),
  ENTRY(Q,            'q',  'Q'),
  ENTRY(R,            'r',  'R'),
  ENTRY(S,            's',  'S'),
  ENTRY(T,            't',  'T'),
  ENTRY(U,            'u',  'U'),
  ENTRY(V,            'v',  'V'),
  ENTRY(W,            'w',  'W'),
  ENTRY(X,            'x',  'X'),
  ENTRY(Y,            'y',  'Y'),
  ENTRY(Z,            'z',  'Z'),
};

char handle_key(const char *buf) {
  char key[32];
  static int shift = 0;
  sscanf(buf + 2, "%s", key);

  if (strcmp(key, "LSHIFT") == 0 || strcmp(key, "RSHIFT") == 0)  { shift ^= 1; return '\0'; }

  if (buf[0] == 'd') {
    if (key[0] >= 'A' && key[0] <= 'Z' && key[1] == '\0') {
      if (shift) return key[0];
      else return key[0] - 'A' + 'a';
    }
    for (auto item: SHIFT) {
      if (strcmp(item.name, key) == 0) {
        if (shift) return item.shift;
        else return item.noshift;
      }
    }
  }
  return '\0';
}

char handle_key(SDL_Event *ev) {
  static int shift = 0;
  int key = ev->key.keysym.sym;
  if (key == SDLK_LSHIFT || key == SDLK_RSHIFT) { shift ^= 1; return '\0'; }

  if (ev->type == SDL_KEYDOWN) {
    for (auto item: SHIFT) {
      if (item.keycode == key) {
        if (shift) return item.shift;
        else return item.noshift;
      }
    }
  }
  return '\0';
}
