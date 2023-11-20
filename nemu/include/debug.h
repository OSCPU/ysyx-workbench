/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <common.h>
#include <stdio.h>
#include <utils.h>

#define Log(format, ...) \
    _Log( format "\n",  ## __VA_ARGS__)

#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      MUXDEF(CONFIG_TARGET_AM, printf(ANSI_FMT(format, ANSI_FG_RED) "\n", ## __VA_ARGS__), \
        (fflush(stdout), fprintf(stderr, ANSI_FMT(format, ANSI_FG_RED) "\n", ##  __VA_ARGS__))); \
      IFNDEF(CONFIG_TARGET_AM, extern FILE* log_fp; fflush(log_fp)); \
      extern void assert_fail_msg(); \
      assert_fail_msg(); \
      assert(cond); \
    } \
  } while (0)

#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

#define TODO() panic("please implement me")


#ifdef CONFIG_CC_DEBUG
#define  DEBUG_LOG(format ,...) \
    _Log("[%s:%d %s] " ANSI_FMT( "[DEBUG]" , ANSI_BG_YELLOW) " "  format "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)
#else
#define  DEBUG_LOG(format ,...)
#endif

#define ERROR_LOG(format , ...) \
    _Log("[%s:%d %s] " ANSI_FMT( "[ERROR]" , ANSI_FG_RED) " "  format "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

#define INFO_LOG(format , ...) \
    _Log("[%s:%d %s] " ANSI_FMT( "[INFO]" , ANSI_FG_BLUE) " "  format "\n", \
        __FILE__, __LINE__, __func__, ## __VA_ARGS__)

// #define CHECK_LOG

#endif
