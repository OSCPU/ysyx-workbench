// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlight.h for the primary calling header

#ifndef VERILATED_VLIGHT___024ROOT_H_
#define VERILATED_VLIGHT___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vlight__Syms;

//----------

VL_MODULE(Vlight___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT16(led,15,0);

    // LOCAL SIGNALS
    IData/*31:0*/ light__DOT__count;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vlight__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vlight___024root);  ///< Copying not allowed
  public:
    Vlight___024root(const char* name);
    ~Vlight___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vlight__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
