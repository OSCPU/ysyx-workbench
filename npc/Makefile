
V_FILE:=vsrc/example.v
CPP_FILE:=csrc/main.cpp
OUTPUT:=output
NEMU_HOME= $(shell pwd)
all:$(V_FILE)	$(CPP_FILE)
	# verilator	-Wall	-cc	$(V_FILE)	--exe	$(CPP_FILE)
	# make -C $(OUTPUT) -j -f vour.mk vour

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	# $(all)




include ../Makefile
