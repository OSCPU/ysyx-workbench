#include "psg.h"
#include <klib.h>

static int p = 10;
static int key_state[256];

#define KEYS \
  CONCAT(AM_KEY_, KEY_A), \
  CONCAT(AM_KEY_, KEY_B), \
  CONCAT(AM_KEY_, KEY_SELECT), \
  CONCAT(AM_KEY_, KEY_START), \
  CONCAT(AM_KEY_, KEY_UP), \
  CONCAT(AM_KEY_, KEY_DOWN), \
  CONCAT(AM_KEY_, KEY_LEFT), \
  CONCAT(AM_KEY_, KEY_RIGHT),

static int MAP[256] = {
  0, // On/Off
  KEYS
  255,
};

byte psgio_read(word address) {
  // Joystick 1
  if (address == 0x4016) {
    if (p++ < 9) {
      return key_state[MAP[p]];
    }
  }
  return 0;
}

void psgio_write(word address, byte data) {
  static byte prev_write;
  if (address == 0x4016) {
    if ((data & 1) == 0 && prev_write == 1) {
      // strobe
      p = 0;
    }
  }
  prev_write = data & 1;
}

void psg_detect_key() {
  while (1) {
    AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
    if (ev.keycode == AM_KEY_NONE) break;
    key_state[ev.keycode] = ev.keydown;
  }
}

void psg_init() {
  key_state[0] = 1;
}
