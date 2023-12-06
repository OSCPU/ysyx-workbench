#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
	panic("Not implemented");	
}
int vsprintf(char *out, const char *fmt, va_list ap) {
	int len=0;
	while(*fmt!='\0')
	{
		switch(*fmt)
		{
			case '%':
			  fmt++;
			switch(*fmt)
			{
			  case 'd':
			    int val=va_arg(ap,int); 
			    if(val==0)
			    {out[len]='0';
			     len++;
			     break;}
			    else if(val<0)
			    {out[len]='-';
			     len++;
			     val=0-val;}
			     int r;
			     char *p="0";
			     int plen=0;
			     while(val>0)
			     {
			     	r=val%10;
				val=val/10;
				p[plen]=48+r;
				plen++;
			     }
			     for(int i=plen-1;i>=0;i--)
			     {
			       out[len]=p[i];
			       len++;
			     }
			     break;
			     case 's':
			     int i;
			     char *sr=va_arg(ap,char*);
			     for(i=0;sr[i]!='\0';i++)
			     {
			     	out[len]=sr[i];
				len++;
			     }
			     break;
			}
			break;
			case '\n':
			  out[len]='\n';
			  len++;
			  break;
			default:
			  out[len]=*fmt;
			  len++;
		}
		fmt++;
	}
	out[len]='\0';
	return len;
}

int sprintf(char *out, const char *fmt, ...) {
	   va_list ap;
	   size_t n;
           va_start(ap, fmt);
	   n=vsprintf(out,fmt,ap);
           va_end(ap);
           return n;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
