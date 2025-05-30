// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+48,"clock",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"reset",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+50,"imm",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+51,"rd",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+52,"ALU_ctrl",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+53,"rs1_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+54,"rs2_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+55,"ALU_carry",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"ALU_overflow",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"is_break_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->pushNamePrefix("ysyx_25020077_top ");
    tracep->declBit(c+48,"clock",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"reset",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+50,"imm",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+51,"rd",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+52,"ALU_ctrl",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+53,"rs1_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+54,"rs2_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+55,"ALU_carry",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"ALU_overflow",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"is_break_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"io_Pc_count",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"instruction_out",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"imm_type",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+4,"rs1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+60,"rs2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+5,"ALU_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBit(c+48,"clock",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"reset",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+1,"io_Pc_count",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+1,"state",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBus(c+1,"instruction_in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"instruction_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i2 ");
    tracep->declBus(c+2,"io_instruction",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"io_imm_type",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+4,"io_rs1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+51,"io_rd",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+52,"io_ALU_ctrl",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBit(c+57,"is_break_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+6,"instruction_type",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 9,0);
    tracep->declBus(c+7,"addi_Rs1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+8,"addi_Rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+9,"isSpecialType",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i3 ");
    tracep->declBus(c+2,"io_instruction",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"io_imm_type",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+50,"io_imm",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+10,"Imm_1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+11,"isType1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i4 ");
    tracep->declBit(c+48,"clock",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"reset",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+51,"io_waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+5,"io_wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+4,"io_raddr_rs1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+53,"io_rdata_rs1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+60,"io_raddr_rs2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+54,"io_rdata_rs2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+12,"regs_0",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,"regs_1",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,"regs_2",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,"regs_3",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,"regs_4",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,"regs_5",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,"regs_6",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,"regs_7",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,"regs_8",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,"regs_9",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,"regs_10",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,"regs_11",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,"regs_12",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,"regs_13",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,"regs_14",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,"regs_15",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,"regs_16",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,"regs_17",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,"regs_18",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,"regs_19",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,"regs_20",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,"regs_21",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,"regs_22",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,"regs_23",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,"regs_24",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,"regs_25",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,"regs_26",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,"regs_27",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,"regs_28",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,"regs_29",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,"regs_30",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,"regs_31",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+58,"isReg0",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("i5 ");
    tracep->declBus(c+53,"io_in_a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+50,"io_in_b",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+52,"io_sw",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 2,0);
    tracep->declBus(c+5,"io_out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+55,"io_carry",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"io_overflow",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+59,"oneHot",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 7,0);
    tracep->declQuad(c+44,"addResult",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 32,0);
    tracep->declQuad(c+46,"subResult",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 32,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_25020077_top__DOT__i0__DOT__state),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_25020077_top__DOT__instruction_out),32);
    bufp->fullCData(oldp+3,(((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                              ? 1U : 0U)),3);
    bufp->fullCData(oldp+4,(vlSelf->ysyx_25020077_top__DOT__rs1),5);
    bufp->fullIData(oldp+5,((IData)(vlSelf->ysyx_25020077_top__DOT__i5__DOT___io_out_T_47)),32);
    bufp->fullSData(oldp+6,(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type),10);
    bufp->fullCData(oldp+7,((0x1fU & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+8,((0x1fU & (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                      >> 7U))),5);
    bufp->fullBit(oldp+9,((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))));
    bufp->fullIData(oldp+10,(((((vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                 >> 0x1fU) ? 0xfffffU
                                 : 0U) << 0xcU) | (vlSelf->ysyx_25020077_top__DOT__instruction_out 
                                                   >> 0x14U))),32);
    bufp->fullBit(oldp+11,((1U == ((0x13U == (IData)(vlSelf->ysyx_25020077_top__DOT__i2__DOT__instruction_type))
                                    ? 1U : 0U))));
    bufp->fullIData(oldp+12,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_0),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_1),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_2),32);
    bufp->fullIData(oldp+15,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_3),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_4),32);
    bufp->fullIData(oldp+17,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_5),32);
    bufp->fullIData(oldp+18,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_6),32);
    bufp->fullIData(oldp+19,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_7),32);
    bufp->fullIData(oldp+20,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_8),32);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_9),32);
    bufp->fullIData(oldp+22,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_10),32);
    bufp->fullIData(oldp+23,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_11),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_12),32);
    bufp->fullIData(oldp+25,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_13),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_14),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_15),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_16),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_17),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_18),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_19),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_20),32);
    bufp->fullIData(oldp+33,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_21),32);
    bufp->fullIData(oldp+34,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_22),32);
    bufp->fullIData(oldp+35,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_23),32);
    bufp->fullIData(oldp+36,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_24),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_25),32);
    bufp->fullIData(oldp+38,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_26),32);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_27),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_28),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_29),32);
    bufp->fullIData(oldp+42,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_30),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_25020077_top__DOT__i4__DOT__regs_31),32);
    bufp->fullQData(oldp+44,(vlSelf->ysyx_25020077_top__DOT__i5__DOT__addResult),33);
    bufp->fullQData(oldp+46,(vlSelf->ysyx_25020077_top__DOT__i5__DOT__subResult),33);
    bufp->fullBit(oldp+48,(vlSelf->clock));
    bufp->fullBit(oldp+49,(vlSelf->reset));
    bufp->fullIData(oldp+50,(vlSelf->imm),32);
    bufp->fullCData(oldp+51,(vlSelf->rd),5);
    bufp->fullCData(oldp+52,(vlSelf->ALU_ctrl),3);
    bufp->fullIData(oldp+53,(vlSelf->rs1_out),32);
    bufp->fullIData(oldp+54,(vlSelf->rs2_out),32);
    bufp->fullBit(oldp+55,(vlSelf->ALU_carry));
    bufp->fullBit(oldp+56,(vlSelf->ALU_overflow));
    bufp->fullBit(oldp+57,(vlSelf->is_break_out));
    bufp->fullBit(oldp+58,((0U == (IData)(vlSelf->rd))));
    bufp->fullCData(oldp+59,((0xffU & ((IData)(1U) 
                                       << (IData)(vlSelf->ALU_ctrl)))),8);
    bufp->fullCData(oldp+60,(0U),5);
}
