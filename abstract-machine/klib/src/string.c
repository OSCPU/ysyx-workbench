#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
 // panic("Not implemented");
  size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char *strcpy(char *dst, const char *src) {
  //panic("Not implemented");
	char *ret = dst;
    while ((*dst++ = *src++) != '\0')
        ;
    return ret;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("cnmmstrncpyNot implemented");
}

char *strcat(char *dst, const char *src) {
  //panic("Not implemented");
	char *ret = dst;
    while (*dst) {  // Move to the end of dest
        dst++;
    }
    while ((*dst++ = *src++) != '\0')  // Append src to dest
        ;
    return ret;
}

int strcmp(const char *s1, const char *s2) {
//  panic("Not implemented");
	while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
	return (unsigned char)(*s1) - (unsigned char)(*s2);
  //  return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("cnmNot implemented");
}

void *memset(void *s, int c, size_t n) {
   unsigned char *ptr = s;
    while (n--) {
        *ptr++ = (unsigned char)c;
    }
    return s;
}

void *memmove(void *dst, const void *src, size_t n) {
unsigned char *d = (unsigned char *)dst;
  const unsigned char *s = (const unsigned char *)src;

  if (d == s || n == 0) return dst; // 如果源和目标相同，或者 n == 0，则直接返回

  if (d < s || d >= s + n) {
    // 无重叠，可以像 `memcpy()` 一样从头到尾复制
    while (n--) {
      *d++ = *s++;
    }
  } else {
    // 有重叠，必须从后往前复制
    d += n;
    s += n;
    while (n--) {
      *(--d) = *(--s);
    }
  }
  
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *d = out;
    const unsigned char *s = in;
    while (n--) {
        *d++ = *s++;
    }
    return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *ptr1 = s1;
    const unsigned char *ptr2 = s2;

    while (n--) {
        if (*ptr1 != *ptr2) {
            return (int)(*ptr1 - *ptr2);  // 返回第一个不相等字节的差值
        }
        ptr1++;
        ptr2++;
    }
    return 0;  // 如果前 n 个字节都相等，返回 0
}

#endif
