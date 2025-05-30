#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

#define MAXDEC 64
static char *__out;
void sputch(char ch){*__out++ = ch;}

int vprintf( void(*gputch)(char) , const char *fmt, va_list ap){
	int i;
	bool in_format = false;
	int long_flags = 0;
	int pos = 0;
	for( ;*fmt != '\0';fmt++){
		if(*fmt != '%' && in_format == false){
			gputch(*fmt);pos++;
		}
		else{
			if(in_format == false && (*fmt == '%')){
				fmt++;
				in_format = true;
			}
			switch(*fmt){
				case 'l':  //para
					long_flags += 1;
					break;
				case 's':  //%s
					char *s;
					assert(long_flags == 0);
					s = va_arg(ap , char *);
					for(i = 0; s[i] != '\0'; i++){
						gputch(s[i]);pos++;
					}
					in_format = false;
					break;
				case 'c':  //%c
					int c;
					assert(long_flags == 0);
					c = va_arg(ap , int);
					gputch((char)c);pos++;
					in_format = false;
					break;
				case 'd':{//%d
					assert(long_flags <= 2);
					int64_t d = 0;
					if(long_flags == 2)    //get d
						d = va_arg(ap , int64_t);
					else
						d = va_arg(ap , int32_t);

					if(d < 0){
						d = -d;
						gputch('-');pos++;
					}
					if(d == 0){
						gputch('0');pos++;
					};
					char invert[MAXDEC];
					i = 0;
					for( ; d != 0 ; i++ , d/=10){
						invert[i] = d%10 + '0';
					}
					for(i-=1 ;i >= 0 ; i--){
						gputch(invert[i]);pos++;
					}
					long_flags = 0;
					in_format = false;
					break;
					}
				case 'u':{  //%u
					uint64_t u = 0;
					assert(long_flags <= 2);
					if(long_flags == 2)    //get d
						u = va_arg(ap , uint64_t);
					else
						u = va_arg(ap , uint32_t);

					if(u == 0){
						gputch('0');pos++;
					};
					char invert[MAXDEC];
					i = 0;
					for( ; u != 0 ; i++ , u/=10){
						invert[i] = u%10 + '0';
					}
					for(i-=1 ;i >= 0 ; i--){
						gputch(invert[i]);pos++;
					}
					long_flags = 0;
					in_format = false;
					break;
					}
				case '%':
					gputch('%');
					in_format = false;
					break;
			}
		}
	}
	return pos;
}

int printf(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	int res = vprintf(putch , fmt , ap);
	va_end(ap);
	return res;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	__out = out;
	int res = vprintf(sputch , fmt , ap);
	sputch('\0');
	va_end(ap);
	return res++;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
