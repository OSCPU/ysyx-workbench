typedef uint32_t socklen_t;
typedef unsigned short int sa_family_t;

typedef uint32_t in_addr_t;
struct in_addr { in_addr_t s_addr; };

typedef uint16_t in_port_t;

struct sockaddr_in {
  sa_family_t sin_family;
  in_port_t sin_port;
  struct in_addr sin_addr;
};

struct sockaddr {
  sa_family_t sa_family;
  char sa_data[14];
};

typedef unsigned long int nfds_t;

extern int h_errno;
