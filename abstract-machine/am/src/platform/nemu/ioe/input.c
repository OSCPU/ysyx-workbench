#include <am.h>
#include <nemu.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t key = inl(KBD_ADDR);  // 从键盘IO口读取按键信息
  kbd->keydown = (key & 0x8000) != 0; // 高位为 1 表示按下，0 表示松开
  kbd->keycode = key & 0x7fff;        // 低 15 位为按键码
}
