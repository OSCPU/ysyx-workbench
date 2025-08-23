// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state = 0x80000000U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_24 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_28 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_23 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_27 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_29 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_22 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_31 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_26 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_25 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_30 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_19 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_18 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_17 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_16 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_15 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_14 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_13 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_12 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_11 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_10 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_2 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_1 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_3 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_4 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_5 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_6 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_7 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_8 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_9 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_20 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_21 = 0U;
        vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_0 = 0U;
    } else {
        vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state 
            = ((0x80000010U == vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state)
                ? 0x80000000U : vlSelfRef.ysyx_25020077_top__DOT__i0__DOT___nextState_T_2);
        if ((0x18U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_24 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1cU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_28 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x17U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_23 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1bU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_27 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1dU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_29 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x16U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_22 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1fU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_31 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1aU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_26 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x19U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_25 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1eU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_30 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x13U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_19 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x12U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_18 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x11U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_17 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x10U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_16 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xfU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_15 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xeU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_14 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xdU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_13 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xcU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_12 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xbU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_11 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xaU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_10 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((2U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_2 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((1U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_1 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((3U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_3 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((4U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_4 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((5U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_5 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((6U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_6 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((7U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_7 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((8U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_8 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((9U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_9 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x14U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_20 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x15U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_21 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_0 
                = ((0U != (IData)(vlSelfRef.rd)) ? (IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
    }
    vlSelfRef.ysyx_25020077_top__DOT__i0__DOT___nextState_T_2 
        = ((IData)(4U) + vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state);
    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state, vlSelfRef.__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout);
    vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
        = vlSelfRef.__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
    vlSelfRef.rs2_out = vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_0;
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

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
