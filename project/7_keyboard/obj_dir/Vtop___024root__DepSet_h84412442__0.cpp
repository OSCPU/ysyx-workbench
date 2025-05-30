// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->top__DOT__data_1) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__data_1));
    vlSelf->__VactTriggered.at(2U) = ((IData)(vlSelf->top__DOT__data_2) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__data_2));
    vlSelf->__VactTriggered.at(3U) = ((IData)(vlSelf->top__DOT__data_3) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__data_3));
    vlSelf->__VactTriggered.at(4U) = ((IData)(vlSelf->top__DOT__data_4) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__data_4));
    vlSelf->__VactTriggered.at(5U) = ((IData)(vlSelf->top__DOT__data_5) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__data_5));
    vlSelf->__VactTriggered.at(6U) = ((IData)(vlSelf->top__DOT__data_6) 
                                      != (IData)(vlSelf->__Vtrigrprev__TOP__top__DOT__data_6));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_1 = vlSelf->top__DOT__data_1;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_2 = vlSelf->top__DOT__data_2;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_3 = vlSelf->top__DOT__data_3;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_4 = vlSelf->top__DOT__data_4;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_5 = vlSelf->top__DOT__data_5;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_6 = vlSelf->top__DOT__data_6;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(1U) = 1U;
        vlSelf->__VactTriggered.at(2U) = 1U;
        vlSelf->__VactTriggered.at(3U) = 1U;
        vlSelf->__VactTriggered.at(4U) = 1U;
        vlSelf->__VactTriggered.at(5U) = 1U;
        vlSelf->__VactTriggered.at(6U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}
