#include <NDL.h>
#include <SDL.h>
#include <assert.h>
#include <string.h>

#define keyname(k) #k,

// 按键名称匹配表（按键数量83）
static const char *keyname[] = {
  "NONE",
  _KEYS(keyname)
};

// 维护一个所有按键状态的数组给SDL_GetKeyState用
static uint8_t key_state[sizeof(keyname) / sizeof(keyname[0])];


// SDL_PushEvent  Pushes an event onto the event queue
int SDL_PushEvent(SDL_Event *ev) {
  printf("[SDL_PushEvent] 未实现\n");
  return 0;
}

// 有事件返回1,把事件写入ev中，没有返回0.
int SDL_PollEvent(SDL_Event *ev) {
  char buf[20];
  if(NDL_PollEvent(buf,20)){
    // 过滤换行符来保证navy-app的native可以正常使用(native中的按键信息加了一个换行符而位的没加产生区别，困惑过很久)
    // 现在解决办法是改了native的信息去掉了这个换行符；还可以手动把接受的字符串曲调这个换行符
    
    //printf("%s\n",buf);
    int pos = 0;
    // 检查一下读到的事件文本对不对
    assert(buf[pos] == 'k' && (buf[pos+1] == 'd' || buf[pos+1] == 'u'));

    // 判断按键的状态并写入ev中
    // 此处可以写入的有ev->type 指明event类型.
    // 根据main中的编写，实现keyup keydown这两种判断
    ev->type     = (buf[pos + 1] == 'd') ? SDL_KEYDOWN : SDL_KEYUP;

    // 逐个对比，将相应的键值赋给ev->key.keysym.sym
    for (int i = 0; i< (sizeof(key_state) / sizeof(uint8_t)); ++i){
      // buf[3]开始是keyname，遍历按键数组匹配到相应按键
      // 在key_state中设置相应的状态
      //printf("strcmp(buf +3 , keyname[i]) == %d --%d\n",strcmp(buf +3 , keyname[i]),i);
      if(strcmp(buf +3 , keyname[i]) == 0){
        ev->key.keysym.sym = i;
        //printf("ev->type %d ev->key.keysym.sym %d\n", ev->type, ev->key.keysym.sym);
        switch(ev->type){
          case SDL_KEYDOWN : 
            key_state[i] = 1;
            //printf("[SDL_PollEvent] %s DOWN\n",keyname[i]);
            break;
          case SDL_KEYUP   :
            key_state[i] = 0;
            //printf("[SDL_PollEvent] %s UP\n",keyname[i]);
            break;
            default :
            //printf("[SDL_PollEvent] 没有遇到的按键");
            break;
        }
      }
    }
    return 1;
    
  }
  return 0;
}

// 直到有按键按下后返回1否者一直等待，与SDL_PollEvent行为一致
int SDL_WaitEvent(SDL_Event *event) {
  printf("进入SDL_WaitEvent等待按键输入\n");
  while(SDL_PollEvent(event) == 0);
  return 1;
}

int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask) {
  printf("[SDL_PeepEvents] 未实现\n");
  return 0;
}

// 返回一个指向键状态数组的指针。键状态表示为整数，0 表示该键未被按下，1 表示该键已被按下。
// numkeys 是输出参数，为返回数组中的元素数。不使用这个参数，可以将其传入 NULL。
uint8_t* SDL_GetKeyState(int *numkeys) {
  //printf("[SDL_GetKeyState] entering and return\n");
  if(numkeys){
    *numkeys = sizeof(key_state) / sizeof(uint8_t);
  }
  return key_state;
}
