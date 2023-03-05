REPO_PATH = repo
ifeq ($(wildcard repo/161220016/main.c),)
  $(shell git clone --depth=1 git@github.com:NJU-ProjectN/oslab0-collection.git $(REPO_PATH))
endif

GAMES = $(shell ls ./repo | grep -E "[0-9]{9}")
ALL = $(GAMES)
ifeq ($(filter $(GAMES), $(ALL)),)
  $(error Expected games in {$(GAMES)}, Got "$(ALL)")
endif

ALL_PATH = $(foreach app,$(ALL),./repo/$(app))

ifeq ($(findstring $(MAKECMDGOALS),clean|clean-all|html),)
libam:
	$(MAKE) -C $(NAVY_HOME)/libs/libam archive
else
libam: ;
endif

default $(MAKECMDGOALS): libam
	-for f in $(ALL_PATH); do AM_HOME=$(NAVY_HOME) LIBS=libam $(MAKE) -C $$f -f ../Makefile $(MAKECMDGOALS); done

.PHONY: libam default $(MAKECMDGOALS)

init:;
.PHONY: init
