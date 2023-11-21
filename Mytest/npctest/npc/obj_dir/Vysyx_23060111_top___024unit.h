// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_23060111_top.h for the primary calling header

#ifndef VERILATED_VYSYX_23060111_TOP___024UNIT_H_
#define VERILATED_VYSYX_23060111_TOP___024UNIT_H_  // guard

#include "verilated.h"

class Vysyx_23060111_top__Syms;

class Vysyx_23060111_top___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vysyx_23060111_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_23060111_top___024unit(Vysyx_23060111_top__Syms* symsp, const char* v__name);
    ~Vysyx_23060111_top___024unit();
    VL_UNCOPYABLE(Vysyx_23060111_top___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
