-include $(NPC_HOME)/../Makefile
include $(NPC_HOME)/scripts/build.mk

compile_git:
	$(call git_commit, "compile npc")

$(BINARY): compile_git

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt

# Command to execute NPC
IMG ?=
NPC_EXEC := $(BINARY) $(ARGS) $(IMG)

run-env: $(BINARY)

run: run-env
	$(call git_commit, "run npc")
	$(NPC_EXEC)

gdb: run-env
	$(call git_commit, "gdb NPC")
	gdb -s $(BINARY) --args $(NPC_EXEC)

.PHONY: run gdb run-env
