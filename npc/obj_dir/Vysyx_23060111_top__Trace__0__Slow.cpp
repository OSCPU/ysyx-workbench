// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060111_top__Syms.h"


VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_init_sub__TOP__0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+33,"rst", false,-1);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBus(c+37,"rbb", false,-1, 9,0);
    tracep->pushNamePrefix("ysyx_23060111_top ");
    tracep->declBit(c+33,"rst", false,-1);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->declBus(c+37,"rbb", false,-1, 9,0);
    tracep->declBus(c+38,"dnpc", false,-1, 31,0);
    tracep->declBus(c+38,"snpc", false,-1, 31,0);
    tracep->declBus(c+39,"imm", false,-1, 31,20);
    tracep->declBus(c+40,"rs1", false,-1, 19,15);
    tracep->declBus(c+41,"funct3", false,-1, 14,12);
    tracep->declBus(c+42,"rd", false,-1, 11,7);
    tracep->declBus(c+43,"opcode", false,-1, 6,0);
    tracep->declBus(c+44,"wdata", false,-1, 31,0);
    tracep->declBus(c+42,"waddr", false,-1, 4,0);
    tracep->declBus(c+40,"raddr", false,-1, 4,0);
    tracep->declBit(c+47,"wen", false,-1);
    tracep->declBus(c+45,"rout", false,-1, 31,0);
    tracep->pushNamePrefix("init_EXU ");
    tracep->declBus(c+38,"dnpc", false,-1, 31,0);
    tracep->declBus(c+38,"snpc", false,-1, 31,0);
    tracep->declBus(c+39,"imm", false,-1, 31,20);
    tracep->declBus(c+40,"rs1", false,-1, 19,15);
    tracep->declBus(c+41,"funct3", false,-1, 14,12);
    tracep->declBus(c+42,"rd", false,-1, 11,7);
    tracep->declBus(c+43,"opcode", false,-1, 6,0);
    tracep->declBus(c+45,"rout", false,-1, 31,0);
    tracep->declBus(c+44,"wdata", false,-1, 31,0);
    tracep->declBus(c+42,"waddr", false,-1, 4,0);
    tracep->declBus(c+40,"raddr", false,-1, 4,0);
    tracep->declBus(c+37,"rbb", false,-1, 9,0);
    tracep->declBit(c+47,"wen", false,-1);
    tracep->declBus(c+46,"imm_32", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("init_IDU ");
    tracep->declBus(c+35,"inst", false,-1, 31,0);
    tracep->declBus(c+39,"imm", false,-1, 31,20);
    tracep->declBus(c+41,"funct3", false,-1, 14,12);
    tracep->declBus(c+40,"rs1", false,-1, 19,15);
    tracep->declBus(c+42,"rd", false,-1, 11,7);
    tracep->declBus(c+43,"opcode", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_renew ");
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+33,"rst", false,-1);
    tracep->declBus(c+38,"snpc", false,-1, 31,0);
    tracep->declBus(c+38,"dnpc", false,-1, 31,0);
    tracep->declBus(c+36,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("renew_pc ");
    tracep->declBus(c+48,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+49,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBit(c+33,"rst", false,-1);
    tracep->declBus(c+38,"din", false,-1, 31,0);
    tracep->declBus(c+36,"dout", false,-1, 31,0);
    tracep->declBit(c+47,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_$0 ");
    tracep->declBus(c+50,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+48,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+34,"clk", false,-1);
    tracep->declBus(c+44,"wdata", false,-1, 31,0);
    tracep->declBus(c+42,"waddr", false,-1, 4,0);
    tracep->declBus(c+40,"raddr", false,-1, 4,0);
    tracep->declBit(c+47,"wen", false,-1);
    tracep->declBus(c+45,"rout", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_init_top(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_23060111_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_23060111_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_23060111_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_register(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_23060111_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_23060111_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_23060111_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_full_sub_0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_23060111_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060111_top___024root*>(voidSelf);
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_23060111_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_23060111_top___024root__trace_full_sub_0(Vysyx_23060111_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060111_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060111_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[31]),32);
    bufp->fullBit(oldp+33,(vlSelf->rst));
    bufp->fullBit(oldp+34,(vlSelf->clk));
    bufp->fullIData(oldp+35,(vlSelf->inst),32);
    bufp->fullIData(oldp+36,(vlSelf->pc),32);
    bufp->fullSData(oldp+37,(vlSelf->rbb),10);
    bufp->fullIData(oldp+38,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullSData(oldp+39,((vlSelf->inst >> 0x14U)),12);
    bufp->fullCData(oldp+40,((0x1fU & (vlSelf->inst 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+41,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+42,((0x1fU & (vlSelf->inst 
                                       >> 7U))),5);
    bufp->fullCData(oldp+43,((0x7fU & vlSelf->inst)),7);
    bufp->fullIData(oldp+44,((vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))] 
                              + (vlSelf->inst >> 0x14U))),32);
    bufp->fullIData(oldp+45,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
                             [(0x1fU & (vlSelf->inst 
                                        >> 0xfU))]),32);
    bufp->fullIData(oldp+46,((vlSelf->inst >> 0x14U)),32);
    bufp->fullBit(oldp+47,(1U));
    bufp->fullIData(oldp+48,(0x20U),32);
    bufp->fullIData(oldp+49,(0x80000000U),32);
    bufp->fullIData(oldp+50,(5U),32);
}
