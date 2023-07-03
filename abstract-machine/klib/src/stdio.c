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
    // 将有符号十进制整数转换为字符数组
    // 返回字符个数
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

int uintcountHexDigits(unsigned int num) {
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
    // 将无符号十进制整数转换为字符数组
    // 返回字符个数
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

int inthexToCharArray(char* out, int num) {
    // 将有符号十六进制整数转换为字符数组
    // 返回字符个数

    int count = 0;  // 字符个数

    if (num == 0) {
        *out++ = '0';
        count++;
    } else {
        char buffer[20];  // 保存转换后的字符
        int idx = 0;      // 缓冲区索引

        int isNegative = 0;  // 是否为负数的标志
        if (num < 0) {
            isNegative = 1;
            num = -num;
        }

        while (num > 0) {
            int digit = num % 16;
            buffer[idx++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
            num /= 16;
        }

        if (isNegative) {
            buffer[idx++] = '-';  // 添加负号
        }

        while (idx > 0) {
            *out++ = buffer[--idx];
            count++;
        }
    }

    return count;  // 返回转换后的字符个数
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
    // 格式化输出字符串
    // 返回输出字符的总个数

    va_list ap;
    va_start(ap, fmt);

    int num = 0;  // 输出字符的个数

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;  // 跳过 '%'
            switch (*fmt) {
                case 'c':
                    // 打印字符
                    putchar(va_arg(ap, int));
                    num++;
                    break;
                case 'd':
                    // 打印有符号十进制整数
                    num += printDecimal(va_arg(ap, int));
                    break;
                case 'u':
                    // 打印无符号十进制整数
                    num += printUnsignedDecimal(va_arg(ap, unsigned int));
                    break;
                case 'x':
                case 'p':
                    // 打印有符号十六进制整数
                    num += printHexadecimal(va_arg(ap, int));
                    break;
                case 's':
                    // 打印字符串
                    num += printString(va_arg(ap, const char*));
                    break;
                default:
                    // 处理未知格式，直接打印 '%'
                    putchar('%');
                    num++;
                    break;
            }
        } else {
            // 打印普通字符
            putchar(*fmt);
            num++;
        }

        fmt++;
    }

    va_end(ap);
    return num;  // 返回输出字符的总个数
}


/**
 * 将格式化的字符串输出到字符数组中
 * out 输出的字符数组，用于保存格式化后的字符串
 * fmt 格式化字符串，包含要输出的文本以及格式化标识符
 * ap va_list对象，包含可变参数列表
 * 返回输出字符的总个数
 */
int vsprintf(char *out, const char *fmt, va_list ap) {
    int outi = 0;  // 输出字符数组的索引
    int num = 0;   // 输出字符的总个数

    // 遍历格式化字符串
    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;  // 跳过 '%'

            // 处理格式化标识符
            switch (*fmt) {
                case 'c':
                    // 打印字符
                    out[outi++] = va_arg(ap, int);
                    num++;
                    break;
                case 'd':
                    // 打印有符号十进制整数
                    {
                        int integer = va_arg(ap, int);
                        if (integer < 0) {
                            out[outi++] = '-';
                            num++;
                            integer = -integer;
                        }
                        outi += intToCharArray(out + outi, integer);  // 将整数转换为字符数组并保存到输出数组中
                        num += countDigits(integer) + 1;  // 统计输出的字符个数（整数位数+符号位）
                    }
                    break;
                case 'u':
                    // 打印无符号十进制整数
                    {
                        unsigned int integer = va_arg(ap, unsigned int);
                        outi += uintToCharArray(out + outi, integer);  // 将无符号整数转换为字符数组并保存到输出数组中
                        num += countDigits(integer);  // 统计输出的字符个数（整数位数）
                    }
                    break;
                case 'x':
                case 'p':
                    // 打印有符号十六进制整数
                    {
                        int integer = va_arg(ap, int);
                        outi += inthexToCharArray(out + outi, integer);  // 将有符号十六进制整数转换为字符数组并保存到输出数组中
                        num += uintcountHexDigits(integer);  // 统计输出的字符个数（十六进制位数）
                    }
                    break;
                case 's':
                    // 打印字符串
                    {
                        const char* str = va_arg(ap, const char*);
                        while (*str != '\0') {
                            out[outi++] = *str++;
                            num++;
                        }
                    }
                    break;
                default:
                    // 处理未知格式，直接打印 '%'
                    out[outi++] = '%';
                    num++;
                    break;
            }
        } else {
            // 打印普通字符
            out[outi++] = *fmt;
            num++;
        }

        fmt++;
    }

    out[outi] = '\0';  // 添加字符串结束符
    return num;  // 返回输出字符的总个数
}



/**
 * 将格式化的字符串输出到字符数组中
 *
 * out 输出的字符数组，用于保存格式化后的字符串
 * fmt 格式化字符串，包含要输出的文本以及格式化标识符
 * ... 可变参数列表
 *  返回输出字符的总个数
 */
int sprintf(char* out, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    // 调用vsprintf函数将格式化的字符串输出到字符数组中
    int result = vsprintf(out, fmt, ap);

    va_end(ap);
    return result;  // 返回输出字符的总个数
}


/**
 * 格式化输出到字符数组，限制输出字符的个数
 *
 * out 输出字符数组的指针
 * n 输出字符数组的最大长度（包括字符串结束符）
 * fmt 格式化字符串
 * ap 可变参数列表
 * 实际输出的字符个数（不包括字符串结束符）
 */
int vsnprintf(char* out, size_t n, const char* fmt, va_list ap) {
    int outi = 0;                         // 输出字符数组的索引
    int num = 0;                          // 输出字符的个数
    size_t remaining = n > 0 ? n - 1 : 0;  // 剩余可写入的字符数，预留一个字符位置用于添加字符串结束符

    while (*fmt != '\0' && remaining > 0) {
        if (*fmt == '%') {
            fmt++;  // 跳过 '%'
            switch (*fmt) {
                case 'c':
                    out[outi++] = va_arg(ap, int);  // 从可变参数列表中获取一个整数参数，存入字符数组
                    num++;
                    remaining--;
                    break;
                case 'd':
                    {
                        int integer = va_arg(ap, int);  // 从可变参数列表中获取一个整数参数，存入整型变量
                        if (integer < 0) {
                            out[outi++] = '-';  // 如果整数为负数，将负号存入字符数组
                            num++;
                            remaining--;
                            integer = -integer;  // 取整数的绝对值
                        }
                        int digits = countDigits(integer);  // 计算整数的位数
                        if (digits <= remaining) {
                            outi += intToCharArray(out + outi, integer);  // 将整数转换为字符数组，并存入字符数组
                            num += digits + 1;  // 更新字符个数（包括负号和数字位数）
                            remaining -= digits;  // 更新剩余可写入的字符数
                        } else {
                            break;  // 超过剩余可写入的字符数，跳出循环
                        }
                    }
                    break;
                case 'u':
                    {
                        unsigned int integer = va_arg(ap, unsigned int);  // 从可变参数列表中获取一个无符号整数参数，存入无符号整型变量
                        int digits = countDigits(integer);  // 计算无符号整数的位数
                        if (digits <= remaining) {
                            outi += uintToCharArray(out + outi, integer);  // 将无符号整数转换为字符数组，并存入字符数组
                            num += digits;  // 更新字符个数
                            remaining -= digits;  // 更新剩余可写入的字符数
                        } else {
                            break;  // 超过剩余可写入的字符数，跳出循环
                        }
                    }
                    break;
                case 'x':
                case 'p':
                    {
                        int integer = va_arg(ap, int);  // 从可变参数列表中获取一个整数参数，存入整型变量
                        int digits = uintcountHexDigits(integer);  // 计算整数的十六进制位数
                        if (digits <= remaining) {
                            outi += inthexToCharArray(out + outi, integer);  // 将整数转换为十六进制字符数组，并存入字符数组
                            num += digits;  // 更新字符个数
                            remaining -= digits;  // 更新剩余可写入的字符数
                        } else {
                            break;  // 超过剩余可写入的字符数，跳出循环
                        }
                    }
                    break;
                case 's':
                    {
                        const char* str = va_arg(ap, const char*);  // 从可变参数列表中获取一个字符串参数，存入字符指针
                        while (*str != '\0' && remaining > 0) {
                            out[outi++] = *str++;  // 将字符串的每个字符存入字符数组
                            num++;
                            remaining--;
                        }
                    }
                    break;
                default:
                    out[outi++] = '%';  // 处理无效格式
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


/**
 * 格式化输出到字符数组，限制输出字符的个数
 * 
 * str 输出字符数组的指针
 * size 输出字符数组的最大长度（包括字符串结束符）
 * format 格式化字符串
 * ... 可变参数列表
 * 实际输出的字符个数（不包括字符串结束符）
*/
int snprintf(char* str, size_t size, const char* format, ...) {
    va_list ap;
    va_start(ap, format);
    int ret = vsnprintf(str, size, format, ap);
    va_end(ap);
    return ret;
}

#endif