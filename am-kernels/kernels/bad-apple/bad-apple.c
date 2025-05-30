#include <am.h>
#include <stdio.h>
#include <klib-macros.h>

#define FPS 30
#define CHAR_WHITE '.'
#define CHAR_BLACK 'X'

typedef struct {
  uint8_t pixel[VIDEO_ROW * VIDEO_COL / 8];
} frame_t;

static void sleep_until(uint64_t next) {
  while (io_read(AM_TIMER_UPTIME).us < next) ;
}

static uint8_t getbit(uint8_t *p, int idx) {
  int byte_idx = idx / 8;
  int bit_idx = idx % 8;
  bit_idx = 7 - bit_idx;
  uint8_t byte = p[byte_idx];
  uint8_t bit = (byte >> bit_idx) & 1;
  return bit;
}

int main() {
  extern uint8_t video_payload, video_payload_end;
  extern uint8_t audio_payload, audio_payload_end;
  int audio_len = 0, audio_left = 0;
  Area sbuf;

  ioe_init();

  frame_t *f = (void *)&video_payload;
  frame_t *fend = (void *)&video_payload_end;
  printf("\033[H\033[J");  // screan_clear

  bool has_audio = io_read(AM_AUDIO_CONFIG).present;
  if (has_audio) {
    io_write(AM_AUDIO_CTRL, AUDIO_FREQ, AUDIO_CHANNEL, 1024);
    audio_left = audio_len = &audio_payload_end - &audio_payload;
    sbuf.start = &audio_payload;
  }
  
  uint64_t now = io_read(AM_TIMER_UPTIME).us;
  for (; f < fend; f ++) {
     printf("\033[0;0H");  // reset cursor
     for (int y = 0; y < VIDEO_ROW; y++) {
       for (int x = 0; x < VIDEO_COL; x++) {
         uint8_t p = getbit(f->pixel, y * VIDEO_COL + x);
         putch(p ? CHAR_BLACK : CHAR_WHITE);
       }
       putch('\n');
     }

     if (has_audio) {
       int should_play = (AUDIO_FREQ / FPS) * sizeof(int16_t) * AUDIO_CHANNEL;
       if (should_play > audio_left) should_play = audio_left;
       audio_left -= should_play;
       while (should_play > 0) {
         int len = (should_play > 4096 ? 4096 : should_play);
         sbuf.end = sbuf.start + len;
         io_write(AM_AUDIO_PLAY, sbuf);
         sbuf.start += len;
         should_play -= len;
       }
     }

     uint64_t next = now + (1000 * 1000 / FPS);
     sleep_until(next);
     now = next;
  }
  return 0;
}
