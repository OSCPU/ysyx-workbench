CC=cc
CFLAGS=-Wall

all: run clean run-crash clean

ex1:
	${CC} -o ex1 main.c

crash:
	${CC} -o crash crash.c

run: ex1
	./ex1

run-crash: crash
	./crash

clean:
	rm -f ./ex1
	rm -f ./crash
