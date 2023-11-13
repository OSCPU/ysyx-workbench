// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vps2_keyboard.h"
#include "Vps2_keyboard__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vps2_keyboard::Vps2_keyboard(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vps2_keyboard__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , ps2_clk{vlSymsp->TOP.ps2_clk}
    , ps2_data{vlSymsp->TOP.ps2_data}
    , BTNC{vlSymsp->TOP.BTNC}
    , BTNU{vlSymsp->TOP.BTNU}
    , BTND{vlSymsp->TOP.BTND}
    , BTNL{vlSymsp->TOP.BTNL}
    , BTNR{vlSymsp->TOP.BTNR}
    , VGA_CLK{vlSymsp->TOP.VGA_CLK}
    , VGA_HSYNC{vlSymsp->TOP.VGA_HSYNC}
    , VGA_VSYNC{vlSymsp->TOP.VGA_VSYNC}
    , VGA_BLANK_N{vlSymsp->TOP.VGA_BLANK_N}
    , VGA_R{vlSymsp->TOP.VGA_R}
    , VGA_G{vlSymsp->TOP.VGA_G}
    , VGA_B{vlSymsp->TOP.VGA_B}
    , seg0{vlSymsp->TOP.seg0}
    , seg1{vlSymsp->TOP.seg1}
    , seg2{vlSymsp->TOP.seg2}
    , seg3{vlSymsp->TOP.seg3}
    , seg4{vlSymsp->TOP.seg4}
    , seg5{vlSymsp->TOP.seg5}
    , seg6{vlSymsp->TOP.seg6}
    , seg7{vlSymsp->TOP.seg7}
    , sw{vlSymsp->TOP.sw}
    , ledr{vlSymsp->TOP.ledr}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vps2_keyboard::Vps2_keyboard(const char* _vcname__)
    : Vps2_keyboard(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vps2_keyboard::~Vps2_keyboard() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vps2_keyboard___024root___eval_debug_assertions(Vps2_keyboard___024root* vlSelf);
#endif  // VL_DEBUG
void Vps2_keyboard___024root___eval_static(Vps2_keyboard___024root* vlSelf);
void Vps2_keyboard___024root___eval_initial(Vps2_keyboard___024root* vlSelf);
void Vps2_keyboard___024root___eval_settle(Vps2_keyboard___024root* vlSelf);
void Vps2_keyboard___024root___eval(Vps2_keyboard___024root* vlSelf);

void Vps2_keyboard::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vps2_keyboard::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vps2_keyboard___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vps2_keyboard___024root___eval_static(&(vlSymsp->TOP));
        Vps2_keyboard___024root___eval_initial(&(vlSymsp->TOP));
        Vps2_keyboard___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vps2_keyboard___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vps2_keyboard::eventsPending() { return false; }

uint64_t Vps2_keyboard::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vps2_keyboard::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vps2_keyboard___024root___eval_final(Vps2_keyboard___024root* vlSelf);

VL_ATTR_COLD void Vps2_keyboard::final() {
    Vps2_keyboard___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vps2_keyboard::hierName() const { return vlSymsp->name(); }
const char* Vps2_keyboard::modelName() const { return "Vps2_keyboard"; }
unsigned Vps2_keyboard::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vps2_keyboard::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vps2_keyboard___024root__trace_init_top(Vps2_keyboard___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vps2_keyboard___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vps2_keyboard___024root*>(voidSelf);
    Vps2_keyboard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vps2_keyboard___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vps2_keyboard___024root__trace_register(Vps2_keyboard___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vps2_keyboard::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vps2_keyboard::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vps2_keyboard___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
