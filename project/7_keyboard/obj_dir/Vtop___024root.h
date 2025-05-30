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
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(overflow,0,0);
    VL_OUT8(seg_1,7,0);
    VL_OUT8(seg_2,7,0);
    VL_OUT8(seg_3,7,0);
    VL_OUT8(seg_4,7,0);
    VL_OUT8(seg_5,7,0);
    VL_OUT8(seg_6,7,0);
    VL_OUT8(seg_7,7,0);
    VL_OUT8(seg_8,7,0);
    CData/*1:0*/ top__DOT__close;
    CData/*7:0*/ top__DOT__y_1;
    CData/*7:0*/ top__DOT__press_count;
    CData/*3:0*/ top__DOT__data_1;
    CData/*3:0*/ top__DOT__data_2;
    CData/*3:0*/ top__DOT__data_3;
    CData/*3:0*/ top__DOT__data_4;
    CData/*3:0*/ top__DOT__data_5;
    CData/*3:0*/ top__DOT__data_6;
    CData/*7:0*/ top__DOT__dout;
    CData/*2:0*/ top__DOT__i1__DOT__w_ptr;
    CData/*2:0*/ top__DOT__i1__DOT__r_ptr;
    CData/*3:0*/ top__DOT__i1__DOT__count;
    CData/*2:0*/ top__DOT__i1__DOT__ps2_clk_sync;
    CData/*0:0*/ top__DOT__i1__DOT__nextdata_n;
    CData/*0:0*/ top__DOT__i1__DOT__ready;
    CData/*0:0*/ top__DOT__i1__DOT____Vlvbound_h1a91ade8__0;
    CData/*7:0*/ top__DOT__i2__DOT__y;
    CData/*7:0*/ top__DOT__i3__DOT__y;
    CData/*7:0*/ top__DOT__i4__DOT__y;
    CData/*7:0*/ top__DOT__i5__DOT__y;
    CData/*7:0*/ top__DOT__i7__DOT__y;
    CData/*7:0*/ top__DOT__i8__DOT__y;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*3:0*/ __Vtrigrprev__TOP__top__DOT__data_1;
    CData/*3:0*/ __Vtrigrprev__TOP__top__DOT__data_2;
    CData/*3:0*/ __Vtrigrprev__TOP__top__DOT__data_3;
    CData/*3:0*/ __Vtrigrprev__TOP__top__DOT__data_4;
    CData/*3:0*/ __Vtrigrprev__TOP__top__DOT__data_5;
    CData/*3:0*/ __Vtrigrprev__TOP__top__DOT__data_6;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ top__DOT__i1__DOT__buffer;
    IData/*31:0*/ top__DOT__i2__DOT__i;
    IData/*31:0*/ top__DOT__i3__DOT__i;
    IData/*31:0*/ top__DOT__i4__DOT__i;
    IData/*31:0*/ top__DOT__i5__DOT__i;
    IData/*31:0*/ top__DOT__i7__DOT__i;
    IData/*31:0*/ top__DOT__i8__DOT__i;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> top__DOT__i1__DOT__fifo;
    VlUnpacked<CData/*7:0*/, 256> top__DOT__i6__DOT__rom;
    VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<7> __VactTriggered;
    VlTriggerVec<7> __VnbaTriggered;

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
