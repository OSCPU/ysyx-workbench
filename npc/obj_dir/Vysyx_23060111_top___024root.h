// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_23060111_top.h for the primary calling header

#ifndef VERILATED_VYSYX_23060111_TOP___024ROOT_H_
#define VERILATED_VYSYX_23060111_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_23060111_top__Syms;
class Vysyx_23060111_top___024unit;


class Vysyx_23060111_top___024root final : public VerilatedModule {
  public:
    // CELLS
    Vysyx_23060111_top___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__hit;
    CData/*0:0*/ ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__hit;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactDidInit;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    VL_OUT(pc,31,0);
    VlWide<7>/*214:0*/ ysyx_23060111_top__DOT__init_IDU__DOT____Vcellinp__typeMux____pinNumber4;
    IData/*31:0*/ ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h8a6dd40b__0;
    IData/*31:0*/ ysyx_23060111_top__DOT__init_EXU__DOT____VdfgTmp_h51178536__0;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __Vtrigrprev__TOP__inst;
    IData/*31:0*/ __VactIterCount;
    QData/*35:0*/ ysyx_23060111_top__DOT__init_IDU__DOT____Vcellout__typeMux____pinNumber1;
    QData/*35:0*/ ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__lut_out;
    QData/*63:0*/ ysyx_23060111_top__DOT__init_EXU__DOT____Vcellout__i1____pinNumber1;
    QData/*63:0*/ ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__lut_out;
    VlUnpacked<IData/*31:0*/, 32> ysyx_23060111_top__DOT__reg___0240__DOT__rf;
    VlUnpacked<QData/*42:0*/, 5> ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*6:0*/, 5> ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__key_list;
    VlUnpacked<QData/*35:0*/, 5> ysyx_23060111_top__DOT__init_IDU__DOT__typeMux__DOT__i0__DOT__data_list;
    VlUnpacked<VlWide<3>/*67:0*/, 5> ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__pair_list;
    VlUnpacked<CData/*3:0*/, 5> ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__key_list;
    VlUnpacked<QData/*63:0*/, 5> ysyx_23060111_top__DOT__init_EXU__DOT__i1__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_23060111_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_23060111_top___024root(Vysyx_23060111_top__Syms* symsp, const char* v__name);
    ~Vysyx_23060111_top___024root();
    VL_UNCOPYABLE(Vysyx_23060111_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
