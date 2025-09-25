// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMaxPeriodFibonacciLFSR_sram.h for the primary calling header

#include "VMaxPeriodFibonacciLFSR_sram__pch.h"
#include "VMaxPeriodFibonacciLFSR_sram__Syms.h"
#include "VMaxPeriodFibonacciLFSR_sram___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___eval_triggers__stl(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_triggers__stl\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
