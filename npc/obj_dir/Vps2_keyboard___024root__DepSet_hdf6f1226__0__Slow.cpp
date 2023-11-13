// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2_keyboard.h for the primary calling header

#include "verilated.h"

#include "Vps2_keyboard___024root.h"

VL_ATTR_COLD void Vps2_keyboard___024root___eval_static(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vps2_keyboard___024root___eval_initial(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vps2_keyboard___024root___eval_final(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vps2_keyboard___024root___eval_triggers__stl(Vps2_keyboard___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___dump_triggers__stl(Vps2_keyboard___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___eval_stl(Vps2_keyboard___024root* vlSelf);

VL_ATTR_COLD void Vps2_keyboard___024root___eval_settle(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vps2_keyboard___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vps2_keyboard___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vps2_keyboard___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___dump_triggers__stl(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*7:0*/, 16> Vps2_keyboard__ConstPool__TABLE_hc4fbb95d_0;
extern const VlUnpacked<CData/*7:0*/, 16> Vps2_keyboard__ConstPool__TABLE_h40bdb436_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_h2f6b22a7_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_h34e4bf12_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_hdbab5b42_0;
extern const VlUnpacked<CData/*7:0*/, 256> Vps2_keyboard__ConstPool__TABLE_h30414c85_0;

VL_ATTR_COLD void Vps2_keyboard___024root___stl_sequent__TOP__0(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx1 = vlSelf->top__DOT__my_keyboard__DOT__c;
    vlSelf->seg7 = Vps2_keyboard__ConstPool__TABLE_hc4fbb95d_0
        [__Vtableidx1];
    vlSelf->seg6 = Vps2_keyboard__ConstPool__TABLE_h40bdb436_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelf->top__DOT__my_keyboard__DOT__b;
    vlSelf->seg4 = Vps2_keyboard__ConstPool__TABLE_h2f6b22a7_0
        [__Vtableidx2];
    vlSelf->seg3 = Vps2_keyboard__ConstPool__TABLE_h34e4bf12_0
        [__Vtableidx2];
    vlSelf->seg1 = Vps2_keyboard__ConstPool__TABLE_hdbab5b42_0
        [__Vtableidx2];
    vlSelf->seg0 = Vps2_keyboard__ConstPool__TABLE_h30414c85_0
        [__Vtableidx2];
}

VL_ATTR_COLD void Vps2_keyboard___024root___eval_stl(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vps2_keyboard___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___dump_triggers__act(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_keyboard___024root___dump_triggers__nba(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vps2_keyboard___024root___ctor_var_reset(Vps2_keyboard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_keyboard___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->sw = VL_RAND_RESET_I(14);
    vlSelf->ps2_clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_data = VL_RAND_RESET_I(1);
    vlSelf->BTNC = VL_RAND_RESET_I(1);
    vlSelf->BTNU = VL_RAND_RESET_I(1);
    vlSelf->BTND = VL_RAND_RESET_I(1);
    vlSelf->BTNL = VL_RAND_RESET_I(1);
    vlSelf->BTNR = VL_RAND_RESET_I(1);
    vlSelf->ledr = VL_RAND_RESET_I(16);
    vlSelf->VGA_CLK = VL_RAND_RESET_I(1);
    vlSelf->VGA_HSYNC = VL_RAND_RESET_I(1);
    vlSelf->VGA_VSYNC = VL_RAND_RESET_I(1);
    vlSelf->VGA_BLANK_N = VL_RAND_RESET_I(1);
    vlSelf->VGA_R = VL_RAND_RESET_I(8);
    vlSelf->VGA_G = VL_RAND_RESET_I(8);
    vlSelf->VGA_B = VL_RAND_RESET_I(8);
    vlSelf->seg0 = VL_RAND_RESET_I(8);
    vlSelf->seg1 = VL_RAND_RESET_I(8);
    vlSelf->seg2 = VL_RAND_RESET_I(8);
    vlSelf->seg3 = VL_RAND_RESET_I(8);
    vlSelf->seg4 = VL_RAND_RESET_I(8);
    vlSelf->seg5 = VL_RAND_RESET_I(8);
    vlSelf->seg6 = VL_RAND_RESET_I(8);
    vlSelf->seg7 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__my_keyboard__DOT__buffer = VL_RAND_RESET_I(10);
    vlSelf->top__DOT__my_keyboard__DOT__count = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__my_keyboard__DOT__c = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__my_keyboard__DOT__b = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__my_keyboard__DOT____Vlvbound_h1a91ade8__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
