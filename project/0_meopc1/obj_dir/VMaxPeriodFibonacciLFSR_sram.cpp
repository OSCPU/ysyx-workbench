// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMaxPeriodFibonacciLFSR_sram__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VMaxPeriodFibonacciLFSR_sram::VMaxPeriodFibonacciLFSR_sram(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VMaxPeriodFibonacciLFSR_sram__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_is_unknown_instruction{vlSymsp->TOP.io_is_unknown_instruction}
    , io_carry{vlSymsp->TOP.io_carry}
    , io_isoverflow{vlSymsp->TOP.io_isoverflow}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VMaxPeriodFibonacciLFSR_sram::VMaxPeriodFibonacciLFSR_sram(const char* _vcname__)
    : VMaxPeriodFibonacciLFSR_sram(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VMaxPeriodFibonacciLFSR_sram::~VMaxPeriodFibonacciLFSR_sram() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VMaxPeriodFibonacciLFSR_sram___024root___eval_debug_assertions(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
#endif  // VL_DEBUG
void VMaxPeriodFibonacciLFSR_sram___024root___eval_static(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
void VMaxPeriodFibonacciLFSR_sram___024root___eval_initial(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
void VMaxPeriodFibonacciLFSR_sram___024root___eval_settle(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);
void VMaxPeriodFibonacciLFSR_sram___024root___eval(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);

void VMaxPeriodFibonacciLFSR_sram::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMaxPeriodFibonacciLFSR_sram::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMaxPeriodFibonacciLFSR_sram___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VMaxPeriodFibonacciLFSR_sram___024root___eval_static(&(vlSymsp->TOP));
        VMaxPeriodFibonacciLFSR_sram___024root___eval_initial(&(vlSymsp->TOP));
        VMaxPeriodFibonacciLFSR_sram___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VMaxPeriodFibonacciLFSR_sram___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VMaxPeriodFibonacciLFSR_sram::eventsPending() { return false; }

uint64_t VMaxPeriodFibonacciLFSR_sram::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VMaxPeriodFibonacciLFSR_sram::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VMaxPeriodFibonacciLFSR_sram___024root___eval_final(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram::final() {
    VMaxPeriodFibonacciLFSR_sram___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VMaxPeriodFibonacciLFSR_sram::hierName() const { return vlSymsp->name(); }
const char* VMaxPeriodFibonacciLFSR_sram::modelName() const { return "VMaxPeriodFibonacciLFSR_sram"; }
unsigned VMaxPeriodFibonacciLFSR_sram::threads() const { return 1; }
void VMaxPeriodFibonacciLFSR_sram::prepareClone() const { contextp()->prepareClone(); }
void VMaxPeriodFibonacciLFSR_sram::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VMaxPeriodFibonacciLFSR_sram::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VMaxPeriodFibonacciLFSR_sram___024root__trace_decl_types(VerilatedFst* tracep);

void VMaxPeriodFibonacciLFSR_sram___024root__trace_init_top(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VMaxPeriodFibonacciLFSR_sram___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VMaxPeriodFibonacciLFSR_sram___024root*>(voidSelf);
    VMaxPeriodFibonacciLFSR_sram__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VMaxPeriodFibonacciLFSR_sram___024root__trace_decl_types(tracep);
    VMaxPeriodFibonacciLFSR_sram___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram___024root__trace_register(VMaxPeriodFibonacciLFSR_sram___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VMaxPeriodFibonacciLFSR_sram::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VMaxPeriodFibonacciLFSR_sram::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VMaxPeriodFibonacciLFSR_sram___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
