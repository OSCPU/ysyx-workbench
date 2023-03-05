AM_KERNELS_PATH = $(AM_HOME)/../am-kernels
ifeq ($(wildcard $(AM_KERNELS_PATH)/tests/am-tests/src),)
  $(error Please set $$AM_KERNELS_PATH in the Makefile to a valid path of an am-kernels repo)
endif

BENCHMARKS = coremark dhrystone
KERNELS    = typing-game
APP_PATH   = $(AM_KERNELS_PATH)/$(if $(findstring $(1), $(BENCHMARKS)),benchmarks,kernels)/$(1)

ALL = $(BENCHMARKS) $(KERNELS)
ALL_PATH = $(foreach app,$(ALL),$(call APP_PATH,$(app)))

ifeq ($(findstring $(MAKECMDGOALS),clean|clean-all|html),)
libam:
	$(MAKE) -C $(NAVY_HOME)/libs/libam archive
else
libam: ;
endif

default $(MAKECMDGOALS): libam
	-for f in $(ALL_PATH); do AM_HOME=$(NAVY_HOME) LIBS=libam $(MAKE) -C $$f $(MAKECMDGOALS); done

.PHONY: libam default $(MAKECMDGOALS)
