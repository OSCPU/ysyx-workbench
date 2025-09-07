// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_25020077_top.h for the primary calling header

#include "Vysyx_25020077_top__pch.h"
#include "Vysyx_25020077_top__Syms.h"
#include "Vysyx_25020077_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_25020077_top___024root___dump_triggers__act(Vysyx_25020077_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vysyx_25020077_top___024root___eval_triggers__act(Vysyx_25020077_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25020077_top___024root___eval_triggers__act\n"); );
    Vysyx_25020077_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_25020077_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
