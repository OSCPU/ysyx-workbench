# "一生一芯"工程项目

工程目录
.
├── 1.bin
├── csrc
│   ├── device
│   │   ├── device.c
│   │   ├── io
│   │   │   ├── map.c
│   │   │   └── mmio.c
│   │   ├── keyboard.c
│   │   ├── rtc.c
│   │   ├── serial.c
│   │   └── vga.c
│   ├── include
│   │   ├── common.h
│   │   ├── config.h
│   │   ├── debug.h
│   │   ├── device.h
│   │   ├── macro.h
│   │   └── utils.h
│   ├── main.cpp
│   ├── memory
│   │   └── mem.c
│   └── utils
│       ├── disasm.cc
│       └── timer.c
├── makefile
└── vsrc
    ├── 2.txt
    ├── define.v
    ├── S011HD1P_X32Y2D128_BW.v
    ├── top.v
    ├── ysyx_22050019_alu.v
    ├── ysyx_22050019_AXI_ARBITER.v
    ├── ysyx_22050019_AXI_LSU_SRAM.v
    ├── ysyx_22050019_core.v
    ├── ysyx_22050019_CSR.v
    ├── ysyx_22050019_EXU.v
    ├── ysyx_22050019_icache.v
    ├── ysyx_22050019_IDU.v
    ├── ysyx_22050019_IFU.v
    ├── ysyx_22050019_LSU.v
    ├── ysyx_22050019_mux.v
    ├── ysyx_22050019_regs.v
    ├── ysyx_22050019_Reg.v
    └── ysyx_22050019_WBU.v

