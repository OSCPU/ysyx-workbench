// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMuxKeyInternal.h"
#include "VMuxKeyInternal__Syms.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VMuxKeyInternal::VMuxKeyInternal(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VMuxKeyInternal__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VMuxKeyInternal::VMuxKeyInternal(const char* _vcname__)
    : VMuxKeyInternal(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VMuxKeyInternal::~VMuxKeyInternal() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VMuxKeyInternal___024root___eval_debug_assertions(VMuxKeyInternal___024root* vlSelf);
#endif  // VL_DEBUG
void VMuxKeyInternal___024root___eval_static(VMuxKeyInternal___024root* vlSelf);
void VMuxKeyInternal___024root___eval_initial(VMuxKeyInternal___024root* vlSelf);
void VMuxKeyInternal___024root___eval_settle(VMuxKeyInternal___024root* vlSelf);
void VMuxKeyInternal___024root___eval(VMuxKeyInternal___024root* vlSelf);

void VMuxKeyInternal::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMuxKeyInternal::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMuxKeyInternal___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VMuxKeyInternal___024root___eval_static(&(vlSymsp->TOP));
        VMuxKeyInternal___024root___eval_initial(&(vlSymsp->TOP));
        VMuxKeyInternal___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VMuxKeyInternal___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VMuxKeyInternal::eventsPending() { return false; }

uint64_t VMuxKeyInternal::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VMuxKeyInternal::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VMuxKeyInternal___024root___eval_final(VMuxKeyInternal___024root* vlSelf);

VL_ATTR_COLD void VMuxKeyInternal::final() {
    VMuxKeyInternal___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VMuxKeyInternal::hierName() const { return vlSymsp->name(); }
const char* VMuxKeyInternal::modelName() const { return "VMuxKeyInternal"; }
unsigned VMuxKeyInternal::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> VMuxKeyInternal::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VMuxKeyInternal___024root__trace_init_top(VMuxKeyInternal___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VMuxKeyInternal___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMuxKeyInternal___024root*>(voidSelf);
    VMuxKeyInternal__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    VMuxKeyInternal___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void VMuxKeyInternal___024root__trace_register(VMuxKeyInternal___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VMuxKeyInternal::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VMuxKeyInternal::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VMuxKeyInternal___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
