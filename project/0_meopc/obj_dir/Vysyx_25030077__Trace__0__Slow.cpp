// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_25030077__Syms.h"


VL_ATTR_COLD void Vysyx_25030077___024root__trace_init_sub__TOP__0(Vysyx_25030077___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_init_sub__TOP__0\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+281,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ysyx_25030077", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+281,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"b_ifu_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"b_ifu_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"b_ifu_io_rd_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"b_ifu_io_rd_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"b_ifu_io_rd_Req_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"b_ifu_io_ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"b_ifu_io_ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"b_ifu_io_ar_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"c_arbiter_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"c_arbiter_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"c_arbiter_io_ifu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"c_arbiter_io_delay_cnt_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+8,0,"c_arbiter_io_delay_cnt_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"c_arbiter_io_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"c_arbiter_io_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"c_arbiter_io_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"c_arbiter_io_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"c_arbiter_io_r_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+13,0,"c_arbiter_io_w_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+14,0,"c_arbiter_io_axi_ar_valid_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"c_arbiter_io_axi_ar_addr_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"c_arbiter_io_axi_ar_strb_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"c_arbiter_io_axi_ar_ready_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"c_arbiter_io_axi_ar_valid_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"c_arbiter_io_axi_ar_addr_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"c_arbiter_io_axi_ar_strb_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+20,0,"c_arbiter_io_axi_ar_ready_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"c_arbiter_io_axi_aw_valid_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"c_arbiter_io_axi_aw_addr_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"c_arbiter_io_axi_aw_ready_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"c_arbiter_io_axi_w_valid_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"c_arbiter_io_axi_w_data_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"c_arbiter_io_axi_w_strb_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"c_arbiter_io_axi_w_ready_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"c_arbiter_io_axi_aw_valid_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"c_arbiter_io_axi_aw_addr_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+27,0,"c_arbiter_io_axi_aw_ready_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"c_arbiter_io_axi_w_valid_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"c_arbiter_io_axi_w_data_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"c_arbiter_io_axi_w_strb_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+27,0,"c_arbiter_io_axi_w_ready_uart",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"c_arbiter_io_axi_r_valid_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"c_arbiter_io_axi_r_data_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"c_arbiter_io_axi_r_ready_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"c_arbiter_io_axi_r_valid_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"c_arbiter_io_axi_r_data_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"c_arbiter_io_axi_r_ready_clint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"c_arbiter_io_axi_b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"c_arbiter_io_axi_b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"c_arbiter_io_axi_b_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+282,0,"c_arbiter_io_gpr_b_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+35,0,"c_arbiter_io_gpr_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"c_arbiter_io_gpr_b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"c_arbiter_io_gpr_r_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"c_arbiter_io_gpr_b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"c_arbiter_io_gpr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"c_arbiter_io_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"c_arbiter_io_ifu_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"c_arbiter_io_r_valid_lsu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"c_arbiter_io_is_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_idu_io_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"d_idu_io_imm_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+42,0,"d_idu_io_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"d_idu_io_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"d_idu_io_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+45,0,"d_idu_io_data_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+46,0,"d_idu_io_ALU_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"d_idu_io_pc_next_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+12,0,"d_idu_io_r_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+13,0,"d_idu_io_w_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+39,0,"d_idu_io_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"e_imm_io_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"e_imm_io_imm_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"e_imm_io_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"f_gpr_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"f_gpr_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"f_gpr_io_mem_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"f_gpr_io_mem_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"f_gpr_io_b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"f_gpr_io_b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"f_gpr_io_gpr_b_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+48,0,"f_gpr_io_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"f_gpr_io_waddr_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+49,0,"f_gpr_io_wdata_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"f_gpr_io_raddr_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"f_gpr_io_rdata_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"f_gpr_io_raddr_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"f_gpr_io_rdata_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"f_gpr_io_ifu_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"f_gpr_io_ifu_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"f_gpr_io_ifu_Req_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"g_mem_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"g_mem_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"g_mem_io_ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"g_mem_io_ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"g_mem_io_aw_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"g_mem_io_aw_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"g_mem_io_w_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"g_mem_io_w_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"g_mem_io_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"g_mem_io_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"g_mem_io_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"g_mem_io_r_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+24,0,"g_mem_io_w_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+40,0,"g_mem_io_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"g_mem_io_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"g_mem_io_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+32,0,"g_mem_io_r__ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"g_mem_io_r__valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"g_mem_io_b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"g_mem_io_b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"g_mem_io_b_resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+9,0,"h_data_control_io_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"h_data_control_io_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"h_data_control_io_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"h_data_control_io_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"h_data_control_io_pc_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"h_data_control_io_data_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+50,0,"h_data_control_io_data_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"h_data_control_io_data_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"i_alu_io_in_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"i_alu_io_in_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"i_alu_io_sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+49,0,"i_alu_io_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"j_pc_next_io_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"j_pc_next_io_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"j_pc_next_io_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"j_pc_next_io_pc_next_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+3,0,"j_pc_next_io_pc_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"j_pc_next_io_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+281,0,"j_pc_next_io_is_unknown_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"l_uart_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"l_uart_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"l_uart_io_aw_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"l_uart_io_aw_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"l_uart_io_w_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"l_uart_io_w_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"l_uart_io_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"l_uart_io_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"l_uart_io_w_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+279,0,"m_clint_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"m_clint_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"m_clint_io_ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"m_clint_io_ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"m_clint_io_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"m_clint_io_r_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+40,0,"m_clint_io_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"m_clint_io_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"m_clint_io_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+32,0,"m_clint_io_r__ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"m_clint_io_r__valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("b_ifu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_rd_Req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_rd_Req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_rd_Req_bits_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_ar_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_ar_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_ar_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"reqQ_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reqQ_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"reqQ_io_enq_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reqQ_io_enq_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"reqQ_io_enq_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"reqQ_io_deq_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"reqQ_io_deq_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"reqQ_io_deq_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqQ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_enq_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_enq_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_enq_bits_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_deq_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_deq_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_deq_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ram_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+52+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+283,0,"ram_addr_io_deq_bits_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+284,0,"ram_addr_io_deq_bits_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"ram_addr_io_deq_bits_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"ram_addr_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+284,0,"ram_addr_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"ram_addr_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"ram_addr_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"maybe_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"do_enq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"do_deq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("c_arbiter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_ifu_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"io_delay_cnt_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+8,0,"io_delay_cnt_clint",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"io_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"io_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"io_r_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+13,0,"io_w_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+14,0,"io_axi_ar_valid_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"io_axi_ar_addr_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"io_axi_ar_strb_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"io_axi_ar_ready_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_axi_ar_valid_clint",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"io_axi_ar_addr_clint",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_axi_ar_strb_clint",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+20,0,"io_axi_ar_ready_clint",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_axi_aw_valid_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"io_axi_aw_addr_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_axi_aw_ready_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_axi_w_valid_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"io_axi_w_data_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_axi_w_strb_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+4,0,"io_axi_w_ready_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"io_axi_aw_valid_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"io_axi_aw_addr_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+27,0,"io_axi_aw_ready_uart",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"io_axi_w_valid_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"io_axi_w_data_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"io_axi_w_strb_uart",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+27,0,"io_axi_w_ready_uart",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_axi_r_valid_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"io_axi_r_data_mem",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"io_axi_r_ready_mem",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_axi_r_valid_clint",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"io_axi_r_data_clint",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+32,0,"io_axi_r_ready_clint",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_axi_b_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_axi_b_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"io_axi_b_resp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+282,0,"io_gpr_b_resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+35,0,"io_gpr_r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"io_gpr_b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_gpr_r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_gpr_b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"io_gpr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"io_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_ifu_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"io_r_valid_lsu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"io_is_r",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"state_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+38,0,"inst_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"axi_ar_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"delay_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+58,0,"axi_r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"axi_ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"axi_r_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"axi_aw_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+62,0,"axi_aw_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"axi_ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"axi_ar_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"axi_w_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"axi_w_strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("d_idu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"io_imm_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+42,0,"io_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"io_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"io_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+45,0,"io_data_control",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+46,0,"io_ALU_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"io_pc_next_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+12,0,"io_r_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+13,0,"io_w_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+39,0,"io_r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"addi_Rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+68,0,"addi_Rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+69,0,"sltu_Rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+70,0,"isaddi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"isxori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"isori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"isandi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"issrai",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"issrli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"isslli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"issra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"issrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"isbeq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"isbne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"isadd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"isxor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"isand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"isor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"issub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"islui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"isauipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"isjal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"isjalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"issw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"isbge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"isblt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"isbltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"isbgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+95,0,"issb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"issh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"islbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"islb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"islw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"islh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"islhu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"issll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"isslt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"issltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"issltiu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"isslti",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"iscsrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"iscsrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"isebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"isecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"ismret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("e_imm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+38,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"io_imm_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"io_imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"Imm_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"Imm_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"Imm_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"Imm_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"Imm_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+117,0,"is_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"is_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"is_type3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"is_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"is_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"is_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("f_gpr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_mem_Req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"io_mem_Req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_b_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"io_b_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"io_gpr_b_resp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+48,0,"io_pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"io_waddr_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+49,0,"io_wdata_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"io_raddr_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+9,0,"io_rdata_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"io_raddr_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"io_rdata_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"io_ifu_Req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_ifu_Req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_ifu_Req_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"canAccept_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"canAccept_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"canAccept_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"canAccept_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"canAccept_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"canAccept_prng_io_out_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"canAccept_prng_io_out_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"canAccept_prng_io_out_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"canAccept_prng_io_out_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"canAccept_prng_io_out_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"canAccept_prng_io_out_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"canAccept_prng_io_out_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"canAccept_prng_io_out_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"canAccept_prng_io_out_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"canAccept_prng_io_out_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"canAccept_prng_io_out_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"canAccept_prng_io_out_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"canAccept_prng_io_out_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+138,0,"regs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"regs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"regs_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"regs_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"regs_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"regs_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"regs_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"regs_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"regs_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"regs_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+148,0,"regs_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+149,0,"regs_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"regs_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"regs_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"regs_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"regs_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+154,0,"regs_16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+155,0,"regs_17",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+156,0,"regs_18",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+157,0,"regs_19",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+158,0,"regs_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+159,0,"regs_21",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"regs_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"regs_23",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"regs_24",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"regs_25",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"regs_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"regs_27",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"regs_28",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"regs_29",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"regs_30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"regs_31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+170,0,"canAccept_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+32,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"pc_next_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("canAccept_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"io_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"io_out_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"io_out_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"io_out_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"io_out_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"io_out_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"io_out_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"io_out_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"io_out_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"io_out_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"io_out_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"io_out_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"io_out_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"state_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"state_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"state_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"state_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"state_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"state_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"state_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"state_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"state_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"state_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"state_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"state_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"state_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("g_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"io_ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"io_w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"io_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"io_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"io_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"io_r_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+24,0,"io_w_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+40,0,"io_r_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"io_mem_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"io_cnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+32,0,"io_r__ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_r__valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"io_b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"io_b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"io_b_resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+171,0,"io_r_mask_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+172,0,"io_w_mask_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+279,0,"canAccept_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"canAccept_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"canAccept_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"canAccept_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"canAccept_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"canAccept_prng_io_out_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"canAccept_prng_io_out_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"canAccept_prng_io_out_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"canAccept_prng_io_out_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"canAccept_prng_io_out_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"canAccept_prng_io_out_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+182,0,"canAccept_prng_io_out_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"canAccept_prng_io_out_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"canAccept_prng_io_out_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"canAccept_prng_io_out_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"canAccept_prng_io_out_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"canAccept_prng_io_out_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"canAccept_prng_io_out_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"delayCnt_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"delayCnt_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"delayCnt_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"delayCnt_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"delayCnt_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"mem_data_Reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+192,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+193,0,"canAccept_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+4,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+194,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"delayCnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+195,0,"startDelay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("canAccept_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"io_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"io_out_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"io_out_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"io_out_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"io_out_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"io_out_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+182,0,"io_out_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"io_out_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"io_out_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"io_out_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"io_out_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"io_out_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"io_out_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"state_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"state_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"state_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"state_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+180,0,"state_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"state_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+182,0,"state_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"state_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+184,0,"state_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"state_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"state_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"state_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"state_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("delayCnt_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("h_data_control", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"io_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"io_mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"io_data_control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+50,0,"io_data_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"io_data_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+196,0,"control1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"control2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"control3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+50,0,"io_in_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"io_in_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"io_sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+49,0,"io_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"csr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+200,0,"oneHot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+201,0,"add33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+203,0,"sub33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+205,0,"and32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"or32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"xor32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"srai32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"srli32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+210,0,"sll32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 62,0);
    tracep->declBit(c+212,0,"sltiu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"slt_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+214,0,"out33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("j_pc_next", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"io_pc_next_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+3,0,"io_pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"io_pc_next",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+281,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+216,0,"ecall_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"default_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+218,0,"is_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+219,0,"is_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"is_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+221,0,"is_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+222,0,"is_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+223,0,"is_type7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+224,0,"is_type8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"is_type9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+226,0,"is_type10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"is_type11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+228,0,"is_eql",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+229,0,"is_more_equ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+230,0,"is_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+231,0,"is_more_equ_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+232,0,"is_less_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+233,0,"beq_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"bge_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+235,0,"blt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+236,0,"bltu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+237,0,"bgeu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"bne_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("l_uart", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"io_aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"io_aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"io_w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"io_w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"io_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"io_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"io_w_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+279,0,"canAccept_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"canAccept_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"canAccept_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"canAccept_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"canAccept_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"canAccept_prng_io_out_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"canAccept_prng_io_out_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"canAccept_prng_io_out_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"canAccept_prng_io_out_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+245,0,"canAccept_prng_io_out_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+246,0,"canAccept_prng_io_out_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+247,0,"canAccept_prng_io_out_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"canAccept_prng_io_out_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"canAccept_prng_io_out_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"canAccept_prng_io_out_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"canAccept_prng_io_out_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"canAccept_prng_io_out_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"canAccept_prng_io_out_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+254,0,"canAccept_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+27,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"charToPrint",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("canAccept_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"io_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"io_out_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"io_out_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"io_out_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+245,0,"io_out_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+246,0,"io_out_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+247,0,"io_out_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"io_out_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"io_out_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"io_out_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"io_out_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"io_out_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"io_out_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+239,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+240,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"state_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+242,0,"state_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"state_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+244,0,"state_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+245,0,"state_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+246,0,"state_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+247,0,"state_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+248,0,"state_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+249,0,"state_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+250,0,"state_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+251,0,"state_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+252,0,"state_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"state_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("m_clint", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"io_ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"io_ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"io_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"io_r_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+40,0,"io_r_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"io_mem_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"io_cnt",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+32,0,"io_r__ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"io_r__valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"canAccept_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"canAccept_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"canAccept_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"canAccept_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"canAccept_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"canAccept_prng_io_out_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"canAccept_prng_io_out_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+260,0,"canAccept_prng_io_out_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"canAccept_prng_io_out_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"canAccept_prng_io_out_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"canAccept_prng_io_out_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+264,0,"canAccept_prng_io_out_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"canAccept_prng_io_out_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+266,0,"canAccept_prng_io_out_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"canAccept_prng_io_out_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"canAccept_prng_io_out_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"canAccept_prng_io_out_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+270,0,"canAccept_prng_io_out_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"delayCnt_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"delayCnt_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"delayCnt_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+272,0,"delayCnt_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+273,0,"delayCnt_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+274,0,"mem_data_Reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+276,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+277,0,"canAccept_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+20,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"delayCnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+278,0,"startDelay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("canAccept_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"io_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"io_out_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+260,0,"io_out_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"io_out_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"io_out_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"io_out_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+264,0,"io_out_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"io_out_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+266,0,"io_out_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"io_out_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"io_out_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"io_out_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+270,0,"io_out_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+256,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+258,0,"state_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"state_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+260,0,"state_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"state_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+262,0,"state_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+263,0,"state_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+264,0,"state_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+265,0,"state_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+266,0,"state_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"state_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+268,0,"state_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+269,0,"state_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+270,0,"state_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("delayCnt_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+279,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+272,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+273,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+271,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+272,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+273,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vysyx_25030077___024root__trace_init_top(Vysyx_25030077___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_init_top\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vysyx_25030077___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_25030077___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vysyx_25030077___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vysyx_25030077___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vysyx_25030077___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vysyx_25030077___024root__trace_register(Vysyx_25030077___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_register\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vysyx_25030077___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vysyx_25030077___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vysyx_25030077___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vysyx_25030077___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_25030077___024root__trace_const_0_sub_0(Vysyx_25030077___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vysyx_25030077___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_const_0\n"); );
    // Init
    Vysyx_25030077___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25030077___024root*>(voidSelf);
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_25030077___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_25030077___024root__trace_const_0_sub_0(Vysyx_25030077___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_const_0_sub_0\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+282,(0U),2);
    bufp->fullBit(oldp+283,(1U));
    bufp->fullBit(oldp+284,(0U));
}

VL_ATTR_COLD void Vysyx_25030077___024root__trace_full_0_sub_0(Vysyx_25030077___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vysyx_25030077___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_full_0\n"); );
    // Init
    Vysyx_25030077___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_25030077___024root*>(voidSelf);
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_25030077___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_25030077___024root__trace_full_0_sub_0(Vysyx_25030077___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_25030077___024root__trace_full_0_sub_0\n"); );
    Vysyx_25030077__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,((1U & (~ (IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)))));
    bufp->fullBit(oldp+2,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__validReg));
    bufp->fullIData(oldp+3,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg),32);
    bufp->fullBit(oldp+4,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
    bufp->fullBit(oldp+5,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
    bufp->fullIData(oldp+6,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                            [0U]),32);
    bufp->fullCData(oldp+7,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt),3);
    bufp->fullCData(oldp+8,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt),3);
    bufp->fullIData(oldp+9,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data),32);
    bufp->fullIData(oldp+10,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data),32);
    bufp->fullIData(oldp+11,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_imm),32);
    bufp->fullCData(oldp+12,(((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                               ? 1U : ((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                        ? 3U : ((0x283U 
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
    bufp->fullCData(oldp+13,(((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                               ? 1U : ((0x23U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                        ? 3U : ((0xa3U 
                                                 == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                 ? 2U
                                                 : 0U)))),3);
    bufp->fullBit(oldp+14,(((~ (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)) 
                            & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid))));
    bufp->fullIData(oldp+15,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem),32);
    bufp->fullCData(oldp+16,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem),3);
    bufp->fullBit(oldp+17,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2) 
                            & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid))));
    bufp->fullIData(oldp+18,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                               ? vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr
                               : 0x80000000U)),32);
    bufp->fullCData(oldp+19,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                               ? ((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                   ? 6U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                            ? ((0x103U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 1U
                                                : (
                                                   (0x83U 
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
                                            : 0U)) : 0U)),3);
    bufp->fullBit(oldp+20,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0));
    bufp->fullBit(oldp+21,(((0xa00003f8U != vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                            & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid))));
    bufp->fullIData(oldp+22,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                               ? 0U : vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)),32);
    bufp->fullIData(oldp+23,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                               ? 0U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                        ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                                        : 0U))),32);
    bufp->fullCData(oldp+24,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                               ? 0U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                        ? ((0x123U 
                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                            ? 1U : 
                                           ((0x23U 
                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                             ? 3U : 
                                            ((0xa3U 
                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                              ? 2U : 0U)))
                                        : 0U))),3);
    bufp->fullBit(oldp+25,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                            & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid))));
    bufp->fullIData(oldp+26,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                               ? 0xa00003f8U : 0U)),32);
    bufp->fullBit(oldp+27,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0));
    bufp->fullIData(oldp+28,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                               ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                   ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                                   : 0U) : 0U)),32);
    bufp->fullCData(oldp+29,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                               ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                   ? ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                       ? 1U : ((0x23U 
                                                == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                ? 3U
                                                : (
                                                   (0xa3U 
                                                    == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                    ? 2U
                                                    : 0U)))
                                   : 0U) : 0U)),3);
    bufp->fullBit(oldp+30,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem));
    bufp->fullIData(oldp+31,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg),32);
    bufp->fullBit(oldp+32,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0));
    bufp->fullBit(oldp+33,(((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg) 
                            & (0U == (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt)))));
    bufp->fullIData(oldp+34,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint),32);
    bufp->fullBit(oldp+35,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid));
    bufp->fullBit(oldp+36,(((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg)) 
                            & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem))));
    bufp->fullIData(oldp+37,(((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                               ? ((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                                   ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint
                                   : vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg)
                               : 0U)),32);
    bufp->fullIData(oldp+38,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg),32);
    bufp->fullBit(oldp+39,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu));
    bufp->fullBit(oldp+40,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r));
    bufp->fullCData(oldp+41,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type),3);
    bufp->fullCData(oldp+42,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs1),5);
    bufp->fullCData(oldp+43,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rs2),5);
    bufp->fullCData(oldp+44,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_rd),5);
    bufp->fullCData(oldp+45,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control),3);
    bufp->fullCData(oldp+46,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl),4);
    bufp->fullCData(oldp+47,(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type),4);
    bufp->fullIData(oldp+48,(vlSelfRef.ysyx_25030077__DOT__f_gpr_io_pc_next),32);
    bufp->fullIData(oldp+49,(vlSelfRef.ysyx_25030077__DOT__f_gpr_io_wdata_rd),32);
    bufp->fullIData(oldp+50,(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1),32);
    bufp->fullIData(oldp+51,(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2),32);
    bufp->fullIData(oldp+52,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0]),32);
    bufp->fullBit(oldp+53,(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en));
    bufp->fullBit(oldp+54,(((IData)(vlSelfRef.ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full) 
                            & (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
    bufp->fullCData(oldp+55,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg),2);
    bufp->fullIData(oldp+56,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr),32);
    bufp->fullCData(oldp+57,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt),3);
    bufp->fullBit(oldp+58,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid));
    bufp->fullBit(oldp+59,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                             ? (IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0)
                             : (IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0))));
    bufp->fullIData(oldp+60,(((IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2)
                               ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint
                               : vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg)),32);
    bufp->fullIData(oldp+61,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr),32);
    bufp->fullBit(oldp+62,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid));
    bufp->fullBit(oldp+63,(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid));
    bufp->fullCData(oldp+64,(((0U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                               ? 6U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                        ? ((0x103U 
                                            == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                            ? 1U : 
                                           ((0x83U 
                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                             ? 3U : 
                                            ((0x283U 
                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                              ? 4U : 
                                             ((0x203U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 2U
                                               : ((3U 
                                                   == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                                   ? 5U
                                                   : 0U)))))
                                        : 0U))),3);
    bufp->fullIData(oldp+65,(((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                               ? vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data
                               : 0U)),32);
    bufp->fullCData(oldp+66,(((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                               ? ((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                   ? 1U : ((0x23U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                            ? 3U : 
                                           ((0xa3U 
                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                             ? 2U : 0U)))
                               : 0U)),3);
    bufp->fullCData(oldp+67,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+68,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                       >> 7U))),5);
    bufp->fullCData(oldp+69,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                       >> 0x14U))),5);
    bufp->fullBit(oldp+70,((0x13U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+71,((0x213U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+72,((0x313U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+73,((0x393U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+74,((0x4293U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+75,((0x293U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+76,((0x93U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+77,((0x42b3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+78,((0x2b3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+79,((0x63U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+80,((0xe3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+81,((0x33U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+82,((0x233U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+83,((0x3b3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+84,((0x333U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+85,((0x8033U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+86,((0x37U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))));
    bufp->fullBit(oldp+87,((0x17U == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))));
    bufp->fullBit(oldp+88,((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg))));
    bufp->fullBit(oldp+89,((0x67U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+90,((0x123U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+91,((0x2e3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+92,((0x263U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+93,((0x363U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+94,((0x3e3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+95,((0x23U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+96,((0xa3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+97,((0x203U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+98,((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+99,((0x103U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+100,((0x83U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+101,((0x283U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+102,((0xb3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+103,((0x133U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+104,((0x1b3U == vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+105,((0x193U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+106,((0x113U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+107,((0xf3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+108,((0x173U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+109,((0x100073U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)));
    bufp->fullBit(oldp+110,((0x73U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)));
    bufp->fullBit(oldp+111,((0x30200073U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)));
    bufp->fullIData(oldp+112,(vlSelfRef.ysyx_25030077__DOT__e_imm__DOT__Imm_type1),32);
    bufp->fullIData(oldp+113,((0xfffff000U & vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg)),32);
    bufp->fullIData(oldp+114,(((((vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                  >> 0x1fU) ? 0xfffffU
                                  : 0U) << 0xcU) | 
                               ((0xfe0U & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                           >> 0x14U)) 
                                | (0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                            >> 7U))))),32);
    bufp->fullIData(oldp+115,((0x1fU & (vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg 
                                        >> 0x14U))),32);
    bufp->fullIData(oldp+116,(VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__inst_reg, 0x14U)),32);
    bufp->fullBit(oldp+117,((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+118,((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+119,((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+120,((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+121,((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+122,((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+123,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1));
    bufp->fullBit(oldp+124,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2));
    bufp->fullBit(oldp+125,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3));
    bufp->fullBit(oldp+126,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4));
    bufp->fullBit(oldp+127,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5));
    bufp->fullBit(oldp+128,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6));
    bufp->fullBit(oldp+129,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7));
    bufp->fullBit(oldp+130,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8));
    bufp->fullBit(oldp+131,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9));
    bufp->fullBit(oldp+132,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10));
    bufp->fullBit(oldp+133,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11));
    bufp->fullBit(oldp+134,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12));
    bufp->fullBit(oldp+135,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13));
    bufp->fullBit(oldp+136,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14));
    bufp->fullBit(oldp+137,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15));
    bufp->fullIData(oldp+138,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_0),32);
    bufp->fullIData(oldp+139,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_1),32);
    bufp->fullIData(oldp+140,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_2),32);
    bufp->fullIData(oldp+141,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_3),32);
    bufp->fullIData(oldp+142,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_4),32);
    bufp->fullIData(oldp+143,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_5),32);
    bufp->fullIData(oldp+144,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_6),32);
    bufp->fullIData(oldp+145,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_7),32);
    bufp->fullIData(oldp+146,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_8),32);
    bufp->fullIData(oldp+147,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_9),32);
    bufp->fullIData(oldp+148,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_10),32);
    bufp->fullIData(oldp+149,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_11),32);
    bufp->fullIData(oldp+150,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_12),32);
    bufp->fullIData(oldp+151,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_13),32);
    bufp->fullIData(oldp+152,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_14),32);
    bufp->fullIData(oldp+153,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_15),32);
    bufp->fullIData(oldp+154,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_16),32);
    bufp->fullIData(oldp+155,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_17),32);
    bufp->fullIData(oldp+156,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_18),32);
    bufp->fullIData(oldp+157,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_19),32);
    bufp->fullIData(oldp+158,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_20),32);
    bufp->fullIData(oldp+159,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_21),32);
    bufp->fullIData(oldp+160,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_22),32);
    bufp->fullIData(oldp+161,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_23),32);
    bufp->fullIData(oldp+162,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_24),32);
    bufp->fullIData(oldp+163,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_25),32);
    bufp->fullIData(oldp+164,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_26),32);
    bufp->fullIData(oldp+165,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_27),32);
    bufp->fullIData(oldp+166,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_28),32);
    bufp->fullIData(oldp+167,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_29),32);
    bufp->fullIData(oldp+168,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_30),32);
    bufp->fullIData(oldp+169,(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__regs_31),32);
    bufp->fullCData(oldp+170,((((((IData)(vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7) 
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
    bufp->fullIData(oldp+171,(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem),32);
    bufp->fullIData(oldp+172,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                ? 0U : ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                         ? ((0x123U 
                                             == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                             ? 1U : 
                                            ((0x23U 
                                              == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                              ? 3U : 
                                             ((0xa3U 
                                               == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 2U
                                               : 0U)))
                                         : 0U))),32);
    bufp->fullIData(oldp+173,(((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0) 
                               & ((0xa00003f8U != vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr) 
                                  & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid)))),32);
    bufp->fullBit(oldp+174,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1));
    bufp->fullBit(oldp+175,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2));
    bufp->fullBit(oldp+176,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3));
    bufp->fullBit(oldp+177,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4));
    bufp->fullBit(oldp+178,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5));
    bufp->fullBit(oldp+179,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6));
    bufp->fullBit(oldp+180,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7));
    bufp->fullBit(oldp+181,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_8));
    bufp->fullBit(oldp+182,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_9));
    bufp->fullBit(oldp+183,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10));
    bufp->fullBit(oldp+184,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_11));
    bufp->fullBit(oldp+185,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12));
    bufp->fullBit(oldp+186,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13));
    bufp->fullBit(oldp+187,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_14));
    bufp->fullBit(oldp+188,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_15));
    bufp->fullBit(oldp+189,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0));
    bufp->fullBit(oldp+190,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1));
    bufp->fullBit(oldp+191,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2));
    bufp->fullBit(oldp+192,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__validReg));
    bufp->fullCData(oldp+193,((((((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7) 
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
    bufp->fullIData(oldp+194,(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT__read_data),32);
    bufp->fullBit(oldp+195,(((IData)(vlSelfRef.ysyx_25030077__DOT__g_mem__DOT___startDelay_T) 
                             & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r))));
    bufp->fullBit(oldp+196,((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))));
    bufp->fullBit(oldp+197,((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))));
    bufp->fullBit(oldp+198,((3U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_data_control))));
    bufp->fullIData(oldp+199,(vlSelfRef.ysyx_25030077__DOT__i_alu__DOT__csr_data),32);
    bufp->fullSData(oldp+200,((0xffffU & ((IData)(1U) 
                                          << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))),16);
    bufp->fullQData(oldp+201,((0x1ffffffffULL & ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                                 + (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))),33);
    bufp->fullQData(oldp+203,((0x1ffffffffULL & ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                                 - (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))),33);
    bufp->fullIData(oldp+205,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                               & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)),32);
    bufp->fullIData(oldp+206,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                               | vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)),32);
    bufp->fullIData(oldp+207,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                               ^ vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)),32);
    bufp->fullIData(oldp+208,(VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, 
                                             (0x1fU 
                                              & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))),32);
    bufp->fullIData(oldp+209,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                               >> (0x1fU & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))),32);
    bufp->fullQData(oldp+210,((0x7fffffffffffffffULL 
                               & ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                  << (0x1fU & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))),63);
    bufp->fullBit(oldp+212,((vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                             < vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)));
    bufp->fullBit(oldp+213,(VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)));
    bufp->fullQData(oldp+214,(((((0x1ffffffffULL & 
                                  ((((((((1U & ((IData)(1U) 
                                                << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                          ? ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                             + (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                          : 0ULL) | 
                                        ((2U & ((IData)(1U) 
                                                << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                          ? ((QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1)) 
                                             - (QData)((IData)(vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                          : 0ULL)) 
                                       | ((4U & ((IData)(1U) 
                                                 << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                           ? (QData)((IData)(
                                                             (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                              < vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                           : 0ULL)) 
                                      | ((8U & ((IData)(1U) 
                                                << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                          ? (QData)((IData)(
                                                            (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                             | vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                          : 0ULL)) 
                                     | ((0x10U & ((IData)(1U) 
                                                  << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                         ? (QData)((IData)(
                                                           (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                            ^ vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                         : 0ULL)) | 
                                    ((0x20U & ((IData)(1U) 
                                               << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                      ? (QData)((IData)(
                                                        VL_SHIFTRS_III(32,32,5, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, 
                                                                       (0x1fU 
                                                                        & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))
                                      : 0ULL)) | ((0x40U 
                                                   & ((IData)(1U) 
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
                                     : 0ULL)) | ((0x200U 
                                                  & ((IData)(1U) 
                                                     << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                                  ? (QData)((IData)(
                                                                    (vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2))))
                                                  : 0ULL)) 
                               | ((0x400U & ((IData)(1U) 
                                             << (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_ALU_ctrl)))
                                   ? (QData)((IData)(
                                                     VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_1, vlSelfRef.ysyx_25030077__DOT__h_data_control_io_data_2)))
                                   : 0ULL))),64);
    bufp->fullIData(oldp+216,(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__ecall_dnpc),32);
    bufp->fullIData(oldp+217,(((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg)),32);
    bufp->fullBit(oldp+218,((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+219,((2U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+220,((4U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+221,((5U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+222,((6U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+223,((7U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+224,((8U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+225,((9U == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+226,((0xaU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+227,(((0xbU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type)) 
                             | (0xcU == (IData)(vlSelfRef.ysyx_25030077__DOT__d_idu_io_pc_next_type)))));
    bufp->fullBit(oldp+228,(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql));
    bufp->fullBit(oldp+229,(VL_GTES_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
    bufp->fullBit(oldp+230,(VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
    bufp->fullBit(oldp+231,((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                             >= vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
    bufp->fullBit(oldp+232,((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                             < vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)));
    bufp->fullIData(oldp+233,(((IData)(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql)
                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+234,((VL_GTES_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+235,((VL_LTS_III(32, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data, vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+236,(((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                < vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+237,(((vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs1_data 
                                >= vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                ? vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+238,(((IData)(vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT__is_eql)
                                ? ((IData)(4U) + vlSelfRef.ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg)
                                : vlSelfRef.ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9)),32);
    bufp->fullBit(oldp+239,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1));
    bufp->fullBit(oldp+240,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2));
    bufp->fullBit(oldp+241,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3));
    bufp->fullBit(oldp+242,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4));
    bufp->fullBit(oldp+243,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5));
    bufp->fullBit(oldp+244,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6));
    bufp->fullBit(oldp+245,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7));
    bufp->fullBit(oldp+246,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_8));
    bufp->fullBit(oldp+247,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_9));
    bufp->fullBit(oldp+248,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10));
    bufp->fullBit(oldp+249,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_11));
    bufp->fullBit(oldp+250,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12));
    bufp->fullBit(oldp+251,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13));
    bufp->fullBit(oldp+252,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_14));
    bufp->fullBit(oldp+253,(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_15));
    bufp->fullCData(oldp+254,((((((IData)(vlSelfRef.ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7) 
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
    bufp->fullCData(oldp+255,(((0xa00003f8U == vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr)
                                ? ((1U == (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter__DOT__state_reg))
                                    ? (0xffU & vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_rs2_data)
                                    : 0U) : 0U)),8);
    bufp->fullBit(oldp+256,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1));
    bufp->fullBit(oldp+257,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2));
    bufp->fullBit(oldp+258,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3));
    bufp->fullBit(oldp+259,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4));
    bufp->fullBit(oldp+260,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5));
    bufp->fullBit(oldp+261,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6));
    bufp->fullBit(oldp+262,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7));
    bufp->fullBit(oldp+263,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_8));
    bufp->fullBit(oldp+264,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_9));
    bufp->fullBit(oldp+265,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10));
    bufp->fullBit(oldp+266,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_11));
    bufp->fullBit(oldp+267,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12));
    bufp->fullBit(oldp+268,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13));
    bufp->fullBit(oldp+269,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_14));
    bufp->fullBit(oldp+270,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_15));
    bufp->fullBit(oldp+271,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0));
    bufp->fullBit(oldp+272,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1));
    bufp->fullBit(oldp+273,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2));
    bufp->fullQData(oldp+274,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg),64);
    bufp->fullBit(oldp+276,(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__validReg));
    bufp->fullCData(oldp+277,((((((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7) 
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
    bufp->fullBit(oldp+278,(((IData)(vlSelfRef.ysyx_25030077__DOT__m_clint__DOT___startDelay_T) 
                             & (IData)(vlSelfRef.ysyx_25030077__DOT__c_arbiter_io_is_r))));
    bufp->fullBit(oldp+279,(vlSelfRef.clock));
    bufp->fullBit(oldp+280,(vlSelfRef.reset));
    bufp->fullBit(oldp+281,(vlSelfRef.io_is_unknown_instruction));
}
