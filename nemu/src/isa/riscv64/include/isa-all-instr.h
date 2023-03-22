#include <cpu/decode.h>
#include "../local-include/rtl.h"
//f(ld) f(sd) f(branch)
#define INSTR_LIST(f)  f(inv) f(nemu_trap) f(addi) f(slli) f(slti) f(sltiu)\
 f(xori) f(srli) f(srai) f(ori) f(andi)\
f(add) f(sub) f(sll) f(slt) f(sltu) f(xor) f(srl) f(sra) f(or) f(and)\
f(beq) f(bne) f(blt) f(bge) f(bltu) f(bgeu) f(auipc)
//f(csrrw) f(csrrs)
//f(lb) f(lbu) f(lh) f(lhu) f(lw) f(sb) f(sh) f(sw)

def_all_EXEC_ID();
