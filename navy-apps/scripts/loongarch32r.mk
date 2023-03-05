CROSS_COMPILE = loongarch32r-linux-gnusf-
LNK_ADDR = $(if $(VME), 0x40000000, 0x83000000)
CFLAGS  += -fno-pic
LDFLAGS += -e_start -Ttext-segment $(LNK_ADDR)
