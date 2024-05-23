VERILATOR = verilator
VFLAGS = -Wall --cc --trace --exe --build
VSRC = vsrc/top.v
CSRC = csrc/main.cpp
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

