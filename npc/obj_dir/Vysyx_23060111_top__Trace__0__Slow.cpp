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
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBit(c+110,"clk", false,-1);
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBus(c+112,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("ysyx_23060111_top ");
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBit(c+110,"clk", false,-1);
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBus(c+112,"pc", false,-1, 31,0);
    tracep->declBus(c+45,"snpc", false,-1, 31,0);
    tracep->declBus(c+113,"opcode", false,-1, 6,0);
    tracep->declBus(c+114,"rd", false,-1, 11,7);
    tracep->declBus(c+115,"funct3", false,-1, 14,12);
    tracep->declBus(c+116,"rs1", false,-1, 19,15);
    tracep->declBus(c+117,"rs2", false,-1, 24,20);
    tracep->declBus(c+118,"funct7", false,-1, 31,25);
    tracep->declBus(c+11,"type_i", false,-1, 3,0);
    tracep->declBus(c+12,"imm", false,-1, 31,0);
    tracep->declBus(c+46,"wdata", false,-1, 31,0);
    tracep->declBus(c+114,"waddr", false,-1, 4,0);
    tracep->declBus(c+116,"raddr", false,-1, 4,0);
    tracep->declBit(c+133,"wen", false,-1);
    tracep->declBus(c+119,"rout", false,-1, 31,0);
    tracep->pushNamePrefix("init_EXU ");
    tracep->declBus(c+119,"rout", false,-1, 31,0);
    tracep->declBus(c+112,"pc", false,-1, 31,0);
    tracep->declBus(c+45,"snpc", false,-1, 31,0);
    tracep->declBus(c+113,"opcode", false,-1, 6,0);
    tracep->declBus(c+114,"rd", false,-1, 11,7);
    tracep->declBus(c+115,"funct3", false,-1, 14,12);
    tracep->declBus(c+116,"rs1", false,-1, 19,15);
    tracep->declBus(c+117,"rs2", false,-1, 24,20);
    tracep->declBus(c+118,"funct7", false,-1, 31,25);
    tracep->declBus(c+11,"type_i", false,-1, 3,0);
    tracep->declBus(c+12,"imm", false,-1, 31,0);
    tracep->declBus(c+46,"wdata", false,-1, 31,0);
    tracep->declBus(c+114,"waddr", false,-1, 4,0);
    tracep->declBus(c+116,"raddr", false,-1, 4,0);
    tracep->declBit(c+133,"wen", false,-1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBus(c+134,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+135,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+136,"DATA_LEN", false,-1, 31,0);
    tracep->declQuad(c+47,"out", false,-1, 63,0);
    tracep->declBus(c+11,"key", false,-1, 3,0);
    tracep->declQuad(c+120,"default_out", false,-1, 63,0);
    tracep->declArray(c+122,"lut", false,-1, 339,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+134,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+135,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+136,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+137,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declQuad(c+47,"out", false,-1, 63,0);
    tracep->declBus(c+11,"key", false,-1, 3,0);
    tracep->declQuad(c+120,"default_out", false,-1, 63,0);
    tracep->declArray(c+122,"lut", false,-1, 339,0);
    tracep->declBus(c+138,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 5; ++i) {
        tracep->declArray(c+49+i*3,"pair_list", true,(i+0), 67,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+64+i*2,"data_list", true,(i+0), 63,0);
    }
    tracep->declQuad(c+74,"lut_out", false,-1, 63,0);
    tracep->declBit(c+76,"hit", false,-1);
    tracep->declBus(c+139,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("init_IDU ");
    tracep->declBus(c+111,"inst", false,-1, 31,0);
    tracep->declBus(c+113,"opcode", false,-1, 6,0);
    tracep->declBus(c+114,"rd", false,-1, 11,7);
    tracep->declBus(c+115,"funct3", false,-1, 14,12);
    tracep->declBus(c+116,"rs1", false,-1, 19,15);
    tracep->declBus(c+117,"rs2", false,-1, 24,20);
    tracep->declBus(c+118,"funct7", false,-1, 31,25);
    tracep->declBus(c+11,"type_i", false,-1, 3,0);
    tracep->declBus(c+12,"imm", false,-1, 31,0);
    tracep->pushNamePrefix("typeMux ");
    tracep->declBus(c+134,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+140,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+141,"DATA_LEN", false,-1, 31,0);
    tracep->declQuad(c+13,"out", false,-1, 35,0);
    tracep->declBus(c+113,"key", false,-1, 6,0);
    tracep->declQuad(c+142,"default_out", false,-1, 35,0);
    tracep->declArray(c+15,"lut", false,-1, 214,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+134,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+140,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+141,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+137,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declQuad(c+13,"out", false,-1, 35,0);
    tracep->declBus(c+113,"key", false,-1, 6,0);
    tracep->declQuad(c+142,"default_out", false,-1, 35,0);
    tracep->declArray(c+15,"lut", false,-1, 214,0);
    tracep->declBus(c+144,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+22+i*2,"pair_list", true,(i+0), 42,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+6+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+32+i*2,"data_list", true,(i+0), 35,0);
    }
    tracep->declQuad(c+42,"lut_out", false,-1, 35,0);
    tracep->declBit(c+44,"hit", false,-1);
    tracep->declBus(c+139,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("pc_renew ");
    tracep->declBit(c+110,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+45,"snpc", false,-1, 31,0);
    tracep->declBus(c+112,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("renew_pc ");
    tracep->declBus(c+145,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+146,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+110,"clk", false,-1);
    tracep->declBit(c+109,"rst", false,-1);
    tracep->declBus(c+45,"din", false,-1, 31,0);
    tracep->declBus(c+112,"dout", false,-1, 31,0);
    tracep->declBit(c+133,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_$0 ");
    tracep->declBus(c+134,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+145,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+110,"clk", false,-1);
    tracep->declBus(c+46,"wdata", false,-1, 31,0);
    tracep->declBus(c+114,"waddr", false,-1, 4,0);
    tracep->declBus(c+116,"raddr", false,-1, 4,0);
    tracep->declBit(c+133,"wen", false,-1);
    tracep->declBus(c+119,"rout", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+77+i*1,"rf", true,(i+0), 31,0);
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
    VlWide<11>/*351:0*/ __Vtemp_h44e97e15__0;
    // Body
    bufp->fullCData(oldp+1,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+2,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+3,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+4,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[3]),4);
    bufp->fullCData(oldp+5,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list[4]),4);
    bufp->fullCData(oldp+6,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+7,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+8,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+9,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+10,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[4]),7);
    bufp->fullCData(oldp+11,((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                              >> 0x20U)))),4);
    bufp->fullIData(oldp+12,((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1)),32);
    bufp->fullQData(oldp+13,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1),36);
    bufp->fullWData(oldp+15,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4),215);
    bufp->fullQData(oldp+22,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[0]),43);
    bufp->fullQData(oldp+24,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[1]),43);
    bufp->fullQData(oldp+26,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[2]),43);
    bufp->fullQData(oldp+28,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[3]),43);
    bufp->fullQData(oldp+30,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[4]),43);
    bufp->fullQData(oldp+32,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[0]),36);
    bufp->fullQData(oldp+34,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[1]),36);
    bufp->fullQData(oldp+36,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[2]),36);
    bufp->fullQData(oldp+38,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[3]),36);
    bufp->fullQData(oldp+40,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[4]),36);
    bufp->fullQData(oldp+42,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out),36);
    bufp->fullBit(oldp+44,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+45,((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1)),32);
    bufp->fullIData(oldp+46,((IData)((vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1 
                                      >> 0x20U))),32);
    bufp->fullQData(oldp+47,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1),64);
    bufp->fullWData(oldp+49,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0]),68);
    bufp->fullWData(oldp+52,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1]),68);
    bufp->fullWData(oldp+55,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2]),68);
    bufp->fullWData(oldp+58,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3]),68);
    bufp->fullWData(oldp+61,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4]),68);
    bufp->fullQData(oldp+64,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[0]),64);
    bufp->fullQData(oldp+66,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[1]),64);
    bufp->fullQData(oldp+68,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[2]),64);
    bufp->fullQData(oldp+70,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[3]),64);
    bufp->fullQData(oldp+72,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[4]),64);
    bufp->fullQData(oldp+74,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out),64);
    bufp->fullBit(oldp+76,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+77,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
    bufp->fullIData(oldp+78,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[1]),32);
    bufp->fullIData(oldp+79,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[2]),32);
    bufp->fullIData(oldp+80,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[3]),32);
    bufp->fullIData(oldp+81,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[4]),32);
    bufp->fullIData(oldp+82,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[5]),32);
    bufp->fullIData(oldp+83,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[6]),32);
    bufp->fullIData(oldp+84,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[7]),32);
    bufp->fullIData(oldp+85,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[8]),32);
    bufp->fullIData(oldp+86,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[9]),32);
    bufp->fullIData(oldp+87,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[10]),32);
    bufp->fullIData(oldp+88,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[11]),32);
    bufp->fullIData(oldp+89,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[12]),32);
    bufp->fullIData(oldp+90,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[13]),32);
    bufp->fullIData(oldp+91,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[14]),32);
    bufp->fullIData(oldp+92,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[15]),32);
    bufp->fullIData(oldp+93,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[16]),32);
    bufp->fullIData(oldp+94,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[17]),32);
    bufp->fullIData(oldp+95,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[18]),32);
    bufp->fullIData(oldp+96,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[19]),32);
    bufp->fullIData(oldp+97,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[20]),32);
    bufp->fullIData(oldp+98,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[21]),32);
    bufp->fullIData(oldp+99,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[22]),32);
    bufp->fullIData(oldp+100,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[23]),32);
    bufp->fullIData(oldp+101,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[24]),32);
    bufp->fullIData(oldp+102,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[25]),32);
    bufp->fullIData(oldp+103,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[26]),32);
    bufp->fullIData(oldp+104,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[27]),32);
    bufp->fullIData(oldp+105,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[28]),32);
    bufp->fullIData(oldp+106,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[29]),32);
    bufp->fullIData(oldp+107,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[30]),32);
    bufp->fullIData(oldp+108,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[31]),32);
    bufp->fullBit(oldp+109,(vlSelf->rst));
    bufp->fullBit(oldp+110,(vlSelf->clk));
    bufp->fullIData(oldp+111,(vlSelf->inst),32);
    bufp->fullIData(oldp+112,(vlSelf->pc),32);
    bufp->fullCData(oldp+113,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+114,((0x1fU & (vlSelf->inst 
                                        >> 7U))),5);
    bufp->fullCData(oldp+115,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+116,((0x1fU & (vlSelf->inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+117,((0x1fU & (vlSelf->inst 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+118,((vlSelf->inst >> 0x19U)),7);
    bufp->fullIData(oldp+119,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))]),32);
    bufp->fullQData(oldp+120,((QData)((IData)(((IData)(4U) 
                                               + vlSelf->pc)))),64);
    __Vtemp_h44e97e15__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(4U) 
                                                          + vlSelf->pc))) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))));
    __Vtemp_h44e97e15__0[1U] = (IData)(((((QData)((IData)(
                                                          ((IData)(4U) 
                                                           + vlSelf->pc))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))) 
                                        >> 0x20U));
    __Vtemp_h44e97e15__0[2U] = (5U | ((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((IData)(4U) 
                                                                  + vlSelf->pc))))) 
                                      << 4U));
    __Vtemp_h44e97e15__0[3U] = (((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x1cU) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 4U));
    __Vtemp_h44e97e15__0[4U] = (0x40U | (((IData)((
                                                   ((QData)((IData)(
                                                                    ((IData)(4U) 
                                                                     + vlSelf->pc))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)))) 
                                          << 8U) | 
                                         ((IData)((
                                                   (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelf->pc)))) 
                                                   >> 0x20U)) 
                                          >> 0x1cU)));
    __Vtemp_h44e97e15__0[5U] = (((IData)((((QData)((IData)(
                                                           ((IData)(4U) 
                                                            + vlSelf->pc))) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)))) 
                                 >> 0x18U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         ((IData)(4U) 
                                                                          + vlSelf->pc))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0))) 
                                                       >> 0x20U)) 
                                              << 8U));
    __Vtemp_h44e97e15__0[6U] = (0x300U | (((IData)(
                                                   (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1)) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelf->pc))))) 
                                           << 0xcU) 
                                          | ((IData)(
                                                     ((((QData)((IData)(
                                                                        ((IData)(4U) 
                                                                         + vlSelf->pc))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0))) 
                                                      >> 0x20U)) 
                                             >> 0x18U)));
    __Vtemp_h44e97e15__0[7U] = (((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x14U) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 0xcU));
    __Vtemp_h44e97e15__0[8U] = (0x2000U | (((IData)(
                                                    (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       ((IData)(4U) 
                                                                        + vlSelf->pc))))) 
                                            << 0x10U) 
                                           | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              >> 0x14U)));
    __Vtemp_h44e97e15__0[9U] = (((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x10U) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 0x10U));
    __Vtemp_h44e97e15__0[0xaU] = (0x10000U | ((IData)(
                                                      ((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              >> 0x10U));
    bufp->fullWData(oldp+122,(__Vtemp_h44e97e15__0),340);
    bufp->fullBit(oldp+133,(1U));
    bufp->fullIData(oldp+134,(5U),32);
    bufp->fullIData(oldp+135,(4U),32);
    bufp->fullIData(oldp+136,(0x40U),32);
    bufp->fullIData(oldp+137,(1U),32);
    bufp->fullIData(oldp+138,(0x44U),32);
    bufp->fullIData(oldp+139,(5U),32);
    bufp->fullIData(oldp+140,(7U),32);
    bufp->fullIData(oldp+141,(0x24U),32);
    bufp->fullQData(oldp+142,(0ULL),36);
    bufp->fullIData(oldp+144,(0x2bU),32);
    bufp->fullIData(oldp+145,(0x20U),32);
    bufp->fullIData(oldp+146,(0x80000000U),32);
}
