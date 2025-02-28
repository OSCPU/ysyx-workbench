#ifndef MONITOR_H
#define MONITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <isa.h>
#include <memory/paddr.h>
#include <getopt.h>
#include <elf.h>

// Function Declarations
void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();
void welcome();
void parse_elf(const char *elf_file);
void sdb_set_batch_mode();
long load_img();
int parse_args(int argc, char *argv[]);
void init_monitor(int argc, char *argv[]);
void am_init_monitor();

// Symbol Structure
 typedef struct {
    char name[64];  // Function name
    paddr_t addr;   // Function head address
    Elf32_Xword size;  // Function size
} Symbol;
extern Symbol *symbol ;
//extern Symbol *symbol;  // Dynamic allocation of symbols
extern  int func_num;  // Function number (index for symbols)

extern const char *elf_file;  // ELF file path
extern char *log_file;  // Log file path
extern char *diff_so_file;  // Diff test reference file path
extern char *img_file;  // Image file path
extern int difftest_port;  // Difftest port number

#endif // MONITOR_H

