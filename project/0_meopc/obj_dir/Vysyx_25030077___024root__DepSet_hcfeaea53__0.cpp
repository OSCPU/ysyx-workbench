// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25030077.h for the primary calling header

#include "Vysyx_25030077__pch.h"
#include "Vysyx_25030077___024root.h"

void Vysyx_25030077___024root___eval_act(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_act\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vysyx_25030077___024root___nba_sequent__TOP__0(Vysyx_25030077___024root* vlSelf);

void Vysyx_25030077___024root___eval_nba(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_nba\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vysyx_25030077___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read_TOP(IData/*31:0*/ pc, CData/*3:0*/ type_p, IData/*31:0*/ &ecall_read__Vfuncrtn);
void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__g_mem__DOT__addr_read_TOP(IData/*31:0*/ addr_in, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__g_mem__DOT__mem_data_read_TOP(IData/*31:0*/ mask, IData/*31:0*/ addr_in, IData/*31:0*/ &mem_data_read__Vfuncrtn);
void Vysyx_25030077___024root____Vdpiimwrap_ysyx_25030077__DOT__i_alu__DOT__csr_read_TOP(IData/*31:0*/ rs1, IData/*31:0*/ imm, CData/*3:0*/ sw, IData/*31:0*/ &csr_read__Vfuncrtn);

VL_INLINE_OPT void Vysyx_25030077___024root___nba_sequent__TOP__0(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___nba_sequent__TOP__0\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __Vdly__ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0 = 0;
    CData/*0:0*/ __Vdly__ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0 = 0;
    CData/*0:0*/ __Vdly__ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0 = 0;
    CData/*0:0*/ __Vdly__ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0 = 0;
    CData/*0:0*/ __Vdly__ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0 = 0;
    CData/*0:0*/ __Vdly__ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0 = 0;
    IData/*31:0*/ __VdlyVal__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0;
    __VdlyVal__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 0;
    CData/*0:0*/ __VdlySet__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0;
    __VdlySet__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 0;
    // Body
    __Vdly__ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0 
        = vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0 
        = vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0;
    __VdlySet__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if (VL_UNLIKELY((((IData)((((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                                    & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid)) 
                                   & (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0))) 
                          & (0xa00003f8U == ((0xa00003f8U 
                                              == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                              ? 0xa00003f8U
                                              : 0U)))))) {
            VL_FWRITEF_NX(0x80000002U,"%c",0,8,((0xa00003f8U 
                                                 == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                                 ? 
                                                ((1U 
                                                  == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                                  ? 
                                                 (0xffU 
                                                  & vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                                  : 0U)
                                                 : 0U));
        }
    }
    __Vdly__ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0 
        = vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0 
        = vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0 
        = vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0 
        = vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0;
    __Vdly__ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0 
        = ((IData)(vlSelfRef.reset) | ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1) 
                                       ^ (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2)));
    __Vdly__ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0 
        = ((IData)(vlSelfRef.reset) | ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1) 
                                       ^ (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2)));
    if (vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en) {
        __VdlyVal__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 
            = vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg;
        __VdlySet__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0 = 1U;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt = 0U;
        vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt = 0U;
        vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full = 0U;
        vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg = 0ULL;
        vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30 = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg = 0x80000000U;
        vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg = 0U;
        vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg = 0U;
        vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31 = 0U;
    } else {
        vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt 
            = (((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T) 
                & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r))
                ? (((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2) 
                    << 2U) | (((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1) 
                               << 1U) | (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0)))
                : ((0U != (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt))
                    ? (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___delayCnt_T_3)
                    : 0U));
        vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt 
            = (((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T) 
                & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r))
                ? (((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2) 
                    << 2U) | (((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1) 
                               << 1U) | (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0)))
                : ((0U != (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt))
                    ? (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___delayCnt_T_3)
                    : 0U));
        if (((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en) 
             != (IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__do_deq))) {
            vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full 
                = vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en;
        }
        if (vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T) {
            vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg 
                = vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___mem_data_Reg_T_2;
        }
        if (((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt)) 
             & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)))) {
            vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                    ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint
                    : vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg);
        }
        if ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((7U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((8U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((9U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0xaU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0xbU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0xcU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0xdU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0xeU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0xfU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x10U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x11U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x12U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x13U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x14U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x15U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x16U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x17U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x18U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x19U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x1aU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x1bU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x1cU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x1dU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if ((0x1eU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30 
                = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T)
                    ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd)
                    : ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31
                        : vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94));
        }
        if (vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T) {
            vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg 
                = vlSelfRef.ysyx_25030077__DOT__f_gpr_io_pc_next;
        }
        if (vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T) {
            vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg 
                = vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__read_data;
        }
        vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg 
            = ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___axi_ar_addr_T_2)
                ? (1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt))
                : ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_3)
                    ? ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu)
                        ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt))
                            ? 2U : 1U) : ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu)
                                           ? 0U : (
                                                   ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid) 
                                                    & ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0) 
                                                       | (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0)))
                                                    ? 2U
                                                    : 1U)))
                    : ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_13)
                        ? (((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid) 
                            & ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                ? (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0)
                                : (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0)))
                            ? 0U : 2U) : 0U)));
        if ((0x1fU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
            if (vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T) {
                vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31 
                    = ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))
                        ? 0U : vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd);
            } else if ((0x1fU != (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd))) {
                vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31 
                    = vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___GEN_94;
            }
        }
    }
    __Vdly__ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0 
        = ((IData)(vlSelfRef.reset) | ((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13) 
                                       ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_15) 
                                          ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10) 
                                             ^ (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12)))));
    __Vdly__ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0 
        = ((IData)(vlSelfRef.reset) | ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13) 
                                       ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_15) 
                                          ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10) 
                                             ^ (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12)))));
    __Vdly__ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0 
        = ((IData)(vlSelfRef.reset) | ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13) 
                                       ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_15) 
                                          ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10) 
                                             ^ (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12)))));
    __Vdly__ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0 
        = ((IData)(vlSelfRef.reset) | ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13) 
                                       ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15) 
                                          ^ ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10) 
                                             ^ (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12)))));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg 
        = ((IData)(vlSelfRef.reset) || (((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid) 
                                         & (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0)) 
                                        | (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T_1)));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T) 
                                                   | (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___validReg_T_3)));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__validReg 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T) 
                                                   | (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___validReg_T_4)));
    if (__VdlySet__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0) {
        vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0U] 
            = __VdlyVal__ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr__v0;
    }
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___delayCnt_T_3 
        = (7U & ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt) 
                 - (IData)(1U)));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___delayCnt_T_3 
        = (7U & ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt) 
                 - (IData)(1U)));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_15 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_14));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_15 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_14));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_15 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_14));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14));
    vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en 
        = ((~ (IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T_1 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___mem_data_Reg_T_2 
        = (0x700ULL + vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg);
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
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_14 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_14 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_14 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_13 
        = (2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___axi_ar_addr_T_2 
        = (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg));
    vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_3 
        = (1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg));
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
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0 
        = __Vdly__ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0;
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0 
        = __Vdly__ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0;
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
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12));
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
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_11));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_11));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_11));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11));
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
    vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint 
        = ((0xa0000048U == ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                             ? vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr
                             : 0x80000000U)) ? (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg)
            : (IData)((vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg 
                       >> 0x20U)));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_11 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_11 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_11 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10));
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
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_9));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_9));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_9));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9));
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
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_9 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_8));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_9 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_8));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_9 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_8));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_8 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_8 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_8 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0 
        = __Vdly__ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0;
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0 
        = __Vdly__ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0;
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0 
        = __Vdly__ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0;
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0 
        = __Vdly__ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0;
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0) 
           & ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2) 
              & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid)));
    vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__do_deq 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0) 
           & ((~ (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)) 
              & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid)));
    vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT___validReg_T 
        = ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid));
    vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___validReg_T_4 
        = ((~ ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0) 
               & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt)))) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__validReg));
    vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___validReg_T_3 
        = ((~ ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0) 
               & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt)))) 
           & (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg));
}

void Vysyx_25030077___024root___eval_triggers__act(Vysyx_25030077___024root* vlSelf);

bool Vysyx_25030077___024root___eval_phase__act(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_phase__act\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vysyx_25030077___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vysyx_25030077___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vysyx_25030077___024root___eval_phase__nba(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_phase__nba\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vysyx_25030077___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25030077___024root___dump_triggers__nba(Vysyx_25030077___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25030077___024root___dump_triggers__act(Vysyx_25030077___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25030077___024root___eval(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vysyx_25030077___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/ysyx_25030077.v", 1860, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vysyx_25030077___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/ysyx_25030077.v", 1860, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vysyx_25030077___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vysyx_25030077___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_25030077___024root___eval_debug_assertions(Vysyx_25030077___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root___eval_debug_assertions\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
