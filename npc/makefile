export PRJ_PATH=$(shell pwd)/..
#多核处理，这个地方只能手动指定，不清楚原因
export MAKEFLAGS += -j1 --no-print-directory
#顶层模块名
TOPNAME   =top
INC_PATH ?= $(abspath ./csrc/include)

#开启多线程的话无法批处理一群函数，因为多输入问题会一起执行导致报错
#verilator的编译选项
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --trace --threads {1} --output-split {1}-Wall 
VERILATOR_CFLAGS += -Wno-fatal		# only print lint warning, but not terminate compile.
VERILATOR_CFLAGS += -Wno-UNUSED 		# close <unused> warning.
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

#默认运行bin
default: $(BIN)
#创建build/obj_dir编译目录
$(shell mkdir -p $(BUILD_DIR))

#相关文件资源的搜索路径，.v中只能强制指定不然宏定义失败 ，include路径无法用<>改为“”相对路径寻址，这个指定优先寻址地点
VSRCS = ./vsrc/*.v 
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
#INCFLAGS = -I./csrc/include

#verilator的一些添加标志，top名，链接库，反汇编
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\"" -O3 -MMD -Wall 
CFLAGS += $(INCFLAGS)
LIBS += $(shell llvm-config --libs) 
LDFLAGS += -lSDL2 -lSDL2_image -lreadline -ldl -pie -fPIE $(LIBS)
#bin检查3者更新然后构建verilator编译规则
$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	@echo "start rtl sim compile"
	@+$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $(VSRCS) $(CSRCS) \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) > /dev/null
	
all:
	@echo "Write this Makefile by your self."
#运行编译好的bin文件
sim: $(BIN) 
	@echo "RTL sim finished"
	+$(call git_commit, "sim RTL")
	@+./$(BIN) 
#gtkwave top.vcd

#调用生成nemu的so
nemu:
	$(MAKE) -C $(NEMU_HOME) run-env
AM_NPC=/home/xin/.ssh/ysyx-workbench/am-kernels/tests/cpu-tests

npc:
	$(MAKE) -C $(AM_NPC) 

clean:
	@rm -rf obj_dir top.vcd
	 rm -rf $(BUILD_DIR)  
include ../Makefile