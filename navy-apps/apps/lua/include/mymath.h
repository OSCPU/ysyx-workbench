#ifndef mymath_h
#define mymath_h

#ifndef LUA_INTONLY_NUMBERS
#include <math.h>
#else
#include <luaconf.h>
LUA_NUMBER floor(LUA_NUMBER x);
LUA_NUMBER pow(LUA_NUMBER x, LUA_NUMBER y);
LUA_NUMBER fmod(LUA_NUMBER x, LUA_NUMBER y);
LUA_NUMBER frexp(LUA_NUMBER x, int *exp);
LUA_NUMBER tan(LUA_NUMBER x);
LUA_NUMBER sqrt(LUA_NUMBER x);
LUA_NUMBER sin(LUA_NUMBER x);
LUA_NUMBER log2(LUA_NUMBER x);
LUA_NUMBER log10(LUA_NUMBER x);
LUA_NUMBER log(LUA_NUMBER x);
LUA_NUMBER exp(LUA_NUMBER x);
LUA_NUMBER cos(LUA_NUMBER x);
LUA_NUMBER atan2(LUA_NUMBER y, LUA_NUMBER x);
LUA_NUMBER asin(LUA_NUMBER x);
LUA_NUMBER acos(LUA_NUMBER x);
LUA_NUMBER ceil(LUA_NUMBER x);
LUA_NUMBER fabs(LUA_NUMBER x);
LUA_NUMBER ldexp(LUA_NUMBER x, int exp);
LUA_NUMBER nan(const char *tagp);
#endif

#endif
