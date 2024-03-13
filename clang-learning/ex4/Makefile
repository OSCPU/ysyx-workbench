CC=cc
CFLAGS=-Wall -g

all: run clean run-crash clean

ex4:
	${CC} -o ex4 main.c

crash:
	${CC} -o crash crash.c

run: ex4
	./ex4

run-crash: crash
	valgrind ./crash

clean:
	rm -f ./ex4
	rm -f ./crash
