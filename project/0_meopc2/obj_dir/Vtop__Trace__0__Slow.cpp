// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+139,0,"ALU_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+140,0,"rs1_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"rs2_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+142,0,"ALU_carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"ALU_overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ysyx_25030077_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+139,0,"ALU_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+140,0,"rs1_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"rs2_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+142,0,"ALU_carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"ALU_overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"io_Pc_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"Pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"instruction_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"imm_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+6,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"data_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+8,0,"pc_next_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+9,0,"is_break_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"ALU_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"ALU_data_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"ALU_data_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"is_unknown_instruction",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("i0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"io_next_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"io_Pc_count",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"instruction_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"instruction_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+3,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_imm_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"io_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+6,0,"io_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+138,0,"io_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+7,0,"io_data_control",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+139,0,"io_ALU_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+8,0,"io_pc_next_type",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+9,0,"is_break_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"addi_Rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+16,0,"addi_Rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+17,0,"sltu_Rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+18,0,"isaddi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"isxori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"isori",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"isandi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"issrai",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"issrli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"isslli",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"issra",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"issrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"isbeq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"isbne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"isadd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"isxor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"isand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"isor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"issub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"islui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"isauipc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"isjal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"isjalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"issw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"isbge",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"isblt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"isbltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"isbgeu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"issb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"issh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"islbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"islb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"islw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"islh",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"islhu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"issll",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"isslt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"issltu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"issltiu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"isslti",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"iscsrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"iscsrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"isebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"isecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"ismret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+3,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"io_imm_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+137,0,"io_imm",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"Imm_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"Imm_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"Imm_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"Imm_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"Imm_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"is_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"is_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"is_type3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"is_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"is_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"is_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i4", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clock",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+138,0,"io_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+10,0,"io_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"io_raddr_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+140,0,"io_rdata_rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"io_raddr_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+141,0,"io_rdata_rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+71,0,"regs_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"regs_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"regs_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"regs_3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+75,0,"regs_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"regs_5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"regs_6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"regs_7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"regs_8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+80,0,"regs_9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"regs_10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"regs_11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"regs_12",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"regs_13",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"regs_14",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"regs_15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"regs_16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+88,0,"regs_17",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"regs_18",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,0,"regs_19",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"regs_20",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"regs_21",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"regs_22",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"regs_23",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"regs_24",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"regs_25",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"regs_26",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"regs_27",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+99,0,"regs_28",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+100,0,"regs_29",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+101,0,"regs_30",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+102,0,"regs_31",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+144,0,"isReg0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i5", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+140,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"io_imm",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"io_mem_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"io_pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"io_data_control",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+12,0,"io_data_1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"io_data_2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+103,0,"control1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"control2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"control3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i6", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+12,0,"io_in_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"io_in_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"io_sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"io_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+142,0,"io_carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"io_overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"csr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"oneHot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+107,0,"addResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declQuad(c+109,0,"subResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,0);
    tracep->declBit(c+111,0,"sltiuResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"sltResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"andResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"orResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"xorResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"sraiResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"srliResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+118,0,"sllResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 62,0);
    tracep->popPrefix();
    tracep->pushPrefix("i7", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+140,0,"io_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"io_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"io_pc_next_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1,0,"io_pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"io_pc_next",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"io_is_unknown_instruction",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+120,0,"ecall_dnpc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"default_pc_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+122,0,"is_type1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"is_type2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"is_type4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"is_type5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"is_type6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"is_type7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+128,0,"is_type8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+129,0,"is_type9",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+130,0,"is_type10",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+131,0,"is_type11",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"is_eql",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"is_more_equ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"is_less",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"is_more_equ_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"is_less_u",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+133,0,"beq_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+150,0,"bge_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"blt_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"bltu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"bgeu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"bne_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("i8", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+135,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"io_Pc_count",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"is_break_out",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"is_unknown_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("i9", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+3,0,"io_instruction",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+140,0,"rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"imm_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"mem_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state),32);
    bufp->fullIData(oldp+2,(vlSelfRef.ysyx_25030077_top__DOT__Pc_next),32);
    bufp->fullIData(oldp+3,(vlSelfRef.ysyx_25030077_top__DOT__instruction_out),32);
    bufp->fullCData(oldp+4,(vlSelfRef.ysyx_25030077_top__DOT__imm_type),3);
    bufp->fullCData(oldp+5,(vlSelfRef.ysyx_25030077_top__DOT__rs1),5);
    bufp->fullCData(oldp+6,(vlSelfRef.ysyx_25030077_top__DOT__rs2),5);
    bufp->fullCData(oldp+7,(vlSelfRef.ysyx_25030077_top__DOT__data_control),3);
    bufp->fullCData(oldp+8,(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type),4);
    bufp->fullBit(oldp+9,(vlSelfRef.ysyx_25030077_top__DOT__is_break_out));
    bufp->fullIData(oldp+10,(vlSelfRef.ysyx_25030077_top__DOT__ALU_result),32);
    bufp->fullIData(oldp+11,(vlSelfRef.ysyx_25030077_top__DOT__mem_data),32);
    bufp->fullIData(oldp+12,(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1),32);
    bufp->fullIData(oldp+13,(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2),32);
    bufp->fullBit(oldp+14,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullCData(oldp+15,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+16,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                       >> 7U))),5);
    bufp->fullCData(oldp+17,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                       >> 0x14U))),5);
    bufp->fullBit(oldp+18,((0x13U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+19,((0x213U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+20,((0x313U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+21,((0x393U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+22,((0x4293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
    bufp->fullBit(oldp+23,((0x293U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
    bufp->fullBit(oldp+24,((0x93U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
    bufp->fullBit(oldp+25,((0x42b3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
    bufp->fullBit(oldp+26,((0x2b3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___issrai_T_3))));
    bufp->fullBit(oldp+27,((0x63U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+28,((0xe3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+29,((0x33U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+30,((0x233U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+31,((0x3b3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+32,((0x333U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+33,((0x8033U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+34,((0x37U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))));
    bufp->fullBit(oldp+35,((0x17U == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))));
    bufp->fullBit(oldp+36,((0x6fU == (0x7fU & vlSelfRef.ysyx_25030077_top__DOT__instruction_out))));
    bufp->fullBit(oldp+37,((0x67U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+38,((0x123U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+39,((0x2e3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+40,((0x263U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+41,((0x363U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+42,((0x3e3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+43,((0x23U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+44,((0xa3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+45,((0x203U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+46,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+47,((0x103U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+48,((0x83U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+49,((0x283U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+50,((0xb3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+51,((0x133U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+52,((0x1b3U == vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isadd_T_3)));
    bufp->fullBit(oldp+53,((0x193U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+54,((0x113U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+55,((0xf3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+56,((0x173U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__i2__DOT___isaddi_T_2))));
    bufp->fullBit(oldp+57,((0x100073U == vlSelfRef.ysyx_25030077_top__DOT__instruction_out)));
    bufp->fullBit(oldp+58,((0x73U == vlSelfRef.ysyx_25030077_top__DOT__instruction_out)));
    bufp->fullBit(oldp+59,((0x30200073U == vlSelfRef.ysyx_25030077_top__DOT__instruction_out)));
    bufp->fullIData(oldp+60,(vlSelfRef.ysyx_25030077_top__DOT__i3__DOT__Imm_type1),32);
    bufp->fullIData(oldp+61,((0xfffff000U & vlSelfRef.ysyx_25030077_top__DOT__instruction_out)),32);
    bufp->fullIData(oldp+62,(((((vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                 >> 0x1fU) ? 0xfffffU
                                 : 0U) << 0xcU) | (
                                                   (0xfe0U 
                                                    & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                                         >> 7U))))),32);
    bufp->fullIData(oldp+63,((0x1fU & (vlSelfRef.ysyx_25030077_top__DOT__instruction_out 
                                       >> 0x14U))),32);
    bufp->fullIData(oldp+64,(VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__instruction_out, 0x14U)),32);
    bufp->fullBit(oldp+65,((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
    bufp->fullBit(oldp+66,((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
    bufp->fullBit(oldp+67,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
    bufp->fullBit(oldp+68,((4U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
    bufp->fullBit(oldp+69,((5U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
    bufp->fullBit(oldp+70,((6U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__imm_type))));
    bufp->fullIData(oldp+71,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_0),32);
    bufp->fullIData(oldp+72,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_1),32);
    bufp->fullIData(oldp+73,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_2),32);
    bufp->fullIData(oldp+74,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_3),32);
    bufp->fullIData(oldp+75,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_4),32);
    bufp->fullIData(oldp+76,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_5),32);
    bufp->fullIData(oldp+77,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_6),32);
    bufp->fullIData(oldp+78,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_7),32);
    bufp->fullIData(oldp+79,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_8),32);
    bufp->fullIData(oldp+80,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_9),32);
    bufp->fullIData(oldp+81,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_10),32);
    bufp->fullIData(oldp+82,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_11),32);
    bufp->fullIData(oldp+83,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_12),32);
    bufp->fullIData(oldp+84,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_13),32);
    bufp->fullIData(oldp+85,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_14),32);
    bufp->fullIData(oldp+86,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_15),32);
    bufp->fullIData(oldp+87,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_16),32);
    bufp->fullIData(oldp+88,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_17),32);
    bufp->fullIData(oldp+89,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_18),32);
    bufp->fullIData(oldp+90,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_19),32);
    bufp->fullIData(oldp+91,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_20),32);
    bufp->fullIData(oldp+92,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_21),32);
    bufp->fullIData(oldp+93,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_22),32);
    bufp->fullIData(oldp+94,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_23),32);
    bufp->fullIData(oldp+95,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_24),32);
    bufp->fullIData(oldp+96,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_25),32);
    bufp->fullIData(oldp+97,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_26),32);
    bufp->fullIData(oldp+98,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_27),32);
    bufp->fullIData(oldp+99,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_28),32);
    bufp->fullIData(oldp+100,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_29),32);
    bufp->fullIData(oldp+101,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_30),32);
    bufp->fullIData(oldp+102,(vlSelfRef.ysyx_25030077_top__DOT__i4__DOT__regs_31),32);
    bufp->fullBit(oldp+103,((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))));
    bufp->fullBit(oldp+104,((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))));
    bufp->fullBit(oldp+105,((3U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__data_control))));
    bufp->fullIData(oldp+106,(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__csr_data),32);
    bufp->fullQData(oldp+107,(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__addResult),33);
    bufp->fullQData(oldp+109,(vlSelfRef.ysyx_25030077_top__DOT__i6__DOT__subResult),33);
    bufp->fullBit(oldp+111,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                             < vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)));
    bufp->fullBit(oldp+112,(VL_LTS_III(32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)));
    bufp->fullIData(oldp+113,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                               & vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
    bufp->fullIData(oldp+114,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                               | vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
    bufp->fullIData(oldp+115,((vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1 
                               ^ vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
    bufp->fullIData(oldp+116,(VL_SHIFTRS_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
    bufp->fullIData(oldp+117,(VL_SHIFTR_III(32,32,32, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1, vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)),32);
    bufp->fullQData(oldp+118,((0x7fffffffffffffffULL 
                               & ((QData)((IData)(vlSelfRef.ysyx_25030077_top__DOT__ALU_data_1)) 
                                  << (0x1fU & vlSelfRef.ysyx_25030077_top__DOT__ALU_data_2)))),63);
    bufp->fullIData(oldp+120,(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__ecall_dnpc),32);
    bufp->fullIData(oldp+121,(((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state)),32);
    bufp->fullBit(oldp+122,((1U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+123,((2U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+124,((4U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+125,((5U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+126,((6U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+127,((7U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+128,((8U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+129,((9U == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+130,((0xaU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type))));
    bufp->fullBit(oldp+131,(((0xbU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)) 
                             | (0xcU == (IData)(vlSelfRef.ysyx_25030077_top__DOT__pc_next_type)))));
    bufp->fullBit(oldp+132,(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql));
    bufp->fullIData(oldp+133,(((IData)(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql)
                                ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))),32);
    bufp->fullIData(oldp+134,(((IData)(vlSelfRef.ysyx_25030077_top__DOT__i7__DOT__is_eql)
                                ? ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state)
                                : vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9)),32);
    bufp->fullBit(oldp+135,(vlSelfRef.clock));
    bufp->fullBit(oldp+136,(vlSelfRef.reset));
    bufp->fullIData(oldp+137,(vlSelfRef.imm),32);
    bufp->fullCData(oldp+138,(vlSelfRef.rd),5);
    bufp->fullCData(oldp+139,(vlSelfRef.ALU_ctrl),4);
    bufp->fullIData(oldp+140,(vlSelfRef.rs1_out),32);
    bufp->fullIData(oldp+141,(vlSelfRef.rs2_out),32);
    bufp->fullBit(oldp+142,(vlSelfRef.ALU_carry));
    bufp->fullBit(oldp+143,(vlSelfRef.ALU_overflow));
    bufp->fullBit(oldp+144,((0U == (IData)(vlSelfRef.rd))));
    bufp->fullSData(oldp+145,((0xffffU & ((IData)(1U) 
                                          << (IData)(vlSelfRef.ALU_ctrl)))),16);
    bufp->fullBit(oldp+146,(VL_GTES_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)));
    bufp->fullBit(oldp+147,(VL_LTS_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)));
    bufp->fullBit(oldp+148,((vlSelfRef.rs1_out >= vlSelfRef.rs2_out)));
    bufp->fullBit(oldp+149,((vlSelfRef.rs1_out < vlSelfRef.rs2_out)));
    bufp->fullIData(oldp+150,((VL_GTES_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)
                                ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))),32);
    bufp->fullIData(oldp+151,((VL_LTS_III(32, vlSelfRef.rs1_out, vlSelfRef.rs2_out)
                                ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))),32);
    bufp->fullIData(oldp+152,(((vlSelfRef.rs1_out < vlSelfRef.rs2_out)
                                ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))),32);
    bufp->fullIData(oldp+153,(((vlSelfRef.rs1_out >= vlSelfRef.rs2_out)
                                ? vlSelfRef.ysyx_25030077_top__DOT__i7__DOT___beq_result_T_9
                                : ((IData)(4U) + vlSelfRef.ysyx_25030077_top__DOT__i0__DOT__state))),32);
}
