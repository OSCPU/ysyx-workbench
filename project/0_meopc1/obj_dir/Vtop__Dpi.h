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


    // DPI IMPORTS
    // DPI import at vsrc/ysyx_25020077_IFU.v:5:35
    extern svBitVecVal addr_read(const svBitVecVal* pc);
    // DPI import at vsrc/ysyx_25020077_IDU.v:9:31
    extern svBit is_break(const svBitVecVal* instruction_in);

#ifdef __cplusplus
}
#endif

#endif  // guard
