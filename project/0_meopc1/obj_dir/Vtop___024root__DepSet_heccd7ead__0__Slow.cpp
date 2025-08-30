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

void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i7__DOT__ecall_read_TOP(IData/*31:0*/ pc, CData/*3:0*/ type_p, IData/*31:0*/ &ecall_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i9__DOT__mem_data_read_TOP(IData/*31:0*/ instruction_in, IData/*31:0*/ rs1_data_in, IData/*31:0*/ rs2_data_in, IData/*31:0*/ imm_data_in, IData/*31:0*/ &mem_data_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i6__DOT__csr_read_TOP(IData/*31:0*/ rs1, IData/*31:0*/ imm, CData/*3:0*/ sw, IData/*31:0*/ &csr_read__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3 
        = ((0xfc00U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                       >> 0x10U)) | (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3 
        = ((0x1fc00U & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU)) | (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_imm_type_T_18 
        = ((0xf3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
            ? 6U : ((0x173U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? 6U : ((0x4293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                              ? 5U : ((0x293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                       ? 5U : ((0x93U 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                ? 5U
                                                : (
                                                   (0x193U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 1U
                                                    : 
                                                   ((0x113U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 1U
                                                     : 
                                                    ((0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                      ? 2U
                                                      : 
                                                     ((0x17U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                       ? 2U
                                                       : 
                                                      ((0x6fU 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                        ? 3U
                                                        : 
                                                       ((0x67U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                         ? 3U
                                                         : 
                                                        ((0x123U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                          ? 4U
                                                          : 
                                                         ((0x23U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                           ? 4U
                                                           : 
                                                          ((0xa3U 
                                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                            ? 4U
                                                            : 
                                                           ((0x103U 
                                                             == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                             ? 1U
                                                             : 
                                                            ((0x83U 
                                                              == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                              ? 1U
                                                              : 
                                                             ((0x283U 
                                                               == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                               ? 1U
                                                               : 
                                                              ((0x203U 
                                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                ? 1U
                                                                : 
                                                               ((3U 
                                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                                 ? 1U
                                                                 : 0U)))))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rd_T_12 
        = (0x1fU & ((0x283U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 7U) : ((0x203U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                   ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                      >> 7U) : ((3U 
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
                                                           : 0U))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_pc_next_type_T_19 
        = ((0x203U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
            ? 0U : ((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? 0U : ((0x33U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                              ? 0U : ((0x3b3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                       ? 0U : ((0xb3U 
                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                ? 0U
                                                : (
                                                   (0x42b3U 
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
                                                                  : 3U))))))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_data_control_T_19 
        = ((0x83U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
            ? 2U : ((0x283U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? 2U : ((0x203U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                              ? 2U : ((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                       ? 2U : ((0x33U 
                                                == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)
                                                ? 3U
                                                : (
                                                   (0x3b3U 
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
                                                                  : 0U))))))))))))))))))));
    if ((0x42b3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x2b3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x233U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x333U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x8033U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x63U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x2e3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x263U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x363U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x3e3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0xe3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x1b3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else if ((0x133U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)) {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU));
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0x14U));
    } else {
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 
            = (0x1fU & 0U);
        vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 
            = (0x1fU & 0U);
    }
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rd_T_24 
        = (0x1fU & ((0x173U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 7U) : ((0x4293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                   ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                      >> 7U) : ((0x293U 
                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                 ? 
                                                (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                 >> 7U)
                                                 : 
                                                ((0x93U 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                  ? 
                                                 (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                  >> 7U)
                                                  : 
                                                 ((0x193U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                   >> 7U)
                                                   : 
                                                  ((0x113U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 7U)
                                                    : 
                                                   ((0x37U 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                     >> 7U)
                                                     : 
                                                    ((0x17U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                      >> 7U)
                                                      : 
                                                     ((0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                       >> 7U)
                                                       : 
                                                      ((0x67U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                        >> 7U)
                                                        : 
                                                       ((0x103U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                         >> 7U)
                                                         : 
                                                        ((0x83U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                          >> 7U)
                                                          : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rd_T_12))))))))))))));
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
                                                                    : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_pc_next_type_T_19)))))))))))))))))))))));
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
                                                     : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_data_control_T_19))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_25 
        = (0x1fU & ((0x113U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                     ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                        >> 0xfU) : ((0x67U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                     ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                        >> 0xfU) : 
                                    ((0x123U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                      ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                         >> 0xfU) : 
                                     ((0x23U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                       ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                          >> 0xfU) : 
                                      ((0xa3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                        ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                           >> 0xfU)
                                        : ((0x103U 
                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                            ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                               >> 0xfU)
                                            : ((0x83U 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                   >> 0xfU)
                                                : (
                                                   (0x283U 
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
                                                         : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12)))))))))))))));
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
                                                      : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12))))))));
    if ((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ALU_ctrl = 0U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
    } else if ((0x213U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ALU_ctrl = 4U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
    } else if ((0x313U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ALU_ctrl = 3U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
    } else if ((0x393U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))) {
        vlSelfRef.ALU_ctrl = 6U;
        vlSelfRef.ysyx_25030077_top__DOT__imm_type = 1U;
    } else {
        vlSelfRef.ALU_ctrl = ((0xf3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                               ? 0xbU : ((0x173U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                          ? 0xcU : 
                                         ((0x4293U 
                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                           ? 5U : (
                                                   (0x293U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                    ? 9U
                                                    : 
                                                   ((0x93U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                     ? 8U
                                                     : 
                                                    ((0x193U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                      ? 2U
                                                      : 
                                                     ((0x113U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                       ? 0xaU
                                                       : 
                                                      ((0x37U 
                                                        == 
                                                        (0x7fU 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                        ? 0U
                                                        : 
                                                       ((0x17U 
                                                         == 
                                                         (0x7fU 
                                                          & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                         ? 0U
                                                         : 
                                                        ((0x6fU 
                                                          == 
                                                          (0x7fU 
                                                           & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))
                                                          ? 0U
                                                          : 
                                                         ((0x67U 
                                                           == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
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
                                                                     ? 6U
                                                                     : 
                                                                    ((0xb3U 
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
                                                                                 : 0U)))))))))))))))))))))))))))))))))));
        vlSelfRef.ysyx_25030077_top__DOT__imm_type 
            = vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_imm_type_T_18;
    }
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
    vlSelfRef.rd = (0x1fU & ((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                              ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 7U) : ((0x213U 
                                            == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                            ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                               >> 7U)
                                            : ((0x313U 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                ? (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                   >> 7U)
                                                : (
                                                   (0x393U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 7U)
                                                    : 
                                                   ((0xf3U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                     >> 7U)
                                                     : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rd_T_24)))))));
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i7__DOT__ecall_read_TOP(vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state, (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type), vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i7__DOT__ecall_read__3__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__rs1 = (0x1fU 
                                             & ((0x13U 
                                                 == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                 ? 
                                                (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                 >> 0xfU)
                                                 : 
                                                ((0x213U 
                                                  == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                  ? 
                                                 (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                  >> 0xfU)
                                                  : 
                                                 ((0x313U 
                                                   == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                   ? 
                                                  (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                   >> 0xfU)
                                                   : 
                                                  ((0x393U 
                                                    == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                    ? 
                                                   (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                    >> 0xfU)
                                                    : 
                                                   ((0xf3U 
                                                     == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                     ? 
                                                    (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                     >> 0xfU)
                                                     : 
                                                    ((0x173U 
                                                      == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                      ? 
                                                     (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                      >> 0xfU)
                                                      : 
                                                     ((0x4293U 
                                                       == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                       ? 
                                                      (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                       >> 0xfU)
                                                       : 
                                                      ((0x293U 
                                                        == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                        ? 
                                                       (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                        >> 0xfU)
                                                        : 
                                                       ((0x93U 
                                                         == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                         >> 0xfU)
                                                         : 
                                                        ((0x193U 
                                                          == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))
                                                          ? 
                                                         (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                          >> 0xfU)
                                                          : (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_25))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc 
        = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i7__DOT__ecall_read__3__Vfuncout;
    vlSelfRef.ysyx_25030077_top__DOT__i4__DOT___GEN_85 
        = ((0x15U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21
            : ((0x14U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20
                : ((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19
                    : ((0x12U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18
                        : ((0x11U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17
                            : ((0x10U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16
                                : ((0xfU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15
                                    : ((0xeU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14
                                        : ((0xdU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13
                                            : ((0xcU 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs2))
                                                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12
                                                : (
                                                   (0xbU 
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
                                                              : vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0)))))))))))))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i4__DOT___GEN_53 
        = ((0x15U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21
            : ((0x14U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20
                : ((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19
                    : ((0x12U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18
                        : ((0x11U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17
                            : ((0x10U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16
                                : ((0xfU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                    ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15
                                    : ((0xeU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                        ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14
                                        : ((0xdU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                            ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13
                                            : ((0xcU 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__rs1))
                                                ? vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12
                                                : (
                                                   (0xbU 
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
                                                              : vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0)))))))))))))))))))));
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
                                                     : vlSelfRef.ysyx_25030077_top__DOT__i4__DOT___GEN_85))))))))));
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
                                                     : vlSelfRef.ysyx_25030077_top__DOT__i4__DOT___GEN_53))))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i5__DOT___io_data_2_T 
        = ((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
            ? vlSelfRef.rs2_out : vlSelfRef.imm);
    vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql 
        = (vlSelfRef.rs1_out == vlSelfRef.rs2_out);
    Vtop___024root____Vdpiimwrap_ysyx_25030077_top__DOT__i9__DOT__mem_data_read_TOP(vlSelfRef.ysyx_25030077_top__DOT__instruction_out, vlSelfRef.rs1_out, vlSelfRef.rs2_out, vlSelfRef.imm, vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i9__DOT__mem_data_read__4__Vfuncout);
    vlSelfRef.ysyx_25030077_top__DOT__mem_data = vlSelfRef.__Vfunc_ysyx_25030077_top__DOT__i9__DOT__mem_data_read__4__Vfuncout;
    vlSelfRef.ysyx_25030077_top__DOT__i6__DOT____VdfgRegularize_h4243b50f_0_2 
        = ((2U != (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control)) 
           & (vlSelfRef.ysyx_25030077_top__DOT__i5__DOT___io_data_2_T 
              >> 0x1fU));
    vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2 = 
        ((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
          ? 0U : vlSelfRef.ysyx_25030077_top__DOT__i5__DOT___io_data_2_T);
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
                                    >> 0x1fU) == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT____VdfgRegularize_h4243b50f_0_2)) 
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
                                                   != (IData)(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT____VdfgRegularize_h4243b50f_0_2)) 
                                                  & ((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                      >> 0x1fU) 
                                                     != 
                                                     (1U 
                                                      & (IData)(
                                                                (vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult 
                                                                 >> 0x1fU))))))));
    vlSelfRef.ysyx_25030077_top__DOT__i6__DOT___io_out_T_39 
        = (0x7fffffffffffffffULL & (((((((((1U & ((IData)(1U) 
                                                  << (IData)(vlSelfRef.ALU_ctrl)))
                                            ? vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult
                                            : 0ULL) 
                                          | ((2U & 
                                              ((IData)(1U) 
                                               << (IData)(vlSelfRef.ALU_ctrl)))
                                              ? vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult
                                              : 0ULL)) 
                                         | (QData)((IData)(
                                                           (1U 
                                                            & ((((IData)(1U) 
                                                                 << (IData)(vlSelfRef.ALU_ctrl)) 
                                                                >> 2U) 
                                                               & (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                                  < vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)))))) 
                                        | (QData)((IData)(
                                                          ((8U 
                                                            & ((IData)(1U) 
                                                               << (IData)(vlSelfRef.ALU_ctrl)))
                                                            ? 
                                                           (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                            | vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                                            : 0U)))) 
                                       | (QData)((IData)(
                                                         ((0x10U 
                                                           & ((IData)(1U) 
                                                              << (IData)(vlSelfRef.ALU_ctrl)))
                                                           ? 
                                                          (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                           ^ vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                                           : 0U)))) 
                                      | (QData)((IData)(
                                                        ((0x20U 
                                                          & ((IData)(1U) 
                                                             << (IData)(vlSelfRef.ALU_ctrl)))
                                                          ? 
                                                         VL_SHIFTRS_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                                          : 0U)))) 
                                     | (QData)((IData)(
                                                       ((0x40U 
                                                         & ((IData)(1U) 
                                                            << (IData)(vlSelfRef.ALU_ctrl)))
                                                         ? 
                                                        (vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                                         & vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                                                         : 0U)))) 
                                    | ((0x100U & ((IData)(1U) 
                                                  << (IData)(vlSelfRef.ALU_ctrl)))
                                        ? ((QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1)) 
                                           << ((2U 
                                                == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
                                                ? 0U
                                                : (0x1fU 
                                                   & vlSelfRef.ysyx_25030077_top__DOT__i5__DOT___io_data_2_T)))
                                        : 0ULL)));
    vlSelfRef.ysyx_25030077_top__DOT__ALU_result = 
        ((1U & ((((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                 >> 0xbU) | (((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)) 
                             >> 0xcU))) ? vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__csr_data
          : (((IData)(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT___io_out_T_39) 
              | ((0x200U & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))
                  ? VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)
                  : 0U)) | (IData)((QData)((IData)(
                                                   (1U 
                                                    & ((((IData)(1U) 
                                                         << (IData)(vlSelfRef.ALU_ctrl)) 
                                                        >> 0xaU) 
                                                       & VL_LTS_III(32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2))))))));
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
    vlSelf->ALU_ctrl = VL_RAND_RESET_I(4);
    vlSelf->rs1_out = VL_RAND_RESET_I(32);
    vlSelf->rs2_out = VL_RAND_RESET_I(32);
    vlSelf->ALU_carry = VL_RAND_RESET_I(1);
    vlSelf->ALU_overflow = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25030077_top__DOT__Pc_next = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__instruction_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__imm_type = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25030077_top__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__data_control = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25030077_top__DOT__pc_next_type = VL_RAND_RESET_I(4);
    vlSelf->ysyx_25030077_top__DOT__is_break_out = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25030077_top__DOT__ALU_result = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__mem_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__ALU_data_1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__ALU_data_2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i0__DOT__state = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2 = VL_RAND_RESET_I(10);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___issrai_T_3 = VL_RAND_RESET_I(16);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___isadd_T_3 = VL_RAND_RESET_I(17);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_imm_type_T_18 = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_12 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_rs1_T_25 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_rs2_T_12 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_rd_T_12 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_rd_T_24 = VL_RAND_RESET_I(5);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_data_control_T_19 = VL_RAND_RESET_I(3);
    vlSelf->ysyx_25030077_top__DOT__i2__DOT___io_pc_next_type_T_19 = VL_RAND_RESET_I(4);
    vlSelf->ysyx_25030077_top__DOT__i3__DOT__Imm_type1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_0 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_1 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_2 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_3 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_4 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_5 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_6 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_7 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_8 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_9 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_10 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_11 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_12 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_13 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_14 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_15 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_16 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_17 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_18 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_19 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_20 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_21 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_22 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_23 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_24 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_25 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_26 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_27 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_28 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_29 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_30 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT__regs_31 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT___GEN_53 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i4__DOT___GEN_85 = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i5__DOT___io_data_2_T = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT__csr_data = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT__addResult = VL_RAND_RESET_Q(33);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT__subResult = VL_RAND_RESET_Q(33);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT___io_out_T_39 = VL_RAND_RESET_Q(63);
    vlSelf->ysyx_25030077_top__DOT__i6__DOT____VdfgRegularize_h4243b50f_0_2 = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_25030077_top__DOT__i7__DOT__is_eql = VL_RAND_RESET_I(1);
    vlSelf->ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9 = VL_RAND_RESET_I(32);
    vlSelf->__Vfunc_ysyx_25030077_top__DOT__i1__DOT__addr_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077_top__DOT__i2__DOT__is_break__1__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077_top__DOT__i6__DOT__csr_read__2__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077_top__DOT__i7__DOT__ecall_read__3__Vfuncout = 0;
    vlSelf->__Vfunc_ysyx_25030077_top__DOT__i9__DOT__mem_data_read__4__Vfuncout = 0;
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
