// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rs2_out = vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_0;
    vlSelfRef.ysyx_25020077_top__DOT__i0__DOT___nextState_T_2 
        = ((IData)(4U) + vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state);
    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state, vlSelfRef.__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout);
    vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
        = vlSelfRef.__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(vlSelfRef.ysyx_25020077_top__DOT__instruction_out, vlSelfRef.__Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout);
    vlSelfRef.is_break_out = vlSelfRef.__Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout;
    vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type 
        = ((0x380U & (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                      >> 5U)) | (0x7fU & vlSelfRef.ysyx_25020077_top__DOT__instruction_out));
    if ((0x13U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type))) {
        vlSelfRef.rd = (0x1fU & (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                 >> 7U));
        vlSelfRef.ALU_ctrl = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__rs1 = (0x1fU 
                                                 & (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                                    >> 0xfU));
    } else {
        vlSelfRef.rd = 0U;
        vlSelfRef.ALU_ctrl = 7U;
        vlSelfRef.ysyx_25020077_top__DOT__rs1 = 0U;
    }
    if ((1U == ((0x13U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                 ? 1U : 0U))) {
        vlSelfRef.ysyx_25020077_top__DOT__i5__DOT____VdfgRegularize_h7d8bcb34_0_4 
            = (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
               >> 0x1fU);
        vlSelfRef.imm = ((((vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                            >> 0x1fU) ? 0xfffffU : 0U) 
                          << 0xcU) | (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                      >> 0x14U));
    } else {
        vlSelfRef.ysyx_25020077_top__DOT__i5__DOT____VdfgRegularize_h7d8bcb34_0_4 = 0U;
        vlSelfRef.imm = 0U;
    }
    vlSelfRef.ysyx_25020077_top__DOT__i4__DOT___GEN_53 
        = ((0x15U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
            ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_21
            : ((0x14U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_20
                : ((0x13U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                    ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_19
                    : ((0x12U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                        ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_18
                        : ((0x11U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                            ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_17
                            : ((0x10U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_16
                                : ((0xfU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                    ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_15
                                    : ((0xeU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                        ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_14
                                        : ((0xdU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                            ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_13
                                            : ((0xcU 
                                                == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                    ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                     ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                      ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                       ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                        ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                         ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                          ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                           ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                            ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                             ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                              ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_1
                                                              : vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_0)))))))))))))))))))));
    vlSelfRef.rs1_out = ((0x1fU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                          ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_31
                          : ((0x1eU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                              ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_30
                              : ((0x1dU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                  ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_29
                                  : ((0x1cU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                      ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_28
                                      : ((0x1bU == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                          ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_27
                                          : ((0x1aU 
                                              == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                              ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_26
                                              : ((0x19U 
                                                  == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                  ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_25
                                                  : 
                                                 ((0x18U 
                                                   == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                   ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_24
                                                   : 
                                                  ((0x17U 
                                                    == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                    ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_23
                                                    : 
                                                   ((0x16U 
                                                     == (IData)(vlSelfRef.ysyx_25020077_top__DOT__rs1))
                                                     ? vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_22
                                                     : vlSelfRef.ysyx_25020077_top__DOT__i4__DOT___GEN_53))))))))));
    vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_13 
        = (vlSelfRef.rs1_out & vlSelfRef.imm);
    vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_15 
        = (vlSelfRef.rs1_out | vlSelfRef.imm);
    vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_17 
        = (vlSelfRef.rs1_out ^ vlSelfRef.imm);
    vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__addResult 
        = (0x1ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.rs1_out) 
                             + VL_EXTENDS_QI(33,32, vlSelfRef.imm)));
    vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__subResult 
        = (0x1ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelfRef.rs1_out) 
                             - VL_EXTENDS_QI(33,32, vlSelfRef.imm)));
    vlSelfRef.ALU_carry = (1U & ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                                  & (IData)((vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__addResult 
                                             >> 0x20U))) 
                                 | (IData)(((vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__subResult 
                                             >> 0x20U) 
                                            & (((IData)(1U) 
                                                << (IData)(vlSelfRef.ALU_ctrl)) 
                                               >> 1U)))));
    vlSelfRef.ALU_overflow = ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                               & (((vlSelfRef.rs1_out 
                                    >> 0x1fU) == (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT____VdfgRegularize_h7d8bcb34_0_4)) 
                                  & ((vlSelfRef.rs1_out 
                                      >> 0x1fU) != 
                                     (1U & (IData)(
                                                   (vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__addResult 
                                                    >> 0x1fU)))))) 
                              | (1U & ((((IData)(1U) 
                                         << (IData)(vlSelfRef.ALU_ctrl)) 
                                        >> 1U) & ((
                                                   (vlSelfRef.rs1_out 
                                                    >> 0x1fU) 
                                                   != (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT____VdfgRegularize_h7d8bcb34_0_4)) 
                                                  & ((vlSelfRef.rs1_out 
                                                      >> 0x1fU) 
                                                     != 
                                                     (1U 
                                                      & (IData)(
                                                                (vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__subResult 
                                                                 >> 0x1fU))))))));
    vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47 
        = ((((((1U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
                ? vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__addResult
                : 0ULL) | ((2U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
                            ? vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__subResult
                            : 0ULL)) | ((4U & ((IData)(1U) 
                                               << (IData)(vlSelfRef.ALU_ctrl)))
                                         ? (((QData)((IData)(
                                                             (vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_13 
                                                              >> 0x1fU))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_13)))
                                         : 0ULL)) | 
            ((8U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
              ? (((QData)((IData)((vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_15 
                                   >> 0x1fU))) << 0x20U) 
                 | (QData)((IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_15)))
              : 0ULL)) | ((0x10U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
                           ? (((QData)((IData)((vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_17 
                                                >> 0x1fU))) 
                               << 0x20U) | (QData)((IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_17)))
                           : 0ULL));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vm_traceActivitySetAll\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->imm = VL_RAND_RESET_I(32);
    vlSelf->rd = VL_RAND_RESET_I(5);
    vlSelf->ALU_ctrl = VL_RAND_RESET_I(3);
    vlSelf->rs1_out = VL_RAND_RESET_I(32);
    vlSelf->rs2_out = VL_RAND_RESET_I(32);
    vlSelf->ALU_carry = VL_RAND_RESET_I(1);
    vlSelf->ALU_overflow = VL_RAND_RESET_I(1);
    vlSelf->is_break_out = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25020077_top__DOT__instruction_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25020077_top__DOT__i0__DOT__state = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i0__DOT___nextState_T_2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type = VL_RAND_RESET_I(10);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_3 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_4 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_5 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_6 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_7 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_8 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_9 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_10 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_11 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_12 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_13 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_14 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_15 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_16 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_17 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_18 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_19 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_20 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_21 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_22 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_23 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_24 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_25 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_26 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_27 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_28 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_29 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_30 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_31 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i4__DOT___GEN_53 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult = VL_RAND_RESET_Q(33);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult = VL_RAND_RESET_Q(33);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_13 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_15 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_17 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47 = VL_RAND_RESET_Q(33);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT____VdfgRegularize_h7d8bcb34_0_4 = VL_RAND_RESET_I(1);
    vlSelf->__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
