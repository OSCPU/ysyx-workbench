#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <string.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define SERIAL_BUF_SIZE 1000

// Description: reverse the input string
// @s         input string
// @len       length of input string
// Return     : none
static void strrev(char *s, int len) {
  char tmp,*start,*end;

  start = s;
  end   = s + len - 1;

  while(start < end) {
    tmp    = *start;
    *start = *end;
    *end   = tmp;

    start++;
    end--;
  }
}
// Description: integer to string
// @n          value of integer
// @s          target string for converting
// @radix      radix eg 10,16...
// Retrun     : the length of string
static int itoa(int n, char *s, int radix) {
  int i, isNegative, bit;

  isNegative = n < 0;
  if(isNegative) n = -n;

  i = 0;
  do {
    bit = n % radix;
    if (bit >= 10) s[i++] = 'a' + bit - 10;
    else s[i++] = '0' + bit;
  } while ((n /= radix) > 0);

  if (isNegative) s[i++] = '-';

  s[i] = '\0';

  strrev(s, i);

  return i;
}

// Description: unsigned integer to string
// @n          value of integer
// @s          target string for converting
// @radix      radix eg 10,16...
static int uitoa(unsigned int n, char *s, int radix) {
  int i, bit;

  i = 0;
  do {
    bit = n % radix;
    if (bit >= 10) s[i++] = 'a' + bit - 10;
    else s[i++] = '0' + bit;
  } while ((n /= radix) > 0);

  s[i] = '\0';

  strrev(s, i);

  return i;
}
int vsprintf(char *out, const char *fmt, va_list ap) {
  char *start = out;

  for(; *fmt != '\0'; ++fmt) {
    if(*fmt != '%') {            // normal character
      *out = *fmt;
      ++out;
    } else {                     // charachter with format
      switch (*(++fmt)) {        // skip to next character
        case '%':
          *out = *fmt;
          ++out;
          break;
        case 'b':
          out += itoa(va_arg(ap, int), out, 2);
          break;
        case 'o':
          out += itoa(va_arg(ap, int), out, 8);
          break;
        case 'd':
          out += itoa(va_arg(ap, int), out, 10);
          break;
        case 'u':
          out += uitoa(va_arg(ap, int), out, 10);
          break;
        case 'x':case 'X':
          out += itoa(va_arg(ap, int), out, 16);
          break;
        case 's':
          strcpy(out, va_arg(ap, char *));
          out += strlen(out);
          break;
        case 'p':
          out += uitoa(va_arg(ap, int), out, 16);
          break;
      }
    }
  }
  *out = '\0';
  return out - start;
        
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  int cnt = vsprintf(out, fmt, args);

  va_end(args);

  return cnt;
}

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  char serial_buf[SERIAL_BUF_SIZE];

  int cnt = vsprintf(serial_buf, fmt, args);
  int i;
  for(i = 0; i < cnt; i++) {
    putch(serial_buf[i]);
  }

  va_end(args);

  return cnt;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
