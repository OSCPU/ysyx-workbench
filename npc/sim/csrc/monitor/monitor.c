#include "macro.h"
#include <common.h>
#include <cstddef>
#include <getopt.h>
#include <elf.h>

extern uint8_t imem[CONFIG_MSIZE];

void sdb_set_batch_mode();
void init_log(const char *log_file);
void init_elf(const char *elf_file);
void init_mem();
void init_sdb();
void init_difftest(char *ref_so_file, long img_size, int port);
void sim_init();
extern "C" void init_disasm(const char *triple);

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NPC!\n", ANSI_FMT("riscv32e", ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

static char *log_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static char *diff_so_file = NULL;
static int  difftest_port = 1234;
static uint32_t img[] = {
  0x80000,0x8002000,0x8051231,0x80006547
};

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return sizeof(img);
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(imem, size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"   , no_argument      , NULL, 'b'},
    {"log"     , required_argument, NULL, 'l'},
    {"diff"    , required_argument, NULL, 'd'},
    {"port"    , required_argument, NULL, 'p'},
    {"elf"     , required_argument, NULL, 'e'},
    {0         , 0                , NULL,  0 },
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bl:e:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'l': log_file = optarg; break;
      case 'e': elf_file = optarg; break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'd': diff_so_file = optarg; break;
      case 1:   img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {

  parse_args(argc, argv);

  init_log(log_file);

  long img_size = load_img();

  IFDEF(CONFIG_DIFFTEST, init_difftest(diff_so_file, img_size, difftest_port));

  init_mem();

	init_sdb();

  init_elf(elf_file);

  sim_init();

  init_disasm("riscv32-pc-linux-gnu");

  welcome();
}
