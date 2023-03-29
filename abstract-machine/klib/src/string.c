#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  //panic("Not implemented");
  size_t i=0;
  while(s[0]!='\0'){i++;}
  return i;
  //return LENGTH(s)
}

char *strcpy(char *dst, const char *src) {
  //panic("Not implemented");
  int i=0;
  while(src[i]!='\0'){
    dst[i]=src[i];
    i++;
  }
  dst[i]='\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  //panic("Not implemented");
  int i=0;
  for(;src[i]!='\0'&&i<n;i++){
    dst[i]=src[i];
  }
  dst[i]='\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  //panic("Not implemented");
  int i=0;
  while(dst[i]!='\0'){i++;}
  int j=0;
  while(src[j]!='\0'){
    dst[i++]=src[j++];
  }
  dst[i]='\0';
  return dst;
}

int strcmp(const char *s1, const char *s2) {
  //panic("Not implemented");
  int i=0;
  while(s1[i]!='\0'&&s2[i]!='\0'){
    if(s1[i]!=s2[i]){return s1[i]-s2[i];}
    i++;
  }
  if(s1[i]=='\0'&&s2[i]=='\0'){return 0;}
  else if(s1[i]=='\0'){return -1;}
  else{return 1;}
}

int strncmp(const char *s1, const char *s2, size_t n) {
  //panic("Not implemented");
  int i=0;
  while(i<n){
    if(s1[i]!=s2[i]){return s1[i]-s2[i];}
    i++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  //panic("Not implemented");
  int i=0;
  while(i<n){
    ((char*)s)[i]=c;
    i++;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  //panic("Not implemented");
  int i=0;
  while(i<n){
    ((char*)dst)[i]=((char*)src)[i];
    i++;
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  //panic("Not implemented");
  int i=0;
  while(i<n){
    ((char*)out)[i]=((char*)in)[i];
    i++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  //panic("Not implemented");
  int i=0;
  while(i<n){
    if(((char*)s1)[i]!=((char*)s2)[i]){return ((char*)s1)[i]-((char*)s2)[i];}
    i++;
  }
  return 0;
}

#endif
