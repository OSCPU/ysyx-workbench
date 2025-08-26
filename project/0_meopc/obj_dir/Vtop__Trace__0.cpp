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
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__j_pc_next__DOT__validReg));
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__j_pc_next__DOT__pc_next_reg),32);
        bufp->chgBit(oldp+3,(vlSelfRef.top__DOT__b_ifu_io_sramReq_ready));
        bufp->chgBit(oldp+4,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
        bufp->chgIData(oldp+5,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                               [0U]),32);
        bufp->chgBit(oldp+6,(vlSelfRef.top__DOT__c_sram_io_iduReq_ready));
        bufp->chgBit(oldp+7,(vlSelfRef.top__DOT__c_sram__DOT__validReg));
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__c_sram__DOT__instReg),32);
        bufp->chgIData(oldp+9,(vlSelfRef.top__DOT__c_sram__DOT__pcReg),32);
        bufp->chgCData(oldp+10,(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o),3);
        bufp->chgCData(oldp+11,(vlSelfRef.top__DOT__d_idu__DOT__rs1_reg_o),5);
        bufp->chgCData(oldp+12,(vlSelfRef.top__DOT__d_idu__DOT__rs2_reg_o),5);
        bufp->chgCData(oldp+13,(vlSelfRef.top__DOT__d_idu__DOT__rd_reg_o),5);
        bufp->chgBit(oldp+14,(vlSelfRef.top__DOT__d_idu_io_ready));
        bufp->chgBit(oldp+15,(vlSelfRef.top__DOT__d_idu__DOT__validReg));
        bufp->chgCData(oldp+16,(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o),3);
        bufp->chgCData(oldp+17,(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o),4);
        bufp->chgCData(oldp+18,(vlSelfRef.top__DOT__d_idu__DOT__pc_next_type_reg_o),4);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__d_idu__DOT__inst_reg),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__d_idu__DOT__pc_reg),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__e_imm_io_imm),32);
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__f_gpr_io_rd_Req_ready));
        bufp->chgBit(oldp+23,(vlSelfRef.top__DOT__i_alu__DOT__validReg));
        bufp->chgCData(oldp+24,(vlSelfRef.top__DOT__i_alu__DOT__rd_addr_reg),5);
        bufp->chgIData(oldp+25,(vlSelfRef.top__DOT__i_alu__DOT__out_reg),32);
        bufp->chgIData(oldp+26,(vlSelfRef.top__DOT__i_alu__DOT__rs1_data_reg),32);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__i_alu__DOT__rs2_data_reg),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__i_alu__DOT__instruction_reg),32);
        bufp->chgCData(oldp+29,(vlSelfRef.top__DOT__i_alu__DOT__pc_next_type_reg),4);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__i_alu__DOT__pc_count_reg),32);
        bufp->chgBit(oldp+31,(vlSelfRef.top__DOT__f_gpr_io_pcnext_Req_ready));
        bufp->chgBit(oldp+32,(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
        bufp->chgIData(oldp+33,(vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg),32);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__f_gpr__DOT__instruction_reg),32);
        bufp->chgCData(oldp+36,(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg),4);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg),32);
        bufp->chgIData(oldp+38,(vlSelfRef.top__DOT__f_gpr_io_rdata_rs1),32);
        bufp->chgIData(oldp+39,(vlSelfRef.top__DOT__f_gpr_io_rdata_rs2),32);
        bufp->chgIData(oldp+40,(vlSelfRef.top__DOT__g_mem_io_mem_data),32);
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1),32);
        bufp->chgIData(oldp+42,(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2),32);
        bufp->chgBit(oldp+43,(vlSelfRef.top__DOT__j_pc_next__DOT__is_unknown_instruction_reg));
        bufp->chgBit(oldp+44,(vlSelfRef.top__DOT__is_break_out_o));
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0]),32);
        bufp->chgBit(oldp+46,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en));
        bufp->chgBit(oldp+47,(((IData)(vlSelfRef.top__DOT__b_ifu_io_sramReq_ready) 
                               & (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full))));
        bufp->chgCData(oldp+48,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+49,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                          >> 7U))),5);
        bufp->chgCData(oldp+50,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+51,((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+52,((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+53,((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+54,((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+55,((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+56,((0x293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+57,((0x93U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+58,((0x42b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+59,((0x2b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
        bufp->chgBit(oldp+60,((0x63U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+61,((0xe3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+62,((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+63,((0x233U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+64,((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+65,((0x333U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+66,((0x8033U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+67,((0x37U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))));
        bufp->chgBit(oldp+68,((0x17U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))));
        bufp->chgBit(oldp+69,((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))));
        bufp->chgBit(oldp+70,((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+71,((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+72,((0x2e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+73,((0x263U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+74,((0x363U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+75,((0x3e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+76,((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+77,((0xa3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+78,((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+79,((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+80,((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+81,((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+82,((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+83,((0xb3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+84,((0x133U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+85,((0x1b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
        bufp->chgBit(oldp+86,((0x193U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+87,((0x113U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+88,((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+89,((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
        bufp->chgBit(oldp+90,((0x100073U == vlSelfRef.top__DOT__c_sram__DOT__instReg)));
        bufp->chgBit(oldp+91,((0x73U == vlSelfRef.top__DOT__c_sram__DOT__instReg)));
        bufp->chgBit(oldp+92,((0x30200073U == vlSelfRef.top__DOT__c_sram__DOT__instReg)));
        bufp->chgCData(oldp+93,(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg),5);
        bufp->chgIData(oldp+94,(((((vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                    >> 0x1fU) ? 0xfffffU
                                    : 0U) << 0xcU) 
                                 | (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                    >> 0x14U))),32);
        bufp->chgIData(oldp+95,((0xfffff000U & vlSelfRef.top__DOT__d_idu__DOT__inst_reg)),32);
        bufp->chgIData(oldp+96,(((((vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                    >> 0x1fU) ? 0xfffffU
                                    : 0U) << 0xcU) 
                                 | ((0xfe0U & (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                               >> 0x14U)) 
                                    | (0x1fU & (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                                >> 7U))))),32);
        bufp->chgIData(oldp+97,((0x1fU & (vlSelfRef.top__DOT__d_idu__DOT__inst_reg 
                                          >> 0x14U))),32);
        bufp->chgIData(oldp+98,(VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__d_idu__DOT__inst_reg, 0x14U)),32);
        bufp->chgBit(oldp+99,((1U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))));
        bufp->chgBit(oldp+100,((2U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))));
        bufp->chgBit(oldp+101,((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))));
        bufp->chgBit(oldp+102,((4U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))));
        bufp->chgBit(oldp+103,((5U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))));
        bufp->chgBit(oldp+104,((6U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__imm_type_reg_o))));
        bufp->chgIData(oldp+105,(vlSelfRef.top__DOT__f_gpr__DOT__regs_0),32);
        bufp->chgIData(oldp+106,(vlSelfRef.top__DOT__f_gpr__DOT__regs_1),32);
        bufp->chgIData(oldp+107,(vlSelfRef.top__DOT__f_gpr__DOT__regs_2),32);
        bufp->chgIData(oldp+108,(vlSelfRef.top__DOT__f_gpr__DOT__regs_3),32);
        bufp->chgIData(oldp+109,(vlSelfRef.top__DOT__f_gpr__DOT__regs_4),32);
        bufp->chgIData(oldp+110,(vlSelfRef.top__DOT__f_gpr__DOT__regs_5),32);
        bufp->chgIData(oldp+111,(vlSelfRef.top__DOT__f_gpr__DOT__regs_6),32);
        bufp->chgIData(oldp+112,(vlSelfRef.top__DOT__f_gpr__DOT__regs_7),32);
        bufp->chgIData(oldp+113,(vlSelfRef.top__DOT__f_gpr__DOT__regs_8),32);
        bufp->chgIData(oldp+114,(vlSelfRef.top__DOT__f_gpr__DOT__regs_9),32);
        bufp->chgIData(oldp+115,(vlSelfRef.top__DOT__f_gpr__DOT__regs_10),32);
        bufp->chgIData(oldp+116,(vlSelfRef.top__DOT__f_gpr__DOT__regs_11),32);
        bufp->chgIData(oldp+117,(vlSelfRef.top__DOT__f_gpr__DOT__regs_12),32);
        bufp->chgIData(oldp+118,(vlSelfRef.top__DOT__f_gpr__DOT__regs_13),32);
        bufp->chgIData(oldp+119,(vlSelfRef.top__DOT__f_gpr__DOT__regs_14),32);
        bufp->chgIData(oldp+120,(vlSelfRef.top__DOT__f_gpr__DOT__regs_15),32);
        bufp->chgIData(oldp+121,(vlSelfRef.top__DOT__f_gpr__DOT__regs_16),32);
        bufp->chgIData(oldp+122,(vlSelfRef.top__DOT__f_gpr__DOT__regs_17),32);
        bufp->chgIData(oldp+123,(vlSelfRef.top__DOT__f_gpr__DOT__regs_18),32);
        bufp->chgIData(oldp+124,(vlSelfRef.top__DOT__f_gpr__DOT__regs_19),32);
        bufp->chgIData(oldp+125,(vlSelfRef.top__DOT__f_gpr__DOT__regs_20),32);
        bufp->chgIData(oldp+126,(vlSelfRef.top__DOT__f_gpr__DOT__regs_21),32);
        bufp->chgIData(oldp+127,(vlSelfRef.top__DOT__f_gpr__DOT__regs_22),32);
        bufp->chgIData(oldp+128,(vlSelfRef.top__DOT__f_gpr__DOT__regs_23),32);
        bufp->chgIData(oldp+129,(vlSelfRef.top__DOT__f_gpr__DOT__regs_24),32);
        bufp->chgIData(oldp+130,(vlSelfRef.top__DOT__f_gpr__DOT__regs_25),32);
        bufp->chgIData(oldp+131,(vlSelfRef.top__DOT__f_gpr__DOT__regs_26),32);
        bufp->chgIData(oldp+132,(vlSelfRef.top__DOT__f_gpr__DOT__regs_27),32);
        bufp->chgIData(oldp+133,(vlSelfRef.top__DOT__f_gpr__DOT__regs_28),32);
        bufp->chgIData(oldp+134,(vlSelfRef.top__DOT__f_gpr__DOT__regs_29),32);
        bufp->chgIData(oldp+135,(vlSelfRef.top__DOT__f_gpr__DOT__regs_30),32);
        bufp->chgIData(oldp+136,(vlSelfRef.top__DOT__f_gpr__DOT__regs_31),32);
        bufp->chgBit(oldp+137,((1U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))));
        bufp->chgBit(oldp+138,((2U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))));
        bufp->chgBit(oldp+139,((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o))));
        bufp->chgBit(oldp+140,(vlSelfRef.top__DOT__i_alu__DOT__carry_reg));
        bufp->chgBit(oldp+141,(vlSelfRef.top__DOT__i_alu__DOT__overflow_reg));
        bufp->chgSData(oldp+142,((0xffffU & ((IData)(1U) 
                                             << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)))),16);
        bufp->chgQData(oldp+143,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1)) 
                                   + (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2))))),33);
        bufp->chgQData(oldp+145,((0x1ffffffffULL & 
                                  ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1)) 
                                   - (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2))))),33);
        bufp->chgIData(oldp+147,((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                  & vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)),32);
        bufp->chgIData(oldp+148,((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                  | vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)),32);
        bufp->chgIData(oldp+149,((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                  ^ vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)),32);
        bufp->chgIData(oldp+150,(VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1, (IData)(vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h4243b50f_0_0))),32);
        bufp->chgIData(oldp+151,((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                  >> (IData)(vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h4243b50f_0_0))),32);
        bufp->chgQData(oldp+152,((0x7fffffffffffffffULL 
                                  & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1)) 
                                     << (IData)(vlSelfRef.top__DOT__i_alu__DOT____VdfgRegularize_h4243b50f_0_0)))),63);
        bufp->chgBit(oldp+154,((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                < vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)));
        bufp->chgBit(oldp+155,(VL_LTS_III(32, vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1, vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data2)));
        bufp->chgQData(oldp+156,(vlSelfRef.top__DOT__i_alu__DOT__out33),64);
        bufp->chgBit(oldp+158,((vlSelfRef.top__DOT__h_data_control_io_alu_Req_bits_data1 
                                >> 0x1fU)));
        bufp->chgBit(oldp+159,(((2U != (IData)(vlSelfRef.top__DOT__d_idu__DOT__data_control_reg_o)) 
                                & (vlSelfRef.top__DOT__h_data_control__DOT___io_alu_Req_bits_data2_T 
                                   >> 0x1fU))));
        bufp->chgBit(oldp+160,((1U & (IData)((vlSelfRef.top__DOT__i_alu__DOT__out33 
                                              >> 0x1fU)))));
        bufp->chgBit(oldp+161,(((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T))));
        bufp->chgBit(oldp+162,(((IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T) 
                                & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1))));
        bufp->chgBit(oldp+163,(((((IData)(1U) << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)) 
                                 & ((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                    & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T))) 
                                | (((IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T) 
                                    & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                                   & (((IData)(1U) 
                                       << (IData)(vlSelfRef.top__DOT__d_idu__DOT__ALU_ctrl_reg_o)) 
                                      >> 1U)))));
        bufp->chgIData(oldp+164,(((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg)),32);
        bufp->chgBit(oldp+165,((1U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+166,((2U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+167,((3U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+168,((4U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+169,((5U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+170,((6U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+171,((7U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+172,((8U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+173,((9U == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+174,((0xaU == (IData)(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_type_reg))));
        bufp->chgBit(oldp+175,(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql));
        bufp->chgBit(oldp+176,(VL_GTES_III(32, vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg, vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)));
        bufp->chgBit(oldp+177,(VL_LTS_III(32, vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg, vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)));
        bufp->chgBit(oldp+178,((vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                >= vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)));
        bufp->chgBit(oldp+179,((vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                < vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)));
        bufp->chgIData(oldp+180,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))),32);
        bufp->chgIData(oldp+181,((VL_GTES_III(32, vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg, vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))),32);
        bufp->chgIData(oldp+182,((VL_LTS_III(32, vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg, vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))),32);
        bufp->chgIData(oldp+183,(((vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                   < vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))),32);
        bufp->chgIData(oldp+184,(((vlSelfRef.top__DOT__f_gpr__DOT__rs1_data_reg 
                                   >= vlSelfRef.top__DOT__f_gpr__DOT__rs2_data_reg)
                                   ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                   : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg))),32);
        bufp->chgIData(oldp+185,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                   ? ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_count_reg)
                                   : vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9)),32);
    }
    bufp->chgBit(oldp+186,(vlSelfRef.clock));
    bufp->chgBit(oldp+187,(vlSelfRef.reset));
    bufp->chgBit(oldp+188,(vlSelfRef.io_is_unknown_instruction));
    bufp->chgBit(oldp+189,(vlSelfRef.carry));
    bufp->chgBit(oldp+190,(vlSelfRef.overflow));
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
