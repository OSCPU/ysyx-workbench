include ../Makefile

TOPNAME =top
NXDC_FILES =constr/top.nxdc
BUILD =build
YSYX_HOME =$(shell pwd)/../
OBJ_DIR = $(BUILD)/obj_dir
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BIN  = ./$(BUILD)/$(TOPNAME)
V_FILE = $(shell find $(abspath ./vsrc) -name "*.v")
CPP_FILE = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp") 

INC_PATH ?=

SRC_AUTO_BIND = $(abspath $(BUILD)/auto_bind.cpp)
$(SRC_AUTO_BIND):$(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@
CPP_FILE += $(SRC_AUTO_BIND)

include $(NVBOARD_HOME)/scripts/nvboard.mk


INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

default: $(BIN)




all:$(V_FILE)	$(CPP_FILE)
	verilator -Wall --cc --exe --build $(CPP_FILE) $(V_FILE) --trace

$(BIN):	$(CPP_FILE) $(V_FILE)	 $(NVBOARD_ARCHIVE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!

	rm -rf $(OBJ_DIR)

	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


all: default

run: $(BIN)
	@$^

gtk:
	gtkwave wave.vcd
