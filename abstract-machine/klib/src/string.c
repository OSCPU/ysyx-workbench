#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)
/*
函数功能：计算字符串的长度。
参数：指向以空字符结尾的字符串的指针 s。
返回值：字符串的长度。
*/
size_t strlen(const char *s) {
	assert(s != NULL);
	size_t len = 0;
	while (s[len] != '\0') {
		++len;
	}
  return len;
}

/*
函数功能：将源字符串复制到目标字符串。
参数：指向目标字符串的指针 dst 和指向源字符串的指针 src。
返回值：指向目标字符串的指针。
*/
char *strcpy(char *dst, const char *src) {
	assert(dst != NULL && src != NULL);
    size_t i;
	for (i = 0; src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	dst[i] = src[i];
	return dst;
}

/*
函数功能：将指定长度的源字符串复制到目标字符串。
参数：指向目标字符串的指针 dst，指向源字符串的指针 src，以及要复制的最大字符数 n。
返回值：指向目标字符串的指针。
*/
char *strncpy(char *dst, const char *src, size_t n) {
	assert(dst != NULL && src != NULL);
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dst[i] = src[i];
	}
	for (; i < n; ++i) {
		dst[i] = '\0';
	}
	return dst;
}

/*
函数功能：将源字符串追加到目标字符串的末尾。
参数：指向目标字符串的指针 dst 和指向源字符串的指针 src。
返回值：指向目标字符串的指针。
*/
char *strcat(char *dst, const char *src) {
	assert(dst != NULL && src != NULL);
	size_t dst_len = strlen(dst), i;
	for (i = 0; src[i] != '\0'; ++i) {
		dst[dst_len + i] = src[i];
	}
	dst[dst_len + i] = '\0';
	return dst;
}

/*
函数功能：比较两个字符串。
参数：指向要比较的字符串的指针 s1 和 s2。
返回值：如果字符串相等，返回 0；如果字符串不相等，返回第一个不匹配字符的差值
*/
int strcmp(const char *s1, const char *s2) {
	assert(s1 != NULL && s2 != NULL);
	size_t i = 0;
	for (; s1[i] != '\0' && s2[i] != '\0'; ++i) {
		if (s1[i] != s2[i]) return s1[i] - s2[i];
	}
	return s1[i] - s2[i];
}

/*
函数功能：比较两个字符串的前 n 个字符。
参数：指向要比较的字符串的指针 s1 和 s2，以及要比较的最大字符数 n。
返回值：如果字符串相等，返回 0；如果字符串不相等，返回第一个不匹配字符的差值。
*/
int strncmp(const char *s1, const char *s2, size_t n) {
	assert(s1 != NULL && s2 != NULL);
	size_t i = 0;
	for (; s1[i] != '\0' && s2[i] != '\0' && i < n; ++i) {
		if (s1[i] != s2[i]) return s1[i] - s2[i];
	}
	if (i == n) return 0;
	return s1[i] - s2[i];
}

/*
函数功能：将内存块的内容设置为指定的值。
参数：指向要设置值的内存块的指针 s，要设置的值 c，以及要设置的字节数 n。
返回值：指向内存块的指针。
*/
void *memset(void *s, int c, size_t n) {
	assert(s != NULL);
    char *ptr = s;
	while (n--) {
		*ptr++ = c;
	}
	return s;
}

/*
函数功能：将内存块从源位置复制到目标位置，处理内存重叠情况。
参数：指向目标位置的指针 dst，指向源位置的指针 src，以及要复制的字节数 n。
返回值：指向目标
*/
void *memmove(void *dst, const void *src, size_t n) {
	assert(dst != NULL && src != NULL);
    char *ptrd = dst;
	const char *ptrs = src;
	if (dst < src) {
		while (n--) {
			*ptrd++ = *ptrs++;
		}
	} else {
		while (n--) {
			*(ptrd + n) = *(ptrs + n);
		}
	}
	return dst;
}

/*
函数功能：将内存块从源位置复制到目标位置，不处理内存重叠情况。
参数：指向目标位置的指针 out，指向源位置的指针 in，以及要复制的字节数 n。
返回值：指向目标位置的指针。
*/
void *memcpy(void *out, const void *in, size_t n) {
	assert(out != NULL && in != NULL);
	char *ptrd = out;
	const char *ptrs = in;
	while (n--) {
		*ptrd++ = *ptrs++;
	}
	return out;
}

/*
函数功能：比较两个内存块的内容。
参数：指向要比较的内存块的指针 s1 和 s2，以及要比较的字节数 n。
返回值：如果内存块相等，返回 0；如果内存块不相等，返回第一个不匹配字节的差值。
*/
int memcmp(const void *s1, const void *s2, size_t n) {
	assert(s1 != NULL && s2 != NULL);
	const unsigned char *ptra = s1, *ptrb = s2;
	int ret;
	while (n--) {
		ret = *ptra - *ptrb;
	  if (ret != 0) return ret;
	}
	return 0;
}

#endif