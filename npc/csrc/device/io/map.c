#include <common.h>

#define IO_SPACE_MAX (2 * 1024 * 1024)
#define PAGE_SHIFT        12
#define PAGE_SIZE         (1ul << PAGE_SHIFT)
#define PAGE_MASK         (PAGE_SIZE - 1)

static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    case 8: return *(uint64_t *)addr;
    default: assert(0);
  }
}

static inline void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    case 8: *(uint64_t *)addr = data; return;
    default: assert(0);
  }
}

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
static int check_bound(IOMap *map, paddr_t addr) {
  if (map == NULL) {
    return 0;
  }
  
  else if(addr <= map->high && addr >= map->low){
    //printf("timer-0x%016lx\n",addr);
    return 1;
  }
  //printf("timer-0x%016lx\n",addr);
  return 0;
}

// 回调函数的作用是模拟设备读写，更新相应状态
static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write) {
  if (c != NULL) { c(offset, len, is_write); }
}

// 开辟io映射的内存空间
void init_map() {
  io_space = (uint8_t*)malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

// 将地址addr映射到map指示的空间中并进行访问，访问时触发回调函数对设备和目标空间的状态进行更新，支持dtrace获取设备访问的踪迹
word_t map_read(paddr_t addr, int len, IOMap *map) {
  assert(len >= 1 && len <= 8);
  if(!check_bound(map, addr)){
    printf("[map_read ]地址越界%016lx pc=0x%016lx\n",addr,cpu_gpr[32]);
  }
  //printf("timer-0x%016lx\n",addr);
  paddr_t offset = addr - map->low;
  //printf("offset-0x%016lx\n",offset);
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read((uint8_t*)map->space + offset, len);
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map) {
  assert(len >= 1 && len <= 8);
  if(!check_bound(map, addr)){
  printf("[map_write]地址越界%016lx pc=0x%016lx\n",addr,cpu_gpr[32]);
  }
  paddr_t offset = addr - map->low;
  host_write((uint8_t*)map->space + offset, len, data);
  invoke_callback(map->callback, offset, len, true);
}
