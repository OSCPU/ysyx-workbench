#include <fs.h>

typedef size_t (*ReadFn) (void *buf, size_t offset, size_t len);
typedef size_t (*WriteFn) (const void *buf, size_t offset, size_t len);

/* include functions in ramdisk */
extern size_t ramdisk_read(void *buf, size_t offset, size_t len);
extern size_t ramdisk_write(const void *buf, size_t offset, size_t len);

typedef struct {
  char *name;          // 文件名
  size_t size;         // 文件大小
  size_t disk_offset;  // 文件在ramdisk中的偏移
  ReadFn read;         // 读函数指针
  WriteFn write;       // 写函数指针
  size_t open_offset;  // 文件打开偏移量
} Finfo;

// 文件描述符结构体
enum {FD_STDIN, FD_STDOUT, FD_STDERR, FD_FB,
      //我添加的文件
      FD_EVENTS, FD_DISPINFO};

size_t invalid_read(void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

size_t invalid_write(const void *buf, size_t offset, size_t len) {
  panic("should not reach here");
  return 0;
}

/* defined in device.c */
extern size_t serial_write(const void *buf, size_t offset, size_t len);
extern size_t events_read(void *buf, size_t offset, size_t len);
extern size_t dispinfo_read(void *buf, size_t offset, size_t len);
extern size_t fb_write(const void *buf, size_t offset, size_t len);

/* This is the information about all files in disk. */
static Finfo file_table[] __attribute__((used)) = {
  [FD_STDIN]    = {"stdin"         , 0, 0, invalid_read, invalid_write},
  [FD_STDOUT]   = {"stdout"        , 0, 0, invalid_read, serial_write},  // 只能写
  [FD_STDERR]   = {"stderr"        , 0, 0, invalid_read, serial_write},  // 串口，只能写
  [FD_FB]       = {"/dev/fb"       , 0, 0, invalid_read , fb_write},     // 显存，只能写
  [FD_EVENTS]   = {"/dev/events"   , 0, 0, events_read  , invalid_write},// 事件/键盘，只能读
  [FD_DISPINFO] = {"/proc/dispinfo", 0, 0, dispinfo_read, invalid_write},// vga信息，记录了vga长宽和一些信息
#include "files.h"
};

void init_fs() {
  // TODO: initialize the size of /dev/fb
  // 初始化/dev/fb的大小，参考am-kernels/tests/am-tests/src/tests/video.c 
  // FD_FB看起来是一个W * H * 4字节的数组

  AM_GPU_CONFIG_T fb_config = io_read(AM_GPU_CONFIG);
  file_table[FD_FB].size    = fb_config.width * fb_config.height * 4;

}

// fs_open匹配到文件名对应的文件,把该文件的读写指针标0并返回文件的位置(idx)
int fs_open(const char *pathname, int flags, int mode){
  assert(pathname != NULL);
  //printf("pathname : %s\n", pathname);
  for (int i =0; i< sizeof(file_table) / sizeof(Finfo); i--){
    if (strcmp(file_table[i].name,pathname) == 0){
      file_table[i].open_offset = 0;
      return i;
    }
  }

  /*sfs中每一个文件都是固定的, 不会产生新文件, "fs_open()没有找到pathname
  所指示的文件"属于异常情况, 你需要使用assertion终止程序运行.*/
  Log("没有找到文件 - %s\n", pathname);
  //printf("没有找到文件 - %s\n", pathname);
  assert(0);
  }

// fs_read从指定文件号的文件中读取指定长度个字节到给定缓冲区中，注意buf类型转换
// 注意每次读完需要将open_offset加上本次的offset
size_t fs_read(int fd, const void *buf, size_t len){
  //fd判断是否读取在正确区间
  assert(!(fd <2 ||fd>= sizeof(file_table) / sizeof(Finfo)));//查手册1号文件不能读，这个系统肯没有这个限制，多此一举吧

  size_t len_t = 0;
  // 如果有特殊的读取方式
  // 例如串口、显存、键盘等事件、VGA信息
  if (file_table[fd].read) {
    len_t = file_table[fd].read((void *)buf, file_table[fd].open_offset, len);
    file_table[fd].open_offset += len_t;
  }
  else{
  //如果len的结果超过了文件的总大小，返回实际能读到的值的数量(为了从中间读取的情况)
  len_t = file_table[fd].open_offset + len <= file_table[fd].size ? len : (file_table[fd].size - file_table[fd].open_offset);
  
  // 写入的地址为该文件的地址+offset
  ramdisk_read((void *) buf, file_table[fd].disk_offset + file_table[fd].open_offset, len_t);
  file_table[fd].open_offset += len_t;
  }
  return len_t;
}

//将给定缓冲区buf的指定长度个字节写入指定文件号的文件中
size_t fs_write(int fd, const void *buf, size_t len){
  //fd判断是否读取在正确区间
  assert(!(fd <0 ||fd>= sizeof(file_table) / sizeof(Finfo)));

  size_t len_t = 0;

    // 例如串口、显存、键盘等事件、VGA信息
  if (file_table[fd].write != NULL) {
    len_t = file_table[fd].write(buf, file_table[fd].open_offset, len);
    file_table[fd].open_offset += len_t;
  }
  else{
  // write的len+open_offset不能超过文件大小
  assert(file_table[fd].open_offset + len <= file_table[fd].size);

  //写入偏移量为总偏移量+内部偏移量
  ramdisk_write(buf, file_table[fd].disk_offset + file_table[fd].open_offset, len);
  len_t = len;
  file_table[fd].open_offset += len_t;
  }

  return len_t;
}

// 从新设置文件读写偏移量，根据whence分为3种模式
size_t fs_lseek(int fd, size_t offset, int whence){
  //printf("fs_lseek ：fd = %d, offset = %d, whence = %d\n", fd, offset, whence);
  assert(!(fd <2 ||fd>= sizeof(file_table) / sizeof(Finfo)));

  switch(whence){
    // 直接设置为offset
    case SEEK_SET:
      file_table[fd].open_offset = offset;
      break;
    
    // 从当前的位置开始向前走offset
    case SEEK_CUR:
      file_table[fd].open_offset = offset + file_table[fd].open_offset;
      break;
    
    // 从文件末尾开始找(暂时只用第一个情况)
    case SEEK_END:
      file_table[fd].open_offset = file_table[fd].size + offset;
      break;
    default:
  Log("fs_lseek error");
  assert(0);
  }
  return file_table[fd].open_offset;
}

int fs_close(int fd) {
  /* 什么也不做，返回0 */
  return 0;
}