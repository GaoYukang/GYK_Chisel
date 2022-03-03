// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimTop.h for the primary calling header

#include "VSimTop.h"
#include "VSimTop__Syms.h"

//==========

VSimTop::VSimTop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    VSimTop__Syms* __restrict vlSymsp = __VlSymsp = new VSimTop__Syms(_vcontextp__, this, name());
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void VSimTop::__Vconfigure(VSimTop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

VSimTop::~VSimTop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VSimTop::_settle__TOP__2(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_settle__TOP__2\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_tick = (0x10U == vlTOPp->SimTop__DOT__myCounter__DOT__c);
    vlTOPp->SimTop__DOT__myCounter__DOT___c_T_1 = ((IData)(1U) 
                                                   + vlTOPp->SimTop__DOT__myCounter__DOT__c);
}

void VSimTop::_eval_initial(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval_initial\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VSimTop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::final\n"); );
    // Variables
    VSimTop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSimTop::_eval_settle(VSimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_eval_settle\n"); );
    VSimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VSimTop::_ctor_var_reset(VSimTop* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimTop::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clock = VL_RAND_RESET_I(1);
    self->reset = VL_RAND_RESET_I(1);
    self->io_tick = VL_RAND_RESET_I(1);
    self->SimTop__DOT__myCounter__DOT__c = VL_RAND_RESET_I(32);
    self->SimTop__DOT__myCounter__DOT___c_T_1 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        self->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
