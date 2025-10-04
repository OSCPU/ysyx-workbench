// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMaxPeriodFibonacciLFSR_sram.h for the primary calling header

#include "VMaxPeriodFibonacciLFSR_sram__pch.h"
#include "VMaxPeriodFibonacciLFSR_sram__Syms.h"
#include "VMaxPeriodFibonacciLFSR_sram___024root.h"

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__b_ifu__DOT__pc_read_data_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &pc_read_data__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__b_ifu__DOT__pc_read_data_TOP\n"); );
    // Init
    // Body
    pc_read_data__Vfuncrtn = vlSymsp->TOP.top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr
        [0U];
}

extern "C" svBitVecVal addr_read(const svBitVecVal* pc);

VL_INLINE_OPT void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__c_sram__DOT__addr_read_TOP(IData/*31:0*/ pc, IData/*31:0*/ &addr_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__c_sram__DOT__addr_read_TOP\n"); );
    // Body
    svBitVecVal pc__Vcvt[1];
    VL_SET_SVBV_I(32, pc__Vcvt, pc);
    svBitVecVal addr_read__Vfuncrtn__Vcvt[1];
    addr_read__Vfuncrtn__Vcvt[0] = addr_read(pc__Vcvt);
    addr_read__Vfuncrtn = VL_SET_I_SVBV(addr_read__Vfuncrtn__Vcvt);
}

extern "C" svBit is_break(const svBitVecVal* instruction_in);

VL_INLINE_OPT void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__d_idu__DOT__is_break_TOP(IData/*31:0*/ instruction_in, CData/*0:0*/ &is_break__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__d_idu__DOT__is_break_TOP\n"); );
    // Body
    svBitVecVal instruction_in__Vcvt[1];
    VL_SET_SVBV_I(32, instruction_in__Vcvt, instruction_in);
    svBit is_break__Vfuncrtn__Vcvt;
    is_break__Vfuncrtn__Vcvt = is_break(instruction_in__Vcvt);
    is_break__Vfuncrtn = (1U & is_break__Vfuncrtn__Vcvt);
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_addr_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_addr__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_addr_TOP\n"); );
    // Init
    // Body
    reg_read_addr__Vfuncrtn = vlSymsp->TOP.top__DOT__d_idu_io_rd;
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_data_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_data__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__f_gpr__DOT__reg_read_data_TOP\n"); );
    // Init
    // Body
    reg_read_data__Vfuncrtn = vlSymsp->TOP.top__DOT__f_gpr_io_wdata_rd;
}

extern "C" svBitVecVal mem_data_read(const svBitVecVal* instruction_in, const svBitVecVal* rs1_data_in, const svBitVecVal* rs2_data_in, const svBitVecVal* imm_data_in);

VL_INLINE_OPT void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__g_mem__DOT__mem_data_read_TOP(IData/*31:0*/ instruction_in, IData/*31:0*/ rs1_data_in, IData/*31:0*/ rs2_data_in, IData/*31:0*/ imm_data_in, IData/*31:0*/ &mem_data_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__g_mem__DOT__mem_data_read_TOP\n"); );
    // Body
    svBitVecVal instruction_in__Vcvt[1];
    VL_SET_SVBV_I(32, instruction_in__Vcvt, instruction_in);
    svBitVecVal rs1_data_in__Vcvt[1];
    VL_SET_SVBV_I(32, rs1_data_in__Vcvt, rs1_data_in);
    svBitVecVal rs2_data_in__Vcvt[1];
    VL_SET_SVBV_I(32, rs2_data_in__Vcvt, rs2_data_in);
    svBitVecVal imm_data_in__Vcvt[1];
    VL_SET_SVBV_I(32, imm_data_in__Vcvt, imm_data_in);
    svBitVecVal mem_data_read__Vfuncrtn__Vcvt[1];
    mem_data_read__Vfuncrtn__Vcvt[0] = mem_data_read(instruction_in__Vcvt, rs1_data_in__Vcvt, rs2_data_in__Vcvt, imm_data_in__Vcvt);
    mem_data_read__Vfuncrtn = VL_SET_I_SVBV(mem_data_read__Vfuncrtn__Vcvt);
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__g_mem__DOT__wmask_read_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &wmask_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__g_mem__DOT__wmask_read_TOP\n"); );
    // Init
    // Body
    wmask_read__Vfuncrtn = ((0x123U == (IData)(vlSymsp->TOP.top__DOT__d_idu__DOT___isaddi_T_2))
                             ? 1U : ((0x23U == (IData)(vlSymsp->TOP.top__DOT__d_idu__DOT___isaddi_T_2))
                                      ? 3U : ((0xa3U 
                                               == (IData)(vlSymsp->TOP.top__DOT__d_idu__DOT___isaddi_T_2))
                                               ? 2U
                                               : 0U)));
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__g_mem__DOT__valid_read_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &valid_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__g_mem__DOT__valid_read_TOP\n"); );
    // Init
    // Body
    valid_read__Vfuncrtn = vlSymsp->TOP.top__DOT__c_sram__DOT__validReg;
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs1_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs1__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs1_TOP\n"); );
    // Init
    // Body
    reg_read_rs1__Vfuncrtn = vlSymsp->TOP.top__DOT__f_gpr_io_rdata_rs1;
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs2_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &reg_read_rs2__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__h_data_control__DOT__reg_read_rs2_TOP\n"); );
    // Init
    // Body
    reg_read_rs2__Vfuncrtn = vlSymsp->TOP.top__DOT__f_gpr_io_rdata_rs2;
}

extern "C" svBitVecVal csr_read(const svBitVecVal* rs1, const svBitVecVal* imm, const svBitVecVal* sw);

VL_INLINE_OPT void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__i_alu__DOT__csr_read_TOP(IData/*31:0*/ rs1, IData/*31:0*/ imm, CData/*3:0*/ sw, IData/*31:0*/ &csr_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__i_alu__DOT__csr_read_TOP\n"); );
    // Body
    svBitVecVal rs1__Vcvt[1];
    VL_SET_SVBV_I(32, rs1__Vcvt, rs1);
    svBitVecVal imm__Vcvt[1];
    VL_SET_SVBV_I(32, imm__Vcvt, imm);
    svBitVecVal sw__Vcvt[1];
    VL_SET_SVBV_I(4, sw__Vcvt, sw);
    svBitVecVal csr_read__Vfuncrtn__Vcvt[1];
    csr_read__Vfuncrtn__Vcvt[0] = csr_read(rs1__Vcvt, imm__Vcvt, sw__Vcvt);
    csr_read__Vfuncrtn = VL_SET_I_SVBV(csr_read__Vfuncrtn__Vcvt);
}

void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__j_pc_next__DOT__dnpc_read_data_TOP(VMaxPeriodFibonacciLFSR_sram__Syms* __restrict vlSymsp, IData/*31:0*/ &dnpc_read_data__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiexp_top__DOT__j_pc_next__DOT__dnpc_read_data_TOP\n"); );
    // Init
    // Body
    dnpc_read_data__Vfuncrtn = vlSymsp->TOP.top__DOT__f_gpr_io_pc_next;
}

extern "C" svBitVecVal ecall_read(const svBitVecVal* pc, const svBitVecVal* type_p);

VL_INLINE_OPT void VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__j_pc_next__DOT__ecall_read_TOP(IData/*31:0*/ pc, CData/*3:0*/ type_p, IData/*31:0*/ &ecall_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root____Vdpiimwrap_top__DOT__j_pc_next__DOT__ecall_read_TOP\n"); );
    // Body
    svBitVecVal pc__Vcvt[1];
    VL_SET_SVBV_I(32, pc__Vcvt, pc);
    svBitVecVal type_p__Vcvt[1];
    VL_SET_SVBV_I(4, type_p__Vcvt, type_p);
    svBitVecVal ecall_read__Vfuncrtn__Vcvt[1];
    ecall_read__Vfuncrtn__Vcvt[0] = ecall_read(pc__Vcvt, type_p__Vcvt);
    ecall_read__Vfuncrtn = VL_SET_I_SVBV(ecall_read__Vfuncrtn__Vcvt);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__act(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
#endif  // VL_DEBUG

void VMaxPeriodFibonacciLFSR_sram___024root___eval_triggers__act(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMaxPeriodFibonacciLFSR_sram___024root___eval_triggers__act\n"); );
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clock) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VMaxPeriodFibonacciLFSR_sram___024root___dump_triggers__act(vlSelf);
    }
#endif
}
