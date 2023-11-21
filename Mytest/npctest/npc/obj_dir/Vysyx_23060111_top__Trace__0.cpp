// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060111_top__Syms.h"


void Vysyx_23060111_top___024root__trace_chg_sub_0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_23060111_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_23060111_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060111_top___024root*>(voidSelf);
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_23060111_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_23060111_top___024root__trace_chg_sub_0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->rst));
    bufp->chgBit(oldp+1,(vlSelf->clk));
    bufp->chgIData(oldp+2,(vlSelf->inst),32);
    bufp->chgIData(oldp+3,(vlSelf->val),32);
    bufp->chgIData(oldp+4,(vlSelf->snpc),32);
    bufp->chgIData(oldp+5,(vlSelf->dnpc),32);
    bufp->chgIData(oldp+6,(vlSelf->pc),32);
    bufp->chgSData(oldp+7,(vlSelf->imm),12);
    bufp->chgCData(oldp+8,(vlSelf->rs1),5);
    bufp->chgCData(oldp+9,(vlSelf->funct3),3);
    bufp->chgCData(oldp+10,(vlSelf->rd),5);
    bufp->chgCData(oldp+11,(vlSelf->opcode),7);
    bufp->chgIData(oldp+12,(vlSelf->out),32);
    bufp->chgIData(oldp+13,(vlSelf->reg_out),32);
    bufp->chgIData(oldp+14,(vlSelf->reg_out1),32);
    bufp->chgIData(oldp+15,(vlSelf->rbb),20);
    bufp->chgIData(oldp+16,((vlSelf->inst >> 0x14U)),32);
    bufp->chgIData(oldp+17,((vlSelf->reg_out + (vlSelf->inst 
                                                >> 0x14U))),32);
    bufp->chgBit(oldp+18,((1U & (vlSelf->inst >> 7U))));
    bufp->chgIData(oldp+19,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__reg_rd__DOT__rf[0]),32);
    bufp->chgBit(oldp+20,((1U & (vlSelf->inst >> 0xfU))));
    bufp->chgIData(oldp+21,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
}

void Vysyx_23060111_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_23060111_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060111_top___024root*>(voidSelf);
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
