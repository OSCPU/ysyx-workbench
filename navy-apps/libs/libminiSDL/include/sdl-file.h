#include <stdint.h>
#include <stdio.h>

enum { RW_TYPE_FILE, RW_TYPE_MEM };

#define RW_SEEK_SET SEEK_SET
#define RW_SEEK_CUR SEEK_CUR
#define RW_SEEK_END SEEK_END

typedef struct SDL_RWops {
  int64_t (*size) (struct SDL_RWops *f);
  int64_t (*seek) (struct SDL_RWops *f, int64_t offset, int whence);
  size_t  (*read) (struct SDL_RWops *f, void *buf, size_t size, size_t nmemb);
  size_t  (*write)(struct SDL_RWops *f, const void *buf, size_t size, size_t nmemb);
  int     (*close)(struct SDL_RWops *f);
  uint32_t type;
  FILE *fp;

  // mem.base is only defined when type == RW_TYPE_MEM
  struct { void *base; ssize_t size; } mem;
} SDL_RWops;

SDL_RWops* SDL_RWFromFile(const char *filename, const char *mode);
SDL_RWops* SDL_RWFromMem(void *mem, int size);

#define SDL_RWtell(f)  SDL_RWseek(f, 0, RW_SEEK_CUR)
#define SDL_RWsize(f)  f->size(f)
#define SDL_RWseek(f, offset, whence)  f->seek(f, offset, whence)
#define SDL_RWread(f, buf, size, nmemb)  f->read(f, buf, size, nmemb)
#define SDL_RWwrite(f, buf, size, nmemb) f->write(f, buf, size, nmemb)
#define SDL_RWclose(f) f->close(f)
