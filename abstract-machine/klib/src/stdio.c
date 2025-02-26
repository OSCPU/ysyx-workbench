#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stddef.h>
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
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
