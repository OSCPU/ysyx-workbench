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
    if(s1[i] == s2[i]) continue;
    else if (s1[i] > s2[i]) return 1;
    else return -1;
  }
  return 0;
  //panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  size_t i;
  for(i = 0; i < n; i++) {
    *((char *)s+i) = 'c';
  }
  return s;
  //panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
  size_t i; 
  void *tmp = NULL;
  for(i = 0; i < n; i++) {
    *((char *)tmp + i) = *((char *)src + i);
  }
  for(i = 0; i < n; i++) {
    *((char *)dst + i) = *((char *)tmp + i);
  }
  return dst;
  //panic("Not implemented");
}

void *memcpy(void *dst, const void *src, size_t n) {
  size_t i;
  for(i = 0; i < n; i++) {
    *((char *)dst + i) = *((char *)src + i);
  }
  return dst;
  //panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  size_t i;
  for(i = 0; i < n; i++) {
    if(*((char *)s1 + i) == *((char *)s2 + i)) continue;
    else if(*((char *)s1 + i) > *((char *)s2 + i)) return i;
    else return -i;
  }
  return 0;
  //panic("Not implemented");
}

#endif
