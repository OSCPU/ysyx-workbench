// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vexample.h for the primary calling header

#include "verilated.h"

#include "Vexample__Syms.h"
#include "Vexample___024root.h"

void Vexample___024root___ctor_var_reset(Vexample___024root* vlSelf);

Vexample___024root::Vexample___024root(Vexample__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vexample___024root___ctor_var_reset(this);
}

void Vexample___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vexample___024root::~Vexample___024root() {
}
