#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <nwm.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#ifdef __ISA_NATIVE__
#include <sys/prctl.h>
#include <signal.h>
#endif

void Window::draw_raw_px(int x, int y, uint32_t color) {
  if (x >= 0 && y >= 0 && x < w && y < h) {
    wm->mark_dirty(this->x + x, this->y + y);
    canvas[x + y * w] = color;
  }
}

void Window::draw_px(int x, int y, uint32_t color) {
  draw_raw_px(x + dx, y + dy, color);
}

void Window::draw_ch(BDF_Font *font, int x, int y, char ch, uint32_t color) {
  uint32_t *bm = font->font[ch];
  if (!bm) return;
  for (int j = 0; j < font->h; j ++)
    for (int i = 0; i < font->w; i ++)
      if ((bm && ((bm[j] >> i) & 1))) {
        draw_px(x + i, y + j, color);
      }
}

void Window::draw_raw_ch(BDF_Font *font, int x, int y, char ch, uint32_t color) {
  uint32_t *bm = font->font[ch];
  if (!bm) return;
  for (int j = 0; j < font->h; j ++)
    for (int i = 0; i < font->w; i ++)
      if ((bm && ((bm[j] >> i) & 1))) {
        draw_raw_px(x + i, y + j, color);
      }
}

void Window::draw() {
  for (int i = 0; i < w; i ++)
    for (int j = 0; j < h; j ++) {
      wm->mark_dirty(this->x + i, this->y + j);
    }
}

Window::Window(WindowManager *wm, const char *cmd, const char * const *argv, const char **envp) {
  this->wm = wm;
  x = y = w = h = 0;
  canvas = nullptr;
  fb = nullptr;

  if (cmd) {
    has_titlebar = true;
    has_alpha = false;
    const char *title = cmd;
    for (const char *p = cmd; *p; p ++) {
      if (*p == '/') title = p + 1;
    }
    strcpy(this->title, title);

    // create child process
    assert(0 == pipe2(nwm_to_app, O_NONBLOCK));
    assert(0 == pipe2(app_to_nwm, O_NONBLOCK));

    read_fd = app_to_nwm[0];
    write_fd = nwm_to_app[1];
    fbdev_fd = memfd_create("nwm-fbdev", 0);

    pid_t p = fork();
    if (p == 0) { // child
#ifdef __ISA_NATIVE__
      // install a parent death signal in the chlid
      int r = prctl(PR_SET_PDEATHSIG, SIGTERM);
      if (r == -1) {
        perror("prctl error");
        assert(0);
      }
#endif

      // FIXME: what if they are overlapped
      dup2(nwm_to_app[0], 3);
      dup2(app_to_nwm[1], 4);
      dup2(fbdev_fd, 5);

      // close enough files, which fixes the fork-after-SDL issue
      for (int i = 6; i < 20; i ++) close(i);

      execve(argv[0], (char**)argv, (char**)envp);
      assert(0);
    } else {
    }
  } else {
    // an internal window (without title bar)
    has_alpha = true;
    has_titlebar = false;
    read_fd = write_fd = -1;
    fbdev_fd = -1;
  }
}

void Window::move(int x, int y) {
  draw();
  this->x = x;
  this->y = y;
  draw();
}

void Window::center() {
  move((wm->w - w) / 2, (wm->h - h) / 2);
}

void Window::resize(int width, int height) {
  draw();

  if (canvas) {
    delete [] canvas;
    canvas = nullptr;
  }

  if (fbdev_fd != -1) munmap(fb, fw * fh * sizeof(uint32_t));

  if (has_titlebar) {
    this->w = width + border_px * 2;
    this->h = height + border_px * 2 + title_px;
    this->dx = border_px;
    this->dy = title_px + border_px;
  } else {
    this->w = width;
    this->h = height;
    this->dx = 0;
    this->dy = 0;
  }
  this->fw = width; // frame buffer w/h
  this->fh = height;

  if (fbdev_fd != -1) {
    int fbsize = fw * fh * sizeof(uint32_t);
    ftruncate(fbdev_fd, fbsize);
    fb = (uint32_t *)mmap(NULL, fbsize, PROT_READ | PROT_WRITE, MAP_SHARED, fbdev_fd, 0);
    assert(fb != (void *) -1);
    write(write_fd, "mmap ok", 7);
  }

  canvas = new uint32_t[w * h];

  for (int i = 0; i < w; i ++)
    for (int j = 0; j < h; j ++)
      draw_raw_px(i, j, border_col);

  if (has_titlebar) {
    for (int i = 0; i < w; i ++) {
      for (int j = 0; j < title_px; j ++) {
        int cx = 100 - 100 * i / w;
        int cy = 100 - 100 * j / title_px;
        uint8_t c = (cx + cy) / 10 + 200;
        draw_raw_px(i, j, (c << 16) | (c << 8) | c);
      }
    }

    int x = (w - strlen(title) * wm->title_font->w) / 2;
    int y = 2;
    for (const char *p = title; *p; p ++) {
      draw_raw_ch(wm->title_font, x, y, *p, title_col);
      x += wm->title_font->w;
    }

    draw_raw_px(0, 0, 0xff000000);
    draw_raw_px(w - 1, 0, 0xff000000);
  }

  draw();
}

Window::~Window() {
  if (canvas) {
    delete [] canvas;
    canvas = nullptr;
  }
  if (fbdev_fd != -1) {
    munmap(fb, fw * fh * sizeof(uint32_t));
    fb = nullptr;
    close(fbdev_fd);
    fbdev_fd = -1;
  }
  if (read_fd != -1) {
     // close pipes
    for (int i = 0; i < 2; i ++) {
      close(nwm_to_app[i]);
      close(app_to_nwm[i]);
    }
  }
}

void Window::update() {
  if (read_fd != -1) {
    do {
      char buf[64];
      int nread = read(read_fd, buf, sizeof(buf) - 1); // this a non-blocking read
      if (nread == -1) break;
      buf[nread] = '\0';
      int w, h;
      int ret = sscanf(buf, "%d %d", &w, &h);
      if (ret == 2) resize(w, h);
    } while (1);
    int y;
    for (y = 0; y < fh; y ++) {
      memcpy(&canvas[(dy + y) * w + dx], &fb[y * fw], fw * sizeof(uint32_t));
    }
    draw();
  }
}
