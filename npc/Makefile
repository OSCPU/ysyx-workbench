VERILATOR = verilator
VFLAGS = -Wall --cc --trace --exe --build
VSRC = $(shell find $(abspath ./vsrc) -name "*.v")"")
CSRC = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo $(VSRCS)
	$(VERILATOR) $(VFLAGS) $(VSRC) $(CSRC)


include ../Makefile

clean:
	rm -rf obj_dir
	rm wave.vcd

wave: sim
	./obj_dir/Vtop
	gtkwave wave.vcd

