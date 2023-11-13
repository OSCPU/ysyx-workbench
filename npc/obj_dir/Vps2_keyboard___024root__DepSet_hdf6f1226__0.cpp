// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2_keyboard.h for the primary calling header

#include "verilated.h"

#include "Vps2_keyboard___024root.h"

void Vps2_keyboard___024root___eval_act(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*7:0*/, 16> Vps2_keyboard__ConstPool__TABLE_hc4fbb95d_0;
extern const VlUnpacked<CData/*7:0*/, 16> Vps2_keyboard__ConstPool__TABLE_h40bdb436_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_h2f6b22a7_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_h34e4bf12_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_hdbab5b42_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_h30414c85_0;

VL_INLINE_OPT void Vps2_keyboard___024root___nba_sequent__TOP__0(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*2:0*/ __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync = 0;
    CData/*3:0*/ __Vdly__top__DOT__my_keyboard__DOT__count;
    __Vdly__top__DOT__my_keyboard__DOT__count = 0;
    // Body
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync;
    __Vdly__top__DOT__my_keyboard__DOT__count = vlSelf->top__DOT__my_keyboard__DOT__count;
    __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (vlSelf->rst) {
        __Vdly__top__DOT__my_keyboard__DOT__count = 0U;
    } else if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))) {
        if ((0xaU == (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))) {
            if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                              & (IData)(vlSelf->ps2_data)) 
                             & VL_REDXOR_32((0x1ffU 
                                             & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                                >> 1U)))))) {
                VL_WRITEF("receive %x\n",8,(0xffU & 
                                            ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                             >> 1U)));
                if ((0xf0U == (0xffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                        >> 1U)))) {
                    vlSelf->top__DOT__my_keyboard__DOT__c 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__c)));
                } else {
                    vlSelf->top__DOT__my_keyboard__DOT__b 
                        = (0xffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer) 
                                    >> 1U));
                }
            }
            __Vdly__top__DOT__my_keyboard__DOT__count = 0U;
        } else {
            vlSelf->top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0 
                = vlSelf->ps2_data;
            if (VL_LIKELY((9U >= (IData)(vlSelf->top__DOT__my_keyboard__DOT__count)))) {
                vlSelf->top__DOT__my_keyboard__DOT__buffer 
                    = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))) 
                        & (IData)(vlSelf->top__DOT__my_keyboard__DOT__buffer)) 
                       | (0x3ffU & ((IData)(vlSelf->top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0) 
                                    << (IData)(vlSelf->top__DOT__my_keyboard__DOT__count))));
            }
            __Vdly__top__DOT__my_keyboard__DOT__count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__my_keyboard__DOT__count)));
        }
    }
    vlSelf->top__DOT__my_keyboard__DOT__count = __Vdly__top__DOT__my_keyboard__DOT__count;
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync 
        = __Vdly__top__DOT__my_keyboard__DOT__ps2_clk_sync;
    __Vtableidx1 = vlSelf->top__DOT__my_keyboard__DOT__c;
    vlSelf->seg7 = Vps2_keyboard__ConstPool__TABLE_hc4fbb95d_0
        [__Vtableidx1];
    vlSelf->seg6 = Vps2_keyboard__ConstPool__TABLE_h40bdb436_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelf->top__DOT__my_keyboard__DOT__b;
    vlSelf->seg4 = Vps2_keyboard__ConstPool__TABLE_h2f6b22a7_0
        [__Vtableidx2];
    vlSelf->seg3 = Vps2_keyboard__ConstPool__TABLE_h34e4bf12_0
        [__Vtableidx2];
    vlSelf->seg1 = Vps2_keyboard__ConstPool__TABLE_hdbab5b42_0
        [__Vtableidx2];
    vlSelf->seg0 = Vps2_keyboard__ConstPool__TABLE_h30414c85_0
        [__Vtableidx2];
}

void Vps2_keyboard___024root___eval_nba(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vps2_keyboard___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vps2_keyboard___024root___eval_triggers__act(Vps2_keyboard___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___dump_triggers__act(Vps2_keyboard___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___dump_triggers__nba(Vps2_keyboard___024root* vlSelf);
#endif  // VL_DEBUG

void Vps2_keyboard___024root___eval(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vps2_keyboard___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vps2_keyboard___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vps2_keyboard___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vps2_keyboard___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vps2_keyboard___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vps2_keyboard___024root___eval_debug_assertions(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->sw & 0xc000U))) {
        Verilated::overWidthError("sw");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
    if (VL_UNLIKELY((vlSelf->BTNC & 0xfeU))) {
        Verilated::overWidthError("BTNC");}
    if (VL_UNLIKELY((vlSelf->BTNU & 0xfeU))) {
        Verilated::overWidthError("BTNU");}
    if (VL_UNLIKELY((vlSelf->BTND & 0xfeU))) {
        Verilated::overWidthError("BTND");}
    if (VL_UNLIKELY((vlSelf->BTNL & 0xfeU))) {
        Verilated::overWidthError("BTNL");}
    if (VL_UNLIKELY((vlSelf->BTNR & 0xfeU))) {
        Verilated::overWidthError("BTNR");}
}
#endif  // VL_DEBUG
