#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>// 时间库
#include <fcntl.h>   // 打开描述符权限库
#include <assert.h>

static int evtdev = -1;
static int fbdev = -1;

static int screen_w = 0, screen_h = 0;// 屏幕大小的vga
static int canvas_w = 0, canvas_h = 0;// 需要的vga

// NDL库的实现是使用linux库来实现的

// 以毫秒为单位返回系统时间s*1000加us*1000
static uint32_t boot_time = 0;
static uint32_t get_time_internal() {
  struct timeval now;
  gettimeofday(&now, NULL);
  uint32_t us = now.tv_sec * 1000 + now.tv_usec / 1000;
  return us;
}
uint32_t NDL_GetTicks() {
  if (boot_time == 0) boot_time = get_time_internal();
  uint32_t now = get_time_internal();
  return now - boot_time;;
}

// 读出一条事件信息, 将其写入`buf`中, 最长写入`len`字节 
// 返回读取的字节数（随便返的）
/* 用fopen()还是open()?
键入按键的字节序列是"流动"的, 被读出之后就不存在了, 它们没有"位置"的概念. 
属于后者的文件则不支持lseek操作, 相应的设备称为"字符设备"，
说明我们需要让数据直接被“读出”，也就是读函数中交互过程能直接把数据传送到我们需要的地方。
********
其实调用fopen最后也是会通过open实现的。但在这里打开的是设备文件，应该用open比较好
open的实现是具有缓冲区的，！！！这系列的读写操作实际上是对FILE里面的缓冲区进行操作的，！！！
而我们的设备文件需要直接把我们需要的buf打印。
*/
int NDL_PollEvent(char *buf, int len) {
  int fp = 0, ret = 0;
  // 打开事件文件，使用系统函数时候使用只读权限 O_RDONLY
  fp = open("/dev/events", O_RDONLY);
  if(fp == -1){
    printf("[NDL_PollEvent] 读取按键事件失败\n");
    assert(0);
  }
  //printf("%d",fp);
  //printf("%d",sizeof(char) * len);
  // len表示最多读取的字符数，文本的内容是char型的
  ret = read(fp, buf, sizeof(char) * len);
  close(fp);

  return ret;
}

// 打开一张(*w) X (*h)的画布
// 如果*w和*h均为0, 则将系统全屏幕作为画布, 并将*w和*h分别设为系统屏幕的大小
void NDL_OpenCanvas(int *w, int *h) {
  // 申请画布需要小于等于screen，否者会无法正确写入
  printf("[NDL_OpenCanvas] Require screen at least %dx%d.\n", *w, *h);
  assert((*w <= screen_w) || (*h <= screen_h));

  if (*w == 0) *w = screen_w;//全屏幕投射
  if (*h == 0) *h = screen_h;
  
  // 实际投射出的canvas的大小
  canvas_w = *w;
  canvas_h = *h;

/*
  if (getenv("NWM_APP")) {
    int fbctl = 4;
    fbdev = 5;
    screen_w = *w; screen_h = *h;
    char buf[64];
    int len = sprintf(buf, "%d %d", screen_w, screen_h);
    // let NWM resize the window and create the frame buffer
    write(fbctl, buf, len);
    while (1) {
      // 3 = evtdev
      int nread = read(3, buf, sizeof(buf) - 1);
      if (nread <= 0) continue;
      buf[nread] = '\0';
      if (strcmp(buf, "mmap ok") == 0) break;
    }
    close(fbctl);
  }
*/

  printf("[NDL_OpenCanvas] canvas_w = %d, canvas_h = %d\n", canvas_w, canvas_h);
}

// 向画布`(x, y)`坐标处绘制`w*h`的矩形图像, 并将该绘制区域同步到屏幕上
// 图像像素按行优先方式存储在`pixels`中, 每个像素用32位整数以`00RRGGBB`的方式描述颜色
/*    screen_w= 16
    xxxxxxxxxxxxxxxx

       xxxxxxxxxx    canvas_w =10
       xxxxxxxxxx    中间是显示的图像最外一圈是实际屏幕大小，要剧中就俩相减法/2就可
       xxxxxxxxxx 

    xxxxxxxxxxxxxxxx
*/
void NDL_DrawRect(uint32_t *pixels, int x, int y, int w, int h) {
  // 显存只能写，读不出来东西，会assert
  int fd = open("/dev/fb", O_WRONLY);

  // 向系统申请的画布尺寸和硬件的尺寸不一定一致，相减/2后到达每一行的开头，他是依照中心线对称。
  x += (screen_w - canvas_w) / 2;
  y += (screen_h - canvas_h) / 2;

  for (int i = 0; i < h; ++ i) {
    // 更改offset到每一列的开头
    lseek(fd, ((y + i) * screen_w + x) * sizeof(uint32_t), SEEK_SET);
    // 写入一行的图像
    write(fd, pixels + i * w, w * sizeof(uint32_t));
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

// 不能用fopen在native环境下会报错找不到
int NDL_Init(uint32_t flags) {
  printf("[NDL_Init] initiating...\n");
  if (getenv("NWM_APP")) {
    evtdev = 3;
  }

  // 读取出屏幕初始化大小，为申请绘图提出方便
  int fd = open("/proc/dispinfo",O_RDONLY);
  char buf[128];

  if(read(fd,buf,sizeof(buf)) ==-1){
    printf("[NDL_Init] open /proc/dispinfo  fail\n");
    assert(0);
  }
  else {
  close(fd);
  sscanf(buf, "WIDTH:%d\nHEIGHT:%d", &screen_w, &screen_h);
  printf("[NDL_Init] screen_w = %d, screen_h = %d\n", screen_w, screen_h);
  }

  return 0;
}

void NDL_Quit() {
  return ;
}
