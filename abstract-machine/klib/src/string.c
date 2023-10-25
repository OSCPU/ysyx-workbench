#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len = 0;
  size_t i;
  for(i = 0; s[i] != '\0'; i++) {
    len++;
  }
  return len;
  //panic("Not implemented");
}

char *strcpy(char *dst, const char *src) {
  size_t i;
  for (i = 0; src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  dst[i] = '\0';
  return dst;
  //panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
  for(i = 0; i < n && src[i] != '\0'; i++) {
    dst[i] = src[i];
  }
  for(; i < n; i++) {
    dst[i] = '\0';
  }
  return dst;
  //panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  size_t i;
  size_t dst_len = strlen(dst);
  for(i = 0; src[i] != '\0'; i++)  {
    dst[dst_len + i] = src[i];
  }
  dst[dst_len + i] = '\0';
  return dst;
  //panic("Not implemented");
}

int strcmp(const char *s1, const char *s2) {
  size_t i;
  for(i = 0; ; i++) {
    if(s1[i] == s2[i] && !s1[i]) return 0;
    if(s1[i] == s2[i]) continue;
    else if(s1[i] > s2[i]) return 1;
    else return -1;
  }
  //panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;
  for(i = 0; i < n; i++ ) {
    if(s1[i] == s2[i] && !s1[i]) return 0;
    if(s1[i] == s2[i]) continue;
    else if (s1[i] > s2[i]) return 1;
    else return -1;
  }
  return 0;
  //panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  assert(s != NULL);
  assert(n >= 0);

  size_t i;
  for(i = 0; i < n; i++) {
    *((unsigned char *)s + i) = (unsigned char)c;
  }
  return s;
  //panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  assert(dst != NULL);
  assert(src != NULL);
  assert(n >= 0);

  void* ret = dst;
  if (dst < src) {
    while (n--) {
      *(unsigned char*)dst = *(unsigned char*)src;
      (unsigned char*)dst++;
      (unsigned char*)src++;
    }
  } else {
    while (n--) {
      *((unsigned char*)dst + n) = *((unsigned char*)src + n);
    }
  }
  return ret;
  //panic("Not implemented");
}

void *memcpy(void *dst, const void *src, size_t n) {
  assert(dst != NULL);
  assert(n >=0);

  size_t i;
  for(i = 0; i < n; i++) {
    *((unsigned char *)dst + i) = *((const unsigned char *)src + i);
  }
  return dst;
  //panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  size_t i;
  if(n == 0) return 0;
  for(i = 0; i < n; i++) {
    if(*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i)) continue;
    else if(*((unsigned char *)s1 + i) > *((unsigned char *)s2 + i)) return 1;
    else return -1;
  }
  return 0;
  //panic("Not implemented");
}

#endif
