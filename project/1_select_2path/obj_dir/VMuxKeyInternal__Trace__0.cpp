// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VMuxKeyInternal__Syms.h"


void VMuxKeyInternal___024root__trace_chg_sub_0(VMuxKeyInternal___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VMuxKeyInternal___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKeyInternal___024root__trace_chg_top_0\n"); );
    // Init
    VMuxKeyInternal___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMuxKeyInternal___024root*>(voidSelf);
    VMuxKeyInternal__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VMuxKeyInternal___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VMuxKeyInternal___024root__trace_chg_sub_0(VMuxKeyInternal___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VMuxKeyInternal__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKeyInternal___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__i0__DOT__i0__DOT__key_list[0]),2);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__i0__DOT__i0__DOT__key_list[1]),2);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__i0__DOT__i0__DOT__key_list[2]),2);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__i0__DOT__i0__DOT__key_list[3]),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__i0__DOT__i0__DOT__pair_list[0]),4);
        bufp->chgCData(oldp+5,(vlSelf->top__DOT__i0__DOT__i0__DOT__pair_list[1]),4);
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__i0__DOT__i0__DOT__pair_list[2]),4);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__i0__DOT__i0__DOT__pair_list[3]),4);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__i0__DOT__i0__DOT__data_list[0]),2);
        bufp->chgCData(oldp+9,(vlSelf->top__DOT__i0__DOT__i0__DOT__data_list[1]),2);
        bufp->chgCData(oldp+10,(vlSelf->top__DOT__i0__DOT__i0__DOT__data_list[2]),2);
        bufp->chgCData(oldp+11,(vlSelf->top__DOT__i0__DOT__i0__DOT__data_list[3]),2);
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__i0__DOT__i0__DOT__lut_out),2);
        bufp->chgBit(oldp+13,(vlSelf->top__DOT__i0__DOT__i0__DOT__hit));
    }
    bufp->chgCData(oldp+14,(vlSelf->a),8);
    bufp->chgCData(oldp+15,(vlSelf->s),2);
    bufp->chgCData(oldp+16,(vlSelf->y),2);
    bufp->chgSData(oldp+17,((0x48cU | ((0x3000U & ((IData)(vlSelf->a) 
                                                   << 6U)) 
                                       | ((0x300U & 
                                           ((IData)(vlSelf->a) 
                                            << 4U)) 
                                          | ((0x30U 
                                              & ((IData)(vlSelf->a) 
                                                 << 2U)) 
                                             | (3U 
                                                & (IData)(vlSelf->a))))))),16);
}

void VMuxKeyInternal___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMuxKeyInternal___024root__trace_cleanup\n"); );
    // Init
    VMuxKeyInternal___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMuxKeyInternal___024root*>(voidSelf);
    VMuxKeyInternal__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
