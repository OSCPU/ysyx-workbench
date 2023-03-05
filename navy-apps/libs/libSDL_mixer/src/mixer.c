#include <SDL_mixer.h>


// General

int Mix_OpenAudio(int frequency, uint16_t format, int channels, int chunksize) {
  return 0;
}

void Mix_CloseAudio() {
}

char *Mix_GetError() {
  return "";
}

int Mix_QuerySpec(int *frequency, uint16_t *format, int *channels) {
  return 0;
}

// Samples

Mix_Chunk *Mix_LoadWAV_RW(SDL_RWops *src, int freesrc) {
  return NULL;
}

void Mix_FreeChunk(Mix_Chunk *chunk) {
}


// Channels

int Mix_AllocateChannels(int numchans) {
  return 0;
}

int Mix_Volume(int channel, int volume) {
  return 0;
}

int Mix_PlayChannel(int channel, Mix_Chunk *chunk, int loops) {
  return 0;
}

void Mix_Pause(int channel) {
}

void Mix_ChannelFinished(void (*channel_finished)(int channel)) {
}

// Music

Mix_Music *Mix_LoadMUS(const char *file) {
  return NULL;
}

Mix_Music *Mix_LoadMUS_RW(SDL_RWops *src) {
  return NULL;
}

void Mix_FreeMusic(Mix_Music *music) {
}

int Mix_PlayMusic(Mix_Music *music, int loops) {
  return 0;
}

int Mix_SetMusicPosition(double position) {
  return 0;
}

int Mix_VolumeMusic(int volume) {
  return 0;
}

int Mix_SetMusicCMD(const char *command) {
  return 0;
}

int Mix_HaltMusic() {
  return 0;
}

void Mix_HookMusicFinished(void (*music_finished)()) {
}

int Mix_PlayingMusic() {
  return 0;
}
