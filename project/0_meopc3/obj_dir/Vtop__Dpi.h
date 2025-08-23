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
    // DPI export at vsrc/ysyx_25030077_PC_next.v:18:16
    extern int dnpc_read_data();
    // DPI export at vsrc/ysyx_25030077_IFU.v:13:16
    extern int pc_read_data();
    // DPI export at vsrc/ysyx_25030077_reg.v:14:16
    extern int reg_read_addr();
    // DPI export at vsrc/ysyx_25030077_reg.v:19:16
    extern int reg_read_data();
    // DPI export at vsrc/ysyx_25030077_DATA_CONTROL.v:28:16
    extern int reg_read_rs1();
    // DPI export at vsrc/ysyx_25030077_DATA_CONTROL.v:33:16
    extern int reg_read_rs2();

    // DPI IMPORTS
    // DPI import at vsrc/ysyx_25030077_sram.v:12:37
    extern svBitVecVal addr_read(const svBitVecVal* pc);
    // DPI import at vsrc/ysyx_25030077_IDU.v:20:31
    extern svBit is_break(const svBitVecVal* instruction_in);
    // DPI import at vsrc/ysyx_25030077_MEM_read.v:11:37
    extern svBitVecVal mem_data_read(const svBitVecVal* instruction_in, const svBitVecVal* rs1_data_in, const svBitVecVal* rs2_data_in, const svBitVecVal* imm_data_in);

#ifdef __cplusplus
}
#endif

#endif  // guard
