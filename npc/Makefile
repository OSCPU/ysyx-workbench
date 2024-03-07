all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	# @echo "Write this Makefile by your self."
	verilator -cc --trace --exe --build -j 0 -Wall csrc/main.cpp vsrc/top.v
	./obj_dir/Vtop
	gtkwave ./obj_dir/simx.vcd

example:
	verilator -cc --exe --build -j 0 -Wall csrc/main.cpp vsrc/example.v
	./obj_dir/Vexample

include ../Makefile
