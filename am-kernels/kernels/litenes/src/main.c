#include "common.h"
#include "fce.h"
#include "psg.h"

extern char rom_mario_nes[];

int main() {
  ioe_init();

  printf("==================== LiteNES Emulator ====================\n\n");
  printf("Control:      [%s]         SELECT [%s]   START [%s]\n"
         "          [%s] [%s] [%s]          A [%s]   B     [%s]\n\n",
        TOSTRING(KEY_UP),   TOSTRING(KEY_SELECT), TOSTRING(KEY_START),
        TOSTRING(KEY_LEFT), TOSTRING(KEY_DOWN),   TOSTRING(KEY_RIGHT),
        TOSTRING(KEY_A),    TOSTRING(KEY_B));
  printf("==========================================================\n");

  fce_load_rom((void *)rom_mario_nes);
  fce_init();
  fce_run();
  return 1;
}
