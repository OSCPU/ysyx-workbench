include ../Makefile

TOPNAME:=top
NXDC_FILES:=constr/top.nxdc
BUILD:=build
YSYX_HOME :=$(shell pwd)/../
OBJ_DIR = $(BUILD)/obj_dir
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BIN := ./$(BUILD)/$(TOPNAME)
V_FILE:=vsrc/top.v
CPP_FILE:=csrc/main.cpp $(SRC_AUTO_BIND)
SRC_AUTO_BIND:= ./$(BUILD)/auto_bind.cpp


default: $(BIN)


$(SRC_AUTO_BIND):$(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

include $(NVBOARD_HOME)/scripts/nvboard.mk

all:$(V_FILE)	$(CPP_FILE)
	verilator -Wall --cc --exe --build $(CPP_FILE) $(V_FILE) --trace

$(BIN):	$(V_FILE)	$(CPP_FILE) $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

	rm -rf $(BUILD)

	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


all: default

run: $(BIN)
	@$^

gtk:
	gtkwave wave.vcd
