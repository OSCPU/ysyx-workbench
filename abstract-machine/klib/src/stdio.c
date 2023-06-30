#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int putchar(int c) {
    putch(c);
    return 1;
}

int countDigits(int num) {
    // 计算有符号整数的位数
    int count = 0;
    if (num == 0) {
        return 1;
    } else if (num < 0) {
        count++; // 负号占一位
        num = -num;
    }
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

int intToCharArray(char* out, int num) {
    int count = 0;  // 字符个数

    if (num < 0) {
        *out++ = '-';
        num = -num;
        count++;
    }

    if (num == 0) {
        *out++ = '0';
        count++;
    } else {
        char buffer[20];  // 保存转换后的字符
        int idx = 0;      // 缓冲区索引

        while (num > 0) {
            buffer[idx++] = num % 10 + '0';
            num /= 10;
        }

        while (idx > 0) {
            *out++ = buffer[--idx];
            count++;
        }
    }

    return count;
}

int countHexDigits(unsigned int num) {
    // 计算无符号十六进制整数的位数
    int count = 0;
    if (num == 0) {
        return 1;
    }
    while (num > 0) {
        count++;
        num /= 16;
    }
    return count;
}

int uintToCharArray(char* arr, unsigned int num) {
    int count = 0;  // 字符个数

    if (num == 0) {
        arr[0] = '0';
        arr[1] = '\0';
        count = 1;
    } else {
        int index = 0;
        while (num > 0) {
            arr[index] = '0' + num % 10;
            index++;
            num /= 10;
        }
        arr[index] = '\0';
        count = index;
    }

    return count;
}


int hexToCharArray(char* out, int num) {
    int count = 0;  // 字符个数

    if (num == 0) {
        *out++ = '0';
        count++;
    } else {
        char buffer[20];  // 保存转换后的字符
        int idx = 0;      // 缓冲区索引

        while (num > 0) {
            int digit = num % 16;
            buffer[idx++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
            num /= 16;
        }

        while (idx > 0) {
            *out++ = buffer[--idx];
            count++;
        }
    }

    return count;
}

int printString(const char* str) {
    // 打印字符串
    // 返回打印的字符个数
    int count = 0;
    while (*str != '\0') {
        putch(*str++);
        count++;
    }
    return count;
}

int printDecimal(int num) {
    // 打印有符号十进制整数
    // 返回打印的字符个数
    if (num == 0) {
        putch('0');
        return 1;
    }

    int count = 0;
    if (num < 0) {
        putch('-');
        count++;
        num = -num;
    }

    int digits[10];
    int index = 0;

    while (num > 0) {
        digits[index] = num % 10;
        num /= 10;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        putch('0' + digits[i]);
        count++;
    }

    return count;
}

int printUnsignedDecimal(unsigned int num) {
    // 打印无符号十进制整数
    // 返回打印的字符个数
    if (num == 0) {
        putch('0');
        return 1;
    }

    int count = 0;
    unsigned int digits[10];
    int index = 0;

    while (num > 0) {
        digits[index] = num % 10;
        num /= 10;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        putch('0' + digits[i]);
        count++;
    }

    return count;
}

int printHexadecimal(unsigned int num) {
    // 打印有符号十六进制整数
    // 返回打印的字符个数
    if (num == 0) {
        putch('0');
        return 1;
    }

    int count = 0;
    char digits[8];
    int index = 0;

    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            digits[index] = '0' + remainder;
        } else {
            digits[index] = 'a' + remainder - 10;
        }
        num /= 16;
        index++;
    }

    for (int i = index - 1; i >= 0; i--) {
        putch(digits[i]);
        count++;
    }

    return count;
}

int printf(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    int num = 0;  // 输出字符的个数

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;  // 跳过 '%'
            switch (*fmt) {
                case 'c':
                    putchar(va_arg(ap, int));
                    num++;
                    break;
                case 'd':
                    num += printDecimal(va_arg(ap, int));
                    break;
                case 'u':
                    num += printUnsignedDecimal(va_arg(ap, unsigned int));
                    break;
                case 'x':
                case 'p':
                    num += printHexadecimal(va_arg(ap, int));
                    break;
                case 's':
                    num += printString(va_arg(ap, const char*));
                    break;
                default:
                    putchar('%');
                    num++;
                    break;
            }
        } else {
            putchar(*fmt);
            num++;
        }

        fmt++;
    }

    va_end(ap);
    return num;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
    int outi = 0;
    int num = 0;  // 输出字符的个数

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;  // 跳过 '%'
            switch (*fmt) {
                case 'c':
                    out[outi++] = va_arg(ap, int);
                    num++;
                    break;
                case 'd':
                    {
                        int integer = va_arg(ap, int);
                        if (integer < 0) {
                            out[outi++] = '-';
                            num++;
                            integer = -integer;
                        }
                        outi += intToCharArray(out + outi, integer);
                        num += countDigits(integer) + 1;
                    }
                    break;
                case 'u':
                    {
                        unsigned int integer = va_arg(ap, unsigned int);
                        outi += uintToCharArray(out + outi, integer);
                        num += countDigits(integer);
                    }
                    break;
                case 'x':
                case 'p':
                    {
                        int integer = va_arg(ap, int);
                        outi += hexToCharArray(out + outi, integer);
                        num += countHexDigits(integer);
                    }
                    break;
                case 's':
                    {
                        const char* str = va_arg(ap, const char*);
                        while (*str != '\0') {
                            out[outi++] = *str++;
                            num++;
                        }
                    }
                    break;
                default:
                    out[outi++] = '%';
                    num++;
                    break;
            }
        } else {
            out[outi++] = *fmt;
            num++;
        }

        fmt++;
    }

    out[outi] = '\0';  // 添加字符串结束符
    return num;
}


int sprintf(char* out, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int result = vsprintf(out, fmt, ap);
    va_end(ap);
    return result;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
    int outi = 0;
    int num = 0; 
    size_t remaining = n > 0 ? n - 1 : 0;  // 剩余可写入的字符数，预留一个字符位置用于添加字符串结束符

    while (*fmt != '\0' && remaining > 0) {
        if (*fmt == '%') {
            fmt++;  // 跳过 '%'
            switch (*fmt) {
                case 'c':
                    out[outi++] = va_arg(ap, int);
                    num++;
                    remaining--;
                    break;
                case 'd':
                    {
                        int integer = va_arg(ap, int);
                        if (integer < 0) {
                            out[outi++] = '-';
                            num++;
                            remaining--;
                            integer = -integer;
                        }
                        int digits = countDigits(integer);
                        if (digits <= remaining) {
                            outi += intToCharArray(out + outi, integer);
                            num += digits + 1;
                            remaining -= digits;
                        } else {
                            break;
                        }
                    }
                    break;
                case 'u':
                    {
                        unsigned int integer = va_arg(ap, unsigned int);
                        int digits = countDigits(integer);
                        if (digits <= remaining) {
                            outi += uintToCharArray(out + outi, integer);
                            num += digits;
                            remaining -= digits;
                        } else {
                            break;
                        }
                    }
                    break;
                case 'x':
                case 'p':
                    {
                        int integer = va_arg(ap, int);
                        int digits = countHexDigits(integer);
                        if (digits <= remaining) {
                            outi += hexToCharArray(out + outi, integer);
                            num += digits;
                            remaining -= digits;
                        } else {
                            break;
                        }
                    }
                    break;
                case 's':
                    {
                        const char* str = va_arg(ap, const char*);
                        while (*str != '\0' && remaining > 0) {
                            out[outi++] = *str++;
                            num++;
                            remaining--;
                        }
                    }
                    break;
                default:
                    out[outi++] = '%';
                    num++;
                    remaining--;
                    break;
            }
        } else {
            out[outi++] = *fmt;
            num++;
            remaining--;
        }

        fmt++;
    }

    out[outi] = '\0';  // 添加字符串结束符
    return num;
}

int snprintf(char* str, size_t size, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vsnprintf(str, size, format, ap);
    va_end(ap);
    return ret;
}

#endif