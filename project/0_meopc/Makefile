TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH = nemu/include

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert


BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

CSRCS_SIM = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

LIBCAPSTONE = /home/meowth/ysyx/ysyx-workbench/project/0_meopc/tools/capstone/repo/libcapstone.so.5
#CFLAGS += -I  /home/meowth/ysyx/ysyx-workbench/project/0_meopc/tools/capstone/repo/include
/home/meowth/ysyx/ysyx-workbench/project/0_meopc/csrc/utils/disasm.cpp: $(LIBCAPSTONE)
$(LIBCAPSTONE):
	$(MAKE) -C /home/meowth/ysyx/ysyx-workbench/project/0_meopc/tools/capstone

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@$^

clean:
	rm -rf $(BUILD_DIR)
	rm -rf obj_dir
	
wave_build:
	verilator --cc --exe --trace-fst --build -j 0 nemu/main.cpp  vsrc/top.v 
	obj_dir/Vtop

wave_display:
	gtkwave obj_dir/wave.fst

IMAGE = /home/meowth/ysyx/ysyx-workbench/am-kernels/tests/cpu-tests/build/bit-riscv32e-npc
DIFF_SO = /home/meowth/ysyx/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so
sim:
	verilator --cc --exe --trace-fst --build -j 0 \
	-CFLAGS "-I/usr/include/readline \
			 -I  /home/meowth/ysyx/ysyx-workbench/project/0_meopc/tools/capstone/repo/include" \
	-LDFLAGS "-lreadline -lncurses" \
	--top-module top \
	$(CSRCS_SIM)  vsrc/*.v 
	obj_dir/Vtop -e $(IMAGE).elf -d $(DIFF_SO) $(IMAGE).bin mainargs=1
	gtkwave obj_dir/wave.fst

test:
	verilator --cc --exe --trace-fst --build -j 0 $(CSRCS_SIM)  vsrc/*.v 
	obj_dir/Vtop /home/meowth/ysyx/ysyx-workbench/am-kernels/tests/cpu-tests/build/dummy-riscv32e-npc.bin


.PHONY: default all clean run
