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

#include <isa.h>
#include <memory/paddr.h>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm(const char *triple);

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

#ifdef CONFIG_FTRACE
#include <elf.h>
#include "monitor.h"
char *elf_file =NULL;
int times=0;
int fun_num=0;
void elf_read(char *elf_file);
void elf_read_fun(char* elf_file);
void elf_read_strtab(char* elf_file);
/*
transfer to momitor.h
typedef struct function
{
	uint32_t value;
	int      size;
	char     name[128];
}FUN;

*/
FUN fun_buff[128];

#endif
void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

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
    {"batch"    , /*no_argument*/ required_argument     , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
    switch (o) {
      case 'b':
		log_file = optarg; 
      		sdb_set_batch_mode();
		break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1:
      		#ifdef CONFIG_FTRACE
		if(times==0){
		elf_file = optarg;	
		times++;
		printf("----%s\n",elf_file);
		break;
		}
		#endif
      		img_file = optarg;
		printf("-0-%s\n",img_file);
		return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);

  /* Set random seed. */
  init_rand();

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

#ifndef CONFIG_ISA_loongarch32r
  IFDEF(CONFIG_ITRACE, init_disasm(
    MUXDEF(CONFIG_ISA_x86,     "i686",
    MUXDEF(CONFIG_ISA_mips32,  "mipsel",
    MUXDEF(CONFIG_ISA_riscv,
      MUXDEF(CONFIG_RV64,      "riscv64",
                               "riscv32"),
                               "bad"))) "-pc-linux-gnu"
  ));
#endif

  /* Display welcome message. */
  welcome();
  #ifdef CONFIG_FTRACE
  elf_read(elf_file);
  #endif



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

#ifdef CONFIG_FTRACE
void elf_read(char *elf_file)
{
	//elf_read_strtab(elf_file);
	elf_read_fun(elf_file);
}
void elf_read_strtab(char *elf_file) {
	FILE* fp;
	Elf32_Ehdr elf_header;
	fp=fopen(elf_file,"r");
	if(fp==NULL)   exit(0);
	int ret=fread(&elf_header,sizeof(Elf32_Ehdr),1,fp);
	assert(ret==1);
	if(elf_header.e_ident[0] !=0x7f||elf_header.e_ident[1]!='E')  {printf("no elf file\n");exit(0);} 
	
	Elf32_Shdr* sec_headers=(Elf32_Shdr*)malloc(sizeof(Elf32_Shdr)*elf_header.e_shnum);
	fseek(fp,elf_header.e_shoff,SEEK_SET);
	int ret1=fread(sec_headers,sizeof(Elf32_Shdr)*elf_header.e_shnum,1,fp);
	assert(ret1==1);
	printf("There are %d section headers, starting at offset 0x%x\n\n", elf_header.e_shnum, elf_header.e_shoff);

	int str_tab_ind=elf_header.e_shstrndx;
	fseek(fp,sec_headers[str_tab_ind].sh_offset,SEEK_SET);
	char* string_table = (char*)malloc(sec_headers[str_tab_ind].sh_size * sizeof(char));
	int ret2=fread(string_table,sec_headers[str_tab_ind].sh_size,1,fp);
	assert(ret2==1);

	/*printf("  [Nr]\tName\t\t\tType\t\tAddr\t\tOffset\t\tSize\t\t"
           "EntSize\t\tLink\tInfo\tAlign\n");*/
    //遍历section_headers段表里的每个section,输出相应的信息
    for (int i = 0; i < elf_header.e_shnum; i++) {
    	if(sec_headers[i].sh_type==SHT_STRTAB)
	{
        printf("  [%2d]\t", i);
        printf("%-24s", &string_table[sec_headers[i].sh_name]);
        printf("STRTAB          ");
        printf("0x%08x\t", sec_headers[i].sh_addr);
        printf("0x%08x\t", sec_headers[i].sh_offset);
        printf("0x%08x\t", sec_headers[i].sh_size);
        printf("0x%08x\t", sec_headers[i].sh_entsize);
        printf("%-8d", sec_headers[i].sh_link);
        printf("%-8d", sec_headers[i].sh_info);
        printf("%-8d", sec_headers[i].sh_addralign);
        printf("\n");
	}
    }

    //释放堆内存
    free (string_table);
    free (sec_headers);
    fclose(fp);	



}
void elf_read_fun(char *elf_file) {
	FILE* fp;
	Elf32_Ehdr elf_header;
	fp=fopen(elf_file,"r");
	if(fp==NULL)   exit(0);
	int ret=fread(&elf_header,sizeof(Elf32_Ehdr),1,fp);
	assert(ret==1);
	if(elf_header.e_ident[0] !=0x7f||elf_header.e_ident[1]!='E')  {printf("no elf file\n");exit(0);} 
	
	Elf32_Shdr* sec_headers=(Elf32_Shdr*)malloc(sizeof(Elf32_Shdr)*elf_header.e_shnum);
	fseek(fp,elf_header.e_shoff,SEEK_SET);
	int ret1=fread(sec_headers,sizeof(Elf32_Shdr)*elf_header.e_shnum,1,fp);
	assert(ret1==1);
	//printf("There are %d section headers, starting at offset 0x%x\n\n", elf_header.e_shnum, elf_header.e_shoff);

	int str_tab_ind=elf_header.e_shstrndx;
	fseek(fp,sec_headers[str_tab_ind].sh_offset,SEEK_SET);
	char* string_table = (char*)malloc(sec_headers[str_tab_ind].sh_size * sizeof(char));
	int ret2=fread(string_table,sec_headers[str_tab_ind].sh_size,1,fp);
	assert(ret2==1);

	int dynsym_ind = -1;//默认.dynsym符号表索引为-1
    	int symtab_ind = -1;//默认.symtab符号表索引为-1
    	int dynstr_ind = -1;//默认.dynstr字符串表索引为-1
    	int strtab_ind = -1;//默认.strtab字符串索引为-1

    //遍历段表section_headers获取符号表.dynsym;.symtab;.dynstr;.strtab四张表在段表中的索引
    	for (int i = 0; i < elf_header.e_shnum; i++) {
        	if (sec_headers[i].sh_type == SHT_DYNSYM)//是.dynsym符号表
            		dynsym_ind = i;
        	else if (sec_headers[i].sh_type == SHT_SYMTAB)//是.symtab符号表
            		symtab_ind = i;
        	if (strcmp(&string_table[sec_headers[i].sh_name], ".strtab") == 0)//是.strtab字符串表
            		strtab_ind = i;
        	else if (strcmp(&string_table[sec_headers[i].sh_name], ".dynstr") == 0)//是.dynstr字符串表
            		dynstr_ind = i;
    }

	
	


	if((dynsym_ind!=-1)&&(dynstr_ind !=-1))
	{
		 unsigned long entry_num = sec_headers[dynsym_ind].sh_size / sec_headers[dynsym_ind].sh_entsize;
        	 //printf("Symbol table '.dynsym' contains %ld entries\n", entry_num);
		 fseek(fp, sec_headers[dynstr_ind].sh_offset, SEEK_SET);
		 char* dynstr_string_table=(char*)malloc(sec_headers[str_tab_ind].sh_size * sizeof(char));
		 int ret4=fread(dynstr_string_table, sec_headers[dynstr_ind].sh_size,1, fp);
		 assert(ret4==1);


	fseek(fp, sec_headers[dynsym_ind].sh_offset, SEEK_SET);//将指针移动到符号表对应的偏移地址

        Elf32_Sym* sym_entries = (Elf32_Sym*)malloc(sizeof(Elf32_Sym)*entry_num);//开辟堆内存用来存储符号表中所有entry
        int ret3=fread(sym_entries, sizeof(Elf64_Sym)*entry_num,1, fp);//读符号表
	assert(ret3==1);


	//printf("  NUM:\tValue\t\tSize\tType\tName\n");

	for(int i=0;i<entry_num;i++)
	{
	   if((sym_entries[i].st_info & 0x0000000f)==STT_FUNC)
	   {
	   /*
 	    printf("  %3d:\t", i);
            printf("0x%08x:\t", sym_entries[i].st_value);
            printf("%4d\t", sym_entries[i].st_size);
	    printf("FUN\t");
            printf("%s", &dynstr_string_table[sym_entries[i].st_name]);
            printf("\n");
	    */
	    fun_buff[fun_num].value=sym_entries[i].st_value;
	    fun_buff[fun_num].size=sym_entries[i].st_size;
	    strcpy(fun_buff[fun_num].name,&dynstr_string_table[sym_entries[i].st_name]);
	   }
	}

    free (sym_entries);

    free (dynstr_string_table);
	}
	else{printf("NO Dynamic linker symbol table!\n");}
	printf("\n");


	if ((symtab_ind != -1) && (strtab_ind != -1)) {
        unsigned long entry_num = sec_headers[symtab_ind].sh_size / sec_headers[symtab_ind].sh_entsize;
        //printf("Symbol table '.symtab' contains %ld entries\n", entry_num);
        fseek(fp, sec_headers[strtab_ind].sh_offset, SEEK_SET);
        char* strtab_string_table = (char*)malloc(sec_headers[str_tab_ind].sh_size * sizeof(char));
        int ret5=fread(strtab_string_table, sec_headers[strtab_ind].sh_size,1, fp);
	assert(ret5==1);


	fseek(fp, sec_headers[symtab_ind].sh_offset, SEEK_SET);//将指针移动到符号表对应的偏移地址

        Elf32_Sym* sym_entries = (Elf32_Sym*)malloc(sizeof(Elf32_Sym)*entry_num);//开辟堆内存用来存储符号表中所有entry
        int ret3=fread(sym_entries, sizeof(Elf64_Sym)*entry_num,1, fp);//读符号表
	assert(ret3==1);


	//printf("  NUM:\tValue\t\tSize\tType\tName\n");

	for(int i=0;i<entry_num;i++)
	{
	   if((sym_entries[i].st_info & 0x0000000f)==STT_FUNC)
	   {
	   /*
 	    printf("  %3d:\t", i);
            printf("0x%08x:\t", sym_entries[i].st_value);
            printf("%4d\t", sym_entries[i].st_size);
	    printf("FUN\t");
            printf("%s", &strtab_string_table[sym_entries[i].st_name]);
            printf("\n");
	    */
	    fun_buff[fun_num].value=sym_entries[i].st_value;
	    fun_buff[fun_num].size=sym_entries[i].st_size;
	    strcpy(fun_buff[fun_num].name,&strtab_string_table[sym_entries[i].st_name]);

	    fun_num++;
	    }
	}
	/*   print the fun_buff
	for(int i=0;i<fun_num;i++)
	{
		printf("0x%08x:\t",fun_buff[i].value);
		printf("%4d\t",fun_buff[i].size);
		printf("%s",fun_buff[i].name);
		printf("\n");
	}
	*/

    free (sym_entries);

	free(strtab_string_table);
    } else {
        printf("No symbol table!\n");
    }

    //释放堆内存
    free (string_table);
    free (sec_headers);
    fclose(fp);	



}
#endif
