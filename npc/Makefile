TOPNAME = Top
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert \
				 --trace-fst  # 使 Verilator 生成 FST 格式波形

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)
$(call git_commit, "sim RTL")
$(shell mkdir -p $(BUILD_DIR))


# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")


# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BIN): $(VSRCS) $(CSRCS) 
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@$^ $(IMG)

clean:
	rm -rf $(BUILD_DIR)
sim: $(BIN)
	@ARCH=$(ARCH) ALL=$(ALL) $^ $(IMG) +trace  # 运行时传递 ARCH 和 ALL 变量
	@echo "Simulation complete. Waveform saved as dump.fst."
	@echo "Use 'gtkwave dump.fst' to view waveform."

.PHONY: default all clean run
