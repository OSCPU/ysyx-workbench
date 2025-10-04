# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vysyx_25030077.mk

default: Vysyx_25030077

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /home/meowth/ysyx/ysyx-workbench/oss-cad-suite-linux-x64-20250830/oss-cad-suite/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?=
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?=

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vysyx_25030077
# Module prefix (from --prefix)
VM_MODPREFIX = Vysyx_25030077
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
  -I/usr/include/readline 		 -I  /home/meowth/ysyx/ysyx-workbench/project/0_meopc/tools/capstone/repo/include \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
  -lz \
  -lreadline -lncurses \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
  cpu_exec \
  elf \
  main \
  memory \
  monitor \
  regs \
  expr \
  sdb \
  disasm \
  dut \
  ftrace \
  itrace \
  logs \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
  .. \
  ../csrc \
  ../csrc/cpu_exec \
  ../csrc/elf \
  ../csrc/memory \
  ../csrc/monitor \
  ../csrc/regs \
  ../csrc/sdb \
  ../csrc/utils \

### Default rules...
# Include list of all generated classes
include Vysyx_25030077_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

cpu_exec.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/cpu_exec/cpu_exec.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
elf.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/elf/elf.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
main.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/main.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
memory.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/memory/memory.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
monitor.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/monitor/monitor.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
regs.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/regs/regs.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
expr.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/sdb/expr.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
sdb.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/sdb/sdb.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
disasm.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/utils/disasm.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
dut.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/utils/dut.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
ftrace.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/utils/ftrace.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
itrace.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/utils/itrace.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
logs.o: /home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/utils/logs.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
Vysyx_25030077: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@

# Verilated -*- Makefile -*-
