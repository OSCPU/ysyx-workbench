// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25020077_top.h for the primary calling header

#include "Vysyx_25020077_top__pch.h"
#include "Vysyx_25020077_top___024root.h"

VL_ATTR_COLD void Vysyx_25020077_top___024root___eval_static(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_static\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vysyx_25020077_top___024root___eval_initial(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_initial\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vysyx_25020077_top___024root___eval_final(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_final\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25020077_top___024root___dump_triggers__stl(Vysyx_25020077_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vysyx_25020077_top___024root___eval_phase__stl(Vysyx_25020077_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25020077_top___024root___eval_settle(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_settle\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vysyx_25020077_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/ysyx_25020077_top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vysyx_25020077_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25020077_top___024root___dump_triggers__stl(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___dump_triggers__stl\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_25020077_top___024root___stl_sequent__TOP__0(Vysyx_25020077_top___024root* vlSelf);
VL_ATTR_COLD void Vysyx_25020077_top___024root____Vm_traceActivitySetAll(Vysyx_25020077_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25020077_top___024root___eval_stl(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_stl\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vysyx_25020077_top___024root___stl_sequent__TOP__0(vlSelf);
        Vysyx_25020077_top___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vysyx_25020077_top___024root___stl_sequent__TOP__0(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___stl_sequent__TOP__0\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdeeptemp_h20c20ccb__0;
    IData/*31:0*/ __Vdeeptemp_h53fb63df__0;
    IData/*31:0*/ __Vdeeptemp_h474464c7__0;
    IData/*31:0*/ __Vdeeptemp_h8729ea13__0;
    IData/*31:0*/ __Vdeeptemp_hcc701b89__0;
    IData/*31:0*/ __Vdeeptemp_h46af4f1d__0;
    // Body
    __Vdeeptemp_h20c20ccb__0 = ((0x76U == (0xffU & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                 ? 0x76U : ((0x75U 
                                             == (0xffU 
                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                             ? 0x75U
                                             : ((0x74U 
                                                 == 
                                                 (0xffU 
                                                  & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                 ? 0x74U
                                                 : 
                                                ((0x73U 
                                                  == 
                                                  (0xffU 
                                                   & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                  ? 0x73U
                                                  : 
                                                 ((0x72U 
                                                   == 
                                                   (0xffU 
                                                    & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                   ? 0x72U
                                                   : 
                                                  ((0x71U 
                                                    == 
                                                    (0xffU 
                                                     & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                    ? 0x71U
                                                    : 
                                                   ((0x70U 
                                                     == 
                                                     (0xffU 
                                                      & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                     ? 0x70U
                                                     : 
                                                    ((0x6fU 
                                                      == 
                                                      (0xffU 
                                                       & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                      ? 0x6fU
                                                      : 
                                                     ((0x6eU 
                                                       == 
                                                       (0xffU 
                                                        & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                       ? 0x6eU
                                                       : 
                                                      ((0x6dU 
                                                        == 
                                                        (0xffU 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                        ? 0x6dU
                                                        : 
                                                       ((0x6cU 
                                                         == 
                                                         (0xffU 
                                                          & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                         ? 0x6cU
                                                         : 
                                                        ((0x6bU 
                                                          == 
                                                          (0xffU 
                                                           & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                          ? 0x6bU
                                                          : 
                                                         ((0x6aU 
                                                           == 
                                                           (0xffU 
                                                            & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                           ? 0x6aU
                                                           : 
                                                          ((0x69U 
                                                            == 
                                                            (0xffU 
                                                             & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                            ? 0x69U
                                                            : 
                                                           ((0x68U 
                                                             == 
                                                             (0xffU 
                                                              & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                             ? 0x68U
                                                             : 
                                                            ((0x67U 
                                                              == 
                                                              (0xffU 
                                                               & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                              ? 0x67U
                                                              : 
                                                             ((0x66U 
                                                               == 
                                                               (0xffU 
                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                               ? 0x66U
                                                               : 
                                                              ((0x65U 
                                                                == 
                                                                (0xffU 
                                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                ? 0x65U
                                                                : 
                                                               ((0x64U 
                                                                 == 
                                                                 (0xffU 
                                                                  & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                 ? 0x64U
                                                                 : 
                                                                ((0x63U 
                                                                  == 
                                                                  (0xffU 
                                                                   & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                  ? 0x63U
                                                                  : 
                                                                 ((0x62U 
                                                                   == 
                                                                   (0xffU 
                                                                    & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                   ? 0x62U
                                                                   : 
                                                                  ((0x61U 
                                                                    == 
                                                                    (0xffU 
                                                                     & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                    ? 0x61U
                                                                    : 
                                                                   ((0x60U 
                                                                     == 
                                                                     (0xffU 
                                                                      & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                     ? 0x60U
                                                                     : 
                                                                    ((0x5fU 
                                                                      == 
                                                                      (0xffU 
                                                                       & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                      ? 0x5fU
                                                                      : 
                                                                     ((0x5eU 
                                                                       == 
                                                                       (0xffU 
                                                                        & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                       ? 0x5eU
                                                                       : 
                                                                      ((0x5dU 
                                                                        == 
                                                                        (0xffU 
                                                                         & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                        ? 0x5dU
                                                                        : 
                                                                       ((0x5cU 
                                                                         == 
                                                                         (0xffU 
                                                                          & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                         ? 0x5cU
                                                                         : 
                                                                        ((0x5bU 
                                                                          == 
                                                                          (0xffU 
                                                                           & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                          ? 0x5bU
                                                                          : 
                                                                         ((0x5aU 
                                                                           == 
                                                                           (0xffU 
                                                                            & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                           ? 0x5aU
                                                                           : 
                                                                          ((0x59U 
                                                                            == 
                                                                            (0xffU 
                                                                             & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                            ? 0x59U
                                                                            : 
                                                                           ((0x58U 
                                                                             == 
                                                                             (0xffU 
                                                                              & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                             ? 0x58U
                                                                             : 
                                                                            ((0x57U 
                                                                              == 
                                                                              (0xffU 
                                                                               & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                              ? 0x57U
                                                                              : 
                                                                             ((0x56U 
                                                                               == 
                                                                               (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                               ? 0x56U
                                                                               : 
                                                                              ((0x55U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                ? 0x55U
                                                                                : 
                                                                               ((0x54U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x54U
                                                                                 : 
                                                                                ((0x53U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x53U
                                                                                 : 
                                                                                ((0x52U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x52U
                                                                                 : 
                                                                                ((0x51U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x51U
                                                                                 : 
                                                                                ((0x50U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x50U
                                                                                 : 
                                                                                ((0x4fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x4fU
                                                                                 : 
                                                                                ((0x4eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x4eU
                                                                                 : 
                                                                                ((0x4dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x4dU
                                                                                 : 
                                                                                ((0x4cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x4cU
                                                                                 : 
                                                                                ((0x4bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x4bU
                                                                                 : 
                                                                                ((0x4aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x4aU
                                                                                 : 
                                                                                ((0x49U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x49U
                                                                                 : 
                                                                                ((0x48U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x48U
                                                                                 : 
                                                                                ((0x47U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x47U
                                                                                 : 
                                                                                ((0x46U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x46U
                                                                                 : 
                                                                                ((0x45U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x45U
                                                                                 : 
                                                                                ((0x44U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x44U
                                                                                 : 
                                                                                ((0x43U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x43U
                                                                                 : 
                                                                                ((0x42U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x42U
                                                                                 : 
                                                                                ((0x41U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x41U
                                                                                 : 
                                                                                ((0x40U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x40U
                                                                                 : 
                                                                                ((0x3fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x3fU
                                                                                 : 
                                                                                ((0x3eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x3eU
                                                                                 : 
                                                                                ((0x3dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x3dU
                                                                                 : 
                                                                                ((0x3cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x3cU
                                                                                 : 
                                                                                ((0x3bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x3bU
                                                                                 : 
                                                                                ((0x3aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x3aU
                                                                                 : 
                                                                                ((0x39U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x39U
                                                                                 : 
                                                                                ((0x38U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x38U
                                                                                 : 
                                                                                ((0x37U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x37U
                                                                                 : 
                                                                                ((0x36U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x36U
                                                                                 : 
                                                                                ((0x35U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x35U
                                                                                 : 
                                                                                ((0x34U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x34U
                                                                                 : 
                                                                                ((0x33U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x33U
                                                                                 : 
                                                                                ((0x32U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x32U
                                                                                 : 
                                                                                ((0x31U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x31U
                                                                                 : 
                                                                                ((0x30U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x30U
                                                                                 : 
                                                                                ((0x2fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x2fU
                                                                                 : 
                                                                                ((0x2eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x2eU
                                                                                 : 
                                                                                ((0x2dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x2dU
                                                                                 : 
                                                                                ((0x2cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x2cU
                                                                                 : 
                                                                                ((0x2bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x2bU
                                                                                 : 
                                                                                ((0x2aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x2aU
                                                                                 : 
                                                                                ((0x29U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x29U
                                                                                 : 
                                                                                ((0x28U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x28U
                                                                                 : 
                                                                                ((0x27U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x27U
                                                                                 : 
                                                                                ((0x26U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x26U
                                                                                 : 
                                                                                ((0x25U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x25U
                                                                                 : 
                                                                                ((0x24U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x24U
                                                                                 : 
                                                                                ((0x23U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x23U
                                                                                 : 
                                                                                ((0x22U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x22U
                                                                                 : 
                                                                                ((0x21U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x21U
                                                                                 : 
                                                                                ((0x20U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x20U
                                                                                 : 
                                                                                ((0x1fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x1fU
                                                                                 : 
                                                                                ((0x1eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x1eU
                                                                                 : 
                                                                                ((0x1dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x1dU
                                                                                 : 
                                                                                ((0x1cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x1cU
                                                                                 : 
                                                                                ((0x1bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x1bU
                                                                                 : 
                                                                                ((0x1aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x1aU
                                                                                 : 
                                                                                ((0x19U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x19U
                                                                                 : 
                                                                                ((0x18U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x18U
                                                                                 : 
                                                                                ((0x17U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x17U
                                                                                 : 
                                                                                ((0x16U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x16U
                                                                                 : 
                                                                                ((0x15U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x15U
                                                                                 : 
                                                                                ((0x14U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x14U
                                                                                 : 
                                                                                ((0x13U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x13U
                                                                                 : 
                                                                                ((0x12U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x12U
                                                                                 : 
                                                                                ((0x11U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x11U
                                                                                 : 
                                                                                ((0x10U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x10U
                                                                                 : 
                                                                                ((0xfU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xfU
                                                                                 : 
                                                                                ((0xeU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xeU
                                                                                 : 
                                                                                ((0xdU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xdU
                                                                                 : 
                                                                                ((0xcU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xcU
                                                                                 : 
                                                                                ((0xbU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbU
                                                                                 : 
                                                                                ((0xaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xaU
                                                                                 : 
                                                                                ((9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 9U
                                                                                 : 
                                                                                ((8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 8U
                                                                                 : 
                                                                                ((7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 7U
                                                                                 : 
                                                                                ((6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 6U
                                                                                 : 
                                                                                ((5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 5U
                                                                                 : 
                                                                                ((4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 4U
                                                                                 : 
                                                                                ((3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 3U
                                                                                 : 
                                                                                ((2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 2U
                                                                                 : 
                                                                                ((1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 1U
                                                                                 : 0U))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vdeeptemp_h474464c7__0 = ((0xecU == (0xffU & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                 ? 0xecU : ((0xebU 
                                             == (0xffU 
                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                             ? 0xebU
                                             : ((0xeaU 
                                                 == 
                                                 (0xffU 
                                                  & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                 ? 0xeaU
                                                 : 
                                                ((0xe9U 
                                                  == 
                                                  (0xffU 
                                                   & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                  ? 0xe9U
                                                  : 
                                                 ((0xe8U 
                                                   == 
                                                   (0xffU 
                                                    & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                   ? 0xe8U
                                                   : 
                                                  ((0xe7U 
                                                    == 
                                                    (0xffU 
                                                     & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                    ? 0xe7U
                                                    : 
                                                   ((0xe6U 
                                                     == 
                                                     (0xffU 
                                                      & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                     ? 0xe6U
                                                     : 
                                                    ((0xe5U 
                                                      == 
                                                      (0xffU 
                                                       & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                      ? 0xe5U
                                                      : 
                                                     ((0xe4U 
                                                       == 
                                                       (0xffU 
                                                        & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                       ? 0xe4U
                                                       : 
                                                      ((0xe3U 
                                                        == 
                                                        (0xffU 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                        ? 0xe3U
                                                        : 
                                                       ((0xe2U 
                                                         == 
                                                         (0xffU 
                                                          & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                         ? 0xe2U
                                                         : 
                                                        ((0xe1U 
                                                          == 
                                                          (0xffU 
                                                           & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                          ? 0xe1U
                                                          : 
                                                         ((0xe0U 
                                                           == 
                                                           (0xffU 
                                                            & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                           ? 0xe0U
                                                           : 
                                                          ((0xdfU 
                                                            == 
                                                            (0xffU 
                                                             & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                            ? 0xdfU
                                                            : 
                                                           ((0xdeU 
                                                             == 
                                                             (0xffU 
                                                              & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                             ? 0xdeU
                                                             : 
                                                            ((0xddU 
                                                              == 
                                                              (0xffU 
                                                               & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                              ? 0xddU
                                                              : 
                                                             ((0xdcU 
                                                               == 
                                                               (0xffU 
                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                               ? 0xdcU
                                                               : 
                                                              ((0xdbU 
                                                                == 
                                                                (0xffU 
                                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                ? 0xdbU
                                                                : 
                                                               ((0xdaU 
                                                                 == 
                                                                 (0xffU 
                                                                  & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                 ? 0xdaU
                                                                 : 
                                                                ((0xd9U 
                                                                  == 
                                                                  (0xffU 
                                                                   & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                  ? 0xd9U
                                                                  : 
                                                                 ((0xd8U 
                                                                   == 
                                                                   (0xffU 
                                                                    & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                   ? 0xd8U
                                                                   : 
                                                                  ((0xd7U 
                                                                    == 
                                                                    (0xffU 
                                                                     & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                    ? 0xd7U
                                                                    : 
                                                                   ((0xd6U 
                                                                     == 
                                                                     (0xffU 
                                                                      & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                     ? 0xd6U
                                                                     : 
                                                                    ((0xd5U 
                                                                      == 
                                                                      (0xffU 
                                                                       & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                      ? 0xd5U
                                                                      : 
                                                                     ((0xd4U 
                                                                       == 
                                                                       (0xffU 
                                                                        & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                       ? 0xd4U
                                                                       : 
                                                                      ((0xd3U 
                                                                        == 
                                                                        (0xffU 
                                                                         & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                        ? 0xd3U
                                                                        : 
                                                                       ((0xd2U 
                                                                         == 
                                                                         (0xffU 
                                                                          & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                         ? 0xd2U
                                                                         : 
                                                                        ((0xd1U 
                                                                          == 
                                                                          (0xffU 
                                                                           & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                          ? 0xd1U
                                                                          : 
                                                                         ((0xd0U 
                                                                           == 
                                                                           (0xffU 
                                                                            & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                           ? 0xd0U
                                                                           : 
                                                                          ((0xcfU 
                                                                            == 
                                                                            (0xffU 
                                                                             & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                            ? 0xcfU
                                                                            : 
                                                                           ((0xceU 
                                                                             == 
                                                                             (0xffU 
                                                                              & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                             ? 0xceU
                                                                             : 
                                                                            ((0xcdU 
                                                                              == 
                                                                              (0xffU 
                                                                               & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                              ? 0xcdU
                                                                              : 
                                                                             ((0xccU 
                                                                               == 
                                                                               (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                               ? 0xccU
                                                                               : 
                                                                              ((0xcbU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                ? 0xcbU
                                                                                : 
                                                                               ((0xcaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xcaU
                                                                                 : 
                                                                                ((0xc9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc9U
                                                                                 : 
                                                                                ((0xc8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc8U
                                                                                 : 
                                                                                ((0xc7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc7U
                                                                                 : 
                                                                                ((0xc6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc6U
                                                                                 : 
                                                                                ((0xc5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc5U
                                                                                 : 
                                                                                ((0xc4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc4U
                                                                                 : 
                                                                                ((0xc3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc3U
                                                                                 : 
                                                                                ((0xc2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc2U
                                                                                 : 
                                                                                ((0xc1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc1U
                                                                                 : 
                                                                                ((0xc0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xc0U
                                                                                 : 
                                                                                ((0xbfU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbfU
                                                                                 : 
                                                                                ((0xbeU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbeU
                                                                                 : 
                                                                                ((0xbdU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbdU
                                                                                 : 
                                                                                ((0xbcU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbcU
                                                                                 : 
                                                                                ((0xbbU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbbU
                                                                                 : 
                                                                                ((0xbaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xbaU
                                                                                 : 
                                                                                ((0xb9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb9U
                                                                                 : 
                                                                                ((0xb8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb8U
                                                                                 : 
                                                                                ((0xb7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb7U
                                                                                 : 
                                                                                ((0xb6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb6U
                                                                                 : 
                                                                                ((0xb5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb5U
                                                                                 : 
                                                                                ((0xb4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb4U
                                                                                 : 
                                                                                ((0xb3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb3U
                                                                                 : 
                                                                                ((0xb2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb2U
                                                                                 : 
                                                                                ((0xb1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb1U
                                                                                 : 
                                                                                ((0xb0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xb0U
                                                                                 : 
                                                                                ((0xafU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xafU
                                                                                 : 
                                                                                ((0xaeU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xaeU
                                                                                 : 
                                                                                ((0xadU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xadU
                                                                                 : 
                                                                                ((0xacU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xacU
                                                                                 : 
                                                                                ((0xabU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xabU
                                                                                 : 
                                                                                ((0xaaU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xaaU
                                                                                 : 
                                                                                ((0xa9U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa9U
                                                                                 : 
                                                                                ((0xa8U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa8U
                                                                                 : 
                                                                                ((0xa7U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa7U
                                                                                 : 
                                                                                ((0xa6U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa6U
                                                                                 : 
                                                                                ((0xa5U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa5U
                                                                                 : 
                                                                                ((0xa4U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa4U
                                                                                 : 
                                                                                ((0xa3U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa3U
                                                                                 : 
                                                                                ((0xa2U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa2U
                                                                                 : 
                                                                                ((0xa1U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa1U
                                                                                 : 
                                                                                ((0xa0U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0xa0U
                                                                                 : 
                                                                                ((0x9fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x9fU
                                                                                 : 
                                                                                ((0x9eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x9eU
                                                                                 : 
                                                                                ((0x9dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x9dU
                                                                                 : 
                                                                                ((0x9cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x9cU
                                                                                 : 
                                                                                ((0x9bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x9bU
                                                                                 : 
                                                                                ((0x9aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x9aU
                                                                                 : 
                                                                                ((0x99U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x99U
                                                                                 : 
                                                                                ((0x98U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x98U
                                                                                 : 
                                                                                ((0x97U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x97U
                                                                                 : 
                                                                                ((0x96U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x96U
                                                                                 : 
                                                                                ((0x95U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x95U
                                                                                 : 
                                                                                ((0x94U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x94U
                                                                                 : 
                                                                                ((0x93U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x93U
                                                                                 : 
                                                                                ((0x92U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x92U
                                                                                 : 
                                                                                ((0x91U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x91U
                                                                                 : 
                                                                                ((0x90U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x90U
                                                                                 : 
                                                                                ((0x8fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x8fU
                                                                                 : 
                                                                                ((0x8eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x8eU
                                                                                 : 
                                                                                ((0x8dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x8dU
                                                                                 : 
                                                                                ((0x8cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x8cU
                                                                                 : 
                                                                                ((0x8bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x8bU
                                                                                 : 
                                                                                ((0x8aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x8aU
                                                                                 : 
                                                                                ((0x89U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x89U
                                                                                 : 
                                                                                ((0x88U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x88U
                                                                                 : 
                                                                                ((0x87U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x87U
                                                                                 : 
                                                                                ((0x86U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x86U
                                                                                 : 
                                                                                ((0x85U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x85U
                                                                                 : 
                                                                                ((0x84U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x84U
                                                                                 : 
                                                                                ((0x83U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x83U
                                                                                 : 
                                                                                ((0x82U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x82U
                                                                                 : 
                                                                                ((0x81U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x81U
                                                                                 : 
                                                                                ((0x80U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x80U
                                                                                 : 
                                                                                ((0x7fU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x7fU
                                                                                 : 
                                                                                ((0x7eU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x7eU
                                                                                 : 
                                                                                ((0x7dU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x7dU
                                                                                 : 
                                                                                ((0x7cU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x7cU
                                                                                 : 
                                                                                ((0x7bU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x7bU
                                                                                 : 
                                                                                ((0x7aU 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x7aU
                                                                                 : 
                                                                                ((0x79U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x79U
                                                                                 : 
                                                                                ((0x78U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x78U
                                                                                 : 
                                                                                ((0x77U 
                                                                                == 
                                                                                (0xffU 
                                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                                 ? 0x77U
                                                                                 : __Vdeeptemp_h20c20ccb__0))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vdeeptemp_h53fb63df__0 = ((0xeeU == (0xffU & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                 ? 0xeeU : ((0xedU 
                                             == (0xffU 
                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                             ? 0xedU
                                             : __Vdeeptemp_h474464c7__0));
    vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
        = ((0xffU == (0xffU & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
            ? 0xffU : ((0xfeU == (0xffU & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                        ? 0xfeU : ((0xfdU == (0xffU 
                                              & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                    ? 0xfdU : ((0xfcU 
                                                == 
                                                (0xffU 
                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                ? 0xfcU
                                                : (
                                                   (0xfbU 
                                                    == 
                                                    (0xffU 
                                                     & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                    ? 0xfbU
                                                    : 
                                                   ((0xfaU 
                                                     == 
                                                     (0xffU 
                                                      & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                     ? 0xfaU
                                                     : 
                                                    ((0xf9U 
                                                      == 
                                                      (0xffU 
                                                       & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                      ? 0xf9U
                                                      : 
                                                     ((0xf8U 
                                                       == 
                                                       (0xffU 
                                                        & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                       ? 0xf8U
                                                       : 
                                                      ((0xf7U 
                                                        == 
                                                        (0xffU 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                        ? 0xf7U
                                                        : 
                                                       ((0xf6U 
                                                         == 
                                                         (0xffU 
                                                          & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                         ? 0xf6U
                                                         : 
                                                        ((0xf5U 
                                                          == 
                                                          (0xffU 
                                                           & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                          ? 0xf5U
                                                          : 
                                                         ((0xf4U 
                                                           == 
                                                           (0xffU 
                                                            & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                           ? 0xf4U
                                                           : 
                                                          ((0xf3U 
                                                            == 
                                                            (0xffU 
                                                             & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                            ? 0xf3U
                                                            : 
                                                           ((0xf2U 
                                                             == 
                                                             (0xffU 
                                                              & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                             ? 0xf2U
                                                             : 
                                                            ((0xf1U 
                                                              == 
                                                              (0xffU 
                                                               & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                              ? 0xf1U
                                                              : 
                                                             ((0xf0U 
                                                               == 
                                                               (0xffU 
                                                                & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                               ? 0xf0U
                                                               : 
                                                              ((0xefU 
                                                                == 
                                                                (0xffU 
                                                                 & vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                                ? 0xefU
                                                                : __Vdeeptemp_h53fb63df__0)))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9 
        = (vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state 
           + ((((vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                 >> 0x1fU) ? 0x7ffffU : 0U) << 0xdU) 
              | (((0x1000U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                              >> 0x13U)) | (0x800U 
                                            & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                               << 4U))) 
                 | ((0x7e0U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                               >> 0x14U)) | (0x1eU 
                                             & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                >> 7U))))));
    vlSelfRef.ysyx_25030077_top__DOT__i3__DOT__Imm_type1 
        = ((((vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
              >> 0x1fU) ? 0xfffffU : 0U) << 0xcU) | 
           (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
            >> 0x14U));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2 
        = ((0x380U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                      >> 5U)) | (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3 
        = ((0x1fc00U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU)) | (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3 
        = ((0xfc00U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                       >> 0x10U)) | (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2));
    if ((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x213U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 4U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x313U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 3U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x393U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 6U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0xf3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 0xbU;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 6U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x173U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 0xcU;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 6U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x4293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 5U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 5U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 9U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 5U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x93U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 8U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 5U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x193U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 2U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else if ((0x113U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 0xaU;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else {
        if ((0x37U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))) {
            vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                     >> 7U));
            vlSelfRef.ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077_top__DOT__imm_type = 2U;
        } else if ((0x17U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))) {
            vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                     >> 7U));
            vlSelfRef.ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077_top__DOT__imm_type = 2U;
        } else if ((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))) {
            vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                     >> 7U));
            vlSelfRef.ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077_top__DOT__imm_type = 3U;
        } else if ((0x67U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
            vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                     >> 7U));
            vlSelfRef.ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077_top__DOT__imm_type = 3U;
        } else {
            vlSelfRef.rd = (0x1fU & ((0x103U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                      ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                         >> 7U) : (
                                                   (0x83U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 7U)
                                                    : 
                                                   ((0x283U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                     >> 7U)
                                                     : 
                                                    ((0x203U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                      >> 7U)
                                                      : 
                                                     ((3U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                       >> 7U)
                                                       : 
                                                      ((0x33U 
                                                        == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                        >> 7U)
                                                        : 
                                                       ((0x3b3U 
                                                         == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                         >> 7U)
                                                         : 
                                                        ((0xb3U 
                                                          == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                          >> 7U)
                                                          : 
                                                         ((0x42b3U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                           >> 7U)
                                                           : 
                                                          ((0x2b3U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                            >> 7U)
                                                            : 
                                                           ((0x233U 
                                                             == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                             ? 
                                                            (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                             >> 7U)
                                                             : 
                                                            ((0x333U 
                                                              == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                              ? 
                                                             (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                              >> 7U)
                                                              : 
                                                             ((0x8033U 
                                                               == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                               ? 
                                                              (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                               >> 7U)
                                                               : 
                                                              ((0x1b3U 
                                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                ? 
                                                               (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                >> 7U)
                                                                : 
                                                               ((0x133U 
                                                                 == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                 ? 
                                                                (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                 >> 7U)
                                                                 : 0U))))))))))))))));
            if ((0x123U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 4U;
            } else if ((0x23U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 4U;
            } else if ((0xa3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 4U;
            } else if ((0x103U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
            } else if ((0x83U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
            } else if ((0x283U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
            } else if ((0x203U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
            } else if ((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
                vlSelfRef.ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
            } else {
                vlSelfRef.ALU_ctrl = ((0x33U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                       ? 0U : ((0x3b3U 
                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                ? 6U
                                                : (
                                                   (0xb3U 
                                                    == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                    ? 8U
                                                    : 
                                                   ((0x42b3U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                     ? 5U
                                                     : 
                                                    ((0x2b3U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                      ? 9U
                                                      : 
                                                     ((0x233U 
                                                       == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                       ? 4U
                                                       : 
                                                      ((0x333U 
                                                        == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                        ? 3U
                                                        : 
                                                       ((0x8033U 
                                                         == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                         ? 1U
                                                         : 
                                                        ((0x63U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                          ? 0U
                                                          : 
                                                         ((0x2e3U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                           ? 0U
                                                           : 
                                                          ((0x263U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0x363U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0x3e3U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                              ? 0U
                                                              : 
                                                             ((0xe3U 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                               ? 0U
                                                               : 
                                                              ((0x133U 
                                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                ? 0xaU
                                                                : 
                                                               ((0x1b3U 
                                                                 == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                 ? 2U
                                                                 : 0U))))))))))))))));
                vlSelfRef.ysyx_25030077_top__DOT__imm_type = 0U;
            }
        }
        vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                                 & ((0x67U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                     >> 0xfU)
                                                     : 
                                                    ((0x123U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                      >> 0xfU)
                                                      : 
                                                     ((0x23U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                       >> 0xfU)
                                                       : 
                                                      ((0xa3U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                        >> 0xfU)
                                                        : 
                                                       ((0x103U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                         >> 0xfU)
                                                         : 
                                                        ((0x83U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                          >> 0xfU)
                                                          : 
                                                         ((0x283U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                           >> 0xfU)
                                                           : 
                                                          ((0x203U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                            >> 0xfU)
                                                            : 
                                                           ((3U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                             ? 
                                                            (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                             >> 0xfU)
                                                             : 
                                                            ((0x33U 
                                                              == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                              ? 
                                                             (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                              >> 0xfU)
                                                              : 
                                                             ((0x3b3U 
                                                               == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                               ? 
                                                              (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                               >> 0xfU)
                                                               : 
                                                              ((0xb3U 
                                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                ? 
                                                               (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                >> 0xfU)
                                                                : 
                                                               ((0x42b3U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                                 ? 
                                                                (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                 >> 0xfU)
                                                                 : 
                                                                ((0x2b3U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                                  ? 
                                                                 (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                  >> 0xfU)
                                                                  : 
                                                                 ((0x233U 
                                                                   == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                   ? 
                                                                  (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                   >> 0xfU)
                                                                   : 
                                                                  ((0x333U 
                                                                    == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                    ? 
                                                                   (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                    >> 0xfU)
                                                                    : 
                                                                   ((0x8033U 
                                                                     == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                     ? 
                                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                     >> 0xfU)
                                                                     : 
                                                                    ((0x63U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                      ? 
                                                                     (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                      >> 0xfU)
                                                                      : 
                                                                     ((0x2e3U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                       ? 
                                                                      (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                       >> 0xfU)
                                                                       : 
                                                                      ((0x263U 
                                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                        ? 
                                                                       (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                        >> 0xfU)
                                                                        : 
                                                                       ((0x363U 
                                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                         ? 
                                                                        (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                         >> 0xfU)
                                                                         : 
                                                                        ((0x3e3U 
                                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                          ? 
                                                                         (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                          >> 0xfU)
                                                                          : 
                                                                         ((0xe3U 
                                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                           ? 
                                                                          (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                           >> 0xfU)
                                                                           : 
                                                                          ((0x1b3U 
                                                                            == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                            ? 
                                                                           (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                            >> 0xfU)
                                                                            : 
                                                                           ((0x133U 
                                                                             == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                             ? 
                                                                            (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                             >> 0xfU)
                                                                             : 0U))))))))))))))))))))))))));
    }
    vlSelfRef.ysyx_25030077_top__DOT__pc_next_type 
        = ((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
            ? 1U : ((0x67U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? 2U : ((0x17U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                              ? 0U : ((0x37U == (0x7fU 
                                                 & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                       ? 0U : ((0x13U 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                ? 0U
                                                : (
                                                   (0x213U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 0U
                                                    : 
                                                   ((0x313U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 0U
                                                     : 
                                                    ((0x393U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                      ? 0U
                                                      : 
                                                     ((0xf3U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                       ? 0U
                                                       : 
                                                      ((0x173U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                        ? 0U
                                                        : 
                                                       ((0x4293U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                         ? 0U
                                                         : 
                                                        ((0x293U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                          ? 0U
                                                          : 
                                                         ((0x93U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                           ? 0U
                                                           : 
                                                          ((0x123U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0x23U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0xa3U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                              ? 0U
                                                              : 
                                                             ((0x100073U 
                                                               == vlSelfRef.ysyx_25030077_top__DOT__instruction_out)
                                                               ? 4U
                                                               : 
                                                              ((0x73U 
                                                                == vlSelfRef.ysyx_25030077_top__DOT__instruction_out)
                                                                ? 0xbU
                                                                : 
                                                               ((0x30200073U 
                                                                 == vlSelfRef.ysyx_25030077_top__DOT__instruction_out)
                                                                 ? 0xcU
                                                                 : 
                                                                ((0x103U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                  ? 0U
                                                                  : 
                                                                 ((0x83U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                   ? 0U
                                                                   : 
                                                                  ((0x283U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                    ? 0U
                                                                    : 
                                                                   ((0x203U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                     ? 0U
                                                                     : 
                                                                    ((3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                      ? 0U
                                                                      : 
                                                                     ((0x33U 
                                                                       == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                       ? 0U
                                                                       : 
                                                                      ((0x3b3U 
                                                                        == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                        ? 0U
                                                                        : 
                                                                       ((0xb3U 
                                                                         == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                         ? 0U
                                                                         : 
                                                                        ((0x42b3U 
                                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                                          ? 0U
                                                                          : 
                                                                         ((0x2b3U 
                                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                                           ? 0U
                                                                           : 
                                                                          ((0x233U 
                                                                            == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                            ? 0U
                                                                            : 
                                                                           ((0x333U 
                                                                             == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                             ? 0U
                                                                             : 
                                                                            ((0x8033U 
                                                                              == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                              ? 0U
                                                                              : 
                                                                             ((0x63U 
                                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                               ? 6U
                                                                               : 
                                                                              ((0x2e3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                ? 7U
                                                                                : 
                                                                               ((0x263U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                 ? 9U
                                                                                 : 
                                                                                ((0x363U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                 ? 0xaU
                                                                                 : 
                                                                                ((0x3e3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                 ? 8U
                                                                                 : 
                                                                                ((0xe3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                 ? 5U
                                                                                 : 
                                                                                ((0x1b3U 
                                                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x133U 
                                                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x193U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x113U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                                 ? 0U
                                                                                 : 3U))))))))))))))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__data_control 
        = ((0x17U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
            ? 1U : ((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                     ? 1U : ((0x67U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                              ? 1U : ((0x123U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                       ? 0U : ((0x23U 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                ? 0U
                                                : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 0U
                                                    : 
                                                   ((0x103U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : 
                                                    ((0x83U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                      ? 2U
                                                      : 
                                                     ((0x283U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                       ? 2U
                                                       : 
                                                      ((0x203U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                        ? 2U
                                                        : 
                                                       ((3U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                         ? 2U
                                                         : 
                                                        ((0x33U 
                                                          == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                          ? 3U
                                                          : 
                                                         ((0x3b3U 
                                                           == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                           ? 3U
                                                           : 
                                                          ((0xb3U 
                                                            == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                            ? 3U
                                                            : 
                                                           ((0x42b3U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                             ? 3U
                                                             : 
                                                            ((0x2b3U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                              ? 3U
                                                              : 
                                                             ((0x233U 
                                                               == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                               ? 3U
                                                               : 
                                                              ((0x333U 
                                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                ? 3U
                                                                : 
                                                               ((0x8033U 
                                                                 == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                 ? 3U
                                                                 : 
                                                                ((0x63U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                  ? 0U
                                                                  : 
                                                                 ((0x2e3U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                   ? 0U
                                                                   : 
                                                                  ((0x263U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                    ? 0U
                                                                    : 
                                                                   ((0x363U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                     ? 0U
                                                                     : 
                                                                    ((0x3e3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                      ? 0U
                                                                      : 
                                                                     ((0xe3U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                       ? 0U
                                                                       : 
                                                                      ((0x133U 
                                                                        == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                        ? 3U
                                                                        : 
                                                                       ((0x1b3U 
                                                                         == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                         ? 3U
                                                                         : 0U)))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__rs2 = (0x1fU 
                                             & ((0x123U 
                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                 ? 
                                                (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                 >> 0x14U)
                                                 : 
                                                ((0x23U 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                  ? 
                                                 (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                  >> 0x14U)
                                                  : 
                                                 ((0xa3U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                   >> 0x14U)
                                                   : 
                                                  ((0x33U 
                                                    == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0x14U)
                                                    : 
                                                   ((0x3b3U 
                                                     == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                     >> 0x14U)
                                                     : 
                                                    ((0xb3U 
                                                      == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                      >> 0x14U)
                                                      : 
                                                     ((0x42b3U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                       >> 0x14U)
                                                       : 
                                                      ((0x2b3U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                        >> 0x14U)
                                                        : 
                                                       ((0x233U 
                                                         == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                         >> 0x14U)
                                                         : 
                                                        ((0x333U 
                                                          == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                          >> 0x14U)
                                                          : 
                                                         ((0x8033U 
                                                           == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                           >> 0x14U)
                                                           : 
                                                          ((0x63U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                            >> 0x14U)
                                                            : 
                                                           ((0x2e3U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                             ? 
                                                            (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                             >> 0x14U)
                                                             : 
                                                            ((0x263U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                              ? 
                                                             (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                              >> 0x14U)
                                                              : 
                                                             ((0x363U 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                               ? 
                                                              (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                               >> 0x14U)
                                                               : 
                                                              ((0x3e3U 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                ? 
                                                               (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                >> 0x14U)
                                                                : 
                                                               ((0xe3U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                 ? 
                                                                (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                 >> 0x14U)
                                                                 : 
                                                                ((0x1b3U 
                                                                  == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                  ? 
                                                                 (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                  >> 0x14U)
                                                                  : 
                                                                 ((0x133U 
                                                                   == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                                   ? 
                                                                  (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                                   >> 0x14U)
                                                                   : 0U))))))))))))))))))));
    vlSelfRef.imm = ((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))
                      ? vlSelfRef.ysyx_25030077_top__DOT__i3__DOT__Imm_type1
                      : ((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))
                          ? (0xfffff000U & vlSelfRef.ysyx_25030077_top__DOT__instruction_out)
                          : ((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))
                              ? 4U : ((4U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))
                                       ? ((((vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                             >> 0x1fU)
                                             ? 0xfffffU
                                             : 0U) 
                                           << 0xcU) 
                                          | ((0xfe0U 
                                              & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                   >> 7U))))
                                       : ((5U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))
                                           ? (0x1fU 
                                              & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                 >> 0x14U))
                                           : ((6U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))
                                               ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__instruction_out, 0x14U)
                                               : 0U))))));
    vlSelfRef.rs2_out = ((0x1fU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_31
                          : ((0x1eU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                              ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_30
                              : ((0x1dU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                  ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_29
                                  : ((0x1cU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                      ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_28
                                      : ((0x1bU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_27
                                          : ((0x1aU 
                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                              ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_26
                                              : ((0x19U 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                  ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_25
                                                  : 
                                                 ((0x18U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                   ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_24
                                                   : 
                                                  ((0x17U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_23
                                                    : 
                                                   ((0x16U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                     ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_22
                                                     : 
                                                    ((0x15U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                      ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21
                                                      : 
                                                     ((0x14U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                       ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19
                                                        : 
                                                       ((0x12U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                         ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18
                                                         : 
                                                        ((0x11U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17
                                                          : 
                                                         ((0x10U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                           ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16
                                                           : 
                                                          ((0xfU 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15
                                                            : 
                                                           ((0xeU 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                             ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14
                                                             : 
                                                            ((0xdU 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                              ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13
                                                              : 
                                                             ((0xcU 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                               ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12
                                                               : 
                                                              ((0xbU 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_11
                                                                : 
                                                               ((0xaU 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                 ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_10
                                                                 : 
                                                                ((9U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                  ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_9
                                                                  : 
                                                                 ((8U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                   ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_8
                                                                   : 
                                                                  ((7U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_7
                                                                    : 
                                                                   ((6U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                     ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_6
                                                                     : 
                                                                    ((5U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                      ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_5
                                                                      : 
                                                                     ((4U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                       ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_4
                                                                       : 
                                                                      ((3U 
                                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_3
                                                                        : 
                                                                       ((2U 
                                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                         ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_2
                                                                         : 
                                                                        ((1U 
                                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_1
                                                                          : vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0)))))))))))))))))))))))))))))));
    vlSelfRef.rs1_out = ((0x1fU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_31
                          : ((0x1eU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                              ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_30
                              : ((0x1dU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                  ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_29
                                  : ((0x1cU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                      ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_28
                                      : ((0x1bU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_27
                                          : ((0x1aU 
                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                              ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_26
                                              : ((0x19U 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                  ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_25
                                                  : 
                                                 ((0x18U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                   ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_24
                                                   : 
                                                  ((0x17U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_23
                                                    : 
                                                   ((0x16U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                     ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_22
                                                     : 
                                                    ((0x15U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                      ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21
                                                      : 
                                                     ((0x14U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                       ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19
                                                        : 
                                                       ((0x12U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                         ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18
                                                         : 
                                                        ((0x11U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17
                                                          : 
                                                         ((0x10U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                           ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16
                                                           : 
                                                          ((0xfU 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15
                                                            : 
                                                           ((0xeU 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                             ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14
                                                             : 
                                                            ((0xdU 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                              ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13
                                                              : 
                                                             ((0xcU 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                               ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12
                                                               : 
                                                              ((0xbU 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_11
                                                                : 
                                                               ((0xaU 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                 ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_10
                                                                 : 
                                                                ((9U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                  ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_9
                                                                  : 
                                                                 ((8U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                   ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_8
                                                                   : 
                                                                  ((7U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_7
                                                                    : 
                                                                   ((6U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                     ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_6
                                                                     : 
                                                                    ((5U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                      ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_5
                                                                      : 
                                                                     ((4U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                       ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_4
                                                                       : 
                                                                      ((3U 
                                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_3
                                                                        : 
                                                                       ((2U 
                                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                         ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_2
                                                                         : 
                                                                        ((1U 
                                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                                          ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_1
                                                                          : vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0)))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2 = 
        ((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
          ? 0U : ((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
                   ? vlSelfRef.rs2_out : vlSelfRef.imm));
    vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql 
        = (vlSelfRef.rs1_out == vlSelfRef.rs2_out);
    vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index 
        = (0xffU & (((vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                      ^ vlSelfRef.rs1_out) ^ vlSelfRef.rs2_out) 
                    ^ vlSelfRef.imm));
    vlSelfRef.ysyx_25030077_top__DOT__Pc_next = (((0xbU 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)) 
                                                  | (0xcU 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)))
                                                  ? vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                   ? 
                                                  (vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state 
                                                   + 
                                                   (((((vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                        >> 0x1fU)
                                                        ? 0x7ffU
                                                        : 0U) 
                                                      << 0x15U) 
                                                     | (0x100000U 
                                                        & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                           >> 0xbU))) 
                                                    | (((0xff000U 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__instruction_out) 
                                                        | (0x800U 
                                                           & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                              >> 9U))) 
                                                       | (0x7feU 
                                                          & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                             >> 0x14U)))))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                    ? 
                                                   (0xfffffffeU 
                                                    & (vlSelfRef.rs1_out 
                                                       + vlSelfRef.ysyx_25030077_top__DOT__i3__DOT__Imm_type1))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                     ? vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                      ? 
                                                     ((IData)(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql)
                                                       ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                                       : 
                                                      ((IData)(4U) 
                                                       + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                       ? 
                                                      ((IData)(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql)
                                                        ? 
                                                       ((IData)(4U) 
                                                        + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state)
                                                        : vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9)
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                        ? 
                                                       (VL_GTES_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)
                                                         ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                                         : 
                                                        ((IData)(4U) 
                                                         + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                        : 
                                                       ((8U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                         ? 
                                                        ((vlSelfRef.rs1_out 
                                                          >= vlSelfRef.rs2_out)
                                                          ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                                          : 
                                                         ((IData)(4U) 
                                                          + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                         : 
                                                        ((9U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                          ? 
                                                         (VL_LTS_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)
                                                           ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                                           : 
                                                          ((IData)(4U) 
                                                           + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                          : 
                                                         ((0xaU 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))
                                                           ? 
                                                          ((vlSelfRef.rs1_out 
                                                            < vlSelfRef.rs2_out)
                                                            ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                                            : 
                                                           ((IData)(4U) 
                                                            + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))
                                                           : 
                                                          ((IData)(4U) 
                                                           + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state)))))))))));
    __Vdeeptemp_h8729ea13__0 = ((0x77U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                 ? 0x77U : ((0x76U 
                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                             ? 0x76U
                                             : ((0x75U 
                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                 ? 0x75U
                                                 : 
                                                ((0x74U 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                  ? 0x74U
                                                  : 
                                                 ((0x73U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                   ? 0x73U
                                                   : 
                                                  ((0x72U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                    ? 0x72U
                                                    : 
                                                   ((0x71U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                     ? 0x71U
                                                     : 
                                                    ((0x70U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                      ? 0x70U
                                                      : 
                                                     ((0x6fU 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                       ? 0x6fU
                                                       : 
                                                      ((0x6eU 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                        ? 0x6eU
                                                        : 
                                                       ((0x6dU 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                         ? 0x6dU
                                                         : 
                                                        ((0x6cU 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                          ? 0x6cU
                                                          : 
                                                         ((0x6bU 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                           ? 0x6bU
                                                           : 
                                                          ((0x6aU 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                            ? 0x6aU
                                                            : 
                                                           ((0x69U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                             ? 0x69U
                                                             : 
                                                            ((0x68U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                              ? 0x68U
                                                              : 
                                                             ((0x67U 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                               ? 0x67U
                                                               : 
                                                              ((0x66U 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                ? 0x66U
                                                                : 
                                                               ((0x65U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                 ? 0x65U
                                                                 : 
                                                                ((0x64U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                  ? 0x64U
                                                                  : 
                                                                 ((0x63U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                   ? 0x63U
                                                                   : 
                                                                  ((0x62U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                    ? 0x62U
                                                                    : 
                                                                   ((0x61U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                     ? 0x61U
                                                                     : 
                                                                    ((0x60U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                      ? 0x60U
                                                                      : 
                                                                     ((0x5fU 
                                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                       ? 0x5fU
                                                                       : 
                                                                      ((0x5eU 
                                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                        ? 0x5eU
                                                                        : 
                                                                       ((0x5dU 
                                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                         ? 0x5dU
                                                                         : 
                                                                        ((0x5cU 
                                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                          ? 0x5cU
                                                                          : 
                                                                         ((0x5bU 
                                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                           ? 0x5bU
                                                                           : 
                                                                          ((0x5aU 
                                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                            ? 0x5aU
                                                                            : 
                                                                           ((0x59U 
                                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                             ? 0x59U
                                                                             : 
                                                                            ((0x58U 
                                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                              ? 0x58U
                                                                              : 
                                                                             ((0x57U 
                                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                               ? 0x57U
                                                                               : 
                                                                              ((0x56U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                ? 0x56U
                                                                                : 
                                                                               ((0x55U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x55U
                                                                                 : 
                                                                                ((0x54U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x54U
                                                                                 : 
                                                                                ((0x53U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x53U
                                                                                 : 
                                                                                ((0x52U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x52U
                                                                                 : 
                                                                                ((0x51U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x51U
                                                                                 : 
                                                                                ((0x50U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x50U
                                                                                 : 
                                                                                ((0x4fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x4fU
                                                                                 : 
                                                                                ((0x4eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x4eU
                                                                                 : 
                                                                                ((0x4dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x4dU
                                                                                 : 
                                                                                ((0x4cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x4cU
                                                                                 : 
                                                                                ((0x4bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x4bU
                                                                                 : 
                                                                                ((0x4aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x4aU
                                                                                 : 
                                                                                ((0x49U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x49U
                                                                                 : 
                                                                                ((0x48U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x48U
                                                                                 : 
                                                                                ((0x47U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x47U
                                                                                 : 
                                                                                ((0x46U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x46U
                                                                                 : 
                                                                                ((0x45U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x45U
                                                                                 : 
                                                                                ((0x44U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x44U
                                                                                 : 
                                                                                ((0x43U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x43U
                                                                                 : 
                                                                                ((0x42U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x42U
                                                                                 : 
                                                                                ((0x41U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x41U
                                                                                 : 
                                                                                ((0x40U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x40U
                                                                                 : 
                                                                                ((0x3fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x3fU
                                                                                 : 
                                                                                ((0x3eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x3eU
                                                                                 : 
                                                                                ((0x3dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x3dU
                                                                                 : 
                                                                                ((0x3cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x3cU
                                                                                 : 
                                                                                ((0x3bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x3bU
                                                                                 : 
                                                                                ((0x3aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x3aU
                                                                                 : 
                                                                                ((0x39U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x39U
                                                                                 : 
                                                                                ((0x38U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x38U
                                                                                 : 
                                                                                ((0x37U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x37U
                                                                                 : 
                                                                                ((0x36U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x36U
                                                                                 : 
                                                                                ((0x35U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x35U
                                                                                 : 
                                                                                ((0x34U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x34U
                                                                                 : 
                                                                                ((0x33U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x33U
                                                                                 : 
                                                                                ((0x32U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x32U
                                                                                 : 
                                                                                ((0x31U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x31U
                                                                                 : 
                                                                                ((0x30U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x30U
                                                                                 : 
                                                                                ((0x2fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x2fU
                                                                                 : 
                                                                                ((0x2eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x2eU
                                                                                 : 
                                                                                ((0x2dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x2dU
                                                                                 : 
                                                                                ((0x2cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x2cU
                                                                                 : 
                                                                                ((0x2bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x2bU
                                                                                 : 
                                                                                ((0x2aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x2aU
                                                                                 : 
                                                                                ((0x29U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x29U
                                                                                 : 
                                                                                ((0x28U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x28U
                                                                                 : 
                                                                                ((0x27U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x27U
                                                                                 : 
                                                                                ((0x26U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x26U
                                                                                 : 
                                                                                ((0x25U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x25U
                                                                                 : 
                                                                                ((0x24U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x24U
                                                                                 : 
                                                                                ((0x23U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x23U
                                                                                 : 
                                                                                ((0x22U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x22U
                                                                                 : 
                                                                                ((0x21U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x21U
                                                                                 : 
                                                                                ((0x20U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x20U
                                                                                 : 
                                                                                ((0x1fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x1fU
                                                                                 : 
                                                                                ((0x1eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x1eU
                                                                                 : 
                                                                                ((0x1dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x1dU
                                                                                 : 
                                                                                ((0x1cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x1cU
                                                                                 : 
                                                                                ((0x1bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x1bU
                                                                                 : 
                                                                                ((0x1aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x1aU
                                                                                 : 
                                                                                ((0x19U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x19U
                                                                                 : 
                                                                                ((0x18U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x18U
                                                                                 : 
                                                                                ((0x17U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x17U
                                                                                 : 
                                                                                ((0x16U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x16U
                                                                                 : 
                                                                                ((0x15U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x15U
                                                                                 : 
                                                                                ((0x14U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x14U
                                                                                 : 
                                                                                ((0x13U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x13U
                                                                                 : 
                                                                                ((0x12U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x12U
                                                                                 : 
                                                                                ((0x11U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x11U
                                                                                 : 
                                                                                ((0x10U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x10U
                                                                                 : 
                                                                                ((0xfU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xfU
                                                                                 : 
                                                                                ((0xeU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xeU
                                                                                 : 
                                                                                ((0xdU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xdU
                                                                                 : 
                                                                                ((0xcU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xcU
                                                                                 : 
                                                                                ((0xbU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbU
                                                                                 : 
                                                                                ((0xaU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xaU
                                                                                 : 
                                                                                ((9U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 9U
                                                                                 : 
                                                                                ((8U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 8U
                                                                                 : 
                                                                                ((7U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 7U
                                                                                 : 
                                                                                ((6U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 6U
                                                                                 : 
                                                                                ((5U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 5U
                                                                                 : 
                                                                                ((4U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 4U
                                                                                 : 
                                                                                ((3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 3U
                                                                                 : 
                                                                                ((2U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 2U
                                                                                 : 
                                                                                ((1U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 1U
                                                                                 : 0U)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vdeeptemp_h46af4f1d__0 = ((0xeeU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                 ? 0xeeU : ((0xedU 
                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                             ? 0xedU
                                             : ((0xecU 
                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                 ? 0xecU
                                                 : 
                                                ((0xebU 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                  ? 0xebU
                                                  : 
                                                 ((0xeaU 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                   ? 0xeaU
                                                   : 
                                                  ((0xe9U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                    ? 0xe9U
                                                    : 
                                                   ((0xe8U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                     ? 0xe8U
                                                     : 
                                                    ((0xe7U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                      ? 0xe7U
                                                      : 
                                                     ((0xe6U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                       ? 0xe6U
                                                       : 
                                                      ((0xe5U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                        ? 0xe5U
                                                        : 
                                                       ((0xe4U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                         ? 0xe4U
                                                         : 
                                                        ((0xe3U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                          ? 0xe3U
                                                          : 
                                                         ((0xe2U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                           ? 0xe2U
                                                           : 
                                                          ((0xe1U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                            ? 0xe1U
                                                            : 
                                                           ((0xe0U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                             ? 0xe0U
                                                             : 
                                                            ((0xdfU 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                              ? 0xdfU
                                                              : 
                                                             ((0xdeU 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                               ? 0xdeU
                                                               : 
                                                              ((0xddU 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                ? 0xddU
                                                                : 
                                                               ((0xdcU 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                 ? 0xdcU
                                                                 : 
                                                                ((0xdbU 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                  ? 0xdbU
                                                                  : 
                                                                 ((0xdaU 
                                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                   ? 0xdaU
                                                                   : 
                                                                  ((0xd9U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                    ? 0xd9U
                                                                    : 
                                                                   ((0xd8U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                     ? 0xd8U
                                                                     : 
                                                                    ((0xd7U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                      ? 0xd7U
                                                                      : 
                                                                     ((0xd6U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                       ? 0xd6U
                                                                       : 
                                                                      ((0xd5U 
                                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                        ? 0xd5U
                                                                        : 
                                                                       ((0xd4U 
                                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                         ? 0xd4U
                                                                         : 
                                                                        ((0xd3U 
                                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                          ? 0xd3U
                                                                          : 
                                                                         ((0xd2U 
                                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                           ? 0xd2U
                                                                           : 
                                                                          ((0xd1U 
                                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                            ? 0xd1U
                                                                            : 
                                                                           ((0xd0U 
                                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                             ? 0xd0U
                                                                             : 
                                                                            ((0xcfU 
                                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                              ? 0xcfU
                                                                              : 
                                                                             ((0xceU 
                                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                               ? 0xceU
                                                                               : 
                                                                              ((0xcdU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                ? 0xcdU
                                                                                : 
                                                                               ((0xccU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xccU
                                                                                 : 
                                                                                ((0xcbU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xcbU
                                                                                 : 
                                                                                ((0xcaU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xcaU
                                                                                 : 
                                                                                ((0xc9U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc9U
                                                                                 : 
                                                                                ((0xc8U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc8U
                                                                                 : 
                                                                                ((0xc7U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc7U
                                                                                 : 
                                                                                ((0xc6U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc6U
                                                                                 : 
                                                                                ((0xc5U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc5U
                                                                                 : 
                                                                                ((0xc4U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc4U
                                                                                 : 
                                                                                ((0xc3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc3U
                                                                                 : 
                                                                                ((0xc2U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc2U
                                                                                 : 
                                                                                ((0xc1U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc1U
                                                                                 : 
                                                                                ((0xc0U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xc0U
                                                                                 : 
                                                                                ((0xbfU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbfU
                                                                                 : 
                                                                                ((0xbeU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbeU
                                                                                 : 
                                                                                ((0xbdU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbdU
                                                                                 : 
                                                                                ((0xbcU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbcU
                                                                                 : 
                                                                                ((0xbbU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbbU
                                                                                 : 
                                                                                ((0xbaU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xbaU
                                                                                 : 
                                                                                ((0xb9U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb9U
                                                                                 : 
                                                                                ((0xb8U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb8U
                                                                                 : 
                                                                                ((0xb7U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb7U
                                                                                 : 
                                                                                ((0xb6U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb6U
                                                                                 : 
                                                                                ((0xb5U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb5U
                                                                                 : 
                                                                                ((0xb4U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb4U
                                                                                 : 
                                                                                ((0xb3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb3U
                                                                                 : 
                                                                                ((0xb2U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb2U
                                                                                 : 
                                                                                ((0xb1U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb1U
                                                                                 : 
                                                                                ((0xb0U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xb0U
                                                                                 : 
                                                                                ((0xafU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xafU
                                                                                 : 
                                                                                ((0xaeU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xaeU
                                                                                 : 
                                                                                ((0xadU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xadU
                                                                                 : 
                                                                                ((0xacU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xacU
                                                                                 : 
                                                                                ((0xabU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xabU
                                                                                 : 
                                                                                ((0xaaU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xaaU
                                                                                 : 
                                                                                ((0xa9U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa9U
                                                                                 : 
                                                                                ((0xa8U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa8U
                                                                                 : 
                                                                                ((0xa7U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa7U
                                                                                 : 
                                                                                ((0xa6U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa6U
                                                                                 : 
                                                                                ((0xa5U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa5U
                                                                                 : 
                                                                                ((0xa4U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa4U
                                                                                 : 
                                                                                ((0xa3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa3U
                                                                                 : 
                                                                                ((0xa2U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa2U
                                                                                 : 
                                                                                ((0xa1U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa1U
                                                                                 : 
                                                                                ((0xa0U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0xa0U
                                                                                 : 
                                                                                ((0x9fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x9fU
                                                                                 : 
                                                                                ((0x9eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x9eU
                                                                                 : 
                                                                                ((0x9dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x9dU
                                                                                 : 
                                                                                ((0x9cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x9cU
                                                                                 : 
                                                                                ((0x9bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x9bU
                                                                                 : 
                                                                                ((0x9aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x9aU
                                                                                 : 
                                                                                ((0x99U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x99U
                                                                                 : 
                                                                                ((0x98U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x98U
                                                                                 : 
                                                                                ((0x97U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x97U
                                                                                 : 
                                                                                ((0x96U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x96U
                                                                                 : 
                                                                                ((0x95U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x95U
                                                                                 : 
                                                                                ((0x94U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x94U
                                                                                 : 
                                                                                ((0x93U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x93U
                                                                                 : 
                                                                                ((0x92U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x92U
                                                                                 : 
                                                                                ((0x91U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x91U
                                                                                 : 
                                                                                ((0x90U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x90U
                                                                                 : 
                                                                                ((0x8fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x8fU
                                                                                 : 
                                                                                ((0x8eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x8eU
                                                                                 : 
                                                                                ((0x8dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x8dU
                                                                                 : 
                                                                                ((0x8cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x8cU
                                                                                 : 
                                                                                ((0x8bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x8bU
                                                                                 : 
                                                                                ((0x8aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x8aU
                                                                                 : 
                                                                                ((0x89U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x89U
                                                                                 : 
                                                                                ((0x88U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x88U
                                                                                 : 
                                                                                ((0x87U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x87U
                                                                                 : 
                                                                                ((0x86U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x86U
                                                                                 : 
                                                                                ((0x85U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x85U
                                                                                 : 
                                                                                ((0x84U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x84U
                                                                                 : 
                                                                                ((0x83U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x83U
                                                                                 : 
                                                                                ((0x82U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x82U
                                                                                 : 
                                                                                ((0x81U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x81U
                                                                                 : 
                                                                                ((0x80U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x80U
                                                                                 : 
                                                                                ((0x7fU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x7fU
                                                                                 : 
                                                                                ((0x7eU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x7eU
                                                                                 : 
                                                                                ((0x7dU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x7dU
                                                                                 : 
                                                                                ((0x7cU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x7cU
                                                                                 : 
                                                                                ((0x7bU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x7bU
                                                                                 : 
                                                                                ((0x7aU 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x7aU
                                                                                 : 
                                                                                ((0x79U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x79U
                                                                                 : 
                                                                                ((0x78U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                                 ? 0x78U
                                                                                 : __Vdeeptemp_h8729ea13__0)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    __Vdeeptemp_hcc701b89__0 = ((0xefU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                 ? 0xefU : __Vdeeptemp_h46af4f1d__0);
    vlSelfRef.ysyx_25030077_top__DOT__mem_data = ((0xffU 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                   ? 0xffU
                                                   : 
                                                  ((0xfeU 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                    ? 0xfeU
                                                    : 
                                                   ((0xfdU 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                     ? 0xfdU
                                                     : 
                                                    ((0xfcU 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                      ? 0xfcU
                                                      : 
                                                     ((0xfbU 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                       ? 0xfbU
                                                       : 
                                                      ((0xfaU 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                        ? 0xfaU
                                                        : 
                                                       ((0xf9U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                         ? 0xf9U
                                                         : 
                                                        ((0xf8U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                          ? 0xf8U
                                                          : 
                                                         ((0xf7U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                           ? 0xf7U
                                                           : 
                                                          ((0xf6U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                            ? 0xf6U
                                                            : 
                                                           ((0xf5U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                             ? 0xf5U
                                                             : 
                                                            ((0xf4U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                              ? 0xf4U
                                                              : 
                                                             ((0xf3U 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                               ? 0xf3U
                                                               : 
                                                              ((0xf2U 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                ? 0xf2U
                                                                : 
                                                               ((0xf1U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                 ? 0xf1U
                                                                 : 
                                                                ((0xf0U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i9__DOT__index))
                                                                  ? 0xf0U
                                                                  : __Vdeeptemp_hcc701b89__0))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 = 
        ((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
          ? vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state
          : ((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
              ? vlSelfRef.ysyx_25030077_top__DOT__mem_data
              : vlSelfRef.rs1_out));
    vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult 
        = (0x1ffffffffULL & ((QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1)) 
                             + (QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2))));
    vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult 
        = (0x1ffffffffULL & ((QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1)) 
                             - (QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2))));
    vlSelfRef.ALU_carry = (1U & ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                                  & (IData)((vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult 
                                             >> 0x20U))) 
                                 | (IData)(((vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult 
                                             >> 0x20U) 
                                            & (((IData)(1U) 
                                                << (IData)(vlSelfRef.ALU_ctrl)) 
                                               >> 1U)))));
    vlSelfRef.ysyx_25030077_top__DOT__ALU_result = 
        ((1U & ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                 >> 0xbU) | (((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                             >> 0xcU))) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1
          : ((((IData)(((((((((1U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
                               ? vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult
                               : 0ULL) | ((2U & ((IData)(1U) 
                                                 << (IData)(vlSelfRef.ALU_ctrl)))
                                           ? vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult
                                           : 0ULL)) 
                            | (QData)((IData)((1U & 
                                               ((((IData)(1U) 
                                                  << (IData)(vlSelfRef.ALU_ctrl)) 
                                                 >> 2U) 
                                                & (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                   < vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)))))) 
                           | (QData)((IData)(((8U & 
                                               ((IData)(1U) 
                                                << (IData)(vlSelfRef.ALU_ctrl)))
                                               ? (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                  | vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                               : 0U)))) 
                          | (QData)((IData)(((0x10U 
                                              & ((IData)(1U) 
                                                 << (IData)(vlSelfRef.ALU_ctrl)))
                                              ? (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                 ^ vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                              : 0U)))) 
                         | (QData)((IData)(((0x20U 
                                             & ((IData)(1U) 
                                                << (IData)(vlSelfRef.ALU_ctrl)))
                                             ? VL_SHIFTRS_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                             : 0U)))) 
                        | (QData)((IData)(((0x40U & 
                                            ((IData)(1U) 
                                             << (IData)(vlSelfRef.ALU_ctrl)))
                                            ? (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                               & vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                            : 0U))))) 
               | (IData)(((0x100U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
                           ? (0x7fffffffffffffffULL 
                              & ((QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1)) 
                                 << (0x1fU & vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)))
                           : 0ULL))) | ((0x200U & ((IData)(1U) 
                                                   << (IData)(vlSelfRef.ALU_ctrl)))
                                         ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                         : 0U)) | (IData)((QData)((IData)(
                                                                          (1U 
                                                                           & ((((IData)(1U) 
                                                                                << (IData)(vlSelfRef.ALU_ctrl)) 
                                                                               >> 0xaU) 
                                                                              & VL_LTS_III(32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2))))))));
    vlSelfRef.ALU_overflow = ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                               & (((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                    >> 0x1fU) == (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2 
                                                  >> 0x1fU)) 
                                  & ((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                      >> 0x1fU) != 
                                     (1U & (IData)(
                                                   (vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult 
                                                    >> 0x1fU)))))) 
                              | (1U & ((((IData)(1U) 
                                         << (IData)(vlSelfRef.ALU_ctrl)) 
                                        >> 1U) & ((
                                                   (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2 
                                                    >> 0x1fU)) 
                                                  & ((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                      >> 0x1fU) 
                                                     != 
                                                     (1U 
                                                      & (IData)(
                                                                (vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult 
                                                                 >> 0x1fU))))))));
}

VL_ATTR_COLD void Vysyx_25020077_top___024root___eval_triggers__stl(Vysyx_25020077_top___024root* vlSelf);

VL_ATTR_COLD bool Vysyx_25020077_top___024root___eval_phase__stl(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_phase__stl\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vysyx_25020077_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vysyx_25020077_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25020077_top___024root___dump_triggers__act(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___dump_triggers__act\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25020077_top___024root___dump_triggers__nba(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___dump_triggers__nba\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_25020077_top___024root____Vm_traceActivitySetAll(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root____Vm_traceActivitySetAll\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vysyx_25020077_top___024root___ctor_var_reset(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___ctor_var_reset\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17436245599429385641ull);
    vlSelf->rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10303652599525973633ull);
    vlSelf->ALU_ctrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 623548301751767430ull);
    vlSelf->rs1_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8092479236763461277ull);
    vlSelf->rs2_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2072742683039084026ull);
    vlSelf->ALU_carry = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1385632783046539091ull);
    vlSelf->ALU_overflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9827906817532509129ull);
    vlSelf->ysyx_25030077_top__DOT__Pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4359114053267489926ull);
    vlSelf->ysyx_25030077_top__DOT__instruction_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12381671318808089293ull);
    vlSelf->ysyx_25030077_top__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17196304268990620234ull);
    vlSelf->ysyx_25030077_top__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12308533099449350753ull);
    vlSelf->ysyx_25030077_top__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11769354428594916742ull);
    vlSelf->ysyx_25030077_top__DOT__data_control = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1152451158948089146ull);
    vlSelf->ysyx_25030077_top__DOT__pc_next_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6188249807046237292ull);
    vlSelf->ysyx_25030077_top__DOT__ALU_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15328211177512517193ull);
    vlSelf->ysyx_25030077_top__DOT__mem_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3038412244204909205ull);
    vlSelf->ysyx_25030077_top__DOT__ALU_data_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10605335588819089977ull);
    vlSelf->ysyx_25030077_top__DOT__ALU_data_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10566019785287598843ull);
    vlSelf->ysyx_25030077_top__DOT__i0__DOT__state = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4547209301736471496ull);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 952889539391445529ull);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___issrai_T_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4916142133664097322ull);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___isadd_T_3 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8574051958325915529ull);
    vlSelf->ysyx_25030077_top__DOT__i3__DOT__Imm_type1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8771657348136028346ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8729454563798133033ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3314648234123829289ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1238933419270665930ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2406257397402018517ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9956502564455477251ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_5 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1731920318234896351ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_6 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6027853594055628782ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_7 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11328171878863742997ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17988461532225159606ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6520840493019924281ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16670884285630197163ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12920139751779413610ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17489771229956778537ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7174530808552075235ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5496983594510505857ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13881659562540954416ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14702508189882252125ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_17 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9418063048769352145ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_18 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1961511866161617553ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_19 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17096110260535467467ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_20 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14363483415460866513ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_21 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5180097725225990693ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_22 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2018109744176186805ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_23 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11449260246188549593ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_24 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3992709063580843673ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_25 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1812418115414846974ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_26 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3361791459914142550ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_27 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5811015328892672346ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_28 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4786436755804809483ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_29 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6906932232853266449ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_30 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1452313099808080127ull);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_31 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5854152459447714148ull);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT__addResult = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 950076269584105077ull);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT__subResult = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 13072856727825326455ull);
    vlSelf->ysyx_25030077_top__DOT__i7__DOT__is_eql = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1334325471378988014ull);
    vlSelf->ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2390908093461220299ull);
    vlSelf->ysyx_25030077_top__DOT__i9__DOT__index = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1279052732485605730ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
