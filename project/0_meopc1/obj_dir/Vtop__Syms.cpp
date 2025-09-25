// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"

void Vtop___024root____Vdpiexp_top__DOT__b_ifu__DOT__pc_read_data_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read_data__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_addr_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_addr__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_data_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_data__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__g_mem__DOT__valid_read_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &valid_read__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__g_mem__DOT__wmask_read_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &wmask_read__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs1_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs1__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs2_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs2__Vfuncrtn);
void Vtop___024root____Vdpiexp_top__DOT__j_pc_next__DOT__dnpc_read_data_TOP(Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &dnpc_read_data__Vfuncrtn);

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
        Verilated::stackCheck(280);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_top__b_ifu.configure(this, name(), "top.b_ifu", "b_ifu", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__f_gpr.configure(this, name(), "top.f_gpr", "f_gpr", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__g_mem.configure(this, name(), "top.g_mem", "g_mem", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__h_data_control.configure(this, name(), "top.h_data_control", "h_data_control", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    __Vscope_top__j_pc_next.configure(this, name(), "top.j_pc_next", "j_pc_next", "<null>", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_top__b_ifu.exportInsert(__Vfinal, "pc_read_data", (void*)(&Vtop___024root____Vdpiexp_top__DOT__b_ifu__DOT__pc_read_data_TOP));
        __Vscope_top__f_gpr.exportInsert(__Vfinal, "reg_read_addr", (void*)(&Vtop___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_addr_TOP));
        __Vscope_top__f_gpr.exportInsert(__Vfinal, "reg_read_data", (void*)(&Vtop___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_data_TOP));
        __Vscope_top__g_mem.exportInsert(__Vfinal, "valid_read", (void*)(&Vtop___024root____Vdpiexp_top__DOT__g_mem__DOT__valid_read_TOP));
        __Vscope_top__g_mem.exportInsert(__Vfinal, "wmask_read", (void*)(&Vtop___024root____Vdpiexp_top__DOT__g_mem__DOT__wmask_read_TOP));
        __Vscope_top__h_data_control.exportInsert(__Vfinal, "reg_read_rs1", (void*)(&Vtop___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs1_TOP));
        __Vscope_top__h_data_control.exportInsert(__Vfinal, "reg_read_rs2", (void*)(&Vtop___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs2_TOP));
        __Vscope_top__j_pc_next.exportInsert(__Vfinal, "dnpc_read_data", (void*)(&Vtop___024root____Vdpiexp_top__DOT__j_pc_next__DOT__dnpc_read_data_TOP));
    }
}
