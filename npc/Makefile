# include sim.mk for simulation
include $(NPC_HOME)/scripts/sim.mk

# Basic variables definition
CHISEL_BUILD_DIR = $(shell pwd)/chisel-build
VERILOG_FILE     = Top.v

export PATH := $(PATH):$(abspath ./utils)

# Some convenient for chisel build
test:
	mill -i __.test

verilog:
	$(call git_commit, "generate verilog")
	@echo + Build verilog
	@mkdir -p $(CHISEL_BUILD_DIR)
	mill -i __.test.runMain Elaborate -td $(CHISEL_BUILD_DIR)
	@cp $(CHISEL_BUILD_DIR)/$(VERILOG_FILE) $(VSRCS_DIR)

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
	@-rm -rf $(CHISEL_BUILD_DIR)
	@-rm -rf $(BUILD_DIR)
	@find $(VSRCS_DIR) -type f -name "*.v" -exec rm {} \;

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(NPC_EXEC)

.PHONY: test verilog help compile bsp reformat checkformat clean sim

-include ../Makefile
