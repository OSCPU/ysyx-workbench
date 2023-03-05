FCEUX_PATH = $(AM_HOME)/../fceux
ifeq ($(wildcard $(FCEUX_PATH)/src/x6502.cpp),)
  $(error Please set $$FCEUX_PATH in the Makefile to a valid path of a FCEUX repo)
else
  $(shell mkdir -p $(NAVY_HOME)/fsimg/share/games)
  $(shell ln -sf -T $(FCEUX_PATH)/nes/rom $(NAVY_HOME)/fsimg/share/games/nes)
endif

ifeq ($(findstring $(MAKECMDGOALS),clean|clean-all|html),)
libam:
	$(MAKE) -C $(NAVY_HOME)/libs/libam archive
else
libam: ;
endif

default $(MAKECMDGOALS): libam
	AM_HOME=$(NAVY_HOME) LIBS=libam $(MAKE) -C $(FCEUX_PATH) $(MAKECMDGOALS)

.PHONY: libam default $(MAKECMDGOALS)
