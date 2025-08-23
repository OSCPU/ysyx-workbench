// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__d_idu__DOT___GEN_0 = ((IData)(vlSelfRef.reset)
                                               ? 0U
                                               : ((IData)(vlSelfRef.top__DOT__d_idu__DOT___validReg_T)
                                                   ? (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg)
                                                   : (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)));
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ top__DOT__d_idu__DOT___rs1_reg_T_12;
    top__DOT__d_idu__DOT___rs1_reg_T_12 = 0;
    CData/*4:0*/ top__DOT__d_idu__DOT___rd_reg_T_12;
    top__DOT__d_idu__DOT___rd_reg_T_12 = 0;
    CData/*4:0*/ top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19;
    top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0;
    IData/*31:0*/ top__DOT__f_gpr__DOT___GEN_21;
    top__DOT__f_gpr__DOT___GEN_21 = 0;
    IData/*31:0*/ top__DOT__f_gpr__DOT___GEN_85;
    top__DOT__f_gpr__DOT___GEN_85 = 0;
    IData/*31:0*/ top__DOT__f_gpr__DOT___GEN_117;
    top__DOT__f_gpr__DOT___GEN_117 = 0;
    IData/*31:0*/ top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T;
    top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0;
    __VdlyVal__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0;
    __VdlySet__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 0;
    // Body
    __VdlySet__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 0U;
    if (vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en) {
        __VdlyVal__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 
            = vlSelfRef.top__DOT__j_pc_next__DOT__pc_next_reg;
        __VdlySet__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 1U;
    }
    vlSelfRef.top__DOT__j_pc_next__DOT__validReg = 
        ((1U & (~ (IData)(vlSelfRef.reset))) && (((IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg) 
                                                  & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept)) 
                                                 | (IData)(vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T_1)));
    vlSelfRef.top__DOT__f_gpr__DOT__validReg = ((1U 
                                                 & (~ (IData)(vlSelfRef.reset))) 
                                                && ((IData)(vlSelfRef.top__DOT__f_gpr__DOT___regs_T) 
                                                    | (IData)(vlSelfRef.top__DOT__f_gpr__DOT___validReg_T_1)));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o = 0U;
        vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o = 0U;
        vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o = 0U;
        vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o = 0U;
        vlSelfRef.top__DOT__j_pc_next__DOT__is_unknown_instruction_reg = 0U;
        vlSelfRef.io_is_unknown_instruction = vlSelfRef.top__DOT__j_pc_next__DOT__is_unknown_instruction_reg;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_0 = 0U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_1 = 1U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_2 = 2U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_3 = 3U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_4 = 4U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_5 = 5U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_6 = 6U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_7 = 7U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_8 = 8U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_9 = 9U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_10 = 0xaU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_11 = 0xbU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_12 = 0xcU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_13 = 0xdU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_14 = 0xeU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_15 = 0xfU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_16 = 0x10U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_17 = 0x11U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_18 = 0x12U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_19 = 0x13U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_20 = 0x14U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_21 = 0x15U;
    } else {
        if (vlSelfRef.top__DOT__d_idu__DOT___validReg_T) {
            if ((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o = 1U;
                vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o 
                    = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                >> 0xfU));
            } else if ((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o = 1U;
                vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o 
                    = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                >> 0xfU));
            } else if ((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o = 1U;
                vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o 
                    = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                >> 0xfU));
            } else if ((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o = 1U;
                vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o 
                    = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                >> 0xfU));
            } else {
                vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o 
                    = vlSelfRef.top__DOT__d_idu__DOT___imm_type_reg_T_18;
                vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o 
                    = (0x1fU & ((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                 ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                    >> 0xfU) : ((0x173U 
                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                 ? 
                                                (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                 >> 0xfU)
                                                 : 
                                                ((0x4293U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                  ? 
                                                 (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU)
                                                  : 
                                                 ((0x293U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                   ? 
                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                   >> 0xfU)
                                                   : 
                                                  ((0x93U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                    ? 
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 0xfU)
                                                    : 
                                                   ((0x193U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                     >> 0xfU)
                                                     : (IData)(vlSelfRef.top__DOT__d_idu__DOT___rs1_reg_T_25))))))));
            }
            vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o 
                = ((0x17U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                    ? 1U : ((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                             ? 1U : ((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                      ? 1U : ((0x123U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 0U
                                               : ((0x23U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 0U
                                                   : 
                                                  ((0xa3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 0U
                                                    : 
                                                   ((0x103U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : (IData)(vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19))))))));
            vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o 
                = (0x1fU & ((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                             ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                >> 0x14U) : ((0x23U 
                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                              ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                 >> 0x14U)
                                              : ((0xa3U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                  ? 
                                                 (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0x14U)
                                                  : 
                                                 ((0x33U 
                                                   == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                   ? 
                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                   >> 0x14U)
                                                   : 
                                                  ((0x3b3U 
                                                    == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                    ? 
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 0x14U)
                                                    : 
                                                   ((0xb3U 
                                                     == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                     ? 
                                                    (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                     >> 0x14U)
                                                     : (IData)(vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12))))))));
        }
        if (vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T) {
            vlSelfRef.top__DOT__j_pc_next__DOT__is_unknown_instruction_reg 
                = (3U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg));
        }
        vlSelfRef.io_is_unknown_instruction = vlSelfRef.top__DOT__j_pc_next__DOT__is_unknown_instruction_reg;
        if ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_0 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((1U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_1 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((2U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_2 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((3U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_3 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((4U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_4 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((5U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_5 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((6U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_6 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((7U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_7 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((8U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_8 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((9U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_9 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0xaU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_10 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0xbU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_11 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0xcU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_12 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0xdU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_13 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0xeU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_14 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0xfU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_15 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x10U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_16 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x11U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_17 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x12U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_18 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x13U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_19 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x14U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_20 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x15U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_21 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
    }
    top__DOT__f_gpr__DOT___GEN_85 = ((0x15U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_21
                                      : ((0x14U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_20
                                          : ((0x13U 
                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_19
                                              : ((0x12U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_18
                                                  : 
                                                 ((0x11U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_17
                                                   : 
                                                  ((0x10U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_16
                                                    : 
                                                   ((0xfU 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_15
                                                     : 
                                                    ((0xeU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_14
                                                      : 
                                                     ((0xdU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_13
                                                       : 
                                                      ((0xcU 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_12
                                                        : 
                                                       ((0xbU 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_11
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_10
                                                          : 
                                                         ((9U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_9
                                                           : 
                                                          ((8U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_8
                                                            : 
                                                           ((7U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_7
                                                             : 
                                                            ((6U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_6
                                                              : 
                                                             ((5U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_5
                                                               : 
                                                              ((4U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_4
                                                                : 
                                                               ((3U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                                 ? vlSelfRef.top__DOT__f_gpr__DOT__regs_3
                                                                 : 
                                                                ((2U 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_2
                                                                  : 
                                                                 ((1U 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_1
                                                                   : vlSelfRef.top__DOT__f_gpr__DOT__regs_0)))))))))))))))))))));
    top__DOT__f_gpr__DOT___GEN_117 = ((0x15U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_21
                                       : ((0x14U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_20
                                           : ((0x13U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_19
                                               : ((0x12U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_18
                                                   : 
                                                  ((0x11U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_17
                                                    : 
                                                   ((0x10U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_16
                                                     : 
                                                    ((0xfU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_15
                                                      : 
                                                     ((0xeU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_14
                                                       : 
                                                      ((0xdU 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_13
                                                        : 
                                                       ((0xcU 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_12
                                                         : 
                                                        ((0xbU 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_11
                                                          : 
                                                         ((0xaU 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_10
                                                           : 
                                                          ((9U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_9
                                                            : 
                                                           ((8U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_8
                                                             : 
                                                            ((7U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_7
                                                              : 
                                                             ((6U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_6
                                                               : 
                                                              ((5U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_5
                                                                : 
                                                               ((4U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                                 ? vlSelfRef.top__DOT__f_gpr__DOT__regs_4
                                                                 : 
                                                                ((3U 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_3
                                                                  : 
                                                                 ((2U 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_2
                                                                   : 
                                                                  ((1U 
                                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_1
                                                                    : vlSelfRef.top__DOT__f_gpr__DOT__regs_0)))))))))))))))))))));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__f_gpr__DOT__regs_22 = 0x16U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_23 = 0x17U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_24 = 0x18U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_25 = 0x19U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_26 = 0x1aU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_27 = 0x1bU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_28 = 0x1cU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_29 = 0x1dU;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_30 = 0x1eU;
        vlSelfRef.top__DOT__j_pc_next__DOT__pc_next_reg = 0x413U;
        vlSelfRef.top__DOT__f_gpr__DOT__regs_31 = 0x1fU;
    } else {
        if ((0x16U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_22 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x17U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_23 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x18U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_24 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x19U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_25 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x1aU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_26 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x1bU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_27 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x1cU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_28 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x1dU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_29 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if ((0x1eU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            vlSelfRef.top__DOT__f_gpr__DOT__regs_30 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                    & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))
                    ? ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg)
                    : ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.top__DOT__f_gpr__DOT___GEN_30));
        }
        if (vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T) {
            vlSelfRef.top__DOT__j_pc_next__DOT__pc_next_reg 
                = ((1U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                    ? (vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg 
                       + (((((vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                              >> 0x1fU) ? 0x7ffU : 0U) 
                            << 0x15U) | (0x100000U 
                                         & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                            >> 0xbU))) 
                          | (((0xff000U & vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg) 
                              | (0x800U & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                           >> 9U))) 
                             | (0x7feU & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                          >> 0x14U)))))
                    : ((2U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                        ? (0xfffffffeU & (vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                          + ((((vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                                >> 0x1fU)
                                                ? 0xfffffU
                                                : 0U) 
                                              << 0xcU) 
                                             | (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                                >> 0x14U))))
                        : ((4U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                            ? vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg
                            : ((6U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                                ? ((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                    ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                    : ((IData)(4U) 
                                       + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))
                                : ((5U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                                    ? ((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                        ? ((IData)(4U) 
                                           + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg)
                                        : vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9)
                                    : ((7U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                                        ? (VL_GTES_III(32, vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg, vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                            ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                            : ((IData)(4U) 
                                               + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))
                                        : ((8U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                                            ? ((vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                                >= vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                                ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                : ((IData)(4U) 
                                                   + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))
                                            : ((9U 
                                                == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                                                ? (
                                                   VL_LTS_III(32, vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg, vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                                    ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))
                                                : (
                                                   (0xaU 
                                                    == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))
                                                    ? 
                                                   ((vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                                     < vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                                     ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))))))))));
        }
        if ((0x1fU == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
            if (((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                 & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept))) {
                vlSelfRef.top__DOT__f_gpr__DOT__regs_31 
                    = ((0U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                        ? 0U : vlSelfRef.top__DOT__i_alu__DOT__out_reg);
            } else if ((0x1fU != (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))) {
                vlSelfRef.top__DOT__f_gpr__DOT__regs_31 
                    = vlSelfRef.top__DOT__f_gpr__DOT___GEN_30;
            }
        }
    }
    vlSelfRef.top__DOT__i_alu__DOT__validReg = ((1U 
                                                 & (~ (IData)(vlSelfRef.reset))) 
                                                && (((IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg) 
                                                     & (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept)) 
                                                    | (IData)(vlSelfRef.top__DOT__i_alu__DOT___validReg_T_1)));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg = 0U;
        vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg = 0U;
    } else if (vlSelfRef.top__DOT__f_gpr__DOT___regs_T) {
        vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
            = vlSelfRef.top__DOT__i_alu__DOT__rs1_data_reg;
        vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg 
            = vlSelfRef.top__DOT__i_alu__DOT__rs2_data_reg;
    }
    vlSelfRef.top__DOT__j_pc_next__DOT__is_eql = (vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                                  == vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg);
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg = 0x413U;
        vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg = 0x413U;
    } else if (vlSelfRef.top__DOT__f_gpr__DOT___regs_T) {
        vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg 
            = vlSelfRef.top__DOT__i_alu__DOT__pc_count_reg;
        vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
            = vlSelfRef.top__DOT__i_alu__DOT__instruction_reg;
    }
    vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9 
        = (vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg 
           + ((((vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                 >> 0x1fU) ? 0x7ffffU : 0U) << 0xdU) 
              | (((0x1000U & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                              >> 0x13U)) | (0x800U 
                                            & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                               << 4U))) 
                 | ((0x7e0U & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                               >> 0x14U)) | (0x1eU 
                                             & (vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg 
                                                >> 7U))))));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg = 0U;
        vlSelfRef.top__DOT__i_alu__DOT__out_reg = 0U;
    } else {
        if (vlSelfRef.top__DOT__f_gpr__DOT___regs_T) {
            vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg 
                = vlSelfRef.top__DOT__i_alu__DOT__pc_next_type_reg;
        }
        if (vlSelfRef.top__DOT__i_alu__DOT___validReg_T) {
            vlSelfRef.top__DOT__i_alu__DOT__out_reg 
                = (((IData)(vlSelfRef.top__DOT__i_alu__DOT___out33_T_47) 
                    | (IData)(((0x200U & ((IData)(1U) 
                                          << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                ? (QData)((IData)((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                                   >> (IData)(vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0))))
                                : 0ULL))) | (IData)(
                                                    ((0x400U 
                                                      & ((IData)(1U) 
                                                         << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                      ? (QData)((IData)(
                                                                        VL_LTS_III(32, vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1, vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                      : 0ULL)));
        }
    }
    vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o 
        = (0xfU & (IData)(vlSelfRef.top__DOT__d_idu__DOT___GEN_0));
    vlSelfRef.top__DOT__d_idu__DOT__validReg = ((1U 
                                                 & (~ (IData)(vlSelfRef.reset))) 
                                                && (((IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg) 
                                                     & (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept)) 
                                                    | (IData)(vlSelfRef.top__DOT__d_idu__DOT___validReg_T_1)));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg = 0U;
    } else if (vlSelfRef.top__DOT__i_alu__DOT___validReg_T) {
        vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg 
            = vlSelfRef.top__DOT__d_idu__DOT__rd_reg_o;
    }
    top__DOT__f_gpr__DOT___GEN_21 = ((0x15U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_21
                                      : ((0x14U == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_20
                                          : ((0x13U 
                                              == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_19
                                              : ((0x12U 
                                                  == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_18
                                                  : 
                                                 ((0x11U 
                                                   == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_17
                                                   : 
                                                  ((0x10U 
                                                    == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_16
                                                    : 
                                                   ((0xfU 
                                                     == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_15
                                                     : 
                                                    ((0xeU 
                                                      == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_14
                                                      : 
                                                     ((0xdU 
                                                       == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_13
                                                       : 
                                                      ((0xcU 
                                                        == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_12
                                                        : 
                                                       ((0xbU 
                                                         == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_11
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_10
                                                          : 
                                                         ((9U 
                                                           == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_9
                                                           : 
                                                          ((8U 
                                                            == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_8
                                                            : 
                                                           ((7U 
                                                             == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_7
                                                             : 
                                                            ((6U 
                                                              == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_6
                                                              : 
                                                             ((5U 
                                                               == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_5
                                                               : 
                                                              ((4U 
                                                                == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_4
                                                                : 
                                                               ((3U 
                                                                 == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                                 ? vlSelfRef.top__DOT__f_gpr__DOT__regs_3
                                                                 : 
                                                                ((2U 
                                                                  == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_2
                                                                  : 
                                                                 ((1U 
                                                                   == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_1
                                                                   : vlSelfRef.top__DOT__f_gpr__DOT__regs_0)))))))))))))))))))));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__i_alu__DOT__rs1_data_reg = 0U;
    } else if (vlSelfRef.top__DOT__i_alu__DOT___validReg_T) {
        vlSelfRef.top__DOT__i_alu__DOT__rs1_data_reg 
            = vlSelfRef.top__DOT__f_gpr_io_rdata_rs1;
    }
    vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 = ((0x1fU 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                                               : ((0x1eU 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_30
                                                   : 
                                                  ((0x1dU 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_22
                                                           : top__DOT__f_gpr__DOT___GEN_85))))))))));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__i_alu__DOT__rs2_data_reg = 0U;
    } else if (vlSelfRef.top__DOT__i_alu__DOT___validReg_T) {
        vlSelfRef.top__DOT__i_alu__DOT__rs2_data_reg 
            = vlSelfRef.top__DOT__f_gpr_io_rdata_rs2;
    }
    vlSelfRef.top__DOT__f_gpr_io_rdata_rs2 = ((0x1fU 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                                               : ((0x1eU 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_30
                                                   : 
                                                  ((0x1dU 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_22
                                                           : top__DOT__f_gpr__DOT___GEN_117))))))))));
    vlSelfRef.top__DOT__f_gpr__DOT___GEN_30 = ((0x1eU 
                                                == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_30
                                                : (
                                                   (0x1dU 
                                                    == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_22
                                                           : top__DOT__f_gpr__DOT___GEN_21)))))))));
    vlSelfRef.top__DOT__c_sram__DOT__validReg = ((1U 
                                                  & (~ (IData)(vlSelfRef.reset))) 
                                                 && (((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
                                                      & (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready)) 
                                                     | (IData)(vlSelfRef.top__DOT__c_sram__DOT___validReg_T_1)));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__i_alu__DOT__pc_count_reg = 0x413U;
        vlSelfRef.top__DOT__i_alu__DOT__instruction_reg = 0x413U;
        vlSelfRef.top__DOT__i_alu__DOT__pc_next_type_reg = 0U;
        vlSelfRef.top__DOT__d_idu__DOT__rd_reg_o = 0U;
        vlSelfRef.top__DOT__d_idu__DOT__pc_reg = 0x413U;
        vlSelfRef.top__DOT__d_idu__DOT__inst_reg = 0x413U;
    } else {
        if (vlSelfRef.top__DOT__i_alu__DOT___validReg_T) {
            vlSelfRef.top__DOT__i_alu__DOT__pc_count_reg 
                = vlSelfRef.top__DOT__d_idu__DOT__pc_reg;
            vlSelfRef.top__DOT__i_alu__DOT__instruction_reg 
                = vlSelfRef.top__DOT__d_idu__DOT__inst_reg;
            vlSelfRef.top__DOT__i_alu__DOT__pc_next_type_reg 
                = vlSelfRef.top__DOT__d_idu__DOT__pc_next_type_reg_o;
        }
        if (vlSelfRef.top__DOT__d_idu__DOT___validReg_T) {
            vlSelfRef.top__DOT__d_idu__DOT__rd_reg_o 
                = (0x1fU & ((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                             ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                >> 7U) : ((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                           ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                              >> 7U)
                                           : ((0x313U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 7U)
                                               : ((0x393U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                   >> 7U)
                                                   : 
                                                  ((0xf3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 7U)
                                                    : (IData)(vlSelfRef.top__DOT__d_idu__DOT___rd_reg_T_24)))))));
            vlSelfRef.top__DOT__d_idu__DOT__pc_reg 
                = vlSelfRef.top__DOT__c_sram__DOT__pcReg;
            vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                = vlSelfRef.top__DOT__c_sram__DOT__instReg;
        }
    }
    vlSelfRef.top__DOT__e_imm_io_imm = ((1U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))
                                         ? ((((vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                               >> 0x1fU)
                                               ? 0xfffffU
                                               : 0U) 
                                             << 0xcU) 
                                            | (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                               >> 0x14U))
                                         : ((2U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))
                                             ? (0xfffff000U 
                                                & vlSelfRef.top__DOT__d_idu__DOT__inst_reg)
                                             : ((3U 
                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))
                                                 ? 4U
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))
                                                  ? 
                                                 ((((vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                                     >> 0x1fU)
                                                     ? 0xfffffU
                                                     : 0U) 
                                                   << 0xcU) 
                                                  | ((0xfe0U 
                                                      & (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                                           >> 7U))))
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))
                                                   ? 
                                                  (0x1fU 
                                                   & (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                                      >> 0x14U))
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))
                                                    ? 
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__d_idu__DOT__inst_reg, 0x14U)
                                                    : 0U))))));
    vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
        = ((1U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))
            ? vlSelfRef.top__DOT__d_idu__DOT__pc_reg
            : ((2U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))
                ? ((vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                    & vlSelfRef.top__DOT__f_gpr_io_rdata_rs1) 
                   ^ (vlSelfRef.top__DOT__e_imm_io_imm 
                      | vlSelfRef.top__DOT__f_gpr_io_rdata_rs2))
                : vlSelfRef.top__DOT__f_gpr_io_rdata_rs1));
    top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T 
        = ((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))
            ? vlSelfRef.top__DOT__f_gpr_io_rdata_rs2
            : vlSelfRef.top__DOT__e_imm_io_imm);
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__d_idu__DOT__pc_next_type_reg_o = 0U;
        vlSelfRef.top__DOT__c_sram__DOT__pcReg = 0x413U;
        vlSelfRef.top__DOT__c_sram__DOT__instReg = 0x413U;
    } else {
        if (vlSelfRef.top__DOT__d_idu__DOT___validReg_T) {
            vlSelfRef.top__DOT__d_idu__DOT__pc_next_type_reg_o 
                = ((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                    ? 1U : ((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                             ? 2U : ((0x17U == (0x7fU 
                                                & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                      ? 0U : ((0x37U 
                                               == (0x7fU 
                                                   & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                               ? 0U
                                               : ((0x13U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 0U
                                                   : 
                                                  ((0x213U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 0U
                                                    : 
                                                   ((0x313U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 0U
                                                     : 
                                                    ((0x393U 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 0U
                                                      : 
                                                     ((0xf3U 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 0U
                                                       : 
                                                      ((0x173U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 0U
                                                        : 
                                                       ((0x4293U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                         ? 0U
                                                         : 
                                                        ((0x293U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                          ? 0U
                                                          : 
                                                         ((0x93U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                           ? 0U
                                                           : 
                                                          ((0x123U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0x23U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0xa3U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                              ? 0U
                                                              : 
                                                             ((0x100073U 
                                                               == vlSelfRef.top__DOT__c_sram__DOT__instReg)
                                                               ? 4U
                                                               : 
                                                              ((0x73U 
                                                                == vlSelfRef.top__DOT__c_sram__DOT__instReg)
                                                                ? 0xbU
                                                                : 
                                                               ((0x30200073U 
                                                                 == vlSelfRef.top__DOT__c_sram__DOT__instReg)
                                                                 ? 0xcU
                                                                 : 
                                                                ((0x103U 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 0U
                                                                  : 
                                                                 ((0x83U 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                   ? 0U
                                                                   : 
                                                                  ((0x283U 
                                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                    ? 0U
                                                                    : (IData)(vlSelfRef.top__DOT__d_idu__DOT___pc_next_type_reg_T_19)))))))))))))))))))))));
        }
        if (vlSelfRef.top__DOT__c_sram__DOT___validReg_T) {
            vlSelfRef.top__DOT__c_sram__DOT__pcReg 
                = vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                [0U];
            vlSelfRef.top__DOT__c_sram__DOT__instReg 
                = vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                [0U];
        }
    }
    if (__VdlySet__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0) {
        vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0U] 
            = __VdlyVal__top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0;
    }
    if ((2U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))) {
        vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2 = 0U;
        vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0 = 0U;
    } else {
        vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2 
            = top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T;
        vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0 
            = (0x1fU & top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T);
    }
    vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2 = (
                                                   (0x380U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 5U)) 
                                                   | (0x7fU 
                                                      & vlSelfRef.top__DOT__c_sram__DOT__instReg));
    if (vlSelfRef.reset) {
        vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full = 1U;
    } else if (((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en) 
                != (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__do_deq))) {
        vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full 
            = vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en;
    }
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en 
        = ((~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)) 
           & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__validReg));
    vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T_1 
        = ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__validReg));
    vlSelfRef.top__DOT__j_pc_next__DOT__canAccept = 
        (1U & ((~ (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__validReg)) 
               | (~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full))));
    vlSelfRef.top__DOT__i_alu__DOT___out33_T_47 = (
                                                   (0x1ffffffffULL 
                                                    & ((((((((1U 
                                                              & ((IData)(1U) 
                                                                 << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                              ? 
                                                             ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1)) 
                                                              + (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                              : 0ULL) 
                                                            | ((2U 
                                                                & ((IData)(1U) 
                                                                   << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                                ? 
                                                               ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1)) 
                                                                - (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                                : 0ULL)) 
                                                           | ((4U 
                                                               & ((IData)(1U) 
                                                                  << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                               ? (QData)((IData)(
                                                                                (vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                                                                < vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                               : 0ULL)) 
                                                          | ((8U 
                                                              & ((IData)(1U) 
                                                                 << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                              ? (QData)((IData)(
                                                                                (vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                                                                | vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                              : 0ULL)) 
                                                         | ((0x10U 
                                                             & ((IData)(1U) 
                                                                << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                             ? (QData)((IData)(
                                                                               (vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                                                                ^ vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                             : 0ULL)) 
                                                        | ((0x20U 
                                                            & ((IData)(1U) 
                                                               << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                            ? (QData)((IData)(
                                                                              VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1, (IData)(vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0))))
                                                            : 0ULL)) 
                                                       | ((0x40U 
                                                           & ((IData)(1U) 
                                                              << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                           ? (QData)((IData)(
                                                                             (vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                                                              & vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)))
                                                           : 0ULL))) 
                                                   | ((0x100U 
                                                       & ((IData)(1U) 
                                                          << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))
                                                       ? 
                                                      (0x7fffffffffffffffULL 
                                                       & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1)) 
                                                          << (IData)(vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0)))
                                                       : 0ULL));
    vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3 = ((0x1fc00U 
                                                   & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 0xfU)) 
                                                  | (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3 = (
                                                   (0xfc00U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 0x10U)) 
                                                   | (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.top__DOT__f_gpr__DOT___validReg_T_1 = 
        ((~ (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept)) 
         & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
    vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T 
        = ((IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg) 
           & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept));
    vlSelfRef.top__DOT__f_gpr__DOT__canAccept = (1U 
                                                 & ((~ (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg)) 
                                                    | (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept)));
    vlSelfRef.top__DOT__d_idu__DOT___imm_type_reg_T_18 
        = ((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
            ? 6U : ((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                     ? 6U : ((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                              ? 5U : ((0x293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                       ? 5U : ((0x93U 
                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                ? 5U
                                                : (
                                                   (0x193U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 1U
                                                    : 
                                                   ((0x113U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 1U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                      ? 2U
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                       ? 2U
                                                       : 
                                                      ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                        ? 3U
                                                        : 
                                                       ((0x67U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 3U
                                                         : 
                                                        ((0x123U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 4U
                                                          : 
                                                         ((0x23U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 4U
                                                           : 
                                                          ((0xa3U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 4U
                                                            : 
                                                           ((0x103U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 1U
                                                             : 
                                                            ((0x83U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                              ? 1U
                                                              : 
                                                             ((0x283U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                               ? 1U
                                                               : 
                                                              ((0x203U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                ? 1U
                                                                : 
                                                               ((3U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                 ? 1U
                                                                 : 0U)))))))))))))))))));
    if ((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 2U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 2U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 2U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 2U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 6U;
    } else if ((0xb3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 8U;
    } else if ((0x42b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 5U;
    } else if ((0x2b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 9U;
    } else if ((0x233U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 4U;
    } else if ((0x333U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 3U;
    } else if ((0x8033U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 1U;
    } else if ((0x63U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x2e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x263U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x363U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x3e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0xe3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    } else if ((0x133U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0xaU;
    } else if ((0x1b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 3U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 2U;
    } else {
        vlSelfRef.top__DOT__d_idu__DOT___data_control_reg_T_19 = 0U;
        top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19 = 0U;
    }
    vlSelfRef.top__DOT__d_idu__DOT___pc_next_type_reg_T_19 
        = ((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
            ? 0U : ((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                     ? 0U : ((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                              ? 0U : ((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                       ? 0U : ((0xb3U 
                                                == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                ? 0U
                                                : (
                                                   (0x42b3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                    ? 0U
                                                    : 
                                                   ((0x2b3U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                     ? 0U
                                                     : 
                                                    ((0x233U 
                                                      == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                      ? 0U
                                                      : 
                                                     ((0x333U 
                                                       == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                       ? 0U
                                                       : 
                                                      ((0x8033U 
                                                        == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                        ? 0U
                                                        : 
                                                       ((0x63U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 6U
                                                         : 
                                                        ((0x2e3U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 7U
                                                          : 
                                                         ((0x263U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 9U
                                                           : 
                                                          ((0x363U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 0xaU
                                                            : 
                                                           ((0x3e3U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 8U
                                                             : 
                                                            ((0xe3U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                              ? 5U
                                                              : 
                                                             ((0x1b3U 
                                                               == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 0U
                                                               : 
                                                              ((0x133U 
                                                                == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                ? 0U
                                                                : 
                                                               ((0x193U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                 ? 0U
                                                                 : 
                                                                ((0x113U 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 0U
                                                                  : 3U))))))))))))))))))));
    if ((0x42b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x2b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x233U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x333U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x8033U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x63U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x2e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x263U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x363U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x3e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0xe3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x1b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else if ((0x133U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)) {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                        >> 0x14U));
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0xfU));
    } else {
        vlSelfRef.top__DOT__d_idu__DOT___rs2_reg_T_12 
            = (0x1fU & 0U);
        top__DOT__d_idu__DOT___rs1_reg_T_12 = (0x1fU 
                                               & 0U);
    }
    top__DOT__d_idu__DOT___rd_reg_T_12 = (0x1fU & (
                                                   (0x283U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 7U)
                                                    : 
                                                   ((0x203U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                     >> 7U)
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 7U)
                                                      : 
                                                     ((0x33U 
                                                       == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                       ? 
                                                      (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 7U)
                                                       : 
                                                      ((0x3b3U 
                                                        == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                        ? 
                                                       (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                        >> 7U)
                                                        : 
                                                       ((0xb3U 
                                                         == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                         ? 
                                                        (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 7U)
                                                         : 
                                                        ((0x42b3U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                          ? 
                                                         (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                          >> 7U)
                                                          : 
                                                         ((0x2b3U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                           ? 
                                                          (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                           >> 7U)
                                                           : 
                                                          ((0x233U 
                                                            == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                            ? 
                                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                            >> 7U)
                                                            : 
                                                           ((0x333U 
                                                             == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                             ? 
                                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                             >> 7U)
                                                             : 
                                                            ((0x8033U 
                                                              == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 
                                                             (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                              >> 7U)
                                                              : 
                                                             ((0x1b3U 
                                                               == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 
                                                              (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                               >> 7U)
                                                               : 
                                                              ((0x133U 
                                                                == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                ? 
                                                               (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                >> 7U)
                                                                : 0U))))))))))))));
    vlSelfRef.top__DOT__f_gpr__DOT___regs_T = ((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                                               & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept));
    vlSelfRef.top__DOT__i_alu__DOT___validReg_T_1 = 
        ((~ (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept)) 
         & (IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg));
    vlSelfRef.top__DOT__i_alu__DOT__canAccept = (1U 
                                                 & ((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg)) 
                                                    | (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept)));
    vlSelfRef.top__DOT__d_idu__DOT___rs1_reg_T_25 = 
        (0x1fU & ((0x113U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                   ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                      >> 0xfU) : ((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                   ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                      >> 0xfU) : ((0x123U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                   >> 0xfU)
                                                   : 
                                                  ((0x23U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 0xfU)
                                                    : 
                                                   ((0xa3U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                     >> 0xfU)
                                                     : 
                                                    ((0x103U 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 0xfU)
                                                      : 
                                                     ((0x83U 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 
                                                      (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 0xfU)
                                                       : 
                                                      ((0x283U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 
                                                       (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                        >> 0xfU)
                                                        : 
                                                       ((0x203U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 
                                                        (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 0xfU)
                                                         : 
                                                        ((3U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 
                                                         (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                          >> 0xfU)
                                                          : 
                                                         ((0x33U 
                                                           == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                           ? 
                                                          (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                           >> 0xfU)
                                                           : 
                                                          ((0x3b3U 
                                                            == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                            ? 
                                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                            >> 0xfU)
                                                            : 
                                                           ((0xb3U 
                                                             == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                             ? 
                                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                             >> 0xfU)
                                                             : (IData)(top__DOT__d_idu__DOT___rs1_reg_T_12)))))))))))))));
    vlSelfRef.top__DOT__d_idu__DOT___rd_reg_T_24 = 
        (0x1fU & ((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                   ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                      >> 7U) : ((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                 ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                    >> 7U) : ((0x293U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                               ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 7U)
                                               : ((0x93U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                   ? 
                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                   >> 7U)
                                                   : 
                                                  ((0x193U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 7U)
                                                    : 
                                                   ((0x113U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                     >> 7U)
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                      ? 
                                                     (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 7U)
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                       ? 
                                                      (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 7U)
                                                       : 
                                                      ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                        ? 
                                                       (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                        >> 7U)
                                                        : 
                                                       ((0x67U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 
                                                        (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 7U)
                                                         : 
                                                        ((0x103U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 
                                                         (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                          >> 7U)
                                                          : 
                                                         ((0x83U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 
                                                          (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                           >> 7U)
                                                           : (IData)(top__DOT__d_idu__DOT___rd_reg_T_12))))))))))))));
    vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg = 
        ((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
          ? 0U : ((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                   ? 4U : ((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                            ? 3U : ((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                     ? 6U : ((0xf3U 
                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                              ? 0xbU
                                              : ((0x173U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                  ? 0xcU
                                                  : 
                                                 ((0x4293U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                   ? 5U
                                                   : 
                                                  ((0x293U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                    ? 9U
                                                    : 
                                                   ((0x93U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                     ? 8U
                                                     : 
                                                    ((0x193U 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 2U
                                                      : 
                                                     ((0x113U 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 0xaU
                                                       : 
                                                      ((0x37U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                        ? 0U
                                                        : 
                                                       ((0x17U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                         ? 0U
                                                         : 
                                                        ((0x6fU 
                                                          == 
                                                          (0x7fU 
                                                           & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                          ? 0U
                                                          : 
                                                         ((0x67U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 0U
                                                           : 
                                                          ((0x123U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0x23U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0xa3U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                              ? 0U
                                                              : 
                                                             ((0x103U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                               ? 0U
                                                               : (IData)(top__DOT__d_idu__DOT___ALU_ctrl_reg_T_19))))))))))))))))))));
    vlSelfRef.top__DOT__d_idu__DOT___validReg_T_1 = 
        ((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept)) 
         & (IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg));
    vlSelfRef.top__DOT__i_alu__DOT___validReg_T = ((IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg) 
                                                   & (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept));
    vlSelfRef.top__DOT__d_idu__DOT__canAccept = (1U 
                                                 & ((~ (IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg)) 
                                                    | (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept)));
    vlSelfRef.top__DOT__c_sram__DOT___validReg_T_1 
        = ((~ (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept)) 
           & (IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg));
    vlSelfRef.top__DOT__d_idu__DOT___validReg_T = ((IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg) 
                                                   & (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept));
    vlSelfRef.top__DOT__d_idu__DOT___GEN_0 = ((IData)(vlSelfRef.reset)
                                               ? 0U
                                               : ((IData)(vlSelfRef.top__DOT__d_idu__DOT___validReg_T)
                                                   ? (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg)
                                                   : (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)));
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready 
        = (1U & ((~ (IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg)) 
                 | (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept)));
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__do_deq 
        = ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready) 
           & (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
    vlSelfRef.top__DOT__c_sram__DOT___validReg_T = 
        ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
         & (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready));
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
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
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 1941, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 1941, "", "NBA region did not converge.");
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
                VL_FATAL_MT("vsrc/top.v", 1941, "", "Active region did not converge.");
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
