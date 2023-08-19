Vfile:$(wildcard ./vsrc/*.v)
Cfile:$(wildcard ./csrc/*.cpp)

all:
	@echo "Write this Makefile by your self."

sim:$(Vfile) $(Cfile)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."
	verilator -Wall --cc --trace --exe --build $^
	./obj_dir/V$(basename $(Vfile))

.PHONY:clean
clean:
	rm -rf obj_dir
include ../Makefile
