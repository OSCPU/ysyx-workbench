REPO_PATH = repo
ifeq ($(wildcard repo/include/palcommon.h),)
  $(shell mkdir -p $(NAVY_HOME)/fsimg/share/games)
  $(shell git clone --depth=1 git@github.com:NJU-ProjectN/pal-navy.git $(REPO_PATH))
endif

NAME = pal
SRCS = $(shell find $(REPO_PATH)/src/ -name "*.c" -or -name "*.cpp")
INC_PATH = $(REPO_PATH)/include
LIBS += libminiSDL libfixedptc
include $(NAVY_HOME)/Makefile

install: install-file
init:;

install-file:
	ln -sf -T $(abspath $(REPO_PATH)/data) $(NAVY_HOME)/fsimg/share/games/pal

.PHONY: install-file init
