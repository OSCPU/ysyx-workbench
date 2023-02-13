SHELL := /bin/bash

MODULE = dut
VSRC = $(wildcard ./vsrc/*.v ./vsrc/*.sv)
INC = $(wildcard ./csrc/*.h)
SRC_ALL = $(wildcard ./csrc/*.cpp ./csrc/*.c)
MAIN_SRC = $(wildcard ./csrc/main.cpp)
SRC = $(filter-out $(MAIN_SRC), $(SRC_ALL))
TRASH = $(wildcard *.o main)
EMPTY=

.PHONY:sim
sim: waveform.vcd
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "### WAVES ###"	
	gtkwave waveform.vcd -a gtkwave_setup.gtkw

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/V$(MODULE)

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	./obj_dir/V$(MODULE) +verilator+rand+reset+2 

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: ./vsrc/$(MODULE).sv tb_$(MODULE).cpp
	@echo
	@echo "### VERILATING ###"
	verilator -Wall --trace --x-assign unique --x-initial unique -cc \
	$(VSRC) --exe tb_$(MODULE).cpp

.PHONY:lint
lint: ./vsrc/$(MODULE).sv
	verilator --lint-only ./vsrc/$(MODULE).sv

.PHONY:main	
main : $(MAIN_SRC)
	g++ $(MAIN_SRC) -Wall -Og -g -L. -lsteins -Iinc -o main

.PHONY:lib
lib: $(SRC) $(INC) 
	$(call clean_trash)
	@echo "building lib file"
	gcc -c $(SRC)
	ar rs libsteins.a $(wildcard *.o)
	$(call clean_trash)

.PHONY:indent
indent: $(SRC_ALL) $(INC)
	-astyle --style=kr $(SRC_ALL)
	-astyle --style=kr $(INC)

.clean_trash:
ifeq ($(TRASH),$(EMPTY))

else
	@rm $(TRASH)
	@echo "clean done"
endif

include ../Makefile
