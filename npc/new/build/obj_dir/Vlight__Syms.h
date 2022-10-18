// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLIGHT__SYMS_H_
#define VERILATED_VLIGHT__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "Vlight.h"

// INCLUDE MODULE CLASSES
#include "Vlight___024root.h"

// SYMS CLASS (contains all model state)
class Vlight__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vlight* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vlight___024root               TOP;

    // CONSTRUCTORS
    Vlight__Syms(VerilatedContext* contextp, const char* namep, Vlight* modelp);
    ~Vlight__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
