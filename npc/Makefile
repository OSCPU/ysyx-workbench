include ../Makefile

V_FILE:=vsrc/top.v
CPP_FILE:=csrc/main.cpp
OUTPUT:=output
YSYX_HOME = $(shell pwd)/../
all:$(V_FILE)	$(CPP_FILE)
	verilator -Wall --cc --exe --build $(CPP_FILE) $(V_FILE)
sim:	all
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	# $(all)





