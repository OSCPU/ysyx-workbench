// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMAXPERIODFIBONACCILFSR_SRAM__SYMS_H_
#define VERILATED_VMAXPERIODFIBONACCILFSR_SRAM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VMaxPeriodFibonacciLFSR_sram.h"

// INCLUDE MODULE CLASSES
#include "VMaxPeriodFibonacciLFSR_sram___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VMaxPeriodFibonacciLFSR_sram__Vcb_dnpc_read_data_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &dnpc_read_data__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_pc_read_data_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read_data__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_addr_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_addr__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_data_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_data__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_rs1_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs1__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_reg_read_rs2_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs2__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_valid_read_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &valid_read__Vfuncrtn);
using VMaxPeriodFibonacciLFSR_sram__Vcb_wmask_read_t = void (*) (VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &wmask_read__Vfuncrtn);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VMaxPeriodFibonacciLFSR_sram__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VMaxPeriodFibonacciLFSR_sram* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VMaxPeriodFibonacciLFSR_sram___024root TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_top__b_ifu;
    VerilatedScope __Vscope_top__f_gpr;
    VerilatedScope __Vscope_top__g_mem;
    VerilatedScope __Vscope_top__h_data_control;
    VerilatedScope __Vscope_top__j_pc_next;

    // CONSTRUCTORS
    VMaxPeriodFibonacciLFSR_sram__Syms(VerilatedContext* contextp, const char* namep, VMaxPeriodFibonacciLFSR_sram* modelp);
    ~VMaxPeriodFibonacciLFSR_sram__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
