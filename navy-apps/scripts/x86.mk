LNK_ADDR = $(if $(VME), 0x40000000, 0x03000000)
CFLAGS  += -m32 -fno-pic -march=i386 -mstringop-strategy=loop -mno-inline-all-stringops
CFLAGS  += -fcf-protection=none # remove endbr32 in Ubuntu 20.04 with a CPU newer than Comet Lake
LDFLAGS += -melf_i386 -Ttext-segment $(LNK_ADDR)
