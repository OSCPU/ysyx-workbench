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
        bufp->chgBit(oldp+0,((1U & (~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)))));
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg),32);
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                               [0U]),32);
        bufp->chgCData(oldp+6,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt),3);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__c_arbiter_io_rs1_data),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__c_arbiter_io_imm),32);
        bufp->chgCData(oldp+9,(((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                 ? 1U : ((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                          ? 3U : ((0x283U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 4U
                                                   : 
                                                  ((0x203U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 5U
                                                     : 0U)))))),3);
        bufp->chgCData(oldp+10,(((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                  ? 1U : ((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                           ? 3U : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))),3);
        bufp->chgBit(oldp+11,(((0U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                ? (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)
                                : ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                                   & (IData)(vlSelfRef.top__DOT__c_arbiter_io_axi_r_valid)))));
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__c_arbiter_io_axi_ar_addr),32);
        bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__c_arbiter_io_axi_ar_strb),3);
        bufp->chgBit(oldp+14,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                               & (IData)(vlSelfRef.top__DOT__c_arbiter_io_axi_r_valid))));
        bufp->chgIData(oldp+15,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? (vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                     + vlSelfRef.top__DOT__c_arbiter_io_imm)
                                  : 0U)),32);
        bufp->chgCData(oldp+16,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? ((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                      ? 1U : ((0x23U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 3U
                                               : ((0xa3U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 2U
                                                   : 0U)))
                                  : 0U)),3);
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__c_arbiter_io_axi_r_valid));
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg),32);
        bufp->chgBit(oldp+19,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+20,(vlSelfRef.top__DOT__c_arbiter_io_gpr_r_valid));
        bufp->chgIData(oldp+21,(((2U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg
                                  : 0U)),32);
        bufp->chgIData(oldp+22,(vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg),32);
        bufp->chgBit(oldp+23,(vlSelfRef.top__DOT__c_arbiter_io_r_valid_lsu));
        bufp->chgBit(oldp+24,(((0U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                               | ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                                  & (IData)(vlSelfRef.top__DOT__c_arbiter_io_r_valid_lsu)))));
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__d_idu_io_imm_type),3);
        bufp->chgCData(oldp+26,(vlSelfRef.top__DOT__d_idu_io_rs1),5);
        bufp->chgCData(oldp+27,(vlSelfRef.top__DOT__d_idu_io_rs2),5);
        bufp->chgCData(oldp+28,(vlSelfRef.top__DOT__d_idu_io_rd),5);
        bufp->chgCData(oldp+29,(vlSelfRef.top__DOT__d_idu_io_data_control),3);
        bufp->chgCData(oldp+30,(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl),4);
        bufp->chgCData(oldp+31,(vlSelfRef.top__DOT__d_idu_io_pc_next_type),4);
        bufp->chgIData(oldp+32,(vlSelfRef.top__DOT__f_gpr_io_pc_next),32);
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__f_gpr_io_wdata_rd),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__f_gpr_io_rdata_rs2),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__h_data_control_io_data_1),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__h_data_control_io_data_2),32);
        bufp->chgIData(oldp+37,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? vlSelfRef.top__DOT__f_gpr_io_rdata_rs2
                                  : 0U)),32);
        bufp->chgBit(oldp+38,(vlSelfRef.top__DOT__is_break_out_o));
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0]),32);
        bufp->chgBit(oldp+40,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en));
        bufp->chgBit(oldp+41,(((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
                               & (IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
        bufp->chgCData(oldp+42,(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg),2);
        bufp->chgCData(oldp+43,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+44,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+45,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+46,((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+47,((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+48,((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+49,((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+50,((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+51,((0x293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+52,((0x93U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+53,((0x42b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+54,((0x2b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+55,((0x63U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+56,((0xe3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+57,((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+58,((0x233U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+59,((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+60,((0x333U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+61,((0x8033U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+62,((0x37U == (0x7fU & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+63,((0x17U == (0x7fU & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+64,((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+65,((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+66,((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+67,((0x2e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+68,((0x263U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+69,((0x363U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+70,((0x3e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+71,((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+72,((0xa3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+73,((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+74,((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+75,((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+76,((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+77,((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+78,((0xb3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+79,((0x133U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+80,((0x1b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+81,((0x193U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+82,((0x113U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+83,((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+84,((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+85,((0x100073U == vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgBit(oldp+86,((0x73U == vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgBit(oldp+87,((0x30200073U == vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgIData(oldp+88,(vlSelfRef.top__DOT__e_imm__DOT__Imm_type1),32);
        bufp->chgIData(oldp+89,((0xfffff000U & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)),32);
        bufp->chgIData(oldp+90,(((((vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                    >> 0x1fU) ? 0xfffffU
                                    : 0U) << 0xcU) 
                                 | ((0xfe0U & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                               >> 0x14U)) 
                                    | (0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                                >> 7U))))),32);
        bufp->chgIData(oldp+91,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0x14U))),32);
        bufp->chgIData(oldp+92,(VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg, 0x14U)),32);
        bufp->chgBit(oldp+93,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+94,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+95,((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+96,((4U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+97,((5U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+98,((6U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+99,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+100,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+101,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+102,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+103,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+104,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+105,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+106,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+107,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+108,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+109,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+110,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+111,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+112,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+113,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15));
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__f_gpr__DOT__regs_0),32);
        bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__f_gpr__DOT__regs_1),32);
        bufp->chgIData(oldp+116,(vlSelfRef.top__DOT__f_gpr__DOT__regs_2),32);
        bufp->chgIData(oldp+117,(vlSelfRef.top__DOT__f_gpr__DOT__regs_3),32);
        bufp->chgIData(oldp+118,(vlSelfRef.top__DOT__f_gpr__DOT__regs_4),32);
        bufp->chgIData(oldp+119,(vlSelfRef.top__DOT__f_gpr__DOT__regs_5),32);
        bufp->chgIData(oldp+120,(vlSelfRef.top__DOT__f_gpr__DOT__regs_6),32);
        bufp->chgIData(oldp+121,(vlSelfRef.top__DOT__f_gpr__DOT__regs_7),32);
        bufp->chgIData(oldp+122,(vlSelfRef.top__DOT__f_gpr__DOT__regs_8),32);
        bufp->chgIData(oldp+123,(vlSelfRef.top__DOT__f_gpr__DOT__regs_9),32);
        bufp->chgIData(oldp+124,(vlSelfRef.top__DOT__f_gpr__DOT__regs_10),32);
        bufp->chgIData(oldp+125,(vlSelfRef.top__DOT__f_gpr__DOT__regs_11),32);
        bufp->chgIData(oldp+126,(vlSelfRef.top__DOT__f_gpr__DOT__regs_12),32);
        bufp->chgIData(oldp+127,(vlSelfRef.top__DOT__f_gpr__DOT__regs_13),32);
        bufp->chgIData(oldp+128,(vlSelfRef.top__DOT__f_gpr__DOT__regs_14),32);
        bufp->chgIData(oldp+129,(vlSelfRef.top__DOT__f_gpr__DOT__regs_15),32);
        bufp->chgIData(oldp+130,(vlSelfRef.top__DOT__f_gpr__DOT__regs_16),32);
        bufp->chgIData(oldp+131,(vlSelfRef.top__DOT__f_gpr__DOT__regs_17),32);
        bufp->chgIData(oldp+132,(vlSelfRef.top__DOT__f_gpr__DOT__regs_18),32);
        bufp->chgIData(oldp+133,(vlSelfRef.top__DOT__f_gpr__DOT__regs_19),32);
        bufp->chgIData(oldp+134,(vlSelfRef.top__DOT__f_gpr__DOT__regs_20),32);
        bufp->chgIData(oldp+135,(vlSelfRef.top__DOT__f_gpr__DOT__regs_21),32);
        bufp->chgIData(oldp+136,(vlSelfRef.top__DOT__f_gpr__DOT__regs_22),32);
        bufp->chgIData(oldp+137,(vlSelfRef.top__DOT__f_gpr__DOT__regs_23),32);
        bufp->chgIData(oldp+138,(vlSelfRef.top__DOT__f_gpr__DOT__regs_24),32);
        bufp->chgIData(oldp+139,(vlSelfRef.top__DOT__f_gpr__DOT__regs_25),32);
        bufp->chgIData(oldp+140,(vlSelfRef.top__DOT__f_gpr__DOT__regs_26),32);
        bufp->chgIData(oldp+141,(vlSelfRef.top__DOT__f_gpr__DOT__regs_27),32);
        bufp->chgIData(oldp+142,(vlSelfRef.top__DOT__f_gpr__DOT__regs_28),32);
        bufp->chgIData(oldp+143,(vlSelfRef.top__DOT__f_gpr__DOT__regs_29),32);
        bufp->chgIData(oldp+144,(vlSelfRef.top__DOT__f_gpr__DOT__regs_30),32);
        bufp->chgIData(oldp+145,(vlSelfRef.top__DOT__f_gpr__DOT__regs_31),32);
        bufp->chgCData(oldp+146,((((((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgIData(oldp+147,(vlSelfRef.top__DOT__c_arbiter_io_axi_ar_strb),32);
        bufp->chgIData(oldp+148,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                   ? ((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                       ? 1U : ((0x23U 
                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 3U
                                                : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))
                                   : 0U)),32);
        bufp->chgIData(oldp+149,(vlSelfRef.top__DOT__g_mem__DOT___startDelay_T),32);
        bufp->chgBit(oldp+150,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+151,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+152,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+153,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+154,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+155,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+156,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+157,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+158,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+159,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+160,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+161,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+162,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+163,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+164,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_15));
        bufp->chgBit(oldp+165,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0));
        bufp->chgBit(oldp+166,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1));
        bufp->chgBit(oldp+167,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2));
        bufp->chgBit(oldp+168,(vlSelfRef.top__DOT__g_mem__DOT__validReg));
        bufp->chgCData(oldp+169,((((((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgIData(oldp+170,(vlSelfRef.top__DOT__g_mem__DOT__read_data),32);
        bufp->chgBit(oldp+171,(((IData)(vlSelfRef.top__DOT__g_mem__DOT___startDelay_T) 
                                & ((0U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                                   | ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                                      & (IData)(vlSelfRef.top__DOT__c_arbiter_io_r_valid_lsu))))));
        bufp->chgBit(oldp+172,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
        bufp->chgBit(oldp+173,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
        bufp->chgBit(oldp+174,((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
        bufp->chgIData(oldp+175,(vlSelfRef.top__DOT__i_alu__DOT__csr_data),32);
        bufp->chgSData(oldp+176,((0xffffU & ((IData)(1U) 
                                             << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))),16);
        bufp->chgQData(oldp+177,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                   + (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2))))),33);
        bufp->chgQData(oldp+179,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                   - (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2))))),33);
        bufp->chgIData(oldp+181,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  & vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+182,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  | vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+183,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  ^ vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+184,(VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__h_data_control_io_data_1, 
                                                (0x1fU 
                                                 & vlSelfRef.top__DOT__h_data_control_io_data_2))),32);
        bufp->chgIData(oldp+185,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  >> (0x1fU & vlSelfRef.top__DOT__h_data_control_io_data_2))),32);
        bufp->chgQData(oldp+186,((0x7fffffffffffffffULL 
                                  & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                     << (0x1fU & vlSelfRef.top__DOT__h_data_control_io_data_2)))),63);
        bufp->chgBit(oldp+188,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                < vlSelfRef.top__DOT__h_data_control_io_data_2)));
        bufp->chgBit(oldp+189,(VL_LTS_III(32, vlSelfRef.top__DOT__h_data_control_io_data_1, vlSelfRef.top__DOT__h_data_control_io_data_2)));
        bufp->chgQData(oldp+190,(vlSelfRef.top__DOT__i_alu__DOT__out33),64);
        bufp->chgBit(oldp+192,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                >> 0x1fU)));
        bufp->chgBit(oldp+193,((vlSelfRef.top__DOT__h_data_control_io_data_2 
                                >> 0x1fU)));
        bufp->chgBit(oldp+194,((1U & (IData)((vlSelfRef.top__DOT__i_alu__DOT__out33 
                                              >> 0x1fU)))));
        bufp->chgBit(oldp+195,(((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T))));
        bufp->chgBit(oldp+196,(((IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T) 
                                & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1))));
        bufp->chgIData(oldp+197,(vlSelfRef.top__DOT__j_pc_next__DOT__ecall_dnpc),32);
        bufp->chgIData(oldp+198,(((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)),32);
        bufp->chgBit(oldp+199,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+200,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+201,((4U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+202,((5U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+203,((6U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+204,((7U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+205,((8U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+206,((9U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+207,((0xaU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+208,(((0xbU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)) 
                                | (0xcU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)))));
        bufp->chgBit(oldp+209,(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql));
        bufp->chgBit(oldp+210,(VL_GTES_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgBit(oldp+211,(VL_LTS_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgBit(oldp+212,((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgBit(oldp+213,((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgIData(oldp+214,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+215,((VL_GTES_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+216,((VL_LTS_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+217,(((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                   < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+218,(((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                   >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+219,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                   ? ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)
                                   : vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9)),32);
    }
    bufp->chgBit(oldp+220,(vlSelfRef.clock));
    bufp->chgBit(oldp+221,(vlSelfRef.reset));
    bufp->chgBit(oldp+222,(vlSelfRef.io_is_unknown_instruction));
    bufp->chgBit(oldp+223,(vlSelfRef.io_carry));
    bufp->chgBit(oldp+224,(vlSelfRef.io_isoverflow));
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
