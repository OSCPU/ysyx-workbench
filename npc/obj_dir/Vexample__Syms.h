// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VEXAMPLE__SYMS_H_
#define VERILATED_VEXAMPLE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vexample.h"

// INCLUDE MODULE CLASSES
#include "Vexample___024root.h"

// SYMS CLASS (contains all model state)
class Vexample__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vexample* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vexample___024root             TOP;

    // CONSTRUCTORS
    Vexample__Syms(VerilatedContext* contextp, const char* namep, Vexample* modelp);
    ~Vexample__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
