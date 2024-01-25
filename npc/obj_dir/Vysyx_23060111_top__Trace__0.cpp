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
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+1,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+2,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+3,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+4,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[4]),7);
        bufp->chgCData(oldp+5,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[5]),7);
        bufp->chgCData(oldp+6,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[6]),7);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+7,(vlSelf->ysyx_23060111_top__DOT__type_i),4);
        bufp->chgIData(oldp+8,((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                        >> 1U))),32);
        bufp->chgQData(oldp+9,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1),37);
        bufp->chgWData(oldp+11,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4),308);
        bufp->chgQData(oldp+21,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[0]),44);
        bufp->chgQData(oldp+23,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[1]),44);
        bufp->chgQData(oldp+25,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[2]),44);
        bufp->chgQData(oldp+27,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[3]),44);
        bufp->chgQData(oldp+29,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[4]),44);
        bufp->chgQData(oldp+31,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[5]),44);
        bufp->chgQData(oldp+33,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[6]),44);
        bufp->chgQData(oldp+35,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[0]),37);
        bufp->chgQData(oldp+37,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[1]),37);
        bufp->chgQData(oldp+39,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[2]),37);
        bufp->chgQData(oldp+41,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[3]),37);
        bufp->chgQData(oldp+43,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[4]),37);
        bufp->chgQData(oldp+45,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[5]),37);
        bufp->chgQData(oldp+47,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[6]),37);
        bufp->chgQData(oldp+49,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out),37);
        bufp->chgBit(oldp+51,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+52,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[1]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[2]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[3]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[4]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[5]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[6]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[7]),32);
        bufp->chgIData(oldp+60,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[8]),32);
        bufp->chgIData(oldp+61,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[9]),32);
        bufp->chgIData(oldp+62,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[10]),32);
        bufp->chgIData(oldp+63,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[11]),32);
        bufp->chgIData(oldp+64,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[12]),32);
        bufp->chgIData(oldp+65,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[13]),32);
        bufp->chgIData(oldp+66,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[14]),32);
        bufp->chgIData(oldp+67,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[15]),32);
        bufp->chgIData(oldp+68,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[16]),32);
        bufp->chgIData(oldp+69,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[17]),32);
        bufp->chgIData(oldp+70,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[18]),32);
        bufp->chgIData(oldp+71,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[19]),32);
        bufp->chgIData(oldp+72,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[20]),32);
        bufp->chgIData(oldp+73,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[21]),32);
        bufp->chgIData(oldp+74,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[22]),32);
        bufp->chgIData(oldp+75,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[23]),32);
        bufp->chgIData(oldp+76,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[24]),32);
        bufp->chgIData(oldp+77,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[25]),32);
        bufp->chgIData(oldp+78,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[26]),32);
        bufp->chgIData(oldp+79,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[27]),32);
        bufp->chgIData(oldp+80,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[28]),32);
        bufp->chgIData(oldp+81,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[29]),32);
        bufp->chgIData(oldp+82,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[30]),32);
        bufp->chgIData(oldp+83,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+84,(vlSelf->rst));
    bufp->chgBit(oldp+85,(vlSelf->clk));
    bufp->chgIData(oldp+86,(vlSelf->inst),32);
    bufp->chgIData(oldp+87,(vlSelf->pc),32);
    bufp->chgIData(oldp+88,(vlSelf->halt_ret),32);
    bufp->chgBit(oldp+89,(vlSelf->inv_flag));
    bufp->chgIData(oldp+90,(vlSelf->ysyx_23060111_top__DOT__dnpc),32);
    bufp->chgIData(oldp+91,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgCData(oldp+92,((0x7fU & vlSelf->inst)),7);
    bufp->chgCData(oldp+93,((0x1fU & (vlSelf->inst 
                                      >> 7U))),5);
    bufp->chgCData(oldp+94,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->chgCData(oldp+95,((0x1fU & (vlSelf->inst 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+96,((0x1fU & (vlSelf->inst 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+97,((vlSelf->inst >> 0x19U)),7);
    bufp->chgIData(oldp+98,(vlSelf->ysyx_23060111_top__DOT__wdata),32);
    bufp->chgIData(oldp+99,(vlSelf->ysyx_23060111_top__DOT__rout),32);
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
