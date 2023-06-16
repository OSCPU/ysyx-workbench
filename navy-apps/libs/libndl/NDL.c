#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/time.h>

static int evtdev = -1;
static int fbdev = -1;
static int screen_w = 0, screen_h = 0;
static int canvas_w = 0, canvas_h = 0;
static int canvas_x = 0, canvas_y = 0;

extern int open (const char *file, int flags, ...);
extern ssize_t read (int fd, void *buf, size_t cnt);
extern ssize_t write (int fd, const void *buf, size_t cnt);
extern __off_t lseek(int fd, __off_t pos, int whence);
extern int close (int fd);

uint32_t NDL_GetTicks() 
{
    static uint64_t boot_time = 0;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    uint64_t us = tv.tv_usec + tv.tv_sec * 1000000;

    if(boot_time == 0)
        boot_time = us;

    return (us-boot_time) / 1000;
}

int NDL_PollEvent(char *buf, int len) 
{
    return read(open("/dev/events", 0, 0), buf, len);
}

void NDL_OpenCanvas(int *w, int *h) 
{
    if(getenv("NWM_APP")) 
    {
        int fbctl = 4;
        fbdev = 5;
        screen_w = *w; screen_h = *h;
        char buf[64];
        int len = sprintf(buf, "%d %d", screen_w, screen_h);
        // let NWM resize the window and create the frame buffer
        write(fbctl, buf, len);
        while (1) 
        {
            // 3 = evtdev
            int nread = read(3, buf, sizeof(buf) - 1);
            if (nread <= 0) continue;
            buf[nread] = '\0';
            if (strcmp(buf, "mmap ok") == 0) break;
        }
        close(fbctl);
    }
    else
    {
        char screen_sizeinfo[23];
        read(open("/proc/dispinfo", 0, 0), screen_sizeinfo, sizeof(screen_sizeinfo));

        char *endw = screen_sizeinfo + 9;
        char *endh = screen_sizeinfo + 21;
        screen_w = (int)strtol(&screen_sizeinfo[7], &endw, 10);
        screen_h = (int)strtol(&screen_sizeinfo[19], &endh, 10);
        canvas_w = *w; canvas_h = *h;
        canvas_x = screen_w/2-canvas_w/2;
        canvas_y = screen_h/2-canvas_h/2;
        lseek(open("/dev/fb", 0, 0), 4*(canvas_y*screen_w + canvas_x), SEEK_SET);
    }
}

void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) 
{
    assert(pixels);
    assert(x>=0); assert(y>=0);
    assert(w<=screen_w); assert(h<=screen_h);
    int draw_x = x + canvas_x; int draw_y = y + canvas_y;

    /*lseek(open("/dev/fb", 0, 0), 4*(draw_y*screen_w+draw_x), SEEK_SET);*/
    /*write(open("/dev/fb", 0, 0), pixels, w*4*h);*/

    for(int i = 0; i < h; i++)
    {
        lseek(open("/dev/fb", 0, 0), 4*((draw_y+i)*screen_w+draw_x), SEEK_SET);
        write(open("/dev/fb", 0, 0), pixels+i*w, w*4);
    }

}

void NDL_OpenAudio(int freq, int channels, int samples) {
}

void NDL_CloseAudio() {
}

int NDL_PlayAudio(void *buf, int len) {
  return 0;
}

int NDL_QueryAudio() {
  return 0;
}

int NDL_Init(uint32_t flags) 
{
    if (getenv("NWM_APP")) 
    {
        evtdev = 3;
    }
    return 0;
}

void NDL_Quit() 
{
}