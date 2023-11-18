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
    tracep->declBit(c+1,"rst", false,-1);
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBus(c+3,"inst", false,-1, 31,0);
    tracep->declBus(c+4,"val", false,-1, 31,0);
    tracep->declBus(c+5,"snpc", false,-1, 31,0);
    tracep->declBus(c+6,"dnpc", false,-1, 31,0);
    tracep->declBus(c+7,"pc", false,-1, 31,0);
    tracep->declBus(c+8,"imm", false,-1, 31,20);
    tracep->declBus(c+9,"rs1", false,-1, 19,15);
    tracep->declBus(c+10,"rd", false,-1, 11,7);
    tracep->declBus(c+11,"out", false,-1, 31,0);
    tracep->declBus(c+12,"reg_out", false,-1, 31,0);
    tracep->declBus(c+13,"reg_out1", false,-1, 31,0);
    tracep->declBus(c+14,"rbb", false,-1, 19,15);
    tracep->declBus(c+15,"rbb1", false,-1, 9,0);
    tracep->pushNamePrefix("ysyx_23060111_top ");
    tracep->declBit(c+1,"rst", false,-1);
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBus(c+3,"inst", false,-1, 31,0);
    tracep->declBus(c+4,"val", false,-1, 31,0);
    tracep->declBus(c+5,"snpc", false,-1, 31,0);
    tracep->declBus(c+5,"dnpc", false,-1, 31,0);
    tracep->declBus(c+7,"pc", false,-1, 31,0);
    tracep->declBus(c+8,"imm", false,-1, 31,20);
    tracep->declBus(c+9,"rs1", false,-1, 19,15);
    tracep->declBus(c+10,"rd", false,-1, 11,7);
    tracep->declBus(c+11,"out", false,-1, 31,0);
    tracep->declBus(c+12,"reg_out", false,-1, 31,0);
    tracep->declBus(c+13,"reg_out1", false,-1, 31,0);
    tracep->declBus(c+14,"rbb", false,-1, 19,15);
    tracep->declBus(c+15,"rbb1", false,-1, 9,0);
    tracep->pushNamePrefix("init_EXU ");
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBit(c+1,"rst", false,-1);
    tracep->declBus(c+5,"dnpc", false,-1, 31,0);
    tracep->declBus(c+8,"imm", false,-1, 31,20);
    tracep->declBus(c+9,"rs1", false,-1, 19,15);
    tracep->declBus(c+10,"rd", false,-1, 11,7);
    tracep->declBus(c+7,"pc", false,-1, 31,0);
    tracep->declBus(c+12,"reg_out", false,-1, 31,0);
    tracep->declBus(c+13,"reg_out1", false,-1, 31,0);
    tracep->declBus(c+14,"out", false,-1, 19,15);
    tracep->declBus(c+16,"imm_32", false,-1, 31,0);
    tracep->pushNamePrefix("reg_rd ");
    tracep->declBus(c+22,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+23,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBus(c+17,"wdata", false,-1, 31,0);
    tracep->declBus(c+18,"waddr", false,-1, 0,0);
    tracep->declBit(c+24,"wen", false,-1);
    tracep->declBus(c+13,"out", false,-1, 31,0);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+19+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("reg_src1 ");
    tracep->declBus(c+22,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+23,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBus(c+25,"wdata", false,-1, 31,0);
    tracep->declBus(c+20,"waddr", false,-1, 0,0);
    tracep->declBit(c+26,"wen", false,-1);
    tracep->declBus(c+12,"out", false,-1, 31,0);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+27+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("renew_pc ");
    tracep->declBus(c+23,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+28,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBit(c+1,"rst", false,-1);
    tracep->declBus(c+5,"din", false,-1, 31,0);
    tracep->declBus(c+7,"dout", false,-1, 31,0);
    tracep->declBit(c+24,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("init_IDU ");
    tracep->declBus(c+5,"snpc", false,-1, 31,0);
    tracep->declBus(c+3,"inst", false,-1, 31,0);
    tracep->declBus(c+5,"dnpc", false,-1, 31,0);
    tracep->declBus(c+8,"imm", false,-1, 31,20);
    tracep->declBus(c+9,"rs1", false,-1, 19,15);
    tracep->declBus(c+10,"rd", false,-1, 11,7);
    tracep->declBus(c+15,"rbb", false,-1, 9,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("reg_$0 ");
    tracep->declBus(c+22,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+23,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+2,"clk", false,-1);
    tracep->declBus(c+25,"wdata", false,-1, 31,0);
    tracep->declBus(c+26,"waddr", false,-1, 0,0);
    tracep->declBit(c+24,"wen", false,-1);
    tracep->declBus(c+11,"out", false,-1, 31,0);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+21+i*1,"rf", true,(i+0), 31,0);
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
    bufp->fullBit(oldp+1,(vlSelf->rst));
    bufp->fullBit(oldp+2,(vlSelf->clk));
    bufp->fullIData(oldp+3,(vlSelf->inst),32);
    bufp->fullIData(oldp+4,(vlSelf->val),32);
    bufp->fullIData(oldp+5,(vlSelf->snpc),32);
    bufp->fullIData(oldp+6,(vlSelf->dnpc),32);
    bufp->fullIData(oldp+7,(vlSelf->pc),32);
    bufp->fullSData(oldp+8,(vlSelf->imm),12);
    bufp->fullCData(oldp+9,(vlSelf->rs1),5);
    bufp->fullCData(oldp+10,(vlSelf->rd),5);
    bufp->fullIData(oldp+11,(vlSelf->out),32);
    bufp->fullIData(oldp+12,(vlSelf->reg_out),32);
    bufp->fullIData(oldp+13,(vlSelf->reg_out1),32);
    bufp->fullCData(oldp+14,(vlSelf->rbb),5);
    bufp->fullSData(oldp+15,(vlSelf->rbb1),10);
    bufp->fullIData(oldp+16,((vlSelf->inst >> 0x14U)),32);
    bufp->fullIData(oldp+17,((vlSelf->reg_out + (vlSelf->inst 
                                                 >> 0x14U))),32);
    bufp->fullBit(oldp+18,((1U & (vlSelf->inst >> 7U))));
    bufp->fullIData(oldp+19,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__reg_rd__DOT__rf[0]),32);
    bufp->fullBit(oldp+20,((1U & (vlSelf->inst >> 0xfU))));
    bufp->fullIData(oldp+21,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
    bufp->fullIData(oldp+22,(1U),32);
    bufp->fullIData(oldp+23,(0x20U),32);
    bufp->fullBit(oldp+24,(1U));
    bufp->fullIData(oldp+25,(0U),32);
    bufp->fullBit(oldp+26,(0U));
    bufp->fullIData(oldp+27,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__reg_src1__DOT__rf[0]),32);
    bufp->fullIData(oldp+28,(0x80000000U),32);
}
