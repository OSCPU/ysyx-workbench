#include <common.h>

#if defined(MULTIPROGRAM) && !defined(TIME_SHARING)
# define MULTIPROGRAM_YIELD() yield()
#else
# define MULTIPROGRAM_YIELD()
#endif

#define NAME(key) \
  [AM_KEY_##key] = #key,

static const char *keyname[256] __attribute__((used)) = {
  [AM_KEY_NONE] = "NONE",
  AM_KEYS(NAME)
};

size_t serial_write(const void *buf, size_t offset, size_t len) {
  //通过串口用putchar，由brk堆叠put出去
  for(size_t i = 0; i < len ; i++){
    putch(((char *)buf)[i]);
  }
  return len;
}

size_t events_read(void *buf, size_t offset, size_t len) {
  // 键盘设备必须得是有的，否则直接assert
  // 实际上ioe里面默认返回true，不实现键盘功能还能继续跑，只是没办法处理真的有物理键盘的输入
  
  // 读取键盘寄存器
  // AM_INPUT_KEYBRD_T 包含以下两个成员
  // bool keydown, int keycode
  // keycode为按键断码，无按键时默认为AM_KEY_NONE
  // keydown为按键状态，1为down，20up
  AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);

  // 无输入默认返回0
  if (ev.keycode == AM_KEY_NONE) return 0;

  // 检测到有输入
  // 键盘总共有kd和ku两种事件
  // 下面用于拼接并返回事件log
  // 学的是am-tests里的那一套输出格式
  // "kd/ku keyname"
  char *event_tag = ev.keydown ? "kd" : "ku";
  strcpy(buf, event_tag);
  strcat(buf, " ");
  strcat(buf, keyname[ev.keycode]);
  size_t size = 0;
  size = strlen(buf);
  //printf("[events_read] (kbd): %s (%d) %s\n", keyname[ev.keycode], ev.keycode, ev.keydown ? "DOWN" : "UP");
  return size;
}

// 将文件的len字节写到buf中(我们认为这个文件不支持lseek, 可忽略offset).
size_t dispinfo_read(void *buf, size_t offset, size_t len) {
  //获得am中画布的大小
  AM_GPU_CONFIG_T config = io_read(AM_GPU_CONFIG);
  int width  = config.width;
  int height = config.height;
  int ret = snprintf(buf, len, "WIDTH:%d\nHEIGHT:%d", width, height);
  return ret;
}

// 用于把buf中的len字节写到屏幕上offset处. 你需要先从offset计算出屏幕上的坐标, 
// 然后调用IOE来进行绘图,另外我们约定每次绘图后总是马上将frame buffer中的内容同步到屏幕上.
size_t fb_write(const void *buf, size_t offset, size_t len) {
  AM_GPU_CONFIG_T config = io_read(AM_GPU_CONFIG);
  int width = config.width;

  // 由于像素是32bit，所以offset，len（前两个是大小，需要变为像素数和长度），buf都要转换
  // 数据是按行优先存储的
  // 因此offset取余可以得到一行的第几个数据，offset整除可以得到是第几行

  offset /= sizeof(uint32_t);
  len /= sizeof(uint32_t);
  int x = offset % width;
  int y = offset / width;

  // buf 转为32bit的指针，毕竟是ARGB（调用IOE来进行绘图）
  io_write(AM_GPU_FBDRAW, x, y, (uint32_t *)buf, len, 1, true);

  return len;
}

void init_device() {
  Log("Initializing devices...");
  ioe_init();
}
