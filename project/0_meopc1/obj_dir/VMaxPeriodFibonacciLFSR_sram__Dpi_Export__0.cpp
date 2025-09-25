// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VMaxPeriodFibonacciLFSR_sram.h"
#include "VMaxPeriodFibonacciLFSR_sram__Syms.h"
#include "verilated_dpi.h"


int VMaxPeriodFibonacciLFSR_sram::pc_read_data() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::pc_read_data\n"); );
    // Init
    IData/*31:0*/ pc_read_data__Vfuncrtn__Vcvt;
    pc_read_data__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("pc_read_data");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_pc_read_data_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_pc_read_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), pc_read_data__Vfuncrtn__Vcvt);
    int pc_read_data__Vfuncrtn;
    pc_read_data__Vfuncrtn = pc_read_data__Vfuncrtn__Vcvt;
    return pc_read_data__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::reg_read_addr() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::reg_read_addr\n"); );
    // Init
    IData/*31:0*/ reg_read_addr__Vfuncrtn__Vcvt;
    reg_read_addr__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("reg_read_addr");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_addr_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_addr_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), reg_read_addr__Vfuncrtn__Vcvt);
    int reg_read_addr__Vfuncrtn;
    reg_read_addr__Vfuncrtn = reg_read_addr__Vfuncrtn__Vcvt;
    return reg_read_addr__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::reg_read_data() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::reg_read_data\n"); );
    // Init
    IData/*31:0*/ reg_read_data__Vfuncrtn__Vcvt;
    reg_read_data__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("reg_read_data");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_data_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), reg_read_data__Vfuncrtn__Vcvt);
    int reg_read_data__Vfuncrtn;
    reg_read_data__Vfuncrtn = reg_read_data__Vfuncrtn__Vcvt;
    return reg_read_data__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::wmask_read() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::wmask_read\n"); );
    // Init
    IData/*31:0*/ wmask_read__Vfuncrtn__Vcvt;
    wmask_read__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("wmask_read");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_wmask_read_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_wmask_read_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), wmask_read__Vfuncrtn__Vcvt);
    int wmask_read__Vfuncrtn;
    wmask_read__Vfuncrtn = wmask_read__Vfuncrtn__Vcvt;
    return wmask_read__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::valid_read() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::valid_read\n"); );
    // Init
    IData/*31:0*/ valid_read__Vfuncrtn__Vcvt;
    valid_read__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("valid_read");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_valid_read_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_valid_read_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), valid_read__Vfuncrtn__Vcvt);
    int valid_read__Vfuncrtn;
    valid_read__Vfuncrtn = valid_read__Vfuncrtn__Vcvt;
    return valid_read__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::reg_read_rs1() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::reg_read_rs1\n"); );
    // Init
    IData/*31:0*/ reg_read_rs1__Vfuncrtn__Vcvt;
    reg_read_rs1__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("reg_read_rs1");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_rs1_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_rs1_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), reg_read_rs1__Vfuncrtn__Vcvt);
    int reg_read_rs1__Vfuncrtn;
    reg_read_rs1__Vfuncrtn = reg_read_rs1__Vfuncrtn__Vcvt;
    return reg_read_rs1__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::reg_read_rs2() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::reg_read_rs2\n"); );
    // Init
    IData/*31:0*/ reg_read_rs2__Vfuncrtn__Vcvt;
    reg_read_rs2__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("reg_read_rs2");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_rs2_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_rs2_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), reg_read_rs2__Vfuncrtn__Vcvt);
    int reg_read_rs2__Vfuncrtn;
    reg_read_rs2__Vfuncrtn = reg_read_rs2__Vfuncrtn__Vcvt;
    return reg_read_rs2__Vfuncrtn;
}

int VMaxPeriodFibonacciLFSR_sram::dnpc_read_data() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root::dnpc_read_data\n"); );
    // Init
    IData/*31:0*/ dnpc_read_data__Vfuncrtn__Vcvt;
    dnpc_read_data__Vfuncrtn__Vcvt = 0;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("dnpc_read_data");
    const VerilatedScope* const __Vscopep = Verilated::dpiScope();
    VMaxPeriodFibonacciLFSR_sram__Vcb_dnpc_read_data_t __Vcb = (VMaxPeriodFibonacciLFSR_sram__Vcb_dnpc_read_data_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VMaxPeriodFibonacciLFSR_sram__Syms*)(__Vscopep->symsp()), dnpc_read_data__Vfuncrtn__Vcvt);
    int dnpc_read_data__Vfuncrtn;
    dnpc_read_data__Vfuncrtn = dnpc_read_data__Vfuncrtn__Vcvt;
    return dnpc_read_data__Vfuncrtn;
}
