#include <dlfcn.h>
#include "../include/memory.h"
#include "../include/common.h"

struct CPU_state {
    int  gpr[REGNUM];
    word_t pc;
};

bool is_skip_diff = false;
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;
bool (*ref_difftest_skip)() = NULL;
void isa_reg_display();

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

#ifdef DIFFTEST

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref() {
  is_skip_ref = true;
  skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void init_difftest(char *ref_so_file, long img_size) {
  assert(ref_so_file != NULL);
  // printf("Loading .so from: %s\n", ref_so_file);
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  // printf("ERROR: %s\n", dlerror());
  assert(handle);

  ref_difftest_memcpy = (void(*)(paddr_t,void *,size_t,bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void(*)(void *,bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void(*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void(*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)() = (void(*)())dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_skip = (bool(*)())dlsym(handle, "difftest_skip");

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init();
  ref_difftest_memcpy(0x80000000, (void *)guest_to_host(0x80000000), img_size, DIFFTEST_TO_REF);
  
  CPU_state dut_r;
  dut_r.pc = 0x80000000;
  for(int i = 0;i < REGNUM;i++)
    dut_r.gpr[i] = reg_data[i];
  ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
}

bool static checkregs(struct CPU_state *ref_r){
    bool flag = true;
    int i;
    // if(ref_r -> pc != pc) flag = false;
    for(i = 0;i < REGNUM;i++){
        //printf("dut-%3s = %-#11x\n",regs[i],reg_data[i]);
      if(ref_r -> gpr[i] != reg_data[i])
        flag = false;
    }
    //printf("%d\n\n\n",flag);

    if(flag == false){
      printf("ref-pc=%x\n",ref_r -> pc);
      for(i = 0;i < REGNUM;i++){
      // if(ref_r -> gpr[i] >= 0x02000000){
          printf("ref-%3s = %-#11x",regs[i],ref_r -> gpr[i]);
          if(i % 3 == 0) printf("\n");
          // }
      // else{
      //     printf("ref-%3s = %-11d",regs[i],ref_r -> gpr[i]);
      //     if(i % 3 == 0) printf("\n");
      //     } 
      }
      printf("\n");
    }
    return flag;
}

void difftest_step() {
  if(ref_difftest_memcpy == NULL) return;
  CPU_state ref_r;
  //printf("difftest_step\n");
  ref_difftest_exec(1);

  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  is_skip_diff = ref_difftest_skip();
  if(is_skip_diff == true){
    is_skip_diff = false;
    int i;
    //get dut reg into CPU_state struct
    CPU_state dut_r;
    dut_r.pc = ref_r.pc;
    for(i = 0;i < REGNUM;i++)
      dut_r.gpr[i] = reg_data[i];
    //copy reg to ref to skip this inst
    ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
    return;
  }

  if(!checkregs(&ref_r)){
    isa_reg_display();
    assert(0);
  }
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif
