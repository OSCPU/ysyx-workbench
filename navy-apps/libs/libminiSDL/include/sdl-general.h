#ifndef __SDL_GENERAL_H__
#define __SDL_GENERAL_H__

#include <stdint.h>
#include <stdio.h>

#define SDL_INIT_VIDEO       0x01
#define SDL_INIT_TIMER       0x02
#define SDL_INIT_AUDIO       0x04
#define SDL_INIT_NOPARACHUTE 0x08
#define SDL_INIT_JOYSTICK    0x10

int SDL_Init(uint32_t flags);
void SDL_Quit();
char *SDL_GetError();
int SDL_SetError(const char* fmt, ...);
int SDL_ShowCursor(int toggle);
void SDL_WM_SetCaption(const char *title, const char *icon);

typedef struct SDL_mutex {} SDL_mutex;
static inline SDL_mutex* SDL_CreateMutex() { return NULL; }
static inline void SDL_DestroyMutex(SDL_mutex* mutex) { }
static inline int SDL_mutexP(SDL_mutex* mutex) { return 0; }
static inline int SDL_mutexV(SDL_mutex* mutex) { return 0; }

#endif
