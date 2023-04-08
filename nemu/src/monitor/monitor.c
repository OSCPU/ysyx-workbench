#include <isa.h>
#include <memory/paddr.h>
#include <errno.h>
#include <elf.h>
#include <unistd.h>
#include "monitor.h"
void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm(const char *triple);
static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ASNI_FMT("ON", ASNI_FG_GREEN), ASNI_FMT("OFF", ASNI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ASNI_FMT(str(__GUEST_ISA__), ASNI_FG_YELLOW ASNI_BG_RED));
  printf("For help, type \"help\"\n");
//  Log("Exercise: Please remove me in the source code and compile NEMU again.");
//  assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>
#define CALL_OP 0
#define RET_OP 1

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;
static char *elf_file = NULL;
static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

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
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {"elf"      , required_argument, NULL, 'e'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'e': elf_file = optarg; break;
      case 1: img_file = optarg; return optind - 1;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-e,--elf=FILE           elf file to be parsed\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

word_t depth; // the depth of call
typedef struct Func
{
  char name[64];
  word_t start;
  word_t end;
  struct Func * next;
} Func;
Func * func_head = NULL;
char * opstr[] = {"call", "ret"};
int lastest_op = -1;
static char * ftrace_log_file = "ftrace-log.txt";
bool ftrace = false;
// function trace
// static void parse_elf()
// {
//   FILE *fp;
//   Elf32_Ehdr elf_header;
//   int readfile;

//   ftrace = true;

// // read the header
//   fp = fopen(elf_file, "rb");
  
//   Assert(fp, "fail to open file %s\n", elf_file);
  
//   readfile = fread(&elf_header,sizeof(Elf32_Ehdr),1,fp);
//   printf("readfile = %d\n", readfile);
//   Assert(readfile != 0, "fail to read header\n");
//   //Elf32_Off section_header_offset = elf_header.e_shoff;
//   // find the section table and read each section
//   printf("Start of section headers: 0x%x\n", elf_header.e_shoff);
//   fseek(fp, elf_header.e_shoff, SEEK_SET);

//   Elf32_Shdr shstrtab;
//   // read the Section header string table
//   fseek(fp, sizeof(Elf32_Shdr) * elf_header.e_shstrndx, SEEK_CUR);  // skip the section header
//   readfile = fread(&shstrtab, sizeof(Elf32_Shdr), 1, fp);
//   Assert(readfile != 0, "fail to read shstrtab\n");
//   fseek(fp, elf_header.e_shoff, SEEK_SET);
//   printf("Section header string table offset: 0x%x\n", shstrtab.sh_offset);

//   // find the strtab and symtab
//   Elf32_Shdr *strtab = NULL;
//   Elf32_Shdr *symtab = NULL;
//   Elf32_Shdr temp;
//   for (int i = 0; i < elf_header.e_shnum; i++)
//   {
//     // read a section
//     fseek(fp, sizeof(Elf32_Shdr) * i+shstrtab.sh_offset, SEEK_SET);
//     readfile = fread(&temp, sizeof(Elf32_Shdr), 1, fp);
//     Assert(readfile != 0, "fail to read section\n");
//     Log("readfile %d\n",elf_header.e_shnum);
//     if (temp.sh_type == SHT_SYMTAB)
//     {
//       symtab = (Elf32_Shdr *)malloc(sizeof(Elf32_Shdr));
//       Assert(symtab != NULL,"symtab no memory\n");
//       printf("In symtab offset: 0x%x\n", temp.sh_offset);
//       memcpy(symtab, &temp, sizeof(temp));
//     }
//     else if (temp.sh_type == SHT_STRTAB && i != elf_header.e_shstrndx)//
//     {
//       strtab = (Elf32_Shdr *)malloc(sizeof(Elf32_Shdr));
//       printf("strtab offset: 0x%x\n", temp.sh_offset);
//       Assert(strtab != NULL,"strtab no memory\n");
//       memcpy(strtab, &temp, sizeof(temp));
//     }
//     // judge its section name
//   }
//   assert(strtab != NULL);
//   assert(symtab != NULL);
  
//   printf("symbol table offset: 0x%x\n", symtab->sh_offset);
//   printf("string table offset: 0x%x\n", strtab->sh_offset);

//   // read symbol table and find func
//   Elf32_Sym symbol;
//   fseek(fp, symtab->sh_offset, SEEK_SET);
//   int entries = symtab->sh_size / symtab->sh_entsize;
//   // printf("entries: %d\n", entries);
//   long addr;
//   for (int i = 0; i < entries; i++)
//   {
//     readfile = fread(&symbol, sizeof(symbol), 1, fp);
//     Assert(readfile != 0, "fail to read symbol\n");
//     if ((symbol.st_info  & 0xf) == STT_FUNC)
//     {
//       // read the function name
//       Func *func = (Func *)malloc(sizeof(Func));
//       addr = ftell(fp);
//       fseek(fp, strtab->sh_offset + symbol.st_name, SEEK_SET);
//       int i = 0;
//       char ch;
//       while ((ch = fgetc(fp)) != '\0')
//         func->name[i++] = ch;
//       func->name[i] = '\0';
//       func->start = symbol.st_value;
//       func->end = func->start + symbol.st_size;
//       func->next = func_head;
//       func_head = func;
//       printf("func: %s; start: 0x%lx; end: 0x%lx\n", func->name, func->start, func->end);
//       fseek(fp, addr, SEEK_SET);
//     }
//   }
//   fclose(fp);
// }
typedef struct __FUNC_INFO{
    char func_name[64];
    paddr_t start;
    size_t size;
}FUNC_INFO;
static int end = 0;
static FUNC_INFO elf_funcs[1024];
static void read_from_file(FILE *elf, size_t offset, size_t size, void* dest){
    fseek(elf, offset, SEEK_SET);
    int flag = fread(dest, size, 1, elf);
    assert(flag == 1);
}

static void get_str_from_file(FILE *elf, size_t offset, size_t n, void* dest){
    fseek(elf, offset, SEEK_SET);
    char* flag = fgets(dest, n, elf);
    assert(flag != NULL);
}
static void append(char* func_name, paddr_t start, size_t size){
    strncpy(elf_funcs[end].func_name, func_name, sizeof(elf_funcs[0].func_name));
    elf_funcs[end].start = start;
    elf_funcs[end].size = size;
    end++;
}

void parse_elf(const char* elf_file, size_t global_offset){
    printf("Loading from %s\n", elf_file);
    FILE *elf = fopen(elf_file, "rb");
    assert(elf != NULL);
    Elf32_Ehdr elf_header;
    read_from_file(elf, global_offset + 0, sizeof elf_header, &elf_header);
    
    Elf32_Off section_header_offset = elf_header.e_shoff;
    size_t headers_entry_size = elf_header.e_shentsize;
    int headers_entry_num = elf_header.e_shnum;

    printf("====== Reading ELF File ======\n");
    printf("e_shoff: %d \n", section_header_offset);
    printf("e_shentsize: %ld\t e_shnum: %d \n", headers_entry_size, headers_entry_num);
    
    assert(sizeof(Elf32_Shdr) == headers_entry_size);
    
    // printf("====== Selection Headers ======\n");

    Elf32_Off symbol_table_offset = 0, string_table_offset = 0;
    size_t symbol_table_total_size = 0;
    //size_t string_table_total_size;
    size_t symbol_table_entry_size = 0;
    for (int i = 0; i < headers_entry_num; ++i){
        Elf32_Shdr section_entry;
        read_from_file(elf, global_offset + i * headers_entry_size + section_header_offset,
            headers_entry_size, &section_entry);
        switch(section_entry.sh_type){
            case SHT_SYMTAB:
                symbol_table_offset = section_entry.sh_offset;
                symbol_table_total_size = section_entry.sh_size;
                symbol_table_entry_size = section_entry.sh_entsize;
            break;

            case SHT_STRTAB:
                if (i == elf_header.e_shstrndx){}else{
                    string_table_offset = section_entry.sh_offset;
                    //string_table_total_size = section_entry.sh_size;
                }
            break;
        }
    }

    // printf("String Table Offset: %#x\n", string_table_offset);
    // printf("Symbol Table Offset: %#x\n", symbol_table_offset);
    
    char function_name[64];
    assert(symbol_table_entry_size == sizeof(Elf32_Sym));
    for (int i = 0; i < symbol_table_total_size / symbol_table_entry_size; ++i){
        Elf32_Sym symbol_section_entry;
        read_from_file(elf, global_offset + i * symbol_table_entry_size + symbol_table_offset, 
            symbol_table_entry_size, &symbol_section_entry);
        switch(ELF32_ST_TYPE(symbol_section_entry.st_info)){
            case STT_FUNC:
            get_str_from_file(elf, global_offset + string_table_offset + symbol_section_entry.st_name, 
                sizeof(function_name), function_name);
            append(function_name, symbol_section_entry.st_value, symbol_section_entry.st_size);  
            break;
        }
    }
    // printf("====== Symbol Table ======\n");
    // for (int i = 0; i < end; ++i){
    //     FUNC_INFO *info = &elf_funcs[i];
    //     printf("Func: %12s | Start: %#x | Size: %ld\n", info->func_name, 
    //         info->start, info->size);
    // }
}

static void ftrace_log(int op, word_t addr, word_t t_addr)
{
  if (!ftrace)
    return;
  // Func * p = func_head;
  FUNC_INFO * p =elf_funcs;
  char record[128];
  char blank[32];

  while (p)
  {
    if (t_addr >= p->start && t_addr < p->start + p->size)
      break;
    {
      // blank
      if (lastest_op == op)
      {
        if (op == CALL_OP)
          depth++;
        else
          depth--;
      }

      memset(blank, '\0', sizeof(blank));
      for (int i = 0; i < depth; i++)
        blank[i] = ' ';
      int i = 0;
      while(p->func_name[i] != '\0')
      {
        sprintf(record, "%c", p->func_name[i]);
      }
      sprintf(record, "0x%08lx: %s%s[@0x%lu]\n", addr, blank, opstr[op], t_addr);
      // log to the ftrace-log
      FILE * fp = fopen(ftrace_log_file, "a+");
      Assert(fp, "fail to open ftrace log file\n");Log("fail to open ftrace log file\n");
      fwrite(record, 1, strlen(record), fp);
      Assert(fclose(fp) == 0, "fail to close ftrace log file\n");
      lastest_op = op;

      return;
    }
    p ++;
  }
}

void log_call(word_t addr, word_t t_addr)
{
  ftrace_log(CALL_OP, addr, t_addr);
  printf("call: 0x%08lx; target: 0x%08lx)\n", addr, t_addr);
}

void log_ret(word_t addr, word_t t_addr)
{
  ftrace_log(RET_OP, addr, t_addr);
  printf("ret: 0x%08lx; target: 0x%08lx)\n", addr, t_addr);
}
void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */
  /* Parse arguments. */
  parse_args(argc, argv);
  /* Set random seed. */
  init_rand();
  /* elf */
  if (elf_file)
    parse_elf(elf_file,0);
  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();
  
  IFDEF(CONFIG_ITRACE, init_disasm(
    MUXDEF(CONFIG_ISA_x86,     "i686",
    MUXDEF(CONFIG_ISA_mips32,  "mipsel",
    MUXDEF(CONFIG_ISA_riscv32, "riscv32",
    MUXDEF(CONFIG_ISA_riscv64, "riscv64", "bad")))) "-pc-linux-gnu"
  ));

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
