// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vysyx_25020077_top__pch.h"
#include "Vysyx_25020077_top.h"
#include "Vysyx_25020077_top___024root.h"

// FUNCTIONS
Vysyx_25020077_top__Syms::~Vysyx_25020077_top__Syms()
{
}

Vysyx_25020077_top__Syms::Vysyx_25020077_top__Syms(VerilatedContext* contextp, const char* namep, Vysyx_25020077_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(114);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
