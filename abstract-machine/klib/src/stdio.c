#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char *substr;
static int sublen;
static int subnum;

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


int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
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
  int cnt = 0;
  int i;

  va_list args;
  va_start(args, fmt);


  for(i = 0; fmt[i] != '\0'; i++) {
    cnt++;
    if(fmt[i] == '%') {
      i++;
      switch (fmt[i]) {
        case 'd':
          subnum = va_arg(args,int);
          sublen = num2str(subnum, substr);
          cnt += sublen - 1;
          putstr(substr);
          break;
        case 's':
          substr = va_arg(args,char *);
          sublen = strlen(substr);
          cnt += sublen - 1;
          putstr(substr);
          break;
      }
    }
    else {
      putch(fmt[i]);
    }
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
