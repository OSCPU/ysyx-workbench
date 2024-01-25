#include <dlfcn.h>
#include <common.h>

void isa_reg_display();
char *isa_reg_val2str(int i);

#define __EXPORT __attribute__((visibility("default")))
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

// define extern glabal varibles
extern riscv32_CPU_state cpu;
extern uint8_t imem[CONFIG_MSIZE] PG_ALIGN;

// define functions from .so
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#ifdef CONFIG_DIFFTEST
// difftest apis
static bool difftest_check_reg(const char *name, vaddr_t pc, word_t ref, word_t dut) {
  if (ref != dut) {
    printf("%s\n",ANSI_FMT("Difftest Fail", ANSI_FG_RED));
    printf("NAME: %s",name);
    Log("%s is different after executing instruction at pc = " FMT_WORD
        ", right = " FMT_WORD ", wrong = " FMT_WORD ", diff = " FMT_WORD,
        name, pc, ref, dut, ref ^ dut);
    return false;
  }
  return true;
}

bool isa_difftest_checkregs(riscv32_CPU_state *ref_r, vaddr_t pc) {
  int i;

  // check gpr
  for (i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++) {
    if(!difftest_check_reg(isa_reg_val2str(i), pc,  ref_r->gpr[i], cpu.gpr[i])) return false;
  }

  // check pc
  if(!difftest_check_reg("pc", pc, ref_r->pc, cpu.npc)) return false;

  // check csr
  if(!difftest_check_reg("mtvec"  , pc, ref_r->csr.mtvec  , cpu.csr.mtvec))   return false;
  if(!difftest_check_reg("mepc"   , pc, ref_r->csr.mepc   , cpu.csr.mepc))    return false;
  if(!difftest_check_reg("mcause" , pc, ref_r->csr.mcause , cpu.csr.mcause))  return false;
  if(!difftest_check_reg("mstatus", pc, ref_r->csr.mstatus, cpu.csr.mstatus)) return false;

  return true;
}

void isa_difftest_attach() {
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t, void *, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(CONFIG_MBASE, imem, img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void checkregs(riscv32_CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref,pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc) {
  riscv32_CPU_state ref_r;

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif

