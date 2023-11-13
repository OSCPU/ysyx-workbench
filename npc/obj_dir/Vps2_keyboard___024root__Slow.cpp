// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2_keyboard.h for the primary calling header

#include "verilated.h"

#include "Vps2_keyboard__Syms.h"
#include "Vps2_keyboard___024root.h"

void Vps2_keyboard___024root___ctor_var_reset(Vps2_keyboard___024root* vlSelf);

Vps2_keyboard___024root::Vps2_keyboard___024root(Vps2_keyboard__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vps2_keyboard___024root___ctor_var_reset(this);
}

void Vps2_keyboard___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vps2_keyboard___024root::~Vps2_keyboard___024root() {
}
