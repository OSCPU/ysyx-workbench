ifeq ($(ISA), native)
build/native.so: src/native.cpp
	mkdir -p build/
	g++ -std=c++11 -O1 -fPIC -shared -o build/native.so src/native.cpp -ldl -lSDL2

else
NAME = libos
SRCS = src/syscall.c src/crt0/crt0.c src/crt0/start/$(ISA).S
include $(NAVY_HOME)/Makefile
endif
