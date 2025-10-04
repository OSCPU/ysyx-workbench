// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_25030077__DPI_H_
#define VERILATED_VYSYX_25030077__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at vsrc/ysyx_25030077.v:1620:16
    extern int dnpc_read_data();
    // DPI export at vsrc/ysyx_25030077.v:55:16
    extern int pc_read_data();
    // DPI export at vsrc/ysyx_25030077.v:684:16
    extern int reg_read_addr();
    // DPI export at vsrc/ysyx_25030077.v:689:16
    extern int reg_read_data();
    // DPI export at vsrc/ysyx_25030077.v:1542:16
    extern int reg_read_rs1();
    // DPI export at vsrc/ysyx_25030077.v:1547:16
    extern int reg_read_rs2();
    // DPI export at vsrc/ysyx_25030077.v:1423:16
    extern int valid_read();
    // DPI export at vsrc/ysyx_25030077.v:1418:16
    extern int wmask_read();

    // DPI IMPORTS
    // DPI import at vsrc/ysyx_25030077.v:1416:37
    extern svBitVecVal addr_read(const svBitVecVal* addr_in);
    // DPI import at vsrc/ysyx_25030077.v:1564:37
    extern svBitVecVal csr_read(const svBitVecVal* rs1, const svBitVecVal* imm, const svBitVecVal* sw);
    // DPI import at vsrc/ysyx_25030077.v:1623:37
    extern svBitVecVal ecall_read(const svBitVecVal* pc, const svBitVecVal* type_p);
    // DPI import at vsrc/ysyx_25030077.v:1415:37
    extern svBitVecVal mem_data_read(const svBitVecVal* mask, const svBitVecVal* addr_in);

#ifdef __cplusplus
}
#endif

#endif  // guard
