// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        if ((2U & (IData)(vlSelf->top__DOT__close))) {
            vlSelf->seg_1 = 0xffU;
            vlSelf->seg_2 = 0xffU;
            vlSelf->seg_5 = 0xffU;
            vlSelf->seg_6 = 0xffU;
        } else {
            vlSelf->seg_1 = (0xffU & (~ (IData)(vlSelf->top__DOT__i2__DOT__y)));
            vlSelf->seg_2 = (0xffU & (~ (IData)(vlSelf->top__DOT__i3__DOT__y)));
            vlSelf->seg_5 = (0xffU & (~ (IData)(vlSelf->top__DOT__i7__DOT__y)));
            vlSelf->seg_6 = (0xffU & (~ (IData)(vlSelf->top__DOT__i8__DOT__y)));
        }
    } else {
        vlSelf->seg_1 = 0xffU;
        vlSelf->seg_2 = 0xffU;
        vlSelf->seg_5 = 0xffU;
        vlSelf->seg_6 = 0xffU;
    }
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__top__DOT__i1__DOT__ps2_clk_sync;
    __Vdly__top__DOT__i1__DOT__ps2_clk_sync = 0;
    CData/*0:0*/ __Vdly__top__DOT__i1__DOT__nextdata_n;
    __Vdly__top__DOT__i1__DOT__nextdata_n = 0;
    CData/*2:0*/ __Vdly__top__DOT__i1__DOT__r_ptr;
    __Vdly__top__DOT__i1__DOT__r_ptr = 0;
    CData/*2:0*/ __Vdly__top__DOT__i1__DOT__w_ptr;
    __Vdly__top__DOT__i1__DOT__w_ptr = 0;
    CData/*7:0*/ __Vdly__top__DOT__press_count;
    __Vdly__top__DOT__press_count = 0;
    CData/*1:0*/ __Vdly__top__DOT__close;
    __Vdly__top__DOT__close = 0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__i1__DOT__fifo__v0;
    __Vdlyvdim0__top__DOT__i1__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__i1__DOT__fifo__v0;
    __Vdlyvval__top__DOT__i1__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__i1__DOT__fifo__v0;
    __Vdlyvset__top__DOT__i1__DOT__fifo__v0 = 0;
    CData/*3:0*/ __Vdly__top__DOT__i1__DOT__count;
    __Vdly__top__DOT__i1__DOT__count = 0;
    // Body
    __Vdly__top__DOT__i1__DOT__ps2_clk_sync = vlSelf->top__DOT__i1__DOT__ps2_clk_sync;
    __Vdly__top__DOT__i1__DOT__count = vlSelf->top__DOT__i1__DOT__count;
    __Vdly__top__DOT__i1__DOT__w_ptr = vlSelf->top__DOT__i1__DOT__w_ptr;
    __Vdly__top__DOT__i1__DOT__nextdata_n = vlSelf->top__DOT__i1__DOT__nextdata_n;
    __Vdly__top__DOT__press_count = vlSelf->top__DOT__press_count;
    __Vdly__top__DOT__close = vlSelf->top__DOT__close;
    __Vdly__top__DOT__i1__DOT__r_ptr = vlSelf->top__DOT__i1__DOT__r_ptr;
    __Vdlyvset__top__DOT__i1__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__i1__DOT__ps2_clk_sync = ((6U 
                                                & ((IData)(vlSelf->top__DOT__i1__DOT__ps2_clk_sync) 
                                                   << 1U)) 
                                               | (IData)(vlSelf->ps2_clk));
    if (vlSelf->rst) {
        if (vlSelf->top__DOT__i1__DOT__ready) {
            if (vlSelf->top__DOT__i1__DOT__nextdata_n) {
                __Vdly__top__DOT__i1__DOT__nextdata_n = 0U;
            } else if ((1U & (~ (IData)(vlSelf->top__DOT__i1__DOT__nextdata_n)))) {
                __Vdly__top__DOT__i1__DOT__r_ptr = 
                    (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__i1__DOT__r_ptr)));
                if (((IData)(vlSelf->top__DOT__i1__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__i1__DOT__r_ptr))))) {
                    vlSelf->top__DOT__i1__DOT__ready = 0U;
                    __Vdly__top__DOT__i1__DOT__w_ptr = 0U;
                    __Vdly__top__DOT__i1__DOT__r_ptr = 0U;
                    __Vdly__top__DOT__i1__DOT__nextdata_n = 1U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__i1__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->top__DOT__i1__DOT__count))) {
                if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__i1__DOT__buffer)) 
                                  & (IData)(vlSelf->ps2_data)) 
                                 & VL_REDXOR_32((0x1ffU 
                                                 & ((IData)(vlSelf->top__DOT__i1__DOT__buffer) 
                                                    >> 1U)))))) {
                    if ((0xf0U == (0xffU & ((IData)(vlSelf->top__DOT__i1__DOT__buffer) 
                                            >> 1U)))) {
                        __Vdly__top__DOT__press_count 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlSelf->top__DOT__press_count)));
                        __Vdly__top__DOT__close = 3U;
                    } else {
                        __Vdly__top__DOT__close = (2U 
                                                   & ((IData)(vlSelf->top__DOT__close) 
                                                      << 1U));
                    }
                    __Vdlyvval__top__DOT__i1__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelf->top__DOT__i1__DOT__buffer) 
                                    >> 1U));
                    __Vdlyvset__top__DOT__i1__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__top__DOT__i1__DOT__fifo__v0 
                        = vlSelf->top__DOT__i1__DOT__w_ptr;
                    vlSelf->top__DOT__i1__DOT__ready = 1U;
                    VL_WRITEF("receive %x %b %x\n",
                              8,(0xffU & ((IData)(vlSelf->top__DOT__i1__DOT__buffer) 
                                          >> 1U)),2,
                              (IData)(vlSelf->top__DOT__close),
                              8,vlSelf->top__DOT__press_count);
                    __Vdly__top__DOT__i1__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__i1__DOT__w_ptr)));
                    vlSelf->overflow = ((IData)(vlSelf->overflow) 
                                        | ((IData)(vlSelf->top__DOT__i1__DOT__r_ptr) 
                                           == (7U & 
                                               ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__i1__DOT__w_ptr)))));
                }
                __Vdly__top__DOT__i1__DOT__count = 0U;
            } else {
                vlSelf->top__DOT__i1__DOT____Vlvbound_h1a91ade8__0 
                    = vlSelf->ps2_data;
                if (VL_LIKELY((9U >= (IData)(vlSelf->top__DOT__i1__DOT__count)))) {
                    vlSelf->top__DOT__i1__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__i1__DOT__count))) 
                            & (IData)(vlSelf->top__DOT__i1__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->top__DOT__i1__DOT____Vlvbound_h1a91ade8__0) 
                                        << (IData)(vlSelf->top__DOT__i1__DOT__count))));
                }
                __Vdly__top__DOT__i1__DOT__count = 
                    (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__i1__DOT__count)));
            }
        }
    } else {
        __Vdly__top__DOT__press_count = 0U;
        __Vdly__top__DOT__i1__DOT__count = 0U;
        __Vdly__top__DOT__i1__DOT__w_ptr = 0U;
        __Vdly__top__DOT__i1__DOT__r_ptr = 0U;
        vlSelf->overflow = 0U;
        vlSelf->top__DOT__i1__DOT__ready = 0U;
        __Vdly__top__DOT__i1__DOT__nextdata_n = 0U;
    }
    vlSelf->top__DOT__i1__DOT__nextdata_n = __Vdly__top__DOT__i1__DOT__nextdata_n;
    vlSelf->top__DOT__i1__DOT__w_ptr = __Vdly__top__DOT__i1__DOT__w_ptr;
    vlSelf->top__DOT__i1__DOT__ps2_clk_sync = __Vdly__top__DOT__i1__DOT__ps2_clk_sync;
    vlSelf->top__DOT__i1__DOT__count = __Vdly__top__DOT__i1__DOT__count;
    vlSelf->top__DOT__press_count = __Vdly__top__DOT__press_count;
    vlSelf->top__DOT__i1__DOT__r_ptr = __Vdly__top__DOT__i1__DOT__r_ptr;
    vlSelf->top__DOT__close = __Vdly__top__DOT__close;
    if (__Vdlyvset__top__DOT__i1__DOT__fifo__v0) {
        vlSelf->top__DOT__i1__DOT__fifo[__Vdlyvdim0__top__DOT__i1__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__i1__DOT__fifo__v0;
    }
    vlSelf->top__DOT__y_1 = vlSelf->top__DOT__i1__DOT__fifo
        [vlSelf->top__DOT__i1__DOT__r_ptr];
    vlSelf->top__DOT__dout = vlSelf->top__DOT__i6__DOT__rom
        [vlSelf->top__DOT__y_1];
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
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i2__DOT__y = 0x9eU;
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
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i3__DOT__y = 0x9eU;
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
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->top__DOT__i4__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->top__DOT__data_3))) {
        if ((4U & (IData)(vlSelf->top__DOT__data_3))) {
            if ((2U & (IData)(vlSelf->top__DOT__data_3))) {
                if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x8eU;
                } else {
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i4__DOT__y = 0x9eU;
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
                vlSelf->top__DOT__i4__DOT__y = 0x7aU;
            } else {
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
                vlSelf->top__DOT__i4__DOT__y = 0x9cU;
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__data_3))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
                vlSelf->top__DOT__i4__DOT__y = 0x3eU;
            } else {
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
                vlSelf->top__DOT__i4__DOT__y = 0xeeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
            vlSelf->top__DOT__i4__DOT__y = 0xf6U;
        } else {
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
            vlSelf->top__DOT__i4__DOT__y = 0xfeU;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__data_3))) {
        if ((2U & (IData)(vlSelf->top__DOT__data_3))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
                vlSelf->top__DOT__i4__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
                vlSelf->top__DOT__i4__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
            vlSelf->top__DOT__i4__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
            vlSelf->top__DOT__i4__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__data_3))) {
        if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
            vlSelf->top__DOT__i4__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
            vlSelf->top__DOT__i4__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__data_3))) {
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
        vlSelf->top__DOT__i4__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
        vlSelf->top__DOT__i4__DOT__y = 0xfcU;
    }
    vlSelf->seg_3 = (0xffU & (~ (IData)(vlSelf->top__DOT__i4__DOT__y)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->top__DOT__i5__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->top__DOT__data_4))) {
        if ((4U & (IData)(vlSelf->top__DOT__data_4))) {
            if ((2U & (IData)(vlSelf->top__DOT__data_4))) {
                if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x8eU;
                } else {
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i5__DOT__y = 0x9eU;
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
                vlSelf->top__DOT__i5__DOT__y = 0x7aU;
            } else {
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
                vlSelf->top__DOT__i5__DOT__y = 0x9cU;
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__data_4))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
                vlSelf->top__DOT__i5__DOT__y = 0x3eU;
            } else {
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
                vlSelf->top__DOT__i5__DOT__y = 0xeeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
            vlSelf->top__DOT__i5__DOT__y = 0xf6U;
        } else {
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
            vlSelf->top__DOT__i5__DOT__y = 0xfeU;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__data_4))) {
        if ((2U & (IData)(vlSelf->top__DOT__data_4))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
                vlSelf->top__DOT__i5__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
                vlSelf->top__DOT__i5__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
            vlSelf->top__DOT__i5__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
            vlSelf->top__DOT__i5__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__data_4))) {
        if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
            vlSelf->top__DOT__i5__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
            vlSelf->top__DOT__i5__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__data_4))) {
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
        vlSelf->top__DOT__i5__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
        vlSelf->top__DOT__i5__DOT__y = 0xfcU;
    }
    vlSelf->seg_4 = (0xffU & (~ (IData)(vlSelf->top__DOT__i5__DOT__y)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__5(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__5\n"); );
    // Body
    vlSelf->top__DOT__i7__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->top__DOT__data_5))) {
        if ((4U & (IData)(vlSelf->top__DOT__data_5))) {
            if ((2U & (IData)(vlSelf->top__DOT__data_5))) {
                if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x8eU;
                } else {
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i7__DOT__y = 0x9eU;
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
                vlSelf->top__DOT__i7__DOT__y = 0x7aU;
            } else {
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
                vlSelf->top__DOT__i7__DOT__y = 0x9cU;
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__data_5))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
                vlSelf->top__DOT__i7__DOT__y = 0x3eU;
            } else {
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
                vlSelf->top__DOT__i7__DOT__y = 0xeeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
            vlSelf->top__DOT__i7__DOT__y = 0xf6U;
        } else {
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
            vlSelf->top__DOT__i7__DOT__y = 0xfeU;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__data_5))) {
        if ((2U & (IData)(vlSelf->top__DOT__data_5))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
                vlSelf->top__DOT__i7__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
                vlSelf->top__DOT__i7__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
            vlSelf->top__DOT__i7__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
            vlSelf->top__DOT__i7__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__data_5))) {
        if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
            vlSelf->top__DOT__i7__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
            vlSelf->top__DOT__i7__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__data_5))) {
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
        vlSelf->top__DOT__i7__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
        vlSelf->top__DOT__i7__DOT__y = 0xfcU;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__6(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__6\n"); );
    // Body
    vlSelf->top__DOT__i8__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->top__DOT__data_6))) {
        if ((4U & (IData)(vlSelf->top__DOT__data_6))) {
            if ((2U & (IData)(vlSelf->top__DOT__data_6))) {
                if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x8eU;
                } else {
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                    vlSelf->top__DOT__i8__DOT__y = 0x9eU;
                }
            } else if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
                vlSelf->top__DOT__i8__DOT__y = 0x7aU;
            } else {
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
                vlSelf->top__DOT__i8__DOT__y = 0x9cU;
            }
        } else if ((2U & (IData)(vlSelf->top__DOT__data_6))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
                vlSelf->top__DOT__i8__DOT__y = 0x3eU;
            } else {
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
                vlSelf->top__DOT__i8__DOT__y = 0xeeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
            vlSelf->top__DOT__i8__DOT__y = 0xf6U;
        } else {
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
            vlSelf->top__DOT__i8__DOT__y = 0xfeU;
        }
    } else if ((4U & (IData)(vlSelf->top__DOT__data_6))) {
        if ((2U & (IData)(vlSelf->top__DOT__data_6))) {
            if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
                vlSelf->top__DOT__i8__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
                vlSelf->top__DOT__i8__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
            vlSelf->top__DOT__i8__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
            vlSelf->top__DOT__i8__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->top__DOT__data_6))) {
        if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
            vlSelf->top__DOT__i8__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
            vlSelf->top__DOT__i8__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->top__DOT__data_6))) {
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
        vlSelf->top__DOT__i8__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
        vlSelf->top__DOT__i8__DOT__y = 0xfcU;
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__7(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__7\n"); );
    // Body
    vlSelf->top__DOT__data_1 = (0xfU & ((IData)(vlSelf->top__DOT__y_1) 
                                        >> 4U));
    vlSelf->top__DOT__data_2 = (0xfU & (IData)(vlSelf->top__DOT__y_1));
    vlSelf->top__DOT__data_3 = (0xfU & ((IData)(vlSelf->top__DOT__press_count) 
                                        >> 4U));
    vlSelf->top__DOT__data_4 = (0xfU & (IData)(vlSelf->top__DOT__press_count));
    vlSelf->top__DOT__data_5 = (0xfU & ((IData)(vlSelf->top__DOT__dout) 
                                        >> 4U));
    vlSelf->top__DOT__data_6 = (0xfU & (IData)(vlSelf->top__DOT__dout));
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->seg_1 = ((IData)(vlSelf->rst) ? ((2U & (IData)(vlSelf->top__DOT__close))
                                              ? 0xffU
                                              : (0xffU 
                                                 & (~ (IData)(vlSelf->top__DOT__i2__DOT__y))))
                      : 0xffU);
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->seg_2 = ((IData)(vlSelf->rst) ? ((2U & (IData)(vlSelf->top__DOT__close))
                                              ? 0xffU
                                              : (0xffU 
                                                 & (~ (IData)(vlSelf->top__DOT__i3__DOT__y))))
                      : 0xffU);
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    // Body
    vlSelf->seg_5 = ((IData)(vlSelf->rst) ? ((2U & (IData)(vlSelf->top__DOT__close))
                                              ? 0xffU
                                              : (0xffU 
                                                 & (~ (IData)(vlSelf->top__DOT__i7__DOT__y))))
                      : 0xffU);
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    // Body
    vlSelf->seg_6 = ((IData)(vlSelf->rst) ? ((2U & (IData)(vlSelf->top__DOT__close))
                                              ? 0xffU
                                              : (0xffU 
                                                 & (~ (IData)(vlSelf->top__DOT__i8__DOT__y))))
                      : 0xffU);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        Vtop___024root___nba_sequent__TOP__5(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        Vtop___024root___nba_sequent__TOP__6(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__7(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(2U))) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(5U))) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(6U))) {
        Vtop___024root___nba_comb__TOP__3(vlSelf);
    }
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
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
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<7> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 114, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
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
                    VL_FATAL_MT("vsrc/top.v", 114, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 114, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG
