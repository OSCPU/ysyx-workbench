#ifndef __SDL_TIMER_H__
#define __SDL_TIMER_H__

typedef void* SDL_TimerID;
typedef uint32_t (*SDL_NewTimerCallback)(uint32_t interval, void *param);

SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param);
int SDL_RemoveTimer(SDL_TimerID id);
uint32_t SDL_GetTicks();
void SDL_Delay(uint32_t ms);

#endif
