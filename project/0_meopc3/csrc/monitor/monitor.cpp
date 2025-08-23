#include "../include/memory.h"
#include "../include/common.h"

void init_elf(const char *elf_file);
void init_mem(size_t size);
void init_log(const char *log_file);
void init_difftest(char *ref_so_file, long img_size);
static char *log_file = NULL;
static char* img_file = NULL;
static char *elf_file = NULL;
static char *diff_so_file = NULL;
void init_disasm();
long load_img() {
    if (img_file == NULL) {
      //Log("No image is given. Use the default build-in image.");
      printf("No image is given. Use the default build-in image.\n");
      return 4096; // built-in image size
    }
    FILE *fp = fopen(img_file, "rb");
    //Assert(fp, "Can not open '%s'", img_file);
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    Log("The image is %s, size = %ld", img_file, size);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
    assert(ret == 1);
    fclose(fp);
    return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"elf"      , required_argument, NULL, 'e'},
    {"diff"     , required_argument, NULL, 'd'},
    // {"port"     , required_argument, NULL, 'p'},
    // {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , 0,  0 }
  };
  int o;
  while ((o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
    //printf("o = %d\n", o);
    switch (o) {
    case 'b': printf("~~~~batch mode\n"); break;
    //   case 'b': sdb_set_batch_mode(); break;
    //   case 'p': sscanf(optarg, "%d", &difftest_port); break;
    case 'l': log_file = optarg; break;
    case 'e': elf_file = optarg; 
              printf("ELF file: %s\n", elf_file); // Just for debugging
              break;
    case 'd': diff_so_file = optarg; printf("DIFF file: %s\n", diff_so_file); break;
    case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-e,--elf=FILE           output elf to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        // printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
    //printf("111\n");
    // printf("argc = %d\n", argc);
    // for(int i = 0; i < argc; i++){
    //     printf("argv[%d] = %s\n", i, argv[i]);
    // }
    parse_args(argc, argv);
    
    // init_rand();
    init_log(log_file);

    if(FTRACE)
        init_elf(elf_file);

    init_mem(0x8000000);
    // init_isa();
    long img_size = load_img();
    // for(int i = 0; i < img_size; i++){
    //     printf("guest_to_host(RESET_VECTOR)[%d] = %x\n", i, guest_to_host(RESET_VECTOR)[i]);
    // }
    init_difftest(diff_so_file, img_size);
    // init_sdb();
    IFDEF(ITRACE, init_disasm());
    // init_disasm();
    // welcome();
    return;
  }
  