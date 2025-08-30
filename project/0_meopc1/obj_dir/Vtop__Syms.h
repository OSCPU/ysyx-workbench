// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using Vtop__Vcb_dnpc_read_data_t = void (*) (Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &dnpc_read_data__Vfuncrtn);
using Vtop__Vcb_pc_read_data_t = void (*) (Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read_data__Vfuncrtn);
using Vtop__Vcb_reg_read_addr_t = void (*) (Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_addr__Vfuncrtn);
using Vtop__Vcb_reg_read_data_t = void (*) (Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_data__Vfuncrtn);
using Vtop__Vcb_reg_read_rs1_t = void (*) (Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs1__Vfuncrtn);
using Vtop__Vcb_reg_read_rs2_t = void (*) (Vtop__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs2__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_ysyx_25030077_top__i0;
    VerilatedScope __Vscope_ysyx_25030077_top__i4;
    VerilatedScope __Vscope_ysyx_25030077_top__i5;
    VerilatedScope __Vscope_ysyx_25030077_top__i7;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
