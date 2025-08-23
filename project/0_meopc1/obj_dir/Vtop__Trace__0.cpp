// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.ysyx_25020077_top__DOT__i0__DOT__state),32);
        bufp->chgIData(oldp+1,(vlSelfRef.ysyx_25020077_top__DOT__instruction_out),32);
        bufp->chgCData(oldp+2,(((0x13U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                                 ? 1U : 0U)),3);
        bufp->chgCData(oldp+3,(vlSelfRef.ysyx_25020077_top__DOT__rs1),5);
        bufp->chgIData(oldp+4,((IData)(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)),32);
        bufp->chgSData(oldp+5,(vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type),10);
        bufp->chgCData(oldp+6,((0x1fU & (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+7,((0x1fU & (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                         >> 7U))),5);
        bufp->chgBit(oldp+8,((0x13U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type))));
        bufp->chgIData(oldp+9,(((((vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                   >> 0x1fU) ? 0xfffffU
                                   : 0U) << 0xcU) | 
                                (vlSelfRef.ysyx_25020077_top__DOT__instruction_out 
                                 >> 0x14U))),32);
        bufp->chgBit(oldp+10,((1U == ((0x13U == (IData)(vlSelfRef.ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                                       ? 1U : 0U))));
        bufp->chgIData(oldp+11,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_0),32);
        bufp->chgIData(oldp+12,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_1),32);
        bufp->chgIData(oldp+13,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_2),32);
        bufp->chgIData(oldp+14,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_3),32);
        bufp->chgIData(oldp+15,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_4),32);
        bufp->chgIData(oldp+16,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_5),32);
        bufp->chgIData(oldp+17,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_6),32);
        bufp->chgIData(oldp+18,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_7),32);
        bufp->chgIData(oldp+19,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_8),32);
        bufp->chgIData(oldp+20,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_9),32);
        bufp->chgIData(oldp+21,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_10),32);
        bufp->chgIData(oldp+22,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_11),32);
        bufp->chgIData(oldp+23,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_12),32);
        bufp->chgIData(oldp+24,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_13),32);
        bufp->chgIData(oldp+25,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_14),32);
        bufp->chgIData(oldp+26,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_15),32);
        bufp->chgIData(oldp+27,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_16),32);
        bufp->chgIData(oldp+28,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_17),32);
        bufp->chgIData(oldp+29,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_18),32);
        bufp->chgIData(oldp+30,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_19),32);
        bufp->chgIData(oldp+31,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_20),32);
        bufp->chgIData(oldp+32,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_21),32);
        bufp->chgIData(oldp+33,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_22),32);
        bufp->chgIData(oldp+34,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_23),32);
        bufp->chgIData(oldp+35,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_24),32);
        bufp->chgIData(oldp+36,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_25),32);
        bufp->chgIData(oldp+37,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_26),32);
        bufp->chgIData(oldp+38,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_27),32);
        bufp->chgIData(oldp+39,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_28),32);
        bufp->chgIData(oldp+40,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_29),32);
        bufp->chgIData(oldp+41,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_30),32);
        bufp->chgIData(oldp+42,(vlSelfRef.ysyx_25020077_top__DOT__i4__DOT__regs_31),32);
        bufp->chgQData(oldp+43,(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__addResult),33);
        bufp->chgQData(oldp+45,(vlSelfRef.ysyx_25020077_top__DOT__i5__DOT__subResult),33);
    }
    bufp->chgBit(oldp+47,(vlSelfRef.clock));
    bufp->chgBit(oldp+48,(vlSelfRef.reset));
    bufp->chgIData(oldp+49,(vlSelfRef.imm),32);
    bufp->chgCData(oldp+50,(vlSelfRef.rd),5);
    bufp->chgCData(oldp+51,(vlSelfRef.ALU_ctrl),3);
    bufp->chgIData(oldp+52,(vlSelfRef.rs1_out),32);
    bufp->chgIData(oldp+53,(vlSelfRef.rs2_out),32);
    bufp->chgBit(oldp+54,(vlSelfRef.ALU_carry));
    bufp->chgBit(oldp+55,(vlSelfRef.ALU_overflow));
    bufp->chgBit(oldp+56,(vlSelfRef.is_break_out));
    bufp->chgBit(oldp+57,((0U == (IData)(vlSelfRef.rd))));
    bufp->chgCData(oldp+58,((0xffU & ((IData)(1U) << (IData)(vlSelfRef.ALU_ctrl)))),8);
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
