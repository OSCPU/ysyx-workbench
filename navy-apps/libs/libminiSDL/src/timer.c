#include <NDL.h>
#include <sdl-timer.h>
#include <stdio.h>

SDL_TimerID SDL_AddTimer(uint32_t interval, SDL_NewTimerCallback callback, void *param) {
  printf("[SDL_AddTimer] 未实现\n");
  return NULL;
}

int SDL_RemoveTimer(SDL_TimerID id) {
  printf("[SDL_RemoveTimer] 未实现\n");
  return 1;
}

uint32_t SDL_GetTicks() {
 return NDL_GetTicks();
}

// 这个需要至少延迟10ns才能放出来的函数，实际测试发现其实没啥区别，可能本来程序就够卡的了，不实现为默认1ns
// 程序跑不起来时候可以把他删了，能快一点点，不明显。
void SDL_Delay(uint32_t ms) {
   //printf("[SDL_Delay] 未实现\n");
  uint32_t now = NDL_GetTicks();
  uint32_t md  = ms >=10 ? ms :10;
  while(1){
    uint32_t next_now = NDL_GetTicks();
    if(next_now - now>=md)break; 
  }

}
