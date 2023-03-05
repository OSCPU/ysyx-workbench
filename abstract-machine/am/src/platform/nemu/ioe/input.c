#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define KEYDOWN_MASK 0x8000
#define KEY_QUEUE_LEN 1024

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd)
{
  uint32_t key = inl(KBD_ADDR);
  //key在nemu中的读取原理参照，keycode | keydown == KEYDOWN_MASK ? 1 :0 ;
  //uint32_t am_scancode = keymap[scancode] | (is_keydown ? KEYDOWN_MASK : 0);
  int keycode = key & ~ KEYDOWN_MASK;
  int keydown = key & KEYDOWN_MASK;

  if (keycode == AM_KEY_NONE)
  {
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE;
  }
  else
  {
    /*
      printf ("0x%x \n",keycode);
      printf ("0x%x \n",key);
      printf ("0x%x \n",keydown);

*/
    if (keydown != 0)
      kbd->keydown = true;
    else
      kbd->keydown = false;
    kbd->keycode = keycode;
  }
}
