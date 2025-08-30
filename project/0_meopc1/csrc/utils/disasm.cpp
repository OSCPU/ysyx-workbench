#include <dlfcn.h>
#include <capstone/capstone.h>
#include "../include/common.h"

using cs_open_fn    = cs_err  (*)(cs_arch, cs_mode, csh *);
using cs_disasm_fn  = size_t  (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**);
using cs_free_fn    = void    (*)(cs_insn*, size_t);

static cs_open_fn   cs_open_dl   = nullptr;
static cs_disasm_fn cs_disasm_dl = nullptr;
static cs_free_fn   cs_free_dl   = nullptr;
static csh handle;

void init_disasm() {
  void *dl_handle;
  dl_handle = dlopen("tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  assert(dl_handle);

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  cs_open_dl = reinterpret_cast<cs_open_fn>(
    dlsym(dl_handle, "cs_open")
);
assert(cs_open_dl);

// 加载 cs_disasm
cs_disasm_dl = reinterpret_cast<cs_disasm_fn>(
    dlsym(dl_handle, "cs_disasm")
);
assert(cs_disasm_dl);

// 加载 cs_free （注意函数名）
cs_free_dl = reinterpret_cast<cs_free_fn>(
    dlsym(dl_handle, "cs_free")
);
assert(cs_free_dl);

  cs_arch arch = CS_ARCH_RISCV;
  cs_mode mode = CS_MODE_RISCV32;
	int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);

#ifdef CONFIG_ISA_x86
  cs_err (*cs_option_dl)(csh handle, cs_opt_type type, size_t value) = NULL;
  cs_option_dl = dlsym(dl_handle, "cs_option");
  assert(cs_option_dl);

  ret = cs_option_dl(handle, CS_OPT_SYNTAX, CS_OPT_SYNTAX_ATT);
  assert(ret == CS_ERR_OK);
#endif
}

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
	cs_insn *insn;
	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  assert(count == 1);
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0') {
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  cs_free_dl(insn, count);
}
