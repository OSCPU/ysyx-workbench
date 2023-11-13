# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vps2_keyboard.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vps2_keyboard \
	Vps2_keyboard___024root__DepSet_h0287a111__0 \
	Vps2_keyboard___024root__DepSet_hdf6f1226__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vps2_keyboard__ConstPool_0 \
	Vps2_keyboard___024root__Slow \
	Vps2_keyboard___024root__DepSet_h0287a111__0__Slow \
	Vps2_keyboard___024root__DepSet_hdf6f1226__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vps2_keyboard__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vps2_keyboard__Syms \
	Vps2_keyboard__Trace__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_vcd_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
