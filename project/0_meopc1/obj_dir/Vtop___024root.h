// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(rd,4,0);
    VL_OUT8(ALU_ctrl,2,0);
    VL_OUT8(ALU_carry,0,0);
    VL_OUT8(ALU_overflow,0,0);
    VL_OUT8(is_break_out,0,0);
    CData/*4:0*/ ysyx_25020077_top__DOT__rs1;
    CData/*0:0*/ ysyx_25020077_top__DOT__i5__DOT____VdfgTmp_h0adca177__0;
    CData/*0:0*/ __Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout;
    CData/*0:0*/ __Vtrigrprev__TOP__clock;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ ysyx_25020077_top__DOT__i2__DOT__instruction_type;
    VL_OUT(imm,31,0);
    VL_OUT(rs1_out,31,0);
    VL_OUT(rs2_out,31,0);
    IData/*31:0*/ ysyx_25020077_top__DOT__instruction_out;
    IData/*31:0*/ ysyx_25020077_top__DOT__i0__DOT__state;
    IData/*31:0*/ ysyx_25020077_top__DOT__i0__DOT___nextState_T_2;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_0;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_1;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_2;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_3;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_4;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_5;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_6;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_7;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_8;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_9;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_10;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_11;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_12;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_13;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_14;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_15;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_16;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_17;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_18;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_19;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_20;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_21;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_22;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_23;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_24;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_25;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_26;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_27;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_28;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_29;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_30;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT__regs_31;
    IData/*31:0*/ ysyx_25020077_top__DOT__i4__DOT___GEN_53;
    IData/*31:0*/ ysyx_25020077_top__DOT__i5__DOT___io_out_T_13;
    IData/*31:0*/ ysyx_25020077_top__DOT__i5__DOT___io_out_T_15;
    IData/*31:0*/ ysyx_25020077_top__DOT__i5__DOT___io_out_T_17;
    IData/*31:0*/ __Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    QData/*32:0*/ ysyx_25020077_top__DOT__i5__DOT__addResult;
    QData/*32:0*/ ysyx_25020077_top__DOT__i5__DOT__subResult;
    QData/*32:0*/ ysyx_25020077_top__DOT__i5__DOT___io_out_T_47;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
