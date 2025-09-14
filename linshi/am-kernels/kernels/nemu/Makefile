ARCH_SPLIT = $(subst -, ,$(ARCH))
ISA        = $(word 1,$(ARCH_SPLIT))
PLATFORM   = $(word 2,$(ARCH_SPLIT))

ifneq ($(PLATFORM), nemu)
$(error Only support with NEMU)
endif

TMPDEFCONFIG = tmp_defconfig
TMPDEFCONFIG_FILE = $(NEMU_HOME)/configs/$(TMPDEFCONFIG)

all:
	$(MAKE) save_config
	$(MAKE) build_am
	$(MAKE) restore_config
	$(MAKE) -C $(NEMU_HOME) run IMG=$(NEMU_HOME)/build/$(ISA)-nemu-interpreter-$(ARCH).bin

save_config:
	$(MAKE) -C $(NEMU_HOME) savedefconfig
	mv $(NEMU_HOME)/configs/defconfig $(TMPDEFCONFIG_FILE)

build_am:
	$(MAKE) -C $(NEMU_HOME) $(ISA)-am_defconfig
	$(MAKE) -C $(NEMU_HOME) ARCH=$(ARCH) mainargs=$(mainargs) || \
		($(MAKE) restore_config; false)

restore_config:
	$(MAKE) -C $(NEMU_HOME) ARCH=$(ARCH) $(TMPDEFCONFIG)
	rm $(TMPDEFCONFIG_FILE)

.PHONY: all save_config build_am restore_config
