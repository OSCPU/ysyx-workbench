// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vps2_keyboard.h for the primary calling header

#ifndef VERILATED_VPS2_KEYBOARD___024ROOT_H_
#define VERILATED_VPS2_KEYBOARD___024ROOT_H_  // guard

#include "verilated.h"

class Vps2_keyboard__Syms;

class Vps2_keyboard___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_IN8(BTNC,0,0);
    VL_IN8(BTNU,0,0);
    VL_IN8(BTND,0,0);
    VL_IN8(BTNL,0,0);
    VL_IN8(BTNR,0,0);
    VL_OUT8(VGA_CLK,0,0);
    VL_OUT8(VGA_HSYNC,0,0);
    VL_OUT8(VGA_VSYNC,0,0);
    VL_OUT8(VGA_BLANK_N,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(seg0,7,0);
    VL_OUT8(seg1,7,0);
    VL_OUT8(seg2,7,0);
    VL_OUT8(seg3,7,0);
    VL_OUT8(seg4,7,0);
    VL_OUT8(seg5,7,0);
    VL_OUT8(seg6,7,0);
    VL_OUT8(seg7,7,0);
    CData/*3:0*/ top__DOT__my_keyboard__DOT__count;
    CData/*2:0*/ top__DOT__my_keyboard__DOT__ps2_clk_sync;
    CData/*3:0*/ top__DOT__my_keyboard__DOT__c;
    CData/*7:0*/ top__DOT__my_keyboard__DOT__b;
    CData/*0:0*/ top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN16(sw,13,0);
    VL_OUT16(ledr,15,0);
    SData/*9:0*/ top__DOT__my_keyboard__DOT__buffer;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vps2_keyboard__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vps2_keyboard___024root(Vps2_keyboard__Syms* symsp, const char* v__name);
    ~Vps2_keyboard___024root();
    VL_UNCOPYABLE(Vps2_keyboard___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
