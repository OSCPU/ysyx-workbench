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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->y = ((0x10U & (IData)(vlSelf->top__DOT__operate))
                  ? ((8U & (IData)(vlSelf->top__DOT__operate))
                      ? ((4U & (IData)(vlSelf->top__DOT__operate))
                          ? ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? (0x80U & (IData)(vlSelf->x))
                                  : (0x80U & ((IData)(vlSelf->x) 
                                              << 7U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0xfeU & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->x) 
                                                              >> 7U)))) 
                                               << 1U)) 
                                     | (1U & ((IData)(vlSelf->x) 
                                              >> 7U)))
                                  : (1U & ((IData)(vlSelf->x) 
                                           >> 7U))))
                          : ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x40U & ((IData)(vlSelf->x) 
                                                 << 6U)))
                                  : (0xc0U & ((IData)(vlSelf->x) 
                                              << 6U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0xfcU & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->x) 
                                                              >> 7U)))) 
                                               << 2U)) 
                                     | (3U & ((IData)(vlSelf->x) 
                                              >> 6U)))
                                  : (3U & ((IData)(vlSelf->x) 
                                           >> 6U)))))
                      : ((4U & (IData)(vlSelf->top__DOT__operate))
                          ? ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x60U & ((IData)(vlSelf->x) 
                                                 << 5U)))
                                  : (0xe0U & ((IData)(vlSelf->x) 
                                              << 5U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0xf8U & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->x) 
                                                              >> 7U)))) 
                                               << 3U)) 
                                     | (7U & ((IData)(vlSelf->x) 
                                              >> 5U)))
                                  : (7U & ((IData)(vlSelf->x) 
                                           >> 5U))))
                          : ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x70U & ((IData)(vlSelf->x) 
                                                 << 4U)))
                                  : (0xf0U & ((IData)(vlSelf->x) 
                                              << 4U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0xf0U & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->x) 
                                                              >> 7U)))) 
                                               << 4U)) 
                                     | (0xfU & ((IData)(vlSelf->x) 
                                                >> 4U)))
                                  : (0xfU & ((IData)(vlSelf->x) 
                                             >> 4U))))))
                  : ((8U & (IData)(vlSelf->top__DOT__operate))
                      ? ((4U & (IData)(vlSelf->top__DOT__operate))
                          ? ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x78U & ((IData)(vlSelf->x) 
                                                 << 3U)))
                                  : (0xf8U & ((IData)(vlSelf->x) 
                                              << 3U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0xe0U & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->x) 
                                                              >> 7U)))) 
                                               << 5U)) 
                                     | (0x1fU & ((IData)(vlSelf->x) 
                                                 >> 3U)))
                                  : (0x1fU & ((IData)(vlSelf->x) 
                                              >> 3U))))
                          : ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x7cU & ((IData)(vlSelf->x) 
                                                 << 2U)))
                                  : (0xfcU & ((IData)(vlSelf->x) 
                                              << 2U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0xc0U & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->x) 
                                                              >> 7U)))) 
                                               << 6U)) 
                                     | (0x3fU & ((IData)(vlSelf->x) 
                                                 >> 2U)))
                                  : (0x3fU & ((IData)(vlSelf->x) 
                                              >> 2U)))))
                      : ((4U & (IData)(vlSelf->top__DOT__operate))
                          ? ((2U & (IData)(vlSelf->top__DOT__operate))
                              ? ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x7eU & ((IData)(vlSelf->x) 
                                                 << 1U)))
                                  : (0xfeU & ((IData)(vlSelf->x) 
                                              << 1U)))
                              : ((1U & (IData)(vlSelf->top__DOT__operate))
                                  ? ((0x80U & (IData)(vlSelf->x)) 
                                     | (0x7fU & ((IData)(vlSelf->x) 
                                                 >> 1U)))
                                  : (0x7fU & ((IData)(vlSelf->x) 
                                              >> 1U))))
                          : (IData)(vlSelf->x))));
    vlSelf->top__DOT__operate = (((IData)(vlSelf->shamt) 
                                  << 2U) | (((IData)(vlSelf->LR) 
                                             << 1U) 
                                            | (IData)(vlSelf->AL)));
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
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
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 1, "", "Active region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 1, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->shamt & 0xf8U))) {
        Verilated::overWidthError("shamt");}
    if (VL_UNLIKELY((vlSelf->LR & 0xfeU))) {
        Verilated::overWidthError("LR");}
    if (VL_UNLIKELY((vlSelf->AL & 0xfeU))) {
        Verilated::overWidthError("AL");}
}
#endif  // VL_DEBUG
