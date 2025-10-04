// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at vsrc/ysyx_25030077_PC_next.v:11:16
    extern int dnpc_read_data();
    // DPI export at vsrc/ysyx_25030077_IFU.v:56:16
    extern int pc_read_data();
    // DPI export at vsrc/ysyx_25030077_reg.v:20:16
    extern int reg_read_addr();
    // DPI export at vsrc/ysyx_25030077_reg.v:25:16
    extern int reg_read_data();
    // DPI export at vsrc/ysyx_25030077_DATA_CONTROL.v:12:16
    extern int reg_read_rs1();
    // DPI export at vsrc/ysyx_25030077_DATA_CONTROL.v:17:16
    extern int reg_read_rs2();
    // DPI export at vsrc/ysyx_25030077_MEM.v:35:16
    extern int valid_read();
    // DPI export at vsrc/ysyx_25030077_MEM.v:29:16
    extern int wmask_read();

    // DPI IMPORTS
    // DPI import at vsrc/ysyx_25030077_MEM.v:26:37
    extern svBitVecVal addr_read(const svBitVecVal* addr_in);
    // DPI import at vsrc/ysyx_25030077_ALU.v:9:37
    extern svBitVecVal csr_read(const svBitVecVal* rs1, const svBitVecVal* imm, const svBitVecVal* sw);
    // DPI import at vsrc/ysyx_25030077_PC_next.v:15:37
    extern svBitVecVal ecall_read(const svBitVecVal* pc, const svBitVecVal* type_p);
    // DPI import at vsrc/ysyx_25030077_MEM.v:25:37
    extern svBitVecVal mem_data_read(const svBitVecVal* mask, const svBitVecVal* addr_in);

#ifdef __cplusplus
}
#endif

#endif  // guard
