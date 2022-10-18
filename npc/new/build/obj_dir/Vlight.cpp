// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlight.h"
#include "Vlight__Syms.h"

//============================================================
// Constructors

Vlight::Vlight(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vlight__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
}

Vlight::Vlight(const char* _vcname__)
    : Vlight(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vlight::~Vlight() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vlight___024root___eval_initial(Vlight___024root* vlSelf);
void Vlight___024root___eval_settle(Vlight___024root* vlSelf);
void Vlight___024root___eval(Vlight___024root* vlSelf);
QData Vlight___024root___change_request(Vlight___024root* vlSelf);
#ifdef VL_DEBUG
void Vlight___024root___eval_debug_assertions(Vlight___024root* vlSelf);
#endif  // VL_DEBUG
void Vlight___024root___final(Vlight___024root* vlSelf);

static void _eval_initial_loop(Vlight__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vlight___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vlight___024root___eval_settle(&(vlSymsp->TOP));
        Vlight___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vlight___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/yzw/ysyx-workbench/npc/new/vsrc/light.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vlight___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlight::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlight::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlight___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vlight___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = Vlight___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/yzw/ysyx-workbench/npc/new/vsrc/light.v", 1, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = Vlight___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void Vlight::final() {
    Vlight___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vlight::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vlight::name() const {
    return vlSymsp->name();
}
