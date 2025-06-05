#include "include/monitor.h"

static char * img_file = NULL;
void init_mem(size_t size);
void test(){
  printf("11111\n");
  return ;
}

static long load_img() {
    if (img_file == NULL) {
      //Log("No image is given. Use the default build-in image.");
      printf("No image is given. Use the default build-in image.\n");
      return 4096; // built-in image size
    }
    FILE *fp = fopen(img_file, "rb");
    //Assert(fp, "Can not open '%s'", img_file);
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    //Log("The image is %s, size = %ld", img_file, size);
    fseek(fp, 0, SEEK_SET);
    int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
    //printf("!!!%x   %x@@@\n", guest_to_host(RESET_VECTOR)[0], guest_to_host(RESET_VECTOR)[1]);
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
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
    switch (o) {
    //   case 'b': sdb_set_batch_mode(); break;
    //   case 'p': sscanf(optarg, "%d", &difftest_port); break;
    //   case 'l': log_file = optarg; break;
    //   case 'e': elf_file = optarg; break;
    //   case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-e,--elf=FILE           output elf to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
    parse_args(argc, argv);
  
    // init_rand();
  
    // init_log(log_file);
  
    // init_elf(elf_file);
      
    init_mem(0x80000000);
  
    // init_isa();
  
    long img_size = load_img();
  
    // init_difftest(diff_so_file, img_size, difftest_port);
  
    // init_sdb();
  
    // IFDEF(CONFIG_ITRACE, init_disasm());
  
    // welcome();
  }
  