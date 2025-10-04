// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_25030077__Syms.h"


void Vysyx_25030077___024root__trace_chg_0_sub_0(Vysyx_25030077___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vysyx_25030077___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_chg_0\n"); );
    // Init
    Vysyx_25030077___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25030077___024root*>(voidSelf);
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_25030077___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_25030077___024root__trace_chg_0_sub_0(Vysyx_25030077___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_chg_0_sub_0\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,((1U & (~ (IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)))));
        bufp->chgBit(oldp+1,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg));
        bufp->chgIData(oldp+2,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg),32);
        bufp->chgBit(oldp+3,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+4,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
        bufp->chgIData(oldp+5,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                               [0U]),32);
        bufp->chgCData(oldp+6,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt),3);
        bufp->chgCData(oldp+7,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt),3);
        bufp->chgIData(oldp+8,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data),32);
        bufp->chgIData(oldp+9,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data),32);
        bufp->chgIData(oldp+10,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_imm),32);
        bufp->chgCData(oldp+11,(((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                  ? 1U : ((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                           ? 3U : (
                                                   (0x283U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 4U
                                                    : 
                                                   ((0x203U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 5U
                                                      : 0U)))))),3);
        bufp->chgCData(oldp+12,(((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                  ? 1U : ((0x23U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                           ? 3U : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))),3);
        bufp->chgBit(oldp+13,(((~ (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)) 
                               & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid))));
        bufp->chgIData(oldp+14,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem),32);
        bufp->chgCData(oldp+15,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem),3);
        bufp->chgBit(oldp+16,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2) 
                               & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid))));
        bufp->chgIData(oldp+17,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                  ? vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr
                                  : 0x80000000U)),32);
        bufp->chgCData(oldp+18,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                  ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                      ? 6U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                               ? ((0x103U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 1U
                                                   : 
                                                  ((0x83U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 3U
                                                    : 
                                                   ((0x283U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 4U
                                                     : 
                                                    ((0x203U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 2U
                                                      : 
                                                     ((3U 
                                                       == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                       ? 5U
                                                       : 0U)))))
                                               : 0U))
                                  : 0U)),3);
        bufp->chgBit(oldp+19,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+20,(((0xa00003f8U != vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                               & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid))));
        bufp->chgIData(oldp+21,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                  ? 0U : vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)),32);
        bufp->chgIData(oldp+22,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                  ? 0U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                           ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                                           : 0U))),32);
        bufp->chgCData(oldp+23,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                  ? 0U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                           ? ((0x123U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 1U
                                               : ((0x23U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 3U
                                                   : 
                                                  ((0xa3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))
                                           : 0U))),3);
        bufp->chgBit(oldp+24,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                               & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid))));
        bufp->chgIData(oldp+25,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                  ? 0xa00003f8U : 0U)),32);
        bufp->chgBit(oldp+26,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0));
        bufp->chgIData(oldp+27,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                  ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                      ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                                      : 0U) : 0U)),32);
        bufp->chgCData(oldp+28,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                  ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                      ? ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                          ? 1U : ((0x23U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 3U
                                                   : 
                                                  ((0xa3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))
                                      : 0U) : 0U)),3);
        bufp->chgBit(oldp+29,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem));
        bufp->chgIData(oldp+30,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg),32);
        bufp->chgBit(oldp+31,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0));
        bufp->chgBit(oldp+32,(((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg) 
                               & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt)))));
        bufp->chgIData(oldp+33,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint),32);
        bufp->chgBit(oldp+34,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid));
        bufp->chgBit(oldp+35,(((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)) 
                               & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem))));
        bufp->chgIData(oldp+36,(((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                  ? ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                      ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint
                                      : vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg)
                                  : 0U)),32);
        bufp->chgIData(oldp+37,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg),32);
        bufp->chgBit(oldp+38,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu));
        bufp->chgBit(oldp+39,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r));
        bufp->chgCData(oldp+40,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type),3);
        bufp->chgCData(oldp+41,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1),5);
        bufp->chgCData(oldp+42,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2),5);
        bufp->chgCData(oldp+43,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd),5);
        bufp->chgCData(oldp+44,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control),3);
        bufp->chgCData(oldp+45,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl),4);
        bufp->chgCData(oldp+46,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type),4);
        bufp->chgIData(oldp+47,(vlSelfRef.ysyx_25030077__DOT__f_gpr_io_pc_next),32);
        bufp->chgIData(oldp+48,(vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd),32);
        bufp->chgIData(oldp+49,(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1),32);
        bufp->chgIData(oldp+50,(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2),32);
        bufp->chgIData(oldp+51,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0]),32);
        bufp->chgBit(oldp+52,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en));
        bufp->chgBit(oldp+53,(((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
                               & (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
        bufp->chgCData(oldp+54,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg),2);
        bufp->chgIData(oldp+55,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr),32);
        bufp->chgCData(oldp+56,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt),3);
        bufp->chgBit(oldp+57,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid));
        bufp->chgBit(oldp+58,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                ? (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0)
                                : (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
        bufp->chgIData(oldp+59,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                  ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint
                                  : vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg)),32);
        bufp->chgIData(oldp+60,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr),32);
        bufp->chgBit(oldp+61,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid));
        bufp->chgBit(oldp+62,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid));
        bufp->chgCData(oldp+63,(((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                  ? 6U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                           ? ((0x103U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 1U
                                               : ((0x83U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 3U
                                                   : 
                                                  ((0x283U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 4U
                                                    : 
                                                   ((0x203U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                      ? 5U
                                                      : 0U)))))
                                           : 0U))),3);
        bufp->chgIData(oldp+64,(((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                  ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                                  : 0U)),32);
        bufp->chgCData(oldp+65,(((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                  ? ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                      ? 1U : ((0x23U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 3U
                                               : ((0xa3U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 2U
                                                   : 0U)))
                                  : 0U)),3);
        bufp->chgCData(oldp+66,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+67,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+68,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+69,((0x13U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+70,((0x213U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+71,((0x313U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+72,((0x393U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+73,((0x4293U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+74,((0x293U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+75,((0x93U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+76,((0x42b3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+77,((0x2b3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+78,((0x63U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+79,((0xe3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+80,((0x33U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+81,((0x233U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+82,((0x3b3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+83,((0x333U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+84,((0x8033U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+85,((0x37U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+86,((0x17U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+87,((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))));
        bufp->chgBit(oldp+88,((0x67U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+89,((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+90,((0x2e3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+91,((0x263U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+92,((0x363U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+93,((0x3e3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+94,((0x23U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+95,((0xa3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+96,((0x203U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+97,((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+98,((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+99,((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+100,((0x283U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+101,((0xb3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+102,((0x133U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+103,((0x1b3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+104,((0x193U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+105,((0x113U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+106,((0xf3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+107,((0x173U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+108,((0x100073U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgBit(oldp+109,((0x73U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgBit(oldp+110,((0x30200073U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)));
        bufp->chgIData(oldp+111,(vlSelfRef.ysyx_25030077__DOT__e_imm__DOT__Imm_type1),32);
        bufp->chgIData(oldp+112,((0xfffff000U & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)),32);
        bufp->chgIData(oldp+113,(((((vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                     >> 0x1fU) ? 0xfffffU
                                     : 0U) << 0xcU) 
                                  | ((0xfe0U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                >> 0x14U)) 
                                     | (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                                 >> 7U))))),32);
        bufp->chgIData(oldp+114,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                           >> 0x14U))),32);
        bufp->chgIData(oldp+115,(VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg, 0x14U)),32);
        bufp->chgBit(oldp+116,((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+117,((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+118,((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+119,((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+120,((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+121,((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
        bufp->chgBit(oldp+122,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+123,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+124,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+125,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+126,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+127,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+128,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+129,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+130,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+131,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+132,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+133,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+134,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+135,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+136,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15));
        bufp->chgIData(oldp+137,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0),32);
        bufp->chgIData(oldp+138,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1),32);
        bufp->chgIData(oldp+139,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2),32);
        bufp->chgIData(oldp+140,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3),32);
        bufp->chgIData(oldp+141,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4),32);
        bufp->chgIData(oldp+142,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5),32);
        bufp->chgIData(oldp+143,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6),32);
        bufp->chgIData(oldp+144,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7),32);
        bufp->chgIData(oldp+145,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8),32);
        bufp->chgIData(oldp+146,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9),32);
        bufp->chgIData(oldp+147,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10),32);
        bufp->chgIData(oldp+148,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11),32);
        bufp->chgIData(oldp+149,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12),32);
        bufp->chgIData(oldp+150,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13),32);
        bufp->chgIData(oldp+151,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14),32);
        bufp->chgIData(oldp+152,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15),32);
        bufp->chgIData(oldp+153,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16),32);
        bufp->chgIData(oldp+154,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17),32);
        bufp->chgIData(oldp+155,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18),32);
        bufp->chgIData(oldp+156,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19),32);
        bufp->chgIData(oldp+157,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20),32);
        bufp->chgIData(oldp+158,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21),32);
        bufp->chgIData(oldp+159,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22),32);
        bufp->chgIData(oldp+160,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23),32);
        bufp->chgIData(oldp+161,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24),32);
        bufp->chgIData(oldp+162,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25),32);
        bufp->chgIData(oldp+163,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26),32);
        bufp->chgIData(oldp+164,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27),32);
        bufp->chgIData(oldp+165,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28),32);
        bufp->chgIData(oldp+166,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29),32);
        bufp->chgIData(oldp+167,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30),32);
        bufp->chgIData(oldp+168,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31),32);
        bufp->chgCData(oldp+169,((((((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgIData(oldp+170,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem),32);
        bufp->chgIData(oldp+171,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                   ? 0U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                            ? ((0x123U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 1U
                                                : (
                                                   (0x23U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 3U
                                                    : 
                                                   ((0xa3U 
                                                     == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                     ? 2U
                                                     : 0U)))
                                            : 0U))),32);
        bufp->chgIData(oldp+172,(((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0) 
                                  & ((0xa00003f8U != vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                                     & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid)))),32);
        bufp->chgBit(oldp+173,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+174,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+175,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+176,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+177,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+178,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+179,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+180,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+181,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+182,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+183,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+184,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+185,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+186,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+187,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_15));
        bufp->chgBit(oldp+188,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0));
        bufp->chgBit(oldp+189,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1));
        bufp->chgBit(oldp+190,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2));
        bufp->chgBit(oldp+191,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__validReg));
        bufp->chgCData(oldp+192,((((((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgIData(oldp+193,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__read_data),32);
        bufp->chgBit(oldp+194,(((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T) 
                                & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r))));
        bufp->chgBit(oldp+195,((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))));
        bufp->chgBit(oldp+196,((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))));
        bufp->chgBit(oldp+197,((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))));
        bufp->chgIData(oldp+198,(vlSelfRef.ysyx_25030077__DOT__i_alu__DOT__csr_data),32);
        bufp->chgSData(oldp+199,((0xffffU & ((IData)(1U) 
                                             << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))),16);
        bufp->chgQData(oldp+200,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                   + (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))),33);
        bufp->chgQData(oldp+202,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                   - (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))),33);
        bufp->chgIData(oldp+204,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                  & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+205,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                  | vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+206,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                  ^ vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)),32);
        bufp->chgIData(oldp+207,(VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, 
                                                (0x1fU 
                                                 & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))),32);
        bufp->chgIData(oldp+208,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                  >> (0x1fU & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))),32);
        bufp->chgQData(oldp+209,((0x7fffffffffffffffULL 
                                  & ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                     << (0x1fU & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))),63);
        bufp->chgBit(oldp+211,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                < vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)));
        bufp->chgBit(oldp+212,(VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)));
        bufp->chgQData(oldp+213,(((((0x1ffffffffULL 
                                     & ((((((((1U & 
                                               ((IData)(1U) 
                                                << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                               ? ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                                  + (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                               : 0ULL) 
                                             | ((2U 
                                                 & ((IData)(1U) 
                                                    << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                 ? 
                                                ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                                 - (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                 : 0ULL)) 
                                            | ((4U 
                                                & ((IData)(1U) 
                                                   << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                ? (QData)((IData)(
                                                                  (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                   < vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                : 0ULL)) 
                                           | ((8U & 
                                               ((IData)(1U) 
                                                << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                               ? (QData)((IData)(
                                                                 (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                  | vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                               : 0ULL)) 
                                          | ((0x10U 
                                              & ((IData)(1U) 
                                                 << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                              ? (QData)((IData)(
                                                                (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                 ^ vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                              : 0ULL)) 
                                         | ((0x20U 
                                             & ((IData)(1U) 
                                                << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                             ? (QData)((IData)(
                                                               VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, 
                                                                              (0x1fU 
                                                                               & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))
                                             : 0ULL)) 
                                        | ((0x40U & 
                                            ((IData)(1U) 
                                             << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                            ? (QData)((IData)(
                                                              (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                               & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                            : 0ULL))) 
                                    | ((0x100U & ((IData)(1U) 
                                                  << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                        ? (0x7fffffffffffffffULL 
                                           & ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                              << (0x1fU 
                                                  & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                        : 0ULL)) | 
                                   ((0x200U & ((IData)(1U) 
                                               << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                     ? (QData)((IData)(
                                                       (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                        >> 
                                                        (0x1fU 
                                                         & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))
                                     : 0ULL)) | ((0x400U 
                                                  & ((IData)(1U) 
                                                     << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                  ? (QData)((IData)(
                                                                    VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                                  : 0ULL))),64);
        bufp->chgIData(oldp+215,(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__ecall_dnpc),32);
        bufp->chgIData(oldp+216,(((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg)),32);
        bufp->chgBit(oldp+217,((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+218,((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+219,((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+220,((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+221,((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+222,((7U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+223,((8U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+224,((9U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+225,((0xaU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
        bufp->chgBit(oldp+226,(((0xbU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type)) 
                                | (0xcU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type)))));
        bufp->chgBit(oldp+227,(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql));
        bufp->chgBit(oldp+228,(VL_GTES_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
        bufp->chgBit(oldp+229,(VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
        bufp->chgBit(oldp+230,((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                >= vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
        bufp->chgBit(oldp+231,((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                < vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
        bufp->chgIData(oldp+232,(((IData)(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql)
                                   ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+233,((VL_GTES_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                   ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+234,((VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                   ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+235,(((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                   < vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                   ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+236,(((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                   >= vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                   ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
        bufp->chgIData(oldp+237,(((IData)(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql)
                                   ? ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg)
                                   : vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9)),32);
        bufp->chgBit(oldp+238,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+239,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+240,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+241,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+242,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+243,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+244,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+245,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+246,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+247,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+248,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+249,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+250,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+251,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+252,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_15));
        bufp->chgCData(oldp+253,((((((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgCData(oldp+254,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                   ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                       ? (0xffU & vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                       : 0U) : 0U)),8);
        bufp->chgBit(oldp+255,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1));
        bufp->chgBit(oldp+256,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2));
        bufp->chgBit(oldp+257,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3));
        bufp->chgBit(oldp+258,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4));
        bufp->chgBit(oldp+259,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5));
        bufp->chgBit(oldp+260,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6));
        bufp->chgBit(oldp+261,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7));
        bufp->chgBit(oldp+262,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_8));
        bufp->chgBit(oldp+263,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_9));
        bufp->chgBit(oldp+264,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10));
        bufp->chgBit(oldp+265,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_11));
        bufp->chgBit(oldp+266,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12));
        bufp->chgBit(oldp+267,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13));
        bufp->chgBit(oldp+268,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_14));
        bufp->chgBit(oldp+269,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_15));
        bufp->chgBit(oldp+270,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0));
        bufp->chgBit(oldp+271,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1));
        bufp->chgBit(oldp+272,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2));
        bufp->chgQData(oldp+273,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg),64);
        bufp->chgBit(oldp+275,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg));
        bufp->chgCData(oldp+276,((((((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7) 
                                     << 7U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6) 
                                               << 6U)) 
                                   | (((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5) 
                                       << 5U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4) 
                                                 << 4U))) 
                                  | ((((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3) 
                                       << 3U) | ((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2) 
                                                 << 2U)) 
                                     | (((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1) 
                                         << 1U) | (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0))))),8);
        bufp->chgBit(oldp+277,(((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T) 
                                & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r))));
    }
    bufp->chgBit(oldp+278,(vlSelfRef.clock));
    bufp->chgBit(oldp+279,(vlSelfRef.reset));
    bufp->chgBit(oldp+280,(vlSelfRef.io_is_unknown_instruction));
}

void Vysyx_25030077___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_cleanup\n"); );
    // Init
    Vysyx_25030077___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25030077___024root*>(voidSelf);
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
