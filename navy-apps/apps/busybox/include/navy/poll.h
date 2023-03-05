
struct pollfd {
  int fd;
  short events;
  short revents;
};

#define POLLIN    0x0001
