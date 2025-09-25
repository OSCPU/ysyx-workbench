// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMaxPeriodFibonacciLFSR_sram.h for the primary calling header

#ifndef VERILATED_VMAXPERIODFIBONACCILFSR_SRAM___024ROOT_H_
#define VERILATED_VMAXPERIODFIBONACCILFSR_SRAM___024ROOT_H_  // guard

#include "verilated.h"


class VMaxPeriodFibonacciLFSR_sram__Syms;

class alignas(VL_CACHE_LINE_BYTES) VMaxPeriodFibonacciLFSR_sram___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(io_is_unknown_instruction,0,0);
        VL_OUT8(io_carry,0,0);
        VL_OUT8(io_isoverflow,0,0);
        CData/*2:0*/ top__DOT__d_idu_io_imm_type;
        CData/*4:0*/ top__DOT__d_idu_io_rs1;
        CData/*4:0*/ top__DOT__d_idu_io_rs2;
        CData/*4:0*/ top__DOT__d_idu_io_rd;
        CData/*2:0*/ top__DOT__d_idu_io_data_control;
        CData/*3:0*/ top__DOT__d_idu_io_ALU_ctrl;
        CData/*3:0*/ top__DOT__d_idu_io_pc_next_type;
        CData/*0:0*/ top__DOT__f_gpr_io_mem_Req_ready;
        CData/*0:0*/ top__DOT__f_gpr_io_mem_Req_valid;
        CData/*0:0*/ top__DOT__is_break_out_o;
        CData/*0:0*/ top__DOT__r_valid;
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en;
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full;
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ__DOT__do_deq;
        CData/*0:0*/ top__DOT__c_sram__DOT__validReg;
        CData/*0:0*/ top__DOT__c_sram__DOT___validReg_T_1;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_0;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_1;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_2;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_3;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_4;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_5;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_6;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_7;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_8;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_9;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_10;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_11;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_12;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_13;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_14;
        CData/*0:0*/ top__DOT__c_sram__DOT__canAccept_prng__DOT__state_15;
        CData/*0:0*/ top__DOT__f_gpr__DOT__validReg;
        CData/*0:0*/ top__DOT__f_gpr__DOT___validReg_T;
        CData/*0:0*/ top__DOT__f_gpr__DOT___validReg_T_1;
        CData/*0:0*/ top__DOT__g_mem__DOT__validReg;
        CData/*2:0*/ top__DOT__g_mem__DOT__delayCnt;
        CData/*0:0*/ top__DOT__g_mem__DOT___startDelay_T;
        CData/*2:0*/ top__DOT__g_mem__DOT___delayCnt_T_3;
        CData/*0:0*/ top__DOT__g_mem__DOT___validReg_T_3;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_0;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_1;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_2;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_3;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_4;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_5;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_6;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_7;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_8;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_9;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_10;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_11;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_12;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_13;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_14;
        CData/*0:0*/ top__DOT__g_mem__DOT__canAccept_prng__DOT__state_15;
        CData/*0:0*/ top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0;
        CData/*0:0*/ top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1;
        CData/*0:0*/ top__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2;
    };
    struct {
        CData/*0:0*/ top__DOT__i_alu__DOT___overflowAddBool_T;
        CData/*0:0*/ top__DOT__i_alu__DOT___overflowAddBool_T_1;
        CData/*0:0*/ top__DOT__j_pc_next__DOT__is_eql;
        CData/*0:0*/ __Vfunc_top__DOT__d_idu__DOT__is_break__1__Vfuncout;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ top__DOT__d_idu__DOT___isaddi_T_2;
        SData/*15:0*/ top__DOT__d_idu__DOT___issrai_T_3;
        IData/*31:0*/ top__DOT__e_imm_io_imm;
        IData/*31:0*/ top__DOT__f_gpr_io_pc_next;
        IData/*31:0*/ top__DOT__f_gpr_io_wdata_rd;
        IData/*31:0*/ top__DOT__f_gpr_io_rdata_rs1;
        IData/*31:0*/ top__DOT__f_gpr_io_rdata_rs2;
        IData/*31:0*/ top__DOT__h_data_control_io_data_1;
        IData/*31:0*/ top__DOT__h_data_control_io_data_2;
        IData/*31:0*/ top__DOT__c_sram__DOT__instReg;
        IData/*16:0*/ top__DOT__d_idu__DOT___isadd_T_3;
        IData/*31:0*/ top__DOT__e_imm__DOT__Imm_type1;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_0;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_1;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_2;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_3;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_4;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_5;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_6;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_7;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_8;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_9;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_10;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_11;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_12;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_13;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_14;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_15;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_16;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_17;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_18;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_19;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_20;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_21;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_22;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_23;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_24;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_25;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_26;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_27;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_28;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_29;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_30;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_31;
        IData/*31:0*/ top__DOT__f_gpr__DOT__pc_next_reg;
        IData/*31:0*/ top__DOT__f_gpr__DOT___GEN_94;
        IData/*31:0*/ top__DOT__g_mem__DOT__mem_data_Reg;
        IData/*31:0*/ top__DOT__g_mem__DOT__read_data;
        IData/*31:0*/ top__DOT__i_alu__DOT__csr_data;
        IData/*31:0*/ top__DOT__j_pc_next__DOT__ecall_dnpc;
        IData/*31:0*/ top__DOT__j_pc_next__DOT___beq_result_T_9;
        IData/*31:0*/ __Vfunc_top__DOT__g_mem__DOT__mem_data_read__2__Vfuncout;
        IData/*31:0*/ __Vfunc_top__DOT__i_alu__DOT__csr_read__3__Vfuncout;
        IData/*31:0*/ __Vfunc_top__DOT__j_pc_next__DOT__ecall_read__4__Vfuncout;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ top__DOT__i_alu__DOT__out33;
        VlUnpacked<IData/*31:0*/, 1> top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr;
    };
    struct {
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VMaxPeriodFibonacciLFSR_sram__Syms* const vlSymsp;

    // CONSTRUCTORS
    VMaxPeriodFibonacciLFSR_sram___024root(VMaxPeriodFibonacciLFSR_sram__Syms* symsp, const char* v__name);
    ~VMaxPeriodFibonacciLFSR_sram___024root();
    VL_UNCOPYABLE(VMaxPeriodFibonacciLFSR_sram___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
