# Makefile for npc simulation build

## 1. Basic setup and Checks

### Check for sanity to avoid later confusion
ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

### Set up variables for verilator
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
endif

### Set up variables for gtkwave
ifeq ($(shell which gtkwave),)
$(error "Error: gtkwave is not installed. Please install gtkwave.")
else
GTKWAVE := gtkwave
endif

## 2. General Compilation Targets

### Build targets
GUEST_ISA  := riscv32e
ENGINE     := interpreter
NAME       := $(GUEST_ISA)-npc-$(ENGINE)

TOP_MODULE := Top
BUILD_DIR  := $(CURDIR)/build
OBJ_DIR    := $(BUILD_DIR)/obj-$(NAME)
$(shell mkdir -p $(OBJ_DIR))

### CSRCS
CSRCS_DIR  := $(CURDIR)/csrc
CSRCS      += $(shell find -L $(CSRCS_DIR) -name "*.c") 
CSRCS      += $(shell find -L $(CSRCS_DIR) -name "*.cc") 
CSRCS      += $(shell find -L $(CSRCS_DIR) -name "*.cpp") 
INC_PATH   := $(CSRCS_DIR)/include $(INC_PATH) 
INCLUDES    = $(addprefix -I, $(INC_PATH))

BINARY      = $(OBJ_DIR)/V$(TOP_MODULE)

### VSRCS
VSRCS_DIR  := $(CURDIR)/vsrc
VSRCS      := $(shell find -L $(VSRCS_DIR) -name "*.sv")

### Verilator inputs
VERILATOR_INPUT = -f input.vc $(CSRCS) $(VSRCS)

### Wave file
WAVE_FILE  = wave.vcd

## 3. Verilator flags

### Generate C++ in executable form
VERILATOR_FLAGS += -cc --exe

### Generate makefile dependencies (not shown as complicates the Makefile)
VERILATOR_FLAGS += -MMD

### Optimize
VERILATOR_FLAGS += -x-assign fast

### Warn abount lint issues; may not want this on less solid designs
#VERILATOR_FLAGS += -Wall

### Make waveforms
VERILATOR_FLAGS += --trace

### Check SystemVerilog assertions
VERILATOR_FLAGS += --assert

### Generate coverage analysis
VERILATOR_FLAGS += --coverage

### Run Verilator in debug mode
#VERILATOR_FLAGS += --debug

### Add this trace to get a backtrace in gdb
VERILATOR_FLAGS += --gdbbt

### Define Verilog top module
VERILATOR_FLAGS += --top-module $(TOP_MODULE)

### Define Verilator build objects directory
VERILATOR_FLAGS += --Mdir $(OBJ_DIR)

### Define LDFLAG
LDLIBS += -lreadline -ldl -pie
LDLIBS += $(shell llvm-config --ldflags --libs)
VERILATOR_FLAGS += -LDFLAGS "$(LDLIBS)" 

## 3. NPC simulation build

### Arguments for npc-main.c
DIFF_REF_NAME = riscv32-nemu-interpreter-so
DIFF_REF_SO = $(NEMU_HOME)/build/$(DIFF_REF_NAME)
override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt
override ARGS += --diff=$(DIFF_REF_SO)
override ARGS += -b

### Img to load
IMG ?=

## 4. Some convenient rules

### Basic simulation rules

NPC_EXEC := $(BINARY) $(ARGS) $(IMG)

default: sim

verilate:
	@echo + Verilate to build C++ class 
	@$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)

build: verilate
	@echo + Build NPC Simulation Objects and Link
	@$(MAKE) -j -C $(OBJ_DIR) -f ../../Makefile_obj

sim: build
	@echo + Run Simulation
	$(NPC_EXEC)

gdb: build
	@echo + Run gdb
	gdb -s $(BINARY) --args $(NPC_EXEC)

wave:
	@echo + Show Simulation Wave
	$(GTKWAVE) $(WAVE_FILE)

### Other targets

show-config:
	$(VERILATOR) -V

clean:
	@-rm -rf $(BUILD_DIR) logs *.log *.dmp *.vpd *.vcd coverage.dat core

.PHONY: verilate build sim wave show-config clean
