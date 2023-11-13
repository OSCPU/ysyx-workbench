// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPS2_KEYBOARD__SYMS_H_
#define VERILATED_VPS2_KEYBOARD__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vps2_keyboard.h"

// INCLUDE MODULE CLASSES
#include "Vps2_keyboard___024root.h"

// SYMS CLASS (contains all model state)
class Vps2_keyboard__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vps2_keyboard* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vps2_keyboard___024root        TOP;

    // CONSTRUCTORS
    Vps2_keyboard__Syms(VerilatedContext* contextp, const char* namep, Vps2_keyboard* modelp);
    ~Vps2_keyboard__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
