// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*7:0*/, 512> Vtop__ConstPool__TABLE_h0fcedd5f_0;

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__i1__DOT__data) 
                     << 1U) | (IData)(vlSelf->rst));
    vlSelf->top__DOT__i1__DOT__data = Vtop__ConstPool__TABLE_h0fcedd5f_0
        [__Vtableidx1];
    vlSelf->y = vlSelf->top__DOT__i1__DOT__data;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__i2__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->top__DOT__data_1))) {
        if ((4U & (IData)(vlSelf->top__DOT__data_1))) {
            if ((2U & (IData)(vlSelf->top__DOT__data_1))) {
                if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x8eU;
                } else {
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i2__DOT__y = 0xf2U;
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
                vlSelf->top__DOT__i2__DOT__y = 0x7aU;
            } else {
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
                vlSelf->top__DOT__i2__DOT__y = 0x9cU;
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__data_1))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
                vlSelf->top__DOT__i2__DOT__y = 0x3eU;
            } else {
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
                vlSelf->top__DOT__i2__DOT__y = 0xeeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
            vlSelf->top__DOT__i2__DOT__y = 0xf6U;
        } else {
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
            vlSelf->top__DOT__i2__DOT__y = 0xfeU;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__data_1))) {
        if ((2U & (IData)(vlSelf->top__DOT__data_1))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
                vlSelf->top__DOT__i2__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
                vlSelf->top__DOT__i2__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
            vlSelf->top__DOT__i2__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
            vlSelf->top__DOT__i2__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__data_1))) {
        if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
            vlSelf->top__DOT__i2__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
            vlSelf->top__DOT__i2__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__data_1))) {
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
        vlSelf->top__DOT__i2__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
        vlSelf->top__DOT__i2__DOT__y = 0xfcU;
    }
    vlSelf->seg_1 = (0xffU & (~ (IData)(vlSelf->top__DOT__i2__DOT__y)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__i3__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->top__DOT__data_2))) {
        if ((4U & (IData)(vlSelf->top__DOT__data_2))) {
            if ((2U & (IData)(vlSelf->top__DOT__data_2))) {
                if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x8eU;
                } else {
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                    vlSelf->top__DOT__i3__DOT__y = 0xf2U;
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
                vlSelf->top__DOT__i3__DOT__y = 0x7aU;
            } else {
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
                vlSelf->top__DOT__i3__DOT__y = 0x9cU;
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__data_2))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
                vlSelf->top__DOT__i3__DOT__y = 0x3eU;
            } else {
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
                vlSelf->top__DOT__i3__DOT__y = 0xeeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
            vlSelf->top__DOT__i3__DOT__y = 0xf6U;
        } else {
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
            vlSelf->top__DOT__i3__DOT__y = 0xfeU;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__data_2))) {
        if ((2U & (IData)(vlSelf->top__DOT__data_2))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
                vlSelf->top__DOT__i3__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
                vlSelf->top__DOT__i3__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
            vlSelf->top__DOT__i3__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
            vlSelf->top__DOT__i3__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__data_2))) {
        if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
            vlSelf->top__DOT__i3__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
            vlSelf->top__DOT__i3__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__data_2))) {
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
        vlSelf->top__DOT__i3__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
        vlSelf->top__DOT__i3__DOT__y = 0xfcU;
    }
    vlSelf->seg_2 = (0xffU & (~ (IData)(vlSelf->top__DOT__i3__DOT__y)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->top__DOT__data_1 = (0xfU & ((IData)(vlSelf->top__DOT__i1__DOT__data) 
                                        >> 4U));
    vlSelf->top__DOT__data_2 = (0xfU & (IData)(vlSelf->top__DOT__i1__DOT__data));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
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
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 46, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 46, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->Clk & 0xfeU))) {
        Verilated::overWidthError("Clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
