#include <isa.h>
#include <memory/host.h>
#include <memory/vaddr.h>
#include <device/map.h>

#define IO_SPACE_MAX (2 * 1024 * 1024)

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

uint8_t* new_space(int size) {
  // p_space代表io内存的末尾地址，也是下一次分配的启始地址，这里是对已经分配好的内存从头进行划分
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}
// 检查map的地址是否在io映射内，assert掉内存映射的情况
static void check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
        "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, map->name, map->low, map->high, cpu.pc);
  }
}

// 回调函数的作用是模拟设备读写，更新相应状态
static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

// 开辟io映射的内存空间
void init_map() {
  io_space = malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}
// 将地址addr映射到map指示的空间中并进行访问，访问时触发回调函数对设备和目标空间的状态进行更新，支持dtrace获取设备访问的踪迹
word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read(map->space + offset, len);
#ifdef CONFIG_DTRACE_COND
  printf("read: addr:%016x len:%02d name=%s content:%016lx \n",addr,len,map->name,ret);
#endif
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write(map->space + offset, len, data);
#ifdef CONFIG_DTRACE_COND
  printf("write:addr:%016x len:%02d name=%s content:%016lx \n",addr,len,map->name,data);
#endif
  invoke_callback(map->callback, offset, len, true);
}
