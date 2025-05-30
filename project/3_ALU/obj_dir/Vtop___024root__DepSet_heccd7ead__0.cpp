// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ top__DOT__i3__DOT___io_out_T_13;
    top__DOT__i3__DOT___io_out_T_13 = 0;
    CData/*3:0*/ top__DOT__i3__DOT___io_out_T_15;
    top__DOT__i3__DOT___io_out_T_15 = 0;
    CData/*3:0*/ top__DOT__i3__DOT___io_out_T_17;
    top__DOT__i3__DOT___io_out_T_17 = 0;
    CData/*0:0*/ top__DOT__i3__DOT___io_overflow_T_7;
    top__DOT__i3__DOT___io_overflow_T_7 = 0;
    CData/*0:0*/ top__DOT__i3__DOT___io_overflow_T_15;
    top__DOT__i3__DOT___io_overflow_T_15 = 0;
    // Body
    top__DOT__i3__DOT___io_out_T_13 = ((IData)(vlSelf->x) 
                                       & (IData)(vlSelf->y));
    top__DOT__i3__DOT___io_out_T_15 = ((IData)(vlSelf->x) 
                                       | (IData)(vlSelf->y));
    top__DOT__i3__DOT___io_out_T_17 = ((IData)(vlSelf->x) 
                                       ^ (IData)(vlSelf->y));
    vlSelf->top__DOT__i3__DOT__addResult = (0x1fU & 
                                            (VL_EXTENDS_II(5,4, (IData)(vlSelf->x)) 
                                             + VL_EXTENDS_II(5,4, (IData)(vlSelf->y))));
    vlSelf->top__DOT__i3__DOT__subResult = (0x1fU & 
                                            (VL_EXTENDS_II(5,4, (IData)(vlSelf->x)) 
                                             - VL_EXTENDS_II(5,4, (IData)(vlSelf->y))));
    top__DOT__i3__DOT___io_overflow_T_7 = (((1U & ((IData)(vlSelf->x) 
                                                   >> 3U)) 
                                            == (1U 
                                                & ((IData)(vlSelf->y) 
                                                   >> 3U))) 
                                           & ((1U & 
                                               ((IData)(vlSelf->x) 
                                                >> 3U)) 
                                              != (1U 
                                                  & ((IData)(vlSelf->top__DOT__i3__DOT__addResult) 
                                                     >> 3U))));
    vlSelf->Carry = (1U & ((((IData)(1U) << (IData)(vlSelf->sw)) 
                            & ((IData)(vlSelf->top__DOT__i3__DOT__addResult) 
                               >> 4U)) | (0x7fU & (
                                                   (((IData)(1U) 
                                                     << (IData)(vlSelf->sw)) 
                                                    >> 1U) 
                                                   & ((IData)(vlSelf->top__DOT__i3__DOT__subResult) 
                                                      >> 4U)))));
    top__DOT__i3__DOT___io_overflow_T_15 = (((1U & 
                                              ((IData)(vlSelf->x) 
                                               >> 3U)) 
                                             != (1U 
                                                 & ((IData)(vlSelf->y) 
                                                    >> 3U))) 
                                            & ((1U 
                                                & ((IData)(vlSelf->x) 
                                                   >> 3U)) 
                                               != (1U 
                                                   & ((IData)(vlSelf->top__DOT__i3__DOT__subResult) 
                                                      >> 3U))));
    vlSelf->result = (0xfU & ((((((1U & ((IData)(1U) 
                                         << (IData)(vlSelf->sw)))
                                   ? (IData)(vlSelf->top__DOT__i3__DOT__addResult)
                                   : 0U) | ((2U & ((IData)(1U) 
                                                   << (IData)(vlSelf->sw)))
                                             ? (IData)(vlSelf->top__DOT__i3__DOT__subResult)
                                             : 0U)) 
                                | ((4U & ((IData)(1U) 
                                          << (IData)(vlSelf->sw)))
                                    ? ((0x10U & ((IData)(top__DOT__i3__DOT___io_out_T_13) 
                                                 << 1U)) 
                                       | (IData)(top__DOT__i3__DOT___io_out_T_13))
                                    : 0U)) | ((8U & 
                                               ((IData)(1U) 
                                                << (IData)(vlSelf->sw)))
                                               ? ((0x10U 
                                                   & ((IData)(top__DOT__i3__DOT___io_out_T_15) 
                                                      << 1U)) 
                                                  | (IData)(top__DOT__i3__DOT___io_out_T_15))
                                               : 0U)) 
                              | ((0x10U & ((IData)(1U) 
                                           << (IData)(vlSelf->sw)))
                                  ? ((0x10U & ((IData)(top__DOT__i3__DOT___io_out_T_17) 
                                               << 1U)) 
                                     | (IData)(top__DOT__i3__DOT___io_out_T_17))
                                  : 0U)));
    vlSelf->Overflow = ((((IData)(1U) << (IData)(vlSelf->sw)) 
                         & (IData)(top__DOT__i3__DOT___io_overflow_T_7)) 
                        | (0x7fU & ((((IData)(1U) << (IData)(vlSelf->sw)) 
                                     >> 1U) & (IData)(top__DOT__i3__DOT___io_overflow_T_15))));
    vlSelf->Zero = (0U == (IData)(vlSelf->result));
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
    // Body
    vlSelf->top__DOT__i4__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->x))) {
        if ((4U & (IData)(vlSelf->x))) {
            if ((2U & (IData)(vlSelf->x))) {
                if ((1U & (IData)(vlSelf->x))) {
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                    vlSelf->top__DOT__i4__DOT__y = 0x61U;
                } else {
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i4__DOT__y = 0xdbU;
                }
            } else if ((1U & (IData)(vlSelf->x))) {
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
                vlSelf->top__DOT__i4__DOT__y = 0xf3U;
            } else {
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
                vlSelf->top__DOT__i4__DOT__y = 0x67U;
            }
        } else if ((2U & (IData)(vlSelf->x))) {
            if ((1U & (IData)(vlSelf->x))) {
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
                vlSelf->top__DOT__i4__DOT__y = 0xb7U;
            } else {
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
                vlSelf->top__DOT__i4__DOT__y = 0xbfU;
            }
        } else if ((1U & (IData)(vlSelf->x))) {
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
            vlSelf->top__DOT__i4__DOT__y = 0xe1U;
        } else {
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
            vlSelf->top__DOT__i4__DOT__y = 0xffU;
        }
    } else if ((4U & (IData)(vlSelf->x))) {
        if ((2U & (IData)(vlSelf->x))) {
            if ((1U & (IData)(vlSelf->x))) {
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
        } else if ((1U & (IData)(vlSelf->x))) {
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
    } else if ((2U & (IData)(vlSelf->x))) {
        if ((1U & (IData)(vlSelf->x))) {
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
    } else if ((1U & (IData)(vlSelf->x))) {
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
    vlSelf->smg_1 = (0xffU & (~ (IData)(vlSelf->top__DOT__i4__DOT__y)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__i5__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->y))) {
        if ((4U & (IData)(vlSelf->y))) {
            if ((2U & (IData)(vlSelf->y))) {
                if ((1U & (IData)(vlSelf->y))) {
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                    vlSelf->top__DOT__i5__DOT__y = 0x61U;
                } else {
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i5__DOT__y = 0xdbU;
                }
            } else if ((1U & (IData)(vlSelf->y))) {
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
                vlSelf->top__DOT__i5__DOT__y = 0xf3U;
            } else {
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
                vlSelf->top__DOT__i5__DOT__y = 0x67U;
            }
        } else if ((2U & (IData)(vlSelf->y))) {
            if ((1U & (IData)(vlSelf->y))) {
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
                vlSelf->top__DOT__i5__DOT__y = 0xb7U;
            } else {
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
                vlSelf->top__DOT__i5__DOT__y = 0xbfU;
            }
        } else if ((1U & (IData)(vlSelf->y))) {
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
            vlSelf->top__DOT__i5__DOT__y = 0xe1U;
        } else {
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
            vlSelf->top__DOT__i5__DOT__y = 0xffU;
        }
    } else if ((4U & (IData)(vlSelf->y))) {
        if ((2U & (IData)(vlSelf->y))) {
            if ((1U & (IData)(vlSelf->y))) {
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
        } else if ((1U & (IData)(vlSelf->y))) {
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
    } else if ((2U & (IData)(vlSelf->y))) {
        if ((1U & (IData)(vlSelf->y))) {
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
    } else if ((1U & (IData)(vlSelf->y))) {
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
    vlSelf->smg_2 = (0xffU & (~ (IData)(vlSelf->top__DOT__i5__DOT__y)));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__i6__DOT__i = 8U;
    if ((8U & (IData)(vlSelf->result))) {
        if ((4U & (IData)(vlSelf->result))) {
            if ((2U & (IData)(vlSelf->result))) {
                if ((1U & (IData)(vlSelf->result))) {
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                    vlSelf->top__DOT__i6__DOT__y = 0x61U;
                } else {
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                    vlSelf->top__DOT__i6__DOT__y = 0xdbU;
                }
            } else if ((1U & (IData)(vlSelf->result))) {
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
                vlSelf->top__DOT__i6__DOT__y = 0xf3U;
            } else {
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
                vlSelf->top__DOT__i6__DOT__y = 0x67U;
            }
        } else if ((2U & (IData)(vlSelf->result))) {
            if ((1U & (IData)(vlSelf->result))) {
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
                vlSelf->top__DOT__i6__DOT__y = 0xb7U;
            } else {
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
                vlSelf->top__DOT__i6__DOT__y = 0xbfU;
            }
        } else if ((1U & (IData)(vlSelf->result))) {
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
            vlSelf->top__DOT__i6__DOT__y = 0xe1U;
        } else {
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
            vlSelf->top__DOT__i6__DOT__y = 0xffU;
        }
    } else if ((4U & (IData)(vlSelf->result))) {
        if ((2U & (IData)(vlSelf->result))) {
            if ((1U & (IData)(vlSelf->result))) {
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
                vlSelf->top__DOT__i6__DOT__y = 0xe0U;
            } else {
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
                vlSelf->top__DOT__i6__DOT__y = 0xbeU;
            }
        } else if ((1U & (IData)(vlSelf->result))) {
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
            vlSelf->top__DOT__i6__DOT__y = 0xb6U;
        } else {
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
            vlSelf->top__DOT__i6__DOT__y = 0x66U;
        }
    } else if ((2U & (IData)(vlSelf->result))) {
        if ((1U & (IData)(vlSelf->result))) {
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
            vlSelf->top__DOT__i6__DOT__y = 0xf2U;
        } else {
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
            vlSelf->top__DOT__i6__DOT__y = 0xdaU;
        }
    } else if ((1U & (IData)(vlSelf->result))) {
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
        vlSelf->top__DOT__i6__DOT__y = 0x60U;
    } else {
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
        vlSelf->top__DOT__i6__DOT__y = 0xfcU;
    }
    vlSelf->smg_3 = (0xffU & (~ (IData)(vlSelf->top__DOT__i6__DOT__y)));
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
    VlTriggerVec<3> __VpreTriggered;
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
                VL_FATAL_MT("vsrc/top.v", 82, "", "Input combinational region did not converge.");
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
                    VL_FATAL_MT("vsrc/top.v", 82, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 82, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->x & 0xf0U))) {
        Verilated::overWidthError("x");}
    if (VL_UNLIKELY((vlSelf->y & 0xf0U))) {
        Verilated::overWidthError("y");}
    if (VL_UNLIKELY((vlSelf->sw & 0xf8U))) {
        Verilated::overWidthError("sw");}
}
#endif  // VL_DEBUG
