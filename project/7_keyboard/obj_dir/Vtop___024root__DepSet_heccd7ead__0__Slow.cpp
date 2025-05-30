// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_1 = vlSelf->top__DOT__data_1;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_2 = vlSelf->top__DOT__data_2;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_3 = vlSelf->top__DOT__data_3;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_4 = vlSelf->top__DOT__data_4;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_5 = vlSelf->top__DOT__data_5;
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_6 = vlSelf->top__DOT__data_6;
}

extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_h1b42e5d9_0;

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->seg_7 = 0xffU;
    vlSelf->seg_8 = 0xffU;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(16, Vtop__ConstPool__CONST_h1b42e5d9_0)
                 ,  &(vlSelf->top__DOT__i6__DOT__rom)
                 , 0U, 0xffU);
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 114, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->seg_3 = (0xffU & (~ (IData)(vlSelf->top__DOT__i4__DOT__y)));
    vlSelf->seg_4 = (0xffU & (~ (IData)(vlSelf->top__DOT__i5__DOT__y)));
    vlSelf->top__DOT__data_3 = (0xfU & ((IData)(vlSelf->top__DOT__press_count) 
                                        >> 4U));
    vlSelf->top__DOT__data_4 = (0xfU & (IData)(vlSelf->top__DOT__press_count));
    if (vlSelf->rst) {
        if ((2U & (IData)(vlSelf->top__DOT__close))) {
            vlSelf->seg_1 = 0xffU;
            vlSelf->seg_2 = 0xffU;
            vlSelf->seg_5 = 0xffU;
            vlSelf->seg_6 = 0xffU;
        } else {
            vlSelf->seg_1 = (0xffU & (~ (IData)(vlSelf->top__DOT__i2__DOT__y)));
            vlSelf->seg_2 = (0xffU & (~ (IData)(vlSelf->top__DOT__i3__DOT__y)));
            vlSelf->seg_5 = (0xffU & (~ (IData)(vlSelf->top__DOT__i7__DOT__y)));
            vlSelf->seg_6 = (0xffU & (~ (IData)(vlSelf->top__DOT__i8__DOT__y)));
        }
    } else {
        vlSelf->seg_1 = 0xffU;
        vlSelf->seg_2 = 0xffU;
        vlSelf->seg_5 = 0xffU;
        vlSelf->seg_6 = 0xffU;
    }
    vlSelf->top__DOT__y_1 = vlSelf->top__DOT__i1__DOT__fifo
        [vlSelf->top__DOT__i1__DOT__r_ptr];
    vlSelf->top__DOT__data_1 = (0xfU & ((IData)(vlSelf->top__DOT__y_1) 
                                        >> 4U));
    vlSelf->top__DOT__data_2 = (0xfU & (IData)(vlSelf->top__DOT__y_1));
    vlSelf->top__DOT__dout = vlSelf->top__DOT__i6__DOT__rom
        [vlSelf->top__DOT__y_1];
    vlSelf->top__DOT__data_5 = (0xfU & ((IData)(vlSelf->top__DOT__dout) 
                                        >> 4U));
    vlSelf->top__DOT__data_6 = (0xfU & (IData)(vlSelf->top__DOT__dout));
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[6U] = 1U;
        vlSelf->__Vm_traceActivity[5U] = 1U;
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([changed] top.data_1)\n");
    }
    if (vlSelf->__VactTriggered.at(2U)) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([changed] top.data_2)\n");
    }
    if (vlSelf->__VactTriggered.at(3U)) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([changed] top.data_3)\n");
    }
    if (vlSelf->__VactTriggered.at(4U)) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([changed] top.data_4)\n");
    }
    if (vlSelf->__VactTriggered.at(5U)) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @([changed] top.data_5)\n");
    }
    if (vlSelf->__VactTriggered.at(6U)) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @([changed] top.data_6)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([changed] top.data_1)\n");
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([changed] top.data_2)\n");
    }
    if (vlSelf->__VnbaTriggered.at(3U)) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([changed] top.data_3)\n");
    }
    if (vlSelf->__VnbaTriggered.at(4U)) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([changed] top.data_4)\n");
    }
    if (vlSelf->__VnbaTriggered.at(5U)) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @([changed] top.data_5)\n");
    }
    if (vlSelf->__VnbaTriggered.at(6U)) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @([changed] top.data_6)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ps2_clk = VL_RAND_RESET_I(1);
    vlSelf->ps2_data = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->seg_1 = VL_RAND_RESET_I(8);
    vlSelf->seg_2 = VL_RAND_RESET_I(8);
    vlSelf->seg_3 = VL_RAND_RESET_I(8);
    vlSelf->seg_4 = VL_RAND_RESET_I(8);
    vlSelf->seg_5 = VL_RAND_RESET_I(8);
    vlSelf->seg_6 = VL_RAND_RESET_I(8);
    vlSelf->seg_7 = VL_RAND_RESET_I(8);
    vlSelf->seg_8 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__close = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__y_1 = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__press_count = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__data_1 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__data_2 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__data_3 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__data_4 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__data_5 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__data_6 = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__dout = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i1__DOT__buffer = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top__DOT__i1__DOT__fifo[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__i1__DOT__w_ptr = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__i1__DOT__r_ptr = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__i1__DOT__count = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__i1__DOT__ps2_clk_sync = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__i1__DOT__nextdata_n = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i1__DOT__ready = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i1__DOT____Vlvbound_h1a91ade8__0 = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__i2__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i2__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i3__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i3__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i4__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i4__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i5__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i5__DOT__y = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->top__DOT__i6__DOT__rom[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top__DOT__i7__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i7__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__i8__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__i8__DOT__y = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_1 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_2 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_3 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_4 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_5 = VL_RAND_RESET_I(4);
    vlSelf->__Vtrigrprev__TOP__top__DOT__data_6 = VL_RAND_RESET_I(4);
    vlSelf->__VactDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 7; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
