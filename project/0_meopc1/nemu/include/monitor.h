#ifndef __MONITOR_H__
#define __MONITOR_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "memory.h"
#include "common.h"

static long load_img();
static int parse_args(int argc, char *argv[]);
void init_monitor(int argc, char *argv[]);
void test();
#endif