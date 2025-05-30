// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

extern "C" svBitVecVal addr_read(const svBitVecVal* pc);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i1__DOT__addr_read_TOP\n"); );
    // Body
    svBitVecVal pc__Vcvt[1];
    for (size_t pc__Vidx = 0; pc__Vidx < 1; ++pc__Vidx) VL_SET_SVBV_I(32, pc__Vcvt + 1 * pc__Vidx, pc);
    svBitVecVal addr_read__Vfuncrtn__Vcvt[1];
    addr_read__Vfuncrtn__Vcvt[0] = addr_read(pc__Vcvt);
    addr_read__Vfuncrtn = VL_SET_I_SVBV(addr_read__Vfuncrtn__Vcvt);
}

extern "C" svBit is_break(const svBitVecVal* instruction_in);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_ysyx_25020077_top__DOT__i2__DOT__is_break_TOP\n"); );
    // Body
    svBitVecVal instruction_in__Vcvt[1];
    for (size_t instruction_in__Vidx = 0; instruction_in__Vidx < 1; ++instruction_in__Vidx) VL_SET_SVBV_I(32, instruction_in__Vcvt + 1 * instruction_in__Vidx, instruction_in);
    svBit is_break__Vfuncrtn__Vcvt;
    is_break__Vfuncrtn__Vcvt = is_break(instruction_in__Vcvt);
    is_break__Vfuncrtn = (1U & is_break__Vfuncrtn__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clock) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clock)));
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}
