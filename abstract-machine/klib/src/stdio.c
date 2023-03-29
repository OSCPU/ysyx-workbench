#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *format, ...) {
  panic("Not implemented");
  // va_list arg;
  // int done;

  // va_start (arg, format);
  // done = vfprintf(stdout, format, arg);
  // va_end (arg);

  // return done;
}
int vsprintf(char *out, const char *fmt, va_list ap) {
  //panic("Not implemented");
  return vsnprintf(out, SIZE_MAX, fmt, ap);
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
    int result = 0;

    while (*format != '\0') {
        if (*format != '%') {
            if (written + 1 < size) {
                str[written] = *format;
                ++written;
            } else {
                str[size - 1] = '\0';
                return -1;
            }
            ++format;
            continue;
        }

        ++format;

        if (*format == '\0') {
            break;
        }

        if (*format == '%') {
            if (written + 1 < size) {
                str[written] = '%';
                ++written;
            } else {
                str[size - 1] = '\0';
                return -1;
            }
            ++format;
            continue;
        }

        int width = 0;
        while (*format >= '0' && *format <= '9') {
            width = 10 * width + (*format - '0');
            ++format;
        }

        int precision = -1;
        if (*format == '.') {
            ++format;
            precision = 0;
            while (*format >= '0' && *format <= '9') {
                precision = 10 * precision + (*format - '0');
                ++format;
            }
        }

        if (*format == '\0') {
            break;
        }

        char type = *format;
        ++format;

        if (type == 'd' || type == 'i') {
            int value = va_arg(ap, int);
            char buffer[32];
            int len = sprintf(buffer, "%d", value);
            result += len;
            if (written + len < size) {
                int pad = width - len;
                while (pad-- > 0) {
                    if (written + 1 < size) {
                        str[written] = ' ';
                        ++written;
                    } else {
                        str[size - 1] = '\0';
                        return -1;
                    }
                }
                memcpy(str + written, buffer, len);
                written += len;
            } else {
                str[size - 1] = '\0';
                return -1;
            }
        } else if (type == 's') {
            const char *value = va_arg(ap, const char *);
            int len = strlen(value);
            result += len;
            if (written + len < size) {
                int pad = width - len;
                while (pad-- > 0) {
                    if (written + 1 < size) {
                        str[written] = ' ';
                        ++written;
                    } else {
                        str[size - 1] = '\0';
                        return -1;
                    }
                }
                memcpy(str + written, value, len);
                written += len;
            } else {
                str[size - 1] = '\0';
                return -1;
            }
        } else if (type == 'c') {
            char value = (char)va_arg(ap, int);
            if (written + 1 < size) {
                str[written] = value;
                ++written;
            } else {
                str[size - 1] = '\0';
                return -1;
            }
            ++result;
    } else if (type == 'x' || type == 'X') {
        unsigned int value = va_arg(ap, unsigned int);
        char buffer[32];
        int len = sprintf(buffer, type == 'x' ? "%x" : "%X", value);
        result += len;
        if (written + len < size) {
            int pad = width - len;
            while (pad-- > 0) {
                if (written + 1 < size) {
                    str[written] = ' ';
                    ++written;
                } else {
                    str[size - 1] = '\0';
                    return -1;
                }
            }
            memcpy(str + written, buffer, len);
            written += len;
        } else {
            str[size - 1] = '\0';
            return -1;
        }
    } else if (type == 'p') {
        void *value = va_arg(ap, void *);
        char buffer[32];
        int len = sprintf(buffer, "%p", value);
        result += len;
        if (written + len < size) {
            int pad = width - len;
            while (pad-- > 0) {
                if (written + 1 < size) {
                    str[written] = ' ';
                    ++written;
                } else {
                    str[size - 1] = '\0';
                    return -1;
                }
            }
            memcpy(str + written, buffer, len);
            written += len;
        } else {
            str[size - 1] = '\0';
            return -1;
        }
    } else {
      // Unknown format specifier
        if (written + 1 < size) {
            str[written] = '%';
            ++written;
            str[written] = type;
            ++written;
        } else {
            str[size - 1] = '\0';
            return -1;
        }
    }
  }
    if (written < size) {
      str[written] = '\0';
    }   else {
      str[size - 1] = '\0';
      return -1;
    }
    return result;
}
#endif
