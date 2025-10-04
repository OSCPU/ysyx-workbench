// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25030077.h for the primary calling header

#include "Vysyx_25030077__pch.h"
#include "Vysyx_25030077___024root.h"

VL_ATTR_COLD void Vysyx_25030077___024root___eval_static(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_static\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
}

VL_ATTR_COLD void Vysyx_25030077___024root___eval_initial(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_initial\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vysyx_25030077___024root___eval_final(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_final\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25030077___024root___dump_triggers__stl(Vysyx_25030077___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vysyx_25030077___024root___eval_phase__stl(Vysyx_25030077___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25030077___024root___eval_settle(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_settle\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vysyx_25030077___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/ysyx_25030077.v", 1860, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vysyx_25030077___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25030077___024root___dump_triggers__stl(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___dump_triggers__stl\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vysyx_25030077___024root___stl_sequent__TOP__0(Vysyx_25030077___024root* vlSelf);
VL_ATTR_COLD void Vysyx_25030077___024root____Vm_traceActivitySetAll(Vysyx_25030077___024root* vlSelf);

VL_ATTR_COLD void Vysyx_25030077___024root___eval_stl(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_stl\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vysyx_25030077___024root___stl_sequent__TOP__0(vlSelf);
        Vysyx_25030077___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read_TOP(IData/*31:0*/ pc, CData/*3:0*/ type_p, IData/*31:0*/ &ecall_read__Vfuncrtn);
void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__g_mem__DOT__addr_read_TOP(IData/*31:0*/ addr_in, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__g_mem__DOT__mem_data_read_TOP(IData/*31:0*/ mask, IData/*31:0*/ addr_in, IData/*31:0*/ &mem_data_read__Vfuncrtn);
void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__i_alu__DOT__csr_read_TOP(IData/*31:0*/ rs1, IData/*31:0*/ imm, CData/*3:0*/ sw, IData/*31:0*/ &csr_read__Vfuncrtn);

VL_ATTR_COLD void Vysyx_25030077___024root___stl_sequent__TOP__0(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___stl_sequent__TOP__0\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_13 
        = (2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___axi_ar_addr_T_2 
        = (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_3 
        = (1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___delayCnt_T_3 
        = (7U & ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt) 
                 - (IData)(1U)));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___delayCnt_T_3 
        = (7U & ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt) 
                 - (IData)(1U)));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___mem_data_Reg_T_2 
        = (0x700ULL + vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg);
    vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en 
        = ((~ (IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__do_deq 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T_1 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___validReg_T_4 
        = ((~ ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0) 
               & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt)))) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___validReg_T_3 
        = ((~ ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0) 
               & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt)))) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9 
        = (vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg 
           + ((((vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                 >> 0x1fU) ? 0x7ffffU : 0U) << 0xdU) 
              | (((0x1000U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                              >> 0x13U)) | (0x800U 
                                            & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                               << 4U))) 
                 | ((0x7e0U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                               >> 0x14U)) | (0x1eU 
                                             & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                >> 7U))))));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__validReg) 
           & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt)));
    vlSelfRef.ysyx_25030077__DOT__e_imm__DOT__Imm_type1 
        = ((((vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
              >> 0x1fU) ? 0xfffffU : 0U) << 0xcU) | 
           (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
            >> 0x14U));
    vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2 
        = ((0x380U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 5U)) | (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid 
        = (((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg) 
            & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt))) 
           | (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu 
        = ((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2)) 
           | ((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2)) 
              | ((0x283U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2)) 
                 | ((0x203U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2)) 
                    | (3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))))));
    vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3 
        = ((0x1fc00U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU)) | (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3 
        = ((0xfc00U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                       >> 0x10U)) | (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid 
        = ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid 
        = ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r 
        = ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)) 
           | ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)) 
              & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu)));
    if ((0x13U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x213U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 4U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x313U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 3U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x393U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 6U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0xf3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0xbU;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 6U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x173U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0xcU;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 6U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x4293U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 5U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 5U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x293U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 9U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 5U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x93U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 8U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 5U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x193U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 2U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else if ((0x113U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0xaU;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd = 
            (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                      >> 7U));
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                        >> 0xfU));
    } else {
        if ((0x37U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))) {
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd 
                = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                            >> 7U));
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 2U;
        } else if ((0x17U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))) {
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd 
                = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                            >> 7U));
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 2U;
        } else if ((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))) {
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd 
                = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                            >> 7U));
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 3U;
        } else if ((0x67U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd 
                = (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                            >> 7U));
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 3U;
        } else {
            if ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 4U;
            } else if ((0x23U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 4U;
            } else if ((0xa3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 4U;
            } else if ((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
            } else if ((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
            } else if ((0x283U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
            } else if ((0x203U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
            } else if ((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 1U;
            } else {
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl 
                    = ((0x33U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                        ? 0U : ((0x3b3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                 ? 6U : ((0xb3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                          ? 8U : ((0x42b3U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                   ? 5U
                                                   : 
                                                  ((0x2b3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                    ? 9U
                                                    : 
                                                   ((0x233U 
                                                     == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                     ? 4U
                                                     : 
                                                    ((0x333U 
                                                      == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                      ? 3U
                                                      : 
                                                     ((0x8033U 
                                                       == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                       ? 1U
                                                       : 
                                                      ((0x63U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 0U
                                                        : 
                                                       ((0x2e3U 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 0U
                                                         : 
                                                        ((0x263U 
                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 0U
                                                          : 
                                                         ((0x363U 
                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 0U
                                                           : 
                                                          ((0x3e3U 
                                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0xe3U 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0x133U 
                                                              == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 0xaU
                                                              : 
                                                             ((0x1b3U 
                                                               == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 2U
                                                               : 0U))))))))))))))));
                vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type = 0U;
            }
            vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd 
                = (0x1fU & ((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                             ? (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                >> 7U) : ((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                           ? (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                              >> 7U)
                                           : ((0x283U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                  >> 7U)
                                               : ((0x203U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                   >> 7U)
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                    >> 7U)
                                                    : 
                                                   ((0x33U 
                                                     == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                     >> 7U)
                                                     : 
                                                    ((0x3b3U 
                                                      == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                      >> 7U)
                                                      : 
                                                     ((0xb3U 
                                                       == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                       >> 7U)
                                                       : 
                                                      ((0x42b3U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                        >> 7U)
                                                        : 
                                                       ((0x2b3U 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                         >> 7U)
                                                         : 
                                                        ((0x233U 
                                                          == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                          >> 7U)
                                                          : 
                                                         ((0x333U 
                                                           == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                           >> 7U)
                                                           : 
                                                          ((0x8033U 
                                                            == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                            >> 7U)
                                                            : 
                                                           ((0x1b3U 
                                                             == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                             ? 
                                                            (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                             >> 7U)
                                                             : 
                                                            ((0x133U 
                                                              == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 
                                                             (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                              >> 7U)
                                                              : 0U))))))))))))))));
        }
        vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1 
            = (0x1fU & ((0x67U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                         ? (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                            >> 0xfU) : ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                         ? (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                            >> 0xfU)
                                         : ((0x23U 
                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                             ? (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                >> 0xfU)
                                             : ((0xa3U 
                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                 ? 
                                                (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                 >> 0xfU)
                                                 : 
                                                ((0x103U 
                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                  ? 
                                                 (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                  >> 0xfU)
                                                  : 
                                                 ((0x83U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                   >> 0xfU)
                                                   : 
                                                  ((0x283U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                    >> 0xfU)
                                                    : 
                                                   ((0x203U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                     >> 0xfU)
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                      >> 0xfU)
                                                      : 
                                                     ((0x33U 
                                                       == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                       >> 0xfU)
                                                       : 
                                                      ((0x3b3U 
                                                        == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                        >> 0xfU)
                                                        : 
                                                       ((0xb3U 
                                                         == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                         >> 0xfU)
                                                         : 
                                                        ((0x42b3U 
                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                          >> 0xfU)
                                                          : 
                                                         ((0x2b3U 
                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                           >> 0xfU)
                                                           : 
                                                          ((0x233U 
                                                            == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                            >> 0xfU)
                                                            : 
                                                           ((0x333U 
                                                             == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                             ? 
                                                            (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                             >> 0xfU)
                                                             : 
                                                            ((0x8033U 
                                                              == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 
                                                             (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                              >> 0xfU)
                                                              : 
                                                             ((0x63U 
                                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                               ? 
                                                              (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                               >> 0xfU)
                                                               : 
                                                              ((0x2e3U 
                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                ? 
                                                               (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                >> 0xfU)
                                                                : 
                                                               ((0x263U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                 ? 
                                                                (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                 >> 0xfU)
                                                                 : 
                                                                ((0x363U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 
                                                                 (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                  >> 0xfU)
                                                                  : 
                                                                 ((0x3e3U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                   ? 
                                                                  (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                   >> 0xfU)
                                                                   : 
                                                                  ((0xe3U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                    ? 
                                                                   (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                    >> 0xfU)
                                                                    : 
                                                                   ((0x1b3U 
                                                                     == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                     ? 
                                                                    (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                     >> 0xfU)
                                                                     : 
                                                                    ((0x133U 
                                                                      == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                      ? 
                                                                     (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                      >> 0xfU)
                                                                      : 0U))))))))))))))))))))))))));
    }
    vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type 
        = ((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))
            ? 1U : ((0x67U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                     ? 2U : ((0x17U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))
                              ? 0U : ((0x37U == (0x7fU 
                                                 & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))
                                       ? 0U : ((0x13U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 0U
                                                : (
                                                   (0x213U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 0U
                                                    : 
                                                   ((0x313U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 0U
                                                     : 
                                                    ((0x393U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 0U
                                                      : 
                                                     ((0xf3U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 0U
                                                       : 
                                                      ((0x173U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 0U
                                                        : 
                                                       ((0x4293U 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                         ? 0U
                                                         : 
                                                        ((0x293U 
                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                          ? 0U
                                                          : 
                                                         ((0x93U 
                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                           ? 0U
                                                           : 
                                                          ((0x123U 
                                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0x23U 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0xa3U 
                                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                              ? 0U
                                                              : 
                                                             ((0x100073U 
                                                               == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)
                                                               ? 4U
                                                               : 
                                                              ((0x73U 
                                                                == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)
                                                                ? 0xbU
                                                                : 
                                                               ((0x30200073U 
                                                                 == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)
                                                                 ? 0xcU
                                                                 : 
                                                                ((0x103U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 0U
                                                                  : 
                                                                 ((0x83U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                   ? 0U
                                                                   : 
                                                                  ((0x283U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                    ? 0U
                                                                    : 
                                                                   ((0x203U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                     ? 0U
                                                                     : 
                                                                    ((3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                      ? 0U
                                                                      : 
                                                                     ((0x33U 
                                                                       == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                       ? 0U
                                                                       : 
                                                                      ((0x3b3U 
                                                                        == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                        ? 0U
                                                                        : 
                                                                       ((0xb3U 
                                                                         == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                         ? 0U
                                                                         : 
                                                                        ((0x42b3U 
                                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                                          ? 0U
                                                                          : 
                                                                         ((0x2b3U 
                                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                                           ? 0U
                                                                           : 
                                                                          ((0x233U 
                                                                            == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                            ? 0U
                                                                            : 
                                                                           ((0x333U 
                                                                             == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                             ? 0U
                                                                             : 
                                                                            ((0x8033U 
                                                                              == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                              ? 0U
                                                                              : 
                                                                             ((0x63U 
                                                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                               ? 6U
                                                                               : 
                                                                              ((0x2e3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                ? 7U
                                                                                : 
                                                                               ((0x263U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 9U
                                                                                 : 
                                                                                ((0x363U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 0xaU
                                                                                 : 
                                                                                ((0x3e3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 8U
                                                                                 : 
                                                                                ((0xe3U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 5U
                                                                                 : 
                                                                                ((0x1b3U 
                                                                                == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x133U 
                                                                                == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x193U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 0U
                                                                                 : 
                                                                                ((0x113U 
                                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 0U
                                                                                 : 3U))))))))))))))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control 
        = ((0x17U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))
            ? 1U : ((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))
                     ? 1U : ((0x67U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                              ? 1U : ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                       ? 0U : ((0x23U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 0U
                                                : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 0U
                                                    : 
                                                   ((0x103U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : 
                                                    ((0x83U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 2U
                                                      : 
                                                     ((0x283U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 2U
                                                       : 
                                                      ((0x203U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 2U
                                                        : 
                                                       ((3U 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 2U
                                                         : 
                                                        ((0x33U 
                                                          == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                          ? 3U
                                                          : 
                                                         ((0x3b3U 
                                                           == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                           ? 3U
                                                           : 
                                                          ((0xb3U 
                                                            == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                            ? 3U
                                                            : 
                                                           ((0x42b3U 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                             ? 3U
                                                             : 
                                                            ((0x2b3U 
                                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                              ? 3U
                                                              : 
                                                             ((0x233U 
                                                               == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 3U
                                                               : 
                                                              ((0x333U 
                                                                == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                ? 3U
                                                                : 
                                                               ((0x8033U 
                                                                 == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                 ? 3U
                                                                 : 
                                                                ((0x63U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 0U
                                                                  : 
                                                                 ((0x2e3U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                   ? 0U
                                                                   : 
                                                                  ((0x263U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                    ? 0U
                                                                    : 
                                                                   ((0x363U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                     ? 0U
                                                                     : 
                                                                    ((0x3e3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                      ? 0U
                                                                      : 
                                                                     ((0xe3U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                       ? 0U
                                                                       : 
                                                                      ((0x133U 
                                                                        == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                        ? 3U
                                                                        : 
                                                                       ((0x1b3U 
                                                                         == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                         ? 3U
                                                                         : 0U)))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2 = (0x1fU 
                                                  & ((0x123U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                      >> 0x14U)
                                                      : 
                                                     ((0x23U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                       >> 0x14U)
                                                       : 
                                                      ((0xa3U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                        >> 0x14U)
                                                        : 
                                                       ((0x33U 
                                                         == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                         >> 0x14U)
                                                         : 
                                                        ((0x3b3U 
                                                          == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                          >> 0x14U)
                                                          : 
                                                         ((0xb3U 
                                                           == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                           >> 0x14U)
                                                           : 
                                                          ((0x42b3U 
                                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                            >> 0x14U)
                                                            : 
                                                           ((0x2b3U 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))
                                                             ? 
                                                            (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                             >> 0x14U)
                                                             : 
                                                            ((0x233U 
                                                              == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 
                                                             (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                              >> 0x14U)
                                                              : 
                                                             ((0x333U 
                                                               == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 
                                                              (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                               >> 0x14U)
                                                               : 
                                                              ((0x8033U 
                                                                == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                ? 
                                                               (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                >> 0x14U)
                                                                : 
                                                               ((0x63U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                 ? 
                                                                (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                 >> 0x14U)
                                                                 : 
                                                                ((0x2e3U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 
                                                                 (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                  >> 0x14U)
                                                                  : 
                                                                 ((0x263U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                   ? 
                                                                  (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                   >> 0x14U)
                                                                   : 
                                                                  ((0x363U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                    ? 
                                                                   (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                    >> 0x14U)
                                                                    : 
                                                                   ((0x3e3U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                     ? 
                                                                    (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                     >> 0x14U)
                                                                     : 
                                                                    ((0xe3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                                      ? 
                                                                     (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                      >> 0x14U)
                                                                      : 
                                                                     ((0x1b3U 
                                                                       == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                       ? 
                                                                      (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                       >> 0x14U)
                                                                       : 
                                                                      ((0x133U 
                                                                        == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)
                                                                        ? 
                                                                       (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                                        >> 0x14U)
                                                                        : 0U))))))))))))))))))));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid));
    vlSelfRef.io_is_unknown_instruction = (3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid 
        = ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
            ? (IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)
            : (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid));
    Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read_TOP(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg, (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type), vlSelfRef.__Vfunc_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read__3__Vfuncout);
    vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__ecall_dnpc 
        = vlSelfRef.__Vfunc_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read__3__Vfuncout;
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94 
        = ((0x1eU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30
            : ((0x1dU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29
                : ((0x1cU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28
                    : ((0x1bU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27
                        : ((0x1aU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26
                            : ((0x19U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25
                                : ((0x18U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24
                                    : ((0x17U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23
                                        : ((0x16U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22
                                            : ((0x15U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21
                                                : (
                                                   (0x14U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20
                                                    : 
                                                   ((0x13U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                     ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19
                                                     : 
                                                    ((0x12U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                      ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18
                                                      : 
                                                     ((0x11U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                       ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17
                                                       : 
                                                      ((0x10U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                         ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15
                                                         : 
                                                        ((0xeU 
                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                          ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14
                                                          : 
                                                         ((0xdU 
                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                           ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12
                                                            : 
                                                           ((0xbU 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                             ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11
                                                             : 
                                                            ((0xaU 
                                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                              ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10
                                                              : 
                                                             ((9U 
                                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                               ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9
                                                               : 
                                                              ((8U 
                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8
                                                                : 
                                                               ((7U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                 ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7
                                                                 : 
                                                                ((6U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                  ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6
                                                                  : 
                                                                 ((5U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                   ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5
                                                                   : 
                                                                  ((4U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4
                                                                    : 
                                                                   ((3U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                     ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3
                                                                     : 
                                                                    ((2U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                      ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2
                                                                      : 
                                                                     ((1U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                                                                       ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1
                                                                       : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data 
        = ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
            : ((0x1eU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30
                : ((0x1dU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29
                    : ((0x1cU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28
                        : ((0x1bU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27
                            : ((0x1aU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26
                                : ((0x19U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25
                                    : ((0x18U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24
                                        : ((0x17U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23
                                            : ((0x16U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22
                                                : (
                                                   (0x15U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21
                                                    : 
                                                   ((0x14U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                     ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20
                                                     : 
                                                    ((0x13U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                      ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19
                                                      : 
                                                     ((0x12U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                       ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18
                                                       : 
                                                      ((0x11U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17
                                                        : 
                                                       ((0x10U 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                         ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16
                                                         : 
                                                        ((0xfU 
                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                          ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15
                                                          : 
                                                         ((0xeU 
                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                           ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14
                                                           : 
                                                          ((0xdU 
                                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13
                                                            : 
                                                           ((0xcU 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                             ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12
                                                             : 
                                                            ((0xbU 
                                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                              ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11
                                                              : 
                                                             ((0xaU 
                                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                               ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10
                                                               : 
                                                              ((9U 
                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9
                                                                : 
                                                               ((8U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                 ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8
                                                                 : 
                                                                ((7U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                  ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7
                                                                  : 
                                                                 ((6U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                   ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6
                                                                   : 
                                                                  ((5U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5
                                                                    : 
                                                                   ((4U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                     ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4
                                                                     : 
                                                                    ((3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                      ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3
                                                                      : 
                                                                     ((2U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                       ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2
                                                                       : 
                                                                      ((1U 
                                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2))
                                                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1
                                                                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0)))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_imm 
        = ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))
            ? vlSelfRef.ysyx_25030077__DOT__e_imm__DOT__Imm_type1
            : ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))
                ? (0xfffff000U & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)
                : ((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))
                    ? 4U : ((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))
                             ? ((((vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                   >> 0x1fU) ? 0xfffffU
                                   : 0U) << 0xcU) | 
                                ((0xfe0U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                            >> 0x14U)) 
                                 | (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                             >> 7U))))
                             : ((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))
                                 ? (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                             >> 0x14U))
                                 : ((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))
                                     ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg, 0x14U)
                                     : 0U))))));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
        = ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
            : ((0x1eU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30
                : ((0x1dU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29
                    : ((0x1cU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28
                        : ((0x1bU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27
                            : ((0x1aU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26
                                : ((0x19U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25
                                    : ((0x18U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24
                                        : ((0x17U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23
                                            : ((0x16U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22
                                                : (
                                                   (0x15U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21
                                                    : 
                                                   ((0x14U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                     ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20
                                                     : 
                                                    ((0x13U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                      ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19
                                                      : 
                                                     ((0x12U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                       ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18
                                                       : 
                                                      ((0x11U 
                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17
                                                        : 
                                                       ((0x10U 
                                                         == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                         ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16
                                                         : 
                                                        ((0xfU 
                                                          == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                          ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15
                                                          : 
                                                         ((0xeU 
                                                           == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                           ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14
                                                           : 
                                                          ((0xdU 
                                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13
                                                            : 
                                                           ((0xcU 
                                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                             ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12
                                                             : 
                                                            ((0xbU 
                                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                              ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11
                                                              : 
                                                             ((0xaU 
                                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                               ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10
                                                               : 
                                                              ((9U 
                                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9
                                                                : 
                                                               ((8U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                 ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8
                                                                 : 
                                                                ((7U 
                                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                  ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7
                                                                  : 
                                                                 ((6U 
                                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                   ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6
                                                                   : 
                                                                  ((5U 
                                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                    ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5
                                                                    : 
                                                                   ((4U 
                                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                     ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4
                                                                     : 
                                                                    ((3U 
                                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                      ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3
                                                                      : 
                                                                     ((2U 
                                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                       ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2
                                                                       : 
                                                                      ((1U 
                                                                        == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1))
                                                                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1
                                                                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0)))))))))))))))))))))))))))))));
    vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2 
        = ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))
            ? 0U : ((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))
                     ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                     : vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_imm));
    vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql 
        = (vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
           == vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data);
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT____VdfgRegularize_hf53335a2_0_0 
        = (vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
           + vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_imm);
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr 
        = ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
            ? vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
           [0U] : vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT____VdfgRegularize_hf53335a2_0_0);
    vlSelfRef.ysyx_25030077__DOT__f_gpr_io_pc_next 
        = (((0xbU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type)) 
            | (0xcU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type)))
            ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__ecall_dnpc
            : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                ? (vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg 
                   + (((((vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                          >> 0x1fU) ? 0x7ffU : 0U) 
                        << 0x15U) | (0x100000U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                  >> 0xbU))) 
                      | (((0xff000U & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg) 
                          | (0x800U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                       >> 9U))) | (0x7feU 
                                                   & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                      >> 0x14U)))))
                : ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                    ? (0xfffffffeU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                      + vlSelfRef.ysyx_25030077__DOT__e_imm__DOT__Imm_type1))
                    : ((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg
                        : ((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                            ? ((IData)(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql)
                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))
                            : ((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                                ? ((IData)(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql)
                                    ? ((IData)(4U) 
                                       + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg)
                                    : vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9)
                                : ((7U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                                    ? (VL_GTES_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                        ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                        : ((IData)(4U) 
                                           + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))
                                    : ((8U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                                        ? ((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                            >= vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                            ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                            : ((IData)(4U) 
                                               + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))
                                        : ((9U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                                            ? (VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                                : ((IData)(4U) 
                                                   + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))
                                            : ((0xaU 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))
                                                ? (
                                                   (vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                                    < vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                                    ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))
                                                : ((IData)(4U) 
                                                   + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg)))))))))));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr 
        = ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
            ? vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT____VdfgRegularize_hf53335a2_0_0
            : 0U);
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2 
        = ((0xa0000048U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr) 
           | (0xa000004cU == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr));
    if (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2) {
        vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt 
            = vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt;
        vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem = 0x80000000U;
        vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem = 0U;
    } else {
        vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt 
            = vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt;
        vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem 
            = vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr;
        vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem 
            = ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                ? 6U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                         ? ((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                             ? 1U : ((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                      ? 3U : ((0x283U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 4U
                                               : ((0x203U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 2U
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 5U
                                                    : 0U)))))
                         : 0U));
    }
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0) 
           & ((~ (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)) 
              & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid)));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0) 
           & ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2) 
              & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid)));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint 
        = ((0xa0000048U == ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                             ? vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr
                             : 0x80000000U)) ? (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg)
            : (IData)((vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg 
                       >> 0x20U)));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__read_data 
        = ((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem))
            ? ([&]() {
                Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__g_mem__DOT__addr_read_TOP(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem, vlSelfRef.__Vfunc_ysyx_25030077__DOT__g_mem__DOT__addr_read__0__Vfuncout);
            }(), vlSelfRef.__Vfunc_ysyx_25030077__DOT__g_mem__DOT__addr_read__0__Vfuncout)
            : ([&]() {
                Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__g_mem__DOT__mem_data_read_TOP(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem, vlSelfRef.__Vfunc_ysyx_25030077__DOT__g_mem__DOT__mem_data_read__1__Vfuncout);
            }(), vlSelfRef.__Vfunc_ysyx_25030077__DOT__g_mem__DOT__mem_data_read__1__Vfuncout));
    vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
        = ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))
            ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg
            : ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))
                ? ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                    ? ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                        ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint
                        : vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg)
                    : 0U) : vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data));
    Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__i_alu__DOT__csr_read_TOP(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2, (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl), vlSelfRef.__Vfunc_ysyx_25030077__DOT__i_alu__DOT__csr_read__2__Vfuncout);
    vlSelfRef.ysyx_25030077__DOT__i_alu__DOT__csr_data 
        = vlSelfRef.__Vfunc_ysyx_25030077__DOT__i_alu__DOT__csr_read__2__Vfuncout;
    vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd 
        = ((1U & ((((IData)(1U) << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)) 
                   >> 0xbU) | (((IData)(1U) << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)) 
                               >> 0xcU))) ? vlSelfRef.ysyx_25030077__DOT__i_alu__DOT__csr_data
            : ((((IData)((0x1ffffffffULL & ((((((((1U 
                                                   & ((IData)(1U) 
                                                      << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                   ? 
                                                  ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                                   + (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                   : 0ULL) 
                                                 | ((2U 
                                                     & ((IData)(1U) 
                                                        << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                     ? 
                                                    ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                                     - (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                     : 0ULL)) 
                                                | ((4U 
                                                    & ((IData)(1U) 
                                                       << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                    ? (QData)((IData)(
                                                                      (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                       < vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                    : 0ULL)) 
                                               | ((8U 
                                                   & ((IData)(1U) 
                                                      << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                   ? (QData)((IData)(
                                                                     (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                      | vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                   : 0ULL)) 
                                              | ((0x10U 
                                                  & ((IData)(1U) 
                                                     << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                  ? (QData)((IData)(
                                                                    (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                     ^ vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                  : 0ULL)) 
                                             | ((0x20U 
                                                 & ((IData)(1U) 
                                                    << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                 ? (QData)((IData)(
                                                                   VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, 
                                                                                (0x1fU 
                                                                                & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))
                                                 : 0ULL)) 
                                            | ((0x40U 
                                                & ((IData)(1U) 
                                                   << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                ? (QData)((IData)(
                                                                  (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                   & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                : 0ULL)))) 
                 | (IData)(((0x100U & ((IData)(1U) 
                                       << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                             ? (0x7fffffffffffffffULL 
                                & ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                   << (0x1fU & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                             : 0ULL))) | (IData)(((0x200U 
                                                   & ((IData)(1U) 
                                                      << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                   ? (QData)((IData)(
                                                                     (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))
                                                   : 0ULL))) 
               | (IData)(((0x400U & ((IData)(1U) << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                           ? (QData)((IData)(VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                           : 0ULL))));
}

VL_ATTR_COLD void Vysyx_25030077___024root___eval_triggers__stl(Vysyx_25030077___024root* vlSelf);

VL_ATTR_COLD bool Vysyx_25030077___024root___eval_phase__stl(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_phase__stl\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vysyx_25030077___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vysyx_25030077___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25030077___024root___dump_triggers__act(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___dump_triggers__act\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void Vysyx_25030077___024root___dump_triggers__nba(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___dump_triggers__nba\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vysyx_25030077___024root____Vm_traceActivitySetAll(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root____Vm_traceActivitySetAll\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vysyx_25030077___024root___ctor_var_reset(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___ctor_var_reset\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->io_is_unknown_instruction = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16903048079863618358ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_rs1_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7430335884658931424ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_rs2_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5933493578009671249ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16638658116391781109ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4496302312819771345ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12043809723908708428ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5942520512045225964ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 233845319974658394ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2074952998929401840ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9700340553649277518ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter_io_is_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3657327168406156162ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18232246191449428580ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9961165321568243328ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17894986801431055258ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6499283637741518723ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_data_control = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4724541640752655464ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_ALU_ctrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12620563001403902756ull);
    vlSelf->ysyx_25030077__DOT__d_idu_io_pc_next_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 5797957219976552568ull);
    vlSelf->ysyx_25030077__DOT__f_gpr_io_pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 997154477363252106ull);
    vlSelf->ysyx_25030077__DOT__f_gpr_io_wdata_rd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2213546927129810389ull);
    vlSelf->ysyx_25030077__DOT__h_data_control_io_data_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15807123379015304089ull);
    vlSelf->ysyx_25030077__DOT__h_data_control_io_data_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11690402040395948373ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4732903344065029826ull);
    }
    vlSelf->ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5171848758028634402ull);
    vlSelf->ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16509136621606134466ull);
    vlSelf->ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__do_deq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10655277556380704544ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__state_reg = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12687589343646108247ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__inst_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4103501312290369777ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT___axi_ar_addr_T_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5426044924250540292ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6273708324716198192ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 131114944465997590ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2678792947579909913ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15988575821287959891ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10861868234136787510ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3132572332029728999ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1446303573887544960ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18130479636674365545ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7797156618045034380ull);
    vlSelf->ysyx_25030077__DOT__c_arbiter__DOT____VdfgRegularize_hf53335a2_0_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15129007618564547653ull);
    vlSelf->ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 14639575336056634125ull);
    vlSelf->ysyx_25030077__DOT__d_idu__DOT___issrai_T_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18050888412806817031ull);
    vlSelf->ysyx_25030077__DOT__d_idu__DOT___isadd_T_3 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14507153880085662291ull);
    vlSelf->ysyx_25030077__DOT__e_imm__DOT__Imm_type1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16158054996235109084ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16717815931086342352ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13007563722052566246ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7210582555946134763ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17287874571115896876ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5494551374166674773ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_5 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11855855626307070903ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_6 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3953768729669652095ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_7 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7126245215732832598ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 709974060799252876ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8094887930556116229ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11180054525045566835ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11846746550748051418ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13919340261471907360ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14262145350179555033ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15353854702535523320ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1881550975346023124ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5349844257613756261ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_17 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2267753432479879075ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_18 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1926101112470295546ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_19 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10919106270371912664ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_20 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14465348680051306546ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_21 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14053089235339439572ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_22 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12126024591936348197ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_23 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17458065688232168113ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_24 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11619903833139368670ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_25 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15557058032407251427ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_26 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10891885979355337243ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_27 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1203633943505849673ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_28 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7803727071287283538ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_29 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1134249031196612844ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_30 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11526466589055553335ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__regs_31 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16492460902053254869ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2381012566286692184ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10091781436872838327ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT___validReg_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9602894591481313213ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT___validReg_T_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7871399167207803175ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT___GEN_94 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12364795500168218576ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17446776782067549654ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6090568301714242900ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16216593586107223362ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13543627524325663839ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15647739649710201035ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5511770102701899820ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9715312625126577301ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10814700954604271526ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 733104281161130330ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5354642962010689473ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12201334745419635310ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10937157142673945005ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 175843255694255345ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5732868113506089180ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8887840209915194121ull);
    vlSelf->ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14183317039787836215ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8739245667927093514ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10326081168061490935ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10019141072192934218ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__delayCnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4526790665269506538ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT___startDelay_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10613396571540356421ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT___delayCnt_T_3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5737901266712381224ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT___validReg_T_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17193825919485099896ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17075996634877302437ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9590421758745793628ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4408913901963631808ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18031927808928135750ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10593092447355199148ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15451936152317605048ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16628364695919127900ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5936362794113140914ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15199205117536392536ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15567135614672290884ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 41093591344393503ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14324192177434412912ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2553157303390409322ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14606790492212571362ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3240158631553706993ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3978813926611607997ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10911467779480627917ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8262241542585183751ull);
    vlSelf->ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11923667414114375409ull);
    vlSelf->ysyx_25030077__DOT__i_alu__DOT__csr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11327684817476858390ull);
    vlSelf->ysyx_25030077__DOT__j_pc_next__DOT__ecall_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3228548659994387942ull);
    vlSelf->ysyx_25030077__DOT__j_pc_next__DOT__is_eql = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4074768419297803797ull);
    vlSelf->ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4845100763319410992ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3950837384179220471ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6375118113423888163ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2731399353611936793ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5893463508053199659ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6798508722217009294ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4434918164079637748ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2938924343589074213ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17117524174320276946ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18220824053244238887ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8659983190006225068ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5094765561691568768ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 712044760222853078ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2845367727174458017ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18443091606677461782ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11306924515607678867ull);
    vlSelf->ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6026402740523906971ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1835564315529768214ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18412272435778230634ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__delayCnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6088854550509735428ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT___startDelay_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3628099531815641360ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT___delayCnt_T_3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 964428963140431043ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT___validReg_T_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8174946911863095324ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT___mem_data_Reg_T_2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7732930804948149405ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14734278422891812447ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12815535502664850302ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4370076289369214545ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14806424474884875111ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1328685843378176831ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10874194950881980998ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9805652401567276493ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4251813772592443589ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16219843221764662139ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9381624461095697578ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3826063062648562911ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11897652073846568411ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4896385114384359069ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2107745368665801978ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12407646680375386239ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16994015258886033028ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16448536796009006684ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13491312500986168519ull);
    vlSelf->ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1136987214646848042ull);
    vlSelf->__Vfunc_ysyx_25030077__DOT__g_mem__DOT__addr_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077__DOT__g_mem__DOT__mem_data_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077__DOT__i_alu__DOT__csr_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read__3__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272892335938733197ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
