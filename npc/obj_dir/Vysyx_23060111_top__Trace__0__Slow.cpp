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
    tracep->declBit(c+122,"rst", false,-1);
    tracep->declBit(c+123,"clk", false,-1);
    tracep->declBus(c+124,"inst", false,-1, 31,0);
    tracep->declBus(c+125,"pc", false,-1, 31,0);
    tracep->declBus(c+126,"halt_ret", false,-1, 31,0);
    tracep->declBit(c+127,"inv_flag", false,-1);
    tracep->pushNamePrefix("ysyx_23060111_top ");
    tracep->declBit(c+122,"rst", false,-1);
    tracep->declBit(c+123,"clk", false,-1);
    tracep->declBus(c+124,"inst", false,-1, 31,0);
    tracep->declBus(c+125,"pc", false,-1, 31,0);
    tracep->declBus(c+126,"halt_ret", false,-1, 31,0);
    tracep->declBit(c+127,"inv_flag", false,-1);
    tracep->declBus(c+58,"snpc", false,-1, 31,0);
    tracep->declBus(c+128,"opcode", false,-1, 6,0);
    tracep->declBus(c+129,"rd", false,-1, 11,7);
    tracep->declBus(c+130,"funct3", false,-1, 14,12);
    tracep->declBus(c+131,"rs1", false,-1, 19,15);
    tracep->declBus(c+132,"rs2", false,-1, 24,20);
    tracep->declBus(c+133,"funct7", false,-1, 31,25);
    tracep->declBus(c+13,"type_i", false,-1, 3,0);
    tracep->declBus(c+14,"imm", false,-1, 31,0);
    tracep->declBus(c+59,"wdata", false,-1, 31,0);
    tracep->declBus(c+129,"waddr", false,-1, 4,0);
    tracep->declBus(c+131,"raddr", false,-1, 4,0);
    tracep->declBit(c+148,"wen", false,-1);
    tracep->declBus(c+134,"rout", false,-1, 31,0);
    tracep->pushNamePrefix("init_EXU ");
    tracep->declBus(c+134,"rout", false,-1, 31,0);
    tracep->declBus(c+125,"pc", false,-1, 31,0);
    tracep->declBus(c+58,"snpc", false,-1, 31,0);
    tracep->declBus(c+128,"opcode", false,-1, 6,0);
    tracep->declBus(c+129,"rd", false,-1, 11,7);
    tracep->declBus(c+130,"funct3", false,-1, 14,12);
    tracep->declBus(c+131,"rs1", false,-1, 19,15);
    tracep->declBus(c+132,"rs2", false,-1, 24,20);
    tracep->declBus(c+133,"funct7", false,-1, 31,25);
    tracep->declBus(c+13,"type_i", false,-1, 3,0);
    tracep->declBus(c+14,"imm", false,-1, 31,0);
    tracep->declBus(c+59,"wdata", false,-1, 31,0);
    tracep->declBus(c+129,"waddr", false,-1, 4,0);
    tracep->declBus(c+131,"raddr", false,-1, 4,0);
    tracep->declBit(c+148,"wen", false,-1);
    tracep->pushNamePrefix("i1 ");
    tracep->declBus(c+149,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+150,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+151,"DATA_LEN", false,-1, 31,0);
    tracep->declQuad(c+60,"out", false,-1, 63,0);
    tracep->declBus(c+13,"key", false,-1, 3,0);
    tracep->declQuad(c+135,"default_out", false,-1, 63,0);
    tracep->declArray(c+137,"lut", false,-1, 339,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+149,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+150,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+151,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+152,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declQuad(c+60,"out", false,-1, 63,0);
    tracep->declBus(c+13,"key", false,-1, 3,0);
    tracep->declQuad(c+135,"default_out", false,-1, 63,0);
    tracep->declArray(c+137,"lut", false,-1, 339,0);
    tracep->declBus(c+153,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 5; ++i) {
        tracep->declArray(c+62+i*3,"pair_list", true,(i+0), 67,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declBus(c+1+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 5; ++i) {
        tracep->declQuad(c+77+i*2,"data_list", true,(i+0), 63,0);
    }
    tracep->declQuad(c+87,"lut_out", false,-1, 63,0);
    tracep->declBit(c+89,"hit", false,-1);
    tracep->declBus(c+154,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("init_IDU ");
    tracep->declBus(c+124,"inst", false,-1, 31,0);
    tracep->declBus(c+128,"opcode", false,-1, 6,0);
    tracep->declBus(c+129,"rd", false,-1, 11,7);
    tracep->declBus(c+130,"funct3", false,-1, 14,12);
    tracep->declBus(c+131,"rs1", false,-1, 19,15);
    tracep->declBus(c+132,"rs2", false,-1, 24,20);
    tracep->declBus(c+133,"funct7", false,-1, 31,25);
    tracep->declBus(c+13,"type_i", false,-1, 3,0);
    tracep->declBus(c+14,"imm", false,-1, 31,0);
    tracep->declBit(c+127,"inv_flag", false,-1);
    tracep->pushNamePrefix("typeMux ");
    tracep->declBus(c+155,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+155,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+156,"DATA_LEN", false,-1, 31,0);
    tracep->declQuad(c+15,"out", false,-1, 36,0);
    tracep->declBus(c+128,"key", false,-1, 6,0);
    tracep->declQuad(c+157,"default_out", false,-1, 36,0);
    tracep->declArray(c+17,"lut", false,-1, 307,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+155,"NR_KEY", false,-1, 31,0);
    tracep->declBus(c+155,"KEY_LEN", false,-1, 31,0);
    tracep->declBus(c+156,"DATA_LEN", false,-1, 31,0);
    tracep->declBus(c+152,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declQuad(c+15,"out", false,-1, 36,0);
    tracep->declBus(c+128,"key", false,-1, 6,0);
    tracep->declQuad(c+157,"default_out", false,-1, 36,0);
    tracep->declArray(c+17,"lut", false,-1, 307,0);
    tracep->declBus(c+159,"PAIR_LEN", false,-1, 31,0);
    for (int i = 0; i < 7; ++i) {
        tracep->declQuad(c+27+i*2,"pair_list", true,(i+0), 43,0);
    }
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+6+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 7; ++i) {
        tracep->declQuad(c+41+i*2,"data_list", true,(i+0), 36,0);
    }
    tracep->declQuad(c+55,"lut_out", false,-1, 36,0);
    tracep->declBit(c+57,"hit", false,-1);
    tracep->declBus(c+160,"i", false,-1, 31,0);
    tracep->pushNamePrefix("genblk1 ");
    tracep->popNamePrefix(4);
    tracep->pushNamePrefix("pc_renew ");
    tracep->declBit(c+123,"clk", false,-1);
    tracep->declBit(c+122,"rst", false,-1);
    tracep->declBus(c+58,"snpc", false,-1, 31,0);
    tracep->declBus(c+125,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("renew_pc ");
    tracep->declBus(c+161,"WIDTH", false,-1, 31,0);
    tracep->declBus(c+162,"RESET_VAL", false,-1, 31,0);
    tracep->declBit(c+123,"clk", false,-1);
    tracep->declBit(c+122,"rst", false,-1);
    tracep->declBus(c+58,"din", false,-1, 31,0);
    tracep->declBus(c+125,"dout", false,-1, 31,0);
    tracep->declBit(c+148,"wen", false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("reg_$0 ");
    tracep->declBus(c+149,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+161,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+123,"clk", false,-1);
    tracep->declBus(c+59,"wdata", false,-1, 31,0);
    tracep->declBus(c+129,"waddr", false,-1, 4,0);
    tracep->declBus(c+131,"raddr", false,-1, 4,0);
    tracep->declBit(c+148,"wen", false,-1);
    tracep->declBus(c+134,"rout", false,-1, 31,0);
    tracep->declBus(c+126,"halt_ret", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+90+i*1,"rf", true,(i+0), 31,0);
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
    VlWide<11>/*351:0*/ __Vtemp_h53e1786c__0;
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
    bufp->fullCData(oldp+11,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[5]),7);
    bufp->fullCData(oldp+12,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list[6]),7);
    bufp->fullCData(oldp+13,((0xfU & (IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                              >> 0x21U)))),4);
    bufp->fullIData(oldp+14,((IData)((vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                      >> 1U))),32);
    bufp->fullQData(oldp+15,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1),37);
    bufp->fullWData(oldp+17,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4),308);
    bufp->fullQData(oldp+27,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[0]),44);
    bufp->fullQData(oldp+29,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[1]),44);
    bufp->fullQData(oldp+31,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[2]),44);
    bufp->fullQData(oldp+33,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[3]),44);
    bufp->fullQData(oldp+35,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[4]),44);
    bufp->fullQData(oldp+37,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[5]),44);
    bufp->fullQData(oldp+39,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list[6]),44);
    bufp->fullQData(oldp+41,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[0]),37);
    bufp->fullQData(oldp+43,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[1]),37);
    bufp->fullQData(oldp+45,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[2]),37);
    bufp->fullQData(oldp+47,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[3]),37);
    bufp->fullQData(oldp+49,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[4]),37);
    bufp->fullQData(oldp+51,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[5]),37);
    bufp->fullQData(oldp+53,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list[6]),37);
    bufp->fullQData(oldp+55,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out),37);
    bufp->fullBit(oldp+57,(vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+58,((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1)),32);
    bufp->fullIData(oldp+59,((IData)((vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1 
                                      >> 0x20U))),32);
    bufp->fullQData(oldp+60,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1),64);
    bufp->fullWData(oldp+62,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[0]),68);
    bufp->fullWData(oldp+65,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[1]),68);
    bufp->fullWData(oldp+68,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[2]),68);
    bufp->fullWData(oldp+71,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[3]),68);
    bufp->fullWData(oldp+74,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list[4]),68);
    bufp->fullQData(oldp+77,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[0]),64);
    bufp->fullQData(oldp+79,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[1]),64);
    bufp->fullQData(oldp+81,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[2]),64);
    bufp->fullQData(oldp+83,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[3]),64);
    bufp->fullQData(oldp+85,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list[4]),64);
    bufp->fullQData(oldp+87,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out),64);
    bufp->fullBit(oldp+89,(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+90,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[0]),32);
    bufp->fullIData(oldp+91,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[1]),32);
    bufp->fullIData(oldp+92,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[2]),32);
    bufp->fullIData(oldp+93,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[3]),32);
    bufp->fullIData(oldp+94,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[4]),32);
    bufp->fullIData(oldp+95,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[5]),32);
    bufp->fullIData(oldp+96,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[6]),32);
    bufp->fullIData(oldp+97,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[7]),32);
    bufp->fullIData(oldp+98,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[8]),32);
    bufp->fullIData(oldp+99,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[9]),32);
    bufp->fullIData(oldp+100,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[10]),32);
    bufp->fullIData(oldp+101,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[11]),32);
    bufp->fullIData(oldp+102,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[12]),32);
    bufp->fullIData(oldp+103,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[13]),32);
    bufp->fullIData(oldp+104,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[14]),32);
    bufp->fullIData(oldp+105,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[15]),32);
    bufp->fullIData(oldp+106,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[16]),32);
    bufp->fullIData(oldp+107,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[17]),32);
    bufp->fullIData(oldp+108,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[18]),32);
    bufp->fullIData(oldp+109,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[19]),32);
    bufp->fullIData(oldp+110,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[20]),32);
    bufp->fullIData(oldp+111,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[21]),32);
    bufp->fullIData(oldp+112,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[22]),32);
    bufp->fullIData(oldp+113,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[23]),32);
    bufp->fullIData(oldp+114,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[24]),32);
    bufp->fullIData(oldp+115,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[25]),32);
    bufp->fullIData(oldp+116,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[26]),32);
    bufp->fullIData(oldp+117,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[27]),32);
    bufp->fullIData(oldp+118,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[28]),32);
    bufp->fullIData(oldp+119,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[29]),32);
    bufp->fullIData(oldp+120,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[30]),32);
    bufp->fullIData(oldp+121,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf[31]),32);
    bufp->fullBit(oldp+122,(vlSelf->rst));
    bufp->fullBit(oldp+123,(vlSelf->clk));
    bufp->fullIData(oldp+124,(vlSelf->inst),32);
    bufp->fullIData(oldp+125,(vlSelf->pc),32);
    bufp->fullIData(oldp+126,(vlSelf->halt_ret),32);
    bufp->fullBit(oldp+127,(vlSelf->inv_flag));
    bufp->fullCData(oldp+128,((0x7fU & vlSelf->inst)),7);
    bufp->fullCData(oldp+129,((0x1fU & (vlSelf->inst 
                                        >> 7U))),5);
    bufp->fullCData(oldp+130,((7U & (vlSelf->inst >> 0xcU))),3);
    bufp->fullCData(oldp+131,((0x1fU & (vlSelf->inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+132,((0x1fU & (vlSelf->inst 
                                        >> 0x14U))),5);
    bufp->fullCData(oldp+133,((vlSelf->inst >> 0x19U)),7);
    bufp->fullIData(oldp+134,(vlSelf->ysyx_23060111_top__DOT__reg___0240__DOT__rf
                              [(0x1fU & (vlSelf->inst 
                                         >> 0xfU))]),32);
    bufp->fullQData(oldp+135,((QData)((IData)(((IData)(4U) 
                                               + vlSelf->pc)))),64);
    __Vtemp_h53e1786c__0[0U] = (IData)((((QData)((IData)(
                                                         ((IData)(4U) 
                                                          + vlSelf->pc))) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))));
    __Vtemp_h53e1786c__0[1U] = (IData)(((((QData)((IData)(
                                                          ((IData)(4U) 
                                                           + vlSelf->pc))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0))) 
                                        >> 0x20U));
    __Vtemp_h53e1786c__0[2U] = (5U | ((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((IData)(4U) 
                                                                  + vlSelf->pc))))) 
                                      << 4U));
    __Vtemp_h53e1786c__0[3U] = (((IData)((((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
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
    __Vtemp_h53e1786c__0[4U] = (0x40U | (((IData)((
                                                   ((QData)((IData)(
                                                                    ((IData)(4U) 
                                                                     + vlSelf->pc))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((IData)(4U) 
                                                                      + vlSelf->pc))))) 
                                          << 8U) | 
                                         ((IData)((
                                                   (((QData)((IData)(vlSelf->ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0)) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((IData)(4U) 
                                                                       + vlSelf->pc)))) 
                                                   >> 0x20U)) 
                                          >> 0x1cU)));
    __Vtemp_h53e1786c__0[5U] = (((IData)((((QData)((IData)(
                                                           ((IData)(4U) 
                                                            + vlSelf->pc))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x18U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         ((IData)(4U) 
                                                                          + vlSelf->pc))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 8U));
    __Vtemp_h53e1786c__0[6U] = (0x300U | (((IData)(
                                                   (((QData)((IData)(
                                                                     (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                                      >> 1U))) 
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
                                                       | (QData)((IData)(
                                                                         ((IData)(4U) 
                                                                          + vlSelf->pc)))) 
                                                      >> 0x20U)) 
                                             >> 0x18U)));
    __Vtemp_h53e1786c__0[7U] = (((IData)((((QData)((IData)(
                                                           (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                            >> 1U))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x14U) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                                          >> 1U))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 0xcU));
    __Vtemp_h53e1786c__0[8U] = (0x2000U | (((IData)(
                                                    (((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
                                                      << 0x20U) 
                                                     | (QData)((IData)(
                                                                       ((IData)(4U) 
                                                                        + vlSelf->pc))))) 
                                            << 0x10U) 
                                           | ((IData)(
                                                      ((((QData)((IData)(
                                                                         (vlSelf->ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1 
                                                                          >> 1U))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              >> 0x14U)));
    __Vtemp_h53e1786c__0[9U] = (((IData)((((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((IData)(4U) 
                                                             + vlSelf->pc))))) 
                                 >> 0x10U) | ((IData)(
                                                      ((((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              << 0x10U));
    __Vtemp_h53e1786c__0[0xaU] = (0x10000U | ((IData)(
                                                      ((((QData)((IData)(vlSelf->__VdfgTmp_hd63b7461__0)) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((IData)(4U) 
                                                                           + vlSelf->pc)))) 
                                                       >> 0x20U)) 
                                              >> 0x10U));
    bufp->fullWData(oldp+137,(__Vtemp_h53e1786c__0),340);
    bufp->fullBit(oldp+148,(1U));
    bufp->fullIData(oldp+149,(5U),32);
    bufp->fullIData(oldp+150,(4U),32);
    bufp->fullIData(oldp+151,(0x40U),32);
    bufp->fullIData(oldp+152,(1U),32);
    bufp->fullIData(oldp+153,(0x44U),32);
    bufp->fullIData(oldp+154,(5U),32);
    bufp->fullIData(oldp+155,(7U),32);
    bufp->fullIData(oldp+156,(0x25U),32);
    bufp->fullQData(oldp+157,(1ULL),37);
    bufp->fullIData(oldp+159,(0x2cU),32);
    bufp->fullIData(oldp+160,(7U),32);
    bufp->fullIData(oldp+161,(0x20U),32);
    bufp->fullIData(oldp+162,(0x80000000U),32);
}
