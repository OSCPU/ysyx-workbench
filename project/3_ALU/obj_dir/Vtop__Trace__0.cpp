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
    bufp->chgCData(oldp+0,(vlSelf->x),4);
    bufp->chgCData(oldp+1,(vlSelf->y),4);
    bufp->chgCData(oldp+2,(vlSelf->sw),3);
    bufp->chgCData(oldp+3,(vlSelf->result),4);
    bufp->chgBit(oldp+4,(vlSelf->Carry));
    bufp->chgBit(oldp+5,(vlSelf->Overflow));
    bufp->chgBit(oldp+6,(vlSelf->Zero));
    bufp->chgCData(oldp+7,(vlSelf->smg_1),8);
    bufp->chgCData(oldp+8,(vlSelf->smg_2),8);
    bufp->chgCData(oldp+9,(vlSelf->smg_3),8);
    bufp->chgCData(oldp+10,(vlSelf->smg_4),8);
    bufp->chgCData(oldp+11,(vlSelf->smg_5),8);
    bufp->chgCData(oldp+12,(vlSelf->smg_6),8);
    bufp->chgCData(oldp+13,(vlSelf->smg_7),8);
    bufp->chgCData(oldp+14,(vlSelf->smg_8),8);
    bufp->chgCData(oldp+15,((0xffU & ((IData)(1U) << (IData)(vlSelf->sw)))),8);
    bufp->chgCData(oldp+16,(vlSelf->top__DOT__i3__DOT__addResult),5);
    bufp->chgCData(oldp+17,(vlSelf->top__DOT__i3__DOT__subResult),5);
    bufp->chgIData(oldp+18,(vlSelf->top__DOT__i4__DOT__i),32);
    bufp->chgCData(oldp+19,(vlSelf->top__DOT__i4__DOT__y),8);
    bufp->chgIData(oldp+20,(vlSelf->top__DOT__i5__DOT__i),32);
    bufp->chgCData(oldp+21,(vlSelf->top__DOT__i5__DOT__y),8);
    bufp->chgIData(oldp+22,(vlSelf->top__DOT__i6__DOT__i),32);
    bufp->chgCData(oldp+23,(vlSelf->top__DOT__i6__DOT__y),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
