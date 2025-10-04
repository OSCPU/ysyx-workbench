// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMaxPeriodFibonacciLFSR_sram.h for the primary calling header

#include "VMaxPeriodFibonacciLFSR_sram__pch.h"
#include "VMaxPeriodFibonacciLFSR_sram___024root.h"

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_static(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_static\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_initial(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_initial\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_final(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_final\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VMaxPeriodFibonacciLFSR_sram___024root___eval_phase__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_settle(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_settle\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VMaxPeriodFibonacciLFSR_sram___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__stl\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___stl_sequent__TOP__0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root____Vm_traceActivitySetAll(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_stl\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VMaxPeriodFibonacciLFSR_sram___024root___stl_sequent__TOP__0(vlSelf);
        VMaxPeriodFibonacciLFSR_sram___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__d_idu__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);
void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__j_pc_next__DOT__ecall_read_TOP(IData/*31:0*/ pc, CData/*3:0*/ type_p, IData/*31:0*/ &ecall_read__Vfuncrtn);
void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__g_mem__DOT__mem_data_read_TOP(IData/*31:0*/ instruction_in, IData/*31:0*/ rs1_data_in, IData/*31:0*/ rs2_data_in, IData/*31:0*/ imm_data_in, IData/*31:0*/ &mem_data_read__Vfuncrtn);
void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__i_alu__DOT__csr_read_TOP(IData/*31:0*/ rs1, IData/*31:0*/ imm, CData/*3:0*/ sw, IData/*31:0*/ &csr_read__Vfuncrtn);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___stl_sequent__TOP__0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___stl_sequent__TOP__0\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__g_mem__DOT___delayCnt_T_3 = 
        (7U & ((IData)(vlSelfRef.top__DOT__g_mem__DOT__delayCnt) 
               - (IData)(1U)));
    vlSelfRef.top__DOT__c_sram__DOT___validReg_T_1 
        = ((~ (IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0)) 
           & (IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg));
    vlSelfRef.top__DOT__g_mem__DOT___startDelay_T = 
        ((IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg) 
         & (IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en 
        = ((~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)) 
           & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__do_deq 
        = ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_0));
    vlSelfRef.top__DOT__f_gpr__DOT___validReg_T_1 = 
        ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
         & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__d_idu__DOT__is_break_TOP(vlSelfRef.top__DOT__c_sram__DOT__instReg, vlSelfRef.__Vfunc_top__DOT__d_idu__DOT__is_break__1__Vfuncout);
    vlSelfRef.top__DOT__is_break_out_o = vlSelfRef.__Vfunc_top__DOT__d_idu__DOT__is_break__1__Vfuncout;
    vlSelfRef.top__DOT__f_gpr_io_mem_Req_valid = ((IData)(vlSelfRef.top__DOT__g_mem__DOT__validReg) 
                                                  & (0U 
                                                     == (IData)(vlSelfRef.top__DOT__g_mem__DOT__delayCnt)));
    vlSelfRef.top__DOT__f_gpr_io_mem_Req_ready = (1U 
                                                  & ((~ (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg)) 
                                                     | (~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full))));
    vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9 
        = (vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg 
           + ((((vlSelfRef.top__DOT__c_sram__DOT__instReg 
                 >> 0x1fU) ? 0x7ffffU : 0U) << 0xdU) 
              | (((0x1000U & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                              >> 0x13U)) | (0x800U 
                                            & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                               << 4U))) 
                 | ((0x7e0U & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                               >> 0x14U)) | (0x1eU 
                                             & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                >> 7U))))));
    vlSelfRef.top__DOT__e_imm__DOT__Imm_type1 = (((
                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 0x1fU)
                                                    ? 0xfffffU
                                                    : 0U) 
                                                  << 0xcU) 
                                                 | (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                    >> 0x14U));
    vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2 = (
                                                   (0x380U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 5U)) 
                                                   | (0x7fU 
                                                      & vlSelfRef.top__DOT__c_sram__DOT__instReg));
    vlSelfRef.top__DOT__f_gpr__DOT___validReg_T = ((IData)(vlSelfRef.top__DOT__f_gpr_io_mem_Req_valid) 
                                                   & (IData)(vlSelfRef.top__DOT__f_gpr_io_mem_Req_ready));
    vlSelfRef.top__DOT__g_mem__DOT___validReg_T_3 = 
        ((~ ((IData)(vlSelfRef.top__DOT__f_gpr_io_mem_Req_ready) 
             & (0U == (IData)(vlSelfRef.top__DOT__g_mem__DOT__delayCnt)))) 
         & (IData)(vlSelfRef.top__DOT__g_mem__DOT__validReg));
    vlSelfRef.top__DOT__r_valid = ((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2)) 
                                   | ((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2)) 
                                      | ((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2)) 
                                         | ((0x203U 
                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2)) 
                                            | (3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))))));
    vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3 = ((0x1fc00U 
                                                   & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 0xfU)) 
                                                  | (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3 = (
                                                   (0xfc00U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 0x10U)) 
                                                   | (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.top__DOT__d_idu_io_pc_next_type = ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                  ? 1U
                                                  : 
                                                 ((0x67U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 2U
                                                   : 
                                                  ((0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                    ? 0U
                                                    : 
                                                   ((0x37U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                     ? 0U
                                                     : 
                                                    ((0x13U 
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
                                                                       : 
                                                                      ((0x203U 
                                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                        ? 0U
                                                                        : 
                                                                       ((3U 
                                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                         ? 0U
                                                                         : 
                                                                        ((0x33U 
                                                                          == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                          ? 0U
                                                                          : 
                                                                         ((0x3b3U 
                                                                           == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                           ? 0U
                                                                           : 
                                                                          ((0xb3U 
                                                                            == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                            ? 0U
                                                                            : 
                                                                           ((0x42b3U 
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
                                                                                 : 3U))))))))))))))))))))))))))))))))))))))))));
    if ((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 4U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 3U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 6U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0xbU;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 6U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0xcU;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 6U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 5U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 5U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 9U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 5U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x93U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 8U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 5U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x193U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 2U;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else if ((0x113U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
        vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU & 
                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                            >> 7U));
        vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0xaU;
        vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                             >> 0xfU));
    } else {
        if ((0x37U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))) {
            vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 7U));
            vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.top__DOT__d_idu_io_imm_type = 2U;
        } else if ((0x17U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))) {
            vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 7U));
            vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.top__DOT__d_idu_io_imm_type = 2U;
        } else if ((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))) {
            vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 7U));
            vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.top__DOT__d_idu_io_imm_type = 3U;
        } else if ((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
            vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU 
                                               & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 7U));
            vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
            vlSelfRef.top__DOT__d_idu_io_imm_type = 3U;
        } else {
            vlSelfRef.top__DOT__d_idu_io_rd = (0x1fU 
                                               & ((0x103U 
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
                                                    : 
                                                   ((0x283U 
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
                                                                 : 0U))))))))))))))));
            if ((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 4U;
            } else if ((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 4U;
            } else if ((0xa3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 4U;
            } else if ((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
            } else if ((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
            } else if ((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
            } else if ((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
            } else if ((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))) {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl = 0U;
                vlSelfRef.top__DOT__d_idu_io_imm_type = 1U;
            } else {
                vlSelfRef.top__DOT__d_idu_io_ALU_ctrl 
                    = ((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                        ? 0U : ((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                 ? 6U : ((0xb3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                          ? 8U : ((0x42b3U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                   ? 5U
                                                   : 
                                                  ((0x2b3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                    ? 9U
                                                    : 
                                                   ((0x233U 
                                                     == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                     ? 4U
                                                     : 
                                                    ((0x333U 
                                                      == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                      ? 3U
                                                      : 
                                                     ((0x8033U 
                                                       == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                       ? 1U
                                                       : 
                                                      ((0x63U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                        ? 0U
                                                        : 
                                                       ((0x2e3U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 0U
                                                         : 
                                                        ((0x263U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 0U
                                                          : 
                                                         ((0x363U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 0U
                                                           : 
                                                          ((0x3e3U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 0U
                                                            : 
                                                           ((0xe3U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 0U
                                                             : 
                                                            ((0x133U 
                                                              == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 0xaU
                                                              : 
                                                             ((0x1b3U 
                                                               == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 2U
                                                               : 0U))))))))))))))));
                vlSelfRef.top__DOT__d_idu_io_imm_type = 0U;
            }
        }
        vlSelfRef.top__DOT__d_idu_io_rs1 = (0x1fU & 
                                            ((0x67U 
                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                              ? (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                 >> 0xfU)
                                              : ((0x123U 
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
                                                            : 
                                                           ((0x42b3U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                             ? 
                                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                             >> 0xfU)
                                                             : 
                                                            ((0x2b3U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                              ? 
                                                             (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                              >> 0xfU)
                                                              : 
                                                             ((0x233U 
                                                               == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 
                                                              (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                               >> 0xfU)
                                                               : 
                                                              ((0x333U 
                                                                == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                ? 
                                                               (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                >> 0xfU)
                                                                : 
                                                               ((0x8033U 
                                                                 == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                 ? 
                                                                (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                 >> 0xfU)
                                                                 : 
                                                                ((0x63U 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 
                                                                 (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                  >> 0xfU)
                                                                  : 
                                                                 ((0x2e3U 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                   ? 
                                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                   >> 0xfU)
                                                                   : 
                                                                  ((0x263U 
                                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                    ? 
                                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                    >> 0xfU)
                                                                    : 
                                                                   ((0x363U 
                                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                     ? 
                                                                    (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                     >> 0xfU)
                                                                     : 
                                                                    ((0x3e3U 
                                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                      ? 
                                                                     (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                      >> 0xfU)
                                                                      : 
                                                                     ((0xe3U 
                                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                       ? 
                                                                      (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                       >> 0xfU)
                                                                       : 
                                                                      ((0x1b3U 
                                                                        == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                        ? 
                                                                       (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                        >> 0xfU)
                                                                        : 
                                                                       ((0x133U 
                                                                         == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                         ? 
                                                                        (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                         >> 0xfU)
                                                                         : 0U))))))))))))))))))))))))));
    }
    vlSelfRef.top__DOT__d_idu_io_data_control = ((0x17U 
                                                  == 
                                                  (0x7fU 
                                                   & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                  ? 1U
                                                  : 
                                                 ((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelfRef.top__DOT__c_sram__DOT__instReg))
                                                   ? 1U
                                                   : 
                                                  ((0x67U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 1U
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
                                                        ? 2U
                                                        : 
                                                       ((0x83U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                         ? 2U
                                                         : 
                                                        ((0x283U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                          ? 2U
                                                          : 
                                                         ((0x203U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                           ? 2U
                                                           : 
                                                          ((3U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                            ? 2U
                                                            : 
                                                           ((0x33U 
                                                             == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                             ? 3U
                                                             : 
                                                            ((0x3b3U 
                                                              == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                              ? 3U
                                                              : 
                                                             ((0xb3U 
                                                               == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                               ? 3U
                                                               : 
                                                              ((0x42b3U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                                ? 3U
                                                                : 
                                                               ((0x2b3U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                                 ? 3U
                                                                 : 
                                                                ((0x233U 
                                                                  == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                  ? 3U
                                                                  : 
                                                                 ((0x333U 
                                                                   == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                   ? 3U
                                                                   : 
                                                                  ((0x8033U 
                                                                    == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                    ? 3U
                                                                    : 
                                                                   ((0x63U 
                                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                     ? 0U
                                                                     : 
                                                                    ((0x2e3U 
                                                                      == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                      ? 0U
                                                                      : 
                                                                     ((0x263U 
                                                                       == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                       ? 0U
                                                                       : 
                                                                      ((0x363U 
                                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                        ? 0U
                                                                        : 
                                                                       ((0x3e3U 
                                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                         ? 0U
                                                                         : 
                                                                        ((0xe3U 
                                                                          == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                          ? 0U
                                                                          : 
                                                                         ((0x133U 
                                                                           == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                           ? 3U
                                                                           : 
                                                                          ((0x1b3U 
                                                                            == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                            ? 3U
                                                                            : 0U)))))))))))))))))))))))))));
    vlSelfRef.top__DOT__d_idu_io_rs2 = (0x1fU & ((0x123U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                  ? 
                                                 (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                  >> 0x14U)
                                                  : 
                                                 ((0x23U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                   >> 0x14U)
                                                   : 
                                                  ((0xa3U 
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
                                                       : 
                                                      ((0x42b3U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                        ? 
                                                       (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                        >> 0x14U)
                                                        : 
                                                       ((0x2b3U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))
                                                         ? 
                                                        (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 0x14U)
                                                         : 
                                                        ((0x233U 
                                                          == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                          ? 
                                                         (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                          >> 0x14U)
                                                          : 
                                                         ((0x333U 
                                                           == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                           ? 
                                                          (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                           >> 0x14U)
                                                           : 
                                                          ((0x8033U 
                                                            == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                            ? 
                                                           (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                            >> 0x14U)
                                                            : 
                                                           ((0x63U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                             ? 
                                                            (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                             >> 0x14U)
                                                             : 
                                                            ((0x2e3U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                              ? 
                                                             (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                              >> 0x14U)
                                                              : 
                                                             ((0x263U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                               ? 
                                                              (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                               >> 0x14U)
                                                               : 
                                                              ((0x363U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                ? 
                                                               (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                >> 0x14U)
                                                                : 
                                                               ((0x3e3U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                 ? 
                                                                (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                 >> 0x14U)
                                                                 : 
                                                                ((0xe3U 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                  ? 
                                                                 (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                  >> 0x14U)
                                                                  : 
                                                                 ((0x1b3U 
                                                                   == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                   ? 
                                                                  (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                   >> 0x14U)
                                                                   : 
                                                                  ((0x133U 
                                                                    == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)
                                                                    ? 
                                                                   (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                                    >> 0x14U)
                                                                    : 0U))))))))))))))))))));
    vlSelfRef.io_is_unknown_instruction = (3U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type));
    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__j_pc_next__DOT__ecall_read_TOP(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg, (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type), vlSelfRef.__Vfunc_top__DOT__j_pc_next__DOT__ecall_read__4__Vfuncout);
    vlSelfRef.top__DOT__j_pc_next__DOT__ecall_dnpc 
        = vlSelfRef.__Vfunc_top__DOT__j_pc_next__DOT__ecall_read__4__Vfuncout;
    vlSelfRef.top__DOT__f_gpr__DOT___GEN_94 = ((0x1eU 
                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_30
                                                : (
                                                   (0x1dU 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_22
                                                           : 
                                                          ((0x15U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_21
                                                            : 
                                                           ((0x14U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_20
                                                             : 
                                                            ((0x13U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_19
                                                              : 
                                                             ((0x12U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_18
                                                               : 
                                                              ((0x11U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_17
                                                                : 
                                                               ((0x10U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                 ? vlSelfRef.top__DOT__f_gpr__DOT__regs_16
                                                                 : 
                                                                ((0xfU 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_15
                                                                  : 
                                                                 ((0xeU 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_14
                                                                   : 
                                                                  ((0xdU 
                                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_13
                                                                    : 
                                                                   ((0xcU 
                                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_12
                                                                     : 
                                                                    ((0xbU 
                                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_11
                                                                      : 
                                                                     ((0xaU 
                                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_10
                                                                       : 
                                                                      ((9U 
                                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_9
                                                                        : 
                                                                       ((8U 
                                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_8
                                                                         : 
                                                                        ((7U 
                                                                          == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_7
                                                                          : 
                                                                         ((6U 
                                                                           == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_6
                                                                           : 
                                                                          ((5U 
                                                                            == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_5
                                                                            : 
                                                                           ((4U 
                                                                             == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_4
                                                                             : 
                                                                            ((3U 
                                                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_3
                                                                              : 
                                                                             ((2U 
                                                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_2
                                                                               : 
                                                                              ((1U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rd))
                                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_1
                                                                                : vlSelfRef.top__DOT__f_gpr__DOT__regs_0))))))))))))))))))))))))))))));
    vlSelfRef.top__DOT__e_imm_io_imm = ((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))
                                         ? vlSelfRef.top__DOT__e_imm__DOT__Imm_type1
                                         : ((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))
                                             ? (0xfffff000U 
                                                & vlSelfRef.top__DOT__c_sram__DOT__instReg)
                                             : ((3U 
                                                 == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))
                                                 ? 4U
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))
                                                  ? 
                                                 ((((vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                     >> 0x1fU)
                                                     ? 0xfffffU
                                                     : 0U) 
                                                   << 0xcU) 
                                                  | ((0xfe0U 
                                                      & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                           >> 7U))))
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))
                                                   ? 
                                                  (0x1fU 
                                                   & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 0x14U))
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))
                                                    ? 
                                                   VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__c_sram__DOT__instReg, 0x14U)
                                                    : 0U))))));
    vlSelfRef.top__DOT__f_gpr_io_rdata_rs2 = ((0x1fU 
                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                                               : ((0x1eU 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_30
                                                   : 
                                                  ((0x1dU 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_22
                                                           : 
                                                          ((0x15U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_21
                                                            : 
                                                           ((0x14U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_20
                                                             : 
                                                            ((0x13U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_19
                                                              : 
                                                             ((0x12U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_18
                                                               : 
                                                              ((0x11U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_17
                                                                : 
                                                               ((0x10U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                 ? vlSelfRef.top__DOT__f_gpr__DOT__regs_16
                                                                 : 
                                                                ((0xfU 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_15
                                                                  : 
                                                                 ((0xeU 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_14
                                                                   : 
                                                                  ((0xdU 
                                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_13
                                                                    : 
                                                                   ((0xcU 
                                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_12
                                                                     : 
                                                                    ((0xbU 
                                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_11
                                                                      : 
                                                                     ((0xaU 
                                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_10
                                                                       : 
                                                                      ((9U 
                                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_9
                                                                        : 
                                                                       ((8U 
                                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_8
                                                                         : 
                                                                        ((7U 
                                                                          == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_7
                                                                          : 
                                                                         ((6U 
                                                                           == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_6
                                                                           : 
                                                                          ((5U 
                                                                            == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_5
                                                                            : 
                                                                           ((4U 
                                                                             == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_4
                                                                             : 
                                                                            ((3U 
                                                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_3
                                                                              : 
                                                                             ((2U 
                                                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_2
                                                                               : 
                                                                              ((1U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rs2))
                                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_1
                                                                                : vlSelfRef.top__DOT__f_gpr__DOT__regs_0)))))))))))))))))))))))))))))));
    vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 = ((0x1fU 
                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_31
                                               : ((0x1eU 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_30
                                                   : 
                                                  ((0x1dU 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_29
                                                    : 
                                                   ((0x1cU 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_28
                                                     : 
                                                    ((0x1bU 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_27
                                                      : 
                                                     ((0x1aU 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_26
                                                       : 
                                                      ((0x19U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_25
                                                        : 
                                                       ((0x18U 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_24
                                                         : 
                                                        ((0x17U 
                                                          == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_23
                                                          : 
                                                         ((0x16U 
                                                           == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_22
                                                           : 
                                                          ((0x15U 
                                                            == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_21
                                                            : 
                                                           ((0x14U 
                                                             == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_20
                                                             : 
                                                            ((0x13U 
                                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_19
                                                              : 
                                                             ((0x12U 
                                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_18
                                                               : 
                                                              ((0x11U 
                                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_17
                                                                : 
                                                               ((0x10U 
                                                                 == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                 ? vlSelfRef.top__DOT__f_gpr__DOT__regs_16
                                                                 : 
                                                                ((0xfU 
                                                                  == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                  ? vlSelfRef.top__DOT__f_gpr__DOT__regs_15
                                                                  : 
                                                                 ((0xeU 
                                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__regs_14
                                                                   : 
                                                                  ((0xdU 
                                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                    ? vlSelfRef.top__DOT__f_gpr__DOT__regs_13
                                                                    : 
                                                                   ((0xcU 
                                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                     ? vlSelfRef.top__DOT__f_gpr__DOT__regs_12
                                                                     : 
                                                                    ((0xbU 
                                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                      ? vlSelfRef.top__DOT__f_gpr__DOT__regs_11
                                                                      : 
                                                                     ((0xaU 
                                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                       ? vlSelfRef.top__DOT__f_gpr__DOT__regs_10
                                                                       : 
                                                                      ((9U 
                                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                        ? vlSelfRef.top__DOT__f_gpr__DOT__regs_9
                                                                        : 
                                                                       ((8U 
                                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                         ? vlSelfRef.top__DOT__f_gpr__DOT__regs_8
                                                                         : 
                                                                        ((7U 
                                                                          == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                          ? vlSelfRef.top__DOT__f_gpr__DOT__regs_7
                                                                          : 
                                                                         ((6U 
                                                                           == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                           ? vlSelfRef.top__DOT__f_gpr__DOT__regs_6
                                                                           : 
                                                                          ((5U 
                                                                            == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                            ? vlSelfRef.top__DOT__f_gpr__DOT__regs_5
                                                                            : 
                                                                           ((4U 
                                                                             == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                             ? vlSelfRef.top__DOT__f_gpr__DOT__regs_4
                                                                             : 
                                                                            ((3U 
                                                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                              ? vlSelfRef.top__DOT__f_gpr__DOT__regs_3
                                                                              : 
                                                                             ((2U 
                                                                               == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                               ? vlSelfRef.top__DOT__f_gpr__DOT__regs_2
                                                                               : 
                                                                              ((1U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_rs1))
                                                                                ? vlSelfRef.top__DOT__f_gpr__DOT__regs_1
                                                                                : vlSelfRef.top__DOT__f_gpr__DOT__regs_0)))))))))))))))))))))))))))))));
    vlSelfRef.top__DOT__h_data_control_io_data_2 = 
        ((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))
          ? 0U : ((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))
                   ? vlSelfRef.top__DOT__f_gpr_io_rdata_rs2
                   : vlSelfRef.top__DOT__e_imm_io_imm));
    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__g_mem__DOT__mem_data_read_TOP(
                                                                                ((0x103U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 1U
                                                                                 : 
                                                                                ((0x83U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 3U
                                                                                 : 
                                                                                ((0x283U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 4U
                                                                                 : 
                                                                                ((0x203U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 2U
                                                                                 : 
                                                                                ((3U 
                                                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                                                 ? 5U
                                                                                 : 0U))))), vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2, vlSelfRef.top__DOT__e_imm_io_imm, vlSelfRef.__Vfunc_top__DOT__g_mem__DOT__mem_data_read__2__Vfuncout);
    vlSelfRef.top__DOT__g_mem__DOT__read_data = vlSelfRef.__Vfunc_top__DOT__g_mem__DOT__mem_data_read__2__Vfuncout;
    vlSelfRef.top__DOT__j_pc_next__DOT__is_eql = (vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                                                  == vlSelfRef.top__DOT__f_gpr_io_rdata_rs2);
    vlSelfRef.top__DOT__h_data_control_io_data_1 = 
        ((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))
          ? vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg
          : ((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))
              ? vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg
              : vlSelfRef.top__DOT__f_gpr_io_rdata_rs1));
    vlSelfRef.top__DOT__f_gpr_io_pc_next = (((0xbU 
                                              == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)) 
                                             | (0xcU 
                                                == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)))
                                             ? vlSelfRef.top__DOT__j_pc_next__DOT__ecall_dnpc
                                             : ((1U 
                                                 == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                 ? 
                                                (vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg 
                                                 + 
                                                 (((((vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 0x1fU)
                                                      ? 0x7ffU
                                                      : 0U) 
                                                    << 0x15U) 
                                                   | (0x100000U 
                                                      & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 0xbU))) 
                                                  | (((0xff000U 
                                                       & vlSelfRef.top__DOT__c_sram__DOT__instReg) 
                                                      | (0x800U 
                                                         & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                            >> 9U))) 
                                                     | (0x7feU 
                                                        & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                           >> 0x14U)))))
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                  ? 
                                                 (0xfffffffeU 
                                                  & (vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                                                     + vlSelfRef.top__DOT__e_imm__DOT__Imm_type1))
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                   ? vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                    ? 
                                                   ((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                                     ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                     ? 
                                                    ((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                                      ? 
                                                     ((IData)(4U) 
                                                      + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)
                                                      : vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9)
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                      ? 
                                                     (VL_GTES_III(32, vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                                       ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                       : 
                                                      ((IData)(4U) 
                                                       + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                       ? 
                                                      ((vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                                                        >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                                        ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                        : 
                                                       ((IData)(4U) 
                                                        + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                        ? 
                                                       (VL_LTS_III(32, vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                                         ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                         : 
                                                        ((IData)(4U) 
                                                         + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))
                                                        : 
                                                       ((0xaU 
                                                         == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))
                                                         ? 
                                                        ((vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                                                          < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                                          ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                                          : 
                                                         ((IData)(4U) 
                                                          + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))
                                                         : 
                                                        ((IData)(4U) 
                                                         + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)))))))))));
    vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1 
        = ((vlSelfRef.top__DOT__h_data_control_io_data_1 
            ^ vlSelfRef.top__DOT__h_data_control_io_data_2) 
           >> 0x1fU);
    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__i_alu__DOT__csr_read_TOP(vlSelfRef.top__DOT__h_data_control_io_data_1, vlSelfRef.top__DOT__h_data_control_io_data_2, (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl), vlSelfRef.__Vfunc_top__DOT__i_alu__DOT__csr_read__3__Vfuncout);
    vlSelfRef.top__DOT__i_alu__DOT__csr_data = vlSelfRef.__Vfunc_top__DOT__i_alu__DOT__csr_read__3__Vfuncout;
    vlSelfRef.top__DOT__i_alu__DOT__out33 = ((((0x1ffffffffULL 
                                                & ((((((((1U 
                                                          & ((IData)(1U) 
                                                             << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                          ? 
                                                         ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                                          + (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                          : 0ULL) 
                                                        | ((2U 
                                                            & ((IData)(1U) 
                                                               << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                            ? 
                                                           ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                                            - (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                            : 0ULL)) 
                                                       | ((4U 
                                                           & ((IData)(1U) 
                                                              << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                           ? (QData)((IData)(
                                                                             (vlSelfRef.top__DOT__h_data_control_io_data_1 
                                                                              < vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                           : 0ULL)) 
                                                      | ((8U 
                                                          & ((IData)(1U) 
                                                             << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                          ? (QData)((IData)(
                                                                            (vlSelfRef.top__DOT__h_data_control_io_data_1 
                                                                             | vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                          : 0ULL)) 
                                                     | ((0x10U 
                                                         & ((IData)(1U) 
                                                            << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                         ? (QData)((IData)(
                                                                           (vlSelfRef.top__DOT__h_data_control_io_data_1 
                                                                            ^ vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                         : 0ULL)) 
                                                    | ((0x20U 
                                                        & ((IData)(1U) 
                                                           << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                        ? (QData)((IData)(
                                                                          VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__h_data_control_io_data_1, 
                                                                                (0x1fU 
                                                                                & vlSelfRef.top__DOT__h_data_control_io_data_2))))
                                                        : 0ULL)) 
                                                   | ((0x40U 
                                                       & ((IData)(1U) 
                                                          << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                       ? (QData)((IData)(
                                                                         (vlSelfRef.top__DOT__h_data_control_io_data_1 
                                                                          & vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                       : 0ULL))) 
                                               | ((0x100U 
                                                   & ((IData)(1U) 
                                                      << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                   ? 
                                                  (0x7fffffffffffffffULL 
                                                   & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                                      << 
                                                      (0x1fU 
                                                       & vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                   : 0ULL)) 
                                              | ((0x200U 
                                                  & ((IData)(1U) 
                                                     << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                  ? (QData)((IData)(
                                                                    (vlSelfRef.top__DOT__h_data_control_io_data_1 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & vlSelfRef.top__DOT__h_data_control_io_data_2))))
                                                  : 0ULL)) 
                                             | ((0x400U 
                                                 & ((IData)(1U) 
                                                    << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))
                                                 ? (QData)((IData)(
                                                                   VL_LTS_III(32, vlSelfRef.top__DOT__h_data_control_io_data_1, vlSelfRef.top__DOT__h_data_control_io_data_2)))
                                                 : 0ULL));
    vlSelfRef.io_carry = (1U & (IData)((vlSelfRef.top__DOT__i_alu__DOT__out33 
                                        >> 0x20U)));
    vlSelfRef.top__DOT__f_gpr_io_wdata_rd = ((1U & 
                                              ((((IData)(1U) 
                                                 << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)) 
                                                >> 0xbU) 
                                               | (((IData)(1U) 
                                                   << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)) 
                                                  >> 0xcU)))
                                              ? vlSelfRef.top__DOT__i_alu__DOT__csr_data
                                              : (IData)(vlSelfRef.top__DOT__i_alu__DOT__out33));
    vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T 
        = (1U & ((vlSelfRef.top__DOT__h_data_control_io_data_1 
                  >> 0x1fU) ^ (IData)((vlSelfRef.top__DOT__i_alu__DOT__out33 
                                       >> 0x1fU))));
    vlSelfRef.io_isoverflow = ((((IData)(1U) << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)) 
                                & ((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                   & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T))) 
                               | (((IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T) 
                                   & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                  & (((IData)(1U) << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)) 
                                     >> 1U)));
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_triggers__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);

VL_ATTR_COLD bool VMaxPeriodFibonacciLFSR_sram___024root___eval_phase__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_phase__stl\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VMaxPeriodFibonacciLFSR_sram___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VMaxPeriodFibonacciLFSR_sram___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__act(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__act\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__nba(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__nba\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root____Vm_traceActivitySetAll(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vm_traceActivitySetAll\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___ctor_var_reset(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___ctor_var_reset\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->io_is_unknown_instruction = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16903048079863618358ull);
    vlSelf->io_carry = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6964711134417610914ull);
    vlSelf->io_isoverflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14653561070467061763ull);
    vlSelf->top__DOT__d_idu_io_imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 63459511432776219ull);
    vlSelf->top__DOT__d_idu_io_rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15692825985297407666ull);
    vlSelf->top__DOT__d_idu_io_rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10188601459886786117ull);
    vlSelf->top__DOT__d_idu_io_rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16221016892398490331ull);
    vlSelf->top__DOT__d_idu_io_data_control = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1215923190751758288ull);
    vlSelf->top__DOT__d_idu_io_ALU_ctrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9845315184522018469ull);
    vlSelf->top__DOT__d_idu_io_pc_next_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1528933565177884068ull);
    vlSelf->top__DOT__e_imm_io_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11143517121919905614ull);
    vlSelf->top__DOT__f_gpr_io_mem_Req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9267668400094217248ull);
    vlSelf->top__DOT__f_gpr_io_mem_Req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11708401211554571604ull);
    vlSelf->top__DOT__f_gpr_io_pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16194370634555506904ull);
    vlSelf->top__DOT__f_gpr_io_wdata_rd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15526117910832324007ull);
    vlSelf->top__DOT__f_gpr_io_rdata_rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10729581457183257811ull);
    vlSelf->top__DOT__f_gpr_io_rdata_rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2512450688899279096ull);
    vlSelf->top__DOT__h_data_control_io_data_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2808629681500695676ull);
    vlSelf->top__DOT__h_data_control_io_data_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5583826403555143947ull);
    vlSelf->top__DOT__is_break_out_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5023700915296225761ull);
    vlSelf->top__DOT__r_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18441519270825938268ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2291462414531965279ull);
    }
    vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12683377125686420573ull);
    vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5494231505457940232ull);
    vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__do_deq = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9092938482313408028ull);
    vlSelf->top__DOT__c_sram__DOT__instReg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14396684523307796087ull);
    vlSelf->top__DOT__c_sram__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9628743737289559909ull);
    vlSelf->top__DOT__c_sram__DOT___validReg_T_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7951011372570566014ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15257519495093205771ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17576674413252086989ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3255147628663770353ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5635263368417292455ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11694879028355122959ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8599133260839845581ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9300797562925881777ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8546826247305857201ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3890114989707895490ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13252086472691525647ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5781501829899586155ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3432578007398873291ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13304914814949057596ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18184234096062584115ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11108081656399824783ull);
    vlSelf->top__DOT__c_sram__DOT__canAccept_prng__DOT__state_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11972087392689867973ull);
    vlSelf->top__DOT__d_idu__DOT___isaddi_T_2 = VL_SCOPED_RAND_RESET_I(10, __VscopeHash, 5883447268915374958ull);
    vlSelf->top__DOT__d_idu__DOT___issrai_T_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4483743318239371072ull);
    vlSelf->top__DOT__d_idu__DOT___isadd_T_3 = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 176516518197238690ull);
    vlSelf->top__DOT__e_imm__DOT__Imm_type1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5745566466882642811ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_0 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13915560090118829405ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13040288900040133571ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15798769202188630669ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_3 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18071905109448013406ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16073078618428048460ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_5 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5539509434459534083ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_6 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13592174458291073032ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_7 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2969734912129150805ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_8 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17692208295655295348ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15189514929128088933ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_10 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12510507242185811246ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_11 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18004778236131349317ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_12 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5058074557527585938ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_13 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5612514276511763560ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_14 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2058370411656310550ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_15 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3983772175216447187ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_16 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11921604583399376618ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_17 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 360307771618258890ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_18 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13717758983305261069ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_19 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6905672140731680950ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_20 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1267581309660354981ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_21 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14137779352809203683ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_22 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3204015683712372119ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_23 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8867633823918330486ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_24 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10447830109085232024ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_25 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17128873485165752939ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_26 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11929374135176728324ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_27 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13050412683148852320ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_28 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2122144645743239022ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_29 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6806433455304038190ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_30 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9935936840281224642ull);
    vlSelf->top__DOT__f_gpr__DOT__regs_31 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10756200629194619116ull);
    vlSelf->top__DOT__f_gpr__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14805201399286343840ull);
    vlSelf->top__DOT__f_gpr__DOT__pc_next_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2544821269946485155ull);
    vlSelf->top__DOT__f_gpr__DOT___validReg_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9431369624681544874ull);
    vlSelf->top__DOT__f_gpr__DOT___validReg_T_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6460027487259699373ull);
    vlSelf->top__DOT__f_gpr__DOT___GEN_94 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10575867230171526294ull);
    vlSelf->top__DOT__g_mem__DOT__mem_data_Reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16175677410348553871ull);
    vlSelf->top__DOT__g_mem__DOT__validReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4909816889593878444ull);
    vlSelf->top__DOT__g_mem__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2169482793393195336ull);
    vlSelf->top__DOT__g_mem__DOT__delayCnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16787206411050647373ull);
    vlSelf->top__DOT__g_mem__DOT___startDelay_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6334859897328308648ull);
    vlSelf->top__DOT__g_mem__DOT___delayCnt_T_3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1057288611967921324ull);
    vlSelf->top__DOT__g_mem__DOT___validReg_T_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8595791157575010587ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12229957620653414468ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9648772397955850933ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11797376683503797468ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6513266501195115586ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_4 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8511974776159567033ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_5 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17378230012827658187ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_6 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8952740311574973419ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4799255190619529466ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7823522045540637046ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_9 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4323614029384270138ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_10 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10665530626036015142ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_11 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13090567281887460609ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_12 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13808280142226263560ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_13 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5303327874015492636ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_14 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11580232887946620948ull);
    vlSelf->top__DOT__g_mem__DOT__canAccept_prng__DOT__state_15 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4975452212128441098ull);
    vlSelf->top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11692597089112151250ull);
    vlSelf->top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6290643864802357485ull);
    vlSelf->top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2792096088850884449ull);
    vlSelf->top__DOT__i_alu__DOT__csr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12496928071060802711ull);
    vlSelf->top__DOT__i_alu__DOT__out33 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16831374911420946996ull);
    vlSelf->top__DOT__i_alu__DOT___overflowAddBool_T = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1868429683656607649ull);
    vlSelf->top__DOT__i_alu__DOT___overflowAddBool_T_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9700022697400465388ull);
    vlSelf->top__DOT__j_pc_next__DOT__ecall_dnpc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10579087212567707927ull);
    vlSelf->top__DOT__j_pc_next__DOT__is_eql = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1853276616301336150ull);
    vlSelf->top__DOT__j_pc_next__DOT___beq_result_T_9 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1747781117233378952ull);
    vlSelf->__Vfunc_top__DOT__d_idu__DOT__is_break__1__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__g_mem__DOT__mem_data_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__i_alu__DOT__csr_read__3__Vfuncout = 0;
    vlSelf->__Vfunc_top__DOT__j_pc_next__DOT__ecall_read__4__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272892335938733197ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
