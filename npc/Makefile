all:
	# @echo "Write this Makefile by your self."

sim:all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	# @echo "Write this Makefile by your self."
	verilator -cc --trace --exe --build -j 0 -Wall csrc/main.cpp vsrc/top.v -CFLAGS "-D __SIM_TOP"
	./obj_dir/Vtop
	gtkwave ./obj_dir/top-simx.vcd
	rm -rf obj_dir
	verilator -cc --trace --exe --build -j 0 -Wall csrc/main.cpp vsrc/light.v -CFLAGS "-D __SIM_LIGHT"
	./obj_dir/Vlight
	gtkwave ./obj_dir/light-simx.vcd
	rm -rf obj_dir

clean:
	rm -rf obj_dir

example:
	verilator -cc --exe --build -j 0 -Wall csrc/main.cpp vsrc/example.v
	./obj_dir/Vexample

include ../Makefile
