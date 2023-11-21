// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060111_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060111_top__Syms.h"
#include "Vysyx_23060111_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060111_top___024root___dump_triggers__stl(Vysyx_23060111_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060111_top___024root___eval_triggers__stl(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_23060111_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vysyx_23060111_top___024unit____Vdpiimwrap_add_TOP____024unit(IData/*31:0*/ inst);

VL_ATTR_COLD void Vysyx_23060111_top___024root___stl_sequent__TOP__0(Vysyx_23060111_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    Vysyx_23060111_top___024unit____Vdpiimwrap_add_TOP____024unit(vlSelf->inst);
    vlSelf->val = vlSelf->inst;
    vlSelf->imm = (vlSelf->inst >> 0x14U);
    vlSelf->rs1 = (0x1fU & (vlSelf->inst >> 0xfU));
    vlSelf->funct3 = (7U & (vlSelf->inst >> 0xcU));
    vlSelf->out = vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
        [0U];
    vlSelf->reg_out = ((0U >= (1U & (vlSelf->inst >> 0xfU)))
                        ? vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__reg_src1__DOT__rf
                       [(1U & (vlSelf->inst >> 0xfU))]
                        : 0U);
    vlSelf->reg_out1 = ((0U >= (1U & (vlSelf->inst 
                                      >> 7U))) ? vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__reg_rd__DOT__rf
                        [(1U & (vlSelf->inst >> 7U))]
                         : 0U);
    vlSelf->snpc = ((IData)(4U) + vlSelf->pc);
    vlSelf->rd = (0x1fU & (vlSelf->inst >> 7U));
    vlSelf->opcode = (0x7fU & vlSelf->inst);
    vlSelf->dnpc = vlSelf->snpc;
    vlSelf->rbb = (((IData)(vlSelf->rd) << 0xfU) | 
                   ((0x7f80U & (vlSelf->inst >> 5U)) 
                    | (IData)(vlSelf->opcode)));
}
