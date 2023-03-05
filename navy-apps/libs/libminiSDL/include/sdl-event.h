#ifndef __SDL_EVENT_H__
#define __SDL_EVENT_H__

#define _KEYS(_) \
  _(ESCAPE) _(F1) _(F2) _(F3) _(F4) _(F5) _(F6) _(F7) _(F8) _(F9) _(F10) _(F11) _(F12) \
  _(GRAVE) _(1) _(2) _(3) _(4) _(5) _(6) _(7) _(8) _(9) _(0) _(MINUS) _(EQUALS) _(BACKSPACE) \
  _(TAB) _(Q) _(W) _(E) _(R) _(T) _(Y) _(U) _(I) _(O) _(P) _(LEFTBRACKET) _(RIGHTBRACKET) _(BACKSLASH) \
  _(CAPSLOCK) _(A) _(S) _(D) _(F) _(G) _(H) _(J) _(K) _(L) _(SEMICOLON) _(APOSTROPHE) _(RETURN) \
  _(LSHIFT) _(Z) _(X) _(C) _(V) _(B) _(N) _(M) _(COMMA) _(PERIOD) _(SLASH) _(RSHIFT) \
  _(LCTRL) _(APPLICATION) _(LALT) _(SPACE) _(RALT) _(RCTRL) \
  _(UP) _(DOWN) _(LEFT) _(RIGHT) _(INSERT) _(DELETE) _(HOME) _(END) _(PAGEUP) _(PAGEDOWN)

#define enumdef(k) SDLK_##k,

enum SDL_Keys {
  SDLK_NONE = 0,
  _KEYS(enumdef)
};

enum SDL_EventType {
  SDL_KEYDOWN,
  SDL_KEYUP,
  SDL_USEREVENT,
};

#define SDL_EVENTMASK(ev_type) (1u << (ev_type))

enum SDL_EventAction {
  SDL_ADDEVENT,
  SDL_PEEKEVENT,
  SDL_GETEVENT,
};

typedef struct {
  uint8_t sym;
} SDL_keysym;

typedef struct {
  uint8_t type;
  SDL_keysym keysym;
} SDL_KeyboardEvent;

typedef struct {
  uint8_t type;
  int code;
  void *data1;
  void *data2;
} SDL_UserEvent;

typedef union {
  uint8_t type;
  SDL_KeyboardEvent key;
  SDL_UserEvent user;
} SDL_Event;

int SDL_PushEvent(SDL_Event *ev);
int SDL_PollEvent(SDL_Event *ev);
int SDL_WaitEvent(SDL_Event *ev);
int SDL_PeepEvents(SDL_Event *ev, int numevents, int action, uint32_t mask);
uint8_t* SDL_GetKeyState(int *numkeys);

#endif
