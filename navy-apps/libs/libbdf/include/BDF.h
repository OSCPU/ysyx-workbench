#ifndef __BDF_H__
#define __BDF_H__

#include <stdint.h>

class BDF_Font {
private:
  int w1, h1;
  void create(uint32_t ch, int *bbx, uint32_t *bitmap, int count);

public:
  const char *name;
  int w, h;
  uint32_t *font[256];

  BDF_Font(const char *filename);
  ~BDF_Font();
};

#endif
