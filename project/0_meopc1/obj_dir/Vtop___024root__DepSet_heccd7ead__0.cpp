// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->ysyx_25020077_top__DOT__i0__DOT__state = 0x80000000U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_30 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_25 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_26 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_31 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_22 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_29 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_27 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_23 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_28 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_24 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_21 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_20 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_9 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_8 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_7 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_6 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_5 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_4 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_3 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_1 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_2 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_10 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_11 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_12 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_13 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_14 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_15 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_16 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_17 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_18 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_19 = 0U;
        vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0 = 0U;
    } else {
        vlSelf->ysyx_25020077_top__DOT__i0__DOT__state 
            = ((0x80000010U == vlSelf->ysyx_25020077_top__DOT__i0__DOT__state)
                ? 0x80000000U : vlSelf->ysyx_25020077_top__DOT__i0__DOT___nextState_T_2);
        if ((0x1eU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_30 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x19U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_25 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1aU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_26 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1fU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_31 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x16U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_22 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1dU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_29 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1bU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_27 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x17U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_23 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x1cU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_28 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x18U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_24 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x15U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_21 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x14U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_20 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((9U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_9 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((8U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_8 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((7U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_7 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((6U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_6 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((5U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_5 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((4U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_4 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((3U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_3 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((1U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_1 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((2U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_2 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xaU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_10 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xbU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_11 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xcU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_12 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xdU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_13 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xeU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_14 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0xfU == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_15 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x10U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_16 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x11U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_17 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x12U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_18 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0x13U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_19 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
        if ((0U == (IData)(vlSelf->rd))) {
            vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0 
                = ((0U != (IData)(vlSelf->rd)) ? (IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)
                    : 0U);
        }
    }
    vlSelf->ysyx_25020077_top__DOT__i0__DOT___nextState_T_2 
        = ((IData)(4U) + vlSelf->ysyx_25020077_top__DOT__i0__DOT__state);
    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(vlSelf->ysyx_25020077_top__DOT__i0__DOT__state, vlSelf->__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout);
    vlSelf->ysyx_25020077_top__DOT__instruction_out 
        = vlSelf->__Vfunc_ysyx_25020077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
    vlSelf->rs2_out = vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0;
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
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
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
