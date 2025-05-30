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
    VL_IN8(x,3,0);
    VL_IN8(y,3,0);
    VL_IN8(sw,2,0);
    VL_OUT8(result,3,0);
    VL_OUT8(Carry,0,0);
    VL_OUT8(Overflow,0,0);
    VL_OUT8(Zero,0,0);
    VL_OUT8(smg_1,7,0);
    VL_OUT8(smg_2,7,0);
    VL_OUT8(smg_3,7,0);
    VL_OUT8(smg_4,7,0);
    VL_OUT8(smg_5,7,0);
    VL_OUT8(smg_6,7,0);
    VL_OUT8(smg_7,7,0);
    VL_OUT8(smg_8,7,0);
    CData/*4:0*/ top__DOT__i3__DOT__addResult;
    CData/*4:0*/ top__DOT__i3__DOT__subResult;
    CData/*7:0*/ top__DOT__i4__DOT__y;
    CData/*7:0*/ top__DOT__i5__DOT__y;
    CData/*7:0*/ top__DOT__i6__DOT__y;
    CData/*3:0*/ __Vtrigrprev__TOP__x;
    CData/*3:0*/ __Vtrigrprev__TOP__y;
    CData/*3:0*/ __Vtrigrprev__TOP__result;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__i4__DOT__i;
    IData/*31:0*/ top__DOT__i5__DOT__i;
    IData/*31:0*/ top__DOT__i6__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

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
