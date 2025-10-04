// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_25030077.h for the primary calling header

#ifndef VERILATED_VYSYX_25030077___024ROOT_H_
#define VERILATED_VYSYX_25030077___024ROOT_H_  // guard

#include "verilated.h"


class Vysyx_25030077__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vysyx_25030077___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(io_is_unknown_instruction,0,0);
        CData/*2:0*/ ysyx_25030077__DOT__c_arbiter_io_axi_ar_strb_mem;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter_io_axi_r_valid_mem;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter_io_gpr_r_valid;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter_io_r_valid_lsu;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter_io_is_r;
        CData/*2:0*/ ysyx_25030077__DOT__d_idu_io_imm_type;
        CData/*4:0*/ ysyx_25030077__DOT__d_idu_io_rs1;
        CData/*4:0*/ ysyx_25030077__DOT__d_idu_io_rs2;
        CData/*4:0*/ ysyx_25030077__DOT__d_idu_io_rd;
        CData/*2:0*/ ysyx_25030077__DOT__d_idu_io_data_control;
        CData/*3:0*/ ysyx_25030077__DOT__d_idu_io_ALU_ctrl;
        CData/*3:0*/ ysyx_25030077__DOT__d_idu_io_pc_next_type;
        CData/*0:0*/ ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en;
        CData/*0:0*/ ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__maybe_full;
        CData/*0:0*/ ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__do_deq;
        CData/*1:0*/ ysyx_25030077__DOT__c_arbiter__DOT__state_reg;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT___axi_ar_addr_T_2;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT___delay_cnt_T_2;
        CData/*2:0*/ ysyx_25030077__DOT__c_arbiter__DOT__delay_cnt;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT__axi_r_valid;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_3;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT___state_reg_T_13;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_valid;
        CData/*0:0*/ ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_valid;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__validReg;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT___validReg_T;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT___validReg_T_1;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_0;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_1;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_2;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_3;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_4;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_5;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_6;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_7;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_8;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_9;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_10;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_11;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_12;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_13;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_14;
        CData/*0:0*/ ysyx_25030077__DOT__f_gpr__DOT__canAccept_prng__DOT__state_15;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__validReg;
        CData/*2:0*/ ysyx_25030077__DOT__g_mem__DOT__delayCnt;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT___startDelay_T;
        CData/*2:0*/ ysyx_25030077__DOT__g_mem__DOT___delayCnt_T_3;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT___validReg_T_4;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_0;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_1;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_2;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_3;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_4;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_5;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_6;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_7;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_8;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_9;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_10;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_11;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_12;
    };
    struct {
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_13;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_14;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__canAccept_prng__DOT__state_15;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_0;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_1;
        CData/*0:0*/ ysyx_25030077__DOT__g_mem__DOT__delayCnt_prng__DOT__state_2;
        CData/*0:0*/ ysyx_25030077__DOT__j_pc_next__DOT__is_eql;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_0;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_1;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_2;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_3;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_4;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_5;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_6;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_7;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_8;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_9;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_10;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_11;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_12;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_13;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_14;
        CData/*0:0*/ ysyx_25030077__DOT__l_uart__DOT__canAccept_prng__DOT__state_15;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__validReg;
        CData/*2:0*/ ysyx_25030077__DOT__m_clint__DOT__delayCnt;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT___startDelay_T;
        CData/*2:0*/ ysyx_25030077__DOT__m_clint__DOT___delayCnt_T_3;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT___validReg_T_3;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_0;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_1;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_2;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_3;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_4;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_5;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_6;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_7;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_8;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_9;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_10;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_11;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_12;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_13;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_14;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__canAccept_prng__DOT__state_15;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_0;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_1;
        CData/*0:0*/ ysyx_25030077__DOT__m_clint__DOT__delayCnt_prng__DOT__state_2;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ ysyx_25030077__DOT__d_idu__DOT___isaddi_T_2;
        SData/*15:0*/ ysyx_25030077__DOT__d_idu__DOT___issrai_T_3;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter_io_rs1_data;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter_io_rs2_data;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter_io_imm;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter_io_axi_ar_addr_mem;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter_io_axi_r_data_clint;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr_io_pc_next;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr_io_wdata_rd;
        IData/*31:0*/ ysyx_25030077__DOT__h_data_control_io_data_1;
        IData/*31:0*/ ysyx_25030077__DOT__h_data_control_io_data_2;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter__DOT__inst_reg;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter__DOT__axi_ar_addr;
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter__DOT__axi_aw_addr;
    };
    struct {
        IData/*31:0*/ ysyx_25030077__DOT__c_arbiter__DOT____VdfgRegularize_hf53335a2_0_0;
        IData/*16:0*/ ysyx_25030077__DOT__d_idu__DOT___isadd_T_3;
        IData/*31:0*/ ysyx_25030077__DOT__e_imm__DOT__Imm_type1;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_0;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_1;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_2;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_3;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_4;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_5;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_6;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_7;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_8;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_9;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_10;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_11;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_12;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_13;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_14;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_15;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_16;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_17;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_18;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_19;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_20;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_21;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_22;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_23;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_24;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_25;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_26;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_27;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_28;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_29;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_30;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__regs_31;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT__pc_next_reg;
        IData/*31:0*/ ysyx_25030077__DOT__f_gpr__DOT___GEN_94;
        IData/*31:0*/ ysyx_25030077__DOT__g_mem__DOT__mem_data_Reg;
        IData/*31:0*/ ysyx_25030077__DOT__g_mem__DOT__read_data;
        IData/*31:0*/ ysyx_25030077__DOT__i_alu__DOT__csr_data;
        IData/*31:0*/ ysyx_25030077__DOT__j_pc_next__DOT__ecall_dnpc;
        IData/*31:0*/ ysyx_25030077__DOT__j_pc_next__DOT___beq_result_T_9;
        IData/*31:0*/ __Vfunc_ysyx_25030077__DOT__g_mem__DOT__addr_read__0__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_25030077__DOT__g_mem__DOT__mem_data_read__1__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_25030077__DOT__i_alu__DOT__csr_read__2__Vfuncout;
        IData/*31:0*/ __Vfunc_ysyx_25030077__DOT__j_pc_next__DOT__ecall_read__3__Vfuncout;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ ysyx_25030077__DOT__m_clint__DOT__mem_data_Reg;
        QData/*63:0*/ ysyx_25030077__DOT__m_clint__DOT___mem_data_Reg_T_2;
        VlUnpacked<IData/*31:0*/, 1> ysyx_25030077__DOT__b_ifu__DOT__reqQ__DOT__ram_addr;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_25030077__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_25030077___024root(Vysyx_25030077__Syms* symsp, const char* v__name);
    ~Vysyx_25030077___024root();
    VL_UNCOPYABLE(Vysyx_25030077___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
