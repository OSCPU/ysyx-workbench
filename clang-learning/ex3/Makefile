CC=cc
CFLAGS=-Wall

all: run clean run-crash clean

ex3:
	${CC} -o ex3 main.c

crash:
	${CC} -o crash crash.c

run: ex3
	./ex3

run-crash: crash
	./crash

clean:
	rm -f ./ex3
	rm -f ./crash
