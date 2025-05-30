// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__x = vlSelf->x;
    vlSelf->__Vtrigrprev__TOP__y = vlSelf->y;
    vlSelf->__Vtrigrprev__TOP__result = vlSelf->result;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->smg_4 = 0xffU;
    vlSelf->smg_5 = 0xffU;
    vlSelf->smg_6 = 0xffU;
    vlSelf->smg_7 = 0xffU;
    vlSelf->smg_8 = 0xffU;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 82, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
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
    vlSelf->smg_1 = (0xffU & (~ (IData)(vlSelf->top__DOT__i4__DOT__y)));
    vlSelf->smg_2 = (0xffU & (~ (IData)(vlSelf->top__DOT__i5__DOT__y)));
    vlSelf->smg_3 = (0xffU & (~ (IData)(vlSelf->top__DOT__i6__DOT__y)));
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

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([changed] x)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] y)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] result)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([changed] x)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] y)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] result)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x = VL_RAND_RESET_I(4);
    vlSelf->y = VL_RAND_RESET_I(4);
    vlSelf->sw = VL_RAND_RESET_I(3);
    vlSelf->result = VL_RAND_RESET_I(4);
    vlSelf->Carry = VL_RAND_RESET_I(1);
    vlSelf->Overflow = VL_RAND_RESET_I(1);
    vlSelf->Zero = VL_RAND_RESET_I(1);
    vlSelf->smg_1 = VL_RAND_RESET_I(8);
    vlSelf->smg_2 = VL_RAND_RESET_I(8);
    vlSelf->smg_3 = VL_RAND_RESET_I(8);
    vlSelf->smg_4 = VL_RAND_RESET_I(8);
    vlSelf->smg_5 = VL_RAND_RESET_I(8);
    vlSelf->smg_6 = VL_RAND_RESET_I(8);
    vlSelf->smg_7 = VL_RAND_RESET_I(8);
    vlSelf->smg_8 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i3__DOT__addResult = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__i3__DOT__subResult = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__i4__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i4__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i5__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i5__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i6__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i6__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigrprev__TOP__x = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__y = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__result = VL_RAND_RESET_I(4);
    vlSelf->__VactDidInit = 0;
}
