// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->ysyx_25020077_top__DOT__i0__DOT__state),32);
        bufp->chgIData(oldp+1,(vlSelf->ysyx_25020077_top__DOT__instruction_out),32);
        bufp->chgCData(oldp+2,(((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                                 ? 1U : 0U)),3);
        bufp->chgCData(oldp+3,(vlSelf->ysyx_25020077_top__DOT__rs1),5);
        bufp->chgIData(oldp+4,((IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)),32);
        bufp->chgSData(oldp+5,(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type),10);
        bufp->chgCData(oldp+6,((0x1fU & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+7,((0x1fU & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                         >> 7U))),5);
        bufp->chgBit(oldp+8,((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))));
        bufp->chgIData(oldp+9,(((((vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                   >> 0x1fU) ? 0xfffffU
                                   : 0U) << 0xcU) | 
                                (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                 >> 0x14U))),32);
        bufp->chgBit(oldp+10,((1U == ((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                                       ? 1U : 0U))));
        bufp->chgIData(oldp+11,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0),32);
        bufp->chgIData(oldp+12,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_1),32);
        bufp->chgIData(oldp+13,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_2),32);
        bufp->chgIData(oldp+14,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_3),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_4),32);
        bufp->chgIData(oldp+16,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_5),32);
        bufp->chgIData(oldp+17,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_6),32);
        bufp->chgIData(oldp+18,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_7),32);
        bufp->chgIData(oldp+19,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_8),32);
        bufp->chgIData(oldp+20,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_9),32);
        bufp->chgIData(oldp+21,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_10),32);
        bufp->chgIData(oldp+22,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_11),32);
        bufp->chgIData(oldp+23,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_12),32);
        bufp->chgIData(oldp+24,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_13),32);
        bufp->chgIData(oldp+25,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_14),32);
        bufp->chgIData(oldp+26,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_15),32);
        bufp->chgIData(oldp+27,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_16),32);
        bufp->chgIData(oldp+28,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_17),32);
        bufp->chgIData(oldp+29,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_18),32);
        bufp->chgIData(oldp+30,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_19),32);
        bufp->chgIData(oldp+31,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_20),32);
        bufp->chgIData(oldp+32,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_21),32);
        bufp->chgIData(oldp+33,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_22),32);
        bufp->chgIData(oldp+34,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_23),32);
        bufp->chgIData(oldp+35,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_24),32);
        bufp->chgIData(oldp+36,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_25),32);
        bufp->chgIData(oldp+37,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_26),32);
        bufp->chgIData(oldp+38,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_27),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_28),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_29),32);
        bufp->chgIData(oldp+41,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_30),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_31),32);
        bufp->chgQData(oldp+43,(vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult),33);
        bufp->chgQData(oldp+45,(vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult),33);
    }
    bufp->chgBit(oldp+47,(vlSelf->clock));
    bufp->chgBit(oldp+48,(vlSelf->reset));
    bufp->chgIData(oldp+49,(vlSelf->imm),32);
    bufp->chgCData(oldp+50,(vlSelf->rd),5);
    bufp->chgCData(oldp+51,(vlSelf->ALU_ctrl),3);
    bufp->chgIData(oldp+52,(vlSelf->rs1_out),32);
    bufp->chgIData(oldp+53,(vlSelf->rs2_out),32);
    bufp->chgBit(oldp+54,(vlSelf->ALU_carry));
    bufp->chgBit(oldp+55,(vlSelf->ALU_overflow));
    bufp->chgBit(oldp+56,(vlSelf->is_break_out));
    bufp->chgBit(oldp+57,((0U == (IData)(vlSelf->rd))));
    bufp->chgCData(oldp+58,((0xffU & ((IData)(1U) << (IData)(vlSelf->ALU_ctrl)))),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
