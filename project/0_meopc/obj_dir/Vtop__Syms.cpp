// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

void Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i0__DOT__pc_read_data_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read_data__Vfuncrtn);
void Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i4__DOT__reg_read_addr_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_addr__Vfuncrtn);
void Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i4__DOT__reg_read_data_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_data__Vfuncrtn);
void Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i5__DOT__reg_read_rs1_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs1__Vfuncrtn);
void Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i5__DOT__reg_read_rs2_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs2__Vfuncrtn);
void Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i7__DOT__dnpc_read_data_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &dnpc_read_data__Vfuncrtn);

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(438);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_ysyx_25030077_top__i0.configure(this, name(), "ysyx_25030077_top.i0", "i0", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyx_25030077_top__i4.configure(this, name(), "ysyx_25030077_top.i4", "i4", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyx_25030077_top__i5.configure(this, name(), "ysyx_25030077_top.i5", "i5", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_ysyx_25030077_top__i7.configure(this, name(), "ysyx_25030077_top.i7", "i7", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_ysyx_25030077_top__i0.exportInsert(__Vfinal, "pc_read_data", (void*)(&Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i0__DOT__pc_read_data_TOP));
        __Vscope_ysyx_25030077_top__i4.exportInsert(__Vfinal, "reg_read_addr", (void*)(&Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i4__DOT__reg_read_addr_TOP));
        __Vscope_ysyx_25030077_top__i4.exportInsert(__Vfinal, "reg_read_data", (void*)(&Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i4__DOT__reg_read_data_TOP));
        __Vscope_ysyx_25030077_top__i5.exportInsert(__Vfinal, "reg_read_rs1", (void*)(&Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i5__DOT__reg_read_rs1_TOP));
        __Vscope_ysyx_25030077_top__i5.exportInsert(__Vfinal, "reg_read_rs2", (void*)(&Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i5__DOT__reg_read_rs2_TOP));
        __Vscope_ysyx_25030077_top__i7.exportInsert(__Vfinal, "dnpc_read_data", (void*)(&Vtop___024root____Vdpiexp_ysyx_25030077_top__DOT__i7__DOT__dnpc_read_data_TOP));
    }
}
