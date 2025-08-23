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
            VL_FATAL_MT("vsrc/top.v", 1941, "", "Settle region did not converge.");
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
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
    // Body
    vlSelfRef.io_is_unknown_instruction = vlSelfRef.top__DOT__j_pc_next__DOT__is_unknown_instruction_reg;
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en 
        = ((~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)) 
           & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__validReg));
    vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T_1 
        = ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
           & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__validReg));
    vlSelfRef.top__DOT__j_pc_next__DOT__is_eql = (vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                                  == vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg);
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
    vlSelfRef.top__DOT__j_pc_next__DOT__canAccept = 
        (1U & ((~ (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__validReg)) 
               | (~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full))));
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
    vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2 = (
                                                   (0x380U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 5U)) 
                                                   | (0x7fU 
                                                      & vlSelfRef.top__DOT__c_sram__DOT__instReg));
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
    vlSelfRef.top__DOT__f_gpr__DOT___validReg_T_1 = 
        ((~ (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept)) 
         & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
    vlSelfRef.top__DOT__j_pc_next__DOT___validReg_T 
        = ((IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg) 
           & (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept));
    vlSelfRef.top__DOT__f_gpr__DOT__canAccept = (1U 
                                                 & ((~ (IData)(vlSelfRef.top__DOT__f_gpr__DOT__validReg)) 
                                                    | (IData)(vlSelfRef.top__DOT__j_pc_next__DOT__canAccept)));
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
    vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3 = ((0x1fc00U 
                                                   & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                      >> 0xfU)) 
                                                  | (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3 = (
                                                   (0xfc00U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 0x10U)) 
                                                   | (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2));
    vlSelfRef.top__DOT__f_gpr__DOT___regs_T = ((IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg) 
                                               & (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept));
    vlSelfRef.top__DOT__i_alu__DOT___validReg_T_1 = 
        ((~ (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept)) 
         & (IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg));
    vlSelfRef.top__DOT__i_alu__DOT__canAccept = (1U 
                                                 & ((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT__validReg)) 
                                                    | (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept)));
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
    vlSelfRef.top__DOT__d_idu__DOT___validReg_T_1 = 
        ((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept)) 
         & (IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg));
    vlSelfRef.top__DOT__i_alu__DOT___validReg_T = ((IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg) 
                                                   & (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept));
    vlSelfRef.top__DOT__d_idu__DOT__canAccept = (1U 
                                                 & ((~ (IData)(vlSelfRef.top__DOT__d_idu__DOT__validReg)) 
                                                    | (IData)(vlSelfRef.top__DOT__i_alu__DOT__canAccept)));
    if ((2U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))) {
        vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2 = 0U;
        vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0 = 0U;
    } else {
        vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2 
            = top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T;
        vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0 
            = (0x1fU & top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T);
    }
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
    vlSelfRef.top__DOT__c_sram__DOT___validReg_T_1 
        = ((~ (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept)) 
           & (IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg));
    vlSelfRef.top__DOT__d_idu__DOT___validReg_T = ((IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg) 
                                                   & (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept));
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready 
        = (1U & ((~ (IData)(vlSelfRef.top__DOT__c_sram__DOT__validReg)) 
                 | (IData)(vlSelfRef.top__DOT__d_idu__DOT__canAccept)));
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
    vlSelfRef.top__DOT__d_idu__DOT___GEN_0 = ((IData)(vlSelfRef.reset)
                                               ? 0U
                                               : ((IData)(vlSelfRef.top__DOT__d_idu__DOT___validReg_T)
                                                   ? (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg)
                                                   : (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)));
    vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__do_deq 
        = ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready) 
           & (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
    vlSelfRef.top__DOT__c_sram__DOT___validReg_T = 
        ((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
         & (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ_io_deq_ready));
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

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
    vlSelf->io_is_unknown_instruction = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__e_imm_io_imm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr_io_rdata_rs1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr_io_rdata_rs2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__h_data_control_io_alu_Req_bits_data1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__h_data_control_io_alu_Req_bits_data2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__b_ifu__DOT__reqQ_io_deq_ready = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__b_ifu__DOT__reqQ__DOT__do_deq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__c_sram__DOT__instReg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__c_sram__DOT__pcReg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__c_sram__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__c_sram__DOT___validReg_T = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__c_sram__DOT___validReg_T_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__d_idu__DOT__inst_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__d_idu__DOT__pc_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__d_idu__DOT__imm_type_reg_o = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__d_idu__DOT__rs1_reg_o = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT__rs2_reg_o = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT__rd_reg_o = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT__ALU_ctrl_reg_o = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__d_idu__DOT__data_control_reg_o = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__d_idu__DOT__pc_next_type_reg_o = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__d_idu__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__d_idu__DOT__canAccept = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__d_idu__DOT___validReg_T = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__d_idu__DOT___validReg_T_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__d_idu__DOT___isaddi_T_2 = VL_RAND_RESET_I(10);
    vlSelf->top__DOT__d_idu__DOT___issrai_T_3 = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__d_idu__DOT___isadd_T_3 = VL_RAND_RESET_I(17);
    vlSelf->top__DOT__d_idu__DOT___imm_type_reg_T_18 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__d_idu__DOT___rs1_reg_T_25 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT___rs2_reg_T_12 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT___rd_reg_T_24 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT__ALU_ctrl_reg = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__d_idu__DOT___data_control_reg_T_19 = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__d_idu__DOT___pc_next_type_reg_T_19 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__d_idu__DOT___GEN_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__f_gpr__DOT__regs_0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_1 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_3 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_5 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_6 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_7 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_8 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_9 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_10 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_11 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_12 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_13 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_14 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_15 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_16 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_17 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_18 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_19 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_20 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_21 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_22 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_23 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_24 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_25 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_26 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_27 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_28 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_29 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_30 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__regs_31 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__f_gpr__DOT__rs1_data_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__rs2_data_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__instruction_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__pc_next_type_reg = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__f_gpr__DOT__pc_count_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT__canAccept = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__f_gpr__DOT___regs_T = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__f_gpr__DOT___GEN_30 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__f_gpr__DOT___validReg_T_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i_alu__DOT__out_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i_alu__DOT__rd_addr_reg = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__i_alu__DOT__rs1_data_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i_alu__DOT__rs2_data_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i_alu__DOT__instruction_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i_alu__DOT__pc_next_type_reg = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__i_alu__DOT__pc_count_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i_alu__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i_alu__DOT__canAccept = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i_alu__DOT___out33_T_47 = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__i_alu__DOT___validReg_T = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i_alu__DOT___validReg_T_1 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0 = VL_RAND_RESET_I(5);
    vlSelf->top__DOT__j_pc_next__DOT__validReg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__j_pc_next__DOT__pc_next_reg = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__j_pc_next__DOT__is_unknown_instruction_reg = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__j_pc_next__DOT__is_eql = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__j_pc_next__DOT___beq_result_T_9 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__j_pc_next__DOT__canAccept = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__j_pc_next__DOT___validReg_T = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__j_pc_next__DOT___validReg_T_1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
