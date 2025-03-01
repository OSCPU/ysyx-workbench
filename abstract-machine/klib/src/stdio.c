#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stddef.h>
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
// 辅助函数：整数转换为字符串
static void itoa(int num, char *str) {
  char buf[16];
  int i = 0, j = 0;
  bool is_negative = false;
  
  if (num < 0) {
    is_negative = true;
    num = -num;
  }
  
  do {
    buf[i++] = (num % 10) + '0';
    num /= 10;
  } while (num > 0);
  
  if (is_negative) {
    buf[i++] = '-';
  }
  
  while (i > 0) {
    str[j++] = buf[--i];
  }
  str[j] = '\0';
}

int printf(const char *fmt, ...) {
//  panic("Not implemented");
  char buf[1024];  // 临时缓冲区
  va_list args;
  va_start(args, fmt);
  int len = vsprintf(buf, fmt, args);
  va_end(args);

  for (int i = 0; i < len; i++) {
    putch(buf[i]); // 逐个输出
  }
  return len;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
//  panic("Not implemented");
  char *s;
  char num_buf[16];
  int d;
  char *p = out;
  
  while (*fmt) {
    if (*fmt == '%') {
      fmt++;
      switch (*fmt) {
        case 's': // 处理字符串
          s = va_arg(ap, char *);
          while (*s) {
            *p++ = *s++;
          }
          break;
        case 'd': // 处理整数
          d = va_arg(ap, int);
          itoa(d, num_buf);
          s = num_buf;
          while (*s) {
            *p++ = *s++;
          }
          break;
        default:
          *p++ = '%';
          *p++ = *fmt;
      }
    } else {
      *p++ = *fmt;
    }
    fmt++;
  }
  *p = '\0'; // 确保字符串以 `\0` 结尾
  return p - out; // 返回写入的字符数
}

int sprintf(char *out, const char *fmt, ...) {
      va_list args;
    const char *ptr;
    char *str_ptr = out;
    int num;

    // 初始化可变参数列表
    va_start(args, fmt);

    // 遍历格式字符串
    for (ptr = fmt; *ptr != '\0'; ptr++) {
        if (*ptr == '%' && (*(ptr + 1) == 's' || *(ptr + 1) == 'd')) {
            // 处理 %s (字符串)
            if (*(ptr + 1) == 's') {
                char *str_arg = va_arg(args, char*);
                while (*str_arg != '\0') {
                    *str_ptr++ = *str_arg++;
                }
            }
            // 处理 %d (整数)
            else if (*(ptr + 1) == 'd') {
                num = va_arg(args, int);
                if (num < 0) {
                    *str_ptr++ = '-';
                    num = -num;
                }
                // 将整数转换为字符串
                int n = num, len = 0;
                while (n > 0) {
                    len++;
                    n /= 10;
                }
                if (num == 0) {
                    *str_ptr++ = '0';
                } else {
                    char temp[len];
                    int i = 0;
                    while (num > 0) {
                        temp[i++] = (num % 10) + '0';
                        num /= 10;
                    }
                    // 反转数字并拷贝到结果字符串
                    for (int j = i - 1; j >= 0; j--) {
                        *str_ptr++ = temp[j];
                    }
                }
            }
            ptr++;  // 跳过格式说明符
        } else {
            // 普通字符，直接复制
            *str_ptr++ = *ptr;
        }
    }

    // 结束可变参数列表
    va_end(args);

    // 以 '\0' 结束字符串
    *str_ptr = '\0';

    return str_ptr - out;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
