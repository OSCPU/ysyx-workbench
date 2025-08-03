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
        bufp->chgIData(oldp+0,(vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg),32);
        bufp->chgIData(oldp+1,(vlSelfRef.ysyx_25030077_top__DOT__Pc_next),32);
        bufp->chgIData(oldp+2,(vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg),32);
        bufp->chgBit(oldp+3,(vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__ifu__DOT__state));
        bufp->chgCData(oldp+4,(vlSelfRef.ysyx_25030077_top__DOT__imm_type),3);
        bufp->chgCData(oldp+5,(vlSelfRef.ysyx_25030077_top__DOT__rs1),5);
        bufp->chgCData(oldp+6,(vlSelfRef.ysyx_25030077_top__DOT__rs2),5);
        bufp->chgCData(oldp+7,(vlSelfRef.ysyx_25030077_top__DOT__data_control),3);
        bufp->chgCData(oldp+8,(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type),4);
        bufp->chgBit(oldp+9,(vlSelfRef.ysyx_25030077_top__DOT__is_break_out));
        bufp->chgIData(oldp+10,(vlSelfRef.ysyx_25030077_top__DOT__ALU_result),32);
        bufp->chgIData(oldp+11,(vlSelfRef.ysyx_25030077_top__DOT__mem_data),32);
        bufp->chgIData(oldp+12,(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1),32);
        bufp->chgIData(oldp+13,(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2),32);
        bufp->chgBit(oldp+14,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+15,(vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__addr_state));
        bufp->chgIData(oldp+16,(vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__ifu__DOT__addrReg),32);
        bufp->chgIData(oldp+17,(vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__dpi_inst),32);
        bufp->chgCData(oldp+18,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+19,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+20,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+21,((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+22,((0x213U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+23,((0x313U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+24,((0x393U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+25,((0x4293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
        bufp->chgBit(oldp+26,((0x293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
        bufp->chgBit(oldp+27,((0x93U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
        bufp->chgBit(oldp+28,((0x42b3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
        bufp->chgBit(oldp+29,((0x2b3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
        bufp->chgBit(oldp+30,((0x63U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+31,((0xe3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+32,((0x33U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+33,((0x233U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+34,((0x3b3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+35,((0x333U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+36,((0x8033U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+37,((0x37U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg))));
        bufp->chgBit(oldp+38,((0x17U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg))));
        bufp->chgBit(oldp+39,((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg))));
        bufp->chgBit(oldp+40,((0x67U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+41,((0x123U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+42,((0x2e3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+43,((0x263U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+44,((0x363U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+45,((0x3e3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+46,((0x23U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+47,((0xa3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+48,((0x203U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+49,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+50,((0x103U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+51,((0x83U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+52,((0x283U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+53,((0xb3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+54,((0x133U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+55,((0x1b3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
        bufp->chgBit(oldp+56,((0x193U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+57,((0x113U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+58,((0xf3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+59,((0x173U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+60,((0x100073U == vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg)));
        bufp->chgBit(oldp+61,((0x73U == vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg)));
        bufp->chgBit(oldp+62,((0x30200073U == vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg)));
        bufp->chgIData(oldp+63,(vlSelfRef.ysyx_25030077_top__DOT__i3__DOT__Imm_type1),32);
        bufp->chgIData(oldp+64,((0xfffff000U & vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg)),32);
        bufp->chgIData(oldp+65,(((((vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                    >> 0x1fU) ? 0xfffffU
                                    : 0U) << 0xcU) 
                                 | ((0xfe0U & (vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                               >> 0x14U)) 
                                    | (0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                                >> 7U))))),32);
        bufp->chgIData(oldp+66,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg 
                                          >> 0x14U))),32);
        bufp->chgIData(oldp+67,(VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__sram__DOT__instReg, 0x14U)),32);
        bufp->chgBit(oldp+68,((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
        bufp->chgBit(oldp+69,((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
        bufp->chgBit(oldp+70,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
        bufp->chgBit(oldp+71,((4U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
        bufp->chgBit(oldp+72,((5U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
        bufp->chgBit(oldp+73,((6U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
        bufp->chgIData(oldp+74,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0),32);
        bufp->chgIData(oldp+75,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_1),32);
        bufp->chgIData(oldp+76,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_2),32);
        bufp->chgIData(oldp+77,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_3),32);
        bufp->chgIData(oldp+78,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_4),32);
        bufp->chgIData(oldp+79,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_5),32);
        bufp->chgIData(oldp+80,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_6),32);
        bufp->chgIData(oldp+81,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_7),32);
        bufp->chgIData(oldp+82,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_8),32);
        bufp->chgIData(oldp+83,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_9),32);
        bufp->chgIData(oldp+84,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_10),32);
        bufp->chgIData(oldp+85,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_11),32);
        bufp->chgIData(oldp+86,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12),32);
        bufp->chgIData(oldp+87,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13),32);
        bufp->chgIData(oldp+88,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14),32);
        bufp->chgIData(oldp+89,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15),32);
        bufp->chgIData(oldp+90,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16),32);
        bufp->chgIData(oldp+91,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17),32);
        bufp->chgIData(oldp+92,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18),32);
        bufp->chgIData(oldp+93,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19),32);
        bufp->chgIData(oldp+94,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20),32);
        bufp->chgIData(oldp+95,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21),32);
        bufp->chgIData(oldp+96,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_22),32);
        bufp->chgIData(oldp+97,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_23),32);
        bufp->chgIData(oldp+98,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_24),32);
        bufp->chgIData(oldp+99,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_25),32);
        bufp->chgIData(oldp+100,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_26),32);
        bufp->chgIData(oldp+101,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_27),32);
        bufp->chgIData(oldp+102,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_28),32);
        bufp->chgIData(oldp+103,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_29),32);
        bufp->chgIData(oldp+104,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_30),32);
        bufp->chgIData(oldp+105,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_31),32);
        bufp->chgBit(oldp+106,((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))));
        bufp->chgBit(oldp+107,((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))));
        bufp->chgBit(oldp+108,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))));
        bufp->chgIData(oldp+109,(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__csr_data),32);
        bufp->chgQData(oldp+110,(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult),33);
        bufp->chgQData(oldp+112,(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult),33);
        bufp->chgBit(oldp+114,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                < vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)));
        bufp->chgBit(oldp+115,(VL_LTS_III(32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)));
        bufp->chgIData(oldp+116,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                  & vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
        bufp->chgIData(oldp+117,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                  | vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
        bufp->chgIData(oldp+118,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                                  ^ vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
        bufp->chgIData(oldp+119,(VL_SHIFTRS_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
        bufp->chgIData(oldp+120,(VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
        bufp->chgQData(oldp+121,((0x7fffffffffffffffULL 
                                  & ((QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1)) 
                                     << ((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))
                                          ? 0U : (0x1fU 
                                                  & vlSelfRef.ysyx_25030077_top__DOT__i5__DOT___io_data_2_T))))),63);
        bufp->chgIData(oldp+123,(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc),32);
        bufp->chgIData(oldp+124,(((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg)),32);
        bufp->chgBit(oldp+125,((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+126,((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+127,((4U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+128,((5U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+129,((6U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+130,((7U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+131,((8U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+132,((9U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+133,((0xaU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
        bufp->chgBit(oldp+134,(((0xbU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)) 
                                | (0xcU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)))));
        bufp->chgBit(oldp+135,(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql));
        bufp->chgIData(oldp+136,(((IData)(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql)
                                   ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg))),32);
        bufp->chgIData(oldp+137,(((IData)(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql)
                                   ? ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg)
                                   : vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9)),32);
    }
    bufp->chgBit(oldp+138,(vlSelfRef.clock));
    bufp->chgBit(oldp+139,(vlSelfRef.reset));
    bufp->chgIData(oldp+140,(vlSelfRef.imm),32);
    bufp->chgCData(oldp+141,(vlSelfRef.rd),5);
    bufp->chgCData(oldp+142,(vlSelfRef.ALU_ctrl),4);
    bufp->chgIData(oldp+143,(vlSelfRef.rs1_out),32);
    bufp->chgIData(oldp+144,(vlSelfRef.rs2_out),32);
    bufp->chgBit(oldp+145,(vlSelfRef.ALU_carry));
    bufp->chgBit(oldp+146,(vlSelfRef.ALU_overflow));
    bufp->chgBit(oldp+147,((0U == (IData)(vlSelfRef.rd))));
    bufp->chgSData(oldp+148,((0xffffU & ((IData)(1U) 
                                         << (IData)(vlSelfRef.ALU_ctrl)))),16);
    bufp->chgBit(oldp+149,(VL_GTES_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)));
    bufp->chgBit(oldp+150,(VL_LTS_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)));
    bufp->chgBit(oldp+151,((vlSelfRef.rs1_out >= vlSelfRef.rs2_out)));
    bufp->chgBit(oldp+152,((vlSelfRef.rs1_out < vlSelfRef.rs2_out)));
    bufp->chgIData(oldp+153,((VL_GTES_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)
                               ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                               : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg))),32);
    bufp->chgIData(oldp+154,((VL_LTS_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)
                               ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                               : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg))),32);
    bufp->chgIData(oldp+155,(((vlSelfRef.rs1_out < vlSelfRef.rs2_out)
                               ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                               : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg))),32);
    bufp->chgIData(oldp+156,(((vlSelfRef.rs1_out >= vlSelfRef.rs2_out)
                               ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                               : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i1__DOT__addr_gen__DOT__dataReg))),32);
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
