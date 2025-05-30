/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <stdint.h>
#include <string.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

void elf_print();
char *ftrace_find_symbol(vaddr_t addr);
enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_N, // none
  //添加第四处，规则添加
  TYPE_A,
  TYPE_J,
  TYPE_SW,
  TYPE_L,
  TYPE_M,
  TYPE_B,
  TYPE_SR,
  TYPE_LU,
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)

//添加第三处，立即数提取
#define immA() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | (BITS(i, 19, 12) << 12) | (BITS(i, 20, 20) << 11) | (BITS(i, 30, 21) << 1);} while(0)
#define immSW()do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7);} while(0)
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | (BITS(i, 7, 7) << 11) | (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1);} while(0)
#define immSR()do { *imm = SEXT(BITS(i, 25, 20), 6);} while(0)
#define immLU()do { *imm = (SEXT(BITS(i, 31, 12), 20) << 12);} while(0)

void ftrace_check(int type,Decode *s,word_t imm, int rd){
  if(CONFIG_FTRACE){
    uint32_t i = s->isa.inst;
    int rs1 = BITS(i, 19, 15);
    char *prev_fname = ftrace_find_symbol(s->pc);
    char *now_fname  = ftrace_find_symbol(s->dnpc);
    if(strcmp(prev_fname,now_fname) == 0)	return;
    if(type == 0) elf_print(0,now_fname,s->dnpc,s->pc);
    else if(type == 1){
      if(rs1 == 1 && imm == 0 && rd == 0)
        elf_print(1,prev_fname,s->dnpc,s->pc);
      else 
        elf_print(0,now_fname,s->dnpc,s->pc);
    }
  }
}

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break; 
    case TYPE_N: break;

    //添加第二处，取操作数
    case TYPE_A: src1R();          immA(); break;
    case TYPE_J:                   immJ(); break;
    case TYPE_SW:src1R(); src2R(); immSW();break;
    case TYPE_L: src1R();          immI(); break;
    case TYPE_M: src1R(); src2R();         break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    case TYPE_SR:src1R();          immSR(); break;
    case TYPE_LU:                  immLU(); break;
    default: panic("unsupported type = %d", type);
  }
}
//int pp = 0;
static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;
  // printf("pc = %x\n", s->pc);
  // printf("inst = %x\n", s->isa.inst);
  #define INSTPAT_INST(s) ((s)->isa.inst)
  #define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
    int rd = 0; \
    word_t src1 = 0, src2 = 0, imm = 0; \
    decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
    __VA_ARGS__ ; \
  }
    INSTPAT_START();
    INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc , U, R(rd) = s->pc + imm);
    INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu   , I, R(rd) = Mr(src1 + imm, 1));
    INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb    , S, Mw(src1 + imm, 1, src2));
    INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
    //自己开始添加的
    INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, A,   R(rd) = src1 + imm; );
    INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, A,   R(rd) = src1 & imm; );
    INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal  ,J,   s->dnpc = s->pc + imm; R(rd) = s->snpc; ftrace_check(0, s, imm, rd));//跳转指令
    INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw  , SW,  Mw(src1 + imm, 4, src2));
    INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr ,A,   s->dnpc = (src1 + imm) & ~1; R(rd) = s->snpc; ftrace_check(1, s, imm, rd));//跳转指令
    INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh ,  L,   R(rd) = SEXT(Mr(src1 + imm ,2), 16));
    INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu , L,   R(rd) = Mr(src1 + imm ,2));
    INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw ,  L,   R(rd) = Mr(src1 + imm ,4));
    INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui , LU,  R(rd) = imm;);
    INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add , M,   R(rd) = src1 + src2);
    INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem , M,   R(rd) = (int32_t)src1 % (int32_t)src2);
    INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu, M,   R(rd) = src1 % src2);
    INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub , M,   R(rd) = src1 - src2);
    INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul , M,   R(rd) = src1 * src2);
    INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh ,M,   R(rd) = ((int64_t)SEXT(src1, 32) * (int64_t)SEXT(src2, 32)) >> 32;);
    INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu ,M,  R(rd) = ((uint64_t)src1 * (uint64_t)src2) >> 32;);
    INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div , M,   R(rd) = (int32_t)src1 / (int32_t)src2);
    INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu ,M,   R(rd) = src1 / src2);
    INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor , M,   R(rd) = src1 ^ src2);
    INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori ,A,   R(rd) = src1 ^ imm);
    INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori  ,A,   R(rd) = src1 | imm);
    INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and , M,   R(rd) = src1 & src2);
    INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or  , M,   R(rd) = src1 | src2);
    INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll , M,   R(rd) = src1 << BITS(src2, 4, 0));
    INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu,I,   R(rd) = src1 < imm ? 1 : 0);
    INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu ,M,   R(rd) = src1 < src2 ? 1 : 0);
    INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh,   SW,  Mw(src1 + imm, 2, src2));
    INSTPAT("000000? ????? ????? 101 ????? 01100 11", srl , M,   R(rd) = src1 >> BITS(src2, 4, 0));
    INSTPAT("000000? ????? ????? 001 ????? 00100 11", slli ,SR,  if(imm < 0) assert("Wrong shmat!!"); R(rd) = src1 << BITS(imm, 4, 0));
    INSTPAT("010000? ????? ????? 101 ????? 01100 11", sra , M,   R(rd) = (int32_t)src1 >> BITS(src2, 4, 0));
    INSTPAT("010000? ????? ????? 101 ????? 00100 11", srai ,SR,  if(imm < 0) assert("Wrong shmat!!"); R(rd) = (int32_t)src1 >> BITS(imm, 4, 0));
    INSTPAT("000000? ????? ????? 101 ????? 00100 11", srli ,SR,  if(imm < 0) assert("Wrong shmat!!"); R(rd) = src1 >> BITS(imm, 4, 0));
    INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq , B,   s->dnpc = (src1 == src2)? s->pc + imm : s->dnpc);//跳转指令
    INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne , B,   s->dnpc = (src1 != src2)? s->pc + imm : s->dnpc);//跳转指令
    INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt , B,   s->dnpc = ((int32_t)src1 <  (int32_t)src2)? s->pc + imm : s->dnpc);//跳转指令
    INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu ,B,   s->dnpc = (src1 < src2)? s->pc + imm : s->dnpc);//跳转指令
    INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt , M,   R(rd) = ((int32_t)src1 <  (int32_t)src2)? 1 : 0);
    INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge , B,   s->dnpc = ((int32_t)src1 >= (int32_t)src2)? s->pc + imm : s->dnpc);//跳转指令
    INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu ,B,   s->dnpc = (src1 >= src2)? s->pc + imm : s->dnpc);//跳转指令
    //添加第一处：匹配规则

    INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
    INSTPAT_END();

    R(0) = 0; // reset $zero to 0

    return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);//取指
  return decode_exec(s);//译码
}
