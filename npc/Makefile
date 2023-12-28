# Basic variables definition
BUILD_DIR = $(NPC_HOME)/build
GEN_VSRCS_DIR  = $(BUILD_DIR)/sv-gen
GEN_VSRCS      = $(shell find -L $(GEN_VSRCS_DIR) -name "*.sv")
SIM_DIR   = $(NPC_HOME)/sim
VSRCS_DIR = $(SIM_DIR)/vsrc

export PATH := $(PATH):$(abspath ./utils)

# Some convenient for chisel build
test:
	mill -i __.test

verilog:
	$(call git_commit, "generate verilog")
	@echo + Build verilog
	mill -i __.test.runMain Elaborate
	@cp -r $(GEN_VSRCS) $(VSRCS_DIR)

help:
	mill -i __.test.runMain Elaborate --help

compile:
	mill -i __.compile

bsp:
	mill -i mill.bsp.BSP/install

reformat:
	mill -i __.reformat

checkformat:
	mill -i __.checkFormat

clean:
	@-rm -rf $(BUILD_DIR)

cleanall: clean
	@$(MAKE) -C $(SIM_DIR) clean

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(SIM_DIR) sim

gdb:
	$(MAKE) -C $(SIM_DIR) gdb

wave:
	gtkwave sim/wave.vcd

.PHONY: test verilog help compile bsp reformat checkformat clean sim wave gdb

-include ../Makefile