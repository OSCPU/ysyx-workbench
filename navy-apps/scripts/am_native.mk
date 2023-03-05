LNK_ADDR = $(if $(VME), 0x40000000, 0x03000000)
LDFLAGS += -Ttext-segment $(LNK_ADDR)
