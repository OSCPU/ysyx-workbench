#ifndef __CPU_EXEC_H__
#define __CPU_EXEC_H__

#include "common.h"
#include "memory.h"
void step_and_dump_wave();
// svBit is_break(const svBitVecVal* instruction_in);
svBitVecVal addr_read(const svBitVecVal* pc);
svBitVecVal ecall_read(const svBitVecVal* pc, svBitVecVal* type_p);
svBitVecVal csr_read(const svBitVecVal* rs1, const svBitVecVal* imm, const svBitVecVal* sw);
int cpu_init(int argc, char** argv);
int cpu_exec(int n);
int cpu_end();
#endif