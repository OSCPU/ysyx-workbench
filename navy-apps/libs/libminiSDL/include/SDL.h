#ifndef __SDL_H__
#define __SDL_H__

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "sdl-general.h"
#include "sdl-event.h"
#include "sdl-timer.h"
#include "sdl-video.h"
#include "sdl-audio.h"
#include "sdl-file.h"

#ifdef __cplusplus
}
#endif

typedef bool SDL_bool;
typedef uint8_t  Uint8;
typedef int16_t  Sint16;
typedef uint16_t Uint16;
typedef int32_t  Sint32;
typedef uint32_t Uint32;
typedef int64_t  Sint64;
typedef uint64_t Uint64;

#define SDL_FALSE 0
#define SDL_TRUE  1

#define SDLCALL

// define correct SDL key names
#define SDLK_a   SDLK_A
#define SDLK_b   SDLK_B
#define SDLK_c   SDLK_C
#define SDLK_d   SDLK_D
#define SDLK_e   SDLK_E
#define SDLK_f   SDLK_F
#define SDLK_g   SDLK_G
#define SDLK_h   SDLK_H
#define SDLK_i   SDLK_I
#define SDLK_j   SDLK_J
#define SDLK_k   SDLK_K
#define SDLK_l   SDLK_L
#define SDLK_m   SDLK_M
#define SDLK_n   SDLK_N
#define SDLK_o   SDLK_O
#define SDLK_p   SDLK_P
#define SDLK_q   SDLK_Q
#define SDLK_r   SDLK_R
#define SDLK_s   SDLK_S
#define SDLK_t   SDLK_T
#define SDLK_u   SDLK_U
#define SDLK_v   SDLK_V
#define SDLK_w   SDLK_W
#define SDLK_x   SDLK_X
#define SDLK_y   SDLK_Y
#define SDLK_z   SDLK_Z

#endif
