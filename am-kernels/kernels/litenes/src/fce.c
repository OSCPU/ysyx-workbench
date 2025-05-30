#include "fce.h"
#include "cpu.h"
#include "memory.h"
#include "ppu.h"
#include "psg.h"
#include <klib.h>

static int frame_cnt;
static inline bool candraw() { return frame_cnt % (1 + FRAME_SKIP) == 0; }

static uint32_t canvas[SCR_W * SCR_H];

void draw(int x, int y, int idx) {
  if (x >= 0 && x < SCR_W && y >= 0 && y < SCR_H && candraw()) {
    canvas[y * SCR_W + x] = palette[idx];
  }
}

typedef struct {
  char signature[4];
  byte prg_block_count;
  byte chr_block_count;
  word rom_type;
  byte reserved[8];
} ines_header;

static byte *buf;
static ines_header *fce_rom_header;

byte *romread(int size) {
  byte *ret = buf;
  buf += size;
  return ret;
}

int fce_load_rom(char *rom) {
  buf = (byte*)rom;
  fce_rom_header = (ines_header*)romread(sizeof(ines_header));

  if (memcmp(fce_rom_header->signature, "NES\x1A", 4)) {
    return -1;
  }

  mmc_id = ((fce_rom_header->rom_type & 0xF0) >> 4);

  int prg_size = fce_rom_header->prg_block_count * 0x4000;

  byte *blk = romread(prg_size);

  if (mmc_id == 0 || mmc_id == 3) {
    // if there is only one PRG block, we must repeat it twice
    if (fce_rom_header->prg_block_count == 1) {
      mmc_copy(0x8000, blk, 0x4000);
      mmc_copy(0xC000, blk, 0x4000);
    }
    else {
      mmc_copy(0x8000, blk, 0x8000);
    }
  }
  else {
    return -1;
  }

  // Copying CHR pages into MMC and PPU
  int i;
  for (i = 0; i < fce_rom_header->chr_block_count; i++) {
    byte *blk = romread(0x2000);
    mmc_append_chr_rom_page(blk);

    if (i == 0) {
      ppu_copy(0x0000, blk, 0x2000);
    }
  }

  return 0;
}

void fce_init() {
  cpu_init();
  ppu_init();
  ppu_set_mirroring(fce_rom_header->rom_type & 1);
  cpu_reset();
}

static int gtime;

static inline int uptime_ms() {
  return io_read(AM_TIMER_UPTIME).us / 1000;
}

void wait_for_frame() {
  int cur = uptime_ms();
  while (cur - gtime < 1000 / FPS) {
    cur = uptime_ms();
  }
  gtime = cur;
}

// FCE Lifecycle

void fce_run() {
  gtime = uptime_ms();
  int nr_draw = 0;
  uint32_t last = gtime;
  while(1) {
    wait_for_frame();
    int scanlines = 262;

    while (scanlines-- > 0) {
      ppu_cycle();
      psg_detect_key();
    }

    nr_draw ++;
    int upt = uptime_ms();
    if (upt - last > 1000) {
      last = upt;
      for (int i = 0; i < 80; i++) putch('\b');
      printf("(System time: %ds) FPS = %d", upt / 1000, nr_draw);
      nr_draw = 0;
    }
  }
}

void fce_update_screen() {
  frame_cnt++;
  if (!candraw()) return;

  int idx = ppu_ram_read(0x3F00);
  uint32_t bgc = palette[idx];

  AM_GPU_CONFIG_T cfg = io_read(AM_GPU_CONFIG);
  int xpad = (cfg.width  - SCR_W) / 2;
  int ypad = (cfg.height - SCR_H) / 2;
  panic_on(xpad < 0 || ypad < 0, "screen too small");

  io_write(AM_GPU_FBDRAW, xpad, ypad, canvas, SCR_W, SCR_H, true);

  for (int i = 0; i < SCR_W * SCR_H; i ++) canvas[i] = bgc;
}
