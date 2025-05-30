/**
 * Original author:
 * https://twitter.com/a1k0n
 * https://www.a1k0n.net/2021/01/13/optimizing-donut.html
 *
 * Change Logs:
 * Date           Author       Notes
 * 2006-09-15     Andy Sloane  First version
 * 2011-07-20     Andy Sloane  Second version
 * 2021-01-13     Andy Sloane  Third version
 * 2021-03-25     Meco Man     Port to RT-Thread RTOS
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

#define R(mul,shift,x,y) \
  _=x; \
  x -= mul*y>>shift; \
  y += mul*_>>shift; \
  _ = (3145728-x*x-y*y)>>11; \
  x = x*_>>10; \
  y = y*_>>10;

static char b[1760];
static signed char z[1760];

void donut(void) {
  int sA = 1024, cA = 0, sB = 1024, cB = 0, _;

  while(1) {
    memset(b, 32, 1760);  // text buffer
    memset(z, 127, 1760);   // z buffer
    int sj = 0, cj = 1024;
    for (int j = 0; j < 90; j++) {
      int si = 0, ci = 1024;  // sine and cosine of angle i
      for (int i = 0; i < 324; i++) {
        int R1 = 1, R2 = 2048, K2 = 5120*1024;

        int x0 = R1*cj + R2,
            x1 = ci*x0 >> 10,
            x2 = cA*sj >> 10,
            x3 = si*x0 >> 10,
            x4 = R1*x2 - (sA*x3 >> 10),
            x5 = sA*sj >> 10,
            x6 = K2 + R1*1024*x5 + cA*x3,
            x7 = cj*si >> 10,
            x = 25 + 30*(cB*x1 - sB*x4)/x6,
            y = 12 + 15*(cB*x4 + sB*x1)/x6,
            N = (((-cA*x7 - cB*((-sA*x7>>10) + x2) - ci*(cj*sB >> 10)) >> 10) - x5) >> 7;

        int o = x + 80 * y;
        signed char zz = (x6-K2)>>15;
        if (22 > y && y > 0 && x > 0 && 80 > x && zz < z[o]) {
          z[o] = zz;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
        R(5, 8, ci, si)  // rotate i
      }
      R(9, 7, cj, sj)  // rotate j
    }
    R(5, 7, cA, sA);
    R(5, 8, cB, sB);

    screen_clear();
    int y = 0, x = 0;
    for (int k = 0; 1761 > k; k++) {
      if (k % 80) {
        if (x < 50) print_char(b[k], y, x);
        x ++;
      } else {
        y ++;
        x = 1;
      }
    }
    
    screen_refresh();
    usleep(100000);
  }
}
