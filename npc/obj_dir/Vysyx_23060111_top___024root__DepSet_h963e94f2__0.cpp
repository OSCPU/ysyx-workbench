// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060111_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060111_top___024root.h"

VL_INLINE_OPT void Vysyx_23060111_top___024root___ico_sequent__TOP__0(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___ico_sequent__TOP__0\n"); );
    // Init
    QData/*32:0*/ __VdfgTmp_hcb8dd02c__0;
    __VdfgTmp_hcb8dd02c__0 = 0;
    QData/*32:0*/ __VdfgTmp_h2287e566__0;
    __VdfgTmp_h2287e566__0 = 0;
    // Body
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

void Vysyx_23060111_top___024root___eval_ico(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vysyx_23060111_top___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_23060111_top___024root___eval_act(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vysyx_23060111_top___024root___nba_sequent__TOP__1(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0;
    __Vdlyvdim0__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0 = 0;
    IData/*31:0*/ __Vdlyvval__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0;
    __Vdlyvval__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0 = 0;
    // Body
    __Vdlyvval__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0 
        = (IData)((vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1 
                   >> 0x20U));
    __Vdlyvdim0__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0 
        = (0x1fU & (vlSelf->inst >> 7U));
    vlSelf->pc = ((IData)(vlSelf->rst) ? 0x80000000U
                   : (IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1));
    vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[__Vdlyvdim0__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0] 
        = __Vdlyvval__ysyx_23060111_top__DOT__reg___0240__DOT__rf__v0;
    vlSelf->halt_ret = vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
        [0xaU];
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
}

VL_INLINE_OPT void Vysyx_23060111_top___024root___nba_sequent__TOP__2(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___nba_sequent__TOP__2\n"); );
    // Body
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

void Vysyx_23060111_top___024root___nba_sequent__TOP__0(Vysyx_23060111_top___024root* vlSelf);

void Vysyx_23060111_top___024root___eval_nba(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vysyx_23060111_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vysyx_23060111_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        Vysyx_23060111_top___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vysyx_23060111_top___024root___eval_triggers__ico(Vysyx_23060111_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__ico(Vysyx_23060111_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vysyx_23060111_top___024root___eval_triggers__act(Vysyx_23060111_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__act(Vysyx_23060111_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__nba(Vysyx_23060111_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_23060111_top___024root___eval(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vysyx_23060111_top___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060111_top___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/ysyx_23060111_top.v", 2, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vysyx_23060111_top___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vysyx_23060111_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vysyx_23060111_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/ysyx_23060111_top.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vysyx_23060111_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060111_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/ysyx_23060111_top.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vysyx_23060111_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vysyx_23060111_top___024root___eval_debug_assertions(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
