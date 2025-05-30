#ifndef PSG_H
#define PSG_H

#include "common.h"

#define KEY_A       J
#define KEY_B       K
#define KEY_SELECT  U
#define KEY_START   I
#define KEY_UP      W
#define KEY_DOWN    S
#define KEY_LEFT    A
#define KEY_RIGHT   D

byte psgio_read(word address);
void psgio_write(word address, byte data);
void psg_init();
void psg_detect_key();

#endif
