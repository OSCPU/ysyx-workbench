#include <cpu/decode.h>
#include "../local-include/rtl.h"
//f(ld) f(sd) 
#define INSTR_LIST(f) f(auipc) f(inv) f(nemu_trap) f(load) f(store) f(r_ty) f(i_ty) f(jal) f(jalr) f(branch) f(lui) f(ecall) f(ebreak) f(csrrw) f(csrrs)
// f(lb) f(lbu) f(lh) f(lhu) f(lw) f(sb) f(sh) f(sw)\
// f(addi) f(slli) f(slti) f(sltiu) f(xori) f(srli) f(srai) f(ori) f(andi)\
// f(add) f(sub) f(sll) f(slt) f(sltu) f(xor) f(srl) f(sra) f(or) f(and)\
// f(jal) f(jalr) f(beq) f(bne) f(blt) f(bge) f(bltu) f(bgeu) f(ecall) f(ebreak) f(lui) f(csrrw) f(csrrs)

// #define def_all_EXEC_ID() 
//   INSTR_LIST(def_EXEC_ID)

def_all_EXEC_ID();
