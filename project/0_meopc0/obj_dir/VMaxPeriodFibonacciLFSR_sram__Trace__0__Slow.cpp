// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VMaxPeriodFibonacciLFSR_sram__Syms.h"


VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_init_sub__TOP__0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_init_sub__TOP__0\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"io_carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"io_isoverflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"io_carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"io_isoverflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"b_ifu_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"b_ifu_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"b_ifu_io_rd_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"b_ifu_io_rd_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"b_ifu_io_rd_Req_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"b_ifu_io_sram_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"b_ifu_io_sram_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"b_ifu_io_sram_Req_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"c_sram_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"c_sram_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"c_sram_io_ifu_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"c_sram_io_ifu_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"c_sram_io_ifu_Req_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"c_sram_io_mem_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"c_sram_io_mem_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"c_sram_io_inst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"d_idu_io_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"d_idu_io_imm_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"d_idu_io_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"d_idu_io_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+13,0,"d_idu_io_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"d_idu_io_data_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+15,0,"d_idu_io_ALU_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+16,0,"d_idu_io_pc_next_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+17,0,"d_idu_io_r_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+9,0,"e_imm_io_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"e_imm_io_imm_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+18,0,"e_imm_io_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"f_gpr_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"f_gpr_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"f_gpr_io_mem_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"f_gpr_io_mem_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"f_gpr_io_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"f_gpr_io_waddr_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"f_gpr_io_wdata_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"f_gpr_io_raddr_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+23,0,"f_gpr_io_rdata_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"f_gpr_io_raddr_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"f_gpr_io_rdata_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"f_gpr_io_ifu_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"f_gpr_io_ifu_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"f_gpr_io_ifu_Req_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"g_mem_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"g_mem_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"g_mem_io_sram_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"g_mem_io_sram_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"g_mem_io_rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"g_mem_io_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"g_mem_io_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"g_mem_io_r_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"g_mem_io_w_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+26,0,"g_mem_io_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+19,0,"g_mem_io_gpr_Req_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"g_mem_io_gpr_Req_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"h_data_control_io_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"h_data_control_io_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"h_data_control_io_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"h_data_control_io_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"h_data_control_io_pc_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"h_data_control_io_data_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+27,0,"h_data_control_io_data_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"h_data_control_io_data_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+27,0,"i_alu_io_in_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"i_alu_io_in_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"i_alu_io_sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+22,0,"i_alu_io_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+215,0,"i_alu_io_carry",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"i_alu_io_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"j_pc_next_io_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"j_pc_next_io_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"j_pc_next_io_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"j_pc_next_io_pc_next_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+3,0,"j_pc_next_io_pc_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"j_pc_next_io_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+214,0,"j_pc_next_io_is_unknown_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"is_break_out_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"d_idu_io_w_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+30,0,"r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("b_ifu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_rd_Req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_rd_Req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_rd_Req_bits_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_sram_Req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_sram_Req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_sram_Req_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"reqQ_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reqQ_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"reqQ_io_enq_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"reqQ_io_enq_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"reqQ_io_enq_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"reqQ_io_deq_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"reqQ_io_deq_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"reqQ_io_deq_bits_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqQ", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"io_enq_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_enq_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_enq_bits_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"io_deq_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_deq_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_deq_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("ram_addr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+31+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+217,0,"ram_addr_io_deq_bits_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+218,0,"ram_addr_io_deq_bits_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"ram_addr_io_deq_bits_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"ram_addr_MPORT_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+218,0,"ram_addr_MPORT_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"ram_addr_MPORT_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"ram_addr_MPORT_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"maybe_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"do_enq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"do_deq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("c_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_ifu_Req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"io_ifu_Req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_ifu_Req_bits_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"io_mem_Req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"io_mem_Req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"io_inst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"canAccept_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"canAccept_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"canAccept_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"canAccept_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"canAccept_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"canAccept_prng_io_out_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"canAccept_prng_io_out_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"canAccept_prng_io_out_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"canAccept_prng_io_out_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"canAccept_prng_io_out_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"canAccept_prng_io_out_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"canAccept_prng_io_out_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"canAccept_prng_io_out_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"canAccept_prng_io_out_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"canAccept_prng_io_out_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"canAccept_prng_io_out_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"canAccept_prng_io_out_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"canAccept_prng_io_out_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"instReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"canAccept_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+4,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("canAccept_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"io_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"io_out_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"io_out_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"io_out_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"io_out_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"io_out_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"io_out_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"io_out_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"io_out_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"io_out_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"io_out_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"io_out_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"io_out_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"state_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"state_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"state_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"state_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"state_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"state_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"state_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"state_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"state_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"state_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"state_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"state_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"state_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("d_idu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_imm_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+11,0,"io_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+12,0,"io_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+13,0,"io_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+14,0,"io_data_control",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+15,0,"io_ALU_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+16,0,"io_pc_next_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+17,0,"io_r_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"io_w_mask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+30,0,"io_r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"is_break_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"addi_Rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+51,0,"addi_Rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+52,0,"sltu_Rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+53,0,"isaddi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"isxori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"isori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"isandi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"issrai",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"issrli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"isslli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"issra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"issrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"isbeq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"isbne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"isadd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"isxor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"isand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"isor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"issub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"islui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"isauipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"isjal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"isjalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"issw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"isbge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"isblt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"isbltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"isbgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"issb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"issh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"islbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"islb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"islw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"islh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"islhu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"issll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"isslt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"issltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"issltiu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"isslti",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"iscsrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"iscsrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"isebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"isecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"ismret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("e_imm", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+9,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"io_imm_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+18,0,"io_imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"Imm_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"Imm_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"Imm_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"Imm_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"Imm_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+100,0,"is_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"is_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"is_type3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"is_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"is_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"is_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("f_gpr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"io_mem_Req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"io_mem_Req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"io_pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"io_waddr_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"io_wdata_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"io_raddr_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+23,0,"io_rdata_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"io_raddr_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+24,0,"io_rdata_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"io_ifu_Req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"io_ifu_Req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"io_ifu_Req_bits_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"regs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+107,0,"regs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"regs_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"regs_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"regs_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"regs_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"regs_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"regs_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"regs_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"regs_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"regs_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"regs_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"regs_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"regs_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"regs_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"regs_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"regs_16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+123,0,"regs_17",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+124,0,"regs_18",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+125,0,"regs_19",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"regs_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"regs_21",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"regs_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"regs_23",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"regs_24",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"regs_25",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"regs_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"regs_27",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"regs_28",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"regs_29",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"regs_30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"regs_31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+2,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"pc_next_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("g_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"io_sram_Req_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"io_sram_Req_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"io_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"io_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"io_r_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+25,0,"io_w_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+30,0,"io_r_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"io_mem_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+19,0,"io_gpr_Req_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"io_gpr_Req_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+138,0,"io_r_mask_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"io_w_mask_ext",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+212,0,"canAccept_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"canAccept_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"canAccept_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"canAccept_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"canAccept_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"canAccept_prng_io_out_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"canAccept_prng_io_out_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"canAccept_prng_io_out_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"canAccept_prng_io_out_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"canAccept_prng_io_out_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"canAccept_prng_io_out_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"canAccept_prng_io_out_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"canAccept_prng_io_out_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"canAccept_prng_io_out_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"canAccept_prng_io_out_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"canAccept_prng_io_out_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"canAccept_prng_io_out_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"canAccept_prng_io_out_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"delayCnt_prng_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"delayCnt_prng_reset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"delayCnt_prng_io_out_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"delayCnt_prng_io_out_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"delayCnt_prng_io_out_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+26,0,"mem_data_Reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+159,0,"validReg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+160,0,"canAccept_lo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+7,0,"canAccept",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+161,0,"read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"delayCnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+163,0,"startDelay",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("canAccept_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"io_out_3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"io_out_4",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"io_out_5",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"io_out_6",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"io_out_7",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"io_out_8",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"io_out_9",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"io_out_10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"io_out_11",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"io_out_12",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"io_out_13",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"io_out_14",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"io_out_15",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+142,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"state_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"state_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"state_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"state_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"state_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"state_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"state_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"state_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"state_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"state_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+153,0,"state_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+154,0,"state_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"state_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("delayCnt_prng", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"io_out_0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"io_out_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"io_out_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"state_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"state_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+158,0,"state_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("h_data_control", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"io_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"io_mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"io_data_control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+27,0,"io_data_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"io_data_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+164,0,"control1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+165,0,"control2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+166,0,"control3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"io_in_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"io_in_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"io_sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+22,0,"io_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+215,0,"io_carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"io_overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+167,0,"csr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"oneHot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+169,0,"add33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+171,0,"sub33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBus(c+173,0,"and32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"or32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+175,0,"xor32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"srai32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"srli32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+178,0,"sll32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 62,0);
    tracep->declBit(c+180,0,"sltiu_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+181,0,"slt_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+182,0,"out33",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+184,0,"a31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"b31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+186,0,"s31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+187,0,"overflowAddBool",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"overflowSubBool",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("j_pc_next", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+23,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"io_pc_next_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+3,0,"io_pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"io_pc_next",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+214,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+189,0,"ecall_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+190,0,"default_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+191,0,"is_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"is_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+193,0,"is_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+194,0,"is_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"is_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"is_type7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+197,0,"is_type8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"is_type9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"is_type10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"is_type11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"is_eql",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"is_more_equ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"is_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"is_more_equ_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"is_less_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+206,0,"beq_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"bge_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"blt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"bltu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+210,0,"bgeu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"bne_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("k_EXIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+212,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"io_Pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"is_break_out",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"is_unknown_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_init_top(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_init_top\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VMaxPeriodFibonacciLFSR_sram___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VMaxPeriodFibonacciLFSR_sram___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VMaxPeriodFibonacciLFSR_sram___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_register(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_register\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VMaxPeriodFibonacciLFSR_sram___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VMaxPeriodFibonacciLFSR_sram___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0_sub_0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0\n"); );
    // Init
    VMaxPeriodFibonacciLFSR_sram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMaxPeriodFibonacciLFSR_sram___024root*>(voidSelf);
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0_sub_0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_const_0_sub_0\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+217,(1U));
    bufp->fullBit(oldp+218,(0U));
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0_sub_0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0\n"); );
    // Init
    VMaxPeriodFibonacciLFSR_sram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMaxPeriodFibonacciLFSR_sram___024root*>(voidSelf);
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0_sub_0(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root__trace_full_0_sub_0\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,((1U & (~ (IData)(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full)))));
    bufp->fullBit(oldp+2,(vlSelfRef.top__DOT__f_gpr__DOT__validReg));
    bufp->fullIData(oldp+3,(vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg),32);
    bufp->fullBit(oldp+4,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_0));
    bufp->fullBit(oldp+5,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full));
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
                            [0U]),32);
    bufp->fullBit(oldp+7,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0));
    bufp->fullBit(oldp+8,(vlSelfRef.top__DOT__c_sram__DOT__validReg));
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__c_sram__DOT__instReg),32);
    bufp->fullCData(oldp+10,(vlSelfRef.top__DOT__d_idu_io_imm_type),3);
    bufp->fullCData(oldp+11,(vlSelfRef.top__DOT__d_idu_io_rs1),5);
    bufp->fullCData(oldp+12,(vlSelfRef.top__DOT__d_idu_io_rs2),5);
    bufp->fullCData(oldp+13,(vlSelfRef.top__DOT__d_idu_io_rd),5);
    bufp->fullCData(oldp+14,(vlSelfRef.top__DOT__d_idu_io_data_control),3);
    bufp->fullCData(oldp+15,(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl),4);
    bufp->fullCData(oldp+16,(vlSelfRef.top__DOT__d_idu_io_pc_next_type),4);
    bufp->fullCData(oldp+17,(((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
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
    bufp->fullIData(oldp+18,(vlSelfRef.top__DOT__e_imm_io_imm),32);
    bufp->fullBit(oldp+19,(vlSelfRef.top__DOT__f_gpr_io_mem_Req_ready));
    bufp->fullBit(oldp+20,(vlSelfRef.top__DOT__f_gpr_io_mem_Req_valid));
    bufp->fullIData(oldp+21,(vlSelfRef.top__DOT__f_gpr_io_pc_next),32);
    bufp->fullIData(oldp+22,(vlSelfRef.top__DOT__f_gpr_io_wdata_rd),32);
    bufp->fullIData(oldp+23,(vlSelfRef.top__DOT__f_gpr_io_rdata_rs1),32);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__f_gpr_io_rdata_rs2),32);
    bufp->fullCData(oldp+25,(((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                               ? 1U : ((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                        ? 3U : ((0xa3U 
                                                 == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                 ? 2U
                                                 : 0U)))),3);
    bufp->fullIData(oldp+26,(vlSelfRef.top__DOT__g_mem__DOT__mem_data_Reg),32);
    bufp->fullIData(oldp+27,(vlSelfRef.top__DOT__h_data_control_io_data_1),32);
    bufp->fullIData(oldp+28,(vlSelfRef.top__DOT__h_data_control_io_data_2),32);
    bufp->fullBit(oldp+29,(vlSelfRef.top__DOT__is_break_out_o));
    bufp->fullBit(oldp+30,(vlSelfRef.top__DOT__r_valid));
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr[0]),32);
    bufp->fullBit(oldp+32,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en));
    bufp->fullBit(oldp+33,(vlSelfRef.top__DOT__b_ifu__DOT__reqQ__DOT__do_deq));
    bufp->fullBit(oldp+34,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_1));
    bufp->fullBit(oldp+35,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_2));
    bufp->fullBit(oldp+36,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_3));
    bufp->fullBit(oldp+37,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_4));
    bufp->fullBit(oldp+38,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_5));
    bufp->fullBit(oldp+39,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_6));
    bufp->fullBit(oldp+40,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_7));
    bufp->fullBit(oldp+41,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_8));
    bufp->fullBit(oldp+42,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_9));
    bufp->fullBit(oldp+43,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_10));
    bufp->fullBit(oldp+44,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_11));
    bufp->fullBit(oldp+45,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_12));
    bufp->fullBit(oldp+46,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_13));
    bufp->fullBit(oldp+47,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_14));
    bufp->fullBit(oldp+48,(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_15));
    bufp->fullCData(oldp+49,((((((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_7) 
                                 << 7U) | ((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_6) 
                                           << 6U)) 
                               | (((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_5) 
                                   << 5U) | ((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_4) 
                                             << 4U))) 
                              | ((((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_3) 
                                   << 3U) | ((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_2) 
                                             << 2U)) 
                                 | (((IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_1) 
                                     << 1U) | (IData)(vlSelfRef.top__DOT__c_sram__DOT__canAccept_prng__DOT__state_0))))),8);
    bufp->fullCData(oldp+50,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+51,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                       >> 7U))),5);
    bufp->fullCData(oldp+52,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                       >> 0x14U))),5);
    bufp->fullBit(oldp+53,((0x13U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+54,((0x213U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+55,((0x313U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+56,((0x393U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+57,((0x4293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+58,((0x293U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+59,((0x93U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+60,((0x42b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+61,((0x2b3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___issrai_T_3))));
    bufp->fullBit(oldp+62,((0x63U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+63,((0xe3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+64,((0x33U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+65,((0x233U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+66,((0x3b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+67,((0x333U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+68,((0x8033U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+69,((0x37U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))));
    bufp->fullBit(oldp+70,((0x17U == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))));
    bufp->fullBit(oldp+71,((0x6fU == (0x7fU & vlSelfRef.top__DOT__c_sram__DOT__instReg))));
    bufp->fullBit(oldp+72,((0x67U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+73,((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+74,((0x2e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+75,((0x263U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+76,((0x363U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+77,((0x3e3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+78,((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+79,((0xa3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+80,((0x203U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+81,((3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+82,((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+83,((0x83U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+84,((0x283U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+85,((0xb3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+86,((0x133U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+87,((0x1b3U == vlSelfRef.top__DOT__d_idu__DOT___isadd_T_3)));
    bufp->fullBit(oldp+88,((0x193U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+89,((0x113U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+90,((0xf3U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+91,((0x173U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+92,((0x100073U == vlSelfRef.top__DOT__c_sram__DOT__instReg)));
    bufp->fullBit(oldp+93,((0x73U == vlSelfRef.top__DOT__c_sram__DOT__instReg)));
    bufp->fullBit(oldp+94,((0x30200073U == vlSelfRef.top__DOT__c_sram__DOT__instReg)));
    bufp->fullIData(oldp+95,(vlSelfRef.top__DOT__e_imm__DOT__Imm_type1),32);
    bufp->fullIData(oldp+96,((0xfffff000U & vlSelfRef.top__DOT__c_sram__DOT__instReg)),32);
    bufp->fullIData(oldp+97,(((((vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                 >> 0x1fU) ? 0xfffffU
                                 : 0U) << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                                         >> 7U))))),32);
    bufp->fullIData(oldp+98,((0x1fU & (vlSelfRef.top__DOT__c_sram__DOT__instReg 
                                       >> 0x14U))),32);
    bufp->fullIData(oldp+99,(VL_SHIFTR_III(32,32,32, vlSelfRef.top__DOT__c_sram__DOT__instReg, 0x14U)),32);
    bufp->fullBit(oldp+100,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+101,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+102,((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+103,((4U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+104,((5U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
    bufp->fullBit(oldp+105,((6U == (IData)(vlSelfRef.top__DOT__d_idu_io_imm_type))));
    bufp->fullIData(oldp+106,(vlSelfRef.top__DOT__f_gpr__DOT__regs_0),32);
    bufp->fullIData(oldp+107,(vlSelfRef.top__DOT__f_gpr__DOT__regs_1),32);
    bufp->fullIData(oldp+108,(vlSelfRef.top__DOT__f_gpr__DOT__regs_2),32);
    bufp->fullIData(oldp+109,(vlSelfRef.top__DOT__f_gpr__DOT__regs_3),32);
    bufp->fullIData(oldp+110,(vlSelfRef.top__DOT__f_gpr__DOT__regs_4),32);
    bufp->fullIData(oldp+111,(vlSelfRef.top__DOT__f_gpr__DOT__regs_5),32);
    bufp->fullIData(oldp+112,(vlSelfRef.top__DOT__f_gpr__DOT__regs_6),32);
    bufp->fullIData(oldp+113,(vlSelfRef.top__DOT__f_gpr__DOT__regs_7),32);
    bufp->fullIData(oldp+114,(vlSelfRef.top__DOT__f_gpr__DOT__regs_8),32);
    bufp->fullIData(oldp+115,(vlSelfRef.top__DOT__f_gpr__DOT__regs_9),32);
    bufp->fullIData(oldp+116,(vlSelfRef.top__DOT__f_gpr__DOT__regs_10),32);
    bufp->fullIData(oldp+117,(vlSelfRef.top__DOT__f_gpr__DOT__regs_11),32);
    bufp->fullIData(oldp+118,(vlSelfRef.top__DOT__f_gpr__DOT__regs_12),32);
    bufp->fullIData(oldp+119,(vlSelfRef.top__DOT__f_gpr__DOT__regs_13),32);
    bufp->fullIData(oldp+120,(vlSelfRef.top__DOT__f_gpr__DOT__regs_14),32);
    bufp->fullIData(oldp+121,(vlSelfRef.top__DOT__f_gpr__DOT__regs_15),32);
    bufp->fullIData(oldp+122,(vlSelfRef.top__DOT__f_gpr__DOT__regs_16),32);
    bufp->fullIData(oldp+123,(vlSelfRef.top__DOT__f_gpr__DOT__regs_17),32);
    bufp->fullIData(oldp+124,(vlSelfRef.top__DOT__f_gpr__DOT__regs_18),32);
    bufp->fullIData(oldp+125,(vlSelfRef.top__DOT__f_gpr__DOT__regs_19),32);
    bufp->fullIData(oldp+126,(vlSelfRef.top__DOT__f_gpr__DOT__regs_20),32);
    bufp->fullIData(oldp+127,(vlSelfRef.top__DOT__f_gpr__DOT__regs_21),32);
    bufp->fullIData(oldp+128,(vlSelfRef.top__DOT__f_gpr__DOT__regs_22),32);
    bufp->fullIData(oldp+129,(vlSelfRef.top__DOT__f_gpr__DOT__regs_23),32);
    bufp->fullIData(oldp+130,(vlSelfRef.top__DOT__f_gpr__DOT__regs_24),32);
    bufp->fullIData(oldp+131,(vlSelfRef.top__DOT__f_gpr__DOT__regs_25),32);
    bufp->fullIData(oldp+132,(vlSelfRef.top__DOT__f_gpr__DOT__regs_26),32);
    bufp->fullIData(oldp+133,(vlSelfRef.top__DOT__f_gpr__DOT__regs_27),32);
    bufp->fullIData(oldp+134,(vlSelfRef.top__DOT__f_gpr__DOT__regs_28),32);
    bufp->fullIData(oldp+135,(vlSelfRef.top__DOT__f_gpr__DOT__regs_29),32);
    bufp->fullIData(oldp+136,(vlSelfRef.top__DOT__f_gpr__DOT__regs_30),32);
    bufp->fullIData(oldp+137,(vlSelfRef.top__DOT__f_gpr__DOT__regs_31),32);
    bufp->fullIData(oldp+138,(((0x103U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
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
                                                    : 0U)))))),32);
    bufp->fullIData(oldp+139,(((0x123U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                ? 1U : ((0x23U == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                         ? 3U : ((0xa3U 
                                                  == (IData)(vlSelfRef.top__DOT__d_idu__DOT___isaddi_T_2))
                                                  ? 2U
                                                  : 0U)))),32);
    bufp->fullIData(oldp+140,(vlSelfRef.top__DOT__c_sram__DOT__validReg),32);
    bufp->fullBit(oldp+141,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_1));
    bufp->fullBit(oldp+142,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_2));
    bufp->fullBit(oldp+143,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_3));
    bufp->fullBit(oldp+144,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_4));
    bufp->fullBit(oldp+145,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_5));
    bufp->fullBit(oldp+146,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_6));
    bufp->fullBit(oldp+147,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7));
    bufp->fullBit(oldp+148,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_8));
    bufp->fullBit(oldp+149,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_9));
    bufp->fullBit(oldp+150,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_10));
    bufp->fullBit(oldp+151,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_11));
    bufp->fullBit(oldp+152,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_12));
    bufp->fullBit(oldp+153,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_13));
    bufp->fullBit(oldp+154,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_14));
    bufp->fullBit(oldp+155,(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_15));
    bufp->fullBit(oldp+156,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0));
    bufp->fullBit(oldp+157,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1));
    bufp->fullBit(oldp+158,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2));
    bufp->fullBit(oldp+159,(vlSelfRef.top__DOT__g_mem__DOT__validReg));
    bufp->fullCData(oldp+160,((((((IData)(vlSelfRef.top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7) 
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
    bufp->fullIData(oldp+161,(vlSelfRef.top__DOT__g_mem__DOT__read_data),32);
    bufp->fullCData(oldp+162,(vlSelfRef.top__DOT__g_mem__DOT__delayCnt),3);
    bufp->fullBit(oldp+163,(((IData)(vlSelfRef.top__DOT__g_mem__DOT___startDelay_T) 
                             & (IData)(vlSelfRef.top__DOT__r_valid))));
    bufp->fullBit(oldp+164,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
    bufp->fullBit(oldp+165,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
    bufp->fullBit(oldp+166,((3U == (IData)(vlSelfRef.top__DOT__d_idu_io_data_control))));
    bufp->fullIData(oldp+167,(vlSelfRef.top__DOT__i_alu__DOT__csr_data),32);
    bufp->fullSData(oldp+168,((0xffffU & ((IData)(1U) 
                                          << (IData)(vlSelfRef.top__DOT__d_idu_io_ALU_ctrl)))),16);
    bufp->fullQData(oldp+169,((0x1ffffffffULL & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                                 + (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2))))),33);
    bufp->fullQData(oldp+171,((0x1ffffffffULL & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                                 - (QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_2))))),33);
    bufp->fullIData(oldp+173,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                               & vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
    bufp->fullIData(oldp+174,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                               | vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
    bufp->fullIData(oldp+175,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                               ^ vlSelfRef.top__DOT__h_data_control_io_data_2)),32);
    bufp->fullIData(oldp+176,(VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__h_data_control_io_data_1, 
                                             (0x1fU 
                                              & vlSelfRef.top__DOT__h_data_control_io_data_2))),32);
    bufp->fullIData(oldp+177,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                               >> (0x1fU & vlSelfRef.top__DOT__h_data_control_io_data_2))),32);
    bufp->fullQData(oldp+178,((0x7fffffffffffffffULL 
                               & ((QData)((IData)(vlSelfRef.top__DOT__h_data_control_io_data_1)) 
                                  << (0x1fU & vlSelfRef.top__DOT__h_data_control_io_data_2)))),63);
    bufp->fullBit(oldp+180,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                             < vlSelfRef.top__DOT__h_data_control_io_data_2)));
    bufp->fullBit(oldp+181,(VL_LTS_III(32, vlSelfRef.top__DOT__h_data_control_io_data_1, vlSelfRef.top__DOT__h_data_control_io_data_2)));
    bufp->fullQData(oldp+182,(vlSelfRef.top__DOT__i_alu__DOT__out33),64);
    bufp->fullBit(oldp+184,((vlSelfRef.top__DOT__h_data_control_io_data_1 
                             >> 0x1fU)));
    bufp->fullBit(oldp+185,((vlSelfRef.top__DOT__h_data_control_io_data_2 
                             >> 0x1fU)));
    bufp->fullBit(oldp+186,((1U & (IData)((vlSelfRef.top__DOT__i_alu__DOT__out33 
                                           >> 0x1fU)))));
    bufp->fullBit(oldp+187,(((~ (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1)) 
                             & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T))));
    bufp->fullBit(oldp+188,(((IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T) 
                             & (IData)(vlSelfRef.top__DOT__i_alu__DOT___overflowAddBool_T_1))));
    bufp->fullIData(oldp+189,(vlSelfRef.top__DOT__j_pc_next__DOT__ecall_dnpc),32);
    bufp->fullIData(oldp+190,(((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)),32);
    bufp->fullBit(oldp+191,((1U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+192,((2U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+193,((4U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+194,((5U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+195,((6U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+196,((7U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+197,((8U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+198,((9U == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+199,((0xaU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type))));
    bufp->fullBit(oldp+200,(((0xbU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)) 
                             | (0xcU == (IData)(vlSelfRef.top__DOT__d_idu_io_pc_next_type)))));
    bufp->fullBit(oldp+201,(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql));
    bufp->fullBit(oldp+202,(VL_GTES_III(32, vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
    bufp->fullBit(oldp+203,(VL_LTS_III(32, vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
    bufp->fullBit(oldp+204,((vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                             >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
    bufp->fullBit(oldp+205,((vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                             < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)));
    bufp->fullIData(oldp+206,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+207,((VL_GTES_III(32, vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+208,((VL_LTS_III(32, vlSelfRef.top__DOT__f_gpr_io_rdata_rs1, vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+209,(((vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                                < vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+210,(((vlSelfRef.top__DOT__f_gpr_io_rdata_rs1 
                                >= vlSelfRef.top__DOT__f_gpr_io_rdata_rs2)
                                ? vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg))),32);
    bufp->fullIData(oldp+211,(((IData)(vlSelfRef.top__DOT__j_pc_next__DOT__is_eql)
                                ? ((IData)(4U) + vlSelfRef.top__DOT__f_gpr__DOT__pc_next_reg)
                                : vlSelfRef.top__DOT__j_pc_next__DOT___beq_result_T_9)),32);
    bufp->fullBit(oldp+212,(vlSelfRef.clock));
    bufp->fullBit(oldp+213,(vlSelfRef.reset));
    bufp->fullBit(oldp+214,(vlSelfRef.io_is_unknown_instruction));
    bufp->fullBit(oldp+215,(vlSelfRef.io_carry));
    bufp->fullBit(oldp+216,(vlSelfRef.io_isoverflow));
}
