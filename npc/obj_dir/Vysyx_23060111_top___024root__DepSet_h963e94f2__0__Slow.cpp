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
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[0U] = 0x67U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[1U] = 0x13U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[2U] = 0x6fU;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[3U] = 0x37U;
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[4U] = 0x17U;
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
    IData/*31:0*/ __VdfgTmp_h6ea2e89f__0;
    __VdfgTmp_h6ea2e89f__0 = 0;
    IData/*31:0*/ __VdfgTmp_h229725e1__0;
    __VdfgTmp_h229725e1__0 = 0;
    // Body
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[3U] 
        = (0x37200000000ULL | (QData)((IData)((0xfffff000U 
                                               & vlSelf->inst))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[4U] 
        = (0x17100000000ULL | (QData)((IData)((0xfffff000U 
                                               & vlSelf->inst))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0U] 
        = (0x500000000ULL | (QData)((IData)(((IData)(4U) 
                                             + vlSelf->pc))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2U] 
        = (0x300000000ULL | (QData)((IData)(((IData)(4U) 
                                             + vlSelf->pc))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[0U] 
        = ((IData)(4U) + vlSelf->pc);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[2U] 
        = ((IData)(4U) + vlSelf->pc);
    vlSelf->ysyx_23060111_top__DOT__rout = vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
        [(0x1fU & (vlSelf->inst >> 0xfU))];
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[3U] 
        = (0x200000000ULL | (QData)((IData)((0xfffff000U 
                                             & vlSelf->inst))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[4U] 
        = (0x100000000ULL | (QData)((IData)((0xfffff000U 
                                             & vlSelf->inst))));
    __VdfgTmp_h229725e1__0 = (((- (IData)((vlSelf->inst 
                                           >> 0x1fU))) 
                               << 0x15U) | ((0x100000U 
                                             & (vlSelf->inst 
                                                >> 0xbU)) 
                                            | ((0xff000U 
                                                & vlSelf->inst) 
                                               | ((0x800U 
                                                   & (vlSelf->inst 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlSelf->inst 
                                                        >> 0x14U))))));
    __VdfgTmp_h6ea2e89f__0 = (((- (IData)((vlSelf->inst 
                                           >> 0x1fU))) 
                               << 0xcU) | (vlSelf->inst 
                                           >> 0x14U));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[2U] 
        = (0x6f300000000ULL | (QData)((IData)(__VdfgTmp_h229725e1__0)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[2U] 
        = (0x300000000ULL | (QData)((IData)(__VdfgTmp_h229725e1__0)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[0U] 
        = (IData)((0x67500000000ULL | (QData)((IData)(__VdfgTmp_h6ea2e89f__0))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[1U] 
        = ((0xfffff800U & (((- (IData)((vlSelf->inst 
                                        >> 0x1fU))) 
                            << 0x17U) | (0x7ff800U 
                                         & (vlSelf->inst 
                                            >> 9U)))) 
           | (IData)(((0x67500000000ULL | (QData)((IData)(__VdfgTmp_h6ea2e89f__0))) 
                      >> 0x20U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[2U] 
        = (0x9a000U | ((0xff800000U & (vlSelf->inst 
                                       << 2U)) | (0x7ffU 
                                                  & ((- (IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x1fU))) 
                                                     >> 9U))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[3U] 
        = (0xbcc00000U | ((0x3ff800U & ((- (IData)(
                                                   (vlSelf->inst 
                                                    >> 0x1fU))) 
                                        << 0xbU)) | 
                          ((0x400U & (vlSelf->inst 
                                      >> 0x15U)) | 
                           ((0x3fcU & (vlSelf->inst 
                                       >> 0xaU)) | 
                            ((2U & (vlSelf->inst >> 0x13U)) 
                             | (1U & (vlSelf->inst 
                                      >> 0x1eU)))))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[4U] 
        = (1U | (0xffffe000U & (vlSelf->inst << 1U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[5U] 
        = (0x6e4U | ((0xff000000U & (vlSelf->inst << 0xcU)) 
                     | (0x1fffU & (vlSelf->inst >> 0x1fU))));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4[6U] 
        = (0x171000U | (0xffffffU & (vlSelf->inst >> 0x14U)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[0U] 
        = (0x67500000000ULL | (QData)((IData)(__VdfgTmp_h6ea2e89f__0)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[1U] 
        = (0x13400000000ULL | (QData)((IData)(__VdfgTmp_h6ea2e89f__0)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[0U] 
        = (0x500000000ULL | (QData)((IData)(__VdfgTmp_h6ea2e89f__0)));
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[1U] 
        = (0x400000000ULL | (QData)((IData)(__VdfgTmp_h6ea2e89f__0)));
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
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit)
            ? vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out
            : 0ULL);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3U] 
        = (0x200000000ULL | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1)));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1U] 
        = (0x400000000ULL | (QData)((IData)(((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1) 
                                             + vlSelf->ysyx_23060111_top__DOT__rout))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4U] 
        = (0x100000000ULL | (QData)((IData)(((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1) 
                                             + vlSelf->pc))));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[3U] 
        = (IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[1U] 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1) 
           + vlSelf->ysyx_23060111_top__DOT__rout);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[4U] 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1) 
           + vlSelf->pc);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = ((- (IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                        >> 0x20U))) 
                       == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                            >> 0x20U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                           >> 0x20U))) 
                          == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x20U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                           >> 0x20U))) 
                          == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x20U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                           >> 0x20U))) 
                          == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x20U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
        = (vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out 
           | ((- (IData)(((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                           >> 0x20U))) 
                          == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit) 
           | ((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                               >> 0x20U))) == vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->ysyx_23060111_top__DOT__dnpc = ((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit)
                                             ? vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out
                                             : 0U);
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
    vlSelf->ysyx_23060111_top__DOT__dnpc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060111_top__DOT__rout = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[__Vi0] = VL_RAND_RESET_I(32);
    }
    VL_RAND_RESET_W(215, vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 = VL_RAND_RESET_Q(36);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(43);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(7);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_Q(36);
    }
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out = VL_RAND_RESET_Q(36);
    vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[__Vi0] = VL_RAND_RESET_Q(36);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(4);
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__inst = VL_RAND_RESET_I(32);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
