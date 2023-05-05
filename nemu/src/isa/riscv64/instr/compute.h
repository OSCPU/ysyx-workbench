
def_EHelper(auipc) {
  rtl_li(s, ddest, id_src1->imm + s->pc);
}
def_EHelper(lui) {
  rtl_li(s, ddest, id_src1->imm);
}

def_EHelper(andi) {
  rtl_andi(s, ddest, dsrc1, id_src2->imm);
}

def_EHelper(addi) {
  rtl_addi(s, ddest, dsrc1, id_src2->imm);
}

def_EHelper(xori) {
  rtl_xori(s, ddest, dsrc1, id_src2->imm);
}

def_EHelper(ori) {
  rtl_ori(s, ddest, dsrc1, id_src2->imm);
}


def_EHelper(sll) {
  rtl_sll(s, ddest, dsrc1, dsrc2);
}

def_EHelper(add) {
  rtl_add(s, ddest, dsrc1, dsrc2);
}
def_EHelper(addiw){
  rtl_addiw(s, ddest, dsrc1, id_src2->imm);
}
def_EHelper(addw){
  rtl_addw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(subw){
  rtl_subw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(slliw){
  rtl_slliw(s, ddest, dsrc1, id_src2->imm);
}
def_EHelper(sllw){
  rtl_sllw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(srlw){
  rtl_srlw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(srliw){
  rtl_srliw(s, ddest, dsrc1, id_src2->imm);
}
def_EHelper(sraw){
  rtl_sraw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(sraiw){
  rtl_sraiw(s, ddest, dsrc1, id_src2->imm);
}

def_EHelper(sub) {
  rtl_sub(s, ddest, dsrc1, dsrc2);
}

def_EHelper(sltu) {
  rtl_setrelop(s, RELOP_LTU, ddest, dsrc1, dsrc2);
}

def_EHelper(slt) {
  rtl_setrelop(s, RELOP_LT, ddest, dsrc1, dsrc2);
}

def_EHelper(xor) {
  rtl_xor(s, ddest, dsrc1, dsrc2);
}

def_EHelper(or) {
  rtl_or(s, ddest, dsrc1, dsrc2);
}

def_EHelper(and) {
  rtl_and(s, ddest, dsrc1, dsrc2);
}

def_EHelper(sra) {
  rtl_sra(s, ddest, dsrc1, dsrc2);
}

def_EHelper(srai) {
  rtl_srai(s, ddest, dsrc1, id_src2->imm );//我认为应该用0b11111u只取后五位,但是发现sraiw不加的话也是正确的,所以感到奇怪
}

def_EHelper(srl) {
  rtl_srl(s, ddest, dsrc1, dsrc2);
}

def_EHelper(srli) {
  rtl_srli(s, ddest, dsrc1, id_src2->imm );
}

def_EHelper(slli) {
  rtl_slli(s, ddest, dsrc1, id_src2->imm );
}

def_EHelper(beq) {
  if (*dsrc1 == *ddest){
    rtl_addi(s, &s->dnpc, &s->pc, id_src2->imm);
  }
}

def_EHelper(bne) {
  if (*dsrc1 != *ddest){
    rtl_addi(s, &s->dnpc, &s->pc, id_src2->imm);
  }
}

def_EHelper(bge) {
  if ((sword_t)(*dsrc1) >= (sword_t)(*ddest)){
    rtl_addi(s, &s->dnpc, &s->pc, id_src2->imm);
  }
}

def_EHelper(bgeu) {
  if ((*dsrc1) >= (*ddest)){
    rtl_addi(s, &s->dnpc, &s->pc, id_src2->imm);
  }
}

def_EHelper(blt) {
  if ((sword_t)(*dsrc1) < (sword_t)(*ddest)){
    rtl_addi(s, &s->dnpc, &s->pc, id_src2->imm);
  }
}

def_EHelper(bltu) {
  if ((*dsrc1) < (*ddest)){
    rtl_addi(s, &s->dnpc, &s->pc, id_src2->imm);
  }
}

def_EHelper(sltiu) {
  rtl_setrelopi(s, RELOP_LTU, ddest, dsrc1, id_src2->imm);
}

def_EHelper(slti) {
  rtl_setrelopi(s, RELOP_LT, ddest, dsrc1, id_src2->imm);
}

def_EHelper(jal) {
  rtl_addi(s, ddest, &s->pc, 4);
  rtl_addi(s, &s->dnpc, &s->pc, id_src1->imm);
  // log_call(s->pc,s->dnpc);
}

def_EHelper(jalr) {
  rtl_addi(s, s0, &s->pc, 4);
  rtl_addi(s, &s->dnpc, dsrc1, id_src2->imm);
  rtl_andi(s, &s->dnpc, &s->dnpc, ~1);
  rtl_addi(s, ddest, s0, 0);
  // if (s->isa.instr.i.rd == 0 && s->isa.instr.i.rs1 == 1 && s->isa.instr.i.simm11_0 == 0){//Ret
  //   log_ret(s->pc,s->dnpc);
  // }else{
  //   log_call(s->pc,s->dnpc);
  // }
}
def_EHelper(mul){
  rtl_mulu_lo(s, ddest, dsrc1, dsrc2);
}
def_EHelper(mulh){
  rtl_muls_hi(s, ddest, dsrc1, dsrc2);
}
def_EHelper(mulhu){
  rtl_mulu_hi(s, ddest, dsrc1, dsrc2);
}
def_EHelper(mulhsu){
  rtl_mulhsu(s, ddest, dsrc1, dsrc2);
}
def_EHelper(div){
  rtl_divw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(divu){
  rtl_divuw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(rem){
  rtl_remw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(remu){
  rtl_remuw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(mulw){
  rtl_mulw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(divw){
  rtl_divw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(divuw){
  rtl_divuw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(remw){
  rtl_remw(s, ddest, dsrc1, dsrc2);
}
def_EHelper(remuw){
  rtl_remuw(s, ddest, dsrc1, dsrc2);
}