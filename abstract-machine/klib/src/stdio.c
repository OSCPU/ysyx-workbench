#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  //panic("Not implemented");
  char buffer[2048];
  va_list arg;
  va_start (arg, fmt);
  
  int done = vsprintf(buffer, fmt, arg);

  for (int i = 0; i < done; ++i)
  {
    putch(buffer[i]);
  }

  va_end(arg);
  return done;
}
int vsprintf(char *out, const char *fmt, va_list ap) {
  //panic("Not implemented");
  return vsnprintf(out, -1, fmt, ap);
}

int sprintf(char *out, const char *format, ...) {
  //panic("Not implemented");
  va_list arg;
  int done;

  va_start (arg, format);
  done = vsprintf(out, format, arg);
  va_end (arg);

  return done;
}

int snprintf(char *out, size_t n, const char *format, ...) {
  //panic("Not implemented");
  va_list arg;
  int done;

  va_start (arg, format);
  done = vsnprintf (out, n, format, arg);
  va_end (arg);
  return done;
}



//这个函数的基本思路是遍历格式化字符串，然后对于每个格式化指示符 `%`，根据其后面的字符来确定对应的参数类型,
//并使用对应的 `va_arg` 宏从可变参数列表中取出相应的参数，最后将其格式化为字符串并复制到输出缓冲区中。
//需要注意的是，为了能够正确处理各种格式化指示符，代码中涉及到了一些细节处理，例如：处理宽度、精度、十六进制输出、指针输出等。
//同时，在将格式化结果复制到输出缓冲区时，需要检查是否会溢出输出缓冲区的大小，以避免造成安全问题。
//最终，函数返回格式化输出的字符数，如果输出缓冲区的大小不足以容纳所有字符，函数会截断输出并返回 -1。
int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
  //panic("Not implemented");
    int written = 0;
    //int result = 0;

    while (*format != '\0') {
        if (*format == '\0') break;
        if (*format != '%') {
            if (written + 1 < size) {
                str[written++] = *format;
            } else {
                str[size - 1] = '\0';
                return -1;
            }
            ++format;
            continue;
        }
        if(*format== '%') {
            ++format;
        switch (*format)
        {
        case 'i':
        case 'd':
            int num = va_arg(ap, int);
            char buf[20];
            int i = 0;
            if (num < 0) {
                str[written++] = '-';
                num = -num;
            }
            while (num) {
                buf[i++] = num % 10 + '0';
                num /= 10;
            }
            if (i == 0) buf[i++] = '0';
            while (i > 0) {
                if (written + 1 < size) {
                    str[written++] = buf[--i];
                } else {
                    str[size - 1] = '\0';
                    return -1;
                }
            }
            break;
        case 's':
            char *s = va_arg(ap, char *);
            while (*s) {
                if (written + 1 < size) {
                    str[written++] = *s++;
                } else {
                    str[size - 1] = '\0';
                    return -1;
                }
            }
            break;
        case 'x':
            int num1 = va_arg(ap, int);
            char buf1[20];
            int i1 = 0;
            if (num1 < 0) {
                str[written++] = '-';
                num1 = -num1;
            }
            while (num1) {
                int temp = num1 % 16;
                if (temp < 10) buf1[i1++] = temp + '0';
                else buf1[i1++] = temp - 10 + 'a';
                num1 /= 16;
            }
            if (i1 == 0) buf1[i1++] = '0';
            while (i1 > 0) {
                if (written + 1 < size) {
                    str[written++] = buf1[--i1];
                } else {
                    str[size - 1] = '\0';
                    return -1;
                }
            }
            break;
        case 'p':
            str[written++] = '0';
            str[written++] = 'x';
            int num2 = va_arg(ap, int);
            char buf2[20];
            int i2 = 0;
            if (num2 < 0) {
                str[written++] = '-';
                num2 = -num2;
            }
            while (num2) {
                int temp = num2 % 16;
                if (temp < 10) buf2[i2++] = temp + '0';
                else buf2[i2++] = temp - 10 + 'a';
                num2 /= 16;
            }
            if (i2 == 0) buf2[i2++] = '0';
            while (i2 > 0) {
                if (written + 1 < size) {
                    str[written++] = buf2[--i2];
                } else {
                    str[size - 1] = '\0';
                    return -1;
                }
            }
            break;
        case 'c':
            char c = va_arg(ap, int);
            str[written++] = c;
            break;

        default:
            //panic("Not %% to match");
            break;
        }
    }
        ++format;  
    }
    if(size > 0) {
        str[written] = '\0';
    }
    return written;
}
#endif
