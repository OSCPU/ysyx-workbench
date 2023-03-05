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
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

#ifdef CONFIG_IRINGBUF
int ringptr = 15;
char ringbuf[16][128];
#endif

#ifdef CONFIG_WATCHPOINT
bool watchpoints_check();
#endif

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
    if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
    if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
    IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT
    if (watchpoints_check() == true) {
		nemu_state.state = NEMU_STOP;
		printf("Watchpoint(s) changed.\n");
	}
#endif
}

static void exec_once(Decode *s, vaddr_t pc) {
    s->pc = pc;
    s->snpc = pc;
    isa_exec_once(s);
    cpu.pc = s->dnpc;
// 写入itrace当前的pc，ints，反汇编信息
#ifdef CONFIG_ITRACE
    char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = 0; i < ilen; i ++) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#endif
#ifdef CONFIG_IRINGBUF
	ringptr = (ringptr + 1) % 16;
	strcpy(ringbuf[ringptr], s->logbuf);
    char *f = ringbuf[ringptr];
  f += snprintf(f, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  for (i = 0; i < ilen; i ++) {
    f += snprintf(f, 4, " %02x", inst[i]);
  }
  memset(f, ' ', space_len);
  f += space_len;
  disassemble(f, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#endif

}

// 通过n来决定执行几次，-1为run，每一次都写入相应的信息进入itrace，，diff一次，判断状态，更新vga设备
static void execute(uint64_t n) {
    Decode s;
    for (;n > 0; n --) {
        exec_once(&s, cpu.pc);// 执行一次
        g_nr_guest_inst ++;   // 记录执行一条指令
        trace_and_difftest(&s, cpu.pc);// diff执行一次
        if (nemu_state.state != NEMU_RUNNING) break;// 错误状态退出循环
        IFDEF(CONFIG_DEVICE, device_update());// 更新设备
    }
}

static void statistic() {
    IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
    Log("host time spent = " NUMBERIC_FMT " us", g_timer);
    Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
    if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
    else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
    isa_reg_display();
    statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
    // 如果传入n大于10条就不逐行打印
    g_print_step = (n < MAX_INST_TO_PRINT);
    switch (nemu_state.state) {
        case NEMU_END: case NEMU_ABORT:
            printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
            return;
        default: nemu_state.state = NEMU_RUNNING;
    }

    uint64_t timer_start = get_time();

    execute(n);

    uint64_t timer_end = get_time();
    g_timer += timer_end - timer_start;

    // for trace test
    // nemu_state.state = NEMU_ABORT;

    switch (nemu_state.state) {
        case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

        case NEMU_ABORT:
#ifdef CONFIG_IRINGBUF
            printf("========== IRingBuf Result ==========\n");
			for (int i = 0; i < 16; ++i) {
				if (i == ringptr) printf("--->");
				else printf("    ");
				printf("%s\n", ringbuf[i]);
			}
			printf("\n");
#endif
#ifdef CONFIG_MTRACE
      void print_mtrace();
      print_mtrace();
#endif
        case NEMU_END:
            Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
            nemu_state.halt_pc);
            // fall through
        case NEMU_QUIT: statistic();
    }
}