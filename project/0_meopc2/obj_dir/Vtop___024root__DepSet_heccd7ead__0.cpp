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

void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i7__DOT__ecall_read_TOP(IData/*31:0*/ pc, CData/*3:0*/ type_p, IData/*31:0*/ &ecall_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i9__DOT__mem_data_read_TOP(IData/*31:0*/ instruction_in, IData/*31:0*/ rs1_data_in, IData/*31:0*/ rs2_data_in, IData/*31:0*/ imm_data_in, IData/*31:0*/ &mem_data_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i6__DOT__csr_read_TOP(IData/*31:0*/ rs1, IData/*31:0*/ imm, CData/*3:0*/ sw, IData/*31:0*/ &csr_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((((IData)(vlSelfRef.ysyx_25030077_top__DOT__is_break_out) 
                      & (~ (IData)(vlSelfRef.reset)))))) {
        VL_WRITEF_NX("\346\243\200\346\265\213\345\210\260break\346\214\207\344\273\244, \344\273\277\347\234\237\351\200\200\345\207\272! \345\275\223\345\211\215PC = 0x%08x\n",0,
                     32,vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state);
        VL_FINISH_MT("vsrc/ysyx_25030077_EXIT.v", 12, "");
        VL_FINISH_MT("vsrc/ysyx_25030077_EXIT.v", 13, "");
    }
    if (VL_UNLIKELY((((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)) 
                      & (~ (IData)(vlSelfRef.reset)))))) {
        VL_WRITEF_NX("\346\243\200\346\265\213\345\210\260\346\234\252\347\237\245\346\214\207\344\273\244, \344\273\277\347\234\237\351\200\200\345\207\272! \345\275\223\345\211\215PC = 0x%08x\n",0,
                     32,vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state);
        VL_FINISH_MT("vsrc/ysyx_25030077_EXIT.v", 20, "");
        VL_FINISH_MT("vsrc/ysyx_25030077_EXIT.v", 21, "");
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_11 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_10 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_24 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_2 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_28 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_23 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_1 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_27 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_3 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_29 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_22 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_31 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_26 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_25 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_4 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_30 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_5 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_6 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_7 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_8 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_9 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21 = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state = 0x80000000U;
    } else {
        if ((0x13U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x12U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x11U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x10U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0xfU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0xeU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0xdU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0xcU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0xbU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_11 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0xaU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_10 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x18U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_24 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((2U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_2 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x1cU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_28 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x17U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_23 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((1U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_1 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x1bU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_27 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((3U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_3 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x1dU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_29 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x16U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_22 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x1fU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_31 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x1aU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_26 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x19U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_25 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((4U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_4 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x1eU == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_30 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((5U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_5 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((6U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_6 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((7U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_7 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((8U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_8 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((9U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_9 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x14U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        if ((0x15U == (IData)(vlSelfRef.rd))) {
            vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21 
                = ((0U != (IData)(vlSelfRef.rd)) ? vlSelfRef.ysyx_25030077_top__DOT__ALU_result
                    : 0U);
        }
        vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state 
            = vlSelfRef.ysyx_25030077_top__DOT__Pc_next;
    }
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i1__DOT__addr_read_TOP(vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state, vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i1__DOT__addr_read__0__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
        = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i1__DOT__addr_read__0__Vfuncout;
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i2__DOT__is_break_TOP(vlSelfRef.ysyx_25030077_top__DOT__instruction_out, vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i2__DOT__is_break__1__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__is_break_out 
        = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i2__DOT__is_break__1__Vfuncout;
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
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i7__DOT__ecall_read_TOP(vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state, (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type), vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i7__DOT__ecall_read__3__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc 
        = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i7__DOT__ecall_read__3__Vfuncout;
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
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i9__DOT__mem_data_read_TOP(vlSelfRef.ysyx_25030077_top__DOT__instruction_out, vlSelfRef.rs1_out, vlSelfRef.rs2_out, vlSelfRef.imm, vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i9__DOT__mem_data_read__4__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__mem_data = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i9__DOT__mem_data_read__4__Vfuncout;
    vlSelfRef.ysyx_25030077_top__DOT__Pc_next = (((0xbU 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)) 
                                                  | (0xcU 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)))
                                                  ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc
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
    vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 = 
        ((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
          ? vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state
          : ((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
              ? vlSelfRef.ysyx_25030077_top__DOT__mem_data
              : vlSelfRef.rs1_out));
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i6__DOT__csr_read_TOP(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2, (IData)(vlSelfRef.ALU_ctrl), vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i6__DOT__csr_read__2__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__csr_data 
        = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i6__DOT__csr_read__2__Vfuncout;
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
    vlSelfRef.ysyx_25030077_top__DOT__ALU_result = 
        ((1U & ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                 >> 0xbU) | (((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                             >> 0xcU))) ? vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__csr_data
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
