#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL.h>
#include <vorbis.h>
#include <fixedptc.h>

#define MUSIC_PATH "/share/music/little-star.ogg"
#define SAMPLES 4096
#define FPS 10
#define W 400
#define H 100
#define MAX_VOLUME 128

stb_vorbis *v = NULL;
stb_vorbis_info info = {};
SDL_Surface *screen = NULL;
int is_end = 0;
int16_t *stream_save = NULL;
int volume = MAX_VOLUME;

static void drawVerticalLine(int x, int y0, int y1, uint32_t color) {
  assert(y0 <= y1);
  int i;
  uint32_t *p = (void *)screen->pixels;
  for (i = y0; i <= y1; i ++) {
    p[i * W + x] = color;
  }
}

static void visualize(int16_t *stream, int samples) {
  int i;
  static int color = 0;
  SDL_FillRect(screen, NULL, 0);
  int center_y = H / 2;
  for (i = 0; i < samples; i ++) {
    fixedpt multipler = fixedpt_cos(fixedpt_divi(fixedpt_muli(FIXEDPT_PI, 2 * i), samples));
    int x = i * W / samples;
    int y = center_y - fixedpt_toint(fixedpt_muli(fixedpt_divi(fixedpt_muli(multipler, stream[i]), 32768), H / 2));
    if (y < center_y) drawVerticalLine(x, y, center_y, color);
    else drawVerticalLine(x, center_y, y, color);
    color ++;
    color &= 0xffffff;
  }
  SDL_UpdateRect(screen, 0, 0, 0, 0);
}

static void AdjustVolume(int16_t *stream, int samples) {
  if (volume == MAX_VOLUME) return;
  if (volume == 0) {
    memset(stream, 0, samples * sizeof(stream[0]));
    return;
  }
  int i;
  for (i = 0; i < samples; i ++) {
    stream[i] = stream[i] * volume / MAX_VOLUME;
  }
}

void FillAudio(void *userdata, uint8_t *stream, int len) {
  int nbyte = 0;
  int samples_per_channel = stb_vorbis_get_samples_short_interleaved(v,
      info.channels, (int16_t *)stream, len / sizeof(int16_t));
  if (samples_per_channel != 0) {
    int samples = samples_per_channel * info.channels;
    nbyte = samples * sizeof(int16_t);
    AdjustVolume((int16_t *)stream, samples);
  } else {
    is_end = 1;
  }
  if (nbyte < len) memset(stream + nbyte, 0, len - nbyte);
  memcpy(stream_save, stream, len);
}

int main(int argc, char *argv[]) {
  SDL_Init(0);
  screen = SDL_SetVideoMode(W, H, 32, SDL_HWSURFACE);
  SDL_FillRect(screen, NULL, 0);
  SDL_UpdateRect(screen, 0, 0, 0, 0);

  FILE *fp = fopen(MUSIC_PATH, "r");
  assert(fp);
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  void *buf = malloc(size);
  assert(size);
  fseek(fp, 0, SEEK_SET);
  int ret = fread(buf, size, 1, fp);
  assert(ret == 1);
  fclose(fp);

  int error;
  v = stb_vorbis_open_memory(buf, size, &error, NULL);
  assert(v);
  info = stb_vorbis_get_info(v);

  SDL_AudioSpec spec;
  spec.freq = info.sample_rate;
  spec.channels = info.channels;
  spec.samples = SAMPLES;
  spec.format = AUDIO_S16SYS;
  spec.userdata = NULL;
  spec.callback = FillAudio;
  SDL_OpenAudio(&spec, NULL);

  stream_save = malloc(SAMPLES * info.channels * sizeof(*stream_save));
  assert(stream_save);
  printf("Playing %s(freq = %d, channels = %d)...\n", MUSIC_PATH, info.sample_rate, info.channels);
  SDL_PauseAudio(0);

  while (!is_end) {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
      if (ev.type == SDL_KEYDOWN) {
        switch (ev.key.keysym.sym) {
          case SDLK_MINUS:  if (volume >= 8) volume -= 8; break;
          case SDLK_EQUALS: if (volume <= MAX_VOLUME - 8) volume += 8; break;
        }
      }
    }
    SDL_Delay(1000 / FPS);
    visualize(stream_save, SAMPLES * info.channels);
  }

  SDL_CloseAudio();
  stb_vorbis_close(v);
  SDL_Quit();
  free(stream_save);
  free(buf);

  return 0;
}
