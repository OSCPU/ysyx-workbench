#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stddef.h>
#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
// 辅助函数：整数转换为字符串
// 辅助函数：整数转换为字符串
static void itoa(int num, char *str, int base, int width, char pad) {
    static char digits[] = "0123456789abcdef";
    char buf[32];
    int i = 0, j = 0;
    bool is_negative = false;

    if (base == 10 && num < 0) { // 只对10进制数处理负号
        is_negative = true;
        num = -num;
    }

    do {
        buf[i++] = digits[num % base];
        num /= base;
    } while (num > 0);

    if (is_negative) {
        buf[i++] = '-';
    }

		while (i < width) {
        buf[i++] = pad;  // 补零或空格
    }

    // 逆序拷贝到str
    while (i > 0) {
        str[j++] = buf[--i];
    }
    str[j] = '\0';
}

int printf(const char *fmt, ...) {
//  panic("Not implemented");
  char buf[1000];  // 临时缓冲区
  va_list args;
  va_start(args, fmt);
  int len = vsprintf(buf, fmt, args);
  va_end(args);

  for (int i = 0; i < len; i++) {
    putch(buf[i]); // 逐个输出
  }
  return len;
}
// vsprintf 实现
int vsprintf(char *out, const char *fmt, va_list ap) {
    char *s;
    char num_buf[32]; // 用于存储转换后的数字
    int d;
    char *p = out;

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
						 // 解析格式化标志
            char pad = ' ';  // 默认补空格
            if (*fmt == '0') {
                pad = '0';  // 0前缀表示补零
                fmt++;
            }

            // 解析最小宽度
            int width = 0;
            while (*fmt >= '0' && *fmt <= '9') {
                width = width * 10 + (*fmt - '0');
                fmt++;
            }
						switch (*fmt) {
                case 's':  // 处理字符串
                    s = va_arg(ap, char *);
                    while (*s) {
                        *p++ = *s++;
                    }
                    break;
                case 'd':  // 处理整数
                    d = va_arg(ap, int);
                     itoa(d, num_buf, 10, width, pad);
										s = num_buf;
                    while (*s) {
                        *p++ = *s++;
                    }
                    break;
                case 'x':  // 处理十六进制
                    d = va_arg(ap, int);
                   // *p++ = '0';
                    //*p++ = 'x';
                     itoa(d, num_buf, 16, width, pad);
										s = num_buf;
                    while (*s) {
                        *p++ = *s++;
                    }
                    break;
								case 'c':  // 处理字符

                    d = va_arg(ap, int);  // 字符作为整数处理
                    *p++ = (char) d;
                    break;
                /*case 'f':  // 处理浮点数
                    {
                        float f = va_arg(ap, double);  // 浮点数作为双精度处理
                        ftoa(f, num_buf);
                        s = num_buf;
                        while (*s) {
                            *p++ = *s++;
                        }
										}*/
                default:  // 处理未知格式
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

int sprintf(char *out, const char *fmt, ...) 
	{
    va_list args;
    va_start(args, fmt);
    int len = vsprintf(out, fmt, args);
    va_end(args);
    return len;
}
/*{
    va_list args;
    const char *ptr;
    char *str_ptr = out;
    char buffer[32]; // 临时缓冲区用于存储转换后的字符串

    va_start(args, fmt);

    for (ptr = fmt; *ptr != '\0'; ptr++) {
        if (*ptr == '%' && (*(ptr + 1) == 's' || *(ptr + 1) == 'd' || *(ptr + 1) == 'x'|| *(ptr + 1) == 'c' || *(ptr + 1) == 'f')) {
            ptr++; // 跳过 '%'

            if (*ptr == 's') {  // 处理字符串
                char *str_arg = va_arg(args, char*);
                while (*str_arg) {
                    *str_ptr++ = *str_arg++;
                }
            } 
            else if (*ptr == 'd') {  // 处理整数
                int num = va_arg(args, int);
                itoa(num, buffer, 10);
                char *buf_ptr = buffer;
                while (*buf_ptr) {
                    *str_ptr++ = *buf_ptr++;
   itoa(d, num_buf, 16, width, pad);              }
            } 
            else if (*ptr == 'x') {  // 处理十六进制
                int num = va_arg(args, int);
          //      *str_ptr++ = '0';
            //    *str_ptr++ = 'x';
                itoa(num, buffer, 16);
                char *buf_ptr = buffer;
                while (*buf_ptr) {
                    *str_ptr++ = *buf_ptr++;
                }
            }
						else if (*ptr == 'c') {  // 处理字符
                int c = va_arg(args, int);
                *str_ptr++ = (char)c;
            }
            else if (*ptr == 'f') {  // 处理浮点数
                double f = va_arg(args, double);
                ftoa(f, buffer);
                char *buf_ptr = buffer;
                while (*buf_ptr) {
                    *str_ptr++ = *buf_ptr++;
                }
								}
        } else {  // 直接拷贝普通字符
            *str_ptr++ = *ptr;
        }
    }

    va_end(args);
    *str_ptr = '\0'; // 结束字符串
    return str_ptr - out;
}*/

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
