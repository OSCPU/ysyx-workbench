// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_OUT8(io_is_unknown_instruction,0,0);
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ_io_deq_ready;
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr_MPORT_en;
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ__DOT__maybe_full;
        CData/*0:0*/ top__DOT__b_ifu__DOT__reqQ__DOT__do_deq;
        CData/*0:0*/ top__DOT__c_sram__DOT__validReg;
        CData/*0:0*/ top__DOT__c_sram__DOT___validReg_T;
        CData/*0:0*/ top__DOT__c_sram__DOT___validReg_T_1;
        CData/*2:0*/ top__DOT__d_idu__DOT__imm_type_reg_o;
        CData/*4:0*/ top__DOT__d_idu__DOT__rs1_reg_o;
        CData/*4:0*/ top__DOT__d_idu__DOT__rs2_reg_o;
        CData/*4:0*/ top__DOT__d_idu__DOT__rd_reg_o;
        CData/*3:0*/ top__DOT__d_idu__DOT__ALU_ctrl_reg_o;
        CData/*2:0*/ top__DOT__d_idu__DOT__data_control_reg_o;
        CData/*3:0*/ top__DOT__d_idu__DOT__pc_next_type_reg_o;
        CData/*0:0*/ top__DOT__d_idu__DOT__validReg;
        CData/*0:0*/ top__DOT__d_idu__DOT__canAccept;
        CData/*0:0*/ top__DOT__d_idu__DOT___validReg_T;
        CData/*0:0*/ top__DOT__d_idu__DOT___validReg_T_1;
        CData/*2:0*/ top__DOT__d_idu__DOT___imm_type_reg_T_18;
        CData/*4:0*/ top__DOT__d_idu__DOT___rs1_reg_T_25;
        CData/*4:0*/ top__DOT__d_idu__DOT___rs2_reg_T_12;
        CData/*4:0*/ top__DOT__d_idu__DOT___rd_reg_T_24;
        CData/*4:0*/ top__DOT__d_idu__DOT__ALU_ctrl_reg;
        CData/*2:0*/ top__DOT__d_idu__DOT___data_control_reg_T_19;
        CData/*3:0*/ top__DOT__d_idu__DOT___pc_next_type_reg_T_19;
        CData/*4:0*/ top__DOT__d_idu__DOT___GEN_0;
        CData/*0:0*/ top__DOT__f_gpr__DOT__validReg;
        CData/*3:0*/ top__DOT__f_gpr__DOT__pc_next_type_reg;
        CData/*0:0*/ top__DOT__f_gpr__DOT__canAccept;
        CData/*0:0*/ top__DOT__f_gpr__DOT___regs_T;
        CData/*0:0*/ top__DOT__f_gpr__DOT___validReg_T_1;
        CData/*4:0*/ top__DOT__i_alu__DOT__rd_addr_reg;
        CData/*3:0*/ top__DOT__i_alu__DOT__pc_next_type_reg;
        CData/*0:0*/ top__DOT__i_alu__DOT__validReg;
        CData/*0:0*/ top__DOT__i_alu__DOT__canAccept;
        CData/*0:0*/ top__DOT__i_alu__DOT___validReg_T;
        CData/*0:0*/ top__DOT__i_alu__DOT___validReg_T_1;
        CData/*4:0*/ top__DOT__i_alu__DOT____VdfgRegularize_h5f12ffbc_1_0;
        CData/*0:0*/ top__DOT__j_pc_next__DOT__validReg;
        CData/*0:0*/ top__DOT__j_pc_next__DOT__is_unknown_instruction_reg;
        CData/*0:0*/ top__DOT__j_pc_next__DOT__is_eql;
        CData/*0:0*/ top__DOT__j_pc_next__DOT__canAccept;
        CData/*0:0*/ top__DOT__j_pc_next__DOT___validReg_T;
        CData/*0:0*/ top__DOT__j_pc_next__DOT___validReg_T_1;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ top__DOT__d_idu__DOT___isaddi_T_2;
        SData/*15:0*/ top__DOT__d_idu__DOT___issrai_T_3;
        IData/*31:0*/ top__DOT__e_imm_io_imm;
        IData/*31:0*/ top__DOT__f_gpr_io_rdata_rs1;
        IData/*31:0*/ top__DOT__f_gpr_io_rdata_rs2;
        IData/*31:0*/ top__DOT__h_data_control_io_alu_Req_bits_data1;
        IData/*31:0*/ top__DOT__h_data_control_io_alu_Req_bits_data2;
        IData/*31:0*/ top__DOT__c_sram__DOT__instReg;
        IData/*31:0*/ top__DOT__c_sram__DOT__pcReg;
        IData/*31:0*/ top__DOT__d_idu__DOT__inst_reg;
        IData/*31:0*/ top__DOT__d_idu__DOT__pc_reg;
        IData/*16:0*/ top__DOT__d_idu__DOT___isadd_T_3;
        IData/*31:0*/ top__DOT__f_gpr__DOT__regs_0;
    };
    struct {
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
        IData/*31:0*/ top__DOT__f_gpr__DOT__rs1_data_reg;
        IData/*31:0*/ top__DOT__f_gpr__DOT__rs2_data_reg;
        IData/*31:0*/ top__DOT__f_gpr__DOT__instruction_reg;
        IData/*31:0*/ top__DOT__f_gpr__DOT__pc_count_reg;
        IData/*31:0*/ top__DOT__f_gpr__DOT___GEN_30;
        IData/*31:0*/ top__DOT__i_alu__DOT__out_reg;
        IData/*31:0*/ top__DOT__i_alu__DOT__rs1_data_reg;
        IData/*31:0*/ top__DOT__i_alu__DOT__rs2_data_reg;
        IData/*31:0*/ top__DOT__i_alu__DOT__instruction_reg;
        IData/*31:0*/ top__DOT__i_alu__DOT__pc_count_reg;
        IData/*31:0*/ top__DOT__j_pc_next__DOT__pc_next_reg;
        IData/*31:0*/ top__DOT__j_pc_next__DOT___beq_result_T_9;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ top__DOT__i_alu__DOT___out33_T_47;
        VlUnpacked<IData/*31:0*/, 1> top__DOT__b_ifu__DOT__reqQ__DOT__ram_addr;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
