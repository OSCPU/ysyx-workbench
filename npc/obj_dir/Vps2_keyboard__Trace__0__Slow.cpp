// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vps2_keyboard__Syms.h"


VL_ATTR_COLD void Vps2_keyboard___024root__trace_init_sub__TOP__0(Vps2_keyboard___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+7,"clk", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBus(c+9,"sw", false,-1, 13,0);
    tracep->declBit(c+10,"ps2_clk", false,-1);
    tracep->declBit(c+11,"ps2_data", false,-1);
    tracep->declBit(c+12,"BTNC", false,-1);
    tracep->declBit(c+13,"BTNU", false,-1);
    tracep->declBit(c+14,"BTND", false,-1);
    tracep->declBit(c+15,"BTNL", false,-1);
    tracep->declBit(c+16,"BTNR", false,-1);
    tracep->declBus(c+17,"ledr", false,-1, 15,0);
    tracep->declBit(c+18,"VGA_CLK", false,-1);
    tracep->declBit(c+19,"VGA_HSYNC", false,-1);
    tracep->declBit(c+20,"VGA_VSYNC", false,-1);
    tracep->declBit(c+21,"VGA_BLANK_N", false,-1);
    tracep->declBus(c+22,"VGA_R", false,-1, 7,0);
    tracep->declBus(c+23,"VGA_G", false,-1, 7,0);
    tracep->declBus(c+24,"VGA_B", false,-1, 7,0);
    tracep->declBus(c+25,"seg0", false,-1, 7,0);
    tracep->declBus(c+26,"seg1", false,-1, 7,0);
    tracep->declBus(c+27,"seg2", false,-1, 7,0);
    tracep->declBus(c+28,"seg3", false,-1, 7,0);
    tracep->declBus(c+29,"seg4", false,-1, 7,0);
    tracep->declBus(c+30,"seg5", false,-1, 7,0);
    tracep->declBus(c+31,"seg6", false,-1, 7,0);
    tracep->declBus(c+32,"seg7", false,-1, 7,0);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+7,"clk", false,-1);
    tracep->declBit(c+8,"rst", false,-1);
    tracep->declBus(c+9,"sw", false,-1, 13,0);
    tracep->declBit(c+10,"ps2_clk", false,-1);
    tracep->declBit(c+11,"ps2_data", false,-1);
    tracep->declBit(c+12,"BTNC", false,-1);
    tracep->declBit(c+13,"BTNU", false,-1);
    tracep->declBit(c+14,"BTND", false,-1);
    tracep->declBit(c+15,"BTNL", false,-1);
    tracep->declBit(c+16,"BTNR", false,-1);
    tracep->declBus(c+17,"ledr", false,-1, 15,0);
    tracep->declBit(c+18,"VGA_CLK", false,-1);
    tracep->declBit(c+19,"VGA_HSYNC", false,-1);
    tracep->declBit(c+20,"VGA_VSYNC", false,-1);
    tracep->declBit(c+21,"VGA_BLANK_N", false,-1);
    tracep->declBus(c+22,"VGA_R", false,-1, 7,0);
    tracep->declBus(c+23,"VGA_G", false,-1, 7,0);
    tracep->declBus(c+24,"VGA_B", false,-1, 7,0);
    tracep->declBus(c+25,"seg0", false,-1, 7,0);
    tracep->declBus(c+26,"seg1", false,-1, 7,0);
    tracep->declBus(c+27,"seg2", false,-1, 7,0);
    tracep->declBus(c+28,"seg3", false,-1, 7,0);
    tracep->declBus(c+29,"seg4", false,-1, 7,0);
    tracep->declBus(c+30,"seg5", false,-1, 7,0);
    tracep->declBus(c+31,"seg6", false,-1, 7,0);
    tracep->declBus(c+32,"seg7", false,-1, 7,0);
    tracep->pushNamePrefix("my_keyboard ");
    tracep->declBit(c+7,"clk", false,-1);
    tracep->declBit(c+33,"resetn", false,-1);
    tracep->declBit(c+10,"ps2_clk", false,-1);
    tracep->declBit(c+11,"ps2_data", false,-1);
    tracep->declBus(c+32,"seg7", false,-1, 7,0);
    tracep->declBus(c+31,"seg6", false,-1, 7,0);
    tracep->declBus(c+29,"seg4", false,-1, 7,0);
    tracep->declBus(c+28,"seg3", false,-1, 7,0);
    tracep->declBus(c+26,"seg1", false,-1, 7,0);
    tracep->declBus(c+25,"seg0", false,-1, 7,0);
    tracep->declBus(c+1,"buffer", false,-1, 9,0);
    tracep->declBus(c+2,"count", false,-1, 3,0);
    tracep->declBus(c+3,"ps2_clk_sync", false,-1, 2,0);
    tracep->declBus(c+4,"c", false,-1, 3,0);
    tracep->declBus(c+5,"b", false,-1, 8,1);
    tracep->declBit(c+6,"sampling", false,-1);
    tracep->pushNamePrefix("a1 ");
    tracep->declBus(c+5,"buffer", false,-1, 8,1);
    tracep->declBus(c+29,"seg4", false,-1, 7,0);
    tracep->declBus(c+28,"seg3", false,-1, 7,0);
    tracep->declBus(c+26,"seg1", false,-1, 7,0);
    tracep->declBus(c+25,"seg0", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("co1 ");
    tracep->declBus(c+4,"ct", false,-1, 3,0);
    tracep->declBus(c+32,"seg7", false,-1, 7,0);
    tracep->declBus(c+31,"seg6", false,-1, 7,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vps2_keyboard___024root__trace_init_top(Vps2_keyboard___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_init_top\n"); );
    // Body
    Vps2_keyboard___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vps2_keyboard___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vps2_keyboard___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vps2_keyboard___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vps2_keyboard___024root__trace_register(Vps2_keyboard___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vps2_keyboard___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vps2_keyboard___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vps2_keyboard___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vps2_keyboard___024root__trace_full_sub_0(Vps2_keyboard___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vps2_keyboard___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_full_top_0\n"); );
    // Init
    Vps2_keyboard___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2_keyboard___024root*>(voidSelf);
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vps2_keyboard___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vps2_keyboard___024root__trace_full_sub_0(Vps2_keyboard___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+1,(vlSelf->top__DOT__my_keyboard__DOT__buffer),10);
    bufp->fullCData(oldp+2,(vlSelf->top__DOT__my_keyboard__DOT__count),4);
    bufp->fullCData(oldp+3,(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync),3);
    bufp->fullCData(oldp+4,(vlSelf->top__DOT__my_keyboard__DOT__c),4);
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__my_keyboard__DOT__b),8);
    bufp->fullBit(oldp+6,((IData)((4U == (6U & (IData)(vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync))))));
    bufp->fullBit(oldp+7,(vlSelf->clk));
    bufp->fullBit(oldp+8,(vlSelf->rst));
    bufp->fullSData(oldp+9,(vlSelf->sw),14);
    bufp->fullBit(oldp+10,(vlSelf->ps2_clk));
    bufp->fullBit(oldp+11,(vlSelf->ps2_data));
    bufp->fullBit(oldp+12,(vlSelf->BTNC));
    bufp->fullBit(oldp+13,(vlSelf->BTNU));
    bufp->fullBit(oldp+14,(vlSelf->BTND));
    bufp->fullBit(oldp+15,(vlSelf->BTNL));
    bufp->fullBit(oldp+16,(vlSelf->BTNR));
    bufp->fullSData(oldp+17,(vlSelf->ledr),16);
    bufp->fullBit(oldp+18,(vlSelf->VGA_CLK));
    bufp->fullBit(oldp+19,(vlSelf->VGA_HSYNC));
    bufp->fullBit(oldp+20,(vlSelf->VGA_VSYNC));
    bufp->fullBit(oldp+21,(vlSelf->VGA_BLANK_N));
    bufp->fullCData(oldp+22,(vlSelf->VGA_R),8);
    bufp->fullCData(oldp+23,(vlSelf->VGA_G),8);
    bufp->fullCData(oldp+24,(vlSelf->VGA_B),8);
    bufp->fullCData(oldp+25,(vlSelf->seg0),8);
    bufp->fullCData(oldp+26,(vlSelf->seg1),8);
    bufp->fullCData(oldp+27,(vlSelf->seg2),8);
    bufp->fullCData(oldp+28,(vlSelf->seg3),8);
    bufp->fullCData(oldp+29,(vlSelf->seg4),8);
    bufp->fullCData(oldp+30,(vlSelf->seg5),8);
    bufp->fullCData(oldp+31,(vlSelf->seg6),8);
    bufp->fullCData(oldp+32,(vlSelf->seg7),8);
    bufp->fullBit(oldp+33,((1U & (~ (IData)(vlSelf->rst)))));
}
