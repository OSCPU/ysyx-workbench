// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060111_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060111_top___024root.h"

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_static(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_initial__TOP(Vysyx_23060111_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_initial(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_initial\n"); );
    // Body
    Vysyx_23060111_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__inst = vlSelf->inst;
}

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_initial__TOP(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[0U] = 0x23U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[1U] = 0x73U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[2U] = 0x67U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[3U] = 0x13U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[4U] = 0x6fU;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[5U] = 0x37U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[6U] = 0x17U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[0U] = 0xc00000000ULL;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[1U] = 0xc00000000ULL;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[0U] = 0x46c00000000ULL;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[1U] = 0xe6c00000000ULL;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[0U] = 5U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[1U] = 4U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[2U] = 3U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[3U] = 2U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[4U] = 1U;
}

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_final(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_triggers__stl(Vysyx_23060111_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__stl(Vysyx_23060111_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_stl(Vysyx_23060111_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_settle(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_23060111_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060111_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/ysyx_23060111_top.v", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_23060111_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__stl(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060111_top___024root___stl_sequent__TOP__0(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    QData/*32:0*/ __VdfgTmp_hcb8dd02c__0;
    __VdfgTmp_hcb8dd02c__0 = 0;
    QData/*32:0*/ __VdfgTmp_h2287e566__0;
    __VdfgTmp_h2287e566__0 = 0;
    // Body
    vlSelf->halt_ret = vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
        [0xaU];
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[0U] = 0U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[1U] = 0x46cU;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[2U] 
        = (0xe6c000U | (0xfe000000U & (vlSelf->inst 
                                       << 5U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[3U] 
        = (0xea000000U | (0x1ffffffU & ((0x1ffffe0U 
                                         & ((- (IData)(
                                                       (vlSelf->inst 
                                                        >> 0x1fU))) 
                                            << 5U)) 
                                        | (vlSelf->inst 
                                           >> 0x1bU))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[4U] 
        = (0xcU | (0xffffffe0U & (((- (IData)((vlSelf->inst 
                                               >> 0x1fU))) 
                                   << 0x11U) | (0x1ffe0U 
                                                & (vlSelf->inst 
                                                   >> 0xfU)))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[5U] 
        = (0x2680U | ((0xe0000000U & (vlSelf->inst 
                                      << 0x11U)) | 
                      ((0x10000000U & (vlSelf->inst 
                                       << 8U)) | ((0xffc0000U 
                                                   & (vlSelf->inst 
                                                      >> 3U)) 
                                                  | (0x1fU 
                                                     & ((- (IData)(
                                                                   (vlSelf->inst 
                                                                    >> 0x1fU))) 
                                                        >> 0xfU))))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[6U] 
        = (0xde60000U | ((0x1ffc0U & ((- (IData)((vlSelf->inst 
                                                  >> 0x1fU))) 
                                      << 6U)) | ((0x20U 
                                                  & (vlSelf->inst 
                                                     >> 0x1aU)) 
                                                 | (0x1fU 
                                                    & (vlSelf->inst 
                                                       >> 0xfU)))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[7U] 
        = (0x40000000U | (0x1ffffe00U & (vlSelf->inst 
                                         >> 3U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[8U] 
        = (0x6eU | (0xffe00000U & (vlSelf->inst << 9U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[9U] 
        = (0x2e200U | (0x1fffffU & (vlSelf->inst >> 0x17U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[5U] 
        = (0x6e400000000ULL | ((QData)((IData)((vlSelf->inst 
                                                >> 0xcU))) 
                               << 0xdU));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[6U] 
        = (0x2e200000000ULL | ((QData)((IData)((vlSelf->inst 
                                                >> 0xcU))) 
                               << 0xdU));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2U][0U] 
        = (IData)((((QData)((IData)(((IData)(4U) + vlSelf->pc))) 
                    << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                 + vlSelf->pc)))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2U][1U] 
        = (IData)(((((QData)((IData)(((IData)(4U) + vlSelf->pc))) 
                     << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                  + vlSelf->pc)))) 
                   >> 0x20U));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2U][2U] = 3U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[2U] 
        = (((QData)((IData)(((IData)(4U) + vlSelf->pc))) 
            << 0x20U) | (QData)((IData)(((IData)(4U) 
                                         + vlSelf->pc))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[5U] 
        = (0x400000000ULL | ((QData)((IData)((vlSelf->inst 
                                              >> 0xcU))) 
                             << 0xdU));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[6U] 
        = (0x200000000ULL | ((QData)((IData)((vlSelf->inst 
                                              >> 0xcU))) 
                             << 0xdU));
    __VdfgTmp_h2287e566__0 = (((QData)((IData)((0x7ffU 
                                                & (- (IData)(
                                                             (vlSelf->inst 
                                                              >> 0x1fU)))))) 
                               << 0x16U) | (QData)((IData)(
                                                           ((0x200000U 
                                                             & (vlSelf->inst 
                                                                >> 0xaU)) 
                                                            | ((0x1fe000U 
                                                                & (vlSelf->inst 
                                                                   << 1U)) 
                                                               | ((0x1000U 
                                                                   & (vlSelf->inst 
                                                                      >> 8U)) 
                                                                  | (0xffcU 
                                                                     & (vlSelf->inst 
                                                                        >> 0x13U))))))));
    __VdfgTmp_hcb8dd02c__0 = ((QData)((IData)((((- (IData)(
                                                           (vlSelf->inst 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelf->inst 
                                                  >> 0x14U)))) 
                              << 1U);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[4U] 
        = (0xde600000000ULL | __VdfgTmp_h2287e566__0);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[4U] 
        = (0x600000000ULL | __VdfgTmp_h2287e566__0);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[2U] 
        = (0xcea00000000ULL | __VdfgTmp_hcb8dd02c__0);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[3U] 
        = (0x26800000000ULL | __VdfgTmp_hcb8dd02c__0);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[2U] 
        = (0xa00000000ULL | __VdfgTmp_hcb8dd02c__0);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[3U] 
        = (0x800000000ULL | __VdfgTmp_hcb8dd02c__0);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                               == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                               [0U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                                  [1U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                                  [2U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                                  [3U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                                  [4U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                                  [5U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
              [5U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
              [5U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0x7fU & vlSelf->inst) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
                                  [6U])))) & vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list
              [6U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit) 
           | ((0x7fU & vlSelf->inst) == vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list
              [6U]));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit)
            ? vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out
            : 1ULL);
    vlSelf->inv_flag = (1U & (IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3U][0U] 
        = (IData)((((QData)((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                     >> 1U))) << 0x20U) 
                   | (QData)((IData)(((IData)(4U) + vlSelf->pc)))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3U][1U] 
        = (IData)(((((QData)((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                      >> 1U))) << 0x20U) 
                    | (QData)((IData)(((IData)(4U) 
                                       + vlSelf->pc)))) 
                   >> 0x20U));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3U][2U] = 2U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[3U] 
        = (((QData)((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                             >> 1U))) << 0x20U) | (QData)((IData)(
                                                                  ((IData)(4U) 
                                                                   + vlSelf->pc))));
    vlSelf->__VdfgTmp_hd63b7461__0 = ((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                               >> 1U)) 
                                      + vlSelf->pc);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0 
        = ((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                    >> 1U)) + vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
           [(0x1fU & (vlSelf->inst >> 0xfU))]);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4U][0U] 
        = (IData)((((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
                    << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                 + vlSelf->pc)))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4U][1U] 
        = (IData)(((((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
                     << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                  + vlSelf->pc)))) 
                   >> 0x20U));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4U][2U] = 1U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[4U] 
        = (((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
            << 0x20U) | (QData)((IData)(((IData)(4U) 
                                         + vlSelf->pc))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0U][0U] 
        = (IData)((((QData)((IData)(((IData)(4U) + vlSelf->pc))) 
                    << 0x20U) | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0U][1U] 
        = (IData)(((((QData)((IData)(((IData)(4U) + vlSelf->pc))) 
                     << 0x20U) | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))) 
                   >> 0x20U));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0U][2U] = 5U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1U][0U] 
        = (IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                    << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                 + vlSelf->pc)))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1U][1U] 
        = (IData)(((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                     << 0x20U) | (QData)((IData)(((IData)(4U) 
                                                  + vlSelf->pc)))) 
                   >> 0x20U));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1U][2U] = 4U;
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[0U] 
        = (((QData)((IData)(((IData)(4U) + vlSelf->pc))) 
            << 0x20U) | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[1U] 
        = (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
            << 0x20U) | (QData)((IData)(((IData)(4U) 
                                         + vlSelf->pc))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = ((- (QData)((IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                >> 0x21U))) 
                               == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                               [0U])))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                            >> 0x21U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                   >> 0x21U))) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                                  [1U])))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x21U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                   >> 0x21U))) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                                  [2U])))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x21U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                   >> 0x21U))) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                                  [3U])))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x21U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (QData)((IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                   >> 0x21U))) 
                                  == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                                  [4U])))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x21U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit)
            ? vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out
            : (QData)((IData)(((IData)(4U) + vlSelf->pc))));
}

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_stl(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_23060111_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__ico(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__act(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] inst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__nba(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] inst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060111_top___024root___ctor_var_reset(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->halt_ret = VL_RAND_RESET_I(32);
    vlSelf->inv_flag = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    VL_RAND_RESET_W(308, vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 = VL_RAND_RESET_Q(37);
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(44);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(7);
    }
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_Q(37);
    }
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out = VL_RAND_RESET_Q(37);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1 = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        VL_RAND_RESET_W(68, vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out = VL_RAND_RESET_Q(64);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->__VdfgTmp_hd63b7461__0 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__inst = VL_RAND_RESET_I(32);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
