#include <proc.h>
#include <elf.h>
#include <common.h>
#include <debug.h>
#include <fs.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

#if defined(__ISA_AM_NATIVE__)
#define EXPECT_TYPE EM_X86_64
#elif defined(__ISA_X86__)
#define EXPECT_TYPE EM_386  // see /usr/include/elf.h to get the right type
#elif defined(__ISA_MIPS32__)
#define EXPECT_TYPE EM_MIPS_X
#elif defined(__ISA_RISCV32__) || defined(__ISA_RISCV64__)
#define EXPECT_TYPE EM_RISCV
#else
#error Unsupported ISA
#endif


/* include functions in ramdisk */
extern size_t ramdisk_read(void *buf, size_t offset, size_t len);
extern size_t ramdisk_write(const void *buf, size_t offset, size_t len);
extern size_t get_ramdisk_size();

static uintptr_t loader(PCB *pcb, const char *filename) {
  Log("Initializing loader...");
  //define elf head 
  Elf_Ehdr elf;

  //printf("filename : %s\n",filename);
  int fd =fs_open(filename,0,0);
  //printf("fd : %d\n",fd);//打印一下读的信息确认下

  // 从elf中读取elf头
  fs_read(fd, &elf, sizeof(elf));

  // 检查elf文件的魔数和机器类型(riscv64和native)
  assert(*(uint32_t *)elf.e_ident == 0x464c457f || *(uint32_t *)elf.e_ident == 0x7f454c46 );
  assert(elf.e_machine == EXPECT_TYPE);
  //printf("maigic : %x\n",*(uint32_t *)elf.e_ident);
  //printf("%d\n",EXPECT_TYPE);
  
  /*定义程序头表(数组)，通过program headers的偏移读入
  逐个遍历Type，找到Type为PT_LOAD的，然后读取，将其载入到指定内存中
  elf.e_phnum 程序头表表项的个数
  加载区间     [VirtAddr, VirtAddr + MemSiz)
  .bss清零区间 [VirtAddr + FileSiz, VirtAddr + MemSiz)
  在程序头表结构体中的表项中取
  */
  Elf_Phdr phdr;
  
  for (int i =0; i < elf.e_phnum; i++){
   //通过elf头的phoff找到phdr的初始偏移量
   //通过elf头的phentisize获得每一个数组的大小（偏移量）
   //遍历程序头部数组
   fs_lseek(fd, elf.e_phoff + i * elf.e_phentsize ,SEEK_SET);
   fs_read(fd,&phdr, sizeof(phdr));
   // phdr的type是PT_LOAD代表需要装载
   if(phdr.p_type == PT_LOAD){
    // 根据offset直接指定load的程序在elf中位置
    fs_lseek(fd, phdr.p_offset,SEEK_SET);
    //加载到虚拟内存地址指定的内存中
    fs_read(fd, (void *)phdr.p_vaddr, phdr.p_memsz);
    // filesz与memsz之间的空间清0，留给.bss之类的使用
    memset((void *)(phdr.p_vaddr + phdr.p_filesz),0,phdr.p_memsz - phdr.p_filesz);

   }
  }
  return (uintptr_t) elf.e_entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  // 加载到内存中并返回地址到entry中，地址通常是crt0的起始地址
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = 0x%p - \"%s\"", entry, filename);
  ((void(*)())entry) ();//包装成函数指针，执行测试用例
}

