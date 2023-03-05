#ifndef LIB_NAVY_H
#define LIB_NAVY_H 1

#include <stdint.h>
#include <unistd.h>

// asm-generic/termios.h
#define TIOCGWINSZ    0x5413
struct winsize {
	unsigned short ws_row;
	unsigned short ws_col;
	unsigned short ws_xpixel;
	unsigned short ws_ypixel;
};

// errno.h
#define __errno_location __errno

// signal.h
#define SA_RESTART  0x10000000

#endif
