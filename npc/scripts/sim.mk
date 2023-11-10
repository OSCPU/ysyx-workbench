# Basic variable definition
TOP_MODULE = Top
BINARY     = V$(TOP_MODULE)
TOPNAME    = V$(TOP_MODULE)

WORK_DIR   = $(shell pwd)
BUILD_DIR  = $(WORK_DIR)/npc-build
SCRIPT_DIR = $(WORK_DIR)/scripts

CSRCS_DIR  = $(WORK_DIR)/csrc
CSRCS     += $(shell find -L $(CSRCS_DIR) -name "*.c") 
CSRCS     += $(shell find -L $(CSRCS_DIR) -name "*.cpp") 
INC_PATH  := $(CSRCS_DIR)/include $(INC_PATH) 
INCLUDES   = $(addprefix -I, $(INC_PATH))

VSRCS_DIR  = $(WORK_DIR)/vsrc
VSRCS     += $(shell find -L $(VSRCS_DIR) -name "*.v") 

Dep_FILE   = $(WORK_DIR)/utils/input.vc

WAVE_FILE  = wave.vcd
GTKWAVE    = gtkwave

VERILATOR_INPUT = -f $(VSRCS) $(CSRCS) $(Dep_FILE)

# Check for sanity to avoid later confusion
ifneq ($(words $(WORK_DIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

# Set up variables
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
VERILATOR_COVERAGE = verilator_coverage
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
VERILATOR_COVERAGE = $(VERILATOR_ROOT)/bin/verilator_coverage
endif

# Verilator build flags
## Generate C++ in executable form
VERILATOR_FLAGS += -cc --exe
## Generate makefile dependencies (not shown as complicates the Makefile)
VERILATOR_FLAGS += -MMD
## Optimize
VERILATOR_FLAGS += -x-assign fast
## Warn abount lint issues; may not want this on less solid designs
#VERILATOR_FLAGS += -Wall
## Make waveforms
VERILATOR_FLAGS += --trace
## Check SystemVerilog assertions
VERILATOR_FLAGS += --assert
## Generate coverage analysis
VERILATOR_FLAGS += --coverage
## Run Verilator in debug mode
#VERILATOR_FLAGS += --debug
## Add this trace to get a backtrace in gdb
#VERILATOR_FLAGS += --gdbbt
## Define Verilator top name
VERILATOR_FLAGS += --top-module $(TOP_MODULE)

VERILATOR_FLAGS := $(INCLUDES) $(VERILATOR_FLAGS)

# Args for npc build
override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt

IMG ?=

NPC_EXEC = $(BUILD_DIR)/$(BINARY) $(ARGS) $(IMG)
# Some convenient rules
default: run

## Step 1
verilate:
	@mkdir -p $(BUILD_DIR)
	@echo + verilate
	$(VERILATOR) $(VERILATOR_FLAGS) $(VERILATOR_INPUT)
## Step 2
build: verilate
	@echo + build obj
	$(MAKE) -j -C obj_dir -f $(SCRIPT_DIR)/build.mk
## Step 3
run: build
	@echo + run
	$(NPC_EXEC)
## Step 4
wave: run
	@echo + show wave
	$(GTKWAVE) $(WAVE_FILE)

# Other rules
show-config:
	$(VERILATOR) -V

maintainer-copy::
clean-npc mostlyclean distclean maintainer-clean::
	-rm -rf $(BUILD_DIR) logs *.log *.dmp *.vpd coverage.dat core

.PHONY: verilate build run wave maintainer-copy clean-npc mostlyclean distclean maintainer-clean
