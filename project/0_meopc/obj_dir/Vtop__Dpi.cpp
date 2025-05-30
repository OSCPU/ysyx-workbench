// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call Vtop::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "Vtop__Dpi.h"
#include "Vtop.h"

#ifndef VL_DPIDECL_dnpc_read_data_
#define VL_DPIDECL_dnpc_read_data_
int dnpc_read_data() {
    // DPI export at vsrc/ysyx_25030077_PC_next.v:11:16
    return Vtop::dnpc_read_data();
}
#endif

#ifndef VL_DPIDECL_pc_read_data_
#define VL_DPIDECL_pc_read_data_
int pc_read_data() {
    // DPI export at vsrc/ysyx_25030077_PC.v:8:14
    return Vtop::pc_read_data();
}
#endif

#ifndef VL_DPIDECL_reg_read_addr_
#define VL_DPIDECL_reg_read_addr_
int reg_read_addr() {
    // DPI export at vsrc/ysyx_25030077_reg.v:12:16
    return Vtop::reg_read_addr();
}
#endif

#ifndef VL_DPIDECL_reg_read_data_
#define VL_DPIDECL_reg_read_data_
int reg_read_data() {
    // DPI export at vsrc/ysyx_25030077_reg.v:17:16
    return Vtop::reg_read_data();
}
#endif

#ifndef VL_DPIDECL_reg_read_rs1_
#define VL_DPIDECL_reg_read_rs1_
int reg_read_rs1() {
    // DPI export at vsrc/ysyx_25030077_DATA_CONTROL.v:12:16
    return Vtop::reg_read_rs1();
}
#endif

#ifndef VL_DPIDECL_reg_read_rs2_
#define VL_DPIDECL_reg_read_rs2_
int reg_read_rs2() {
    // DPI export at vsrc/ysyx_25030077_DATA_CONTROL.v:17:16
    return Vtop::reg_read_rs2();
}
#endif

