#include "../local-include/reg.h"
#include <cpu/ifetch.h>
#include <isa-all-instr.h>

def_all_THelper();

static uint32_t get_instr(Decode *s) {
  return s->isa.instr.val;
}

// decode operand helper
#define def_DopHelper(name) \
  void concat(decode_op_, name) (Decode *s, Operand *op, word_t val, bool flag)

static inline def_DopHelper(i) {
  op->imm = val;
}

static inline def_DopHelper(r) {
  bool is_write = flag;
  static word_t zero_null = 0;
  op->preg = (is_write && val == 0) ? &zero_null : &gpr(val);
}

static inline def_DHelper(I) {
  decode_op_r(s, id_src1, s->isa.instr.i.rs1, false);
  decode_op_i(s, id_src2, (sword_t)s->isa.instr.i.simm11_0, false);
  decode_op_r(s, id_dest, s->isa.instr.i.rd, true);
}

static inline def_DHelper(R) {
  decode_op_r(s, id_src1, s->isa.instr.r.rs1, false);
  decode_op_r(s, id_src2, s->isa.instr.r.rs2, false);
  //decode_op_i(s, id_src2, (sword_t)s->isa.instr.r.simm11_0, false);
  decode_op_r(s, id_dest, s->isa.instr.r.rd, true);
}

static inline def_DHelper(U) {
  decode_op_i(s, id_src1, (sword_t)s->isa.instr.u.simm31_12 << 12, true);
  decode_op_r(s, id_dest, s->isa.instr.u.rd, true);
}

static inline def_DHelper(J){
  decode_op_i(s,id_src1, (sword_t)((s->isa.instr.j.simm20<<20) | (s->isa.instr.j.imm19_12<<12) | (s->isa.instr.j.imm11<<11)|(s->isa.instr.j.imm10_1<<1)),true);
  decode_op_r(s,id_dest, s->isa.instr.j.rd,true);
}

static inline def_DHelper(S) {
  decode_op_r(s, id_src1, s->isa.instr.s.rs1, false);
  sword_t simm = (s->isa.instr.s.simm11_5 << 5) | s->isa.instr.s.imm4_0;
  decode_op_i(s, id_src2, simm, false);
  decode_op_r(s, id_dest, s->isa.instr.s.rs2, false);
}

static inline def_DHelper(B) {
  decode_op_r(s, id_src1, s->isa.instr.b.rs1, false);
  sword_t simm = (s->isa.instr.b.simm10_5 << 5) | (s->isa.instr.b.imm4_1<<1) | (s->isa.instr.b.imm11<<11) |(s->isa.instr.b.imm12<<12);
  decode_op_i(s, id_src2, simm, false);
  decode_op_r(s, id_dest, s->isa.instr.b.rs2, false);
}
def_THelper(load) {
  //def_INSTR_TAB("??????? ????? ????? 011 ????? ????? ??", ld);
  def_INSTR_TAB("??????? ????? ????? 000 ????? ????? ??", lb);
  def_INSTR_TAB("??????? ????? ????? 001 ????? ????? ??", lh);
  def_INSTR_TAB("??????? ????? ????? 010 ????? ????? ??", lw);
  def_INSTR_TAB("??????? ????? ????? 100 ????? ????? ??", lbu);
  def_INSTR_TAB("??????? ????? ????? 101 ????? ????? ??", lhu);
  return EXEC_ID_inv;
}

def_THelper(store) {
  //def_INSTR_TAB("??????? ????? ????? 011 ????? ????? ??", sd);
  def_INSTR_TAB("??????? ????? ????? 000 ????? ????? ??", sb);
  def_INSTR_TAB("??????? ????? ????? 001 ????? ????? ??", sh);
  def_INSTR_TAB("??????? ????? ????? 010 ????? ????? ??", sw);
  return EXEC_ID_inv;
}

def_THelper(i_ty){
  def_INSTR_TAB("0000000 ????? ????? 001 ????? ????? ??", slli);
  def_INSTR_TAB("0000000 ????? ????? 101 ????? ????? ??", srli);
  def_INSTR_TAB("0100000 ????? ????? 101 ????? ????? ??", srai);
  def_INSTR_TAB("??????? ????? ????? 000 ????? ????? ??", addi);
  def_INSTR_TAB("??????? ????? ????? 010 ????? ????? ??", slti);
  def_INSTR_TAB("??????? ????? ????? 011 ????? ????? ??", sltiu);
  def_INSTR_TAB("??????? ????? ????? 100 ????? ????? ??", xori);
  def_INSTR_TAB("??????? ????? ????? 110 ????? ????? ??", ori);
  def_INSTR_TAB("??????? ????? ????? 111 ????? ????? ??", andi);
  return EXEC_ID_inv;
}

def_THelper(r_ty) {
  def_INSTR_TAB("0100000 ????? ????? 000 ????? ????? ??", sub);
  def_INSTR_TAB("0000000 ????? ????? 000 ????? ????? ??", add);
  def_INSTR_TAB("0000000 ????? ????? 001 ????? ????? ??", sll);
  def_INSTR_TAB("0000000 ????? ????? 010 ????? ????? ??", slt);
  def_INSTR_TAB("0000000 ????? ????? 011 ????? ????? ??", sltu);
  def_INSTR_TAB("0000000 ????? ????? 100 ????? ????? ??", xor);
  def_INSTR_TAB("0000000 ????? ????? 101 ????? ????? ??", srl);
  def_INSTR_TAB("0100000 ????? ????? 101 ????? ????? ??", sra);
  def_INSTR_TAB("0000000 ????? ????? 110 ????? ????? ??", or);
  def_INSTR_TAB("0000000 ????? ????? 111 ????? ????? ??", and);
  return EXEC_ID_inv;
}
def_THelper(jal){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", jal);
  return EXEC_ID_inv; 
}
def_THelper(jalr){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", jalr);
  return EXEC_ID_inv;
}
def_THelper(branch){
  def_INSTR_TAB("??????? ????? ????? 000 ????? ????? ??", beq);
  def_INSTR_TAB("??????? ????? ????? 001 ????? ????? ??", bne);
  def_INSTR_TAB("??????? ????? ????? 100 ????? ????? ??", blt);
  def_INSTR_TAB("??????? ????? ????? 101 ????? ????? ??", bge);
  def_INSTR_TAB("??????? ????? ????? 110 ????? ????? ??", bltu);
  def_INSTR_TAB("??????? ????? ????? 111 ????? ????? ??", bgeu);
  return EXEC_ID_inv;
}
def_THelper(lui) {
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", lui);
  return EXEC_ID_inv;
}

def_THelper(ecall){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", ecall);
  return EXEC_ID_inv; 
}

def_THelper(auipc){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", auipc);
  return EXEC_ID_inv; 
}

def_THelper(ebreak){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", ebreak);
  return EXEC_ID_inv; 
}

def_THelper(csrrw){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", csrrw);
  return EXEC_ID_inv; 
}

def_THelper(csrrs){
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", csrrs);
  return EXEC_ID_inv; 
}
def_THelper(auipc) {
  def_INSTR_TAB("??????? ????? ????? ??? ????? ????? ??", auipc);
  return EXEC_ID_inv;
}


def_THelper(main) {
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 00000 11", I     , load);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 01000 11", S     , store);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 00101 11", U     , auipc);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 01100 11", R     , r_ty);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 00100 11", I     , i_ty);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11000 11", J     , jal);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11001 11", J     , jalr);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11011 11", B     , branch);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 01101 11", U     , lui);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11100 11", I     , ecall);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11101 11", I     , ebreak);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11110 11", I     , csrrw);
  def_INSTR_IDTAB("??????? ????? ????? ??? ????? 11111 11", I     , csrrs);
  def_INSTR_TAB  ("??????? ????? ????? ??? ????? 11010 11",         nemu_trap);
  return table_inv(s);
};

int isa_fetch_decode(Decode *s) {
  s->isa.instr.val = instr_fetch(&s->snpc, 4);
  int idx = table_main(s);
  return idx;
}
