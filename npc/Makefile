BUILD_DIR = ./build
SIM_DIR   = ./sim
Verilog_FILE = TOP.v

export PATH := $(PATH):$(abspath ./utils)

test:
	mill -i __.test

verilog:
	$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i __.test.runMain Elaborate -td $(BUILD_DIR)
	$(shell cp $(BUILD_DIR)/$(Verilog_FILE) $(SIM_DIR))

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
	-rm -rf $(BUILD_DIR)
	$(MAKE) -C $(SIM_DIR) clean

.PHONY: test verilog help compile bsp reformat checkformat clean sim

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(MAKE) -C $(SIM_DIR) sim

-include ../Makefile
