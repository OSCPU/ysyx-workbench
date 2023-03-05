CROSS_COMPILE = mips-linux-gnu-
LNK_ADDR = $(if $(VME), 0x40000000, 0x83000000)
CFLAGS  += -fno-pic -march=mips32 -EL \
					 -fno-delayed-branch -mno-gpopt -mno-abicalls -mno-check-zero-division \
					 -mno-llsc -mno-imadd -mno-mad
CFLAGS  += -D_LDBL_EQ_DBL
LDFLAGS += -e_start -EL -Ttext-segment $(LNK_ADDR)
