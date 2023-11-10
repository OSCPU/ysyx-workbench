# Include sim.mk
include sim.mk
default: $(TOPNAME)

# Include the rules made by Verilator
include $(TOPNAME).mk

# Use OBJCACHE (ccache) if using gmake and its installed
COMPILE.cc = $(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

# Compile flags
## Turn on creating .d make dependency files
CPPFLAGS += -MMD -MP
## Compile in Verilator runtime debugging, so +verilator+debug works
CPPFLAGS += -DVL_DEBUG=1
## Add inlcude path
CPPFLAGS += $(INCLUDES)

# Turn on some more compiler lint flags (when configured appropriately)
# For testing inside Verilator, "configure --enable-ccwarn" will do this
# automatically; otherwise you may want this unconditionally enabled
ifeq ($(CFG_WITH_CCWARN),yes)  # Local... Else don't burden users
# USER_CPPFLAGS_WALL += -W -Werror -Wall
endif

# See the benchmarking section of bin/verilator.
# Support class optimizations.  This includes the tracing and symbol table.
# SystemC takes minutes to optimize, thus it is off by default.
OPT_SLOW =

# Fast path optimizations.  Most time is spent in these classes.
OPT_FAST = -Os -fstrict-aliasing
#OPT_FAST = -O
#OPT_FAST =

# Automatically understand dependencies

DEPS := $(wildcard *.d)
ifneq ($(DEPS),)
include $(DEPS)
endif
