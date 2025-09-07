// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(rd,4,0);
        VL_OUT8(ALU_ctrl,3,0);
        VL_OUT8(ALU_carry,0,0);
        VL_OUT8(ALU_overflow,0,0);
        CData/*2:0*/ ysyx_25030077_top__DOT__imm_type;
        CData/*4:0*/ ysyx_25030077_top__DOT__rs1;
        CData/*4:0*/ ysyx_25030077_top__DOT__rs2;
        CData/*2:0*/ ysyx_25030077_top__DOT__data_control;
        CData/*3:0*/ ysyx_25030077_top__DOT__pc_next_type;
        CData/*0:0*/ ysyx_25030077_top__DOT__is_break_out;
        CData/*0:0*/ ysyx_25030077_top__DOT__i7__DOT__is_eql;
        CData/*0:0*/ __Vfunc_ysyx_25030077_top__DOT__i2__DOT__is_break__1__Vfuncout;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2;
        SData/*15:0*/ ysyx_25030077_top__DOT__i2__DOT___issrai_T_3;
        VL_OUT(imm,31,0);
        VL_OUT(rs1_out,31,0);
        VL_OUT(rs2_out,31,0);
        IData/*31:0*/ ysyx_25030077_top__DOT__Pc_next;
        IData/*31:0*/ ysyx_25030077_top__DOT__instruction_out;
        IData/*31:0*/ ysyx_25030077_top__DOT__ALU_result;
        IData/*31:0*/ ysyx_25030077_top__DOT__mem_data;
        IData/*31:0*/ ysyx_25030077_top__DOT__ALU_data_1;
        IData/*31:0*/ ysyx_25030077_top__DOT__ALU_data_2;
        IData/*31:0*/ ysyx_25030077_top__DOT__i0__DOT__state;
        IData/*16:0*/ ysyx_25030077_top__DOT__i2__DOT___isadd_T_3;
        IData/*31:0*/ ysyx_25030077_top__DOT__i3__DOT__Imm_type1;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_0;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_1;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_2;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_3;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_4;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_5;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_6;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_7;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_8;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_9;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_10;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_11;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_12;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_13;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_14;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_15;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_16;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_17;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_18;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_19;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_20;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_21;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_22;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_23;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_24;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_25;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_26;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_27;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_28;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_29;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_30;
        IData/*31:0*/ ysyx_25030077_top__DOT__i4__DOT__regs_31;
        IData/*31:0*/ ysyx_25030077_top__DOT__i6__DOT__csr_data;
    };
    struct {
        IData/*31:0*/ ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc;
        IData/*31:0*/ ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9;
        IData/*31:0*/ __Vfunc_ysyx_25030077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_25030077_top__DOT__i6__DOT__csr_read__2__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_25030077_top__DOT__i7__DOT__ecall_read__3__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_25030077_top__DOT__i9__DOT__mem_data_read__4__Vfuncout;
        IData/*31:0*/ __VactIterCount;
        QData/*32:0*/ ysyx_25030077_top__DOT__i6__DOT__addResult;
        QData/*32:0*/ ysyx_25030077_top__DOT__i6__DOT__subResult;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
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
};


#endif  // guard
