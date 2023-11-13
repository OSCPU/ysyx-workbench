// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VPS2_KEYBOARD_H_
#define VERILATED_VPS2_KEYBOARD_H_  // guard

#include "verilated.h"

class Vps2_keyboard__Syms;
class Vps2_keyboard___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class Vps2_keyboard VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vps2_keyboard__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst,0,0);
    VL_IN8(&ps2_clk,0,0);
    VL_IN8(&ps2_data,0,0);
    VL_IN8(&BTNC,0,0);
    VL_IN8(&BTNU,0,0);
    VL_IN8(&BTND,0,0);
    VL_IN8(&BTNL,0,0);
    VL_IN8(&BTNR,0,0);
    VL_OUT8(&VGA_CLK,0,0);
    VL_OUT8(&VGA_HSYNC,0,0);
    VL_OUT8(&VGA_VSYNC,0,0);
    VL_OUT8(&VGA_BLANK_N,0,0);
    VL_OUT8(&VGA_R,7,0);
    VL_OUT8(&VGA_G,7,0);
    VL_OUT8(&VGA_B,7,0);
    VL_OUT8(&seg0,7,0);
    VL_OUT8(&seg1,7,0);
    VL_OUT8(&seg2,7,0);
    VL_OUT8(&seg3,7,0);
    VL_OUT8(&seg4,7,0);
    VL_OUT8(&seg5,7,0);
    VL_OUT8(&seg6,7,0);
    VL_OUT8(&seg7,7,0);
    VL_IN16(&sw,13,0);
    VL_OUT16(&ledr,15,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vps2_keyboard___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vps2_keyboard(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vps2_keyboard(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vps2_keyboard();
  private:
    VL_UNCOPYABLE(Vps2_keyboard);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
