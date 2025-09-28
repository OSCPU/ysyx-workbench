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
        bufp->chgCData(oldp+7,(vlSelfRef.top__DOT__m_clint__DOT__delayCnt),3);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__c_arbiter_io_rs1_data),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__c_arbiter_io_imm),32);
        bufp->chgCData(oldp+10,(((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                  ? 1U : ((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                           ? 3U : (
                                                   (0x283U 
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
        bufp->chgCData(oldp+11,(((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                  ? 1U : ((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                           ? 3U : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))),3);
        bufp->chgBit(oldp+12,(((~ (IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)) 
                               & (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__axi_ar_valid))));
        bufp->chgIData(oldp+13,(vlSelfRef.top__DOT__c_arbiter_io_axi_ar_addr_mem),32);
        bufp->chgCData(oldp+14,(vlSelfRef.top__DOT__c_arbiter_io_axi_ar_strb_mem),3);
        bufp->chgBit(oldp+15,(((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2) 
                               & (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__axi_ar_valid))));
        bufp->chgIData(oldp+16,(((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                  ? vlSelfRef.top__DOT__c_arbiter__DOT__axi_ar_addr
                                  : 0x80000000U)),32);
        bufp->chgCData(oldp+17,(((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                  ? ((0U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                      ? 6U : ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                               ? ((0x103U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 1U
                                                   : 
                                                  ((0x83U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 3U
                                                    : 
                                                   ((0x283U 
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
                                                       : 0U)))))
                                               : 0U))
                                  : 0U)),3);
        bufp->chgBit(oldp+18,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+19,(((0xa00003f8U != vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4) 
                               & (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__axi_aw_valid))));
        bufp->chgIData(oldp+20,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                  ? 0x80000000U : vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)),32);
        bufp->chgCData(oldp+21,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                  ? 0U : ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                           ? ((0x123U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 1U
                                               : ((0x23U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 3U
                                                   : 
                                                  ((0xa3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))
                                           : 0U))),3);
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__c_arbiter_io_axi_r_valid_mem));
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg),32);
        bufp->chgBit(oldp+24,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+25,(((IData)(vlSelfRef.top__DOT__m_clint__DOT__validReg) 
                               & (0U == (IData)(vlSelfRef.top__DOT__m_clint__DOT__delayCnt)))));
        bufp->chgBit(oldp+26,(vlSelfRef.top__DOT__c_arbiter_io_gpr_r_valid));
        bufp->chgBit(oldp+27,(((2U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg)) 
                               & (IData)(vlSelfRef.top__DOT__c_arbiter_io_axi_r_valid_mem))));
        bufp->chgIData(oldp+28,(((2U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? ((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                      ? vlSelfRef.top__DOT__c_arbiter_io_axi_r_data_clint
                                      : vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg)
                                  : 0U)),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg),32);
        bufp->chgBit(oldp+30,(vlSelfRef.top__DOT__c_arbiter_io_r_valid_lsu));
        bufp->chgBit(oldp+31,(vlSelfRef.top__DOT__c_arbiter_io_is_r));
        bufp->chgCData(oldp+32,(vlSelfRef.top__DOT__d_idu_io_imm_type),3);
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__d_idu_io_rs1),5);
        bufp->chgCData(oldp+34,(vlSelfRef.top__DOT__d_idu_io_rs2),5);
        bufp->chgCData(oldp+35,(vlSelfRef.top__DOT__d_idu_io_rd),5);
        bufp->chgCData(oldp+36,(vlSelfRef.top__DOT__d_idu_io_data_control),3);
        bufp->chgCData(oldp+37,(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl),4);
        bufp->chgCData(oldp+38,(vlSelfRef.top__DOT__d_idu_io_pc_next_type),4);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__f_gpr_io_pc_next),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__f_gpr_io_wdata_rd),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__f_gpr_io_rdata_rs2),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__h_data_control_io_data_1),32);
        bufp->chgIData(oldp+43,(vlSelfRef.top__DOT__h_data_control_io_data_2),32);
        bufp->chgIData(oldp+44,(((0xa0000048U == ((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                                   ? vlSelfRef.top__DOT__c_arbiter__DOT__axi_ar_addr
                                                   : 0x80000000U))
                                  ? (IData)(vlSelfRef.top__DOT__m_clint__DOT__mem_data_Reg)
                                  : (IData)((vlSelfRef.top__DOT__m_clint__DOT__mem_data_Reg 
                                             >> 0x20U)))),32);
        bufp->chgIData(oldp+45,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                  ? 0U : ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                           ? vlSelfRef.top__DOT__f_gpr_io_rdata_rs2
                                           : 0U))),32);
        bufp->chgBit(oldp+46,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4) 
                               & (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__axi_aw_valid))));
        bufp->chgIData(oldp+47,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                  ? 0xa00003f8U : 0U)),32);
        bufp->chgIData(oldp+48,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                  ? ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                      ? vlSelfRef.top__DOT__f_gpr_io_rdata_rs2
                                      : 0U) : 0U)),32);
        bufp->chgCData(oldp+49,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                  ? ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                      ? ((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                          ? 1U : ((0x23U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 3U
                                                   : 
                                                  ((0xa3U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))
                                      : 0U) : 0U)),3);
        bufp->chgBit(oldp+50,((0x100073U == vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0]),32);
        bufp->chgBit(oldp+52,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en));
        bufp->chgBit(oldp+53,(((IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
                               & (IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
        bufp->chgCData(oldp+54,(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg),2);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__c_arbiter__DOT__axi_ar_addr),32);
        bufp->chgCData(oldp+56,(vlSelfRef.top__DOT__c_arbiter__DOT__delay_cnt),3);
        bufp->chgBit(oldp+57,(vlSelfRef.top__DOT__c_arbiter__DOT__axi_r_valid));
        bufp->chgBit(oldp+58,(((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                ? (IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_0)
                                : (IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
        bufp->chgIData(oldp+59,(((IData)(vlSelfRef.top__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                  ? vlSelfRef.top__DOT__c_arbiter_io_axi_r_data_clint
                                  : vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg)),32);
        bufp->chgBit(oldp+60,(vlSelfRef.top__DOT__c_arbiter__DOT__axi_aw_valid));
        bufp->chgBit(oldp+61,(vlSelfRef.top__DOT__c_arbiter__DOT__axi_ar_valid));
        bufp->chgCData(oldp+62,(((0U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? 6U : ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                           ? ((0x103U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 1U
                                               : ((0x83U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 3U
                                                   : 
                                                  ((0x283U 
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
                                                      : 0U)))))
                                           : 0U))),3);
        bufp->chgIData(oldp+63,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? vlSelfRef.top__DOT__f_gpr_io_rdata_rs2
                                  : 0U)),32);
        bufp->chgCData(oldp+64,(((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                  ? ((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                      ? 1U : ((0x23U 
                                               == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 3U
                                               : ((0xa3U 
                                                   == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 2U
                                                   : 0U)))
                                  : 0U)),3);
        bufp->chgCData(oldp+65,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+66,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+67,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+68,((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+69,((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+70,((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+71,((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+72,((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+73,((0x293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+74,((0x93U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+75,((0x42b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+76,((0x2b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+77,((0x63U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+78,((0xe3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+79,((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+80,((0x233U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+81,((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+82,((0x333U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+83,((0x8033U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+84,((0x37U == (0x7fU & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+85,((0x17U == (0x7fU & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+86,((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+87,((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+88,((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+89,((0x2e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+90,((0x263U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+91,((0x363U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+92,((0x3e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+93,((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+94,((0xa3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+95,((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+96,((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+97,((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+98,((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+99,((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+100,((0xb3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+101,((0x133U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+102,((0x1b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+103,((0x193U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+104,((0x113U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+105,((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+106,((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+107,((0x73U == vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgBit(oldp+108,((0x30200073U == vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__e_imm__DOT__Imm_type1),32);
        bufp->chgIData(oldp+110,((0xfffff000U & vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg)),32);
        bufp->chgIData(oldp+111,(((((vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                     >> 0x1fU) ? 0xfffffU
                                     : 0U) << 0xcU) 
                                  | ((0xfe0U & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                                >> 0x14U)) 
                                     | (0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                                 >> 7U))))),32);
        bufp->chgIData(oldp+112,((0x1fU & (vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg 
                                           >> 0x14U))),32);
        bufp->chgIData(oldp+113,(VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__c_arbiter__DOT__inst_reg, 0x14U)),32);
        bufp->chgBit(oldp+114,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+115,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+116,((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+117,((4U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+118,((5U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+119,((6U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+120,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+121,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+122,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+123,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+124,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+125,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+126,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+127,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+128,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+129,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+130,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+131,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+132,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+133,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+134,(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15));
        bufp->chgIData(oldp+135,(vlSelfRef.top__DOT__f_gpr__DOT__regs_0),32);
        bufp->chgIData(oldp+136,(vlSelfRef.top__DOT__f_gpr__DOT__regs_1),32);
        bufp->chgIData(oldp+137,(vlSelfRef.top__DOT__f_gpr__DOT__regs_2),32);
        bufp->chgIData(oldp+138,(vlSelfRef.top__DOT__f_gpr__DOT__regs_3),32);
        bufp->chgIData(oldp+139,(vlSelfRef.top__DOT__f_gpr__DOT__regs_4),32);
        bufp->chgIData(oldp+140,(vlSelfRef.top__DOT__f_gpr__DOT__regs_5),32);
        bufp->chgIData(oldp+141,(vlSelfRef.top__DOT__f_gpr__DOT__regs_6),32);
        bufp->chgIData(oldp+142,(vlSelfRef.top__DOT__f_gpr__DOT__regs_7),32);
        bufp->chgIData(oldp+143,(vlSelfRef.top__DOT__f_gpr__DOT__regs_8),32);
        bufp->chgIData(oldp+144,(vlSelfRef.top__DOT__f_gpr__DOT__regs_9),32);
        bufp->chgIData(oldp+145,(vlSelfRef.top__DOT__f_gpr__DOT__regs_10),32);
        bufp->chgIData(oldp+146,(vlSelfRef.top__DOT__f_gpr__DOT__regs_11),32);
        bufp->chgIData(oldp+147,(vlSelfRef.top__DOT__f_gpr__DOT__regs_12),32);
        bufp->chgIData(oldp+148,(vlSelfRef.top__DOT__f_gpr__DOT__regs_13),32);
        bufp->chgIData(oldp+149,(vlSelfRef.top__DOT__f_gpr__DOT__regs_14),32);
        bufp->chgIData(oldp+150,(vlSelfRef.top__DOT__f_gpr__DOT__regs_15),32);
        bufp->chgIData(oldp+151,(vlSelfRef.top__DOT__f_gpr__DOT__regs_16),32);
        bufp->chgIData(oldp+152,(vlSelfRef.top__DOT__f_gpr__DOT__regs_17),32);
        bufp->chgIData(oldp+153,(vlSelfRef.top__DOT__f_gpr__DOT__regs_18),32);
        bufp->chgIData(oldp+154,(vlSelfRef.top__DOT__f_gpr__DOT__regs_19),32);
        bufp->chgIData(oldp+155,(vlSelfRef.top__DOT__f_gpr__DOT__regs_20),32);
        bufp->chgIData(oldp+156,(vlSelfRef.top__DOT__f_gpr__DOT__regs_21),32);
        bufp->chgIData(oldp+157,(vlSelfRef.top__DOT__f_gpr__DOT__regs_22),32);
        bufp->chgIData(oldp+158,(vlSelfRef.top__DOT__f_gpr__DOT__regs_23),32);
        bufp->chgIData(oldp+159,(vlSelfRef.top__DOT__f_gpr__DOT__regs_24),32);
        bufp->chgIData(oldp+160,(vlSelfRef.top__DOT__f_gpr__DOT__regs_25),32);
        bufp->chgIData(oldp+161,(vlSelfRef.top__DOT__f_gpr__DOT__regs_26),32);
        bufp->chgIData(oldp+162,(vlSelfRef.top__DOT__f_gpr__DOT__regs_27),32);
        bufp->chgIData(oldp+163,(vlSelfRef.top__DOT__f_gpr__DOT__regs_28),32);
        bufp->chgIData(oldp+164,(vlSelfRef.top__DOT__f_gpr__DOT__regs_29),32);
        bufp->chgIData(oldp+165,(vlSelfRef.top__DOT__f_gpr__DOT__regs_30),32);
        bufp->chgIData(oldp+166,(vlSelfRef.top__DOT__f_gpr__DOT__regs_31),32);
        bufp->chgCData(oldp+167,((((((IData)(vlSelfRef.top__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7) 
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
        bufp->chgIData(oldp+168,(vlSelfRef.top__DOT__c_arbiter_io_axi_ar_strb_mem),32);
        bufp->chgIData(oldp+169,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                   ? 0U : ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                            ? ((0x123U 
                                                == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 1U
                                                : (
                                                   (0x23U 
                                                    == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 3U
                                                    : 
                                                   ((0xa3U 
                                                     == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : 0U)))
                                            : 0U))),32);
        bufp->chgIData(oldp+170,(((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0) 
                                  & ((0xa00003f8U != vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4) 
                                     & (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__axi_aw_valid)))),32);
        bufp->chgBit(oldp+171,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+172,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+173,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+174,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+175,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+176,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+177,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+178,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+179,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+180,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+181,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+182,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+183,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+184,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+185,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_15));
        bufp->chgBit(oldp+186,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0));
        bufp->chgBit(oldp+187,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1));
        bufp->chgBit(oldp+188,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2));
        bufp->chgBit(oldp+189,(vlSelfRef.top__DOT__g_mem__DOT__validReg));
        bufp->chgCData(oldp+190,((((((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7) 
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
        bufp->chgIData(oldp+191,(vlSelfRef.top__DOT__g_mem__DOT__read_data),32);
        bufp->chgBit(oldp+192,(((IData)(vlSelfRef.top__DOT__g_mem__DOT___startDelay_T) 
                                & (IData)(vlSelfRef.top__DOT__c_arbiter_io_is_r))));
        bufp->chgBit(oldp+193,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
        bufp->chgBit(oldp+194,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
        bufp->chgBit(oldp+195,((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
        bufp->chgIData(oldp+196,(vlSelfRef.top__DOT__i_alu__DOT__csr_data),32);
        bufp->chgSData(oldp+197,((0xffffU & ((IData)(1U) 
                                             << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))),16);
        bufp->chgQData(oldp+198,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                   + (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2))))),33);
        bufp->chgQData(oldp+200,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                   - (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2))))),33);
        bufp->chgIData(oldp+202,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  & vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+203,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  | vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+204,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  ^ vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+205,(VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__h_data_control_io_data_1, 
                                                (0x1fU 
                                                 & vlSelfRef.top__DOT__h_data_control_io_data_2))),32);
        bufp->chgIData(oldp+206,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                  >> (0x1fU & vlSelfRef.top__DOT__h_data_control_io_data_2))),32);
        bufp->chgQData(oldp+207,((0x7fffffffffffffffULL 
                                  & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                     << (0x1fU & vlSelfRef.top__DOT__h_data_control_io_data_2)))),63);
        bufp->chgBit(oldp+209,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                < vlSelfRef.top__DOT__h_data_control_io_data_2)));
        bufp->chgBit(oldp+210,(VL_LTS_III(32, vlSelfRef.top__DOT__h_data_control_io_data_1, vlSelfRef.top__DOT__h_data_control_io_data_2)));
        bufp->chgQData(oldp+211,(vlSelfRef.top__DOT__i_alu__DOT__out33),64);
        bufp->chgBit(oldp+213,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                                >> 0x1fU)));
        bufp->chgBit(oldp+214,((vlSelfRef.top__DOT__h_data_control_io_data_2 
                                >> 0x1fU)));
        bufp->chgBit(oldp+215,((1U & (IData)((vlSelfRef.top__DOT__i_alu__DOT__out33 
                                              >> 0x1fU)))));
        bufp->chgBit(oldp+216,(((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T))));
        bufp->chgBit(oldp+217,(((IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T) 
                                & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1))));
        bufp->chgIData(oldp+218,(vlSelfRef.top__DOT__j_pc_next__DOT__ecall_dnpc),32);
        bufp->chgIData(oldp+219,(((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)),32);
        bufp->chgBit(oldp+220,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+221,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+222,((4U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+223,((5U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+224,((6U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+225,((7U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+226,((8U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+227,((9U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+228,((0xaU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+229,(((0xbU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)) 
                                | (0xcU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)))));
        bufp->chgBit(oldp+230,(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql));
        bufp->chgBit(oldp+231,(VL_GTES_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgBit(oldp+232,(VL_LTS_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgBit(oldp+233,((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgBit(oldp+234,((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
        bufp->chgIData(oldp+235,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+236,((VL_GTES_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+237,((VL_LTS_III(32, vlSelfRef.top__DOT__c_arbiter_io_rs1_data, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+238,(((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                   < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+239,(((vlSelfRef.top__DOT__c_arbiter_io_rs1_data 
                                   >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+240,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                   ? ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)
                                   : vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9)),32);
        bufp->chgBit(oldp+241,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+242,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+243,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+244,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+245,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+246,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+247,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+248,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+249,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+250,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+251,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+252,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+253,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+254,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+255,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+256,(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_15));
        bufp->chgCData(oldp+257,((((((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.top__DOT__l_uart__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgCData(oldp+258,(((0xa00003f8U == vlSelfRef.top__DOT__c_arbiter__DOT___axi_ar_addr_T_4)
                                   ? ((1U == (IData)(vlSelfRef.top__DOT__c_arbiter__DOT__state_reg))
                                       ? (0xffU & vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                       : 0U) : 0U)),8);
        bufp->chgBit(oldp+259,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+260,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+261,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+262,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+263,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+264,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+265,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+266,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+267,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+268,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+269,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+270,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+271,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+272,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+273,(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_15));
        bufp->chgBit(oldp+274,(vlSelfRef.top__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0));
        bufp->chgBit(oldp+275,(vlSelfRef.top__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1));
        bufp->chgBit(oldp+276,(vlSelfRef.top__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2));
        bufp->chgQData(oldp+277,(vlSelfRef.top__DOT__m_clint__DOT__mem_data_Reg),64);
        bufp->chgBit(oldp+279,(vlSelfRef.top__DOT__m_clint__DOT__validReg));
        bufp->chgCData(oldp+280,((((((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.top__DOT__m_clint__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgBit(oldp+281,(((IData)(vlSelfRef.top__DOT__m_clint__DOT___startDelay_T) 
                                & (IData)(vlSelfRef.top__DOT__c_arbiter_io_is_r))));
    }
    bufp->chgBit(oldp+282,(vlSelfRef.clock));
    bufp->chgBit(oldp+283,(vlSelfRef.reset));
    bufp->chgBit(oldp+284,(vlSelfRef.io_is_unknown_instruction));
    bufp->chgBit(oldp+285,(vlSelfRef.io_carry));
    bufp->chgBit(oldp+286,(vlSelfRef.io_isoverflow));
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
