/* adapted from http://rosettacode.org/wiki/Factors_of_a_Mersenne_number#C */
#include "trap.h"

int isPrime(int n) {
  int d = 5;
  if (n % 2 == 0) return n==2;
  if (n % 3 == 0) return n==3;
  while (d * d <= n) {
    if (n % d == 0) return 0;
    d += 2;
    if (n % d == 0) return 0;
    d += 4;
  }
  return 1;
}

int main() {
  int i, d, p, r, q = 929;
  if (!isPrime(q)) return 1; 
  r = q;
  while (r > 0) r <<= 1;
  d = 2 * q + 1;
  do {
    for (p = r, i = 1; p; p <<= 1) {
      i = ((long long)i * i) % d;
      if (p < 0) i *= 2;
      if (i > d) i -= d;
    }
    if (i != 1) d += 2 * q;
    else break;
  } while(1);
  check(d == 13007);
  return 0;
}
