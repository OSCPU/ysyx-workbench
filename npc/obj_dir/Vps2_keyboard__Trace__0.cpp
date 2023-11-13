// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vps2_keyboard__Syms.h"


void Vps2_keyboard___024root__trace_chg_sub_0(Vps2_keyboard___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vps2_keyboard___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_chg_top_0\n"); );
    // Init
    Vps2_keyboard___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2_keyboard___024root*>(voidSelf);
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vps2_keyboard___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vps2_keyboard___024root__trace_chg_sub_0(Vps2_keyboard___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
        bufp->chgCData(oldp+1,(vlSelf->top__DOT__my_keyboard__DOT__count),4);
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
        bufp->chgCData(oldp+3,(vlSelf->top__DOT__my_keyboard__DOT__c),4);
        bufp->chgCData(oldp+4,(vlSelf->top__DOT__my_keyboard__DOT__b),8);
        bufp->chgBit(oldp+5,((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))));
    }
    bufp->chgBit(oldp+6,(vlSelf->clk));
    bufp->chgBit(oldp+7,(vlSelf->rst));
    bufp->chgSData(oldp+8,(vlSelf->sw),14);
    bufp->chgBit(oldp+9,(vlSelf->ps2_clk));
    bufp->chgBit(oldp+10,(vlSelf->ps2_data));
    bufp->chgBit(oldp+11,(vlSelf->BTNC));
    bufp->chgBit(oldp+12,(vlSelf->BTNU));
    bufp->chgBit(oldp+13,(vlSelf->BTND));
    bufp->chgBit(oldp+14,(vlSelf->BTNL));
    bufp->chgBit(oldp+15,(vlSelf->BTNR));
    bufp->chgSData(oldp+16,(vlSelf->ledr),16);
    bufp->chgBit(oldp+17,(vlSelf->VGA_CLK));
    bufp->chgBit(oldp+18,(vlSelf->VGA_HSYNC));
    bufp->chgBit(oldp+19,(vlSelf->VGA_VSYNC));
    bufp->chgBit(oldp+20,(vlSelf->VGA_BLANK_N));
    bufp->chgCData(oldp+21,(vlSelf->VGA_R),8);
    bufp->chgCData(oldp+22,(vlSelf->VGA_G),8);
    bufp->chgCData(oldp+23,(vlSelf->VGA_B),8);
    bufp->chgCData(oldp+24,(vlSelf->seg0),8);
    bufp->chgCData(oldp+25,(vlSelf->seg1),8);
    bufp->chgCData(oldp+26,(vlSelf->seg2),8);
    bufp->chgCData(oldp+27,(vlSelf->seg3),8);
    bufp->chgCData(oldp+28,(vlSelf->seg4),8);
    bufp->chgCData(oldp+29,(vlSelf->seg5),8);
    bufp->chgCData(oldp+30,(vlSelf->seg6),8);
    bufp->chgCData(oldp+31,(vlSelf->seg7),8);
    bufp->chgBit(oldp+32,((1U & (~ (IData)(vlSelf->rst)))));
}

void Vps2_keyboard___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_cleanup\n"); );
    // Init
    Vps2_keyboard___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2_keyboard___024root*>(voidSelf);
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
