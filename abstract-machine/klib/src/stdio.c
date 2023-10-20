#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <string.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int num2str(int num, char *str) {
  int i = 0;
  int isNegative = 0;
  if (num < 0) {
    num = -num;
    isNegative = 1;
  }
  do {
    str[i++] = num % 10 + '0';
    num /= 10;
  } while (num > 0);
  if (isNegative) {
    str[i++] = '-';
  }
  str[i] = '\0';
  int len = 0;
  for(int i = 0; str[i] != '\0'; i++) {
    len++;
  }
  for (int j = 0; j < len / 2; j++) {
    char tmp = str[j];
    str[j] = str[len - j - 1];
    str[len - j - 1] = tmp;
  }
  return len;
}
static void reverse(char *s, int len) {
  char *end = s + len - 1;
  char tmp;
  while (s < end) {
    tmp = *s;
    *s = *end;
    *end = tmp;
    s++;end--;
  }
}static int itoa(int n, char *s, int base) {
  int i = 0, sign = n, bit;
  if (sign < 0) n = -n;
  do {
    bit = n % base;
    if (bit >= 10) s[i++] = 'a' + bit - 10;
    else s[i++] = '0' + bit;
  } while ((n /= base) > 0);
  if (sign < 0) s[i++] = '-';
  s[i] = '\0';
  reverse(s, i);

  return i;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *start = out;

  for(; *fmt != '\0'; ++fmt) {
    if(*fmt != '%') {
      *out = *fmt;
      ++out;
    } else {
      switch (*(++fmt)) {
        case '%':
          *out = *fmt; ++out; break;
        case 'd':
          out += itoa(va_arg(ap, int), out ,10); break;
        case 's':
          char *s = va_arg(ap, char *);
          strcpy(out, s);
          out += strlen(out);
          break;
      }
    }
  }
  *out = '\0';
  return out - start;
        
}

int sprintf(char *out, const char *fmt, ...) {
  int cnt = 0;
  int i;

  va_list args;
  va_start(args, fmt);
  
  for(i = 0; out[i] != '\0'; i++) {
    out[i] = '\0';
  }

  for(i = 0; fmt[i] != '\0'; i++) {
    cnt++;
    if(fmt[i] == '%') {
      i++;
      switch (fmt[i]) {
        case 'd':
          int value = va_arg(args,int);
          int sublen = num2str(value, out+cnt-1);
          cnt += sublen - 1;
          break;
        case 's':
          char *str = va_arg(args,char *);
          for(int ii = 0; str[ii] != '\0'; ii++) {
            out[cnt - 1] = str[ii];
            cnt++;
          }
          cnt--;
          break;
      }
    }
    else {
      out[cnt-1] = fmt[i];
    }
  }

  va_end(args);

  return cnt;
  //panic("Not implemented");
}

int printf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);

  char serial_buf[10000];

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
