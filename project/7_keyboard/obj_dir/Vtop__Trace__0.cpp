// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__close),2);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__y_1),8);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__press_count),8);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__dout),8);
        bufp->chgSData(oldp+4,(vlSelf->top__DOT__i1__DOT__buffer),10);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__i1__DOT__fifo[0]),8);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__i1__DOT__fifo[1]),8);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__i1__DOT__fifo[2]),8);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__i1__DOT__fifo[3]),8);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__i1__DOT__fifo[4]),8);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__i1__DOT__fifo[5]),8);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__i1__DOT__fifo[6]),8);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__i1__DOT__fifo[7]),8);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__i1__DOT__w_ptr),3);
        bufp->chgCData(oldp+14,(vlSelf->top__DOT__i1__DOT__r_ptr),3);
        bufp->chgCData(oldp+15,(vlSelf->top__DOT__i1__DOT__count),4);
        bufp->chgCData(oldp+16,(vlSelf->top__DOT__i1__DOT__ps2_clk_sync),3);
        bufp->chgBit(oldp+17,(vlSelf->top__DOT__i1__DOT__nextdata_n));
        bufp->chgBit(oldp+18,(vlSelf->top__DOT__i1__DOT__ready));
        bufp->chgBit(oldp+19,((IData)((4U == (6U & (IData)(vlSelf->top__DOT__i1__DOT__ps2_clk_sync))))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+20,((0xffU & (~ (IData)(vlSelf->top__DOT__i2__DOT__y)))),8);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__i2__DOT__i),32);
        bufp->chgCData(oldp+22,(vlSelf->top__DOT__i2__DOT__y),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgCData(oldp+23,((0xffU & (~ (IData)(vlSelf->top__DOT__i3__DOT__y)))),8);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__i3__DOT__i),32);
        bufp->chgCData(oldp+25,(vlSelf->top__DOT__i3__DOT__y),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+26,((0xffU & (~ (IData)(vlSelf->top__DOT__i7__DOT__y)))),8);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__i7__DOT__i),32);
        bufp->chgCData(oldp+28,(vlSelf->top__DOT__i7__DOT__y),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgCData(oldp+29,((0xffU & (~ (IData)(vlSelf->top__DOT__i8__DOT__y)))),8);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__i8__DOT__i),32);
        bufp->chgCData(oldp+31,(vlSelf->top__DOT__i8__DOT__y),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgCData(oldp+32,(vlSelf->top__DOT__data_1),4);
        bufp->chgCData(oldp+33,(vlSelf->top__DOT__data_2),4);
        bufp->chgCData(oldp+34,(vlSelf->top__DOT__data_3),4);
        bufp->chgCData(oldp+35,(vlSelf->top__DOT__data_4),4);
        bufp->chgCData(oldp+36,(vlSelf->top__DOT__data_5),4);
        bufp->chgCData(oldp+37,(vlSelf->top__DOT__data_6),4);
    }
    bufp->chgBit(oldp+38,(vlSelf->clk));
    bufp->chgBit(oldp+39,(vlSelf->rst));
    bufp->chgBit(oldp+40,(vlSelf->ps2_clk));
    bufp->chgBit(oldp+41,(vlSelf->ps2_data));
    bufp->chgCData(oldp+42,(vlSelf->seg_1),8);
    bufp->chgCData(oldp+43,(vlSelf->seg_2),8);
    bufp->chgCData(oldp+44,(vlSelf->seg_3),8);
    bufp->chgCData(oldp+45,(vlSelf->seg_4),8);
    bufp->chgCData(oldp+46,(vlSelf->seg_5),8);
    bufp->chgCData(oldp+47,(vlSelf->seg_6),8);
    bufp->chgCData(oldp+48,(vlSelf->seg_7),8);
    bufp->chgCData(oldp+49,(vlSelf->seg_8),8);
    bufp->chgBit(oldp+50,(vlSelf->overflow));
    bufp->chgIData(oldp+51,(vlSelf->top__DOT__i4__DOT__i),32);
    bufp->chgCData(oldp+52,(vlSelf->top__DOT__i4__DOT__y),8);
    bufp->chgIData(oldp+53,(vlSelf->top__DOT__i5__DOT__i),32);
    bufp->chgCData(oldp+54,(vlSelf->top__DOT__i5__DOT__y),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
