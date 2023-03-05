#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

char* itoa(int num, char* str, int radix)
{
  char index[]="0123456789ABCDEF";
  unsigned int unum;
  int i=0,j,k;
  if(radix==-10&&num<0)
  {
    unum=(unsigned)(-num);
    str[i++]='-';
  }
  else unum=(unsigned)num;
	if(radix==-10)radix=10;
  do
  {
    str[i++]=index[unum%(unsigned)radix];
    unum/=radix;
  }while(unum);
  str[i]=0;
  if(str[0]=='-')k=1;
  else k=0;
  char temp;
  for(j=k;j<=(i-1)/2;j++)
  {
    temp=str[j];
    str[j]=str[i-1+k-j];
    str[i-1+k-j]=temp;
  }
  return str;
}

int printf(const char *fmt, ...) {
  va_list ap;
  int fmti=0;
  int num=0;
  va_start(ap,fmt);
  while(*(fmt+fmti)!=0)
  {
    if(*(fmt+fmti)!='%')
    {
      num++;
			putch(*(fmt+fmti));
    }
    else
    {
      fmti++;
      switch(*(fmt+fmti))
      {
        case '%':
					putch('%');
          num++;
          break;
        case 'c':
          putch((char)va_arg(ap,int));
          num++;
          break;
        case 'd':
					{
						int integer=va_arg(ap,int);
						char str[32];
						itoa(integer,str,-10);
						int n=0;
						while(*(str+n)!=0)
						{
							putch(*(str+n++));
							num++;
						}
					}
          break;
        case 'u':
					{
						unsigned int integer=va_arg(ap,unsigned int);
						char str[32];
						itoa(integer,str,10);
						int n=0;
						while(*(str+n)!=0)
						{
							putch(*(str+n++));
							num++;
						}
					}
          break;
        case 'x':
        case 'p':
					{
						int integer=va_arg(ap,int);
						char str[32];
						itoa(integer,str,16);
						int n=0;
						while(*(str+n)!=0)
						{
							putch(*(str+n++));
							num++;
						}
					}
          break;
        case 's':
					{
						char *str=va_arg(ap,char *);
						int n=0;
						while(*(str+n)!=0)
						{
							putch(*(str+n++));
							num++;
						}
					}
          break;
        default:
          return -1;
          break;
      }
    }
		fmti++;
  }
  va_end(ap);
  return num;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  int outi=0;
  int fmti=0;
  int num=0;
  va_start(ap,fmt);
  while(*(fmt+fmti)!=0)
  {
			//printf("char:'%c'\n",*(fmt+fmti));
    if(*(fmt+fmti)!='%')
    {
      *(out+outi++)=*(fmt+fmti);
      num++;
    }
    else
    {
      fmti++;
      switch(*(fmt+fmti))
      {
        case '%':
          *(out+outi++)='%';
          num++;
          break;
        case 'c':
          *(out+outi++)=(char)va_arg(ap,int);
          num++;
          break;
        case 'd':
					{
						int integer=va_arg(ap,int);
						char str[32];
						itoa(integer,str,-10);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        case 'u':
					{
						unsigned int integer=va_arg(ap,unsigned int);
						char str[32];
						itoa(integer,str,10);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        case 'x':
        case 'p':
					{
						int integer=va_arg(ap,int);
						char str[32];
						itoa(integer,str,16);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        case 's':
					{
						char *str=va_arg(ap,char *);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        default:
          return -1;
          break;
      }
    }
    fmti++;
  }
  va_end(ap);
  *(out+outi)=0;
  return num;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  int outi=0;
  int fmti=0;
  int num=0;
  va_start(ap,fmt);
  while(*(fmt+fmti)!=0&&num<n)
  {
			//printf("char:'%c'\n",*(fmt+fmti));
    if(*(fmt+fmti)!='%')
    {
      *(out+outi++)=*(fmt+fmti);
      num++;
    }
    else
    {
      fmti++;
      switch(*(fmt+fmti))
      {
        case '%':
          *(out+outi++)='%';
          num++;
          break;
        case 'c':
          *(out+outi++)=(char)va_arg(ap,int);
          num++;
          break;
        case 'd':
					{
						int integer=va_arg(ap,int);
						char str[32];
						itoa(integer,str,-10);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        case 'u':
					{
						unsigned int integer=va_arg(ap,unsigned int);
						char str[32];
						itoa(integer,str,10);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        case 'x':
        case 'p':
					{
						int integer=va_arg(ap,int);
						char str[32];
						itoa(integer,str,16);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        case 's':
					{
						char *str=va_arg(ap,char *);
						int n=0;
						while(*(str+n)!=0)
						{
							*(out+outi++)=*(str+n++);
							num++;
						}
					}
          break;
        default:
          return -1;
          break;
      }
    }
    fmti++;
  }
  va_end(ap);
  *(out+outi)=0;
  return num;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
