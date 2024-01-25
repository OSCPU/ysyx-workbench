// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060111_top__Syms.h"


void Vysyx_23060111_top___024root__trace_chg_sub_0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_23060111_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_23060111_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060111_top___024root*>(voidSelf);
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_23060111_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_23060111_top___024root__trace_chg_sub_0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<11>/*351:0*/ __Vtemp_hbd33e13b__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+1,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+2,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[2]),4);
        bufp->chgCData(oldp+3,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[3]),4);
        bufp->chgCData(oldp+4,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[4]),4);
        bufp->chgCData(oldp+5,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+6,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+7,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+8,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+9,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[4]),7);
        bufp->chgCData(oldp+10,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[5]),7);
        bufp->chgCData(oldp+11,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[6]),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+12,((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                 >> 0x21U)))),4);
        bufp->chgIData(oldp+13,((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                         >> 1U))),32);
        bufp->chgQData(oldp+14,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1),37);
        bufp->chgWData(oldp+16,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4),308);
        bufp->chgQData(oldp+26,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[0]),44);
        bufp->chgQData(oldp+28,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[1]),44);
        bufp->chgQData(oldp+30,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[2]),44);
        bufp->chgQData(oldp+32,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[3]),44);
        bufp->chgQData(oldp+34,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[4]),44);
        bufp->chgQData(oldp+36,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[5]),44);
        bufp->chgQData(oldp+38,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[6]),44);
        bufp->chgQData(oldp+40,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[0]),37);
        bufp->chgQData(oldp+42,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[1]),37);
        bufp->chgQData(oldp+44,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[2]),37);
        bufp->chgQData(oldp+46,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[3]),37);
        bufp->chgQData(oldp+48,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[4]),37);
        bufp->chgQData(oldp+50,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[5]),37);
        bufp->chgQData(oldp+52,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[6]),37);
        bufp->chgQData(oldp+54,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out),37);
        bufp->chgBit(oldp+56,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgIData(oldp+57,((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1)),32);
        bufp->chgIData(oldp+58,((IData)((vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1 
                                         >> 0x20U))),32);
        bufp->chgQData(oldp+59,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1),64);
        bufp->chgWData(oldp+61,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0]),68);
        bufp->chgWData(oldp+64,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1]),68);
        bufp->chgWData(oldp+67,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2]),68);
        bufp->chgWData(oldp+70,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3]),68);
        bufp->chgWData(oldp+73,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4]),68);
        bufp->chgQData(oldp+76,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[0]),64);
        bufp->chgQData(oldp+78,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[1]),64);
        bufp->chgQData(oldp+80,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[2]),64);
        bufp->chgQData(oldp+82,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[3]),64);
        bufp->chgQData(oldp+84,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[4]),64);
        bufp->chgQData(oldp+86,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out),64);
        bufp->chgBit(oldp+88,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+89,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
        bufp->chgIData(oldp+90,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[1]),32);
        bufp->chgIData(oldp+91,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[2]),32);
        bufp->chgIData(oldp+92,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[3]),32);
        bufp->chgIData(oldp+93,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[4]),32);
        bufp->chgIData(oldp+94,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[5]),32);
        bufp->chgIData(oldp+95,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[6]),32);
        bufp->chgIData(oldp+96,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[7]),32);
        bufp->chgIData(oldp+97,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[8]),32);
        bufp->chgIData(oldp+98,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[9]),32);
        bufp->chgIData(oldp+99,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[10]),32);
        bufp->chgIData(oldp+100,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[11]),32);
        bufp->chgIData(oldp+101,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[12]),32);
        bufp->chgIData(oldp+102,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[13]),32);
        bufp->chgIData(oldp+103,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[14]),32);
        bufp->chgIData(oldp+104,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[15]),32);
        bufp->chgIData(oldp+105,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[16]),32);
        bufp->chgIData(oldp+106,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[17]),32);
        bufp->chgIData(oldp+107,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[18]),32);
        bufp->chgIData(oldp+108,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[19]),32);
        bufp->chgIData(oldp+109,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[20]),32);
        bufp->chgIData(oldp+110,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[21]),32);
        bufp->chgIData(oldp+111,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[22]),32);
        bufp->chgIData(oldp+112,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[23]),32);
        bufp->chgIData(oldp+113,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[24]),32);
        bufp->chgIData(oldp+114,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[25]),32);
        bufp->chgIData(oldp+115,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[26]),32);
        bufp->chgIData(oldp+116,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[27]),32);
        bufp->chgIData(oldp+117,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[28]),32);
        bufp->chgIData(oldp+118,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[29]),32);
        bufp->chgIData(oldp+119,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[30]),32);
        bufp->chgIData(oldp+120,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+121,(vlSelf->rst));
    bufp->chgBit(oldp+122,(vlSelf->clk));
    bufp->chgIData(oldp+123,(vlSelf->inst),32);
    bufp->chgIData(oldp+124,(vlSelf->pc),32);
    bufp->chgIData(oldp+125,(vlSelf->halt_ret),32);
    bufp->chgBit(oldp+126,(vlSelf->inv_flag));
    bufp->chgCData(oldp+127,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+128,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->chgCData(oldp+129,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgCData(oldp+130,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->chgCData(oldp+131,((0x1fU & (vlSelf->inst 
                                       >> 0x14U))),5);
    bufp->chgCData(oldp+132,((vlSelf->inst >> 0x19U)),7);
    bufp->chgIData(oldp+133,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))]),32);
    bufp->chgQData(oldp+134,((QData)((IData)(((IData)(4U) 
                                              + vlSelf->pc)))),64);
    __Vtemp_hbd33e13b__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(4U) 
                                                          + vlSelf->pc))) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))));
    __Vtemp_hbd33e13b__0[1U] = (IData)(((((QData)((IData)(
                                                          ((IData)(4U) 
                                                           + vlSelf->pc))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))) 
                                        >> 0x20U));
    __Vtemp_hbd33e13b__0[2U] = (5U | ((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((IData)(4U) 
                                                                  + vlSelf->pc))))) 
                                      << 4U));
    __Vtemp_hbd33e13b__0[3U] = (((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x1cU) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 4U));
    __Vtemp_hbd33e13b__0[4U] = (0x40U | (((IData)((
                                                   ((QData)((IData)(
                                                                    ((IData)(4U) 
                                                                     + vlSelf->pc))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)))) 
                                          << 8U) | 
                                         ((IData)((
                                                   (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelf->pc)))) 
                                                   >> 0x20U)) 
                                          >> 0x1cU)));
    __Vtemp_hbd33e13b__0[5U] = (((IData)((((QData)((IData)(
                                                           ((IData)(4U) 
                                                            + vlSelf->pc))) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)))) 
                                 >> 0x18U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         ((IData)(4U) 
                                                                          + vlSelf->pc))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0))) 
                                                       >> 0x20U)) 
                                              << 8U));
    __Vtemp_hbd33e13b__0[6U] = (0x300U | (((IData)(
                                                   (((QData)((IData)(
                                                                     (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                                      >> 1U))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelf->pc))))) 
                                           << 0xcU) 
                                          | ((IData)(
                                                     ((((QData)((IData)(
                                                                        ((IData)(4U) 
                                                                         + vlSelf->pc))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0))) 
                                                      >> 0x20U)) 
                                             >> 0x18U)));
    __Vtemp_hbd33e13b__0[7U] = (((IData)((((QData)((IData)(
                                                           (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                            >> 1U))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x14U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                                          >> 1U))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 0xcU));
    __Vtemp_hbd33e13b__0[8U] = (0x2000U | (((IData)(
                                                    (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       ((IData)(4U) 
                                                                        + vlSelf->pc))))) 
                                            << 0x10U) 
                                           | ((IData)(
                                                      ((((QData)((IData)(
                                                                         (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                                          >> 1U))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              >> 0x14U)));
    __Vtemp_hbd33e13b__0[9U] = (((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x10U) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 0x10U));
    __Vtemp_hbd33e13b__0[0xaU] = (0x10000U | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              >> 0x10U));
    bufp->chgWData(oldp+136,(__Vtemp_hbd33e13b__0),340);
}

void Vysyx_23060111_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_23060111_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060111_top___024root*>(voidSelf);
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
