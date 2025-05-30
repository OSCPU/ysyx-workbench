/* from http://rosettacode.org/wiki/Execute_Brain****#C */
/* This is the Neutron brainfuck interpreter.
 * It's rather small and dense, but still readable, more or less.
 *
 * Robert de Bath -- 2013.
 */
#include <am.h>
#include <klib.h>
#include <io.h>

static const char *prog =
#include "mandelbrot.h"
;

struct bfi { char cmd; struct bfi *next, *jmp; };
struct mem { char val; struct mem *next, *prev; };

static inline void putch2(char c) {
  static int x = 0, y = 0;
  if (c == '\n') {
    y ++;
    x = 0;
  } else {
    if (x % 2 == 0) {
      print_char(c, y, x / 2);
      screen_refresh();
    }
    x ++;
  }
}

void bf() {
  int ch;
  struct bfi *p=0, *n=0, *j=0, *pgm = 0;
  struct mem *m = malloc(sizeof(*m));
  struct mem *mhead = m;
  memset(m, 0, sizeof(*m));
  screen_clear();

  /*
   *  For each character, if it's a valid BF command add it onto the
   *  end of the program. If the input is stdin use the '!' character
   *  to mark the end of the program and the start of the data, but
   *  only if we have a complete program.  The 'j' variable points
   *  at the list of currently open '[' commands, one is matched off
   *  by each ']'.  A ']' without a matching '[' is not a legal BF
   *  command and so is ignored.  If there are any '[' commands left
   *  over at the end they are not valid BF commands and so are ignored.
   */
  const char *s = prog;
  while((ch = *(s ++)) != '\0') {
    if (ch == '<' || ch == '>' || ch == '+' || ch == '-' ||
        ch == ',' || ch == '.' || ch == '[' || (ch == ']' && j)) {
      if ((n = malloc(sizeof(*n))) == NULL) {
        printf("malloc failed! exiting...\n");
        halt(1);
      }
      memset(n, 0, sizeof(*n));
      if (p) p->next = n; else pgm = n;
      n->cmd = ch; p = n;
      if (n->cmd == '[') { n->jmp=j; j = n; }
      else if (n->cmd == ']') {
        n->jmp = j; j = j->jmp; n->jmp->jmp = n;
      }
    }
  }

  /* Ignore any left over '[' commands */
  while(j) { p = j; j = j->jmp; p->jmp = 0; p->cmd = ' '; }

  /* Execute the loaded BF program */
  for(n=pgm; n; n=n->next) {
    switch(n->cmd) {
      case '+': m->val++; break;
      case '-': m->val--; break;
      case '.': putch2(m->val); break;
      case ',': if((ch=*(s ++))!='\0') m->val=ch; break;
      case '[': if (m->val == 0) n=n->jmp; break;
      case ']': if (m->val != 0) n=n->jmp; break;
      case '<':
        if (!(m=m->prev)) {
          printf("Hit start of tape\n");
          halt(1);
        }
        break;
      case '>':
        if (m->next == 0) {
          if ((m->next = malloc(sizeof(*m))) == NULL) {
            printf("malloc failed! exiting...\n");
            halt(1);
          }
          memset(m->next, 0, sizeof(*m));
          m->next->prev = m;
        }
        m=m->next;
        break;
    }
  }

  while (mhead != NULL) {
    m = mhead;
    mhead = mhead->next;
    free(m);
  }
  while (pgm != NULL) {
    n = pgm;
    pgm = pgm->next;
    free(n);
  }
}
