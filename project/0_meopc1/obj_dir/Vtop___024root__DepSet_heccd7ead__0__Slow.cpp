// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
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
                VL_FATAL_MT("vsrc/top.v", 1, "", "Settle region did not converge.");
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

void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->rs2_out = vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0;
    vlSelf->ysyx_25020077_top__DOT__i0__DOT___nextState_T_2 
        = ((IData)(4U) + vlSelf->ysyx_25020077_top__DOT__i0__DOT__state);
    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(vlSelf->ysyx_25020077_top__DOT__i0__DOT__state, vlSelf->__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout);
    vlSelf->ysyx_25020077_top__DOT__instruction_out 
        = vlSelf->__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(vlSelf->ysyx_25020077_top__DOT__instruction_out, vlSelf->__Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout);
    vlSelf->is_break_out = vlSelf->__Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout;
    vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type 
        = ((0x380U & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                      >> 5U)) | (0x7fU & vlSelf->ysyx_25020077_top__DOT__instruction_out));
    if ((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))) {
        vlSelf->rd = (0x1fU & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                               >> 7U));
        vlSelf->ALU_ctrl = 0U;
        vlSelf->ysyx_25020077_top__DOT__rs1 = (0x1fU 
                                               & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                                  >> 0xfU));
    } else {
        vlSelf->rd = 0U;
        vlSelf->ALU_ctrl = 7U;
        vlSelf->ysyx_25020077_top__DOT__rs1 = 0U;
    }
    if ((1U == ((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                 ? 1U : 0U))) {
        vlSelf->ysyx_25020077_top__DOT__i5__DOT____VdfgTmp_h0adca177__0 
            = (vlSelf->ysyx_25020077_top__DOT__instruction_out 
               >> 0x1fU);
        vlSelf->imm = ((((vlSelf->ysyx_25020077_top__DOT__instruction_out 
                          >> 0x1fU) ? 0xfffffU : 0U) 
                        << 0xcU) | (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                    >> 0x14U));
    } else {
        vlSelf->ysyx_25020077_top__DOT__i5__DOT____VdfgTmp_h0adca177__0 = 0U;
        vlSelf->imm = 0U;
    }
    vlSelf->ysyx_25020077_top__DOT__i4__DOT___GEN_53 
        = ((0x15U == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
            ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_21
            : ((0x14U == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_20
                : ((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                    ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_19
                    : ((0x12U == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                        ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_18
                        : ((0x11U == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                            ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_17
                            : ((0x10U == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_16
                                : ((0xfU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                    ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_15
                                    : ((0xeU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                        ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_14
                                        : ((0xdU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                            ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_13
                                            : ((0xcU 
                                                == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_12
                                                : (
                                                   (0xbU 
                                                    == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                    ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_11
                                                    : 
                                                   ((0xaU 
                                                     == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                     ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_10
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                      ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_9
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                       ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_8
                                                       : 
                                                      ((7U 
                                                        == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                        ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_7
                                                        : 
                                                       ((6U 
                                                         == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                         ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_6
                                                         : 
                                                        ((5U 
                                                          == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                          ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_5
                                                          : 
                                                         ((4U 
                                                           == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                           ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_4
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                            ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_3
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                             ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_2
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                              ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_1
                                                              : vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0)))))))))))))))))))));
    vlSelf->rs1_out = ((0x1fU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                        ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_31
                        : ((0x1eU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                            ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_30
                            : ((0x1dU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_29
                                : ((0x1cU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                    ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_28
                                    : ((0x1bU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                        ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_27
                                        : ((0x1aU == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                            ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_26
                                            : ((0x19U 
                                                == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_25
                                                : (
                                                   (0x18U 
                                                    == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                    ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_24
                                                    : 
                                                   ((0x17U 
                                                     == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                     ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_23
                                                     : 
                                                    ((0x16U 
                                                      == (IData)(vlSelf->ysyx_25020077_top__DOT__rs1))
                                                      ? vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_22
                                                      : vlSelf->ysyx_25020077_top__DOT__i4__DOT___GEN_53))))))))));
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_13 
        = (vlSelf->rs1_out & vlSelf->imm);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_15 
        = (vlSelf->rs1_out | vlSelf->imm);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_17 
        = (vlSelf->rs1_out ^ vlSelf->imm);
    vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult 
        = (0x1ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelf->rs1_out) 
                             + VL_EXTENDS_QI(33,32, vlSelf->imm)));
    vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult 
        = (0x1ffffffffULL & (VL_EXTENDS_QI(33,32, vlSelf->rs1_out) 
                             - VL_EXTENDS_QI(33,32, vlSelf->imm)));
    vlSelf->ALU_carry = (1U & ((((IData)(1U) << (IData)(vlSelf->ALU_ctrl)) 
                                & (IData)((vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult 
                                           >> 0x20U))) 
                               | (0x7fU & ((((IData)(1U) 
                                             << (IData)(vlSelf->ALU_ctrl)) 
                                            >> 1U) 
                                           & (IData)(
                                                     (vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult 
                                                      >> 0x20U))))));
    vlSelf->ALU_overflow = ((((IData)(1U) << (IData)(vlSelf->ALU_ctrl)) 
                             & (((vlSelf->rs1_out >> 0x1fU) 
                                 == (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT____VdfgTmp_h0adca177__0)) 
                                & ((vlSelf->rs1_out 
                                    >> 0x1fU) != (1U 
                                                  & (IData)(
                                                            (vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult 
                                                             >> 0x1fU)))))) 
                            | (0x7fU & ((((IData)(1U) 
                                          << (IData)(vlSelf->ALU_ctrl)) 
                                         >> 1U) & (
                                                   ((vlSelf->rs1_out 
                                                     >> 0x1fU) 
                                                    != (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT____VdfgTmp_h0adca177__0)) 
                                                   & ((vlSelf->rs1_out 
                                                       >> 0x1fU) 
                                                      != 
                                                      (1U 
                                                       & (IData)(
                                                                 (vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult 
                                                                  >> 0x1fU))))))));
    vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47 
        = ((((((1U & ((IData)(1U) << (IData)(vlSelf->ALU_ctrl)))
                ? vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult
                : 0ULL) | ((2U & ((IData)(1U) << (IData)(vlSelf->ALU_ctrl)))
                            ? vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult
                            : 0ULL)) | ((4U & ((IData)(1U) 
                                               << (IData)(vlSelf->ALU_ctrl)))
                                         ? (((QData)((IData)(
                                                             (vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_13 
                                                              >> 0x1fU))) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_13)))
                                         : 0ULL)) | 
            ((8U & ((IData)(1U) << (IData)(vlSelf->ALU_ctrl)))
              ? (((QData)((IData)((vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_15 
                                   >> 0x1fU))) << 0x20U) 
                 | (QData)((IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_15)))
              : 0ULL)) | ((0x10U & ((IData)(1U) << (IData)(vlSelf->ALU_ctrl)))
                           ? (((QData)((IData)((vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_17 
                                                >> 0x1fU))) 
                               << 0x20U) | (QData)((IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_17)))
                           : 0ULL));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
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
    vlSelf->ysyx_25020077_top__DOT__i5__DOT____VdfgTmp_h0adca177__0 = 0;
    vlSelf->__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25020077_top__DOT__i2__DOT__is_break__1__Vfuncout = 0;
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
