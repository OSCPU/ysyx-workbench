TOPNAME = Top
INC_PATH ?=


VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert \
				 --trace-fst  # 使 Verilator 生成 FST 格式波形

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)
CFLAGS += -I/home/jason/ssh/ysyx-workbench/abstract-machine/klib/include
CFLAGS += -I/home/jason/ssh/ysyx-workbench/abstract-machine/am/include
default: $(BIN)
$(call git_commit, "sim RTL")
$(shell mkdir -p $(BUILD_DIR))

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
LLVM_CONFIG = llvm-config
LLVM_CXXFLAGS = $(shell $(LLVM_CONFIG) --cxxflags)
LLVM_LDFLAGS = $(shell $(LLVM_CONFIG) --ldflags)
LLVM_LIBS = $(shell $(LLVM_CONFIG) --libs)
LLVM_LIBDIR = $(shell $(LLVM_CONFIG) --libdir)
  LDFLAGS += $(shell llvm-config --ldflags --libs all)
LDFLAGS += -L$(NEMU_HOME)/build -l:riscv32-nemu-interpreter-so
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\"" $(LLVM_CXXFLAGS)
#LDFLAGS += -L$(shell llvm-config --libdir) -lLLVMRISCVDisassembler
# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
#CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
$(info CFLAGS: $(CFLAGS))

$(BIN): $(VSRCS) $(CSRCS) 
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


#sim:
#	@echo 
#	$(MAKE) -C $(NPC_HOME) ISA=$(ISA) run ARGS="$(NPCFLAGS)" IMG=add-longlong-riscv32e-npc.bin
run: $(BIN)
	@$^ $(IMG)
clean:
	rm -rf $(BUILD_DIR)
.PHONY: default all clean run
