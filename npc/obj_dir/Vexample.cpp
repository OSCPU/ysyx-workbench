// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vexample.h"
#include "Vexample__Syms.h"

//============================================================
// Constructors

Vexample::Vexample(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vexample__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , c{vlSymsp->TOP.c}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vexample::Vexample(const char* _vcname__)
    : Vexample(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vexample::~Vexample() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vexample___024root___eval_debug_assertions(Vexample___024root* vlSelf);
#endif  // VL_DEBUG
void Vexample___024root___eval_static(Vexample___024root* vlSelf);
void Vexample___024root___eval_initial(Vexample___024root* vlSelf);
void Vexample___024root___eval_settle(Vexample___024root* vlSelf);
void Vexample___024root___eval(Vexample___024root* vlSelf);

void Vexample::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vexample::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vexample___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vexample___024root___eval_static(&(vlSymsp->TOP));
        Vexample___024root___eval_initial(&(vlSymsp->TOP));
        Vexample___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vexample___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vexample::eventsPending() { return false; }

uint64_t Vexample::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vexample::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vexample___024root___eval_final(Vexample___024root* vlSelf);

VL_ATTR_COLD void Vexample::final() {
    Vexample___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vexample::hierName() const { return vlSymsp->name(); }
const char* Vexample::modelName() const { return "Vexample"; }
unsigned Vexample::threads() const { return 1; }
