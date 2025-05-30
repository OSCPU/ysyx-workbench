#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t len;
	len = 0;
  while(s[len] != '\0'){
    len ++;
  }
	return len;
}

char *strcpy(char *dst, const char *src) {
  size_t i;
	for (i = 0; src[i] != '\0'; i++)
    dst[i] = src[i];
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
  	dst[i] = src[i];
  for ( ; i < n; i++)
    dst[i] = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  size_t dst_len = strlen(dst);
  size_t i;
  for (i = 0 ; src[i] != '\0' ; i++)
  	dst[dst_len + i] = src[i];
  dst[dst_len + i] = '\0';
	return dst;
}

int strcmp(const char *s1, const char *s2) {
  for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
		if (s1[i] != s2[i]) {
  			return (s1[i] < s2[i]) ? -1 : 1;
  	}
	}
  return 0;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  for (size_t i = 0; i < n; i++) {
    if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i]) {
      if (s1[i] == s2[i]) {
        return 0;
      }
      return (s1[i] < s2[i]) ? -1 : 1;
    }
}
return 0;
}

void *memset(void *s, int c, size_t n) {
	unsigned char *p = (unsigned char *)s;
  for (size_t i = 0; i < n; i++) {
  	p[i] = (unsigned char)c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
	int i;
	char *dest = (char *)dst;
	char *source = (char *)src;
	if(dst <= src){
		for(i = 0;i < n;i++){
			*dest++ = *source++;
		}
	}
	else{
		dest += n-1;
		source += n-1;
		for(i = 0;i < n;i++){
			*dest-- = *source--;
		}
	}
	return (void *)dst;
}

void *memcpy(void *out, const void *in, size_t n) {
	int i;
	char *dest = (char *)out;
	char *source = (char *)in;
	for(i = 0;i < n;i++){
		*dest++ = *source++;
	}
	return (void *)out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
	unsigned char *p1 = (unsigned char *)s1;
	unsigned char *p2 = (unsigned char *)s2;
	int i;
	for(i = 0; i < n ; i++)
		if(p1[i] != p2[i])
			return (p1[i] < p2[i]) ? -1 : 1;
	return 0;
}

#endif
